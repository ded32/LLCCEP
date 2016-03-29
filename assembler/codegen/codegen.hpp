#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include <bitset>
#include <fstream>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	struct arg {
		lex_t type;
		double value;
	};

	struct op {
		int8_t instruction;
		int8_t condition;
		arg args[3];
	};

	union Convert {
		uint64_t integer;
		double real;
	};

	op *prepare_op(std::vector <lexem> lex);
	void dump_bitset(std::ofstream& out, op *addr);
}

#endif // CODEGEN_HPP
