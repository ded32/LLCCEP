#include <map>
#include <string>

#include "precedence.hpp"

namespace LLCCEP_SiPy {
	int GetOperatorPrecedence(std::string op)
	{
		if (BinaryPrecedence.find(op) == BinaryPrecedence.end())
			return -1;

		return BinaryPrecedence[op];
	}
}
