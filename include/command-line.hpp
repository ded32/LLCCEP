#ifndef INCLUDE_COMMAND_LINE_HPP
#define INCLUDE_COMMAND_LINE_HPP

#include <vector>
#include <string>
#include <cstddef>

namespace LLCCEP_command_line {
	bool isHelp(const char * const str);
	bool isRamSize(const char * const str);
	bool isOutput(const char * const str);
}

class commandLineParametersVM {
public:
	commandLineParametersVM();
	~commandLineParametersVM();
	
	void parse(int argn, char **argv);
	void usage() const;
	
	::std::string getInput() const;
	size_t getRamSize() const;
	bool getHelpNeeded() const;
	
private:
	::std::string _input;
	size_t _ramSize;
	bool _help;
};

#endif // INCLUDE_COMMAND_LINE_HPP
