#include <string>
#include <map>
#include <STDExtras.hpp>

#include "def_cond.hpp"

::std::string LLCCEP_ASM::get_condition_mnemonic(uint8_t bin)
{
	const ::std::map<uint8_t, ::std::string> _CONDS = {
		{0b1000, "al"},
		{0b0100, "eq"},
		{0b0011, "ne"},
		{0b0101, "ae"},
		{0b0110, "le"},
		{0b0010, "ls"},
		{0b0001, "av"}
	};

	if (_CONDS.find(bin) == _CONDS.end()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't resolve condition %x!", bin));
	}

	return _CONDS.at(bin);
}
