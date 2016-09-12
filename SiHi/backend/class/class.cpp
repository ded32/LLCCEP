#include <vector>

#include "./../function/function.hpp"
#include "./../variable/variable.hpp"
#include "./../type/type.hpp"

#include "class.hpp"

LLCCEP_SiHi::classDefinition::classDefinition():
	properties(),
	methods(),
	types()
{ }

LLCCEP_SiHi::classDefinition::~classDefinition()
{ }

void LLCCEP_SiHi::classDefinition::addMember(LLLCCEP_SiHi::classDefinition::memberDeclaration member)
{
	switch (member.member_t) {
	case LLCCEP_SiHi::classDefinition::memberType::MEMBER_TYPE_PROPERTY:
		addProperty(member.member_value.prop);
		break;

	case LLCCEP_SiHi::classDefinition::memberType::MEMBER_TYPE_METHOD:
		addMethod(member.member_value.method);
		break;

	case LLCCEP_SiHi::classDefinition::memberType::MEMBER_TYPE_INTERNAL_TYPE:
		addInternalType(member.member_value.type);
		break;

	default:
		break;
	}
}

void LLCCEP_SiHi::classDefinition::addProperty(LLCCEP_SiHi::classDefinition::propertyDefinition property)
{
	properties.push_back(property);
}

void LLCCEP_SiHi::classDefinition::addMethod(LLCCEP_SiHi::classDefinition::methodDefinition method)
{
	methods.push_back(method);
}

void LLCCEP_SiHi::classDefinition::addType(LLCCEP_SiHi::typeDeclaration type)
{
	types.push_back(type);
}

::std::vector<LLCCEP_SiHi::classDefinition::propertyDefinition> LLCCEP_SiHi::classDefinition::getPropertyList() const
{
	return properties;
}

::std::vector<LLCCEP_SiHi::classDefinition::methodDefinition> LLCCEP_SiHi::classDefinition::getMethodList() const
{
	return methods;
}

::std::vector<LLCCEP_SiHi::typeDeclaration> LLCCEP_SiHi::classDefinition::getInternalTypeList() const
{
	return types;
}

#define FIND_MEMBER(vec) \
{ \
	for (auto i = vec.)
::std::vector<LLCCEP_SiHi::classDefinition::propertyDefinition>::const_iterator LLCCEP_SiHi::classDefinition::propertyPos(::std::string name) const
{
	for (auto i = properties.begin(); i < properties.end(); i++)
		if (i->name == name)
			return i;

	return properties.end();
}
