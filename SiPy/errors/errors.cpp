#include <string>
#include <memory>
#include <cstdint>
#include <cstdarg>

#include "errors.hpp"

namespace LLCCEP_SiPy {
	Exception::Exception(std::string file_, std::string func_, size_t line_, std::string msg_):
		cause(0),
		file(file_),
		func(func_),
		line(line_),
		msg(msg_),
		msg_only(MSG_FLG_ALL)
	{}

	Exception::Exception(std::string file_, std::string func_, size_t line_, std::string msg_, Exception cause_):
		cause(new Exception(cause_)),
		file(file_),
		func(func_),
		line(line_),
		msg(msg_),
		msg_only(MSG_FLG_ALL)
	{}

	Exception::Exception(std::string msg_):
		cause(0),
		file(""),
		func(""),
		line(0),
		msg(msg_),
		msg_only(MSG_FLG_ONLY)
	{}

	Exception::Exception(std::string file_, std::string func_, size_t line_):
		cause(0),
		file(file_),
		func(func_),
		line(line_),
		msg(""),
		msg_only(MSG_FLG_NO)
	{}

	Exception::Exception(Exception &src):
		cause((src.cause)?(new Exception(*src.cause)):(0)),
		file(src.file),
		func(src.func),
		line(src.line),
		msg(src.msg),
		msg_only(src.msg_only)
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

		if (msg_only & 0b10)
			res += msg;

		if (cause)
			((res += "\n") += cause->what());

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
