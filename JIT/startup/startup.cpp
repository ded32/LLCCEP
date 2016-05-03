#if defined(__linux__) || defined(__MACH__) || defined(__UNIX__)
#	include <sys/mman.h>
#	include <sys/types.h>
#	include <unistd.h>
#elif defined(_WIN32)
#	include <windows.h>
#else
#	error _________________________________
#	error | Error! Unknown OS: required 
#	error | windows or some unix
#	error |________________________________
#endif // platform-dependent code

#include <vector>
#include <cstddef>
#include <cstdint>
#include <algorithm>

#include "../emitter/emitter.hpp"
#include "program.hpp"
#include "startup.hpp"

static inline size_t align(size_t size, size_t boundary)
{
	return (size / boundary + (size % boundary > 0) * boundary);
}

static inline void *allocate_exec(size_t size)
{
	void *res = 0;

#if defined(__linux__) || defined(__MACH__) || defined(__UNIX__)
	size_t sz = align(size, getpagesize());
	res = mmap(0, sz, PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_ANON, -1, 0);
#elif defined(_WIN32)
	res = VirtualAlloc(0, size + 1, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
#endif // platform-dependent code

	return res;
}


namespace LLCCEP_JIT {
	program make_program(emitter emit)
	{
		program res = {};
		res.mem = allocate_exec(emit.program_.size());
#if defined(__linux__) || defined(__MACH__) || defined(__UNIX__)
		res.sz = align(emit.program_.size(), getpagesize());
#elif defined(_WIN32)
		res.sz = emit.program_.size() + 1;
#endif // platform-dependent code

		std::copy(emit.program_.begin(), emit.program_.end(), static_cast<uint8_t *>(res.mem));

		return res;
	}

	void call(program data)
	{
		asm __volatile__(
			"call *%0"
			:
			:"r"(data.mem)
			:"eax", "ebx", "ecx", "edx"
		);
	}

	void delete_program(program data)
	{
#if defined(__linux__) || defined(__MACH__) || defined(__UNIX__)
		munmap(data.mem, data.sz);
#elif defined(_WIN32)
		VirtualFree(data.mem, data.sz);
#endif // platform-dependent code
	}
}
