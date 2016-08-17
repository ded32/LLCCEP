#ifndef ASSEMBLER_COMPILER_HPP
#define ASSEMBLER_COMPILER_HPP

#include <vector>
#include <string>
#include <iostream>

namespace LLCCEP_ASM {
	void compile(::std::vector<::std::string> in_paths, ::std::ostream &out);
}

#endif // ASSEMBLER_COMPILER_HPP
