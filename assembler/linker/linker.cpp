#include <vector>
#include <utility>
#include <string>

#include <stddef.h>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "../lexer/lexer.hpp"
#include "linker.hpp"

#define LINKER_ISSUE(file, line, fmt, ...) CONSTRUCT_MSG("Linking issue:\n%s:" size_t_pf ":\n" fmt "\n", file, line, ##__VA_ARGS__)

namespace LLCCEP_ASM {
	bool is_label(::std::vector<lexem> lex)
	{
		return lex.size() == 2 &&
		       lex[0].type == LEX_T_NAME &&
		       lex[1].type == LEX_T_COLON;
	}

	void make_labels_associative_table(
			::std::vector<::std::pair<lexem, size_t> > &associative_table,
			::std::vector<lexem> lex,
			size_t iteration)
	{
		auto associative_pair = [lex, iteration]() -> ::std::pair<lexem, size_t> {
			if (!is_label(lex))
				return ::std::make_pair(lexem{}, 0);

			if (lex.size() > 2) {
				throw RUNTIME_EXCEPTION(LINKER_ISSUE(
					lex[1].pos.file.c_str(),
					lex[1].pos.line,
					"Junk expressions after '%s' label!",
					lex[0].val.c_str()))
			}

			return ::std::make_pair(lex[0], iteration);
		};

		auto pair = associative_pair();
		if (!pair.first.val.length())
			return;	

		for (const auto &i: associative_table) {
			if (i.first.val == pair.first.val) {
				throw RUNTIME_EXCEPTION(LINKER_ISSUE(
						i.first.pos.file.c_str(), i.first.pos.line, 
						"'%s' label is declared both at " size_t_pf " and " size_t_pf "lines", 
						i.first.val.c_str(), i.first.pos.line, pair.first.pos.line))
			}
		}

		associative_table.push_back(pair);
	}

	void substitute_labels_with_addresses(
			::std::vector<::std::pair<lexem, size_t> >
				associative_table,
			::std::vector<lexem> &lex) 
	{
		auto lookup_place = [associative_table](::std::string val) -> ::std::pair<lexem, size_t> {
			for (const auto &i: associative_table) {
				if (i.first.val == val)
					return i;
			}

			return ::std::make_pair(lexem{}, 0);
		};

		for (size_t i = 1; i < lex.size(); i++) {
			if (lex[i].type == LEX_T_NAME) {
				auto pair = lookup_place(lex[i].val);
				if (pair.first.val.length()) {
					lex[i].type = LEX_T_VAL;
					lex[i].val = to_string(pair.second);
				} else {
					throw RUNTIME_EXCEPTION(LINKER_ISSUE(
							lex[i].pos.file.c_str(), lex[i].pos.line,
							"%s was not declared in this scope",
							lex[i].val.c_str()))
				}
			}
		}
	}
}

#undef LINKER_ISSUE
