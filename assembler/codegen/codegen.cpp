#include <vector>
#include <cassert>
#include <iostream>
#include <cstring>

#include <STDExtras.hpp>

#include "codegen.hpp"
#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"

static void __dump_double_as_str(::std::ostream &out, double val)
{
	unsigned size = sizeof(double);
	for (unsigned i = 0; i < size; i++)
		out << *(uint8_t *)(&val);
}

namespace LLCCEP_ASM {
	op *prepare_op(::std::vector<lexem> &lex)
	{
		try {
			analyze(lex);
		} catch (::LLCCEP::runtime_exception &exc) {
			throw (exc);
		} DEFAULT_HANDLING

		op *res = new (std::nothrow) op;
		assert(res);
		::std::memset(res, 0, sizeof(*res));

		for (unsigned i = 0; i < 3; i++)
			res->args[i].type = LEX_T_INVALID;
		
		res->condition = is_cond(lex[0].val);
		res->instruction = is_inst(lex[1].val);

		for (size_t i = 2; i < lex.size(); i++) {
			res->args[i - 2].type = lex[i].type;
			res->args[i - 2].value = std::stod(lex[i].val);
		}

		return res;
	}

	void dump_bitset(::std::ostream& out, op *addr)
	{
		assert(addr);
		assert(!out.fail());

		out << addr->condition
		    << addr->instruction;

		for (size_t i = 0; i < 3; i++) {
			out << static_cast<uint8_t>(addr->args[i].type);
			__dump_double_as_str(out, addr->args[i].value);
		}
	}
}
