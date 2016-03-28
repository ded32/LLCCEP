#include <string>
#include <vector>
#include <cctype>
#include <cstddef>
#include <new>
#include <iostream>

#include "lexer.hpp"

#define PARSE_ISSUE(file, line, msg) std::cerr << "A parsing issue has been detected!\n" << file << ":" << line << ":\n" << msg;

namespace LLCCEP_ASM {
	bool ToLexems(std::string data, std::vector <lexem>& lex, std::string file, size_t line)
	{
		size_t i = 0, l = data.length();
		lexem curr = {};

		while (i < l) {
			curr.pos.file = file;
			curr.pos.line = line;
			
			if (data[i] == '&') {
				curr.type = LEX_T_REG;
				i++;

				while (isdigit(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (data[i] == '$') {
				curr.type = LEX_T_ADDR;
				i++;

				while (isdigit(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (isalpha(data[i])) {
				curr.type = LEX_T_NAME;

				while (data[i] && !isspace(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (isdigit(data[i])) {
				curr.type = LEX_T_NUM;

				while (isdigit(data[i]) || data[i] == '.') {
					curr.val += data[i];
					i++;
				}	
			} else if (isspace(data[i])) {
				while (isspace(data[i]) && data[i])
					i++;

				continue;
			} else if (!data[i] || data[i] == ';') {
				break;
			} else {
				std::string msg = "Undefined reference to '";
				msg += data[i]; msg += "'!\n";

				PARSE_ISSUE(file, line, msg)
				lex.clear();

				return false;
			}

			lex.push_back(curr);

			curr.type = LEX_T_INVALID;
			curr.val = "";
			curr.pos.file = "";
			curr.pos.line = 0;
		}

		return true;
	}
}
