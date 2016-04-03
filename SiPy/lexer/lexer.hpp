#ifndef SIPY_LEXER_HPP
#define SIPY_LEXER_HPP

#include <string>
#include <vector>
#include <cstdint>

namespace LLCCEP_SiPy {
	enum lex_t: int {
		LEX_T_NUM = 0,
		LEX_T_ID  = 1,
		LEX_T_STR = 2,
		LEX_T_INV = 3
	};

	enum decl_t: int {
		DECL_T_EXTERN = 4,
		DECL_T_DEF    = 5
	};

	enum op_t: int {
		OP_T_OB = 6,
		OP_T_CB = 7,

		OP_T_ADD = 8,
		OP_T_SUB = 9,
		OP_T_MUL = 10,
		OP_T_SEG = 11,
		OP_T_POW = 12,
		
		OP_T_ADDEQ = 13,
		OP_T_SUBEQ = 14,
		OP_T_MULEQ = 15,
		OP_T_SEGEQ = 16,
		OP_T_POWEQ = 17,
	
		OP_T_AND = 18,
		OP_T_OR  = 19,
		OP_T_XOR = 20,
		OP_T_NOT = 21,

		OP_T_EQ     = 22,
		OP_T_NOTEQ  = 23,
		OP_T_MOREEQ = 24,
		OP_T_LESSEQ = 25,
		OP_T_MORE   = 26,
		OP_T_LESS   = 27,

		OP_T_SET = 28
	};

	struct lexem {
		int type;

		struct {
			std::string file;
			size_t line;
		} position;
		std::string value;
	};

	void ToLexems(std::string str, std::vector<lexem> &lex, std::string file, size_t &line);
}

#endif // SIPY_LEXER_HPP
