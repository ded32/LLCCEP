#ifndef INSTRUCTION_HPP
#define INSTRUCTION_HPP

#include <vector> 
#include <cstdint>

namespace LLCCEP_JIT {
	class instruction {
		std::vector<uint8_t> opcode;
		struct rmfield {
			bool exist;
			uint8_t val;
		} rmdata;
	public:
		instruction();
		instruction(std::vector<uint8_t> opcodes);
		instruction(std::vector<uint8_t> opcodes, uint8_t rmval);
		~instruction();

		void append_opcode(uint8_t val);
		void set_rm_field(uint8_t val);

		void append_rmfield();
		void dump_data();

		friend void exec(std::vector<instruction> program);
	};

	void exec(std::vector<instruction> program);
}

#endif // INSTRUCTION_HPP
