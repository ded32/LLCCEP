#include <string>
#include <iostream>

#include <codeReader.hpp>
#include <STDExtras.hpp>

#include "disassembler.hpp"

LLCCEP_DisASM::disassembler::disassembler():
	instructions(),
	mainID(0)
{ }

void LLCCEP_DisASM::disassembler::readFile(::std::string *in)
{
	if (!in) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting invalid file "
			"to disassembler!"));
	}

	LLCCEP::codeReader reader(in);
	LLCCEP::codeData header{};

	reader.readProgramHeader();
	header = reader.getProgramData();

	for (size_t i = 0; i < header.size; i++) {
		LLCCEP::instruction inst = reader.getInstruction(i);
		instructions.push_back(inst);
	}

	reader.closeInput();
	mainID = header.main_id;
}

void LLCCEP_DisASM::disassembler::dumpDisassembly(::std::ostream *out)
{
	if (!out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid dump file!"));
	}

	for (size_t i = 0; i < instructions.size(); i++) {
		if (i == mainID)
			(*out) << "_main:" << ::std::endl;

		(*out) << instructions[i] << ::std::endl;
	}
}
