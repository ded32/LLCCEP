#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <vector>
#include <fstream>

namespace LLCCEP_exec {
	enum arg_t: uint8_t {
		ARG_T_REG  = 0,
		ARG_T_MEM  = 1,
		ARG_T_VAL  = 2,
		ARG_T_NO   = 4,
		ARG_T_COND = 5,
	};

	struct arg {
		arg_t type;
		double val;
	};

	struct instruction {
		uint8_t opcode;
		arg args[3];
	};

	struct program_data {
		size_t offset;
		size_t main_id;
		size_t size;
	};

	program_data read_program_data(::std::ifstream &input);
	instruction get_instruction_by_id(::std::ifstream &input, program_data data, size_t id);
}

#endif // PROGRAM_HPP
