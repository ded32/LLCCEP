#include <cstdint>
#include <cassert>
#include <vector>

#include "opcodes.hpp"

namespace LLCCEP_JIT {
	void AppendFINIT(std::vector<BYTE>& program)
	{
		//Initialize FPU after checking for pending unmasked floating-point exceptions.
		APPEND_BYTE(program, 0x9B)
		APPEND_BYTE(program, 0xDB)
		APPEND_BYTE(program, 0xE3)
	}

	void AppendFADD(std::vector<BYTE>& program)
	{
		APPEND_BYTE(program, 0xDC)
		APPEND_BYTE(program, 0x4)
		APPEND_BYTE(program, 0x24)
	}

	void AppendFSUB(std::vector<BYTE>& program)
	{
		APPEND_BYTE(program, 0xDC)
		APPEND_BYTE(program, 0x24)
		APPEND_BYTE(program, 0x24)
	}

	void AppendFMUL(std::vector<BYTE>& program)
	{
		APPEND_BYTE(program, 0xDC)
		APPEND_BYTE(program, 0xC)
		APPEND_BYTE(program, 0x24)
	}

	void AppendFSEG(std::vector<BYTE>& program)
	{
		APPEND_BYTE(program, 0xDC)
		APPEND_BYTE(program, 0x34)
		APPEND_BYTE(program, 0x24)
	}

	void AppendFPUSH(std::vector<BYTE>& program, double *val)
	{
		assert(val);

		union {
			uint8_t addr[sizeof(double *)];
			double *ptr;
		} ptr;

		ptr.ptr = val;

		APPEND_BYTE(program, 0xDD)
		
		for (unsigned i = 0; i < sizeof(double *); i++)
			APPEND_BYTE(program, ptr.addr[i]);

		APPEND_BYTE(program, 0x24)
	}

	void AppendFPOP(std::vector<BYTE>& program, double *where)
	{
		assert(where);

		union {
			uint8_t addr[sizeof(double *)];
			double *ptr;
		} ptr;

		ptr.ptr = where;
	}
}
