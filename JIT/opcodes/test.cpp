#include <iostream>
#include <vector>

#include "opcodes.hpp"

int main()
{
	LLCCEP_JIT::bytevec vec;

	LLCCEP_JIT::append_ret(vec);

	asm(
		"call *%0"
		:
		:"r"(&vec[0])
		:"eax", "ebx", "ecx", "edx"
	);

	return 0;
}
