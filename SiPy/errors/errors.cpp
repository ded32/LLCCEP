#include <string>
#include <cstdint>
#include <cstdarg>

#include "errors.hpp"

namespace LLCCEP_SiPy {
	Exception::Exception(std::string file_, std::string func_, size_t line_, std::string msg_):
		file(file_),
		func(func_),
		line(line_),
		msg(msg_),
		msg_only(MSG_FLG_ALL)
	{}

	Exception::Exception(std::string msg_):
		file(""),
		func(""),
		line(0),
		msg(msg_),
		msg_only(MSG_FLG_ONLY)
	{}

	Exception::Exception(std::string file_, std::string func_, size_t line_):
		file(file_),
		func(func_),
		line(line_),
		msg(""),
		msg_only(MSG_FLG_NO)
	{}

	std::string Exception::what()
	{
		std::string res = "";

		if (msg_only & 0b01) {
			res += "An exception occured:\nFile: \"";
			res += file; res += "\"\nLine: ";
			res += std::to_string(line); res += "\n";
			res += "Function: "; res += func;
		}

		if (msg_only & 0b10) {
			res += msg;
		}

		return res;
	}

	Exception::~Exception()
	{}

	SyntaxException::SyntaxException(std::string msg_):
		Exception(msg_)
	{}

	std::string error_notify(std::string file, size_t line, std::string msg)
	{
		std::string res = "";
		for (unsigned i = 0; i < 100; i++)
			res += "-";
		
		res += '\n';
		res += file; res += ':'; res += std::to_string(line);
		res += '\n';
		res += msg;

		res += '\n';

		for (unsigned i = 0; i < 100; i++)
			res += '-';

		res += '\n';

		return res;
	}
}
