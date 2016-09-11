#include <convert.hpp>

#include "runtime.hpp"
#include "../../exec/softcore/softcore.hpp"

LLCCEP_JIT::runtimeManager::runtimeManager():
	softcore()
{ }

void *LLCCEP_JIT::runtimeManager::getSoftcorePtr()
{
	return dynamic_cast<LLCCEP_exec::softcore *>(this);
}

void *LLCCEP_JIT::runtimeManager::getSwiEmulatePtr()
{
	auto func = ::std::mem_fn(&LLCCEP_JIT::runtimeManager::emulated_swi);
	return func;
}

void *LLCCEP_JIT::runtimeManager::getStregsEmulatePtr()
{
	return reinterpret_value<void (*)(LLCCEP_exec::instruction),
				 void *>(&stregsPtr);
}

void *LLCCEP_JIT::runtimeManager::getLdregsEmulatePtr()
{
	return reinterpret_value<void (*)(LLCCEP_exec::instruction),
				 void *>(&ldregsPtr);
}

void *LLCCEP_JIT::runtimeManager::getCmpPtr()
{
	return reinterpret_cast<void *>(&cmp);
}

void *LLCCEP_JIT::runtimeManager::getRegPtr(size_t id)
{
	return reinterpret_cast<void *>(&(regs[id]));
}

void *LLCCEP_JIT::runtimeManager::getMemoryBeginning()
{
	return mm->getMemBeginning();
}

LLCCEP_exec::codeReader *LLCCEP_JIT::runtimeManager::getCodeReader()
{
	return reader;
}
