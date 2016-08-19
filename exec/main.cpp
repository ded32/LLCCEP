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
	QApplication app(argn, argv);
	LLCCEP_exec::cAttachSignalsHandler();

	::std::vector<LLCCEP_exec::window *> windows;
	int ret = 0;

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
		windows = sc.getWindows();

		// Release memoryManager data
		mm.freeElements();

		// Release codeReader data
		cr.closeInput();

		if (windows.size())
			ret = app.exec();

		for (const auto &i: windows) {
			i->close();
			delete i;
		}

		windows.clear();
	} catch (::LLCCEP::runtime_exception &exc) {
		LLCCEP_exec::messageBox("Program was interrupted by an exception",
					exc.msg(),
					QMessageBox::Close,
					QMessageBox::Close,
					QMessageBox::Critical).spawn();
		QUITE_ERROR(yes, "%s", exc.msg());
	} DEFAULT_HANDLING

	return ret;
}
