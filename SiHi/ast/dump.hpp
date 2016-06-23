#ifndef DUMP_HPP
#define DUMP_HPP

#include <string>

#include "ast.hpp"

namespace LLCCEP_SiHi {
	void dump_ast(::std::string path, ::std::string name,
		       ast *tree);
}

#endif // DUMP_HPP
