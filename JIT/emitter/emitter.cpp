#include <vector>
#include <initializer_list>
#include <cstdint>
#include <cstddef>
#include <iostream>
#include <iomanip>

#include <STLExtras.hpp>

#include "emitter.hpp"

namespace LLCCEP_JIT {
	emitter::emitter():
		program()
	{ }

	emitter::emitter(std::initializer_list<uint8_t> src):
		program(src.begin(), src.end())
	{ }

	emitter::emitter(emitter &src):
		program(src.program)
	{ }

	emitter::~emitter()
	{ }

	void emitter::emit_byte(uint8_t byte)
	{
		program.push_back(byte);
	}

	void emitter::emit(std::initializer_list<uint8_t> data)
	{
		append_init(program, data);
	}

	void emitter::emit(opcode op, regID dst, regID src)
	{
		emit(op);

		uint8_t rm = 0b11000000;
		rm |= (dst << 3) & 0b00111000;
		rm |= src & 0b00000111;

		emit_byte(rm);
	}

	void emitter::dump()
	{
		for (auto byte: program)
			std::cout << std::hex << static_cast<int>(byte) << " ";

		std::cout << "\n";
	}
}
