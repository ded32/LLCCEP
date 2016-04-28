#include "instruction_manager.hpp"

int main()
{
	LLCCEP_JIT::instruction inst;
	inst.append_opcode(0xC3);

	inst.dump();

	return 0;
}
