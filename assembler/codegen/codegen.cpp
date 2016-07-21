#include <vector>
#include <cassert>
#include <iostream>
#include <cstring>

#include <STDExtras.hpp>

#include "codegen.hpp"
#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"

namespace LLCCEP_ASM {
	op prepare_op(::std::vector<lexem> &lex)
	{
		try {
			analyze(lex);
		} catch (::LLCCEP::runtime_exception &exc) {
			throw (exc);
		} DEFAULT_HANDLING

		op res = op{};

		for (unsigned i = 0; i < 3; i++)
			res.args[i].type = LEX_T_INVALID;
		
		res.instruction = is_inst(lex[1].val);

		try {
			for (size_t i = 1; i < lex.size(); i++) {
				res.args[i - 1].type = lex[i].type;
				res.args[i - 1].value = ::std::stod(lex[i].val);
			}
		} catch (::std::invalid_argument &exc) {
			throw (exc);
		} DEFAULT_HANDLING

		return res;
	}

	void dump_bitset(::std::ostream& out, op data)
	{
		assert(!out.fail());

		auto dump_double = [](::std::ostream &out, double val) {
			for (unsigned i = 0; i < sizeof(double); i++)
				out << ((uint8_t *)&val)[i];
		};

		out << data.instruction;

		for (size_t i = 0; i < 3; i++) {
			out << static_cast<uint8_t>(data.args[i].type);
			dump_double(out, data.args[i].value);
		}
	}
}
