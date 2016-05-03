#ifndef EMITTER_HPP
#define EMITTER_HPP

#include <vector>
#include <initializer_list>
#include <cstdint>
#include <cstddef>
#include "../startup/program.hpp"

#include <STLExtras.hpp>

namespace LLCCEP_JIT {
	typedef std::initializer_list<uint8_t> opcode;
	typedef uint8_t regID;

	const regID EAX = 0,
	            ECX = 1,
	            EDX = 2,
	            EBX = 3,
	            ESP = 4;

	class emitter {
		std::vector<uint8_t> program;
	public:
		emitter();
		emitter(std::initializer_list<uint8_t> src);
		emitter(emitter &src);
		~emitter();

		void emit_byte(uint8_t byte);

		template<typename TYPE>
		void emit_data(TYPE val)
		{
			for (size_t i = 0; i < sizeof(TYPE); i++)
				emit_byte((reinterpret_cast<uint8_t *>(&val))[i]);
		}

		void emit(std::initializer_list<uint8_t> data);
		void emit(opcode op, regID dst, regID src);

		void dump();

		friend program_exec_data make_program(emitter emit);
	};
}

#endif // EMITTER_HPP
