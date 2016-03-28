#include <string>
#include <vector>
#include <cstddef>
#include <iostream>

#include "../lexer/lexer.hpp"
#include "analysis.hpp"

#include "../def/def_inst.hpp"
#include "../def/def_cond.hpp"

#define ANALYSIS_ISSUE(file, line, msg) std::cerr << "Syntax error occured!\n" << file << ":" << line << "\n" << msg;

static long long is_in(const std::string *arr, std::string str, long long size)
{
	for (long long i = 0; i < size; i++)
		if (arr[i] == str)
			return i;

	return -1;
}

static long long is_cond(std::string str)
{
	return is_in(LLCCEP_ASM::CONDS, str, LLCCEP_ASM::CONDS_NUM);
}

static long long is_inst(std::string str)
{
	for (long long i = 0; i < LLCCEP_ASM::INST_NUM; i++)
		if (LLCCEP_ASM::INSTRUCTIONS[i].name == str)
			return i;

	return -1;
}

namespace LLCCEP_ASM {
	bool Analyze(std::vector <lexem> lex)
	{
		size_t size = lex.size();
		size_t required = 2;
		long long pos_inst = 0;

		if (size < required) {
			ANALYSIS_ISSUE(lex[0].pos.file, lex[0].pos.line, "No instruction name and arguments!");
			return false;
		}

		if (is_cond(lex[0].val) == -1) {
			std::string msg = "Unknown condition ";
			msg += lex[0].val; msg += "!\n";

			ANALYSIS_ISSUE(lex[0].pos.file, lex[0].pos.line, msg);
			return false;
		}

		pos_inst = is_inst(lex[1].val);
		if (pos_inst == -1) {
			std::string msg = "Unknown instruction ";
			msg += lex[1].val; msg += "!\n";

			ANALYSIS_ISSUE(lex[1].pos.file, lex[1].pos.line, msg);
			return false;
		}

		for (unsigned i = 0; i < 3; i++)
			if (INSTRUCTIONS[pos_inst].types[i] != ARG_T_NO)
				required++;

		if (lex.size() < required) {
			std::string msg = "Not enough arguments for ";
			msg += lex[1].val; msg += "instruction!\n";

			ANALYSIS_ISSUE(lex[1].pos.file, lex[1].pos.line, msg);
			return false;
		}

		return true;
	}
}
