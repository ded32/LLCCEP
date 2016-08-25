#include <iostream>
#include <STDExtras.hpp>

#include "compiler.hpp"

int main()
{
	LLCCEP_ASM::compiler compiler;

	try {
		compiler.setProcessingFiles(
				::std::vector<::std::istream *>{&::std::cin},
				&::std::cout);

		compiler.compile();
	} DEFAULT_HANDLING

	return 0;
}
