#ifndef STLEXTRAS_HPP
#define STLEXTRAS_HPP

#include <vector>
#include <initializer_list>
#include <cstddef>

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

#endif // STLEXTRAS_HPP
