#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <cstdarg>
#include <ios>

#include <STDExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "./../lexer/lexer.hpp"

#include "preprocessor.hpp"

#define PREPROCESSOR_OK DEFAULT_CHECK_BLOCK(true, this, ok())
#define PREPROCESSOR_NOT_OK DEFAULT_CHECK_BLOCK(false, this, ok())

LLCCEP_ASM::preprocessor::preprocessor():
	_in(0),
	_path(),
	_started(false),
	_macros(),
	_processingOrder()
{ }

LLCCEP_ASM::preprocessor::~preprocessor()
{ }

void LLCCEP_ASM::preprocessor::setPreprocessingPath(::std::string path)
{
	PREPROCESSOR_NOT_OK
	
	_path = getAbsolutePath(path);
	_processingOrder.push_back(_path);
	
	PREPROCESSOR_NOT_OK
}

void LLCCEP_ASM::preprocessor::setPreprocessingFile(::std::istream *input)
{
	PREPROCESSOR_NOT_OK
	
	_in = input;
	_started = true;
	
	PREPROCESSOR_OK
}

void LLCCEP_ASM::preprocessor::buildMacroTable()
{
	PREPROCESSOR_OK
	
	LLCCEP_ASM::lexer lex;
	::std::vector<LLCCEP_ASM::lexem> lexems;
	
	auto validMacroDirective = [this, &lexems] {
		for (size_t i = 0; i < lexems.size(); i++) {
			if (lexems[i].type == LLCCEP_ASM::LEX_T_MACRO) {
				if (i) {
					preprocessingIssue(lexems[i].pos.line,
						"'macro' directive should be in "
						"the beginning of the line!");
				} else if (lexems.size() != 4 ||
					   lexems[1].type != LLCCEP_ASM::LEX_T_NAME ||
 					   lexems[2].type != LLCCEP_ASM::LEX_T_COLON ||
					   lexems[3].type != LLCCEP_ASM::LEX_T_VAL) {
					preprocessingIssue(lexems[i].pos.line,
						"'macro' directive should be "
						"followed by macro's name, colon "
						"and amount of arguments!");
				}
				
				return true;
			}
		}
		
		return false;
	};
	
	auto addMacro = [this, validMacroDirective, &lex, &lexems] {
		if (validMacroDirective()) {
			macro newMacro{};
			newMacro._macroData = lexems[1];
			newMacro._amountOfArguments = from_string<size_t>(lexems[3].val);
			
			while (!_in->eof()) {
				lexems.clear();
				lex.getNextLine(lexems);
				
				if (lexems[0].type == LLCCEP_ASM::LEX_T_ENDMACRO)
					break;
				
				newMacro._substitution.insert(newMacro._substitution.end(), lexems.begin(), lexems.end());
				newMacro._substitution.push_back(LLCCEP_ASM::lexem{LLCCEP_ASM::LEX_T_INVALID});
			}
			
			if (lexems[0].type == LLCCEP_ASM::LEX_T_ENDMACRO && lexems.size() > 1) {
				preprocessingIssue(lexems[0].pos.line, "Junk data after 'endmacro'!");
			} else if (_in->eof()) {
				preprocessingIssue(newMacro._macroData.pos.line, 
						   "No 'endmacro' to match macro '%s' definition",
						   newMacro._macroData.val.c_str());
			}
		}
	};
	
	lex.setProcessingPath(_path);
	lex.setProcessingFile(_in);

	_in->seekg(0);
	
	while (!_in->eof()) {
		lexems.clear();
		lex.getNextLine(lexems);
		
		addMacro();
	}
	
	_in->seekg(0);
	
	PREPROCESSOR_OK
}

void LLCCEP_ASM::preprocessor::preprocessCode(::std::vector<LLCCEP_ASM::lexem> in, ::std::vector<LLCCEP_ASM::lexem> &out)
{
	PREPROCESSOR_OK
	
	static bool waitingEndmacro = false;
	out.clear();
	
	auto isMacroName = [this](LLCCEP_ASM::lexem data) {
		if (data.type == LLCCEP_ASM::LEX_T_MACRO) {
			waitingEndmacro = true;
			return _macros.end();
		} else if (waitingEndmacro && data.type == LLCCEP_ASM::LEX_T_ENDMACRO) {
			waitingEndmacro = false;
			return _macros.end();
		}
		
		for (auto i = _macros.begin(); i < _macros.end(); i++)
			if (i->_macroData.val == data.val)
				return i;
		
		return _macros.end();
	};
	
	for (const auto &i: in) {
		auto find = isMacroName(i);
		
		if (find != _macros.end())
			out.insert(out.end(), find->_substitution.begin(), find->_substitution.end());
	}
	
	PREPROCESSOR_OK
}

bool LLCCEP_ASM::preprocessor::ok() const
{
	return _in && _started;
}

void LLCCEP_ASM::preprocessor::preprocessingIssue(size_t line, const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);

	char text[4096] = "";
	vsprintf(text, fmt, list);

	va_end(list);

	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
		"%s:" size_t_pf ":\n%s",
		_path.c_str(), line, text))
}
