#include "program.hpp"
#include "../startup/startup.hpp"
#include "../emitter/emitter.hpp"

int main()
{
/*	LLCCEP_JIT::program prog;
	prog.emit_mov(LLCCEP_JIT::EBX, 0xFFFFFFFF);
	prog.emit_mov(LLCCEP_JIT::EAX, LLCCEP_JIT::EBX);

//	prog.emit_push_imm32(0xFF);
	prog.emit_push(LLCCEP_JIT::EAX);
	prog.emit_ret();

	prog.dump();

	auto data = LLCCEP_JIT::make_program(prog);
	call(data);
	delete_program(data);

	return 0;*/

// TODO: do far ret, go 2 gdb, see disassembly
	asm __volatile__(
		"pushq %rax\n"
		"pushq %rbx\n"
		"pushq %rcx\n"
		"pushq %rdx\n"
		"popq %rax\n"
		"popq %rbx\n"
		"popq %rcx\n"
		"popq %rdx"
	);

	return 0;
}
