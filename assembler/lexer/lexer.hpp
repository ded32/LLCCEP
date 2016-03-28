#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <vector>

namespace LLCCEP_ASM {
	enum lex_t { 
		LEX_T_INVALID = 0,
		LEX_T_NAME    = 1,
		LEX_T_NUM     = 2,
		LEX_T_ADDR    = 3,
		LEX_T_REG     = 4 
	};

	struct lexem {
		lex_t type;
		std::string val;	

		struct {
			std::string file;
			size_t line;
		} pos;
	};

	bool ToLexems(std::string str, std::vector <lexem>& lex, std::string file, size_t line);
}

#endif // LEXER_HPP
