#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>
#include <cstdint>

namespace LLCCEP_SiC {
	enum lex_t {
		LEX_T_NUM = -1,
		LEX_T_ID  = -2,
		LEX_T_STR = -3,
		LEX_T_OP  = -4
	};

	struct position {
		std::string path;
		size_t line;
	};

	struct lexem {
		position pos;
		
		lex_t type;
		std::string val;
	};

	void to_lexems(std::vector<lexem> &lex, std::string str, position pos);
}

#endif // PARSER_HPP
