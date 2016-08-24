#ifndef ASSEMBLER_COMPILER_HPP
#define ASSEMBLER_COMPILER_HPP

#include <vector>
#include <string>
#include <iostream>

namespace LLCCEP_ASM {
	class compiler {
	public:
		compiler();
		~compiler();

		void setProcessingFiles(::std::vector<::std::istream *> in,
				        ::std::ostream *out);
		void compile();

	private:
		::std::vector<::std::istream *> _in;
		::std::ostream *_out;
	};
}

#endif // ASSEMBLER_COMPILER_HPP
