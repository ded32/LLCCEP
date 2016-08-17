#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include "../../exec/softcore/softcore.hpp"
#include "../../exec/program/program.hpp"

namespace LLCCEP_JIT {
	class runtimeManager: public LLCCEP_exec::softcore {
	public:
		runtimeManager();

		void *getSwiEmulatePtr();
		int *getCmpPtr();
		double *getRegPtr();
	};
}

#endif // RUNTIME_HPP
