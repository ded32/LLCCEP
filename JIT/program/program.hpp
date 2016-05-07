#ifndef PROGRAM_MANAGER_HPP
#define PROGRAM_MANAGER_HPP

#include <initializer_list>

#include "../emitter/emitter.hpp"

namespace LLCCEP_JIT {
	class program: public emitter {
	public:
		program();
		program(const program &src);

		void emit_ret();
		
		void emit_mov(regID dst, regID src);
		void emit_mov(regID dst, uint32_t src);
	};
}

#endif // PROGRAM_MANAGER_HPP
