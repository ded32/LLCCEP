#include "instruction/instruction.hpp"
#include "label/label.hpp"

#include <STDExtras.hpp>

void LLCCEP_ASM::statement::build(::std::ostream &out, builderInfo *info)
{
	switch (type) {
	case STATEMENT_T_INSTRUCTION: {
		instructionCompiler ia;
		ia.compileInstruction(out, data.inst, info);
		break;
        }

	case LLCCEP_ASM::STATEMENT_T_LABEL: {
		info->declareLabel(data.lbl);
		break;
	}
				
	case LLCCEP_ASM::STATEMENT_T_INVALID: {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt to compiler statement of invalid type"));
	}
	}
}

LLCCEP_ASM::statement::statemnt():
	type(STATEMENT_T_INVALID),
	data({})
{ }

LLCCEP_ASM::statement::~statement()
{ }

void LLCCEP_ASM::statement::setData(LLCCEP_ASM::instruction *inst)
{
	if (!inst) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting invalid instruction pointer as "
			"statement's one"));
	}

	type = STATEMENT_T_INSTRUCTION;
	data.inst = inst;
}

void LLCCEP_ASM::statement::setData(LLCCEP_ASM::label *lbl)
{
	if (!lbl) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting invalid label data pointer as "
			"statement's one"));
	}

	type = STATEMENT_T_LABEL;
	data.lbl = lbl;
}

LLCCEP_ASM::statement_t LLCCEP_ASM::statement::getType() const
{
	return type;
}

LLCCEP_ASM::statementData LLCCEP_ASM::statement::getData() const
{
	return data;
}
