#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
#include "../codegen/codegen.hpp"

namespace LLCCEP_ASM {
	void compile(char * const in_path, ::std::stringstream &out)
	{
		::std::ifstream in(in_path);
		if (in.fail()) {
			QUITE_ERROR(yes, "can't open '%s'"
			                 " file!\n", 
			                 in_path)
		}

		::std::vector<lexem> program;

		for (uint64_t i = 0; !in.eof(); i++) {
			::std::string code = "";
			::std::getline(in, code);
			
			try {
				to_lexems(code, program, 
				          in_path, i);
				LLCCEP_ASM::op *prep = prepare_op(program);
				dump_bitset(out, prep);
				delete prep;
			} catch (::LLCCEP::runtime_exception &exc) {
				out.flush();
				throw RUNTIME_EXCEPTION("Compilation fails!", &exc);
			} DEFAULT_HANDLING

			code.clear();
			program.clear();
		}
	}
}

#endif // COMPILER_HPP
