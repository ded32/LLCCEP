#include "linker.hpp"

#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include <stddef.h>

#include <STDExtras.hpp>

int main() 
{
	::std::vector<::std::pair<LLCCEP_ASM::lexem, size_t> > labels_table;
	::std::vector<LLCCEP_ASM::lexem> lex;
	::std::string code;
	size_t iteration = 0;

	auto dump = [&lex]() {
		::std::cout << "\n";

		for (const auto &i: lex)
			::std::cout << get_lexem_typename(i) << ": " << i.val << "\n";

		::std::cout << "\n";
	};

	try {
		do {
			size_t old = labels_table.size();

			lex.clear();
			code.clear();

			::std::getline(::std::cin, code);
			LLCCEP_ASM::to_lexems(code, lex, "stdin", 0);
			LLCCEP_ASM::make_labels_associative_table(labels_table, lex, iteration);
			
			::std::vector<LLCCEP_ASM::lexem> lex_(lex);
			lex.clear();
			LLCCEP_ASM::substitute_labels_with_addresses(labels_table, lex_);
			lex.insert(lex.begin(), lex_.begin(), lex_.end());

			dump();

			if (labels_table.size() == old)
				iteration++;
		} while ((lex.size())?(lex[0].val != "quit"):(1));
	} DEFAULT_HANDLING

	return 0;
}
