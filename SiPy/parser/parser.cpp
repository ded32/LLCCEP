#include <memory>
#include <string>
#include <STLExtras.hpp>
#include <iostream>
#include <vector>

#include "../ast/ast.hpp"
#include "../errors/errors.hpp"
#include "parser.hpp"
#include "precedence.hpp"

#define ALERT(str, file, line) throw SyntaxException(error_notify(file, line, str));
#define ALERT_LESS(vec, str) if (!vec.size()) throw Exception(__FILE__, __PRETTY_FUNCTION__, __LINE__, str);
#define REMOVE_HEAD(vec) vec.erase(vec.begin());

namespace LLCCEP_SiPy {
	std::unique_ptr<astNode> GetNumber(std::vector<lexem> &lex)
	{
		ALERT_LESS(lex, "No data")

		if (lex[0].type != LEX_T_NUM)
			ALERT("Given data isn't number!\n", lex[0].position.file, lex[0].position.line)

		double value = stod(lex[0].value);
		REMOVE_HEAD(lex)

		return LLCCEP::make_unique<astNumberNode>(value);
	}
}
