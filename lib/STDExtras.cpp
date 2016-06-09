#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cassert>
#include <stdexcept>
#include <sstream>

#if defined(__linux__)
#	include <linux/limits.h>
#endif // linux

#include <STDExtras.hpp>

#define MAKE_EXCEPTION_MESSAGE(file, line, func, msg, cause)\
({\
	::std::stringstream __res;\
	__res << "Exception data:\n"\
	         "File: \"" << file << "\"\n"\
	         "Function: \"" << func << "\"\n"\
	         "Line: " << line << "\n"\
	         "Message: \"" << msg << "%s\n";\
	\
	if (cause) \
		__res << "Caused by: " << cause->what() << "\n";\
	\
	__res.str().c_str();\
})

namespace LLCCEP {
	runtime_exception::runtime_exception():
		runtime_error(""),
		__text__()
	{
		FATAL_ERROR(yes, "runtime exception constructor",
   		                 "invalid initalization type:"
		                 "runtime_exception()")
	}

	runtime_exception::runtime_exception(const char file[PATH_MAX],
	                                     uint64_t line,
	                                     const char function[512],
	                                     const char msg[1024],
	                                     runtime_exception *cause):
		runtime_error(msg),
		__text__()
	{
		const char *data = MAKE_EXCEPTION_MESSAGE(
		                     file, line, function,
		                     msg, cause);

		strcpy(__text__, data);
	}

	runtime_exception::~runtime_exception() throw()
	{ }

	const char *runtime_exception::what() const throw()
	{
		return __text__;
	}

	const char *runtime_exception::msg() const throw()
	{
		return runtime_error::what();	
	}
}
