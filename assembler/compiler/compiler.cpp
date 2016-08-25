#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <STDExtras.hpp>
#include <STLExtras.hpp>
#include <convert.hpp>

#include "./../lexer/lexer.hpp"
#include "./../linker/linker.hpp"
#include "./../codegen/codegen.hpp"

#include "compiler.hpp"

LLCCEP_ASM::compiler::compiler()
{ }

LLCCEP_ASM::compiler::~compiler()
{ }

void LLCCEP_ASM::compiler::compile(::std::vector<::std::string> in, ::std::string out)
{
	//LLCCEP_ASM::preprocessor prep;
	LLCCEP_ASM::linker link;
	LLCCEP_ASM::codeGenerator codegen;
	size_t pc = 0;

	::std::vector<::std::ifstream> inputs;
	::std::ofstream output(out);
	if (output.fail()) {
		throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
			"Can't open '%s' as output: %s",
			out.c_str(), ::std::strerror(errno)));
	}

	for (const auto &i: in) {
		inputs.push_back(::std::ifstream{i});

		if (inputs[inputs.size() - 1].fail()) {
			throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
				"Can't open '%s' as input: %s",
				i.c_str(), ::std::strerror(errno)));
		}
	}

	for (unsigned pass = 0; pass < 2; pass++) { // bi-passage.
		if (pass) {
			output << static_cast<uint8_t>(sizeof(size_t));
			dump_bytes(output, to_bytes(link.getMainAddress()));
		}

		for (size_t i = 0; i < inputs.size(); i++) {
			LLCCEP_ASM::lexer lex;
			lex.setProcessingPath(in[i]);
			lex.setProcessingFile(&inputs[i]);

			while (!inputs[i].eof()) { // process entire file
				::std::vector<LLCCEP_ASM::lexem> lexems; // current line's lexems
				lex.getNextLine(lexems); // get'em

				bool hasDeclaration = link.hasDeclaration(lexems); // has line declaration, or not
				if (pass) {
					link.modifyVariablesTable(lexems);	
					if (!hasDeclaration && lexems.size()) {
						link.substituteWithAddresses(lexems);	
		
						LLCCEP_ASM::codeGenerator::op opData = codegen.prepareOperation(lexems);
						codegen.dumpOperationBitset(output, opData);
					}
				} else {
					link.buildLabelsAssociativeTable(lexems, pc);

					if (!hasDeclaration && lexems.size())
						pc++;
				}
			}

			reopen_file(inputs[i], in[i]);
		}
	}

	output.close();
}
