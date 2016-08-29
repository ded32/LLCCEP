#include <string>
#include <convert.hpp>

#include "lexem.hpp"

::std::string LLCCEP_SiHi::lexem::toString(bool enforceForImage) const
{
	::std::string quote = /*((enforceForImage)?*/("\\\"")/*:("\""))*/;
	return quote + value + quote + ": " + to_string(type);
}
