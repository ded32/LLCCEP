#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <stdexcept>

#if defined(__linux__)
#	include <linux/limits.h>
#endif // linux

#include <STDExtras.hpp>

#define MAX_BUF_SIZE (1024 * 512)

namespace LLCCEP {
	runtime_exception::runtime_exception():
		runtime_error(""),
		__file__(),
		__line__(0),
		__function__(),
		__cause__(0)
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
		__file__(),
		__line__(line),
		__function__(),
		__cause__(cause)
	{
		::std::strcpy(__file__, file);
		::std::strcpy(__function__, function);
	}

	runtime_exception::~runtime_exception() throw()
	{ }

	const char *runtime_exception::what() const throw()
	{
		char *str = new char[MAX_BUF_SIZE];
		char res[MAX_BUF_SIZE] = "";
		::std::strcpy(res, runtime_error::what());

		::std::sprintf(str, "Exception data:\n"
		                    "File: %s\n"
		                    "Line: %d\n"
		                    "Function: %s\n"
		                    "Message: %s\n",
		                     __file__, __line__, 
		                     __function__, res);

		if (__cause__) {
			::std::sprintf(str, "Caused by:\n%s",
			               __cause__->what());
		}

		return str;
	}
}
