#include <string>
#include <iostream>
#include <vector>

#include "lexer.hpp"

int main()
{
	std::string str = "";
	std::vector <LLCCEP_ASM::lexem> lex;

	do {
		str.clear();
		lex.clear();
	
		std::getline(std::cin, str);
		ToLexems(str, lex, "stdin", 0);

		for (size_t i = 0; i < lex.size(); i++)
			std::cout << lex[i].type << " " << lex[i].val << "\n";	
	} while ((lex.size())?(lex[0].val != "exit"):(1));

	return 0;
}
