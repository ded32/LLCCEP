#ifndef LLCCEP_ASM_STATEMENT_HPP
#define LLCCEP_ASM_STATEMENT_HPP

#include "instruction/instruction.hpp"
#include "label/label.hpp"

namespace LLCCEP_ASM {
	enum statement_t {
		STATEMENT_T_LABEL,
		STATEMENT_T_INSTRUCTION
	};

	union statementData {
		label *lbl;
		instruction *inst;
	};

	class statement {
		struct statementInfo {
			statement_t type;
			statementData data;
		};

	public:
		statement();
		~statement();

		void setData(instruction *inst);
		void setData(label *lbl);

		statement_t getType() const;
		statementData getData() const;
	};
}

#endif /* LLCCEP_ASM_STATEMENT_HPP */
