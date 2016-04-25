#include <vector>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <cmath>

#if defined(__linux__) || defined(__MACH__)
#	include <sys/types.h>
#	include <sys/mman.h>
#	include <unistd.h>
#elif defined(_WIN32)
#	include <windows.h>
#endif 

#include "instruction.hpp"

namespace LLCCEP_JIT {
	instruction::instruction():
		opcode(),
		rmdata()
	{ }

	instruction::instruction(std::vector<uint8_t> opcodes):
		opcode(opcodes),
		rmdata()
	{ }

	instruction::instruction(std::vector<uint8_t> opcodes, uint8_t rmval):
		opcode(opcodes),
		rmdata()
	{ }

	instruction::~instruction()
	{ }

	void instruction::append_opcode(uint8_t val)
	{
		opcode.push_back(val);
	}

	void instruction::set_rm_field(uint8_t rmval)
	{
		rmdata.exist = true;
		rmdata.val = rmval;
	}

#define GETBIT(val, id) ((val >> (7 - id)) & 0b00000001)
	void instruction::append_rmfield()
	{
		uint8_t res = 0;

		for (unsigned i = 0; i < opcode.size(); i++)
			res += GETBIT(rmdata.val, i) * std::pow(2, 7 - i);
	
		opcode.push_back(res);
	}

	void instruction::dump_data()
	{
		for (size_t i = 0; i < opcode.size(); i++)
			std::cout << std::hex << opcode[i] << " ";

		std::cout << rmdata.exist << " " << rmdata.val << "\n";
	}

#if defined(__linux__) || defined(__MACH__)
	size_t align(size_t sz, size_t boundary)
	{
		return (sz / boundary + (sz % boundary > 0)) * boundary;
	}
#endif

	static __attribute__((__always_inline__)) inline void call(uint8_t *program)
	{
		asm(
			"call *%0"
			:
			:"r"(program)
			:"eax", "ebx", "ecx", "edx"
		);
	} 

	void exec(std::vector<instruction> program)
	{
		size_t sz = 0;
		for (size_t i = 0; i < program.size(); i++)
			sz += program[i].opcode.size();
		
		uint8_t *mem = 0;

#if defined(__linux__) || defined(__MACH__)
		sz = align(sz, getpagesize());
		mem = reinterpret_cast<uint8_t *>(mmap(0, sz, PROT_READ | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0));
#elif defined(_WIN32)
		mem = reinterpret_cast<uint8_t *>VirtualAlloc(0, sz + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READ);
#endif

		call(mem);

#if defined(__linux__) || defined(__MACH__)
		munmap(mem, sz);
#elif defined(_WIN32)
		VirtualFree(mem, sz + 1, MEM_DECOMMIT);
#endif
	}
}
