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
#include <convert.hpp>

#include "../lexer/lexer.hpp"
#include "../linker/linker.hpp"
#include "../codegen/codegen.hpp"

namespace LLCCEP_ASM {
	void compile(::std::vector<::std::string> in_paths, ::std::stringstream &out)
	{	
		::std::vector<lexem> program;
		::std::vector<::std::pair<lexem, size_t> > labels_table;
		
#define ITERATOR_T ::std::vector<::std::pair<lexem, size_t> >::iterator
		auto find_main = [&labels_table] {
			for (ITERATOR_T it = labels_table.begin(); it < labels_table.end(); it++)
				if ((*it).first.val == "_main")
					return it;
					
			return labels_table.end();
		};
#undef ITERATOR_T
		
		try {
			for (const auto &f: in_paths) {
				::std::ifstream in(f);
				if (in.fail()) {
					throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("Can't open '%s' for read: %s!\n",
					                                      f.c_str(), ::std::strerror(errno)))
				}

				for (int pass = 0; pass < 2; pass++) {
					if (pass) {
						out << static_cast<uint8_t>(sizeof(size_t));
						dump_bytes(out, to_bytes((*(find_main())).second));
					}

					for (size_t i = 1; !in.eof(); i++) {
						::std::string code = "";

						program.clear();
						::std::getline(in, code);
						to_lexems(code, program, f, i);

						if (!pass) {
							size_t sz = labels_table.size();
							make_labels_associative_table(labels_table, program, i - 1); // Map label, if exists to current line
							
							if (labels_table.size() != sz || !program.size())
								i--;
							
							continue;
						} else if (program.size() && !is_label(program)) {
							if (find_main() == labels_table.end()) {
								throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
									"Error!\n"
									"'_main', required as entry point, was not declared in this scope\n"))
							}

							substitute_labels_with_addresses(labels_table, program);

							LLCCEP_ASM::op prep = prepare_op(program);
							dump_bitset(out, prep);
						}
					}

					reopen_file(in, f);
				}
				
				in.close();
			}
		} catch (::LLCCEP::runtime_exception &exc) {
			throw (exc);
		} DEFAULT_HANDLING
	}
}

#endif // COMPILER_HPP
