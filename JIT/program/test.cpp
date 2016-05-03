#include "../emitter/emitter.hpp"
#include "program.hpp"
#include "../startup/startup.hpp"

int main()
{
	LLCCEP_JIT::program prog;
	prog.emit_mov(LLCCEP_JIT::EBX, 0xFFFFFFFF);
	prog.emit_mov(LLCCEP_JIT::EAX, LLCCEP_JIT::EBX);
	prog.emit_ret();

	LLCCEP_JIT::sys::program = LLCCEP_JIT::make_program(prog);
	call(prog);
	delete_program(prog);

	return 0;
}
