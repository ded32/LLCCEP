#include <initializer_list>
#include <iostream>
#include <cstdlib>

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

	void program::emit_nop()
	{
		emit_byte(0x90);
	}

	void program::emit_mov_reg_reg(regID dst, regID src)
	{
		emit({0x48, dst, src});
	}

	void program::emit_mov_reg_ptr_reg(regID dst, regID src)
	{
		emit({0x48, 0x89});
		emit_rm_field(0b00, dst, src)
	}

	void program::emit_mov_reg_imm(regID dst, uint64_t src)
	{
		emit({0x48, static_cast<uint8_t>(0xB8 + dst)});
		emit_data<uint64_t>(src);
	}

	void program::emit_push_reg(regID src)
	{
		emit({0xFF, static_cast<uint8_t>(0xF0 + src)});
	}

	void program::emit_push_imm(uint64_t src)
	{
		emit_byte(0x68);
		emit_data<uint32_t>((reinterpret_cast<uint32_t *>(&src))[1]);
		emit_byte(0x68);
		emit_data<uint32_t>((reinterpret_cast<uint32_t *>(&src))[0]);
	}

	void program::emit_pop_reg(regID dst)
	{
		emit_byte(static_cast<uint8_t>(0x58 + dst));
	}

	void program::emit_pop_reg_ptr(regID src)
	{
		if (src == RSP || src == RBP) {
			std::cout << "SP & BP are denied to do reg_ptr_pop";
			std::exit(EXIT_FAILURE);
		}

		emit({0x8F, src});
	}

	void program::emit_finit()
	{
		emit({0x9B, 0xDB, 0xE3});
	}

	void program::emit_fclex()
	{
		emit({0x9B, 0xDB, 0xE2});
	}

	void program::emit_fld_esp()
	{
		emit({0xDD, 0x04, 0x24});
	}

	void program::emit_fld_const(fld_const val)
	{
		emit({0xD9, static_cast<uint8_t>(0xE8 + val)});
	}

	void program::emit_fabs()
	{
		emit({0xD9, 0xE1});
	}

	void program::emit_fadd()
	{
		emit({0xD8, 0xC0 + 1});
	}

	void program::emit_fsub()
	{
		emit({0xDC, 0xE8 + 1});
	}

	void program::emit_fmul()
	{
		emit({0xD8, 0xC8 + 1});
	}

	void program::emit_fdiv()
	{
		emit({0xDC, 0xF8 + 1});
	}

	void program::emit_fsqrt()
	{
		emit({0xD9, 0xFA});
	}

	void program::emit_fsin()
	{
		emit({0xD9, 0xFE});
	}

	void program::emit_fcos()
	{
		emit({0xD9, 0xFF});
	}

	void program::emit_fptan()
	{
		emit({0xD9, 0xF2});
	}

	void program::emit_fpatan()
	{
		emit({0xD9, 0xF3});
	}

	void program::emit_fstp_esp()
	{
		emit({0xDD, 0x1C, 0x24});
	}

	void program::emit_call_reg(regID id)
	{
		emit({0xFF, static_cast<uint8_t>(0xD0 + id)});
	}
}
