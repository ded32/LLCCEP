#include "instruction.hpp"

int main()
{
	LLCCEP_JIT::instruction inst;
	inst.append_opcode(0xC3);

	return 0;
}
