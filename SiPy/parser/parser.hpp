#ifndef SIPY_PARSER_HPP
#define SIPY_PARSER_HPP

#include <memory>
#include <vector>
#include "../ast/ast.hpp"
#include "../lexer/lexer.hpp"

namespace LLCCEP_SiPy {
	std::unique_ptr<astNode> GetNumber(std::vector<lexem> &lex);
}

#endif // SIPY_PARSER_HPP
