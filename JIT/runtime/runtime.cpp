#include "runtime.hpp"
#include "../../exec/softcore/softcore.hpp"

LLCCEP_JIT::runtimeManager::runtimeManager():
	softcore()
{ }

void *LLCCEP_JIT::runtimeManager::getSwiEmulatePtr()
{
	union {
		void (LLCCEP_exec::softcore:: *member)(LLCCEP_exec::instruction);
		void *pointer;
	} val;

	val.member = &LLCCEP_JIT::runtimeManager::emulated_swi;
	return val.pointer;
}

void *LLCCEP_JIT::runtimeManager::getCmpPtr()
{
	return reinterpret_cast<void *>(&_cmp);
}

void *LLCCEP_JIT::runtimeManager::getRegPtr(size_t id)
{
	return reinterpret_cast<void *>(&(_regs[id]));
}

void *LLCCEP_JIT::runtimeManager::getMemoryBeginning()
{
	return _mm->getMemBeginning();
}

LLCCEP_exec::codeReader *LLCCEP_JIT::runtimeManager::getCodeReader()
{
	return _reader;
}
