#include <vector>
#include <fstream>
#include <cstring>
#include <cerrno>

#include <STLExtras.hpp>

#include "program.hpp"

namespace LLCCEP_vm {
	void read_program(::std::string input, ::std::vector<instruction> &program)
	{
		::std::ifstream in(input);
		if (in.fail()) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Error!\n"
				"Can't open %s for read: %s!\n",
				input.c_str(), ::std::strerror(errno)));
		}
		
		while (!in.eof()) {
			instruction temp = {};
			in >> temp.cond >> temp.opcode;

			for (unsigned i = 0; i < 3; i++) {
				char data[sizeof(double)] = {};

				in.read(data, 1);
				temp.args[i].type = static_cast<arg_t>(data[0]);

				in.read(data, sizeof(double));
				temp.args[i].val = from_bytes<double>(data);
			}

			program.push_back(temp);
		}

		in.close();
	}
}
