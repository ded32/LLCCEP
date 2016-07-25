#include <string>
#include <iostream>
#include <vector>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"
#include "codegen.hpp"

int main()
{
	std::string str = "";
	std::vector <LLCCEP_ASM::lexem> lex;

	do {
		try {
			str.clear();
			lex.clear();
	
			std::getline(std::cin, str);
			LLCCEP_ASM::to_lexems(str, lex, "stdin", 0);
			LLCCEP_ASM::op prep = prepare_op(lex);
			dump_bitset(std::cout, prep);
		} catch (::LLCCEP::runtime_exception &exc) {
			QUITE_ERROR(yes, exc.msg())
		} DEFAULT_HANDLING
	} while ((lex.size())?(lex[0].val != "exit"):(1));

	return 0;
}
