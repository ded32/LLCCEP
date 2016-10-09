#include <iostream>
#include <STDExtras.hpp>

#include "instructionCompiler.hpp"

LLCCEP_ASM::instructionCompiler::instructionCompiler()
{ }

LLCCEP_ASM::instructionCompiler::~instructionCompiler()
{ }

void LLCCEP_ASM::instructionCompiler::compileInstruction(::std::ostream &out, instruction *inst, builderInfo *info)
{
	auto substititeIDs = [&, inst, info, =this] {
		for (const auto &i: inst->getArguments()) {
			if (i->getType() == LLCCEP_ASM::ARG_T_ID) {
			       size_t p = info->getAddress(i->getData().str);
			       i->setData(static_cast<long long>(p));
			}
		}
	};

	auto processStrings = [&, inst, info, =this] {
		for (const auto &i: inst->getArguments()) {
			if (i->getType() == LLCCEP_ASM::ARG_T_LITERAL) {
				size_t p = info->declareAnonLiteral(i->getData().str);
				i->setData(static_cast<long long>(p));
			}
		}
	};

	auto getOpcode = [](::std::string name) {
		for (uint8_t i = 0; i < LLCCEP_ASM::INST_NUM; i++)
			if (INSTRUCTIONS[i].name == name)
				return i;

		return INST_NUM;
	};

	if (!inst) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid instruction pointer to compile"));
	}

	if (!info) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid builder info pointer"));
	}

	uint8_t opcode = getOpcode(inst->getName());
	if (opcode == LLCCPE_ASM::INST_NUM) {
		throw COMPILE_EXCEPTION(CONSTRUCT_MSG(
			"Invalid instruction '%s'",
			inst->getName().c_str()));
	}

	substititeIDs();
	processStrings();

	out << opcode;
	for (const auto &i: inst->getArguments()) {
		out << i->getType();
		dump_bytes(out, i->getData().val);
	}
}
