#include <cstddef>
#include <cstdint>
#include <new>
#include <cstring>
#include <STDExtras.hpp>

#include "mm.hpp"

#define MM_CHECK_BLOCK(cond) \
{ \
	if ((cond && OK()) || (!cond && !OK())) { \
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
			"memoryManager at %p is %sOK, how %sexcepted", \
			this, \
			(OK())?(""):("not "), \
			(OK())?("not "):(""))); \
	} \
}

#define MM_OK_BLOCK MM_CHECK_BLOCK(false)
#define MM_NOTOK_BLOCK MM_CHECK_BLOCK(true)

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

	_mem = new (::std::nothrow) double[amount];
	_sz = amount;
	MM_OK_BLOCK

	::std::memset(_mem, 0, _sz * sizeof(double));

	MM_OK_BLOCK
}

void LLCCEP_exec::memoryManager::freeElements()
{
	delete _mem;
	_mem = 0;
	_sz = 0;
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

size_t LLCCEP_exec::memoryManager::getMemSize() const
{
	MM_OK_BLOCK

	return _sz;
}

void *LLCCEP_exec::memoryManager::getMemBeginning() const
{
	MM_OK_BLOCK

	return reinterpret_cast<void *>(getMemBeginning());
}

double LLCCEP_exec::memoryManager::operator[](size_t id) const
{
	MM_OK_BLOCK

	if (id >= _sz) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Overbounding while access to "
			"memoryManager's at %p data!\n",
			this))
	}

	return _mem[id];
}

double &LLCCEP_exec::memoryManager::operator[](size_t id)
{
	MM_OK_BLOCK

	if (id >= _sz) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Overbounding while access to "
			"memoryManager's at %p data!\n",
			this))
	}

	return _mem[id];
}

bool LLCCEP_exec::memoryManager::OK() const
{
	return _sz && _mem;
}

#undef MM_CHECK_BLOCK
#undef MM_OK_BLOCK
#undef MM_NOTOK_BLOCK
