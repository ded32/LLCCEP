#include <vector>
#include <cassert>
#include <iostream>

#include "codegen.hpp"
#include "../lexer/lexer.hpp"
#include "../analysis/analysis.hpp"

namespace LLCCEP_ASM {
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

		out << addr->condition << " "
		    << addr->instruction << " ";

		for (size_t i = 0; i < 3; i++) {
			out << addr->args[i].type << " "
		            << addr->args[i].value << " ";  
		}
	}
}
