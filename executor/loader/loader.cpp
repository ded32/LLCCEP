#include <cassert>
#include <vector>
#include <fstream>

#include "loader.hpp"

namespace LLCCEP {
	void LoadProgram(std::ifstream& in, std::vector <inst>& program)
	{
		assert(!in.fail());
	
		while (!in.eof()) {
			std::string str = "";

		}
	}
}
