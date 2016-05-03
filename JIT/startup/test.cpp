#include <iostream>
#include <iomanip>

#include "startup.hpp"
#include "../emitter/emitter.hpp"
#include "program.hpp"

static inline void append_mov_rr(LLCCEP_JIT::emitter &emitter, LLCCEP_JIT::regID dst, LLCCEP_JIT::regID src)
{
	emitter.emit({0x89}, dst, src);
}

static inline void append_mov_rv(LLCCEP_JIT::emitter &emitter, LLCCEP_JIT::regID dst, uint32_t val)
{
	emitter.emit_byte(0xB8 + dst);
	emitter.emit_data<uint32_t>(val);
}

static inline void append_ret(LLCCEP_JIT::emitter &emitter)
{
	emitter.emit_byte(0xC3);
}

int main()
{
	LLCCEP_JIT::emitter emit;
	append_mov_rv(emit, LLCCEP_JIT::EBX, 44);
	append_mov_rr(emit, LLCCEP_JIT::EAX, LLCCEP_JIT::EBX);
	append_ret(emit);

	emit.dump();

	LLCCEP_JIT::sys::program prog = LLCCEP_JIT::make_program(emit);
	LLCCEP_JIT::call(prog);
	LLCCEP_JIT::delete_program(prog);

	return 0;
}
