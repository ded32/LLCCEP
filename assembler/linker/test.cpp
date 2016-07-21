#include "linker.hpp"

#include <vector>
#include <utility>
#include <string>
#include <iostream>

#include <stddef.h>

#include <STDExtras.hpp>

int main() 
{
	::std::vector<::std::pair<::std::string, size_t> > labels_table;
	::std::vector<lexem> lex;
	::std::string code;

	auto dump = [lex]() {
		::std::cout << ""
	};

	try {
		do {
			::std::getline(::std::cin, code);
			LLCCEP_ASM::to_lexems(code, lex, "stdin", 0);
			
			auto label = LLCCEP_ASM::make_labels_associative_table(lex, i);
			if (label.first.length()) {
				labels_table.push_back(label);
			} else {
				LLCCEP_ASM::substitute_labels_with_addresses(labels_table, lex);
				dump();
			}
		} while ((lex.size())?(lex[0].val != "quit"):(1));
	} DEFAULT_HANDLING

	return 0;
}
