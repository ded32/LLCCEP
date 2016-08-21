#include <string>
#include <vector>
#include <fstream>
#include <cstddef>
#include <ios>

#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"

#include "preprocessor.hpp"

LLCCEP_ASM::preprocessor::preprocessor():
	_in(),
	_macros(),
	_line(0)
{ }

LLCCEP_ASM::preprocessor::preprocessor(::std::string inputPath):
	_in(),
	_macros(),
	_line(0)
{
	setPreprocessingFile(inputPath);
}

LLCCEP_ASM::preprocessor::~preprocessor()
{
	if (_in.is_open())
		_in.close();
}

void LLCCEP_ASM::preprocessor::setPreprocessingFile(::std::string inputPath)
{
	try {
		_in.exceptions(::std::ifstream::failbit);
		_in.open(inputPath);
	} catch (::std::ios_base::failure &data) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open file '%s' for preprocessing: %s!",
			data.what()))
	}
}

void LLCCEP_ASM::preprocessor::buildPreprocessingTable()
{
	auto hasMacroBeginning = [](::std::vector<lexem> &lex) {
		for (size_t i = 0; i < lex.size(); i++) {
			if (lex[i].type !=)
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