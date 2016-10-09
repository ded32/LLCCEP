#ifndef LLCCEP_ASM_DECLARATION_HPP
#define LLCCEP_ASM_DECLARATION_HPP

#include <string>

namespace LLCCEP_ASM {
	class declaration {
		struct declarationInfo {
			::std::string name;
			size_t sizeOnHeap;
		};

	public:
		declaration();
		~declaration();

		void setName(::std::string name);
		void setSize(size_t size);

		::std::string getName() const;
		size_t getSize() const;
	};
}

#endif /* LLCCEP_ASM_DECLARATION_HPP */
