#ifndef ANALYZER_HPP
#define ANALYZER_HPP

#include <vector>
#include <string>

#include "./../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class analyzer {
	public:
		analyzer();
		~analyzer();

		void analyze(::std::vector<lexem> lex);

	protected:
		void analyzerIssue(::std::string file, size_t line, const char *fmt, ...);
	};
}

#endif // ANALYZER_HPP
