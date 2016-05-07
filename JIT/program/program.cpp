#include <initializer_list>

#include "program.hpp"

namespace LLCCEP_JIT {
	program::program():
		emitter()
	{ }

	program::program(const program &src):
		emitter(src)
	{ }

	void program::emit_ret()
	{
		emit_byte(0xC3);
	}

	void program::emit_mov(regID dst, regID src)
	{
		emit({0x89}, dst, src);
	}

	void program::emit_mov(regID dst, uint32_t src)
	{
		emit_byte(0xB8 + dst);
		emit_data<uint32_t>(src);
	}

	void program::emit_push(regID src)
	{
		emit_byte(0x50 + src);
	}

	void program::emit_push_imm32(uint32_t src)
	{
		emit_byte(0x68);
		emit_data<uint32_t>(src);
	}

	void program::emit_pop(regID dst)
	{
		emit_byte(0x58 + dst);
	}
}
