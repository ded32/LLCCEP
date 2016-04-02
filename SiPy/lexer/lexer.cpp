#include <string>
#include <vector>
#include <cstdint>

#include "lexer.hpp"
#include "../errors/errors.hpp"

namespace LLCCEP_SiPy {
	void ToLexems(std::string str, std::vector<lexem> &lex, std::string file, size_t &line)
	{
		lexem tmp = {};
		size_t i = 0, l = str.length();

		while (i < l) {
			tmp.position.file = file;
			while (isspace(str[i])) {
				if (str[i] == '\n')
					line++;

				i++;
			}
			tmp.position.line = line;

			if (isalpha(str[i])) {
				std::string temp = "";
				while (isalnum(str[i])) {
					temp += str[i];
					i++;
				}

				if (temp == "def")
					tmp.type = LEX_T_DEF;
				else if (temp == "decl")
					tmp.type = LEX_T_DECL;
				else {
					tmp.type = LEX_T_ID;
					tmp.value = temp;
				}
			} else if (isdigit(str[i]) || str[i] == '.') {
				std::string temp = "";
				while (isdigit(str[i]) || str[i] == '.') {
					temp += str[i];
					i++;
				}

				tmp.type = LEX_T_NUM;
				tmp.value = temp;		
			} else if (str[i] == '\'') {
				std::string temp = "";

				i++;
				while (str[i] && str[i] != '\'') {
					temp += str[i];
					i++;
				}
				i++;

				tmp.type = LEX_T_STR;
				tmp.value = temp;
			} else if (str[i] == '#') {
				while (str[i] != '\n')
					i++;
			} else {
				std::string msg = "Forbidden character '"; msg += str[i];
				msg += "'!";
				std::string err = error_notify(file, line, msg);
				throw SyntaxException(err);
			}

			lex.push_back(tmp);
			tmp.type = LEX_T_INV;
			tmp.value = "";
		}
	}
}
