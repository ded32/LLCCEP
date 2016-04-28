#ifndef INSTRUCTION_MANAGER_HPP
#define INSTRUCTION_MANAGER_HPP

#include <vector>
#include <cstdint>
#include <initializer_list>

namespace LLCCEP_JIT {
	class instruction {
		std::vector<uint8_t> opcode;
		struct rmfield {
			uint8_t val;
			bool exists;
		} rmval;
	public:
		instruction();
		instruction(std::initializer_list<uint8_t> opcode_data);
		instruction(instruction &src);
		~instruction();

		void set_rm(uint8_t newrm);
		void append_opcode(uint8_t op);
		void append_rm();

		void dump() const;
	};
}

#endif // INSTRUCTION_MANAGER_HPP
