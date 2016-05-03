#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <cstddef>

namespace LLCCEP_JIT {
	struct program {
		void *mem;
		size_t sz;
	};
}

#endif // PROGRAM_HPP
