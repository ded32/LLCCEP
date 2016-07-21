#ifndef STLEXTRAS_HPP
#define STLEXTRAS_HPP

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <fstream>

#include <STDExtras.hpp>

template<typename TYPE>
std::vector<TYPE> subvector(std::vector<TYPE> &src, size_t id0, size_t id1)
{
	typename std::vector<TYPE>::const_iterator first = src.begin() + id0;
	typename std::vector<TYPE>::const_iterator last = src.begin() + id1;
	std::vector<TYPE> res(first, last);
	return res;
}

template<typename TYPE>
std::vector<TYPE> init2vec(std::initializer_list<TYPE> src)
{
	std::vector<TYPE> res(src.begin(), src.end());
	return res;
}

template<typename TYPE>
void append_init(std::vector<TYPE> &dst, std::initializer_list<TYPE> src)
{
	dst.insert(dst.end(), src.begin(), src.end());
}

template<typename TYPE>
typename ::std::vector<TYPE>::iterator vec_find(::std::vector<TYPE> &vec, TYPE srch)
{
	return find(vec.begin(), vec.end(), srch);
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
char *to_bytes(TYPE &data)
{
	return static_cast<char *>(&data);
}

template<typename char_t>
typename ::std::basic_ifstream<char_t>::pos_type get_length(::std::basic_ifstream<char_t> &fd)
{
	if (fd.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"File reference with fail!\n"));
	}

	auto pos = fd.tellg();
	fd.seekg(fd.end);
	auto res = fd.tellg();

	fd.seekg(pos);

	return res;
}

#endif // STLEXTRAS_HPP
