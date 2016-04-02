#include <vector>
#include <iostream>
#include <stdexcept>
#include <cstdint>

#include "lexer.hpp"
#include "../errors/errors.hpp"

int main()
{
	std::string tmp = "";
	std::vector <LLCCEP_SiPy::lexem> lex;
	size_t line = 1;

	while ((lex.size())?(lex[0].value != "exit"):(1)) {	
		tmp.clear();
		lex.clear();	

		try {
			std::getline(std::cin, tmp);
			LLCCEP_SiPy::ToLexems(tmp, lex, "stdin", line);

			for (size_t i = 0; i < lex.size(); i++)
				std::cout << static_cast<size_t>(lex[i].type) << " " << lex[i].value << "\n";
		} catch (LLCCEP_SiPy::Exception &data) {
			std::cerr << data.what() << "\n";
			return 1;
		} catch (std::exception &data) {
			std::cerr << data.what() << "\n";
		} catch (std::string &str) {
			std::cerr << str << "!\n";
			return 1;
		} catch (int &id) {
			std::cerr << "Exception: " << id << "!\n";
			return 1;
		} catch (...) {
			std::cerr << "Unknown exception!\n";
		}

	}

	return 0;
}
