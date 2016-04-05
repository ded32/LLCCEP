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
			ParseExpr(lex);
		} catch (LLCCEP_SiPy::Exception &data) {
			std::cerr << data.what() << "\n";
			return 1;
		} catch (std::exception &data) {
			std::cerr << data.what() << "\n";
			return 1;
		} catch (std::string &str) {
 			std::cerr << str << "\n";
			return 1;
		} catch (int &code) {
			std::cerr << code << " error!\n";
			return 1;
		} catch (...) {
			std::cerr << "Unknown exception!\n";
			return 1;
		}
	}

	return 0;
}
