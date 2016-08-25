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
	_macros(),
	_processingMacro(false)
{ }

LLCCEP_ASM::preprocessor::~preprocessor()
{ }

bool LLCCEP_ASM::preprocessor::describeMacro(::std::vector<LLCCEP_ASM::lexem> in)
{
	if (_processingMacro) {
		if (in.size() && in[0].type == LLCCEP_ASM::LEX_T_ENDMACRO) {
			if (in.size() > 1) {
				preprocessingIssue(in[0],
						   "Junk lexems after 'endmacro' directive");
			}

			_processingMacro = false;
		} else if (in.size()) {
			if (!_macros.size()) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Macro table's empty, how not excepted."))
			}

			auto i = _macros.end() - 1;
			i->_substitution.insert(i->_substitution.end(),
					        in.begin(), in.end());
			i->_substitution.push_back(LLCCEP_ASM::lexem{LLCCEP_ASM::LEX_T_NEWLINE});
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

		LLCCEP_ASM::preprocessor::macro macroData{};
		macroData._macroData = in[1];
		macroData._amountOfArguments = from_string<size_t>(in[3].val);

		_macros.push_back(macroData);
		_processingMacro = true;
		return true;
	}

	return false;
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> oldLexems, ::std::vector<LLCCEP_ASM::lexem> &newLexems)
{
	preprocessCode(oldLexems, newLexems, ::std::vector<::std::string>{});
}

::std::vector<LLCCEP_ASM::preprocessor::macro>::iterator LLCCEP_ASM::preprocessor::findMacro(::std::string possibleName)
{
	for (auto i = _macros.begin(); i < _macros.end(); i++)
		if (i->_macroData.val == possibleName)
			return i;

	return _macros.end();
}

bool LLCCEP_ASM::preprocessor::isMacroName(::std::string possibleName)
{
	return findMacro(possibleName) != _macros.end();
}

bool LLCCEP_ASM::preprocessor::shouldBePreprocessed(::std::vector<LLCCEP_ASM::lexem> in)
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

			if (oldLexems.end() - i < macroData->_amountOfArguments) {
				preprocessingIssue(*i, "Not enough arguments for '%s' macro: " 
						       size_t_pf " requested",
						       macroData->_amountOfArguments);
			}

			if (shouldBePreprocessed(macroData->_substitution)) {
				::std::vector<LLCCEP_ASM::lexem> newSubstitution;
				::std::vector<::std::string> newForbidden{forbiddenMacros};
				
				newForbidden.push_back(macroData->_macroData.val);
				preprocessCode(macroData->_substitution, newSubstitution, newForbidden);
				macroData->_substitution.clear();
				macroData->_substitution = newSubstitution;
			}

			::std::vector<LLCCEP_ASM::lexem> macroArguments{i + 1, i + macroData->_amountOfArguments + 1};
			for (const auto &j: macroData->_substitution) {
				if (j.type == LLCCEP_ASM::LEX_T_MACROARG) {
					size_t id = from_string<size_t>(j.val);
					if (id >= macroArguments.size()) {
						preprocessingIssue(j, "Macro '%s' doesn't have " size_t_pf " argument, it takes " size_t_pf " arguments",
								      i->val.c_str(), id,
								      macroData->_amountOfArguments);
					}

					newLexems.push_back(macroArguments[id]);
				} else {
					newLexems.push_back(j);
				}
			}

			i += macroData->_amountOfArguments + 1;
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
