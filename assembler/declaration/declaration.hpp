#ifndef LLCCEP_ASM_DECLARATION_HPP
#define LLCCEP_ASM_DECLARATION_HPP

#include <string>
#include <vector>

#define createSectionDeclarations new declarations
#define createDeclaration new declaration

namespace LLCCEP_ASM {
	class declaration {
		::std::string name;
		size_t size;

	public:
		declaration();
		~declaration();

		void setName(::std::string newName);
		void setSize(size_t newSize);

		::std::string getName() const;
		size_t getSize() const;
	};

	class declarations {
		::std::vector<declaration *> decls;

	public:
		declarations();
		~declarations();

		void addDeclaration(declaration *decl);
		::std::vector<declaration *> getDeclarations() const;
	};
}

#endif /* LLCCEP_ASM_DECLARATION_HPP */
