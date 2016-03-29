#include <fstream>
#include <cerrno>
#include <iostream>
#include <cassert>
#include <cstring>

#include "lexer/lexer.hpp"
#include "analysis/analysis.hpp"
#include "codegen/codegen.hpp"

#define FILEFAIL(path) {std::cerr << "Can't open '" << path << "' for read!\n"; return EBADF;}

int main(int argn, char * const *argv)
{
	if (argn <= 1) {
		std::cerr << "Error!\nNo input!\n";
		return EINVAL;
	}

	for (size_t i = 1; i < argn; i++) {
		size_t line = 1;

		std::ifstream in;
		std::ofstream out;

		in.open(argv[i]);
		out.open(std::string(argv[i]) + ".bin");

		if (in.fail())
			FILEFAIL(argv[i]);

		if (out.fail())
			FILEFAIL(std::string(argv[i]) + ".bin");

		while (!in.eof()) {
			std::string str = "";
			std::vector <LLCCEP_ASM::lexem> lex;

			std::getline(in, str);
			if (!LLCCEP_ASM::ToLexems(str, lex, argv[i], line))
				break;

			if (lex.size()) {
				LLCCEP_ASM::op *prep = LLCCEP_ASM::prepare_op(lex);
				LLCCEP_ASM::dump_bitset(out, prep);
			}

			line++;
		}

		in.close();
		out.close();
	}

	return 0;
}

