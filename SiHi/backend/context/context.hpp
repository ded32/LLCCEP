#ifndef LLCCEP_SIHI_CONTEXT_HPP
#define LLCCEP_SIHI_CONTEXT_HPP

namespace LLCCEP_SiHi {
	enum context_t {
		CONTEXT_T_ORDINARY = 0,
		CONTEXT_T_CLASS    = 1,
		CONTEXT_T_PARAM    = 3,
		CONTEXT_T_BLOCK    = 4
	};

	class context {
		context_t cxt;
		::std::vector<::std::string> varNames;

	public:
		context();
		~context();

		void getContextType();
		::std::vector<::std::string> getVarList();
	};
}

#endif /* LLCCEP_SIHI_CONTEXT_HPP */
