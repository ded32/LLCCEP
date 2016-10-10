#include <vector>
#include <iostream>

#include <STDExtras.hpp>
#include <convert.hpp>

#include "../analyzer/analyzer.hpp"
#include "../lexer/lexer.hpp"

#include "codegen.hpp"

LLCCEP_ASM::codeGenerator::codeGenerator()
{ }

LLCCEP_ASM::codeGenerator::~codeGenerator()
{ }

LLCCEP_ASM::codeGenerator::op LLCCEP_ASM::codeGenerator::prepareOperation(
		::std::vector<lexem> &lex)
{
	LLCCEP_ASM::analyzer analyzer;
	analyzer.analyze(lex);

	LLCCEP_ASM::codeGenerator::op res{};
	res.instruction = LLCCEP_ASM::isInstruction(lex[0].val);
	for (unsigned i = 0; i < 3; i++) {
		if (i >= lex.size() - 1) {
			res.args[i].type = LLCCEP_ASM::LEX_T_NO;
		} else {
			res.args[i].type = lex[i + 1].type;
			res.args[i].value = from_string<double>(lex[i + 1].val);
		}
	}

	return res;
}

void LLCCEP_ASM::codeGenerator::dumpOperationBitset(::std::ostream &out, LLCCEP_ASM::codeGenerator::op data)
{
	auto dumpDouble = [&out](double val) {
		for (size_t i = 0; i < sizeof(double); i++)
			out << reinterpret_cast<uint8_t *>(&val)[i];
	};

	out << static_cast<uint8_t>(data.instruction);

	for (unsigned i = 0; i < 3; i++) {
		out << static_cast<uint8_t>(data.args[i].type);
		dumpDouble(data.args[i].value);
	}
}
