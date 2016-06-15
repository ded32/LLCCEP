#include <STDExtras.hpp>

#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <cstddef>

#include "ram.hpp"

namespace LLCCEP_vm {
	namespace __sys__ {
		void *mem = 0;
		size_t sizeb = 0;
	}

	void allocate_mem(size_t size_b) 
	{
		__sys__::mem = ::std::calloc(size_b, 1);
		if (!__sys__::mem) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nCan't alloc mem: %s!\n",
				::std::strerror(errno)
			));
		}
	}

	uint8_t *get_mem(size_t offset)
	{
		if (offset >= __sys__::sizeb) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nOverbound due access!\n"
			));
		}

		return (reinterpret_cast<uint8_t *>(__sys__::mem) + offset);
	}

	size_t get_mem_size()
	{
		return __sys__::sizeb;
	}

	void free_mem()
	{
		if (__sys__::mem)	
			free((void *)__sys__::mem);
	}
}
