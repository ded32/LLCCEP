#ifndef EMITTER_HPP
#define EMITTER_HPP

#include <vector>
#include <cstdint>

#include "../instruction/instruction.hpp"

#define EAX 0
#define EBX 3
#define ECX 1
#define EDX 2
#define ESP 4

namespace LLCCEP_JIT {
	typedef uint8_t regid;

	enum {

	};

	class program {
		std::vector<instruction> program_data;
	public:
		program();
		program(std::initializer_list<instruction> &program_);
		program(program &src);
		~program();

		void emit_mov(regid dest, regid src);
		void emit_mov(regid dest, uint32_t src);

		void emit_finit();
		void emit_fclex();

		void emit_push(regid src);
		void emit_push(uint32_t src);
	};
}

#endif // EMITTER_HPP
