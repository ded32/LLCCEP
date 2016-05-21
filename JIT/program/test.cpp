#include "program.hpp"
#include "../startup/startup.hpp"
#include "../emitter/emitter.hpp"

int main()
{
/*
	LLCCEP_JIT::program prog;
	prog.emit_mov_reg_val(LLCCEP_JIT::RBX, 0xFFFFFFFF);
	prog.emit_mov_reg_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);

	prog.emit_push_32(0xFF);
	prog.emit_push_reg(LLCCEP_JIT::RAX);

	prog.emit_pop_reg(LLCCEP_JIT::RAX);
	prog.emit_pop_reg(LLCCEP_JIT::RBX);

	prog.emit_ret();

	prog.dump();

	auto data = LLCCEP_JIT::make_program(prog);
	call(data);
	delete_program(data);

	return 0;
*/
	int res = 0;

	asm __volatile__(
		"pushq $0xFF\n"
		"pushq $0xFF\n"
		"pushq $0xFF\n"
		"pushq $0xFF\n"
		"popq %eax\n"
		"popq %eax\n"
		"popq %eax\n"
		"popq %eax\n"
		:
		:
		:"eax", "ebx", "ecx", "edx"
	);

	return 0;
}
