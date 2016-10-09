#include <string>
#include <vector>
#include <tools/check/name.hpp>

#include "declaration.hpp"

LLCCEP_ASM::declaration::declaration():
	name(),
	size(0)
{ }

LLCCEP_ASM::declaration::~declaration()
{ }

void LLCCEP_ASM::declaration::setName(::std::string newName)
{
	if (!okName(name)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting invalid name "
			"to a declaration"));
	}

	name = newName;
}

void LLCCEP_ASM::declaration::setSize(size_t newSize)
{
	size = newSize;
}

::std::string LLCCEP_ASM::declaration::getName() const
{
	return name;
}

size_t LLCCEP_ASM::declaration::getSize() const
{
	return size;
}

LLCCEP_ASM::declarations::declarations():
	decls()
{ }

LLCCEP_ASM::declarations::~declarations()
{ }

LLCCEP_ASM::declarations::addDeclaration(declaration *decl)
{
	if (!decl) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of adding declaration to declarations list "
			"by invalid pointer"));
	}

	decls.push_back(decl)
}

::std::vector<LLCCEP_ASM::declaration *> LLCCEP_ASM::declarations::getDeclarations() const
{
	return decls;
}
