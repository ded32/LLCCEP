#include "program.hpp"
#include "../startup/startup.hpp"
#include "../emitter/emitter.hpp"

// finit
// fclex
// mov rbx, 0xFFFFFFFF
// mov rax, rbx
// push 0xFF
// push rax
// pop rax
// pop rbx
// nop
// ret

int main()
{
	LLCCEP_JIT::program prog;

	prog.emit_finit();
	prog.emit_fclex();
	prog.emit_mov_reg_imm(LLCCEP_JIT::RBX, 0xFFFFFFFF);
	prog.emit_mov_reg_reg(LLCCEP_JIT::RAX, LLCCEP_JIT::RBX);

	prog.emit_push_imm(0xFF);
	prog.emit_push_reg(LLCCEP_JIT::RAX);

	prog.emit_pop_reg(LLCCEP_JIT::RAX);
	prog.emit_pop_reg(LLCCEP_JIT::RBX);

	prog.emit_nop();
	prog.emit_ret();

	prog.dump();

	auto data = LLCCEP_JIT::make_program(prog);
	call(data);
	delete_program(data);

	return 0;
}
