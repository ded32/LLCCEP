#include <QApplication>

#include <string>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cerrno>

#include <STDExtras.hpp>
#include <convert.hpp>

#include "program/program.hpp"
#include "softcore/softcore.hpp"
#include "mm/mm.hpp"

void usage()
{
	::std::fprintf(stderr, "Usage:\n"
	                       "--help/--usage show help(this text)\n"
			       "-r number after is amount of RAM being allocated, in memory elements\n"
	                       "-p everything after is program storage\n"
	                       "If none config or command-line params are given, this help is shown.\n");
}

bool is_help(char * const str)
{
	return !strcmp(str, "--usage") ||
	       !strcmp(str, "--help");
}

bool is_mem(char * const str)
{
	return !strcmp(str, "-r");
}

bool is_program(char * const str)
{
	return !strcmp(str, "-p");
}

bool is_sys(char * const str)
{
	return is_program(str) || is_help(str) || is_mem(str);
}

void parse_command_line_params(int argn, char **argv, size_t &ramS, ::std::string &program)
{
	for (int i = 1; i < argn; i++) {
		if (is_help(argv[i])) {
			usage();
			::std::exit(EXIT_SUCCESS);
		} else if (is_mem(argv[i])) {
			i++;
			if (i >= argn)
				throw RUNTIME_EXCEPTION("Sudden end after '-r' option!\n");

			ramS = from_string<size_t>(argv[i]);
		} else if (is_program(argv[i])) {
			i++;
			if (i >= argn)
				throw RUNTIME_EXCEPTION("Sudden end after '-p' option!\n");

			program = argv[i];
		} else {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Unexpected to '%s'!\n",
				argv[i]));
		}
	}
}

int main(int argn, char **argv)
{
	QCoreApplication app(argn, argv);

	if (argn < 2) {
		usage();
		return EINVAL;
	}

	::std::string program;
	size_t ramS = 0;
	LLCCEP_exec::memoryManager mm;
	LLCCEP_exec::codeReader cr;

	try {
		parse_command_line_params(argn, argv, ramS, program);
	} catch (::LLCCEP::runtime_exception &exc) {
		usage();
		QUITE_ERROR(yes, "%s", exc.msg())
	} DEFAULT_HANDLING

	try {
		LLCCEP_exec::softcore sc;

		// Init codeReader
		cr.initializeInputFile(program);
		cr.readProgramHeader();
		// Init memoryManager
		mm.allocateElements(ramS);
		// Init softcore
		sc.setMm(&mm);
		sc.setCodeReader(&cr);

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
