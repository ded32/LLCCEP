#include "program.hpp"
#include "../startup/startup.hpp"
#include "../emitter/emitter.hpp"

int main()
{
	LLCCEP_JIT::program prog;
	prog.emit_mov(LLCCEP_JIT::EBX, 0xFFFFFFFF);
	prog.emit_mov(LLCCEP_JIT::EAX, LLCCEP_JIT::EBX);
	prog.emit_ret();

	auto data = LLCCEP_JIT::make_program(prog);
	call(data);
	delete_program(data);

	return 0;
}
