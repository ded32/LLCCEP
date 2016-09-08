#ifndef INCLUDE_CONVERT_HPP
#define INCLUDE_CONVERT_HPP

#include <string>
#include <sstream>
#include <vector>
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

template<typename TYPE>
TYPE from_bytes(char data[sizeof(TYPE)])
{
	union {
		char bytes[sizeof(TYPE)];
		TYPE res;
	} cv;

	memcpy(cv.bytes, data, sizeof(TYPE));
	return cv.res;
}

template<typename TYPE>
::std::vector<uint8_t> to_bytes(TYPE data)
{
	union {
		TYPE val;
		uint8_t bytes[sizeof(TYPE)];
	} cv;

	memcpy(&cv.val, &data, sizeof(TYPE));
	return ::std::vector<uint8_t>(cv.bytes, cv.bytes + sizeof(TYPE));
}

template<class typeSrc, class typeDst>
constexpr typeDst reinterpret_value(typeSrc &&src)
{
	static_assert(sizeof(typeSrc) == sizeof(typeDst),
	              "Can't reintepret value between different-sized data types");
	
	return [src] {
		union {
			typeSrc src;
			typeDst dst;
		} cv;
		
		memcpy(&cv.src, &src, sizeof(typeSrc));
		return cv.dst;
	}();
}

#endif // INCLUDE_CONVERT_HPP
