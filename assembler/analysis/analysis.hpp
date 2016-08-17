#ifndef ASSEMBLER_ANALYSIS_HPP
#define ASSEMBLER_ANALYSIS_HPP

#include <vector>
#include <string>
#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	int64_t is_cond(::std::string str);
	int64_t is_inst(::std::string str);

	void analyze(::std::vector<lexem> &lex);
}

#endif // ASSEMBLER_ANALYSIS_HPP
