#ifndef CODEGEN_HPP
#define CODEGEN_HPP

#include "../runtime/runtime_data.hpp"
#include "../program/program.hpp"

namespace LLCCEP_JIT {
	class codegen_backend: public program {
	public:
		void get_cmp(regID reg);
		void get_imm(regID reg, arg data);
		void get_ptr(regID reg, arg data);
		void get_mem_addr(regID reg, arg data);
	};
}

#endif // CODEGEN_HPP
