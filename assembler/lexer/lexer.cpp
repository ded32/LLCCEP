#include <string>
#include <vector>
#include <cctype>
#include <cstdio>
#include <cstddef>
#include <cassert>
#include <new>

#include <convert.hpp>
#include <STDExtras.hpp>
#include <os-specific.hpp>

#include "lexer.hpp"

#define PARSE_ISSUE(file, line, fmt, ...) CONSTRUCT_MSG("Parsing issue:\n%s:" size_t_pf ":\n" fmt "\n", file, line, ##__VA_ARGS__)

namespace LLCCEP_ASM {
	void to_lexems(::std::string data, ::std::vector<lexem> &lex, 
	               ::std::string file, size_t line)
	{
		auto isskip = [](char c) {
			return (isspace(c) || (c == ','));
		};

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
				curr.type = LEX_T_MEM;
				i++;

				while (isdigit(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (data[i] == '"') {
				curr.type = LEX_T_VAL;
				i++;

				::std::string tmp = "";

				while (data[i] && data[i] != '\n' && data[i] != '"') {
					tmp += data[i];
					i++;
				}

				if (data[i] != '"') {
					throw RUNTIME_EXCEPTION(PARSE_ISSUE(
						file.c_str(),
						line,
						"Unclosed char declaration: %s",
						tmp.c_str()))
				}

				if (tmp.length() != 1) {
					throw RUNTIME_EXCEPTION(PARSE_ISSUE(
						file.c_str(),
						line,
						"Invalid length of char declaration!"))
				}

				i++;

				curr.val = to_string(static_cast<int>(tmp[0]));
			} else if (data[i] == '@') {
				i++;
				curr.type = LEX_T_COND;

				::std::string temporary = "";
				while (data[i] && !isskip(data[i])) {
					temporary += data[i];
					i++;
				}

				curr.val = temporary;
			} else if (isalpha(data[i])) {
				curr.type = LEX_T_NAME;

				while (isalnum(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (isdigit(data[i]) || data[i] == '-' || data[i] == '.') {
				curr.type = LEX_T_VAL;

				while (isdigit(data[i]) || data[i] == '.' || data[i] == '-') {
					curr.val += data[i];
					i++;
				}	
			} else if (isskip(data[i])) {
				while (data[i] && isskip(data[i]))
					i++;

				continue;
			} else if (!data[i] || data[i] == ';' || data[i] == '#') {
				break;
			} else {
				lex.clear();
				
				throw RUNTIME_EXCEPTION(PARSE_ISSUE(
					file.c_str(), 
					line, 
					"Forbidden character '%c'!\n",
					data[i]))
			}

			lex.push_back(curr);

			curr.type = LEX_T_INVALID;
			curr.val = "";
			curr.pos.file = "";
			curr.pos.line = 0;
		}
	}
}

#undef PARSE_ISSUE
