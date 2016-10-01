#ifndef LLCCEP_SIHI_CONTEXT_HPP
#define LLCCEP_SIHI_CONTEXT_HPP

#include <backend/variableDeclaration/variableDeclaration.hpp>

#include <string>

namespace LLCCEP_SiHi {
	class context {
		::std::vector<::std::string> contextVariables;
	
	public:
		context();
		~context();

		void addVariable(::std::string name);
		void deleteVariable(::std::string name);

		bool variableDeclared(::std::string name) const;

		::std::string toString() const;
	};
}

#endif /* LLCCEP_SIHI_CONTEXT_HPP */
