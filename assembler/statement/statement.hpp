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
		statement_t type;
		statementData data;

		void build(::std::ostream &out, builderInfo *info);

	public:
		statement();
		~statement();

		void setData(instruction *inst);
		void setData(label *lbl);

		statement_t getType() const;
		statementData getData() const;

		friend class section;
	};
}

#endif /* LLCCEP_ASM_STATEMENT_HPP */
