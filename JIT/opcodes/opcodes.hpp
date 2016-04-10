#ifndef OPCODES_HPP
#define OPCODES_HPP

#include <cstdint>
#include <vector>

namespace LLCCEP_JIT {
	typedef uint8_t BYTE;

	#define APPEND_BYTE(vec, byte) vec.push_back(byte);
	#define APPEND_IMM32(vec) APPEND_BYTE(vec, 0x68);

	void AppendFINIT(std::vector<BYTE>& program);
	void AppendFADD(std::vector<BYTE>& program);
	void AppendFSUB(std::vector<BYTE>& program);
	void AppendFMUL(std::vector<BYTE>& program);
	void AppendFSEG(std::vector<BYTE>& program);
	void AppendFPUSH(std::vector<BYTE>& program, double *val);
	void AppendFPOP(std::vector<BYTE>& program, double *where);
	void AppendRET(std::vector<BYTE>& program);
}

#endif // OPCODES_HPP
