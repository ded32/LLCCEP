#ifndef LLCCEP_ASM_INSTRUCTION_COMPILER_HPP
#define LLCCEP_ASM_INSTRUCTION_COMPILER_HPP

#include <iostream>

namespace LLCCEP_ASM {
	class instructionCompiler {
	public:
		instructionCompiler();
		~instructionCompiler();

		void compileInstruction(::std::ostream &out, statement *stat, builderInfo *info);
	};
}

#endif /* LLCCEP_ASM_INSTRUCTION_COMPILER_HPP */
