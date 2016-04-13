#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

#if defined(__linux__) || defined(__APPLE__)
#	include <sys/mman.h>
#endif // defined

#include "opcodes.cpp"

int main()
{
	LLCCEP_JIT::bytevec vec;
	LLCCEP_JIT::append_ret(vec);

	uint8_t *memory = 0;

#if defined(__linux__) || defined(__APPLE__)
	memory = (uint8_t *)mmap(0, vec.size(), PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE, -1, 0);
	mprotect(memory, vec.size(), PROT_WRITE | PROT_EXEC | PROT_READ);

	std::copy(vec.begin(), vec.end(), memory);	
#endif

	asm(
		"call *%0"
		:
		:"r"(memory)
		:"eax", "ebx", "ecx", "edx"
	);

	return 0;
}
