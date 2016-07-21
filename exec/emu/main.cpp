#include <string>

#include <cstdio>
#include <cstring>

#include <STDExtras.hpp>
#include <convert.hpp>

#include "./../setup/setup.hpp"
#include "./../softcore/softcore.hpp"

void usage()
{
	::std::fprintf(stderr, "Usage:\n"
	                       "--help/--usage show help(this text)\n"
	                       "-r number after is amount of RAM being allocated, in bytes\n"
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

void parse_command_line_params(int argn, char * const *argv, size_t &ramS, ::std::vector<::std::string> &program)
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

			while (i < argn && !is_sys(argv[i])) {
				program.push_back(argv[i]);
				i++;
			}

			i--;
		} else {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Unexpected to '%s'!\n",
				argv[i]));
		}
	}
}

int main(int argn, char * const *argv)
{
	if (argn < 2) {
		usage();
		return EINVAL;
	}

	::std::vector<::std::string> program;
	size_t ramS = 0;
	::std::vector<LLCCEP_vm::instruction> prog;

	try {
		parse_command_line_params(argn, argv, ramS, program);
	} catch (::LLCCEP::runtime_exception &exc) {
		usage();
		QUITE_ERROR(yes, "%s", exc.msg())
	} DEFAULT_HANDLING

	try {
		for (size_t i = 0; i < program.size(); i++)
			LLCCEP_vm::read_program(program[i], prog);

		LLCCEP_vm::setup_vm_resources(ramS);
		LLCCEP_vm::execute(prog);
		LLCCEP_vm::free_vm_resources();
	} catch (::LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s", exc.msg());
	} DEFAULT_HANDLING

	return 0;
}
