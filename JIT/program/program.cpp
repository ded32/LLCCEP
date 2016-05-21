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

	void program::emit_mov_reg_reg(regID dst, regID src)
	{
		emit({0x89}, dst, src);
	}

	void program::emit_mov_reg_32(regID dst, uint32_t src)
	{
		emit_byte(0xB8 + dst);
		emit_data<uint32_t>(src);
	}

	void program::emit_push_reg(regID src)
	{
		emit_byte(0x50 + src);
	}

	void program::emit_push_32(uint32_t src)
	{
		emit_byte(0x68);
		emit_data<uint32_t>(src);
	}

	void program::emit_pop_reg(regID dst)
	{
		emit_byte(0x58 + dst);
	}

	void program::emit_finit()
	{
		emit({0x9B, 0xDB, 0xE3});
	}

	void program::emit_fclex()
	{
		emit({0x9B, 0xDB, 0xE2});
	}

	void program::emit_fld_reg_mem(regID src)
	{
		emit({0xDD, src});
	}

	void program::emit_fld_const(fld_const val)
	{
		emit({0xD9, 0xE8 + val});
	}
}
