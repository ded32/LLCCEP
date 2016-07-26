#include <iostream>
#include <convert.hpp>
#include <STLExtras.hpp>
#include "reader.hpp"

namespace LLCCEP_DisASM {
	instruction read_instruction(::std::istream &in, ::std::string path)
	{
		auto read_double = [&in]() {
			char bytes[sizeof(double)] = {};
			in.get(bytes, sizeof(bytes));

			return from_bytes<double>(bytes);
		};

		instruction res = instruction{};	
		in.seekg(0);

		res.opcode = in.get();

		for (size_t i = 0; i < 3; i++) {
			res.args[i].type = in.get();
			res.args[i].val = read_double();
		}

		return res;
	}
}
