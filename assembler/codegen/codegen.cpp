#include <vector>
#include <iostream>

#include "../lexer/lexer.hpp"

#include "codegen.hpp"

LLCCEP_ASM::codeGenerator::codeGenerator():
	_out(0)
{ }

LLCCEP_ASM::codeGenerator::~codeGenerator()
{ }

void LLCCEP_ASM::codeGenerator::setOutput(::std::ostream *out)
{
	if (!out) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Error!\n"
			"Given output to codeGenetor is null!\n"));
	}

	_out = out;
}

LLCCEP_ASM::codeGenerator::op LLCCEP_ASM::codeGenerator::prepareOperation(
		::std::vector<lexem> &lex)
{
	LLCCEP_ASM::analyzer analyzer;
	analyzer.analyze(lex);

	LLCCEP_ASM::codeGenerator::op res{};
	res.instruction = LLCCEP_ASM::isInstruction(lex[0].val);
	for (unsigned i = 0; i < 3; i++) {
		if (i >= lex.size() - 1) {
			res.args[i].type = LLCCEP_ASM::LEX_T_NONE;
		} else {
			res.args[i].type = lex[i + 1].type;
			res.args[i].type = from_string<double>(lex[i + 1].val);
		}
	}

	return res;
}

void dumpOperationBitset(LLCCEP_ASM::codeGenerator::op data)
{
	auto dumpDouble = [this](double val) {
		for (size_t i = 0; i < sizeof(double); i++)
			*_out << (reinterpret_cast<uint8_t *>(&val))[i];
	};

	*_out << static_cast<uint8_t>(data.instruction);

	for (unsigned i = 0; i < 3; i++) {
		*_out << static_cast<uint8_t>(data.args[i].type);
		dumpDouble(data.args[i].val);
	}
}
