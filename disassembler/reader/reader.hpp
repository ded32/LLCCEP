#ifndef READER_HPP
#define READER_HPP

#include <iostream>

namespace LLCCEP_DisASM {
	struct arg {
		uint8_t type;
		double val;
	};

	struct instruction {
		uint8_t opcode;
		arg args[3];
	};

	instruction read_instruction(::std::istream &in, ::std::string path);
}

#endif // READER_HPP
