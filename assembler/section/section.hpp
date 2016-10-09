#ifndef LLCCEP_ASM_SECTION_HPP
#define LLCCEP_ASM_SECTION_HPP

#include <string>
#include <vector>

#include "../declaration/declaration.hpp"
#include "../statement/statement.hpp"

#define createSectionList new sectionList
#define createSection new section

namespace LLCCEP_ASM {
	enum section_t {
		SECTION_T_DECLARATIVE,
		SECTION_T_IMPERATIVE,
		SECTION_T_INVALID
	};

	union sectionData {
		sectionDeclarations *decls;
		sectionStatements *stats;
	};

	class section {
		section_t type;
		sectionData data;
		::std::string name;
		
		void build(::std::ostream &out, builderInformation *info);

	public:
		section();
		~section();

		void setName(::std::string name);
		void setData(sectionDeclarations *decls);
		void setData(sectionStatements *stats);

		::std::string getName() const;
		section_t getType() const;
		sectionData getData() const;

		friend class sectionList;
	};

	class sectionList {
		::std::vector<section *> sections;
		builderInformation *builderInfo;

	public:
		sectionList();
		~sectionList();

		void addSection(section *sect);

		void buildDeclarative(::std::ostream &out) const;
		void buildImperative(::std::ostream &out) const;
	};
}

#endif /* LLCCEP_ASM_SECTION_HPP */
