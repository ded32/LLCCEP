#ifndef EXEC_MM_HPP
#define EXEC_MM_HPP

#include <cstddef>
#include <string>

#include <STDExtras.hpp>

namespace LLCCEP_exec {
	class memoryManager {
		UNCOPIABLE_CLASS(memoryManager)

	public:
		memoryManager();
		~memoryManager();

		void allocateElements(size_t amount);
		void freeElements();

		::std::string getString(size_t offset);
		void writeString(size_t offset, ::std::string str);

		size_t getMemSize() const;
		void *getMemBeginning();

		double &operator[](size_t id);

		bool OK() const;

	private:
		double &at(size_t id);
		double *addr(size_t id);

		double *mem;
		size_t actualSz;
		size_t maxSz;
	};
}

#endif // EXEC_MM_HPP
