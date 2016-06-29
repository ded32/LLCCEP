#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include "../runtime/runtime_data.hpp"
#include "../program/program.hpp"

namespace LLCCEP_JIT {
	class codegenBackend: public program {
	public:
		void generate(program data);
	};
}

#endif // CODEGEN_HPP
