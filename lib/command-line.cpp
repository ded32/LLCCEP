#include <vector>
#include <string>
#include <cstring>
#include <iostream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <command-line.hpp>
#include <convert.hpp>

bool LLCCEP_command_line::isHelp(const char * const str)
{
	return !::std::strcmp(str, "-h") ||
	       !::std::strcmp(str, "--help");
}

bool LLCCEP_command_line::isRamSize(const char * const str)
{
	return !::std::strcmp(str, "-r") ||
	       !::std::strcmp(str, "--ramsize");
}

bool LLCCEP_command_line::isOutput(const char * const str)
{
	return !::std::strcmp(str, "-o") ||
	       !::std::strcmp(str, "--output");
}

LLCCEP_tools::commandLineParametersParser::commandLineParametersParser():
	flags(),
	helpText(),
	freeParams()
{ }

LLCCEP_tools::commandLineParametersParser::~commandLineParametersParser()
{ }

void LLCCEP_tools::commandLineParametersParser::addFlag(
	LLCCEP_tools::commandLineFlag clf)
{
	auto checkMnemonicsOK = [this, &clf] {
		for (const auto &i: clf.possibleMnemonics) {
			for (const auto &j: flags) {
				for (const auto &k: j.possibleMnemonics) {
					if (i == k) {
						throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
							"Redeclaring '%s' parameter mnemonic",
							k.c_str()));
					}
				}
			}
		}
	};

	for (const auto &i: flags) {
		if (i.name == clf.name) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Attempt of re-adding '%s' param",
				clf.name.c_str()));
		}
	}

	checkMnemonicsOK();
	flags.push_back(clf);
}

void LLCCEP_tools::commandLineParametersParser::setMaxFreeParams(size_t max)
{
	maxFreeParams = max;
}

void LLCCEP_tools::commandLineParametersParser::setHelpText(::std::string str)
{
	helpText = str;
}

void LLCCEP_tools::commandLineParametersParser::parse(int argn, char **argv)
{
	for (int i = 1; i < argn; i++) {
		auto param = isParam(argv[i]);

		if (param != flags.end()) {
			bool follow = followed(argv[i]);

			if (follow && i == argn - 1) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"'%s' requires a parameter after",
					argv[i]));
			} else if (follow) {
				param->following = argv[++i];
			} else if (!follow) {
				param->following = "1";
			}
		} else if (freeParams.size() > maxFreeParams && 
		           maxFreeParams != -1) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Too many free params"));
		} else {
			freeParams.push_back(argv[i]);
		}
	}
}

::std::string LLCCEP_tools::commandLineParametersParser::getParam(
	::std::string name)
{
	auto find = [this, name] {
		for (auto i = flags.begin(); i < flags.end(); i++)
			if (i->name == name)
				return i;

		return flags.end();
	};

	if (find() == flags.end()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"No such flag '%s'", name.c_str()));
	}

	return find()->following;
}

::std::vector<::std::string> LLCCEP_tools::commandLineParametersParser::getFreeParams()
{
	return freeParams;
}

auto LLCCEP_tools::commandLineParametersParser::isParam(::std::string mnem) -> decltype(LLCCEP_tools::commandLineParametersParser::flags.begin())
{
	for (auto i = flags.begin(); i < flags.end(); i++) {
		auto find = vec_find(i->possibleMnemonics, mnem);
		if (find != i->possibleMnemonics.end())
			return i;
	}

	return flags.end();
}

bool LLCCEP_tools::commandLineParametersParser::followed(::std::string mnem)
{
	auto param = isParam(mnem);
	if (param == flags.end()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Not param '%s'",
			mnem.c_str()));
	}

	return param->followed;
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
	            << "Every string with no ram's size flag before will be input.\n"
	            << "If none command-line params are given, this help is shown.\n";
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

commandLineParametersAssembler::commandLineParametersAssembler():
	_input(),
	_help()
{ }

commandLineParametersAssembler::~commandLineParametersAssembler()
{ }

void commandLineParametersAssembler::parse(int argn, char **argv)
{
	for (int i = 1; i < argn; i++) {
		if (LLCCEP_command_line::isHelp(argv[i])) {
			_help = true;
		} else if (LLCCEP_command_line::isOutput(argv[i])) {
			i++;
			if (i >= argn) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Sudden end after output flag!"))
			}

			if (_output.length()) {
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Output was already given."
					"It's '%s'", _output.c_str()))
			}

			_output = argv[i];
		} else {
			_input.push_back(argv[i]);
		}
	}
}

void commandLineParametersAssembler::usage() const
{
	::std::cerr << "Usage:\n"
	            << "-h/--help show help(this text)\n"
	            << "-o/--output string after is output path\n"
	            << "Every string with no output flag before will be inputs' path.\n"
	            << "If none command-line params are given, this help is shown.\n";
}

::std::vector<::std::string> commandLineParametersAssembler::getInput() const
{
	return _input;
}

::std::string commandLineParametersAssembler::getOutput() const
{
	return _output;
}

bool commandLineParametersAssembler::getHelpNeeded() const
{
	return _help;
}
