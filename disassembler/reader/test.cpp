#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <cstdint>

#include "reader.hpp"

static const std::string mnem[] = {
	"mov", "mva", "push",
	"pop", "top", "add",
	"sub", "mul", "dev",
	"and", "or", "xor",
	"off", "nop", "swi",
	"cmp", "inc", "dec"	
};

static std::map<uint8_t, std::string> cond = {
	{0b1000, "al"},
	{0b0100, "eq"},
	{0b0011, "ne"},
	{0b0101, "ae"},
	{0b0110, "le"},
	{0b0010, "ls"},
	{0b0001, "av"}
};

static const std::string types[] = {
	"register", "memory", "value", 
	"name", "nothing", "invalid"
};

static inline void dump(LLCCEP_DisASM::op oper)
{
	std::cout << cond[oper.condition] << " " 
	          << mnem[oper.instruction] << " ";

	for (unsigned i = 0; i < 3; i++)
		std::cout << types[oper.args[i].type] << " " << oper.args[i].value << " ";

	std::cout << "\n";
}

int main(int argn, const char **argv)
{
	if (argn <= 1) {
		std::cerr << "No input!\n";
		return -1;
	}

	for (int i = 1; i < argn; i++) {
		std::ifstream in;
		in.open(argv[i]);
		if (in.fail()) {
			std::cerr << "Open fail!\n";
			return -1;
		}

		std::vector<LLCCEP_DisASM::op> ops;
		LLCCEP_DisASM::load(in, ops);

		for (size_t i = 0; i < ops.size(); i++)
			dump(ops[i]);
	}
}
