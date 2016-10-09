#include <string>
#include <STDExtras.hpp>

#include <tools/check/name.hpp>

#include "label.hpp"

LLCCEP_ASM::label::label():
	name(),
	pos()
{ }

LLCCEP_ASM::label::~label()
{ }

void LLCCEP_ASM::label::setName(::std::string newName)
{
	if (badName(newName)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Bad name to be set to label"));
	}

	name = newName;
}

void LLCCEP_ASM::label::setPos(size_t newPos)
{
	pos = newPos;
}

::std::string LLCCEP_ASM::label::getName() const
{
	return name;
}

size_t LLCCEP_ASM::label::getPos() const
{
	return pos;
}
