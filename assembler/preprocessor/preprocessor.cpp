#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <cstdarg>
#include <iostream>
#include <ios>

#include <STDExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "./../lexer/lexer.hpp"

#include "preprocessor.hpp"

LLCCEP_ASM::preprocessor::preprocessor():
	macros(),
	processingMacro(false)
{ }

LLCCEP_ASM::preprocessor::~preprocessor()
{ }

bool LLCCEP_ASM::preprocessor::preprocessorStuff(::std::vector<LLCCEP_ASM::lexem> in)
{
	return describeMacro(in) || deleteMacro(in);
}

bool LLCCEP_ASM::preprocessor::preprocessorCode(::std::vector<lexem> in)
{
	if (preprocessorsCode) {
		if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_ENDMACRO) {
			preprocessorsCode = false;
			return true;
		} else {
			return true;
		}
	} else {
		if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_DELMACRO) {
			return true;
		} else if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_MACRO) {
			preprocessorsCode = true;
			return true;
		}
	}

	return false;
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> oldLexems, ::std::vector<LLCCEP_ASM::lexem> &newLexems)
{
	preprocessCode(oldLexems, newLexems, ::std::vector<::std::string>{});
}

bool LLCCEP_ASM::preprocessor::describeMacro(::std::vector<LLCCEP_ASM::lexem> in)
{
	if (processingMacro) {
		if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_ENDMACRO) {
			if (in.size() > 1) {
				preprocessingIssue(in[0],
						   "Junk lexems after 'endmacro' directive");
			}

			processingMacro = false;
		} else if (in.size()) {
			if (!macros.size()) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Macro table's empty, how not excepted."))
			}

			auto i = macros.end() - 1;
			i->substitution.insert(i->substitution.end(),
					        in.begin(), in.end());
			i->substitution.push_back(LLCCEP_ASM::lexem{LLCCEP_ASM::LEX_T_NEWLINE});
		}

		return true;
	} else if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_MACRO) {
		if (in.size() != 4 || in[1].type != LLCCEP_ASM::LEX_T_NAME ||
		    in[2].type != LLCCEP_ASM::LEX_T_COLON || in[3].type != LLCCEP_ASM::LEX_T_VAL) {
			preprocessingIssue(in[0], "'macro' directive should be followed by:\n"
					          "1) macro's name\n"
						  "2) colon\n"
						  "3) amount of arguments\n");
		}

		if (isMacroName(in[1].val)) {
			preprocessingIssue(in[1], "'%s' macro was already declared at '%s' file on " size_t_pf " line",
					          in[1].val.c_str(),
						  findMacro(in[1].val)->macroData.pos.file.c_str(),
						  findMacro(in[1].val)->macroData.pos.line);
		}

		LLCCEP_ASM::preprocessor::macro macroData{};
		macroData.macroData = in[1];
		macroData.amountOfArguments = from_string<size_t>(in[3].val);

		macros.push_back(macroData);
		processingMacro = true;
		return true;
	}

	return false;
}

bool LLCCEP_ASM::preprocessor::deleteMacro(::std::vector<LLCCEP_ASM::lexem> in)
{
	if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_DELMACRO) {
		if (in.size() < 2 || (in.size() >= 2 && in[1].type != LLCCEP_ASM::LEX_T_NAME)) {
			preprocessingIssue(in[0], "Excepted macro's name "
					          "after 'delmacro' directive");
		} else if (in.size() > 2) {
			preprocessingIssue(in[0], "Junk lexems after '%s' "
					          "macro deletion",
						  in[1].val.c_str());
		}

		auto foundData = findMacro(in[1].val);
		if (foundData == macros.end()) {
			preprocessingWarning(in[0], "No '%s' macro declared to delete",
					            in[1].val.c_str());
		} else {
			macros.erase(foundData);
		}

		return true;
	}

	return false;
}

::std::vector<LLCCEP_ASM::preprocessor::macro>::const_iterator LLCCEP_ASM::preprocessor::findMacro(::std::string possibleName) const
{
	for (auto i = macros.begin(); i < macros.end(); i++)
		if (i->macroData.val == possibleName)
			return i;

	return macros.end();
}

::std::vector<LLCCEP_ASM::preprocessor::macro>::iterator LLCCEP_ASM::preprocessor::findMacro(::std::string possibleName)
{
	for (auto i = macros.begin(); i < macros.end(); i++)
		if (i->macroData.val == possibleName)
			return i;

	return macros.end();
}

bool LLCCEP_ASM::preprocessor::isMacroName(::std::string possibleName) const
{
	return findMacro(possibleName) != macros.end();
}

bool LLCCEP_ASM::preprocessor::shouldBePreprocessed(::std::vector<LLCCEP_ASM::lexem> in) const
{
	for (const auto &i: in)
		if (isMacroName(i.val))
			return true;

	return false;
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> oldLexems, ::std::vector<LLCCEP_ASM::lexem> &newLexems,
                                              ::std::vector<::std::string> forbiddenMacros)
{
	auto isForbidden = [forbiddenMacros](::std::string name) {
		for (const auto &i: forbiddenMacros)
			if (i == name)
				return true;

		return false;
	};

	for (auto i = oldLexems.begin(); i < oldLexems.end(); i++) {
		if (isMacroName(i->val)) {
			if (isForbidden(i->val)) {
				preprocessingIssue(*i, "Looped macro '%s'",
						   i->val.c_str());
			}

			auto macroData = findMacro(i->val);

			if (oldLexems.end() - i < macroData->amountOfArguments) {
				preprocessingIssue(*i, "Not enough arguments for '%s' macro: " 
						       size_t_pf " requested",
						       macroData->amountOfArguments);
			}

			if (shouldBePreprocessed(macroData->substitution)) {
				::std::vector<LLCCEP_ASM::lexem> newSubstitution;
				::std::vector<::std::string> newForbidden{forbiddenMacros};
				
				newForbidden.push_back(macroData->macroData.val);
				preprocessCode(macroData->substitution, newSubstitution, newForbidden);
				macroData->substitution.clear();
				macroData->substitution = newSubstitution;
			}

			::std::vector<LLCCEP_ASM::lexem> macroArguments{i + 1, i + macroData->amountOfArguments + 1};
			for (const auto &j: macroData->substitution) {
				if (j.type == LLCCEP_ASM::LEX_T_MACROARG) {
					size_t id = from_string<size_t>(j.val);
					if (id >= macroArguments.size()) {
						preprocessingIssue(j, "Macro '%s' doesn't have " size_t_pf " argument, it takes " size_t_pf " arguments",
								      i->val.c_str(), id,
								      macroData->amountOfArguments);
					}

					newLexems.push_back(macroArguments[id]);
				} else {
					newLexems.push_back(j);
				}
			}

			i += macroData->amountOfArguments + 1;
		} else {
			newLexems.push_back(*i);
		}
	}
}


void LLCCEP_ASM::preprocessor::preprocessingIssue(LLCCEP_ASM::lexem issuedLexem, const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);

	char text[4096] = "";
	vsprintf(text, fmt, list);

	va_end(list);

	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
		"%s:" size_t_pf ":\n%s",
		issuedLexem.pos.file.c_str(), issuedLexem.pos.line, text))
}

void LLCCEP_ASM::preprocessor::preprocessingWarning(LLCCEP_ASM::lexem issuedLexem, const char *fmt, ...)
{

	va_list list;
	va_start(list, fmt);

	vfprintf(stderr, fmt, list);

	va_end(list);
}
