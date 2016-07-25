#ifndef COMPILER_HPP
#define COMPILER_HPP

#include <vector>
#include <string>
#include <sstream>

namespace LLCCEP_ASM {
	void compile(::std::vector<::std::string> in_paths, ::std::stringstream &out);
}

#endif // COMPILER_HPP
