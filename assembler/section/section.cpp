#include <vector>
#include <string>

#include <STDExtras.hpp>
#include <tools/check/name.hpp>

#include "section.hpp"

void LLCCEP_ASM::section::build(::std::ostream &out, builderInfo *info)
{
	if (!info) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid builderInfo pointer"));
	}

	auto compileStatements = [&, out, info, =this] {
		for (const auto &i: data.stats->getStatements()) {
			if (!i) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Met invalid statement pointer"));
			}

			i->build(out, builderInfo);
		}
	};

	auto compileDeclarations = [&info, this] {
		for (const auto &i: data.decls->getDeclarations()) {
			if (!i) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Met invalid statement pointer"));
			}

			info->addDeclaration(*i);
		}
	};

	switch (type) {
	case LLCCEP_ASM::SECTION_T_IMPERATIVE:
		compileStatements();
		break;

	case LLCCEP_ASM::SECTION_T_DECLARATIVE:
		compileDeclarations();
		break;

	default:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Met section of invalid type, can't build it"));
	}
}

LLCCEP_ASM::section::section():
	type(SECTION_T_INVALID),
	data({}),
	name()
{ }

LLCCEP_ASM::section::~section()
{ }

void LLCCEP_ASM::section::setName(::std::string newName)
{
	if (!okName(newName)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Attempt of setting section name to "
			"non-id string"));
	}

	name = newName;
}

void LLCCEP_ASM::section::setData(sectionDeclarations *decls)
{
	type = LLCCEP_ASM::SECTION_T_DECLARATIVE;
	data.decls = decls;
}

void LLCCEP_ASM::section::setData(sectionStatements *stats)
{
	type = LLCCEP_ASM::SECTION_T_IMPERATIVE;
	data.stats = stats;
}

::std::string LLCCEP_ASM::section::getName() const
{
	return name;
}

LLCCEP_ASM::section_t LLCCEP_ASM::section::getType() const
{
	return type;
}

LLCCEP_ASM::sectionData LLCCEP_ASM::section::getData() const
{
	return data;
}

LLCCEP_ASM::sectionList::sectionList():
	sections()
{ }

LLCCEP_ASM::sectionList::~sectionList()
{ }

void LLCCEP_ASM::sectionList::addSection(LLCCEP_ASM::section *sect)
{
	if (!sect || sect->getType() == LLCCEP_ASM::SECTION_T_INVALID) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid section to be added"));
	}

	sections.push_back(sect);
}

void LLCCEP_ASM::sectionList::buildDeclarative(::std::ostream &out) const
{
	for (const auto &i: sections)
		if (i->getType() == LLCCEP_ASM::SECTION_T_DECLARATIVE)
			i->build(out, builderInfo);
}

void LLCCEP_ASM::sectionList::buildImperative(::std::ostream &out) const
{
	for (const auto &i: sections)
		if (i->getType() == LLCCEP_ASM::SECTION_T_IMPERATIVE)
			i->build(out, builderInfo);
}
