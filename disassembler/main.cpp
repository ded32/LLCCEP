#include <command-line.hpp>
#include <STDExtras.hpp>

#include <iostream>
#include <fstream>
#include <string>

#include "disassembler/disassembler.hpp"

int main(int argn, char **argv)
{
	try {
		LLCCEP_tools::commandLineParametersParser clpp;
		clpp.addFlag(LLCCEP_tools::commandLineFlag{{"-o", "--output"},
					                    "output", true});
		clpp.setHelpText("LLCCEP disassembler parameters:\n"
		                 "-o/--output | output file path\n"
				 "-h/--help   | does help(this text) needs "
				 "to be shown\n"
				 "All files, written without output flag "
				 "before will become input\n"
				 "But there should be only one input");
		clpp.setMaxFreeParams(1);
		clpp.parse(argn, argv);
		
		LLCCEP_DisASM::disassembler disASM;

		::std::ifstream in;
		::std::ofstream out;
		::std::string outPath = clpp.getParam("output").length()?
		                        clpp.getParam("output"):
					::std::string("a.asm");

		OPEN_FILE(in, clpp.getFreeParams()[0]);
		OPEN_FILE(out, outPath);

		disASM.readFile(dynamic_cast<::std::istream *>(&in));
		disASM.dumpDisassembly(dynamic_cast<::std::ostream *>(&out));
	} DEFAULT_HANDLING

	return 0;
}
