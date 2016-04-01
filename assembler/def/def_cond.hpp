#ifndef DEF_COND_HPP
#define DEF_COND_HPP

#include <map>

namespace LLCCEP_ASM {
	static const int CONDS_NUM = 7;
	static const std::map<std::string, uint8_t> CONDS = {
		{"al", 0b1000},
		{"eq", 0b0100},
		{"ne", 0b0011},
		{"ae", 0b0101},
		{"le", 0b0110},
		{"ls", 0b0010}
}

#endif // DEF_COND_HPP
