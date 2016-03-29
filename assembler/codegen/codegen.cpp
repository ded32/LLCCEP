#include <vector>
#include <cassert>
#include <iostream>

#include "codegen.hpp"
#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"

namespace LLCCEP_ASM {
	uint64_t double2ull(double val)
	{
		Convert cv = {};
		cv.real = val;
		return cv.integer;
	}

	void dump_ull_bitset(std::ofstream& out, uint64_t val)
	{
		assert(!out.fail());

		uint64_t mask = 0xFF00000000000000;
		for (size_t i = 0; i < 8; i++) {
			out << static_cast <char>((val & mask) >> 8 * (7 - i));
			mask >>= 8;
		}
	}

	op *prepare_op(std::vector <lexem> lex)
	{
		if (!Analyze(lex))
			return 0;

		op *res = new (std::nothrow) op;
		assert(res);

		*res = {};
		
		res->condition = is_cond(lex[0].val);
		res->instruction = is_inst(lex[1].val);

		for (size_t i = 2; i < lex.size(); i++) {
			res->args[i - 2].type = lex[i].type;
			res->args[i - 2].value = std::stod(lex[i].val);
		}

		return res;
	}

	void dump_bitset(std::ofstream& out, op *addr)
	{
		assert(addr);
		assert(!out.fail());

		out << static_cast <char>(addr->condition)
		    << static_cast <char>(addr->instruction);

		for (size_t i = 0; i < 3; i++) {
			out << addr->args[i].type;
			dump_ull_bitset(out, double2ull(addr->args[i].value));
		}
	}
}
