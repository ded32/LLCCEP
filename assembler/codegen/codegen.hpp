#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include <vector>
#include <fstream>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	struct arg {
		lex_t type;
		double value;
	};

	struct op {
		uint8_t instruction;
		uint8_t condition;
		arg args[3];
	};

	op *prepare_op(::std::vector <lexem> &lex);
	void dump_bitset(::std::ostream &out, op *addr);
}

#endif // CODEGEN_HPP
