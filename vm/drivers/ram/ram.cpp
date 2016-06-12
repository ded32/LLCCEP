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

	void allocate_mem(size_t size_b) 
	{
		__sys__::mem = ::std::calloc(size_b, 1);
		if (!__sys__::mem) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\nCan't alloc mem: %s!\n",
				::std::strerror(errno);
			));
		}
	}

	template<class T>
	T access_mem_data(size_t id)
	{
		if (id + sizeof(T) >= __sys__::sizeb) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbound due mem access!\n"));
		}

		return (static_cast<T *>(__sys__::mem))[id];
	}

	template<class T>
	void access_mem_data(size_t id, T val)
	{
		if (id + sizeof(T) >= __sys__::sizeb) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Overbound due mem access!\n"));
		}

		(static_cast<T *>(__sys__::mem))[id] = val;
	}

	void free_mem()
	{
		if (__sys__::mem)	
			free((void *)__sys__::mem);
	}
}

#endif // RAM_HPP
