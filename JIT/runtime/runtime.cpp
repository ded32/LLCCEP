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
	return reinterpret_value<void (LLCCEP_exec::softcore:: *)(LLCCEP_exec::instruction),
				 void *>(&LLCCEP_JIT::runtimeManager::emulated_swi);
}

void *LLCCEP_JIT::runtimeManager::getStregsEmulatePtr()
{
	return reinterpret_value<void (LLCCEP_exec::softcore:: *)(LLCCEP_exec::instruction),
				 void *>(&LLCCEP_JIT::runtimeManager::emulated_stregs);
}

void *LLCCEP_JIT::runtimeManager::getLdregsEmulatePtr()
{
	return reinterpret_value<void (LLCCEP_exec::softcore:: *)(LLCCEP_exec::instruction),
				 void *>(&LLCCEP_JIT::runtimeManager::emulated_ldregs);
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
