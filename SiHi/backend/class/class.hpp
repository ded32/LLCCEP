#ifndef SIHI_CLASS_HPP
#define SIHI_CLASS_HPP

#include <vector>

#include "./../function/function.hpp"
#include "./../variable/variable.hpp"
#include "./../type/type.hpp"

namespace LLCCEP_SiHi {
	class classDefinition {
	public:	
		typedef functionDefinition methodDefinition;
		typedef variableDefinition propertyDefinition;

		enum memberType {
			MEMBER_TYPE_PROPERTY,
			MEMBER_TYPE_METHOD,
			MEMBER_TYPE_INTERNAL_TYPE
		};

		enum memberAccessRule {
			MEMBER_ACCESS_RULE_PUBLIC,
			MEMBER_ACCESS_RULE_PROTECTED,
			MEMBER_ACCESS_RULE_PRIVATE
		};

		struct memberDeclaration {
			memberType member_t;
			memberAccessRule access_rule;

			union {
				methodDefinition method;
				propertyDefinition prop;
				typeDeclaration type;
			} member_value;
		};
		
		classDefinition();
		~classDefinition();
		
		void addMember(memberDeclaration member);
		void addProperty(propertyDefinition property);
		void addMethod(methodDefinition method);
		void addType(typeDeclaration type);

		::std::vector<propertyDefinition> getPropertyList() const;
		::std::vector<methodDefinition> getMethodList() const;
		::std::vector<typeDeclaration> getInternalTypeList() const;

		::std::vector<propertyDefinition>::const_iterator propertyPos(::std::string name);
		::std::vector<methodDefinition>::const_iterator methodPos(::std::string name);
		::std::vector<typeDeclaration>::const_iterator typePos(::std::string name);
	private:
		::std::vector<propertyDefinition> properties;
		::std::vector<methodDefinition> methods;
		::std::vector<typeDeclaration> types;
	};
}

#endif /* SIHI_CLASS_HPP */
