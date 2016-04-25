#include "instruction.hpp"

void finit(std::vector<LLCCEP_JIT::instruction> &program)
{
	LLCCEP_JIT::instruction inst;
	inst.append_opcode(0x9B);
	inst.append_opcode(0xDB);
	inst.append_opcode(0xE3);

	program.push_back(inst);
}

void ret(std::vector<LLCCEP_JIT::instruction> &program)
{
	LLCCEP_JIT::instruction inst;
	inst.append_opcode(0xC3);

	program.push_back(inst);
}

void dump(std::vector<LLCCEP_JIT::instruction> program)
{
	for (size_t i = 0; i < program.size(); i++)
		program[i].dump_data();
}

int main()
{
	std::vector<LLCCEP_JIT::instruction> program;
	finit(program);
	ret(program);

	dump(program);

	LLCCEP_JIT::exec(program);

	return 0;
}
