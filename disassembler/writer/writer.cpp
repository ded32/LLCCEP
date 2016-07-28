#include <iostream>
#include "../reader/reader.hpp"
#include "writer.hpp"

#include "../../common/def/def_inst.hpp"
#include "../../assembler/lexer/lexer.hpp"

::std::ostream &operator>>(::std::ostream &out, LLCCEP_DisASM::instruction inst)
{
	auto out_arg = [&out](LLCCEP_DisASM::arg arg, bool comma) {
		if (comma)
			out << ','
		out << ' '

		char prefixes[] = {
			'&', '$', '\0', '\0', '\0', '@', ':', '\0'
		};

		out << prefixes[i];
		switch (static_cast<LLCCEP_ASM::lex_t>(arg.type)) {
			case LEX_T_VAL:
			case LEX_T_MEM:
			case LEX_T_REG:
				out << arg.val;
				break;

			case LEX_T_COND:
				out << get_condition_mnemonic(static_cast<int>(arg.type));
				break;

			case LEX_T_NO:
			case LEX_T_COLON:
				break;

			default:
				throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
					"Argument of type %d shouldn't"
					"appear in assembled files...\n"
					"Damaged binary file...\n",
					LLCCEP_ASM::get_lexem_typename(static_cast<LLCCEP_ASM::arg_t>(arg.type))));
		}
	};

	out << get_mnemonic_by_opcode(inst.opcode) << " ";
	for (unsigned i = 0; i < 3) {

	}
}
