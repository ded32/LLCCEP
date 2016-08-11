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
#include <STLExtras.hpp>

#include "../lexer/lexer.hpp"
#include "../linker/linker.hpp"
#include "../codegen/codegen.hpp"

namespace LLCCEP_ASM {
	void compile(::std::vector<::std::string> in_paths, ::std::stringstream &out)
	{	
		::std::vector<lexem> program;
		::std::vector<::std::pair<lexem, size_t> > labels_table;

		try {
			for (const auto &f: in_paths) {
				::std::ifstream in(f);
				if (in.fail()) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("Can't open '%s' for read: %s!\n",
					                                      f.c_str(), ::std::strerror(errno)))
				}

				for (int pass = 0; pass < 2; pass++) {
					for (size_t i = 1; !in.eof(); i++) {
						::std::string code = "";

						program.clear();
						::std::getline(in, code);
						to_lexems(code, program, f, i);

						if (!pass) {
							make_labels_associative_table(labels_table, program, i);
							continue;
						} else if (program.size() && !is_label(program)) {
							if (vec_find(labels_table, "_main") == labels_table.end())
								throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("Error!\n'_main' was not declared in this scope!"))
                            
							substitute_labels_with_addresses(labels_table, program);

							LLCCEP_ASM::op prep = prepare_op(program);
							dump_bitset(out, prep);
						}
					}

					reopen_file(in, f);
				}
			}
		} catch (::LLCCEP::runtime_exception &exc) {
			throw (exc);
		} DEFAULT_HANDLING
	}
}

#endif // COMPILER_HPP
