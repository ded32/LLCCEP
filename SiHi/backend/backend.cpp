#include <iostream>
#include "./../ast/ast.hpp"

#include "backend.hpp"

LLCCEP_SiHi::backend::backend():
	syntaxTree(0)
{ }

LLCCEP_SiHi::backend::~backend()
{ }

void LLCCEP_SiHi::backend::generateCode(::std::ostream &out) const
{
	generateCode(out, syntaxTree);
}

void LLCCEP_SiHi::backend::rememberFunction(LLCCEP_SiHi::ast *ast)
{
	ASSERT_ARGN(2)
	ASSERT_TYPE(LLCCEP_SiHi::FUNCTION_DEFINITION)

	functionProto newFunctionProto{getFunctionName(ast),
	                               getFunctionArguments(ast)};
	functionProtos.push_back(newFunctionProto);
}

void LLCCEP_SiHi::backend::synthezeFunctionBody(::std::ostream &out, LLCCEP_SiHi::ast *ast)
{
	ASSERT_ARGN(2)
	ASSERT_TYPE(LLCCEP_SiHi::FUNCTION_BODY)

	auto &args = getFunctionArguments(ast);
	for (const auto &i: args)
		synthezeArgument(i);

	synthezeStatement(ast->getChildren()[1]);

	for (const auto &i: args)
		releaseArgument(i);
}

void LLCCEP_SiHi::backend::generateCode(::std::ostream &out, LLCCEP_SiHi::ast *ast) const
{
	if (!ast) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt to generate code for null tree!"))
	}

	switch (ast->getValue().type) {
	case LLCCEP_SiHi::EXTERNAL_DECLARATION:
		for (auto &i: ast->getChildren())
			generateCode(out, i);
		break;
	
	case LLCCEP_SiHi::FUNCTION_DEFINITION:
		ASSERT_ARGN(2)

		rememberFunction(ast);
		synthezeFunctionBody(out, ast);
		break;

	case LLCCEP_SiHi::DECLARATION:
		ASSERT_ARGN(2)

		declareVariables(out, ast);
		break;

	case LLCCEP_SiHi::CLASS_DECLARATION:
		ASSERT_ARGN(3)

		matchClassFields(ast);
		synthezeClassMethods(out, ast);
		break;

	default:
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Forbidden action at the top level"))
	}
}
