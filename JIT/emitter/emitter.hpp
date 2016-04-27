#ifndef EMITTER_HPP
#define EMITTER_HPP

#include <vector>
#include <initializer_list>
#include <cstdint>
#include <cstddef>

#include <STLExtras.hpp>

namespace LLCCEP_JIT {
	typedef std::initializer_list<uint8_t> opcode;
	typedef uint8_t regID;

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

		template<typename TYPE>
		void emit(opcode op, regID dst, TYPE val)
		{
			std::vector<uint8_t> opcode_data(init2vec(op));

			for (size_t i = 0; i < opcode_data.size(); i++) {
				if (i == opcode_data.size() - 1)
					emit_byte(opcode_data[i] + dst);
				else
					emit_byte(opcode_data[i]);				
			}

			emit_data(val);
		}

		void dump();
	};
}

#endif // EMITTER_HPP
