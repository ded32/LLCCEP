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
#include <os-specific.hpp>

#define MAKE_EXCEPTION_MESSAGE(file, line, func, msg, cause)\
({ \
	char *__res = new char[MAX_EXC_BUF_SIZE]; \
	::std::sprintf(__res, "A runtime exception was caught!\n" \
		              "File: %s\n" \
			      "Function subscript: %s\n" \
			      "Line: " size_t_pf "\n" \
			      "Message: '%s'\n", \
	                      file, func, line, msg); \
	if (cause) \
		::std::sprintf(__res, "%sCaused by: %s", \
			              __res, cause->what());\
\
	__res; \
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
	                                     size_t line,
	                                     const char function[512],
	                                     const char *msg,
					     bool freemsg,
	                                     runtime_exception *cause):
		runtime_error(msg),
		__text__()
	{
		char *data = MAKE_EXCEPTION_MESSAGE(file, line, function,
		                                    msg, cause);

		strcpy(__text__, data);
		free((void *)data);

		if (freemsg)
			free((void *)msg);
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

#undef MAKE_EXCEPTION_MESSAGE
