#include <cstddef>
#include <cstdint>
#include <new>
#include <cstring>
#include <STDExtras.hpp>

#include "mm.hpp"

#define MM_CHECK_BLOCK(cond) DEFAULT_CHECK_BLOCK(cond, this, OK())
#define MM_OK_BLOCK MM_CHECK_BLOCK(false)
#define MM_NOTOK_BLOCK MM_CHECK_BLOCK(true)

LLCCEP_exec::memoryManager::memoryManager():
	mem(NULL),
	actualSz(0),
	maxSz(0)
{ }

LLCCEP_exec::memoryManager::~memoryManager()
{
	freeElements();
}

void LLCCEP_exec::memoryManager::allocateElements(size_t amount)
{
	MM_NOTOK_BLOCK

	maxSz = amount;

	MM_OK_BLOCK
}

void LLCCEP_exec::memoryManager::freeElements()
{
	free((void *)mem);
	mem = NULL;
	maxSz = 0;
	actualSz = 0;
}

::std::string LLCCEP_exec::memoryManager::getString(size_t offset)
{
	MM_OK_BLOCK

	::std::string res;
	for (size_t i = offset; i < maxSz && at(i); i++)
		res += static_cast<uint8_t>(at(i));

	MM_OK_BLOCK

	return res;
}

void LLCCEP_exec::memoryManager::writeString(size_t offset, ::std::string str)
{
	MM_OK_BLOCK

	for (size_t i = offset; i < maxSz && i - offset < str.length(); i++)
		at(i) = static_cast<double>(str[i - offset]);

	MM_OK_BLOCK
}

size_t LLCCEP_exec::memoryManager::getMemSize() const
{
	MM_OK_BLOCK

	return maxSz;
}

void *LLCCEP_exec::memoryManager::getMemBeginning()
{
	MM_OK_BLOCK

	return reinterpret_cast<void *>(addr(0));
}

double &LLCCEP_exec::memoryManager::operator[](size_t id)
{
	MM_OK_BLOCK;

	if (id >= maxSz) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Overbounding while access to "
			"memoryManager's at %p data!\n",
			this))
	}

	return at(id);
}

bool LLCCEP_exec::memoryManager::OK() const
{
	return maxSz;
}

double &LLCCEP_exec::memoryManager::at(size_t id)
{
	MM_OK_BLOCK;
	return *addr(id);
}

double *LLCCEP_exec::memoryManager::addr(size_t id)
{
	MM_OK_BLOCK;

	if (id >= maxSz) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Overbounding while accessing to mem via memory manager"));
	}

	if (id >= actualSz) {
		mem = (double *)realloc(mem, (actualSz = id + 1));
		if (!mem) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Failed to reallocate memory for memoryManager: %s",
				::std::extras::strerror_safe(errno).c_str()));
		}
	}

	return mem + id * sizeof(double);
}

#undef MM_CHECK_BLOCK
#undef MM_OK_BLOCK
#undef MM_NOTOK_BLOCK
