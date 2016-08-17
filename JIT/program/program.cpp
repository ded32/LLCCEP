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
		emit_rm_field(0b00, dst, src);
	}

	void program::emit_mov_reg_reg_ptr(regID dst, regID src)
	{
		emit({0x48, 0x8B});
		emit_rm_field(0b00, dst, src);
	}

	void program::emit_mov_reg_imm(regID dst, uint64_t src)
	{
		emit({0x48, static_cast<uint8_t>(0xB8 + dst)});
		emit_data<uint64_t>(src);
	}

	void program::emit_shl_cl(regID what)
	{
		emit({0x48, 0xD3, static_cast<uint8_t>(0xE0 + what)});
	}

	void program::emit_shr_cl(regID what)
	{
		emit({0x48, 0xD3, static_cast<uint8_t>(0xE8 + what)});
	}

	void program::emit_jmp(uint32_t offset)
	{
		emit({0xE9});
		emit_data<uint32_t>(offset);
	}

#define JCC_BLOCK(cc) \
({ \
	emit({0x0F, cc}); \
	emit_data<uint32_t>(offset); \
});
	void program::emit_jle(uint32_t offset)
	{
		JCC_BLOCK(0x8E)
	}

	void program::emit_jl(uint32_t offset)
	{
		JCC_BLOCK(0x8C)
	}

	void program::emit_jge(uint32_t offset)
	{
		JCC_BLOCK(0x8D)
	}

	void program::emit_jg(uint32_t offset)
	{
		JCC_BLOCK(0x8F)
	}

	void program::emit_je(uint32_t offset)
	{
		JCC_BLOCK(0x84)
	}

	void program::emit_jne(uint32_t offset)
	{
		JCC_BLOCK(0x85)
	}
#undef JCC_BLOCK

	void program::emit_fistp(regID dst)
	{
		emit({0xDF, static_cast<uint8_t>(0x38 + dst)});
	}

	void program::emit_fild(regID dst)
	{
		emit({0xDF, static_cast<uint8_t>(0x28 + dst)});
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
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"RSP & RBP are denied to be used by\n"
				"reg_ptr_pop"))
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

	void program::emit_fld(LLCCEP_JIT::regID src)
	{
		emit({0xDD, src});
		if (src == RSP)
			emit_byte(0x24);
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

	void program::emit_fstp_reg_ptr(regID dest)
	{
		emit({0xDD, static_cast<uint8_t>(0x18 + dest)});
		if (dest == RSP)
			emit_byte(0x24);
	}

	void program::emit_call_reg(regID id)
	{
		emit({0xFF, static_cast<uint8_t>(0xD0 + id)});
	}

	void program::emit_cmp_reg_reg(regID op0, regID op1)
	{
		emit({REX_W, 0x39});
		emit_rm_field(0b11, op0, op1);
	}

	void program::emit_and_reg_reg(regID op0, regID op1)
	{
		emit({REX_W, 0x21});
		emit_rm_field(0b11, op0, op1);
	}

	void program::emit_or_reg_reg(regID op0, regID op1)
	{
		emit({REX_W, 0x09});
		emit_rm_field(0b11, op0, op1);
	}

	void program::emit_xor_reg_reg(regID op0, regID op1)
	{
		emit({REX_W, 0x31});
		emit_rm_field(0b11, op0, op1);
	}
}
