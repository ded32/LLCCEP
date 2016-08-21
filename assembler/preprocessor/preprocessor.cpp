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

void LLCCEP_ASM::preprocessor::setPreprocessingPath(::std::string path)
{
	
}

void LLCCEP_ASM::preprocessor::setPreprocessingFile(::std::ifstream *input)
{
	PREPROCESSOR_NOT_OK
	
	_in = input;
	_started = true;
	
	PREPROCESSOR_OK
}