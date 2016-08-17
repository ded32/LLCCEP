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
	
	emitter::emitter(const emitter &src):
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

		uint8_t rm = 0b00000000;
		rm |= (src << 3) & 0b00111000;
		rm |= dst & 0b00000111;

		emit_byte(rm);
	}

	void emitter::emit(opcode op, regID src)
	{
		emit(op);
		emit_byte(src);
	}

	void emitter::emit_rm_field(uint8_t prfx, regID reg, regID rm)
	{
		emit_byte((prfx & 0b011 << 5) |
			  (reg  & 0b111 << 3) |
			  (rm   & 0b111));
	}

	void emitter::dump(bool bin /*= false*/)
	{
		for (auto byte: program) {
			if (bin)
				std::cout << byte;
			else
				std::cout << static_cast<int>(byte);
		}
	}

	std::vector<uint8_t>::const_iterator emitter::begin() const
	{
		return program.begin();
	}

	std::vector<uint8_t>::iterator emitter::begin()
	{
		return program.begin();
	}

	std::vector<uint8_t>::const_iterator emitter::end() const
	{
		return program.end();
	}

	std::vector<uint8_t>::iterator emitter::end()
	{
		return program.end();
	}

	size_t emitter::size() const
	{
		return program.size();
	}
}
