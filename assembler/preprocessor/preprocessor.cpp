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

bool LLCCEP_ASM::preprocessor::buildMacroTable(::std::vector<LLCCEP_ASM::lexem> lexems)
{
	::std::vector<lexem> in;
	preprocessCode(lexems, in);

	auto correctMacroDirective = [in] {
		return in.size() >= 4 &&
		       in[0].type == LLCCEP_ASM::LEX_T_MACRO &&
		       in[1].type == LLCCEP_ASM::LEX_T_NAME &&
		       in[2].type == LLCCEP_ASM::LEX_T_COLON &&
		       in[3].type == LLCCEP_ASM::LEX_T_VAL;
	};

	if (!in.size())
		return _processingMacro;

	if (_processingMacro) {
		if (in[0].type == LEX_T_ENDMACRO) {
			if (in.size() > 1) {
				preprocessingIssue(in[0],
						   "Junk expressions after "
						   "'endmacro' directive.");
			}

			_processingMacro = false;
		} else if (in[0].type == LEX_T_MACRO) {
			preprocessingIssue(in[0], "Not allowed to declare macro inside macro");
		} else {		
			if (!_macros.size()) {
				preprocessingIssue(in[0],
						   "Macro's lexem with no "
						   "macro");
			}

			in.push_back(LLCCEP_ASM::lexem{LLCCEP_ASM::LEX_T_NEWLINE});
			auto &insertTo = (_macros.end() - 1)->_substitution;
			insertTo.insert(insertTo.end(), in.begin(), in.end());
		}

		return true;
	} else if (correctMacroDirective()) {
		if (in.size() > 4) {
			preprocessingIssue(in[0], 
				 	   "Junk expressions after 'macro' "
					   "directive.");
		}

		macro newMacro{in[1], from_string<size_t>(in[3].val)};
		_macros.push_back(newMacro);
		_processingMacro = true;
	
		return true;
	} else if (in[0].type == LLCCEP_ASM::LEX_T_ENDMACRO) {
		preprocessingIssue(in[0], "No 'macro' directive to match this 'endmacro'.");
	}

	return false;
}

void LLCCEP_ASM::preprocessor::processMacroTable()
{
	for (auto &i: _macros) {
		::std::vector<LLCCEP_ASM::lexem> newSubstitution;
		preprocessCode(i._substitution, newSubstitution, 
			       ::std::vector<::std::string>{i._macroData.val});
			
		i._substitution.clear();
		i._substitution.insert(i._substitution.begin(),
		                       newSubstitution.begin(),
				       newSubstitution.end());
	}
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> in, ::std::vector<LLCCEP_ASM::lexem> &out)
{
	processMacroTable();
	preprocessCode(in, out, ::std::vector<::std::string>{});
}

::std::vector<LLCCEP_ASM::preprocessor::macro>::iterator LLCCEP_ASM::preprocessor::findMacro(
		::std::string name)
{
	for (auto i = _macros.begin(); i < _macros.end(); i++)
		if (name == i->_macroData.val)
			return i;

	return _macros.end();
}

bool LLCCEP_ASM::preprocessor::shouldBeReplaced(LLCCEP_ASM::lexem data)
{
	return data.type == LEX_T_NAME && 
	       findMacro(data.val) != _macros.end();
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> in, 
                                              ::std::vector<LLCCEP_ASM::lexem> &out, 
					      ::std::vector<::std::string> forbidden)
{
	auto notPreprocessedSubstitution = [this](::std::vector<LLCCEP_ASM::lexem> sub) {
		for (const auto &i: sub)
			if (shouldBeReplaced(i))
				return true;

		return false;
	};

	auto isForbidden = [forbidden](LLCCEP_ASM::lexem data) {
		for (const auto &i: forbidden)
			if (data.val == i)
				return true;

		return false;
	};

	for (auto i = in.begin(); i < in.end(); i++) {
		if (isForbidden(*i)) {
			preprocessingIssue(*i, "Looped macro '%s'",
					   i->val.c_str());
		}

		if (shouldBeReplaced(*i)) {
			auto macroData = findMacro(i->val);
			if (macroData->_amountOfArguments > in.end() - i) {
				preprocessingIssue(*i, "Not enough arguments "
						       "for '%s' macro",
						       macroData->_macroData.val.c_str());
			}

			if (notPreprocessedSubstitution(macroData->_substitution)) {
				::std::vector<LLCCEP_ASM::lexem> newSubstitution;
				::std::vector<::std::string> denied(forbidden);
				denied.push_back(macroData->_macroData.val);

				preprocessCode(macroData->_substitution, 
					       newSubstitution, denied);

				macroData->_substitution.clear();
				macroData->_substitution.insert(macroData->_substitution.begin(), 
						                newSubstitution.begin(), 
								newSubstitution.end());
			}

			::std::vector<LLCCEP_ASM::lexem> args;
			args.insert(args.begin(), i + 1, i + 1 + macroData->_amountOfArguments);
			for (auto &i: macroData->_substitution) {
				if (i.type == LLCCEP_ASM::LEX_T_MACROARG) {
					size_t argN = from_string<size_t>(i.val);
					if (argN >= macroData->_amountOfArguments) {
						preprocessingIssue(i, 
								   "Macro's argument id overbound: at least " size_t_pf "allowed!",
								   macroData->_amountOfArguments);
					}

					out.push_back(args[argN]);
				} else {
					out.push_back(i);
				}
			}

			i += macroData->_amountOfArguments + 1;
		} else {
			out.push_back(*i);
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
