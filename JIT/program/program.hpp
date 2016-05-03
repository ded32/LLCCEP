#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <initializer_list>

#include "../emitter/emitter.hpp"

namespace LLCCEP_JIT {
	class program: private emitter {
	public:
		program();
		program(std::initilizer_list<uint8_t> data);
		program(const emitter &src);
		program(const program &src);
		~program();

		void emit_ret();
		
		void emit_mov(regID dst, regID src);
		void emit_mov(regID dst, uint32_t src);
	};
}

#endif // PROGRAM_HPP
