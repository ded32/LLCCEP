#ifndef OPCODES_HPP
#define OPCODES_HPP

#include <vector>
#include <cstdint>

namespace LLCCEP_JIT {
	typedef uint8_t BYTE;
	typedef std::vector<BYTE> bytevec;	

	void append_imm32(bytevec& vec);
	void append_ret(bytevec& vec);
}

#endif // OPCODES_HPP
