#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>

#include "loader.hpp"

namespace LLCCEP {
	bool LoadProgram(std::string in, std::vector <inst>& program)
	{
		std::ifstream input;
		input.open(in);
		if (input.fail()) {
			std::cerr << "Error! Can't open " << in << " for read!\n";
			return false;
		}

		while (!input.eof()) {
			inst temp = {};
			int8_t tmp = 0;
	
			input >> tmp >> temp.opcode; temp.cond = tmp;

			for (unsigned i = 0; i < 3; i++) {
				input >> tmp >> temp.args[i].value;
				temp.args[i].type = static_cast<arg_t>(tmp);
			}

			program.push_back(temp);
		}

		program.pop_back();

		return true;
	}
}
