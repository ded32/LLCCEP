#ifndef LINKER_HPP
#define LINKER_HPP

#include <vector>
#include <utility>
#include <string>

#include <stddef.h>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	::std::pair<::std::string, size_t> make_labels_associative_table(
			::std::vector<lexem> &lex,
			size_t iteration);
	void substitute_labels_with_addresses(
			::std::vector<::std::pair<::std::string, size_t> > 
				associative_table,
			::std::vector<lexem> &lex);
}

#endif // LINKER_HPP
