#include <vector>
#include <string>
#include <cstring>
#include <iostream>

#include <STDExtras.hpp>
#include <command-line.hpp>
#include <convert.hpp>

bool LLCCEP_command_line::isHelp(const char * const str)
{
	return !(::std::strcmp(str, "-h") ||
		 ::std::strcmp(str, "--help"));
}

bool LLCCEP_command_line::isRamSize(const char * const str)
{
	return !(::std::strcmp(str, "-r") ||
		 ::std::strcmp(str, "--ramsize"));
}

bool LLCCEP_command_line::isOutput(const char * const str)
{
	return !(::std::strcmp(str, "-o") ||
		 ::std::strcmp(str, "--output"));
}

commandLineParametersVM::commandLineParametersVM():
	_input(),
	_ramSize(4096),
	_help(false)
{ }

commandLineParametersVM::~commandLineParametersVM()
{ }

void commandLineParametersVM::parse(int argn, char **argv)
{
	for (int i = 1; i < argn; i++) {
		if (LLCCEP_command_line::isHelp(argv[i])) {
			_help = true;
		} else if (LLCCEP_command_line::isRamSize(argv[i])) {
			i++;
			
			if (i >= argn) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Sudden end after RAM size flag!\n"))
			}
			
			_ramSize = from_string<size_t>(argv[i]);
		} else {
			_input = argv[i];
		}
	}

	if (!_input.length()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No input given!\n"))
	}
}

void commandLineParametersVM::usage() const
{
	::std::cerr << "Usage:\n"
	            << "-h/--help show help(this text)\n"
	            << "-r/--ramsize number after is amount of RAM being allocated, in memory elements\n"
	            << "String with path will be input program.\n"
	            << "If none config or command-line params are given, this help is shown.\n";
}

::std::string commandLineParametersVM::getInput() const
{
	return _input;
}

size_t commandLineParametersVM::getRamSize() const
{
	return _ramSize;
}

bool commandLineParametersVM::getHelpNeeded() const
{
	return _help;
}
