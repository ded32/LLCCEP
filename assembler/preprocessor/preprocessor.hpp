#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <string>
#include <vector>
#include <cstddef>

#include "./../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class preprocessor {
		struct macro {
			lexem macroData;
			size_t amountOfArguments;
			::std::vector<lexem> substitution;
		};

	public:
		preprocessor();
		~preprocessor();

		bool preprocessorStuff(::std::vector<lexem> in);
		bool preprocessorCode(::std::vector<lexem> in);
		void preprocessCode(::std::vector<lexem> in, ::std::vector<lexem> &out);

	protected:
		bool describeMacro(::std::vector<lexem> in);
	        bool deleteMacro(::std::vector<lexem> in);

		::std::vector<macro>::iterator findMacro(::std::string possibleName);
		::std::vector<macro>::const_iterator findMacro(::std::string possibleName) const;
		bool isMacroName(::std::string possibleName) const;

		bool shouldBePreprocessed(::std::vector<lexem> in) const;

		void preprocessCode(::std::vector<lexem> in, 
				    ::std::vector<lexem> &out, 
				    ::std::vector<::std::string> forbiddenMacros);

		void preprocessingIssue(lexem issuedLexem, const char *fmt, ...);
		void preprocessingWarning(lexem issuedLexem, const char *fmt, ...);
	private:	
		::std::vector<macro> macros;
		bool processingMacro;
		bool preprocessorsCode;
	};
}

#endif // PREPROCESSOR_HPP
