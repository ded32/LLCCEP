#include <QApplication>

#include <string>
#include <iostream>

#include <cstring>

#include <STDExtras.hpp>
#include <command-line.hpp>

#include "codeReader/codeReader.hpp"
#include "softcore/softcore.hpp"
#include "mm/mm.hpp"

int main(int argn, char **argv)
{
	QCoreApplication app(argn, argv);

	try {
		commandLineParametersVM clp;
		clp.parse(argn, argv);
		if (clp.getHelpNeeded()) {
			clp.usage();
			return 0;
		}

		LLCCEP_exec::softcore sc;
		LLCCEP_exec::memoryManager mm;
		LLCCEP_exec::codeReader cr;

		// Init codeReader
		cr.initializeInputFile(clp.getInput());
		cr.readProgramHeader();

		// Init memoryManager
		mm.allocateElements(clp.getRamSize());

		// Init softcore
		sc.setMm(&mm);
		sc.setCodeReader(&cr);

		// Execute program
		sc.executeProgram();

		// Release memoryManager data
		mm.freeElements();

		// Release codeReader data
		cr.closeInput();
	} catch (::LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s", exc.msg());
	} DEFAULT_HANDLING

	return 0;
}
