#include <string>
#include <regex>

#include <tools/check/regmatch.hpp>

bool LLCCEP_ASM::matches(::std::string str, ::std::string regex)
{
	return ::std::regex_match(str, ::std::regex(regex, ::std::regex_constants::egrep));
}
