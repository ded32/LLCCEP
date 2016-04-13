#include <vector>
#include <string>
#include <cstdint>

#include "lexer.hpp"

static const std::string OP[] = {
	"+", "-", "*", "/", "%",
	"+=", "-=", "*=", "/=", "%=",
	",", "(", ")", "[", "]", "{", "}",
	";", "<", ">", ".", "!", "!=", "~",
	":", "and", "or", "xor", "new"
};
static const int OPS_NUM = 29;

static inline int isop(std::string str)
{
	for (unsigned i = 0; i < OPS_NUM; i++)
		if (str.find(OP[i]) == 0)
			return i;

	return -1;
}

namespace LLCCEP_SiC {
	void to_lexems(std::vector<lexem> &lex, std::string str, position pos)
	{
		size_t len = str.length();
		size_t i = 0;
	
		while (i < len) {
			lexem tmp = {};
			tmp.pos = pos;

			if (isop(str.substr(i)) >= 0) {
				tmp.type = LEX_T_OP;
				while (isop(str.substr(i)) >= 0) {
					tmp.val = OP[isop(str.substr(i))];
					i += tmp.val.length();

					lex.push_back(tmp);
				}
			} else if (isalpha(str[i])) {
				tmp.type = LEX_T_ID;
				while (isalnum(str[i])) {
					tmp.val += str[i];
					i++;
				}

				lex.push_back(tmp);
			}
		}
	}
}
