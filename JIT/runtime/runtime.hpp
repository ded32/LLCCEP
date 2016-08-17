#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include "../../exec/softcore/softcore.hpp"
#include "../../exec/program/program.hpp"

namespace LLCCEP_JIT {
	class runtimeManager: public LLCCEP_exec::softcore {
	public:
		runtimeManager();

		void *getSwiEmulatePtr();
		void *getCmpPtr();
		void *getRegPtr(size_t id);
		void *getMemoryBeginning();
	};
}

#endif // RUNTIME_HPP
