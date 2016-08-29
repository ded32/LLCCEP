#include <string>
#include <convert.hpp>

#include "lexem.hpp"

::std::string LLCCEP_SiHi::lexem::toString() const
{
	return "\"" + value + "\": " + to_string(type);
}
