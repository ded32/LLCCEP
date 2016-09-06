#ifndef INCLUDE_STLEXTRAS_HPP
#define INCLUDE_STLEXTRAS_HPP

#include <vector>
#include <initializer_list>
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <typeinfo>

#include <errno.h>

#include <STDExtras.hpp>

#define TYPEHASH(t) typeid(t).hash_code()

template<typename TYPE>
::std::vector<TYPE> subvector(::std::vector<TYPE> &src, size_t id0, size_t id1)
{
	typename std::vector<TYPE>::const_iterator first = src.begin() + id0;
	typename std::vector<TYPE>::const_iterator last = src.begin() + id1;
	std::vector<TYPE> res(first, last);
	return res;
}

template<typename TYPE>
::std::vector<TYPE> init2vec(::std::initializer_list<TYPE> src)
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
typename ::std::vector<TYPE>::iterator vec_find(::std::vector<TYPE> &vec, const TYPE srch)
{
	return find(vec.begin(), vec.end(), srch);
}

template<typename char_t>
size_t get_length(::std::basic_ifstream<char_t> &fd)
{
	if (fd.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"File reference with fail!\n"));
	}

	auto start = fd.tellg();

	fd.seekg(0, ::std::ios_base::end);
	size_t res = fd.tellg();
	fd.seekg(start);

	return res;
}

template<typename TYPE>
void reopen_file(TYPE &f, std::string path)
{
	static_assert(TYPEHASH(TYPE) == TYPEHASH(::std::ifstream) ||
		      TYPEHASH(TYPE) == TYPEHASH(::std::ofstream),
		      "required std::ifstream or ::std::ofstream object as input");
	
	f.close();
	f.clear();

	f.open(path);	
	if (f.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Error!\n"
					"File '%s' reopening failed: %s",
					path.c_str(), ::std::strerror(errno)));
	}
}

#endif // INCLUDE_STLEXTRAS_HPP
