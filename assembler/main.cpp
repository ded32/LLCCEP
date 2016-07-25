#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <sstream>

#include <STDExtras.hpp>

#include "compiler/compiler.hpp"
#include "lexer/lexer.hpp"

void usage()
{
	::std::fprintf(stderr, "Usage:\n"
  	                       "--help/--usage show help(this text)\n"
	                       "-o file after is output\n"
	                       "If none output is provided, a.exec will be used.\n"
	                       "If none command-line params are given, this help is shown.\n");
}

bool is_help(char * const str)
{
	return !strcmp(str, "--usage") || !strcmp(str, "--help");
}

bool is_out(char * const str)
{
	return !strcmp(str, "-o");
}

bool is_spec(char * const str)
{
	return is_help(str) ||
	       is_out(str);
}

void parse_command_line_params(int argn, char * const *argv, ::std::vector<::std::string> &in, ::std::string &out)
{
	for (int i = 1; i < argn; i++) {
		if (is_help(argv[i])) {
			usage();
			::std::exit(EXIT_SUCCESS);
		} else if (is_out(argv[i])) {
			i++;
			if (i >= argn)
				throw RUNTIME_EXCEPTION("Sudden end after '-o' option!\n");

			out = argv[i];
		} else {
			in.push_back(argv[i]);
		}
	}
}

int main(int argn, char * const *argv)
{
	if (argn < 2) {
		::std::fprintf(stderr, "Empty command-line params list!\n");
		usage();
		return EINVAL;
	}

	::std::vector<std::string> inputs;
	std::string output = "a.exec";

	::std::stringstream out;
	::std::ofstream out_f;
	size_t i;

	try {
		parse_command_line_params(argn, argv, inputs, output);
	} catch (::LLCCEP::runtime_exception &exc) {
		usage();
		QUITE_ERROR(yes, "%s", exc.msg())
	} DEFAULT_HANDLING

	try {
		LLCCEP_ASM::compile(inputs, out);
	} catch (::std::ios_base::failure &info) {
		QUITE_ERROR(yes, "Can't open '%s' for read: "
		                 "%s\n", inputs[i].c_str(), info.what());
	} catch (::LLCCEP::runtime_exception &exc) {
		QUITE_ERROR(yes, "%s", exc.msg());
	} DEFAULT_HANDLING

	try {
		out_f.exceptions(::std::ofstream::failbit);
		out_f.open(output);

		out_f << out.str();

		out_f.close();
	} catch (::std::ios_base::failure &info) {
		::std::fprintf(stderr, "Error!\nCan't open '%s' for write: %s",
		               output.c_str(), info.what());
	} catch (...) {
		::std::fprintf(stderr, "Unknown exception");
	}
	
	return 0;
}
