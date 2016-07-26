#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>
#include <sstream>
#include <string.h>

template<typename T>
T from_string(::std::string str)
{
	T val = T();

	::std::stringstream stream;
	stream << str;
	stream >> val;

	return val;
}

template<typename T>
::std::string to_string(T data)
{
	::std::string val;

	::std::stringstream stream;
	stream << data;
	val = stream.str();

	return val;
}

template<typename T>
::std::vector<uint8_t> to_bytes(T val)
{
	union {
		char bytes[sizeof(T)];
		T typed;
	} res;

	memcpy(res.typed, val, sizeof(T));
	return ::std::vector(res.bytes, res.bytes + sizeof(T));
}

template<typename T>
T from_bytes(char *b)
{
	union {
		char bytes[sizeof(T)];
		T typed;
	} res;

	memcpy(res.bytes, b, sizeof(T));
	return res.typed;
}

#endif // CONVERT_HPP
