#include <QApplication>

#include <cstring>
#include <string>
#include <iostream>

#include <STDExtras.hpp>
#include <command-line.hpp>

#include "program/program.hpp"
#include "codegen/codegen.hpp"
#include "../exec/codeReader/codeReader.hpp"
#include "../exec/signal/signal.hpp"

#include "startup/program.hpp"
#include "startup/startup.hpp"

int main(int argn, char **argv)
{
	QCoreApplication app(argn, argv);
	LLCCEP_exec::cAttachSignalsHandler();

	try {
		commandLineParametersVM clp;
		clp.parse(argn, argv);
		if (clp.getHelpNeeded()) {
			clp.usage();
			return 0;
		}

		LLCCEP_JIT::codegenBackend cgen;
		LLCCEP_JIT::runtimeManager rm;
		LLCCEP_exec::codeReader cr;
		LLCCEP_exec::memoryManager mm;

		cr.initializeInputFile(clp.getInput());
		cr.readProgramHeader();

		mm.allocateElements(clp.getRamSize());

		rm.setMm(&mm);
		rm.setCodeReader(&cr);

		cgen.setRuntimeManager(&rm);
		cgen.emit_finit();
		cgen.generateProgram();
		cgen.emit_ret();

		LLCCEP_JIT::program_exec_data prog = LLCCEP_JIT::make_program(cgen);
		LLCCEP_JIT::call(prog);
		LLCCEP_JIT::delete_program(prog);

		mm.freeElements();
		cr.closeInput();
	} catch (LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s", exc.msg());
	} DEFAULT_HANDLING

	return 0;
}
