#include <string>
#include <iostream>
#include <vector>

#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"
#include "codegen.hpp"

int main()
{
	std::string str = "";
	std::vector <LLCCEP_ASM::lexem> lex;

	do {
		str.clear();
		lex.clear();
	
		std::getline(std::cin, str);
		LLCCEP_ASM::ToLexems(str, lex, "stdin", 0);
		
		if (lex.size())
			if (!LLCCEP_ASM::Analyze(lex))
				break;

		LLCCEP_ASM::op *prep = prepare_op(lex);
		dump_bitset(std::cout, prep);
	} while ((lex.size())?(lex[0].val != "exit"):(1));

	return 0;
}
