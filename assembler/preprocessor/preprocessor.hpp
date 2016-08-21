#ifndef PREPROCESSOR_HPP
#define PREPROCESSOR_HPP

#include <string>
#include <vector>
#include <fstream>
#include <cstddef>

#include "./../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class preprocessor {
	public:
		preprocessor();
		explicit preprocessor(::std::string inputPath);
		~preprocessor();
		
		void setPreprocessingFile(::std::string inputPath);
		void buildPreprocessingTable();
		void preprocessNextLine(::std::vector<lexem> &out);
		
	protected:
		void fillMacroTable();
		void addMacro(::std::vector<lexem> lexemData);
		
	private:
		struct macro {
			::std::string _macroName;
			size_t _amountOfArguments;
			::std::vector<lexem> _substitution;
		};
		
		::std::ifstrem _in;
		::std::vector<macro> _macros;
		size_t _line;
	};
}

#endif // PREPROCESSOR_HPP
