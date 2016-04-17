#ifndef OPCODES_HPP
#define OPCODES_HPP

#include <vector>
#include <cstdint>

#define EAX 0
#define EBX 3
#define ECX 1
#define EDX 2

#define ESP 4

namespace LLCCEP_JIT {
	typedef uint8_t BYTE;
	typedef std::vector<BYTE> bytevec;

	void append_ret(bytevec &vec);

	void append_fstp(bytevec &vec, void *mem);
	void append_finit(bytevec &vec);
	void append_fclex(bytevec &vec);
	void append_fld_ptr32_esp(bytevec &vec);

	void append_mov_eax_esp(bytevec &vec);
	void append_mov_ecx_ptr32(bytevec &vec, void *mem);
	void append_push_reg(bytevec &vec, BYTE reg);
	void append_push_ptr32_reg(bytevec &vec, BYTE reg);

	void append_add(bytevec &vec, BYTE reg, BYTE val);
	void append_add_ptr32_esp(bytevec &vec);
	void append_sub_ptr32_esp(bytevec &vec);
	void append_mul_ptr32_esp(bytevec &vec);
	void append_seg_ptr32_esp(bytevec &vec);

	void append_push_imm32(bytevec &vec, void *ptr);
}

#endif // OPCODES_HPP
