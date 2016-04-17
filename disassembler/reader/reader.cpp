#include <vector>
#include <string>
#include <fstream>

#include "reader.hpp"

namespace LLCCEP_DisASM {
	void load(std::ifstream &in, std::vector<op> &ops)
	{
		while (!in.eof()) {
			op tmp = {};
		
			in >> tmp.condition >> tmp.instruction;
			for (unsigned i = 0; i < 3; i++) {
				uint8_t temp = 0;
				in >> temp >> tmp.args[i].value;
				tmp.args[i].type = static_cast<lex_t>(temp);
			}

			ops.push_back(tmp);
		}

		ops.pop_back();
	}
}
