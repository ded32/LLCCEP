#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cassert>

#include <STDExtras.hpp>
#include <os-specific.hpp>
#include <convert.hpp>

#include "../lexer/lexer.hpp"
#include "analysis.hpp"

#include "../../common/def/def_inst.hpp"
#include "../../common/def/def_cond.hpp"

#define ANALYSIS_ISSUE(file, line, fmt, ...) CONSTRUCT_MSG("Analysis issue!\n%s:" size_t_pf ":\n" fmt "\n", file, line, ##__VA_ARGS__)

static ::std::string __static_only_mnemonics[] = {
	"register",
	"memory address",
	"value",
	"name",
	"none",
	"condition",
	"invalid"
};

namespace LLCCEP_ASM {
	int64_t is_cond(::std::string str)
	{
		if (CONDS.find(str) == CONDS.end())
			return -1;
		
		return CONDS.at(str);
	}

	int64_t is_inst(::std::string str)
	{
		for (int64_t i = 0; i < INST_NUM; i++)
			if (INSTRUCTIONS[i].name == str)
				return i;

		return -1;
	}

	void analyze(::std::vector<lexem> &lex)
	{
		size_t size = lex.size();
		size_t required = 1;
		long long pos_inst = 0;

		if (size < required) {
			throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
				"undefined", 
				0, 
				"No instruction!"))
		}

		pos_inst = is_inst(lex[0].val);
		if (pos_inst == -1) {
			throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
				lex[0].pos.file.c_str(),
				lex[0].pos.line,
				"Unknown instruction '%s'",
				lex[0].val.c_str()))
		}

		for (unsigned i = 1; i < lex.size(); i++) {
			if (lex[i].type == LEX_T_COND) {
				int64_t id = is_cond(lex[i].val);
				if (id == -1) {
					throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
						lex[i].pos.file.c_str(),
						lex[i].pos.line,
						"Unknown condition: '%s'",
						lex[i].val.c_str()))
				}

				lex[i].val = to_string(id);
			}

			if (INSTRUCTIONS[pos_inst].types[i - 1] < lex[i].type) {
				throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
					lex[i].pos.file.c_str(),
					lex[i].pos.line,
					"Conflicting types for %u argument of '%s' instruction:\n"
					"%s is requested, but %s is given",
					i, lex[0].val.c_str(), 
					__static_only_mnemonics[INSTRUCTIONS[pos_inst].types[i - 1]].c_str(),
					__static_only_mnemonics[lex[i].type].c_str()))
			}
		}
	}
}

#undef ANALYSIS_ISSUE
