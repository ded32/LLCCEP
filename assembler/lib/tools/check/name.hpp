#include <string>
#include <tools/check/regmatch.hpp>
#include <tools/check/name.hpp>

bool LLCCEP_ASM::okName(::std::string name)
{
	return LLCCEP_ASM::matches(name, "[a-zA-Z_][a-zA-Z_0-9]*");
}
