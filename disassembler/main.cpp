#include <vector>
#include <cstdint>
#include <fstream>
#include <string>
#include <cerrno>
#include <iostream>

#include "reader/reader.hpp"

#include "def/def_inst.hpp"
#include "def/def_cond.hpp"

int main(int argn, const char **argv)
{
	if (argn <= 1) {
		std::cerr << "No input!\n";
		return EINVAL;
	}

	for (int i = 1; i < argn; i++) {
		std::ifstream in;
		in.open(argv[i]);
		if (in.fail()) {
			std::cerr << "Failed to open '" << argv[i] << "' for read!\n";
			return EINVAL;
		}

		std::vector<LLCCEP_DisASM::op> ops;
		LLCCEP_DisASM::load(in, ops);

		std::ofstream out;
		out.open(std::string(argv[i]) + ".res_asm");
		if (out.fail()) {
			std::cerr << "Failed to open '" << argv[i] << ".res_asm" << "' for write!\n";
			return EINVAL;
		}

		for (size_t i = 0; i < ops.size(); i++) {
			out << LLCCEP_DisASM::cond[ops[i].condition] << " " 
			    << LLCCEP_DisASM::mnemonics[ops[i].instruction] << " ";

			for (unsigned j = 0; j < 3; j++) {
				switch (ops[i].args[j].type) {
				case LLCCEP_DisASM::LEX_T_REG:
					out << "&" << ops[i].args[j].value;
					break;

				case LLCCEP_DisASM::LEX_T_MEM:
					out << "$" << ops[i].args[j].value;
					break;

				case LLCCEP_DisASM::LEX_T_VAL:
					out << ops[i].args[j].value;

				default:
					break;
				}

				if (j < 2)
					out << ", ";
			}

			out << "\n";
		}

		out.close();
		in.close();
	}

	return 0;
}
