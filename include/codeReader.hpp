#ifndef EXEC_CODEREADER_HPP
#define EXEC_CODEREADER_HPP

#include <STDExtras.hpp>

#include <vector>
#include <iostream>
#include <cstdint>

#include "./../assembler/lexer/lexer.hpp"
#include "./../common/def/def_cond.hpp"
#include "./../common/def/def_inst.hpp"

namespace LLCCEP {
	/* Module's constants */
	const size_t INSTRUCTION_LENGTH = 28;
	const size_t MAX_ARGN           = 3;

	struct arg {
		/* Argument type */
		LLCCEP_ASM::lex_t type;
		/* Argument value */
		double val;
	} __attribute__((aligned(8))) /* 16 bytes */;

	struct instruction {
		/* Opcode */
		uint8_t opcode;
		/* Instruction arguments */
		arg args[MAX_ARGN];
	} __attribute__((aligned(8))) /* 56 bytes */;

	/* Input program data:
	   - offset of program, in bytes
	   - main label position
	   - size of program, in instructions */
	struct codeData {
		/* Offset of program, in bytes */
		size_t offset;
		/* Offset of main, in instructions */
		size_t main_id;
		/* Program size, in instructions */
		size_t size;
	};

	/* Program reader class */
	class codeReader {
	public:
		/* Default constructor,
		   just initialize everything with
		   zeros */
		codeReader();
		/* Explicit constructor, from file.
		   Initialize everything with zeros and
		   set the input file to the one given */
		explicit codeReader(::std::istream *in);

		/* Set input file */
		void initializeInputFile(::std::istream *in);
		/* Read input program head */
		void readProgramHeader();
		/* Read instruction by its id */
		instruction getInstruction(size_t id);
		/* Get program information */
		codeData getProgramData() const;
		/* Check reader for being ok */
		bool OK() const;

	private:
		/* Input file */
		::std::istream *input;
		/* Input program data */
		codeData data;
	};

	template<typename charT, typename traits>
	::std::basic_ostream<charT, traits> &operator<<(
		::std::basic_ostream<charT, traits> &out,
		arg argInfo)
	{
		switch (argInfo.type) {
		case LLCCEP_ASM::LEX_T_REG:
			out << "&" << argInfo.val;
			break;

		case LLCCEP_ASM::LEX_T_MEM:
			out << "$" << argInfo.val;
			break;

		case LLCCEP_ASM::LEX_T_VAL:
			out << argInfo.val;
			break;

		case LLCCEP_ASM::LEX_T_COND:
			out << "@" << LLCCEP_ASM::get_condition_mnemonic(
				static_cast<uint8_t>(argInfo.val));
			break;

		case LLCCEP_ASM::LEX_T_NO:
			break;

		default:
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Non-argument to dump an argument!"));
		}

		return out;
	}

	template<typename charT, typename traits>
	::std::basic_ostream<charT, traits> &operator<<(
		::std::basic_ostream<charT, traits> &out, 
		instruction inst)
	{
		out << LLCCEP_ASM::get_mnemonic_by_opcode(inst.opcode) << " ";

		for (unsigned i = 0; i < MAX_ARGN; i++) {
			if (inst.args[i].type == LLCCEP_ASM::LEX_T_NO)
				break;

			if (i)
				out << ", ";

			out << inst.args[i];
		}

		return out;
	}
}

#endif // EXEC_CODEREADER_HPP
