#include <string>

LLCCEP_ASM::instruction::instruction():
	instructionName(),
	args(NULL)
{ }

LLCCEP_ASM::instruction::~instruction()
{ }

void LLCCEP_ASM::instruction::setName(::std::string name)
{
	if (!instructionName.length()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting instructon name to "
			"empty string"));
	}

	instructionName = name;
}
void LLCCEP_ASM::instruction::setArguments(LLCCEP_ASM::instructionArguments *newArgs)
{
	if (!newArgs) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting instruction arguments pointer to "
			"invalid pointer"));
	}

	args = newArgs;
}

::std::string LLCCEP_ASM::instruction::getName() const
{
	return instructionName;
}

LLCCEP_ASM::instructionArguments *LLCCEP_ASM::instruction::getArguments() const
{
	return args;
}
