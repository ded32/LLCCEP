#ifndef OPCODES_HPP
#define OPCODES_HPP

#include <vector>
#include <cstdint>

namespace LLCCEP_JIT {
	typedef uint8_t BYTE;
	typedef std::vector<BYTE> bytevec;

	void append_imm32(bytevec &vec);
	void append_ret(bytevec &vec);

	void append_finit(bytevec &vec);
	void append_fclex(bytevec &vec);
	void append_fadd(bytevec &vec);
	void append_fsub(bytevec &vec);
	void append_fmul(bytevec &vec);
	void append_fseg(bytevec &vec);	
	void append_fld(bytevec &vec);
	void append_fstp(bytevec &vec);

	void append_push(bytevec &vec, double *val);
	void append_pop(bytevec &vec);	
}

#endif // OPCODES_HPP
