#ifndef DEF_COND_HPP
#define DEF_COND_HPP

#include <cstdint>
#include <map>

namespace LLCCEP_DisASM {
	static std::map<uint8_t, std::string> cond = {
		{0b1000, "al"},
		{0b0100, "eq"},
		{0b0011, "ne"},
		{0b0101, "ae"},
		{0b0110, "le"},
		{0b0010, "ls"},
		{0b0001, "av"}
	};
}

#endif // DEF_COND_HPP
