#include <iostream>

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
// mov rax, some_func
// call rax
// nop
// ret

void some_func()
{

}

int main()
{
	LLCCEP_JIT::program prog;
	void *func = *(void **)&some_func;

//	std::cout << func << "\n";

	prog.emit_mov_reg_imm(LLCCEP_JIT::RAX, 0xFFFFFFFFFFFFFFFF);
//	prog.emit_call_reg(LLCCEP_JIT::RAX);

//	prog.emit_nop();
	prog.emit_ret();

	prog.dump(true);

	auto data = LLCCEP_JIT::make_program(prog);
	call(data);
	delete_program(data);

	return 0;
}
