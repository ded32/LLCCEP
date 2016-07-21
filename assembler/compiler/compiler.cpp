#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <cassert>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstring>
#include <cerrno>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
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

		for (uint64_t i = 1; !in.eof(); i++) {
			::std::string code = "";
			::std::getline(in, code);
	
			try {
				to_lexems(code, program, 
				          in_path, i);
			} catch (::LLCCEP::runtime_exception &exc) {
				throw (exc);
			} DEFAULT_HANDLING
	
			if (!program.size())
				continue;

			try {
				LLCCEP_ASM::op *prep = prepare_op(program);
				dump_bitset(out, prep);
				delete prep;
			} catch (::LLCCEP::runtime_exception &exc) {
				throw (exc);
			} DEFAULT_HANDLING

			code.clear();
			program.clear();
		}
	}
}

#endif // COMPILER_HPP
