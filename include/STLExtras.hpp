#ifndef STLEXTRAS_HPP
#define STLEXTRAS_HPP

#include <vector>
#include <cstdint>

namespace LLCCEP {
	template<typename TYPE>
	std::vector<TYPE> subvector(std::vector<TYPE> &src, size_t id0, size_t id1); 

	template <class T, class... Args>
	typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type make_unique(Args &&... args);
}

#endif // STLEXTRAS_HPP
