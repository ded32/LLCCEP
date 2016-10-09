#ifndef LLCCEP_ASM_BUILDER_INFO_HPP
#define LLCCEP_ASM_BUILDER_INFO_HPP

namespace LLCCEP_ASM {
	class builderInfo {
		::std::vector<label *> labels;
		::std::vector<declaration *> declarations;

	public:
		builderInfo();
		~builderInfo();

		void declareLabel(label *lbl);
		void addDeclaration(declaration *decl);

		size_t getAddress(::std::string name);
	};
}

#endif /* LLCCEP_ASM_BUILDER_INFO_HPP */
