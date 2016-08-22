#include <iostream>
#include <fstream>

#include "./../lexer/lexer.hpp"
#include "preprocessor.hpp"

void dumpLexem(LLCCEP_ASM::lexem lexemData)
{
	::std::cout << "-> Lexem data: " << lexemData.val 
	            << "(" << LLCCEP_ASM::getLexemTypename(lexemData.type) << ")\n";
}

void dump(::std::vector<LLCCEP_ASM::lexem> lexems)
{
	::std::cout << "--> Lexem dump\n";

	for (const auto &i: lexems)
		dumpLexem(i);

	::std::cout << "--> End lexem dump\n";
}

int main(int argn, char **argv)
{
	if (argn != 2) {
		::std::cerr << "invalid usage!";
		return EINVAL;
	}

	try {
		LLCCEP_ASM::lexer lex;
		LLCCEP_ASM::preprocessor prep;

		::std::ifstream in;
		in.exceptions(::std::ios_base::failbit);
		in.open(argv[1]);

		lex.setProcessingPath(argv[1]);
		lex.setProcessingFile(&in);
		prep.setPreprocessingPath(argv[1]);
		prep.setPreprocessingFile(&in);
		prep.buildMacroTable();

		in.seekg(0, in.beg);
		while (!in.eof()) {
			::std::vector<LLCCEP_ASM::lexem> _in;
			::std::vector<LLCCEP_ASM::lexem> _out;

			lex.getNextLine(_in);
			prep.preprocessCode(_in, _out);

			dump(_in);
			dump(_out);
		}
	} catch (::std::ios_base::failure &data) {
		QUITE_ERROR(yes, "Can't open '%s': %s",
		            argv[1], data.what());
	} DEFAULT_HANDLING		

	return 0;
}
