#ifndef ASSEMBLER_COMPILER_HPP
#define ASSEMBLER_COMPILER_HPP

#include <vector>
#include <string>
#include <fstream>

namespace LLCCEP_ASM {
	class compiler {
	public:
		compiler();
		~compiler();

		void compile(::std::vector<::std::string> in,
			     ::std::string out);
	};
}

#endif // ASSEMBLER_COMPILER_HPP
