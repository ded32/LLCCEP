#include <vector>
#include <cstdint>
#include <initializer_list>
#include <iostream>
#include <iomanip>

#include "instruction_manager.hpp"

namespace LLCCEP_JIT {
	instruction::instruction():
		opcode(),
		rmval()
	{ }

	instruction::instruction(std::initializer_list<uint8_t> opcode_data):
		opcode(opcode_data),
		rmval()
	{ }

	instruction::instruction(instruction &src):
		opcode(src.opcode),
		rmval(src.rmval)
	{ }

	instruction::~instruction()
	{ }

	void instruction::set_rm(uint8_t newrm)
	{
		rmval.val = newrm;
		rmval.exists = true;
	}

	void instruction::append_opcode(uint8_t op)
	{
		opcode.push_back(op);
	}

	void instruction::append_rm()
	{
		if (rmval.exists) {
			opcode.push_back(rmval.val);
			rmval.exists = false; // turn flag as false to avoid re-append
		}
	}

	void instruction::dump() const
	{
		std::cout << "Dumping instruction data...\n"
		          << "Opcode: ";

		for (auto op_curr: opcode)
			std::cout << std::hex << static_cast<int>(op_curr) << " ";

		std::cout << "\n";

		if (rmval.exists)
			std::cout << "R/M field: " << rmval.val << "\n";
	}
}
