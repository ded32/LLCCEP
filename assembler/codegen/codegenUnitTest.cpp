#include <iostream>
#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"
#include "codegen.hpp"

int main()
{
	try {
		::std::vector<LLCCEP_ASM::lexem> lexems;
		LLCCEP_ASM::lexer lex;
		LLCCEP_ASM::codeGenerator codegen;

		lex.setProcessingPath("stdin");
		lex.setProcessingFile(&::std::cin);

		codegen.setOutput(&::std::cout);

		while ((lexems.size())?(lexems[0].val != "exit"):(1)) {
			lexems.clear();
			lex.getNextLine(lexems);
			LLCCEP_ASM::codeGenerator::op tmp{};
			tmp = codegen.prepareOperation(lexems);
			codegen.dumpOperationBitset(tmp);
		}
	} DEFAULT_HANDLING

	return 0;
}
