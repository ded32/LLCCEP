#include <iostream>
#include <vector>

#include "lexer.hpp"

void dumpLexem(LLCCEP_ASM::lexem lexemData)
{
	::std::cout << "--> Lexem data: " << lexemData.val 
	            << "(" << LLCCEP_ASM::getLexemTypename(lexemData.type) << ")\n";	
}

int main(void) 
{
	::std::vector<LLCCEP_ASM::lexem> lexems;
	LLCCEP_ASM::lexer lex;
	lex.setProcessingPath("stdin");
	lex.setProcessingFile(&::std::cin);

	try {
		do {
			lexems.clear();
			lex.getNextLine(lexems);

			for (const auto &i: lexems)
				dumpLexem(i);
		} while ((lexems.size())?(lexems[0].val != "exit"):(1));
	} DEFAULT_HANDLING

	return 0;
}
