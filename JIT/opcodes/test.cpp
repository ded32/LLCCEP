#include "opcodes.hpp"

#include <vector>

struct func {

};

int main()
{
	std::vector<LLCCEP_JIT::BYTE> program;

	double *val = new double[2];

	LLCCEP_JIT::AppendFINIT(program);
	LLCCEP_JIT::AppendFPUSH(program, val);
	LLCCEP_JIT::AppendFPUSH(program, val + sizeof(double));
	LLCCEP_JIT::AppendFADD(program);

	return 0;
}
