#include <vector>
#include <fstream>
#include <cstring>
#include <cerrno>
#include <fstream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <convert.hpp>
#include <os-specific.hpp>

#include "codeReader.hpp"

#include "./../../assembler/lexer/lexer.hpp"
#include "./../../common/def/def_inst.hpp"

#define CHECK_PROGRAM_READER(cond) DEFAULT_CHECK_BLOCK(cond, this, OK());

#define PROGRAM_READER_OK CHECK_PROGRAM_READER(true)
#define PROGRAM_READER_NOTOK CHECK_PROGRAM_READER(false)

LLCCEP_exec::codeReader::codeReader():
	input(),
	path(),
	data()
{ }

LLCCEP_exec::codeReader::codeReader(::std::string in_path):
	input(),
	path(),
	data()
{
	/* Initialize input file */
	initializeInputFile(in_path);
}

void LLCCEP_exec::codeReader::initializeInputFile(::std::string in_path)
{
	PROGRAM_READER_NOTOK

	/* Open input */
	input.open(in_path);
	/* Check for there is no failure */
	if (input.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open '%s' for read: %s!",
			in_path.c_str(), 
			::std::extras::strerror_safe(errno).c_str()));
	}

	path = in_path;

	PROGRAM_READER_OK
}

void LLCCEP_exec::codeReader::readProgramHeader()
{
	PROGRAM_READER_OK

	/* Size of header */
	uint8_t sz = 0;

	/* Go to beginning of the file */
	input.seekg(0);
	/* Get first byte of the file */
	sz = input.get();

	/* If word length differes */
	if (sz > sizeof(size_t)) {
		/* Throw exception about this */
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't execute the program:\n"
			"The word length on machine, compiled\n"
			"the program is greater than on this one.\n"
			"(" size_t_pf "-bit machine required)",
			static_cast<size_t>(sz)));
	}

	/* Read header, just the ID of main label */
	input.read(reinterpret_cast<char *>(&data.main_id),
		    sizeof(size_t));

	/* Get program length */
	size_t pl = get_length(input) - sz - 1;

	/* If there is no some instruction whole */
	if (pl % LLCCEP_exec::INSTRUCTION_LENGTH) {
		/* Throw exception about it */
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't execute the program:\n"
			"Invalid or damaged binary file!\n"
			"Namely, the length of input, "
			"excluding header, not product of 28,\n"
			"which is instruction length."));
	}

	/* Set size of program, in instructions */
	data.size = pl / 28;
	/* Set offset */
	data.offset = sz + 1;

	PROGRAM_READER_OK
}

LLCCEP_exec::instruction LLCCEP_exec::codeReader::getInstruction(size_t id)
{
	PROGRAM_READER_OK

	if (id >= data.size) {
		return LLCCEP_exec::instruction{
			INT8_MAX,
			{{LLCCEP_ASM::LEX_T_NO, 0},
			 {LLCCEP_ASM::LEX_T_NO, 0},
			 {LLCCEP_ASM::LEX_T_NO, 0}}};
	}

	LLCCEP_exec::instruction res{};
	input.seekg(data.offset + id * 28);
	res.opcode = input.get();

	if (res.opcode >= LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Opcode is overbounded!\n"))
	}

	for (unsigned i = 0; i < 3; i++) {
		res.args[i].type = static_cast<LLCCEP_ASM::lex_t>(input.get());
		input.read(reinterpret_cast<char *>(&res.args[i].val),
			   sizeof(double));
	}

	PROGRAM_READER_OK

	return res;
}

LLCCEP_exec::codeData LLCCEP_exec::codeReader::getProgramData() const
{
	PROGRAM_READER_OK

	return data;
}

void LLCCEP_exec::codeReader::closeInput()
{
	PROGRAM_READER_OK

	input.close();
	path = "";

	PROGRAM_READER_NOTOK
}

bool LLCCEP_exec::codeReader::OK() const
{
	return input.is_open() && path.length();
}

#undef CHECK_PROGRAM_READER
#undef PROGRAM_READER_OK
#undef PROGRAM_READER_NOTOK
