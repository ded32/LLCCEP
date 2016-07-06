#include "emitter.hpp"

static inline void append_mov_rr(LLCCEP_JIT::emitter &emitter, LLCCEP_JIT::regID dst, LLCCEP_JIT::regID src)
{
	emitter.emit({0x89}, dst, src);
}

static inline void append_mov_rv(LLCCEP_JIT::emitter &emitter, LLCCEP_JIT::regID dst, uint32_t val)
{
	emitter.emit_byte(0xB8 + dst);
	emitter.emit_data<uint32_t>(val);
}

int main()
{
	LLCCEP_JIT::emitter emit;
	append_mov_rv(emit, LLCCEP_JIT::EBX, 0xFFFFFFFF);
	append_mov_rr(emit, LLCCEP_JIT::EAX, LLCCEP_JIT::EBX);
	emit.dump();

	return 0;
}
