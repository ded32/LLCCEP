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

#include "../../common/def/def_inst.hpp"

#define CHECK_PROGRAM_READER(cond) \
	DEFAULT_CHECK_BLOCK(cond, this, OK());

#define PROGRAM_READER_OK CHECK_PROGRAM_READER(true)
#define PROGRAM_READER_NOTOK CHECK_PROGRAM_READER(false)

LLCCEP_exec::codeReader::codeReader():
	_input(),
	_path(),
	_data()
{ }

LLCCEP_exec::codeReader::codeReader(::std::string in_path):
	_input(),
	_path(),
	_data()
{
	initializeInputFile(in_path);
}

void LLCCEP_exec::codeReader::initializeInputFile(::std::string in_path)
{
	PROGRAM_READER_NOTOK

	_input.open(in_path);
	if (_input.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open '%s' for read: %s!",
			in_path.c_str(), ::std::strerror(errno)));
	}

	_path = in_path;

	PROGRAM_READER_OK
}

void LLCCEP_exec::codeReader::readProgramHeader()
{
	PROGRAM_READER_OK

	uint8_t sz = 0;

	_input.seekg(0);
	sz = _input.get();

	if (sz > sizeof(size_t)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't execute the program:\n"
			"The word-length on machine, compiled\n"
			"this code is greater than on this.\n"
			"(" size_t_pf "-bit machine required)",
			static_cast<size_t>(sz)));
	}

	_input.read(reinterpret_cast<char *>(&_data.main_id),
		    sizeof(size_t));

	size_t pl = get_length(_input) - sz - 1;
	if (pl % 28) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't execute the program:\n"
			"Invalid or damaged binary file!\n"
			"Namely, the length of input, "
			"excluding header, not product of 28,\n"
			"which is instruction length. %zu",
			pl));
	}

	_data.size = pl / 28;
	_data.offset = sz + 1;

	PROGRAM_READER_OK
}

LLCCEP_exec::instruction LLCCEP_exec::codeReader::getInstruction(size_t id)
{
	PROGRAM_READER_OK

	if (id >= _data.size) {
		return LLCCEP_exec::instruction{
			INT8_MAX,
			{{LLCCEP_exec::ARG_T_NO, 0},
			 {LLCCEP_exec::ARG_T_NO, 0},
			 {LLCCEP_exec::ARG_T_NO, 0}}};
	}

	LLCCEP_exec::instruction res{};
	_input.seekg(_data.offset + id * 28);
	res.opcode = _input.get();

	if (res.opcode >= LLCCEP_ASM::INST_NUM) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Opcode is overbounded!\n"))
	}

	for (unsigned i = 0; i < 3; i++) {
		res.args[i].type = static_cast<LLCCEP_exec::arg_t>(_input.get());
		_input.read(reinterpret_cast<char *>(&res.args[i].val),
			    sizeof(double));
	}

	PROGRAM_READER_OK

	return res;
}

LLCCEP_exec::codeData LLCCEP_exec::codeReader::getProgramData() const
{
	PROGRAM_READER_OK

	return _data;
}

void LLCCEP_exec::codeReader::closeInput()
{
	PROGRAM_READER_OK

	_input.close();
	_path = "";

	PROGRAM_READER_NOTOK
}

bool LLCCEP_exec::codeReader::OK() const
{
	return _input.is_open() && _input && _path.length();
}

#undef CHECK_PROGRAM_READER
#undef PROGRAM_READER_OK
#undef PROGRAM_READER_NOTOK
