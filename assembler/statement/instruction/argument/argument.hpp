#ifndef LLCCEP_ASM_STATEMENT_INSTRUCTION_ARGUMENT_HPP
#define LLCCEP_ASM_STATEMENT_INSTRUCTION_ARGUMENT_HPP

#include <vector>
#include <string>

namespace LLCCEP_ASM {
	enum arg_t {
		ARG_T_NUMBER,
		ARG_T_LITERAL,
		ARG_T_ID,
		ARG_T_INVALID
	};

	union instructionArgumentData {
		double val;
		char *str;
	};

	class instructionArgument {
		arg_t type;
		instructionArgumentData data;

	public:
		instructionArgument();
		~instructionArgument();

		void setData(long long val);
		void setData(double val);
		void setData(::std::string str);

		arg_t getType() const;
		instructionArgumentData getData() const;
	};

	class instructionArguments {
		::std::vector<instructionArgument *> arguments;

	public:
		instructionArguments();
		~instructionArguments();

		void addArgument(instructionArgument *argument);
		::std::vector<instructionArgument *> getArguments() const;
	};
}

#endif /* LLCCEP_ASM_STATEMENT_INSTRUCTION_ARGUMENT_HPP */
