#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cstddef>

#include "./../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class preprocessor {
	public:
		preprocessor();
		~preprocessor();
		
		void setPreprocessingPath(::std::string path);
		void setPreprocessingFile(::std::istream *input);
		
		//void processIncludes();
		void buildMacroTable();
		void preprocessCode(::std::vector<lexem> in, ::std::vector<lexem> &out);
		//::std::vector<::std::string> getProcessingOrder();
		
		bool ok() const;

	protected:
		void preprocessingIssue(size_t line, const char *fmt, ...);

	private:
		struct macro {
			lexem _macroData;
			size_t _amountOfArguments;
			::std::vector<lexem> _substitution;
		};
		
		::std::istream *_in;
		::std::string _path;
		bool _started;
		
		::std::vector<macro> _macros;
		::std::vector<::std::string> _processingOrder; // reversed
	};
}

#endif // PREPROCESSOR_HPP
