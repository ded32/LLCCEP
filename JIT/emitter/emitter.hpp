#ifndef EMITTER_HPP
#define EMITTER_HPP

#include <cstdint>

#include "../instruction/instruction.hpp"

#define EAX (static_cast<uint8_t>(0))
#define EBX (static_cast<uint8_t>(3))
#define ECX (static_cast<uint8_t>(1))
#define EDX (static_cast<uint8_t>(2))

#define ESP (static_cast<uint8_t>(4))

namespace LLCCEP_JIT {
	typedef uint8_t regID;

	class program {
		std::vector<instruction> program_data;
	public:
		program();
		program(std::vector<instruction> program_data);
		program(const program &data);

		void emit_mov(regID dst, regID src);
		void emit_mov(regID dst, uint32_t val);

		void emit_push(regID dst);
		void emit_push(uint32_t val);

		void emit_finit();
		void emit_fclex();
	}
}

#endif // EMITTER_HPP
