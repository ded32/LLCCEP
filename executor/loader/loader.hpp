#ifndef LOADER_HPP
#define LOADER_HPP

#include <vector>
#include <string>

namespace LLCCEP {
	enum arg_t: uint8_t {
		ARG_T_REG  = 0,
		ARG_T_MEM  = 1,
		ARG_T_VAL  = 2,
		ARG_T_NAME = 3,
		ARG_T_NO   = 4,
		ARG_T_INV  = 5
	};

	struct arg {
		arg_t type;
		double value;
	};
	
	struct inst {
		uint8_t cond;
		uint8_t opcode;
		arg args[3];
	};

	bool LoadProgram(std::string in, std::vector <inst>& program);
}

#endif // LOADER_HPP
