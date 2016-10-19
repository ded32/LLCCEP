/*****************************************************************************************************************
* This header contains miscellanous extensions of STD C++ library. In particular,
* the safest no-throw error handling is implented here due libC functions. In addition to,
* good exception class with recursive mechanism is implented here.
* It gives you error info & its cause info...
* 
*****************************************************************************************************************/
#ifndef INCLUDE_STDEXTRAS_HPP
#define INCLUDE_STDEXTRAS_HPP

#include <cstdio>
#include <cstdlib>
#include <stddef.h>
#include <climits>
#include <stdexcept>
#include <cstdint>
#include <sstream>
#include <vector>

#if defined(__linux__)
#include <linux/limits.h>
#endif // linux

#define yes true
#define no false

#if defined(__GNUC__) || defined(__clang__)
#define __noreturn __attribute__((noreturn))
#elif defined(_MSC_VER)
#define __noreturn __declspec(noreturn)
#endif

#define MAX_EXC_BUF_SIZE (512 * 1024)

#define $(val) ({assert(val); val})

#define FATAL_ERROR(quit, place, fmt, ...) \
({ \
	::std::fprintf(stderr, "Fatal error in " place \
	                       ":\n%s file\n%d line\n%s function\n" fmt "\n", \
	                       __FILE__, __LINE__, __PRETTY_FUNCTION__, ##__VA_ARGS__); \
	\
	if (quit) \
		::std::exit(EXIT_FAILURE); \
});

#define QUITE_ERROR(quit, fmt, ...) \
({ \
	::std::fprintf(stderr, fmt "\n", ##__VA_ARGS__); \
	\
	if (quit) \
		::std::exit(EXIT_SUCCESS); \
});

#define CONSTRUCT_MSG_nodelete(fmt, ...) \
({ \
	char *__str = new char[MAX_EXC_BUF_SIZE]; \
	::std::sprintf(__str, fmt, ##__VA_ARGS__); \
	__str; \
})

#define CONSTRUCT_MSG(fmt, ...) \
CONSTRUCT_MSG_nodelete(fmt, ##__VA_ARGS__), true

namespace LLCCEP {
	class runtime_exception: public ::std::runtime_error {
		char __text__[MAX_EXC_BUF_SIZE];
	public:
		runtime_exception();
		runtime_exception(const char file[PATH_MAX],
		                  size_t line, 
		                  const char function[512], 
		                  const char *msg = 0,
				  bool freemsg = false,
		                  runtime_exception *cause = 0);

		virtual ~runtime_exception() throw();
		virtual const char *what() const throw();
		virtual const char *msg() const throw();
	};
}

namespace std {
	namespace extras {
		::std::string strerror_safe(int errid);
	}
}

#define RUNTIME_EXCEPTION(...) ::LLCCEP::runtime_exception(__FILE__, __LINE__,\
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
	            "exception data: %zd", id);\
} catch (...) {\
	FATAL_ERROR(yes, "default catch block", "unknown "\
 	            "exception type");\
}

#define DEFAULT_CHECK_BLOCK(cond, object_ptr, state) \
{ \
	if (object_ptr) { \
	        if ((cond && !state) || \
	            (!cond && state)) { \
	                throw RUNTIME_EXCEPTION(CONSTRUCT_MSG( \
	                        "Error!\n" \
	                        "Object at 0x%p excepted to be " \
	                        "%sOK, but is%s!", \
	                        this, \
	                        (cond)?(""):("not "), \
	                        (cond)?("not "):(""))) \
	        } \
	} \
}

::std::string getAbsolutePath(::std::string relpath);
void dump_bytes(::std::ostream &out, ::std::vector<uint8_t> list);

template<typename charT, typename traits, size_t length>
::std::basic_istream<charT, traits> &operator>>(::std::basic_istream<charT, traits> &in, const charT(&sliteral)[length])
{
	charT buf[length - 1] = {};

        in >> buf[0];
        if (length > 2)
		in.read(buf + 1, length - 2);

        if (memcmp(buf, sliteral, sizeof(buf))) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid input formatting!"))
	}

	return in;
}

template<typename charT, typename traits>
::std::basic_istream<charT, traits> &operator>>(::std::basic_istream<charT, traits> &in, const charT &cliteral)
{
	charT buf = 0;
	in >> buf;

	if (buf != cliteral) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid input formatting!"))
	}

	return in;
}

template<typename charT, typename traits, size_t length>
::std::basic_istream<charT, traits> &operator>>(::std::basic_istream<charT, traits> &in, charT(&carray)[length])
{
	return operator>>(in, carray);
}

#endif // INCLUDE_STDEXTRAS_HPP
