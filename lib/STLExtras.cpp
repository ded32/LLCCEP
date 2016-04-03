#include <vector>
#include <memory>

#include <STLExtras.hpp>

namespace LLCCEP {
	template<typename TYPE>
	std::vector<TYPE>& subvector(std::vector<TYPE> &src, size_t id0, size_t id1)
	{
		typename std::vector<TYPE>::const_iterator first = src.begin() + id0;
		typename std::vector<TYPE>::const_iterator last = src.begin() + id1;
		std::vector<TYPE> res(first, last);
		return res;
	}

	template <class T, class... Args>
	typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type make_unique(Args &&... args) 
	{
		return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
	}
}

