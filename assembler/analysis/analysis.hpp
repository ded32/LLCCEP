#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <vector>
#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	int64_t is_cond(std::string str);
	int64_t is_inst(std::string str);

	bool analyze(::std::vector<lexem> &lex);
}

#endif // ANALYSIS_HPP
