#ifndef LOADER_HPP
#define LOADER_HPP

#include <vector>
#include <fstream>

namespace LLCCEP {
	struct arg {
		arg_t type;
		double value;
	};
	
	struct inst {
		uint8_t cond;
		uint8_t opcode;
		arg args[3];
	};

	void LoadProgram(std::ifstream& in, std::vector <inst>& program);
}

#endif // LOADER_HPP
