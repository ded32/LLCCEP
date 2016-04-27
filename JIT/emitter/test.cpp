#include "emitter.hpp"

int main()
{
	LLCCEP_JIT::emitter emit;
	emit.emit({0xC3});
	emit.dump();

	return 0;
}
