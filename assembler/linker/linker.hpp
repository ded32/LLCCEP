#ifndef ASSEMBLER_LINKER_HPP
#define ASSEMBLER_LINKER_HPP

#include <vector>
#include <utility>
#include <string>

#include <stddef.h>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	bool is_label(::std::vector<lexem> lex);
	void make_labels_associative_table(
			::std::vector<::std::pair<lexem, size_t> > &associative_table,
			::std::vector<lexem> lex,
			size_t iteration);
	void substitute_labels_with_addresses(
			::std::vector<::std::pair<lexem, size_t> > 
				associative_table,
			::std::vector<lexem> &lex);
}

#endif // ASSEMBLER_LINKER_HPP
