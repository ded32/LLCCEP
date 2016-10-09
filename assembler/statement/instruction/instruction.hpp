#ifndef LLCCEP_ASM_STATEMENT_INSTRUCTION_HPP
#define LLCCEP_ASM_STATEMENT_INSTRUCTION_HPP

#include <string>
#include "argument/argument.hpp"

namespace LLCCEP_ASM {
	class instruction {
		::std::string instructionName;
		instructionArguments *args;

	public:
		instruction();
		~instruction();

		void setName(::std::string name);
		void setArguments(instructionArgument *newArgs);

		::std::string getName() const;
		instructionArguments *getArguments() const;
	};
}

#endif /* LLCCEP_ASM_STATEMENT_INSTRUCTION_HPP */
