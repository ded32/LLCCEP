#include <vector>
#include <pair>
#include <utility>
#include <string>

#include <stddef.h>

#include <STDExtras.hpp>
#include <os-specific.hpp>

#include "../lexer/lexer.cpp"
#include "linker.hpp"

#define LINKER_ISSUE(file, line, fmt, ...) CONSTRUCT_MSG("Linking issue:\n%s:" size_t_pf ":\n" fmt "\n", file, line, ##__VA_ARGS__)

namespace LLCCEP_ASM {
	::std::pair<::std::string, size_t> make_labels_associative_table(
			::std::vector<lexem> &lex, 
			size_t iteration)
	{
		if (lex.size() < 2 || lex[1].type != ':')
			return ::std::make_pair("", 0);

		if (lex.size() > 2) {
			throw RUNTIME_EXCEPTION(LINKER_ISSUE(
				lex[1].pos.file.c_str(),
				lex[1].pos.line,
				"Junk expressions after '%s' label!",
				lex[0].val.c_str()))
		}

		return ::std::make_pair(lex[0].val, iteration);
	}

	void substitute_labels_with_addresses(
			::std::vector<::std::pair<::std::string, size_t> >
				associative_table,
			::std::vector<lexem> &lex) 
	{
		auto lookup_place = [associative_table](::std::string val) -> associative_table::iterator {
			for (associative_table::iterator i = associative_table.begin();
			     i < associative_table.end(); i++) {
				if (((*i).first) == val)
					return associative_table::const_iterator(i);
			}

			return associative_table.end();
		};

		for (size_t i = 1; i < lex.size(); i++) {
			if (lex[i].type == LEX_T_NAME) {
				associative_table::iterator it = lookup_place(lex[i]);
				if (it != associative_table.end()) {
					lex[i].type = LEX_T_VAL;
					lex[i].val = (*it).second;
				}
			}
		}
	}
}

#undef LINKER_ISSUE
