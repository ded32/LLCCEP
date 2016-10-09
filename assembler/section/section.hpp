#ifndef LLCCEP_ASM_SECTION_HPP
#define LLCCEP_ASM_SECTION_HPP

#include <string>
#include <vector>

#include "../declaration/declaration.hpp"
#include "../statement/statement.hpp"

namespace LLCCEP_ASM {
	enum section_t {
		SECTION_T_DECLARATIVE,
		SECTION_T_IMPERATIVE
	};

	union sectionData {
		sectionDeclarations *decls;
		sectionStatements *stats;
	};

	class section {
		struct sectionInfo_t {
			section_t type;
			sectionData data;
			::std::string name;
		} info;

	public:
		section();
		~section();

		void setName(::std::string name);
		void setData(sectionDeclarations *decls);
		void setData(sectionStatements *stats);
		void setData(sectionData data);

		::std::string getName() const;
		section_t getType() const;
		sectionData getData() const;
	};

	class sectionList {
		::std::vector<section *> sections;

	public:
		sectionList();
		~sectionList();

		void addSection(section *sect);

		void buildDeclarative(::std::ostream &out) const;
		void buildImperative(::std::ostream &out) const;
	};
}

#endif /* LLCCEP_ASM_SECTION_HPP */
