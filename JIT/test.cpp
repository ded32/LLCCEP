#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

#if defined(__linux__) || defined(__APPLE__)
#	include <sys/mman.h>
#	include <unistd.h>
#elif defined(_WIN32)
#	include <windows.h>
#endif

#include "opcodes.hpp"

#define $(cmd)                             \
({                                         \
	std::cout << #cmd << "... ";       \
                                           \
	auto _ret = ({cmd;});              \
                                           \
	std::cout << "[" << _ret << "]\n"; \
	_ret;                              \
})

__attribute__((__always_inline__)) inline int call(const uint8_t *memory)
{
	asm __volatile__(
		"call *%0"
		:
		:"r"(memory)
		:"eax", "ebx", "ecx", "edx"
	);

	return 0;
}

size_t align(size_t size, size_t boundary)
{
	return (size / boundary + (size % boundary > 0)) * boundary;
}

int main()
{
	LLCCEP_JIT::bytevec vec;

	int32_t val = 43;

	LLCCEP_JIT::append_finit(vec);
	LLCCEP_JIT::append_fclex(vec);
	LLCCEP_JIT::append_mov_eax_esp(vec);
	LLCCEP_JIT::append_mov_ecx_ptr32(vec, &val);
	LLCCEP_JIT::append_ret(vec);

	uint8_t *memory = 0;

#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
	size_t sz = align(vec.size(), getpagesize());
	$(memory = reinterpret_cast<uint8_t *>(mmap(0, sz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0)));
	$(std::copy(vec.begin(), vec.end(), memory));
	$(call(memory));
	$(munmap(memory, sz));
#elif defined(_WIN32)
	$(memory = reinterpret_cast<uint8_t *>(VirtualAlloc(0, vec.size() + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE)));
	$(std::copy(vec.begin(), vec.end(), memory));
	$(call(memory));
	$(VirtualFree(memory, vec.size() + 1, MEM_DECOMMIT));
#endif

	return 0;
}
