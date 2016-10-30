#include <string>
#include <iostream>

#include <codeReader.hpp>
#include <STDExtras.hpp>

#include "disassembler.hpp"

LLCCEP_DisASM::disassembler::disassembler():
	reader(),
	mainID(0)
{ }

LLCCEP_DisASM::disassembler::~disassembler()
{

}

void LLCCEP_DisASM::disassembler::readFile(::std::istream *in)
{
	if (!in) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"An attempt of setting invalid file "
			"to disassembler!"));
	}

	reader.initializeInputFile(in);
	LLCCEP::codeData header{};

	reader.readProgramHeader();
	header = reader.getProgramData();

	size = header.size;
	mainID = header.main_id;
}

void LLCCEP_DisASM::disassembler::dumpDisassembly(::std::ostream *out)
{
	if (!out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Invalid dump file!"));
	}

	for (size_t i = 0; i < size; i++) {
		if (i == mainID)
			(*out) << "_main:" << ::std::endl;

		(*out) << reader.getInstruction(i) << ::std::endl;
	}
}
