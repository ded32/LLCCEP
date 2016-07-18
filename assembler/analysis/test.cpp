#include <string>
#include <iostream>
#include <vector>
#include <cstdio>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
#include "analysis.hpp"

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
		
			if (lex.size())
				LLCCEP_ASM::analyze(lex);
		} catch (::LLCCEP::runtime_exception &exc) {
			QUITE_ERROR(yes, "%s", exc.msg());
		} catch (...) {
			::std::fprintf(stderr, "Unknown exception");
		}
	} while ((lex.size())?(lex[0].val != "exit"):(1));

	return 0;
}
