#include <iostream>
#include "../lexer/lexer.hpp"
#include "parser.hpp"

int main()
{
	std::string tmp = "";
	std::vector<LLCCEP_SiPy::lexem> lex;
	size_t line = 1;

	while ((lex.size())?(lex[0].value != "exit"):(1)) {
		tmp.clear();
		lex.clear();

		std::getline(std::cin, tmp);

		LLCCEP_SiPy::ToLexems(tmp, lex, "stdin", line);
		ParseExpr(lex);
	}

	return 0;
}
