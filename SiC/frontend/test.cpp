#include <iostream>
#include <string>
#include <vector>

#include "lexer.hpp"

static const LLCCEP_SiC::position POS = {"stdin", 0};

int main(void)
{
	std::string str = "";
	std::vector<LLCCEP_SiC::lexem> lex;

	while ((lex.size())?(lex[0].val != "exit"):(1)) {
		str.clear();
		lex.clear();

		getline(std::cin, str);
		LLCCEP_SiC::to_lexems(lex, str, POS);

		for (unsigned i = 0; i < lex.size(); i++)
			std::cout << lex[i].type << " " << lex[i].val << "\n";
	}

	return 0;
}
