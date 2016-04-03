#ifndef SIPY_PRECEDENCE_HPP
#define SIPY_PRECEDENCE_HPP

#include <map>
#include <string>

namespace LLCCEP_SiPy {
	static std::map <std::string, int> BinaryPrecedence = {
		{"+=",  1},
		{"-=",  1},
		{"*=",  1},
		{"/=",  1},
		{"**=", 1},
		{"=",   1},
		{"or",  2},
		{"xor", 3},
		{"and", 4},
		{"+",   5},
		{"-",   5},
		{"*",   6},
		{"/",   6}
	};

	int GetOperatorPrecedence(std::string op);
}

#endif // SIPY_PRECEDENCE_HPP
