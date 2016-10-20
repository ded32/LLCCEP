#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <vector>

#include <STDExtras.hpp>
#include <command-line.hpp>

#include "compiler/compiler.hpp"

int main(int argn, char **argv)
{	
	try {
		LLCCEP_ASM::compiler compiler;
		::std::string output = "a.exec";
		::std::vector<::std::string> input;
		commandLineParametersAssembler clp;

		clp.parse(argn, argv);

		if (clp.getOutput().length())
			output = clp.getOutput();

		input = clp.getInput();
		compiler.compile(input, output);
	} catch (::LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s\n", exc.msg());
	} catch (...) {
		QUITE_ERROR(yes, "Unknown error!\n");
	}

	return 0;
}
