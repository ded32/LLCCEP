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

		bool hasDeclaration(::std::vector<lexem> lex) const;

		void modifyVariablesTable(::std::vector<lexem> lex);
		void buildLabelsAssociativeTable(::std::vector<lexem> lex,
				                 size_t iteration);
		void substituteWithAddresses(::std::vector<lexem> &lexems);

		size_t getMainAddress() const;

	protected:
		void linkerIssue(lexem issuedLexem, const char *fmt, ...) const;

		bool hasLabelDeclaration(::std::vector<lexem> lex) const;
		bool hasVariableModification(::std::vector<lexem> lex) const;

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
