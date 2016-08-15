#include <cstddef>
#include <cstdint>
#include <new>
#include <cstring>
#include <STDExtras.hpp>

#include "mm.hpp"

#define MM_CHECK_BLOCK(cond) \
{ \
	if ((cond && OK()) || (!cond && !OK())) { \
		throw RUNTIME_EXCEPTION(CONSTUCT_MSG( \
			"memoryManager at %p is %sOK, how %sexcepted", \
			(cond)?("not "):(""), \
			(cond)?(""):("not "))); \
	} \
}

#define MM_OK_BLOCK MM_CHECK_BLOCK(true)
#define MM_NOTOK_BLOCK MM_CHECK_BLOCK(false)

LLCCEP_exec::memoryManager::memoryManager():
	_mem(0),
	_sz(0)
{ }

LLCCEP_exec::memoryManager::~memoryManager()
{
	freeElements();
}

void LLCCEP_exec::memoryManager::allocateElements(size_t amount)
{
	MM_NOTOK_BLOCK

	_mem = new (::std::nothrow) double[_sz = amount];
	MM_OK_BLOCK

	::std::memset(_mem, 0, _sz * sizeof(double));

	MM_OK_BLOCK
}

void LLCCEP_exec::memoryManager::freeElements()
{
	delete _mem;
	_mem = 0;
	_sz = 0;

	MM_NOTOK_BLOCK
}

::std::string LLCCEP_exec::memoryManager::getString(size_t offset)
{
	MM_OK_BLOCK

	::std::string res;
	for (size_t i = offset; i < _sz && _mem[i]; i++)
		res += static_cast<uint8_t>(_mem[i]);

	MM_OK_BLOCK

	return res;
}

void LLCCEP_exec::memoryManager::writeString(size_t offset, ::std::string str)
{
	MM_OK_BLOCK

	for (size_t i = offset; i < _sz && i - offset < str.length(); i++)
		_mem[i] = static_cast<double>(str[i - offset]);

	MM_OK_BLOCK
}

#undef MM_CHECK_BLOCK
#undef MM_OK_BLOCK
#undef MM_NOTOK_BLOCK
