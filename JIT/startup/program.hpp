#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstddef>

namespace LLCCEP_JIT {
	typedef struct {
		void *mem;
		size_t sz;
	} program_exec_data;
}

#endif // PROGRAM_HPP
