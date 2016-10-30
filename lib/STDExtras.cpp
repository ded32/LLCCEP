#ifdef UNICODE
#undef UNICODE
#endif

#ifdef _UNICODE
#undef _UNICODE
#endif

#if defined(_WIN32)
#include <windows.h>
#elif !defined(__linux__) && !defined(__MACH__)
#error Undefined OS
#endif

/* To provide access to
   strerror_s and
   strerrorlen_s functions */
#define __STDC_WANT_LIB_EXT1__ 1

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <string>

#if defined(__linux__)
#include <linux/limits.h>
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

::std::string std::extras::strerror_safe(int errid)
{
	::std::string res;

#if defined(__linux__) || defined(_WIN32)
	size_t len = strerrorlen_s(errid) + 1;
	char *buffer = new char[len];

	strerror_s(buffer, len, errid);
	res = ::std::string(buffer);
#elif defined(__MACH__)
	res = strerror(errid);
#else
#error Unknown OS
#endif

	return res;
}

::std::string getAbsolutePath(::std::string relpath)
{
	::std::string res;
	
#if defined(__linux__) || defined(__MACH__)
	char *fullpath = realpath(relpath.c_str(), 0);
	res = fullpath;
	delete fullpath;
#elif defined(_WIN32)
	char fullpath[PATH_MAX] = "";
	GetFullPathName(relpath.c_str(), MAX_PATH, fullpath, 0);
	res = fullpath;
#else
#error Undefined OS.
#endif
	
	return res;
}

void dump_bytes(::std::ostream &out, ::std::vector<uint8_t> list)
{
	for (const auto &i: list)
		out.put(i);
}

#undef MAKE_EXCEPTION_MESSAGE
