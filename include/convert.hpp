#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>
#include <sstream>

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

#endif // CONVERT_HPP
