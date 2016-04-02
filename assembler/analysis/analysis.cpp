#include <string>
#include <vector>
#include <iostream>

#include "../lexer/lexer.hpp"
#include "analysis.hpp"

#include "../def/def_inst.hpp"
#include "../def/def_cond.hpp"

#define ANALYSIS_ISSUE(file, line, msg) std::cerr << "\n--------------------------------------------------"\
                                                  << "--------------------------------------------------\n"\
                                                  << "Syntax error occured!\n"\
                                                  << file << ":" << line << "\n"\
                                                  << msg << "\n"\
                                                  << "--------------------------------------------------"\
                                                  << "--------------------------------------------------\n";

static const std::string mnemonics[6] = {
	"register",
	"memory address",
	"value",
	"name",
	"none",
	"invalid"
};

namespace LLCCEP_ASM {
	int64_t is_cond(std::string str)
	{
		if (CONDS.find(str) == CONDS.end())
			return -1;
		
		return CONDS.at(str);
	}

	int64_t is_inst(std::string str)
	{
		for (int64_t i = 0; i < INST_NUM; i++)
			if (INSTRUCTIONS[i].name == str)
				return i;

		return -1;
	}

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
			msg += lex[0].val; msg += "!";

			ANALYSIS_ISSUE(lex[0].pos.file, lex[0].pos.line, msg);
			return false;
		}

		pos_inst = is_inst(lex[1].val);
		if (pos_inst == -1) {
			std::string msg = "Unknown instruction ";
			msg += lex[1].val; msg += "!";

			ANALYSIS_ISSUE(lex[1].pos.file, lex[1].pos.line, msg);
			return false;
		}

		for (unsigned i = 2; i < lex.size(); i++) {
			if (INSTRUCTIONS[pos_inst].types[i - 2] < lex[i].type) {
				std::string msg = "Conflicting types for ";
				msg += lex[1].val; msg += " instruction:\n";
				msg += std::to_string(i - 1); msg += " requested as ";
				msg += mnemonics[INSTRUCTIONS[pos_inst].types[i - 2]];
				msg += " but it is presented as a ";
				msg += mnemonics[lex[i].type]; msg += "!";

				ANALYSIS_ISSUE(lex[i].pos.file, lex[i].pos.line, msg);
				return false;
			}
		}

		return true;
	}
}
