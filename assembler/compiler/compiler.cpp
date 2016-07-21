#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <utility>

#include <errno.h>
#include <stddef.h>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
#include "../linker/linker.hpp"
#include "../codegen/codegen.hpp"

namespace LLCCEP_ASM {
	void compile(::std::string in_path, ::std::stringstream &out)
	{
		::std::ifstream in(in_path);
		if (in.fail()) {
			QUITE_ERROR(yes, "Can't open '%s' for read: %s!\n",
			            in_path.c_str(), ::std::strerror(errno));
		}

		::std::vector<lexem> program;
		::std::vector<::std::pair<lexem, size_t> > labels_table;

		try {
			for (size_t i = 1; !in.eof(); i++) {
				::std::string code = "";
				::std::getline(in, code);
				size_t old = labels_table.size();

				to_lexems(code, program, in_path, i);
				make_labels_associative_table(labels_table, program, i);

				if (!program.size() || labels_table.size() != old)
					continue;

				substitute_labels_with_addresses(labels_table, program);

				LLCCEP_ASM::op prep = prepare_op(program);
				dump_bitset(out, prep);
			
				code.clear();
				program.clear();
			}
		} catch (::LLCCEP::runtime_exception &exc) {
			throw (exc);
		} DEFAULT_HANDLING
	}
}

#endif // COMPILER_HPP
