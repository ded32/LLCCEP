#include <QApplication>

#include <string>
#include <iostream>

#include <cstring>

#include <STDExtras.hpp>
#include <command-line.hpp>

#include "messageBox/messageBox.hpp"
#include "codeReader/codeReader.hpp"
#include "softcore/softcore.hpp"
#include "mm/mm.hpp"
#include "signal/signal.hpp"

int main(int argn, char **argv)
{
	/* Initialize QT application */
	QApplication app(argn, argv);

	/* Handle signals, sent by program by
	   telling about them to user and
	   ending the execution */
	LLCCEP_exec::cAttachSignalsHandler();

	/* Windows, created by the executing program */
	::std::vector<LLCCEP_exec::window *> windows;

	try {
		/* Command-line parameters */
		commandLineParametersVM clp;
		/* Parse command-line parameters */
		clp.parse(argn, argv);
		/* If needed to show help, show it
		   and end the execution */
		if (clp.getHelpNeeded()) {
			clp.usage();
			return 0;
		}

		/* Soft-processor */
		LLCCEP_exec::softcore sc;
		/* Memeory manager */
		LLCCEP_exec::memoryManager mm;
		/* Program reader */
		LLCCEP_exec::codeReader cr;

		/* Read program's common information */
		cr.initializeInputFile(clp.getInput());
		cr.readProgramHeader();

		/* Allocate memory, how much is
		   permitted by user */
		mm.allocateElements(clp.getRamSize());

		/* Initialize soft-processor data */
		sc.setMm(&mm);
		sc.setCodeReader(&cr);

		/* Execute program */
		sc.executeProgram();

		mm.freeElements();
		cr.closeInput();
	} catch (::LLCCEP::runtime_exception &exc) {
		/* Spawn message box in case of
		   internal exception */
		LLCCEP_exec::messageBox("Program was interrupted by an exception",
					exc.msg(),
					QMessageBox::Close,
					QMessageBox::Close,
					QMessageBox::Critical).spawn();
		/* Dump to console error information */
		QUITE_ERROR(yes, "Program was interrupted by an exception:\n"
				 "%s", exc.msg());
	} DEFAULT_HANDLING

	return 0;
}
