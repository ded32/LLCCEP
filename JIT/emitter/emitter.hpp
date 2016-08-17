#ifndef EMITTER_HPP
#define EMITTER_HPP

#include <vector>
#include <initializer_list>
#include <cstdint>
#include <cstddef>
#include "../startup/program.hpp"

#include <STLExtras.hpp>

#ifdef emit
#undef emit
#endif

namespace LLCCEP_JIT {
	typedef std::initializer_list<uint8_t> opcode;

	enum regID: uint8_t {
		RAX = 0,
		RCX = 1,
		RDX = 2,
		RBX = 3,
		RSP = 4,
		RBP = 5,
		RSI = 6,
		RDI = 7
	};

	enum rex: uint8_t {
		REX_W = 0x48,
		REX_R = 0x44,
		REX_X = 0x42,
		REX_B = 0x41
	};

	class emitter {
		std::vector<uint8_t> program;
	public:
		emitter();
		emitter(std::initializer_list<uint8_t> src);
		emitter(const emitter &src);
		virtual ~emitter();

		void emit_byte(uint8_t byte);

		template<typename TYPE>
		void emit_data(TYPE val)
		{
			for (size_t i = 0; i < sizeof(TYPE); i++)
				emit_byte((reinterpret_cast<uint8_t *>(&val))[i]);
		}

		void emit(std::initializer_list<uint8_t> data);
		void emit(opcode op, regID dst, regID src);
		void emit(opcode op, regID src);
		void dump(bool bin = false);

		std::vector<uint8_t>::const_iterator begin() const;
		std::vector<uint8_t>::iterator begin();

		std::vector<uint8_t>::const_iterator end() const;
		std::vector<uint8_t>::iterator end();

		size_t size() const;
	};
}

#endif // EMITTER_HPP
