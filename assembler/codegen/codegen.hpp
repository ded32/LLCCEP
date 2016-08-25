#ifndef ASSEMBLER_CODEGEN_HPP
#define ASSEMBLER_CODEGEN_HPP

#include <vector>
#include <iostream>

#include "../lexer/lexer.hpp"

namespace LLCCEP_ASM {
	class codeGenerator {
	public:
		struct arg {
			lex_t type;
			double value;
		};

		struct op {
			uint8_t instruction;
			arg args[3];
		};

		codeGenerator();
		~codeGenerator();

		op prepareOperation(::std::vector<lexem> &lex);
		void dumpOperationBitset(::std::ostream &out, op data);
	};
}

#endif // ASSEMBLER_CODEGEN_HPP
