#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <ios>

#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"

#include "preprocessor.hpp"

LLCCEP_ASM::preprocessor::preprocessor():
	_in(0),
	_macros(),
	_line(0)
{ }

LLCCEP_ASM::preprocessor::preprocessor(::std::ifstream *input):
	_in(0),
	_macros(),
	_line(0)
{
	setPreprocessingFile(input);
}

LLCCEP_ASM::preprocessor::~preprocessor()
{
	if (_in.is_open())
		_in.close();
}

void LLCCEP_ASM::preprocessor::setPreprocessingFile(::std::ifstream *input)
{
	if (!input) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting preprocessor's file to "
			"null!"))
	}
	
	_in = input;
}

void LLCCEP_ASM::preprocessor::buildPreprocessingTable()
{
	auto hasMacroBeginning = [](::std::vector<LLCCEP_ASM::lexem> &lex) {
		for (size_t i = 0; i < lex.size(); i++) {
			if (lex[i].type == LLCCEP_ASM::LEX_T_MACRO) {
				
			}
		}
		
		return false;
	};
	
	while (!_in.eof()) {
		::std::string tmpLine;
		::std::vector<lexem> lex;
		
		::std::getline(_in, tmpLine);
		LLCCEP_ASM::to_lexems(tmpLine, );
	}
}