#ifndef MM_HPP
#define MM_HPP

#include <cstddef>

namespace LLCCEP_exec {
	class memoryManager {
	public:
		memoryManager();
		~memoryManager();

		void allocateElements(size_t amount);
		void freeElements();

		::std::string getString(size_t offset);
		void writeString(size_t offset, ::std::string str);

	protected:
		bool OK() const;

	private:
		double *_mem;
		size_t _sz;
	};
}

#endif // MM_HPP
