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

#endif // CONVERT_HPP
