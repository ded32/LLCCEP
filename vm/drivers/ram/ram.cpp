#ifndef RAM_HPP
#define RAM_HPP

#include <STDExtras.hpp>

#include <cstring>
#include <cstdlib>
#include <cerrno>

namespace LLCCEP_vm {
	namespace __sys__ {
		void *mem = 0;
		size_t sizeb = 0;
	}

	inline void allocate_mem(size_t size_b) 
	{
		__sys__::mem = ::std::calloc(size_b, 1);
		if (!__sys__::mem) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nCan't alloc mem: %s!\n",
				::std::strerror(errno);
			));
		}
	}

	inline uint8_t *get_mem(size_t offset)
	{
		if (offset >= __sys__::sizeb) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nOverbound due access!\n"
			));
		}

		return __sys__::mem + offset;
	}

	inline void free_mem()
	{
		if (__sys__::mem)	
			free((void *)__sys__::mem);
	}
}

#endif // RAM_HPP
