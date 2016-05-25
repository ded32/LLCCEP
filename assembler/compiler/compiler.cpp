#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <cassert>
#include <string>

#include <STDExtras.hpp>

namespace LLCCEP_ASM {
	void compile(::std::string in_path, ::std::ostream &out)
	{
		::std::ifstream in(in_path);
		if (in.fail) {
			FATAL_ERROR(yes, "can't open '%s'"
			                 " file!\n", 
			                 in_path.c_str())
		}

		::std::vector<lexem> program;

		for (uint64_t i = 0; !in.eof(); i++) {
			::std::string code = "";
			::std::getline(in, code);
			try {
				to_lexems(code, program, 
				          in_path, i);
				op *prep = prepare_op(program);
				dump_bitset(out, prep);
				delete prep;
			} catch (::LLCCEP::runtime_exception &exc) {
				out.flush();
				throw RUNTIME_EXCEPTION("Compilation fails!\n", &exc);
			} DEFAULT_HANDLING
		}
	}
}

#endif // COMPILER_HPP
