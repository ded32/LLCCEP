#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <string>
#include <vector>
#include <cstddef>

#include "./../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class preprocessor {
		struct macro {
			lexem _macroData;
			size_t _amountOfArguments;
			::std::vector<lexem> _substitution;
		};

	public:
		preprocessor();
		~preprocessor();
				
		bool buildMacroTable(::std::vector<lexem> in);
		void processMacroTable();

		void preprocessCode(::std::vector<lexem> in, ::std::vector<lexem> &out);

		void dump() const;

	protected:
		void preprocessCode(::std::vector<lexem> in, ::std::vector<lexem> &out, ::std::vector<::std::string> forbidden);
		void preprocessingIssue(lexem issuedLexem, const char *fmt, ...);

	private:	
		::std::vector<macro> _macros;
		bool _processingMacro;
	};
}

#endif // PREPROCESSOR_HPP
