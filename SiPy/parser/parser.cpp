#include <memory>
#include <STLExtras.hpp>

#include "../ast/ast.hpp"
#include "../errors/errors.hpp"
#include "parser.hpp"
#include "precedence.hpp"

#define ALERT(str) throw Exception(__FILE__, __PRETTY_FUNCTION__, __LINE__, str);
#define REMOVE_HEAD(vec) vec.erase(vec.begin());
#define ALERT_LESS(vec) if (!vec.size()) ALERT("To less elements!\n");

namespace LLCCEP_SiPy {
	std::unique_ptr<astNode> ParseExpr(std::vector<lexem> &lex)
	{
		auto Left = ParsePrime(lex);
		if (!Left)
			return nullptr;

		return ParseBinOp(lex, 0, std::move(Left));
	}

	std::unique_ptr<astNode> ParsePrime(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex)

		lexem tmp = lex[0];
		REMOVE_HEAD(lex)

		switch (lex[0].type) {
			case OP_T_OB:
				return ParseParen(lex);
				break;

			case LEX_T_NUM:
				return ParseNumber(lex);
				break;

			case LEX_T_ID:
				return ParseID(lex);
				break;

			default:
				ALERT("Unknown lexem type for me!\n")
				break;
		}
	}

	std::unique_ptr<astNode> ParseNumber(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex)

		lexem tmp = lex[0];
		REMOVE_HEAD(lex)

		return LLCCEP::make_unique<astNumberNode>(tmp);
	}

	std::unique_ptr<astNode> ParseParen(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex)

		if (lex[0].type != OP_T_OB)
			ALERT("Can't parse: first isn't '('!\n")

		REMOVE_HEAD(lex)

		auto val = ParseExpr(lex);

		ALERT_LESS(lex)
		if (!(lex[0].type == OP_T_CB))
			ALERT("Can't parse: excepted for ')'!\n");

		REMOVE_HEAD(lex)

		return val;
	}

	std::unique_ptr<astNode> ParseID(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex)

		if (lex[0].type != LEX_T_ID)
			ALERT("Can't parse: excepted for ID!\n");

		std::string val = lex[0].value;
		REMOVE_HEAD(lex)

		ALERT_LESS(lex)
		if (lex[0].type != OP_T_OB)
			return LLCCEP::make_unique<astVariableNode>(val);

		REMOVE_HEAD(lex)

		std::vector<std::unique_ptr<astNode> > args;
		while (lex[0].type != OP_T_CB) {
			if (auto arg = ParseExpr(lex))
				args.push_back(LLCCEP::make_unique<astNode>(arg));
			else
				return nullptr;
		}

		REMOVE_HEAD(lex)

		return LLCCEP::make_unique<astInvokeExprNode>(val, std::move(args));
	}
	
	std::unique_ptr<astNode> ParseBinOp(std::vector <lexem> &lex, int prec, std::unique_ptr<astNode> left)
	{
		ALERT_LESS(lex)

		while (true) {
			int prec = GetOperatorPrecedence(lex[0].value);
			if (prec < 0)
				return left;

			std::string op = lex[0].value;
			REMOVE_HEAD(lex)

			auto right = ParsePrime(lex);
			if (!right)
				return nullptr;

			ALERT_LESS(lex)
			int nxt = GetOperatorPrecedence(lex[0].value);
			if (prec < nxt) {
				right = ParseBinOp(lex, prec, std::move(right));
				if (!right)
					return nullptr;
			}

			left = LLCCEP::make_unique<astNode>(op, std::move(left), std::move(right));
		}
	}

	std::unique_ptr<astProto> ParseProto(std::vector<lexem> &lex)	
	{
		ALERT_LESS(lex)

		if (lex[0].type != LEX_T_ID)
			ALERT("I want id as first in prototype");

		std::string name = lex[0].value;
		REMOVE_HEAD(lex)

		if (lex[0].type != OP_T_OB)
			ALERT("Excepted '(' at the beginning of arguments list")

		REMOVE_HEAD(lex)

		std::vector<std::string> args;
		while (lex[0].type == LEX_T_ID) {
			ALERT_LESS(lex)
			args.push_back(lex[0].value);
			REMOVE_HEAD(lex)
		}

		ALERT_LESS(lex)
		if (lex[0].type != OP_T_CB)
			ALERT("Excepted ')' at the end of arguments list")
		
		REMOVE_HEAD(lex)

		return LLCCEP::make_unique<astProto>(name, args);
	}

	std::unique_ptr<astFunc> ParseFunc(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex)

		if (lex[0].type != DECL_T_DEF)
			ALERT("I want 'def' as specifier of function")

		auto proto = ParseProto(lex);
		if (!proto)
			return nullptr;

		if (auto expr = ParseExpr(lex))
			return LLCCEP::make_unique<astFunc>(std::move(proto), std::move(expr));

		return nullptr;
	}

	std::unique_ptr<astProto> ParseExternal(std::vector<lexem>& lex)
	{
		ALERT_LESS(lex)
		REMOVE_HEAD(lex)
		return ParseProto(lex);
	}
}
