#include <string>

#include <cstdio>
#include <cstring>

#include <STDExtras.hpp>

#include "./../conf/conf.hpp"
#include "./../setup/setup.hpp"
#include "./../softcore/softcore.hpp"

void usage()
{
	::std::fprintf(stderr, "Usage:\n"
	                       "--help/--usage show help(this text)\n"
	                       "-c file after is config\n"
	                       "-p program storage\n"
	                       "If none config or command-line params are given, this help is shown.\n");
}

bool is_help(char * const str)
{
	return !strcmp(str, "--usage") ||
	       !strcmp(str, "--help");
}

bool is_cfg(char * const str)
{
	return !strcmp(str, "-c");
}

bool is_program(char * const str)
{
	return !strcmp(str, "-p");
}

void parse_command_line_params(int argn, char * const *argv, ::std::string &cfg, ::std::string &program)
{
	for (int i = 0; i < argn; i++) {
		if (is_help(argv[i])) {
			usage();
			::std::exit(EXIT_SUCCESS);
		} else if (is_out(argv[i])) {
			i++;
			if (i >= argn)
				throw RUNTIME_EXCEPTION("Sudden end after '-c' option!\n");

			cfg = argv[i];
		} else if (is_program(argv[i])) {
			i++;
			if (i >= argn)
				throw RUNTIME_EXCEPTION("Sudden end after '-p' option!\n");

			program = argv[i];
		} else {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Unexpected to '%s'!\n",
				argv[i]);
		}
	}
}

int main(int argn, char * const *argv)
{
	if (argv < 2) {
		usage();
		return EINVAL;
	}

	::std::string cfg = "";
	::std::string program = "";
	try {
		parse_command_line_params(argn, argv, cfg, program);
	} catch (::LLCCEP::runtime_exception &exc) {
		usage();
		QUITE_ERROR(yes, exc.msg())
	} DEFAULT_HANDLING

	LLCCEP_vm::config conf = {};
	try {
		conf = LLCCEP_vm::read_configuration_file(cfg);
		LLCCEP_vm::setup_vm(conf, true);
		LLCCEP_vm::execute(program);
		LLCCEP_vm::free_vm_resources(true);
	} DEFAULT_HANDLING

	return 0;
}
