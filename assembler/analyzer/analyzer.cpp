#include <vector>
#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"
#include "analyzer.hpp"

LLCCEP_ASM::analyzer::analyzer()
{ }

LLCCEP_ASM::analyzer::~analyzer()
{ }

void LLCCEP_ASM::analyzer::analyze(::std::vector<LLCCEP_ASM::lexem> lex)
{
	auto argumentsMismatch = [this](LLCCEP_ASM::lexem lex, LLCCEP_ASM::lex_t t1) {
		::std::map<LLCCEP_ASM::lex_t, ::std::vector<LLCCEP_ASM::lex_t> > supportedMap = {
			{LLCCEP_ASM::LEX_T_REG,  {LLCCEP_ASM::LEX_T_REG}},
			{LLCCEP_ASM::LEX_T_MEM,  {LLCCEP_ASM::LEX_T_REG, LLCCEP_ASM::LEX_T_MEM}},
			{LLCCEP_ASM::LEX_T_VAL,  {LLCCEP_ASM::LEX_T_REG, LLCCEP_ASM::LEX_T_MEM, LLCCEP_ASM::LEX_T_VAL}},
			{LLCCEP_ASM::LEX_T_COND, {LLCCEP_ASM::LEX_T_COND}}
		};

		auto found = supportedMap.find(lex.type);
		if (found == supportedMap.end()) {
			analyzerIssue("Lexem of type '%s' shouldn't appear on analyzis step!\n",
			              LLCCEP_ASM::getLexemTypename(lex.type));
		}

		for (const auto &i: supportedMap[lex.type]) {
			if (lex.type == i)
				return false;
		}

		return true;
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
		if (argumentsMismatch(lex[i], INSTRUCTIONS[pos_inst].types[i - 1])) {
			analyzerIssue(lex[i].pos.file, lex[i].pos.line,
			              "Conflicting type of %u argument of "
				      "'%s' instruction.\n"
				      "'%s' is required, instead of '%s'.\n",
				      i, lex[0].val.c_str(),
				      LLCCEP_ASM::getLexemTypename(
					      INSTRUCTIONS[pos_inst].types[i - 1]),
				      LLCCEP_ASM::getLexemTypename(lex[i].type));
		}
	}
}
