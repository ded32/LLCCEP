#include <iostream>
#include "./../ast/ast.hpp"

#include "backend.hpp"

#define ASSERT_AST(ast) \
{ \
	if (!ast) { \
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
			"Invalid ast pointer!")) \
	} \
}

#define ASSERT_TYPE(ast, type) \
{ \
	ASSERT_AST(ast) \
	if (ast->getValue().type != type) { \
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
			"Unexpected lexem of %d type!", \
			ast->getValue().type)) \
	} \
}

#define ASSERT_ARGN(ast, argn) \
{ \
	ASSERT_AST(ast) \
        if (ast->getChildren().size() != argn) { \
	        throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
			"Invalid arguments amount!")) \
	} \
}

LLCCEP_SiHi::backend::backend():
	syntaxTree(0)
{ }

LLCCEP_SiHi::backend::~backend()
{ }

void LLCCEP_SiHi::backend::generateCode(::std::ostream &out) const
{
	generateCode(out, syntaxTree);
}

void LLCCEP_SiHi::backend::buildFunction(::std::ostream &out, LLCCEP_SiHi::ast *functionTree) const
{
	ASSERT_AST(functionTree)
	ASSERT_TYPE(functionTree, LLCCEP_SiHi::FUNCTION_DEFINITION)
	ASSERT_ARGN(functionTree, 2)

	checkNoSuchFunction(functionTree);
	addFunctionDefinition(out, functionTree);

	ASSERT_AST(functionTree)
}

void LLCCEP_SiHi::backend::generateCode(::std::ostream &out, LLCCEP_SiHi::ast *declarationTree) const
{
	ASSERT_AST(root)
	ASSERT_TYPE(root, LLCCEP_SiHi::EXTERNAL_DECLARATION)

	for (const auto &i: root->getChildren()) {
		ASSERT_AST(i)

		switch (i->value().type) {
		case LLCCEP_SiHi::FUNCTION_DEFINITION:
			buildFunction(out, i);
			break;
		
		case LLCCEP_SiHi::DECLARATION:
			rememberDeclaration(out, i);
			break;
		
		case LLCCEP_SiHi::CLASS_DECLARATION:
			buildClass(out, i);
			break;
		
		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Invalid declaration at the top level."))
		}

		ASSERT_AST(i)
	}

	ASSERT_AST(root)
}
