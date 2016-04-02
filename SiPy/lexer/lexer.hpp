#ifndef SIPY_LEXER_HPP
#define SIPY_LEXER_HPP

#include <string>
#include <vector>
#include <cstdint>

namespace LLCCEP_SiPy {
	enum lex_t {
		LEX_T_NUM  = 0,
		LEX_T_ID   = 1,
		LEX_T_STR  = 2,
		LEX_T_DECL = 3,
		LEX_T_DEF  = 4,
		LEX_T_INV  = 5
	};

	struct lexem {
		lex_t type;

		struct {
			std::string file;
			size_t line;
		} position;
		std::string value;
	};

	void ToLexems(std::string str, std::vector<lexem> &lex, std::string file, size_t &line);
}

#endif // SIPY_LEXER_HPP
