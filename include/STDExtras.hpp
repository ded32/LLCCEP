/*****************************************************************************************************************
* This header contains miscellanous extensions of STD C++ library. In particular,
* the safest no-throw error handling is implented here due libC functions. In addition to,
* good exception class with recursive mechanism is implented here.
* It gives you error info & its cause info...
* 
*****************************************************************************************************************/
#ifndef STDEXTRAS_HPP
#define STDEXTRAS_HPP

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stdexcept>
#include <cstdint>

#if defined(__linux__)
#include <linux/limits.h>
#endif // linux

#define yes true
#define no false

#define FATAL_ERROR(quit, place, fmt, ...) \
({\
	::std::fprintf(stderr, "Fatal error in " place\
	                       ":\n%s file\n%d line\n%s function\n" fmt,\
	                       __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__);\
	\
	if (quit)\
		::std::exit(EXIT_FAILURE);\
});

#define QUITE_ERROR(quit, fmt, ...) \
({\
	::std::fprintf(stderr, fmt, ##__VA_ARGS__);\
	\
	if (quit)\
		::std::exit(EXIT_SUCCESS);\
});

#define MAX_EXC_BUF_SIZE (512 * 1024)

namespace LLCCEP {
	class runtime_exception: public ::std::runtime_error {
		char __text__[MAX_EXC_BUF_SIZE];
	public:
		runtime_exception();
		runtime_exception(const char file[PATH_MAX], 
		                  uint64_t line, 
		                  const char function[512], 
		                  const char msg[1024] = "",
		                  runtime_exception *cause = 0);

		virtual ~runtime_exception() throw();
		virtual const char *what() const throw();
		virtual const char *msg() const throw();
	};
}

#define RUNTIME_EXCEPTION(...) new (std::nothrow) ::LLCCEP::runtime_exception(__FILE__, __LINE__,\
                                                                              __PRETTY_FUNCTION__, ##__VA_ARGS__);

#define DEFAULT_HANDLING \
catch (::std::exception &exc) {\
	FATAL_ERROR(yes, "default catch block", "runtime error"\
	            " message: %s", exc.what());\
} catch (::std::string &str) {\
	FATAL_ERROR(yes, "default catch block", "caught string"\
	           " content: %s", str.c_str());\
} catch (int64_t &id) {\
	FATAL_ERROR(yes, "default catch block", "caught "\
	            "exception data: %lls", id);\
} catch (...) {\
	FATAL_ERROR(yes, "default catch block", "unknown "\
 	            "exception type");\
}

#endif // STDEXTRAS_HPP