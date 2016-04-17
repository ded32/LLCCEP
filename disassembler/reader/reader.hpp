#ifndef READER_HPP
#define READER_HPP

#include <vector>
#include <string>
#include <fstream>
#include <cstdint>

namespace LLCCEP_DisASM {
	enum lex_t: uint8_t {
		LEX_T_REG     = 0,
		LEX_T_MEM     = 1,
		LEX_T_VAL     = 2,
		LEX_T_NAME    = 3,
		LEX_T_NO      = 4,
		LEX_T_INVALID = 5
	};

	struct arg {
		lex_t type;
		double value;
	};

	struct op {
		uint8_t instruction;
		uint8_t condition;
		arg args[3];
	};

	void load(std::ifstream &in, std::vector<op> &ops);
}

#endif // READER_HPP
