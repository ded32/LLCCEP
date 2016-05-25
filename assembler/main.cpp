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
  	                       "-h/-u show help(this text)\n"
	                       "-i files after are input\n"
	                       "-o file after is output\n"
	                       "If none output is provided, a.exec will be used.\n"
	                       "If none command-line params are given, this help is shown.\n");
}

bool is_help(char * const str)
{
	if (!strcmp(str, "-h") || !strcmp(str, "-u"))
		return true;

	return false;
}

bool is_in(char * const str)
{
	if (!strcmp(str, "-i"))
		return true;

	return false;
}

bool is_out(char * const str)
{
	if (!strcmp(str, "-o"))
		return true;

	return false;
}

bool is_spec(char * const str)
{
	return is_help(str) ||
	       is_in(str)   ||
	       is_out(str);
}

void parse_command_line_params(int argn, char * const *argv, ::std::vector<char *> &in, char *out)
{
	for (int i = 1; i < argn; i++) {
		if (is_help(argv[i])) {
			in.clear();
			out = 0;
			usage();
			::std::exit(EXIT_SUCCESS);
		} else if (is_in(argv[i])) {
			i++;
			if (i >= argn || is_spec(argv[i]))
				throw RUNTIME_EXCEPTION("Sudden end after '-i'(command line parameters)")

			while (!is_spec(argv[i]) && i < argn) {
				in.push_back(argv[i]);
				i++;
			}
		} else if (is_out(argv[i])) {
			i++;
			if (i >= argn || is_spec(argv[i]))
				throw RUNTIME_EXCEPTION("Sudden end after '-o'(command line parameters)")

			out = argv[i];
		}
	}
}

#define $(val) ({assert(val); val;})

int main(int argn, char * const *argv)
{
	if (argn < 2) {
		::std::fprintf(stderr, "Empty command-line params list!\n");
		usage();
		return EINVAL;
	}

	::std::vector<char *> inputs;
	char *output;
	::std::stringstream out;
	::std::ofstream out_f;

	try {
		parse_command_line_params(argn, argv, inputs, output);
	} catch (::LLCCEP::runtime_exception &exc) {
		usage();
		QUITE_ERROR(yes, exc.msg())
	} DEFAULT_HANDLING

	for (size_t i = 0; i < inputs.size(); i++)
		LLCCEP_ASM::compile(inputs[i], out);

	try {
		out_f.exceptions(::std::ofstream::failbit);
		out_f.open(output);
	} catch (::std::ios_base::failure &info) {
		::std::fprintf(stderr, "Error!\nCan't open '%s' for write: %s",
		               output, info.what());
	} catch (...) {
		::std::fprintf(stderr, "Unknown exception");
	}
	
	return 0;
}
