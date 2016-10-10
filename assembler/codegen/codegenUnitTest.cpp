#include <iostream>
#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"
#include "codegen.hpp"

void dump(LLCCEP_ASM::codeGenerator::op opData)
{
	::std::cout << static_cast<int>(opData.instruction) << "\n";

	for (unsigned i = 0; i < 3; i++)
		::std::cout << static_cast<int>(opData.args[i].value);
}

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

			LLCCEP_ASM::codeGenerator::op tmp = codegen.prepareOperation(lexems);
			dump(tmp);
			//			codegen.dumpOperationBitset(tmp);
		}
	} DEFAULT_HANDLING

	return 0;
}
