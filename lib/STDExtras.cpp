#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cassert>
#include <stdexcept>

#if defined(__linux__)
#	include <linux/limits.h>
#endif // linux

#include <STDExtras.hpp>

#define MAKE_EXCEPTION_MESSAGE(file, line, func, msg, cause)\
({\
	char *__res = new (std::nothrow) char[MAX_EXC_BUF_SIZE];\
	assert(__res);\
	memset(__res, 0, MAX_EXC_BUF_SIZE);\
	::std::sprintf(__res, "Exception data:\n"\
	                      "File: \"%s\"\n"\
	                      "Function: \"%s\"\n"\
	                      "Line: %llu\n"\
	                      "Message: \"%s\"",\
	                      file, func, line, msg);\
	\
	if (cause) {\
		::std::sprintf(__res, "%s\n"\
		                      "Caused by: \n%s",\
		                      __res/*, cause->what()*/);\
	}\
	__res;\
})

namespace LLCCEP {
	runtime_exception::runtime_exception():
		runtime_error(""),
		__text__("")
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
		__text__("")
	{
		char *data = MAKE_EXCEPTION_MESSAGE(
		                     file, line, function,
		                     msg, cause);

		strcpy(__text__, data);
		delete data;
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
