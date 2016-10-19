#ifndef EXEC_CODEREADER_HPP
#define EXEC_CODEREADER_HPP

#include <STDExtras.hpp>

#include <vector>
#include <fstream>
#include <cstdint>

#include "./../../assembler/lexer/lexer.hpp"

namespace LLCCEP_exec {
	/* Module's constants */
	const size_t INSTRUCTION_LENGTH = 28;

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
		arg args[3];
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
		/* Explicit constructor, from file path.
		   Initialize everything with zeros and
		   set the input file to one with 
		   given path */
		explicit codeReader(::std::string in_path);

		/* Set input file */
		void initializeInputFile(::std::string in_path);
		/* Read input program head */
		void readProgramHeader();
		/* Read instruction by its id */
		instruction getInstruction(size_t id);
		/* Get program information */
		codeData getProgramData() const;
		/* Close input file */
		void closeInput();

		/* Check reader for being ok */
		bool OK() const;

	private:
		/* Input file */
		::std::ifstream input;
		/* Input file path */
		::std::string path;
		/* Input program data */
		codeData data;
	};
}

#endif // EXEC_CODEREADER_HPP
