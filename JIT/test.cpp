#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>

#if defined(__linux__) || defined(__APPLE__)
#include <sys/mman.h>
#include <unistd.h>
#endif

#include "opcodes.cpp"

#define $(cmd)                             \
({                                         \
	std::cout << #cmd << "... ";       \
                                           \
	auto _ret = ({ cmd; });            \
                                           \
	std::cout << "[" << _ret << "]\n"; \
	_ret;                              \
})

__attribute__((__always_inline__)) inline int call(const uint8_t* memory)
{
	asm __volatile__(
		"call *%0"
		:
		:"r" (memory)
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
	LLCCEP_JIT::append_ret(vec);

	uint8_t *memory = 0;

	size_t sz = align(vec.size(), getpagesize());
	$(sz);

#if defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
	$(memory = (uint8_t*)mmap(0, sz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0));
	$(std::copy(vec.begin(), vec.end(), memory));

	$(call(memory));

	$(munmap(memory, sz));
#elif defined(_WIN32)
	$(call(&vec[0]));
#endif

	return 0;
}
    

