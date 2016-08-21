#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <string>
#include <vector>
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
		
		void processIncludes();
		void buildMacroTable();
		void preprocessNextLine(::std::vector<lexem> &out);
		::std::vector<::std::string> getProcessingOrder();
		
	protected:
		void fillMacroTable();
		void addMacro(::std::vector<lexem> lexemData);
		
	private:
		struct macro {
			::std::string _macroName;
			size_t _amountOfArguments;
			::std::vector<lexem> _substitution;
		};
		
		::std::ifstream *_in;
		::std::vector<macro> _macros;
		::std::vector<::std::string> _processingOrder;
		bool _started;
	};
}

#endif // PREPROCESSOR_HPP
