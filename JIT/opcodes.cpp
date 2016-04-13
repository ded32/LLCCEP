#include <vector>
#include <cstdint>

#include "opcodes.hpp"

#define APPEND_BYTE(vec, byte) vec.push_back(byte);

namespace LLCCEP_JIT {
	void append_imm32(bytevec& vec)
	{
		APPEND_BYTE(vec, 0x68)
	}

	void append_ret(bytevec& vec)
	{
		APPEND_BYTE(vec, 0xC3)
	}
}
