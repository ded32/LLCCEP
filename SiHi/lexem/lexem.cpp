#include <string>
#include <convert.hpp>

#include "lexem.hpp"

::std::string LLCCEP_SiHi::lexem::toString(bool enforce) const
{
	::std::string quote = ((enforce)?("\\\""):("\""));
	return quote + value + quote + ": " + to_string(type);
}
