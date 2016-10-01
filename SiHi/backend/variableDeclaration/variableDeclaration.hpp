#ifndef LLCCEP_SIHI_VARIABLEDECLARATION_HPP
#define LLCCEP_SIHI_VARIABLEDECLARATION_HPP

#include <ast/ast.hpp>

#include <string>

namespace LLCCEP_SiHi {
	class context;

	struct variable {
		context *cxt;
		ast *defaultInitValue;

		declarationType type;
		::std:string name;
	};

	class variableDeclaration {
		variable declarationInfo;
		bool wasDeclared;

	public:
		variableDeclaration();
		~variableDeclaration();

		void data(variable data);
		variable data() const;

		void declare() const;
		void release() const;
	};
}

#endif /* LLCCEP_SIHI_VARIABLEDECLARATION_HPP */
