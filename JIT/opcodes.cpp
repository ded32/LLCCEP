#include <vector>
#include <cstdint>

#include "opcodes.hpp"

#define APPEND_BYTE(vec, byte) vec.push_back(byte);

namespace LLCCEP_JIT {
	void append_imm32(bytevec &vec)
	{
		APPEND_BYTE(vec, 0x68)
	}

	void append_ret(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xC3)
	}

	void append_finit(bytevec& vec)
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


#define FPU_STD_APPEND(vec) APPEND_BYTE(vec, 0x24)
	void append_fadd(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDC)
		APPEND_BYTE(vec, 4)
		FPU_STD_APPEND(vec)
	}

	void append_fsub(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDC)
		APPEND_BYTE(vec, 36)
		FPU_STD_APPEND(vec)
	}

	void append_fmul(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDC)
		APPEND_BYTE(vec, 12)
		FPU_STD_APPEND(vec)
	}

	void append_fseg(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDC)
		APPEND_BYTE(vec, 52)
		FPU_STD_APPEND(vec)
	}

	void append_fld(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDD)
		APPEND_BYTE(vec, 4)
		FPU_STD_APPEND(vec)
	}

	void append_fstp(bytevec &vec)
	{
		APPEND_BYTE(vec, 0xDD)
		APPEND_BYTE(vec, 28)
		FPU_STD_APPEND(vec)
	}

	void append_push(bytevec &vec, double *val)
	{
		uint8_t *bytes = (uint8_t *)val;

		append_imm32(vec);
		for (unsigned i = 0; i < 4; i++)
			APPEND_BYTE(vec, bytes[i])

		append_imm32(vec);
		for (unsigned i = 4; i < 8; i++)
			APPEND_BYTE(vec, bytes[i])
	}

	void append_pop(bytevec &vec)
	{
		APPEND_BYTE(vec, 0x83)
		APPEND_BYTE(vec, 0xC4)
		APPEND_BYTE(vec, 0x8)
	}
}
