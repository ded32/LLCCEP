#include <iostream>
#include <stdexcept>

#include "../lexer/lexer.hpp"
#include "../errors/errors.hpp"
#include "parser.hpp"

int main()
{
	std::string tmp = "";
	std::vector<LLCCEP_SiPy::lexem> lex;
	size_t line = 1;

	while ((lex.size())?(lex[0].value != "exit"):(1)) {
		try {
			tmp.clear();
			lex.clear();

			std::getline(std::cin, tmp);

			LLCCEP_SiPy::ToLexems(tmp, lex, "stdin", line);
			for (size_t i = 0; i < lex.size(); i++)
				std::cout << lex[i].type << " " << lex[i].value << " \n";

			LLCCEP_SiPy::GetNumber(lex);
		} catch (LLCCEP_SiPy::Exception &data) {
			std::cerr << "\n" << data.what() << "\n";
			return 1;
		} catch (std::exception &data) {
			std::cerr << "\n" << data.what() << "\n";
			return 1;
		} catch (std::string &str) {
 			std::cerr << "\n" << str << "\n";
			return 1;
		} catch (int &code) {
			std::cerr << "\n" << code << " error!\n";
			return 1;
		} catch (...) {
			std::cerr << "\eUnknown exception!\n";
			return 1;
		}
	}

	return 0;
}
