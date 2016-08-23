#include <vector>
#include <map>
#include <string>

#include <STDExtras.hpp>
#include <convert.hpp>
#include <STLExtras.hpp>

#include <stdio.h>
#include <cstdarg>

#include "./../../common/def/def_inst.hpp"

#include "./../lexer/lexer.hpp"
#include "analyzer.hpp"

LLCCEP_ASM::analyzer::analyzer()
{ }

LLCCEP_ASM::analyzer::~analyzer()
{ }

void LLCCEP_ASM::analyzer::analyze(::std::vector<LLCCEP_ASM::lexem> lex)
{
	auto argumentsMismatch = [this](LLCCEP_ASM::lexem lexemData, LLCCEP_ASM::lex_t t1) {
		::std::map<LLCCEP_ASM::lex_t, ::std::vector<LLCCEP_ASM::lex_t> > supportedMap = {
			{LLCCEP_ASM::LEX_T_REG,  {LLCCEP_ASM::LEX_T_REG}},
			{LLCCEP_ASM::LEX_T_MEM,  {LLCCEP_ASM::LEX_T_REG, LLCCEP_ASM::LEX_T_MEM}},
			{LLCCEP_ASM::LEX_T_VAL,  {LLCCEP_ASM::LEX_T_REG, LLCCEP_ASM::LEX_T_MEM, LLCCEP_ASM::LEX_T_VAL}},
			{LLCCEP_ASM::LEX_T_COND, {LLCCEP_ASM::LEX_T_COND}}
		};

		auto found = supportedMap.find(t1);
		if (found == supportedMap.end()) {
			analyzerIssue("undefined", 0,
				      "Lexem of type '%s' shouldn't appear on analyzis step!",
			              LLCCEP_ASM::getLexemTypename(lexemData.type).c_str());
		}

		auto data = supportedMap[t1];
		return (vec_find(data, lexemData.type) == data.end());
	};

	if (!lex.size())
		return;

	if (lex.size() > 4) {
		analyzerIssue(lex[0].pos.file, lex[0].pos.line,
		              "Too many lexems!\n"
			      "At least an instruction name and three arguments.");
	}

	int64_t instructionFound = LLCCEP_ASM::isInstruction(lex[0].val);
	if (instructionFound == -1) {
		analyzerIssue(lex[0].pos.file, lex[0].pos.line,
			      "No such instruction: '%s'!", 
		              lex[0].val.c_str());
	}

	for (unsigned i = 1; i < lex.size(); i++) {
		if (argumentsMismatch(lex[i], LLCCEP_ASM::INSTRUCTIONS[instructionFound].types[i - 1])) {
			analyzerIssue(lex[i].pos.file, lex[i].pos.line,
			              "Conflicting type of %u argument of "
				      "'%s' instruction.\n"
				      "'%s' is required, instead of '%s'.\n",
				      i, lex[0].val.c_str(),
				      LLCCEP_ASM::getLexemTypename(
					      LLCCEP_ASM::INSTRUCTIONS[instructionFound].types[i - 1]).c_str(),
				      LLCCEP_ASM::getLexemTypename(lex[i].type).c_str());
		}
	}
}

void LLCCEP_ASM::analyzer::analyzerIssue(::std::string file, size_t line, const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);

	char res[4096];
	vsprintf(res, (file + ::std::string(":") + to_string<size_t>(line) + ::std::string(":\n") + ::std::string(fmt)).c_str(), list);

	va_end(list);

	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG("%s", res));
}
