#ifndef SIPY_ERRORS_HPP
#define SIPY_ERRORS_HPP

#include <string>
#include <cstdint>
#include <stdexcept>

namespace LLCCEP_SiPy {
	enum msg_flg {
		MSG_FLG_ONLY = 0b10,
		MSG_FLG_ALL  = 0b11,
		MSG_FLG_NO   = 0b01,
	};

	class Exception {
		std::string file;
		std::string func;
		size_t line;
		std::string msg;
		msg_flg msg_only;	

	public:
		Exception(std::string file_, std::string func_, size_t line_, std::string msg_);
		Exception(std::string msg_);
		Exception(std::string file_, std::string func_, size_t line_);

		virtual std::string what();
		virtual ~Exception();	
	};

	class SyntaxException: public Exception {
	public:
		SyntaxException(std::string msg_);
	};

	std::string error_notify(std::string file, size_t line, std::string msg);
}

#endif // SIPY_ERRORS_HPP
