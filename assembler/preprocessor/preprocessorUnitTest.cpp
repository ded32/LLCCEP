#include <iostream>
#include <fstream>
#include <cerrno>

#include "./../lexer/lexer.hpp"
#include "preprocessor.hpp"

void dumpLexem(LLCCEP_ASM::lexem lexemData)
{
	::std::cout << "-> Lexem data: " << lexemData.val 
	            << "(" << LLCCEP_ASM::getLexemTypename(lexemData.type) << ")\n";

	if (lexemData.expansionData)
		::std::cout << "Exanded from macro '" << static_cast<LLCCEP_ASM::lexem *>(lexemData.expansionData)->val << "\n";
}

void dump(::std::vector<LLCCEP_ASM::lexem> lexems)
{
	for (const auto &i: lexems)
		dumpLexem(i);
}

int main(int argn, char **argv)
{
	try {
		LLCCEP_ASM::lexer lex;
		LLCCEP_ASM::preprocessor prep;

		lex.setProcessingPath("stdin");
		lex.setProcessingFile(&::std::cin);

		do {
			::std::vector<LLCCEP_ASM::lexem> _in;
			::std::vector<LLCCEP_ASM::lexem> _out;

			lex.getNextLine(_in);
			
			if (!prep.describeMacro(_in)) {
				prep.preprocessCode(_in, _out);

				dump(_in);
				dump(_out);
			}
		} while (1);
	} catch (::std::ios_base::failure &data) {
		QUITE_ERROR(yes, "Can't open '%s': %s",
		            argv[1], data.what());
	} DEFAULT_HANDLING		

	return 0;
}
