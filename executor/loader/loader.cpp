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
		
			input >> temp.cond >> temp.opcode;
			for (unsigned i = 0; i < 3; i++)
				input >> temp.args[i].type >> temp.args[i].value;

			program.push_back(temp);
		}

		program.pop_back();

		return true;
	}
}
