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

#define CHECK_TREE(ast, type, argn) \
{ \
	ASSERT_AST(ast) \
	ASSERT_TYPE(ast, type) \
	\
	if (argn != -1) \
	        ASSERT_ARGN(ast, argn) \
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

void LLCCEP_SiHi::backend::generatePrimaryExpression(::std::ostream &out, LLCCEP_SiHi::ast *primaryExpression) const
{
	ASSERT_AST(primaryExpression)

	switch (primaryExpression->value().type) {
	case ID:
		generateGetPtr(out, primaryExpression);
		break;

	case NUMBER:
		generateGetNumber(out, primaryExpression);
		break;
	
	case LITERAL:
		generateGetLiteral(out, primaryExpression);
		break;

	default:
		generateExpression(out, primaryExpression);
	}
}

void LLCCEP_SiHi::backend::generatePostfixExpression(::std::ostream &out, LLCCEP_SiHi::ast *postfixExpression) const
{
	ASSERT_AST(postfixExpression)

	switch (postfixExpression->value().type) {
	case LLCCEP_SiHi::POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS:
		ASSERT_ARGN(postfixExpression, 2)

		generatePostfixExpression(out, postfixExpression->getChildren()[0]);
		getTypeSize(getTypeOf(postfixExpression->getChildren()[0]));
		getOffset(postfixExpression->getChildren()[1]);

		out << "__operator_index_"
		    << getTypeOf(postfixExpression->getChildren()[0])
		    << "__ ";

		break;

	case LLCCEP_SiHi::POSTFIX_EXPRESSION_FUNCTION_CALL:
		generatePostfixExpression(out, postfixExpression->getChildren()[0]);

		if (postfixExpression->getChildren().size() == 2)
			generateArgumentsSave(out, postfixExpression->getChildren()[1]);

		out << "__operator_call_"
		    << getTypeOf(postfixExpression->getChildren()[0])
		    << "__";

		break;

	case LLCCEP_SiHi::POSTFIX_EXPRESSION_MEMBER_ACCESS:
		ASSERT_ARGN(2)

		generatePostfixExpression(postfixExpression->getChildren()[0]);
		out << "__operator_dot_"
		    << getTypeOf(postfixExpression->getChildren()[0])
		    << "__";

		break;

	case LLCCEP_SiHi::POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR:
		ASSERT_ARGN(2)
		
		generatePostfixExpression(out, postfixExpression->getChildren()[0]);
		out << "__operator_arrow_"
		    << getTypeOf(postfixExpression->getChildren()[0])
		    << "__";
		break;

	case LLCCEP_SiHi::POSTFIX_EXPRESSION_INCREMENT:
		ASSERT_ARGN(1)

		generatePostfixExpression(out, postfixExpression->getChildren()[0]);
		out << "__operator_inc_"
		    << getTypeOf(postfixExpression->getChildren()[0])
		    << "__";

		break;

	case LLCCEP_SiHi::POSTFIX_EXPRESSION_DECREMENT:
		ASSERT_ARGN(1)

		generatePostfixExpression(out, postfixExpression->getChildren()[0]);
		out << "__operator_dec_" 
		    << getTypeOf(postfixExpression->getChildren()[0]) 
		    << "__";

		break;

	default:
		generatePrimaryExpression(out, postfixExpression);
	}
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
