#include <string>
#include <STDExtras.hpp>
#include "./../../assembler/lexer/lexer.hpp"
#include "def_inst.hpp"

::std::string LLCCEP_ASM::get_mnemonic_by_opcode(uint8_t op)
{
	if (op >= INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Unknown opcode: %d",
					static_cast<int>(op)));
	}

	return INSTRUCTIONS[static_cast<int>(op)].name;
}
