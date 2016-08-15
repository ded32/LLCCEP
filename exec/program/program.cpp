#include <vector>
#include <fstream>
#include <cstring>
#include <cerrno>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <convert.hpp>
#include <os-specific.hpp>

#include "program.hpp"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

LLCCEP_exec::program_data read_program_data(::std::ifstream &input)
{
	LLCCEP_exec::program_data res = LLCCEP_exec::program_data{};

	input.seekg(0);
	uint8_t sz = 0;
	input >> sz;

	res.offset = sz + 1;

	if (sz > sizeof(size_t)) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"The machine's architecture "
			"is " size_t_pf "-bit, but " size_t_pf "-bit required!\n",
			sizeof(size_t) * 8, static_cast<size_t>(sz) * 8));
	}

	char *bytes = new char[sz + 1];
	input.read(bytes, sz + 1);
	res.main_id = from_bytes<size_t>(bytes);
	size_t len = get_length(input);

	if ((len - sz - 1) % 28) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Bytecode file seems like damaged:\n"
			"It's size not multiple to 28,"
			" the size of instruction"))
	}

	res.size = (len - sz - 1) / 28;

	return res;
}

LLCCEP_exec::instruction LLCCEP_exec::get_instruction_by_id(::std::ifstream &input, program_data data, size_t id)
{
	if (id > data.size)
		return LLCCEP_exec::instruction{static_cast<uint8_t>(-1)};

	LLCCEP_exec::instruction res = LLCCEP_exec::instruction{};
	input.seekg(data.offset + id * 28);
	input >> res.opcode;

	for (unsigned i = 0; i < 3; i++) {
		char bytes[9] = "";

		input >> bytes[0];
		res.args[i].type = static_cast<LLCCEP_exec::arg_t>(bytes[0]);

		input.read(bytes, 9);
		res.args[i].val = from_bytes<size_t>(bytes);
	}

	return res;
}
