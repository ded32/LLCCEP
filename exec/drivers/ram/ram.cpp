#include <STDExtras.hpp>

#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cstddef>

#include "ram.hpp"

namespace LLCCEP_vm {
	namespace __sys__ {
		void *mem = 0;
		size_t size = 0;
	}

	void allocate_mem(size_t size) 
	{
		__sys__::mem = ::std::calloc(size, sizeof(double));
		if (!__sys__::mem) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nCan't alloc mem: %s!\n",
				::std::strerror(errno)
			));
		}

		__sys__::size = size;
	}

	uint8_t *get_mem(size_t offset)
	{
		if (offset >= __sys__::size) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nOverbound due access!\n"
			));
		}

		return (reinterpret_cast<uint8_t *>(__sys__::mem) + offset * sizeof(double));
	}

	size_t get_mem_size()
	{
		return __sys__::size;
	}

	void free_mem()
	{
		if (__sys__::mem)	
			free((void *)__sys__::mem);

		__sys__::size = 0;
	}
}
