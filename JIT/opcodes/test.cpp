#include "opcodes.hpp"

#if defined(__linux__) || defined(__APPLE__)
	#include <sys/mman.h>
#elif defined(_WIN32)
	#include <windows.h>
#endif

#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <cstdio>
#include <cassert>

int main()
{
	std::vector<LLCCEP_JIT::BYTE> program;

	double *val = new double[2];

	LLCCEP_JIT::AppendRET(program);

#if defined(__linux__) || defined(__APPLE__)
	mprotect(&program[0], program.size(), PROT_EXEC | PROT_READ | PROT_WRITE);
#else
	VirtualProtect(&program[0], program.size(), PAGE_EXECUTE_READWRITE, 0);
#endif

	std::string call = "cat /proc/";
	call += std::to_string(getpid());
	call += "/maps";

	system(call.c_str());

	printf("\n%p\n", &program[0]);

	asm
	(
		"call *%0"
		:
		:"r"(&program[0])
		:"eax", "ebx", "ecx"
	);

	return 0;
}
