#include <iostream>
#include <vector>
#include <STDExtras.hpp>

#include "analyzer.hpp"
#include "../lexer/lexer.hpp"

void dump(::std::vector<LLCCEP_ASM::lexem> lexems)
{
	for (const auto &i: lexems)
		::std::cout << "-> Lexem data: " << i.val << "(" << LLCCEP_ASM::getLexemTypename(i.type) << ")\n";
}

int main()
{
	LLCCEP_ASM::analyzer analyzer;
	LLCCEP_ASM::lexer lex;
	::std::vector<LLCCEP_ASM::lexem> lexems;

	try {
		lex.setProcessingPath("stdin");
		lex.setProcessingFile(&::std::cin);

		do {
			lexems.clear();
		
			lex.getNextLine(lexems);
			dump(lexems);

			analyzer.analyze(lexems);
		} while ((lexems.size()?(lexems[0].val != "exit"):(1)));
	} DEFAULT_HANDLING

	return 0;
}
