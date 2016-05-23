#include <string>
#include <sstream>
#include <vector>
#include <cctype>
#include <cstddef>
#include <new>

#include <STDExtras.hpp>

#include "lexer.hpp"

#define PARSE_ISSUE(file, line, msg) \
({\
	::std::stringstrream __res__;\
	__res__ << "A parsing issue has been detected!\n" \
	        << file << ":" << line << ":\n" << msg;\
	\
	__res__.str().c_str();\
})

namespace LLCCEP_ASM {
	void to_lexems(::std::string data, ::std::vector<lexem> &lex, 
	               ::std::string file, ::std::size_t line)
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
				curr.type = LEX_T_MEM;
				i++;

				while (isdigit(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (isalpha(data[i])) {
				curr.type = LEX_T_NAME;

				while (isalnum(data[i])) {
					curr.val += data[i];
					i++;
				}
			} else if (isdigit(data[i])) {
				curr.type = LEX_T_VAL;

				while (isdigit(data[i]) || data[i] == '.') {
					curr.val += data[i];
					i++;
				}	
			} else if (isspace(data[i]) || data[i] == ',') {
				while ((isspace(data[i]) || data[i] == ',') && data[i])
					i++;

				continue;
			} else if (!data[i] || data[i] == ';') {
				break;
			} else {
				std::string msg = "Undefined reference to '";
				msg += data[i]; msg += "'!\n";

				lex.clear();
				throw DEFAULT_EXCEPTION(PARSE_ISSUE(file, line, msg))
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
