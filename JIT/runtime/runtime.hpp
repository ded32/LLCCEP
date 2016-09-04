#ifndef RUNTIME_HPP
#define RUNTIME_HPP

#include "./../../exec/softcore/softcore.hpp"
#include "./../../exec/codeReader/codeReader.hpp"

namespace LLCCEP_JIT {
	class runtimeManager: public LLCCEP_exec::softcore {
	public:
		runtimeManager();

		void *getSoftcorePtr();
		void *getSwiEmulatePtr();
		void *getCmpPtr();
		void *getRegPtr(size_t id);
		void *getMemoryBeginning();
		LLCCEP_exec::codeReader *getCodeReader();
	};
}

#endif // RUNTIME_HPP
