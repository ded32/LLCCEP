#include <vector>
#include <string>

#include "argument.hpp"

LLCCEP_ASM::instructionArgument::instructionArgument():
	type(LLCCEP_ASM::ARG_T_INVALID),
	data({})
{ }

LLCCEP_ASM::instructionArgument::~instructionArgument()
{ 
	if (type == LLCCEP_ASM::ARG_T_LITERAL ||
	    type == LLCCEP_ASM::ARG_T_ID)
		delete data.str;
}

void LLCCEP_ASM::instructionArgument::setData(long long val)
{
	type = LLCCEP_ASM::NUMBER;
	data.val = static_cast<double>(val);
}

void LLCCEP_ASM::instructionArgument::setData(double val)
{
	type = LLCCEP_ASM::NUMBER;
	data.val = val;
}

void LLCCEP_ASM::instructionArgument::setData(::std::string str)
{
	if (!str.length()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting invalid string as argument data"));
	}

	type = (str[0] == '"')?LLCCEP_ASM::LITERAL:LLCCEP_ASM::ID;
	val = new char[str.length()];
	strcpy(val, str.c_str());
}

LLCCEP_ASM::arg_t LLCCEP_ASM::instructionArgument::getType() const
{
	return type;
}

LLCCEP_ASM::instructionArgumentData LLCCEP_ASM::instructionArgument::getData() const
{
	return data;
}

LLCCEP_ASM::instructionArguments::instructionArguments():
	arguments()
{ }

LLCCEP_ASM::instructionArguments::~instructionArguments()
{ }

void LLCCEP_ASM::instructionArguments::addArgument(LLCCEP_ASM::instructionArgument *argument)
{
	if (!argument) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting invalid argument pointer as one"
			" of arguments"));
	}

	arguments.push_back(arguments);
}

::std::vector<LLCCEP_ASM::instructionArgument *> LLCCEP_ASM::instructionArguments::getArguments() const
{
	return arguments;
}
