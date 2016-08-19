#ifndef ASSEMBLER_LEXER_HPP
#define ASSEMBLER_LEXER_HPP

#include <string>
#include <vector>
#include <cstddef>

namespace LLCCEP_ASM {
	enum lex_t: uint8_t { 
		LEX_T_REG     = 0,
		LEX_T_MEM     = 1,
		LEX_T_VAL     = 2,
		LEX_T_COND    = 3,
		LEX_T_NAME    = 4,
		LEX_T_NO      = 5,
		LEX_T_COLON   = 6,
		LEX_T_INVALID = 7
	};

	struct lexem {
		lex_t type;
		::std::string val;

		struct {
			::std::string file;
			size_t line;
		} pos;
	};

	void to_lexems(::std::string str, ::std::vector<lexem> &lex, 
	               ::std::string file, size_t line);
	::std::string get_lexem_typename(lex_t type);
}

#endif // ASSEMBLER_LEXER_HPP
