#include <vector>
#include <cstdint>
#include <cassert>

#include "opcodes.hpp"

#define APPEND_BYTE(vec, byte) vec.push_back(byte);
static void append_address(LLCCEP_JIT::bytevec &vec, char *addr)
{
	for (unsigned i = 0; i < 4; i++)
		APPEND_BYTE(vec, addr[i]);
}

namespace LLCCEP_JIT {
	void append_ret(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xC3)
	}

	void append_fstp(bytevec &vec, void *mem)
	{
		APPEND_BYTE(vec, 0x15)

		append_address(vec, (char *)&mem);
	}

	void append_finit(bytevec &vec)
	{
		APPEND_BYTE(vec, 0x9B)
		APPEND_BYTE(vec, 0xDB)
		APPEND_BYTE(vec, 0xE3)
	}

	void append_fclex(bytevec &vec)
	{
		APPEND_BYTE(vec, 0x9B)
		APPEND_BYTE(vec, 0xDB)
		APPEND_BYTE(vec, 0xE2)
	}

	void append_fld_ptr32_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xD9)
		APPEND_BYTE(vec, 0x04)
		APPEND_BYTE(vec, 0x24)
	}

	void append_mov_eax_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0x8B)
		APPEND_BYTE(vec, 0x44)
		APPEND_BYTE(vec, 0x24)
		APPEND_BYTE(vec, 0x04)
	}

	void append_mov_ecx_ptr32(bytevec &vec, void *mem)
	{
		APPEND_BYTE(vec, 0x8B)
		APPEND_BYTE(vec, 0x0D)

		append_address(vec, (char *)&mem);
	}
	
	void append_push_reg(bytevec &vec, BYTE reg)
	{
		APPEND_BYTE(vec, 0x50 + reg)
	}

	void append_push_ptr32_reg(bytevec &vec, BYTE reg)
	{
		APPEND_BYTE(vec, 0xFF)
		APPEND_BYTE(vec, 0x30 + reg)
	}

	void append_add(bytevec &vec, BYTE reg, BYTE val)
	{
		APPEND_BYTE(vec, 0x83)
		APPEND_BYTE(vec, 0xC0 + reg)
		APPEND_BYTE(vec, val)
	}

	void append_add_ptr32_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xD8)
		APPEND_BYTE(vec, 0x04)
		APPEND_BYTE(vec, 0x24)
	}

	void append_sub_ptr32_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xD8)
		APPEND_BYTE(vec, 0x24)
		APPEND_BYTE(vec, 0x24)
	}

	void append_mul_ptr32_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xD8)
		APPEND_BYTE(vec, 0x0C)
		APPEND_BYTE(vec, 0x24)
	}

	void append_seg_ptr32_esp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xD8)
		APPEND_BYTE(vec, 0x34)
		APPEND_BYTE(vec, 0x24)
	}

	void append_push_imm32(bytevec &vec, void *ptr)
	{
		APPEND_BYTE(vec, 0x68)
		append_address(vec, (char *)ptr);
	}
}
