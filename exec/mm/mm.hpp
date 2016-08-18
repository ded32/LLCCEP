#ifndef EXEC_MM_HPP
#define EXEC_MM_HPP

#include <cstddef>
#include <string>

namespace LLCCEP_exec {
	class memoryManager {
	public:
		memoryManager();
		~memoryManager();

		void allocateElements(size_t amount);
		void freeElements();

		::std::string getString(size_t offset);
		void writeString(size_t offset, ::std::string str);

		size_t getMemSize() const;
		void *getMemBeginning() const;

		double operator[](size_t id) const;
		double &operator[](size_t id);

		bool OK() const;

	private:
		double *_mem;
		size_t _sz;
	};
}

#endif // EXEC_MM_HPP
