#ifndef ASSEMBLER_LINKER_HPP
#define ASSEMBLER_LINKER_HPP

#include <vector>
#include <string>

#include <cstddef>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class linker {
	public:
		linker();
		~linker();

		bool modifyVariablesTable(::std::vector<lexem> lex);
		bool buildLabelsAssociativeTable(::std::vector<lexem> lex,
				                 size_t iteration);
		void substituteWithAddresses(::std::vector<lexem> &lexems);
	
	protected:
		void linkerIssue(lexem issuedLexem, const char *fmt, ...);

	private:
		struct saveData {
			lexem lexemData;
			size_t pos;
			bool label;
		};

		::std::vector<saveData> _variablesLabels;
		::std::vector<size_t> _released;
	};
}

#endif // ASSEMBLER_LINKER_HPP
