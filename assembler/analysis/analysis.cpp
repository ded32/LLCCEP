#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include <STDExtras.hpp>

#include "../lexer/lexer.hpp"
#include "analysis.hpp"

#include "../../common/def/def_inst.hpp"
#include "../../common/def/def_cond.hpp"

#define ANALYSIS_ISSUE(file, line, fmt, ...) \
({\
	char *__res__ = new char[1024];\
	::std::sprintf(__res__, "Syntax error!\n%s:%d:\n" fmt "\n", file, line, ##__VA_ARGS__);\
	__res__;\
})

static const char *__static_only_mnemonics[6] = {
	"register",
	"memory address",
	"value",
	"name",
	"none",
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
		size_t required = 2;
		long long pos_inst = 0;

		if (size < required) {
			throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
				lex[0].pos.file.c_str(), 
				lex[0].pos.line, 
				"No instruction or condition!"))
		}

		if (is_cond(lex[0].val) == -1) {
			throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
				lex[0].pos.file.c_str(),
				lex[0].pos.line,
				"Unknown condition '%s'!",
				lex[0].val.c_str()))
		}

		pos_inst = is_inst(lex[1].val);
		if (pos_inst == -1) {
			throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
				lex[1].pos.file.c_str(),
				lex[1].pos.line,
				"Unknown instruction '%s'",
				lex[1].val.c_str()))
		}

		for (unsigned i = 2; i < lex.size(); i++) {
			if (INSTRUCTIONS[pos_inst].types[i - 2] < lex[i].type) {
				throw RUNTIME_EXCEPTION(ANALYSIS_ISSUE(
					lex[i].pos.file.c_str(),
					lex[i].pos.line,
					"Conflicting types for %u argument of '%s' instruction:\n"
					"%s is requested, but %s is given",
					i - 1, lex[1].val.c_str(), 
					__static_only_mnemonics[INSTRUCTIONS[pos_inst].types[i - 2]],
					__static_only_mnemonics[lex[i].type]))
			}
		}
	}
}
