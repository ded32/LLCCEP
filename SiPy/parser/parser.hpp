#ifndef SIPY_PARSER_HPP
#define SIPY_PARSER_HPP

#include <memory>
#include "../ast/ast.hpp"
#include "../lexer/lexer.hpp"

namespace LLCCEP_SiPy {
	std::unique_ptr<astNode> ParseExpr(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParsePrime(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParseNumber(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParseParen(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParseID(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParsePrime(std::vector<lexem> &lex);
	std::unique_ptr<astNode> ParseBinOp(std::vector<lexem> &lex, int prec, std::unique_ptr<astNode> Left);
	std::unique_ptr<astProto> ParseProto(std::vector<lexem> &lex);
	std::unique_ptr<astFunc> ParseFunc(std::vector<lexem> &lex);
	std::unique_ptr<astProto> ParseExternal(std::vector<lexem> &lex);
}

#endif // SIPY_PARSER_HPP
