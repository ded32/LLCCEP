#ifndef BACKEND_HPP
#define BACKEND_HPP

#include <iostream>
#include "./../ast/ast.hpp"

namespace LLCCEP_SiHi {
	class backend {
		struct variableDeclaration {
			ast *type;
			::std::string name;
		};

		typedef variableDeclaration functionArgument;
		struct functionDeclaration {
			::std::string name;
			::std::vector<functionArgument> args;
			ast *returnType;
		};

		struct typeAlias {
			ast *sourceType;
			::std::string name;
		};

		struct internalType {
			enum {
				INTERNAL_TYPE_CLASS,
				INTERNAL_TYPE_ALIAS
			} type;

			union {
				classDeclaration classDecl;
				typeAlias alias;
			} typeData;
		};

		struct classDeclaration {
			::std::string name;
			::std::vector<functionDeclaration> methods;
			::std::vector<variableDeclaration> properties;
			::std::vector<classType> internalTypes;
		};

	public:
		backend();
		~backend();

		void generateCode(::std::ostream &out) const;

	private:
		void generateCode(::std::ostream &out, ast *root) const;

		::std::vector<classDeclaration> classes;
		::std::vector<functionDeclaration> functions;
		::std::vector<variableDeclaration> variables;

		classDeclaration *currentClassProcessing;
		functionDeclaration *currentFunctionProcessing;

		ast *syntaxTree;
	};

#endif // BACKEND_HPP
