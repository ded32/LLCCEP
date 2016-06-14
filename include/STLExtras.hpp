#ifndef STLEXTRAS_HPP
#define STLEXTRAS_HPP

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <cstdint>

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
typename std::vector<TYPE>::const_iterator vec_find(std::vector<TYPE> &vec, TYPE srch)
{
	return find(vec.begin(), vec.end(), srch);
}

template<typename TYPE>
TYPE from_bytes(uint8_t data[sizeof(TYPE)])
{
	union {
		TYPE val;
		uint8_t bytes[sizeof(TYPE)];
	} res;

	memcpy(res.bytes, data, sizeof(TYPE));
	return res.val;
}

template<typename TYPE>
uint8_t *to_bytes(TYPE &data)
{
	return static_cast<uint8_t *>(&data);
}

#endif // STLEXTRAS_HPP
