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
		program_()
	{ }

	emitter::emitter(std::initializer_list<uint8_t> src):
		program_(src.begin(), src.end())
	{ }

	emitter::emitter(emitter &src):
		program_(src.program_)
	{ }

	emitter::~emitter()
	{ }

	void emitter::emit_byte(uint8_t byte)
	{
		program_.push_back(byte);
	}

	void emitter::emit(std::initializer_list<uint8_t> data)
	{
		append_init(program_, data);
	}

	void emitter::emit(opcode op, regID dst, regID src)
	{
		emit(op);

		uint8_t rm = 0b11000000;
		rm |= (src << 3) & 0b00111000;
		rm |= dst & 0b00000111;

		emit_byte(rm);
	}

	void emitter::dump()
	{
		for (auto byte: program_)
			std::cout << std::hex << static_cast<int>(byte) << " ";

		std::cout << "\n";
	}
}
