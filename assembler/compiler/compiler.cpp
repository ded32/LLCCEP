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
#include "./../preprocessor/preprocessor.hpp"

#include "compiler.hpp"

LLCCEP_ASM::compiler::compiler()
{ }

LLCCEP_ASM::compiler::~compiler()
{ }

void LLCCEP_ASM::compiler::compile(::std::vector<::std::string> in, ::std::string out)
{
	LLCCEP_ASM::preprocessor prep;
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

	for (unsigned pass = 0; pass < 2; pass++) { 
		if (pass) {
			output << static_cast<uint8_t>(sizeof(size_t));
			dump_bytes(output, to_bytes(link.getMainAddress()));
		}

		for (size_t i = 0; i < inputs.size(); i++) {
			LLCCEP_ASM::lexer lex;
			lex.setProcessingPath(in[i]);
			lex.setProcessingFile(&inputs[i]);

			while (!inputs[i].eof()) { 
				::std::vector<LLCCEP_ASM::lexem> lexems; 
				lex.getNextLine(lexems); 

				auto generateCode = [&codegen, &lexems, &output] {
					if (lexems.size()) {
						LLCCEP_ASM::codeGenerator::op opData = codegen.prepareOperation(lexems);
						codegen.dumpOperationBitset(output, opData);
					}
				};

				if (pass) {
					::std::vector<LLCCEP_ASM::lexem> newLexems;

				        if (!prep.preprocessorStuff(lexems))
						prep.preprocessCode(lexems, newLexems);
					else
						continue;
				
					link.modifyVariablesTable(newLexems);
					if (!link.hasDeclaration(newLexems) && newLexems.size()) {
						lexems.clear();
						
						for (const auto &i: newLexems) {
							if (i.type == LLCCEP_ASM::LEX_T_NEWLINE) {
								link.substituteWithAddresses(lexems);
								generateCode();
								lexems.clear();
							} else {
								lexems.push_back(i);
							}
						}

						link.substituteWithAddresses(lexems);
						generateCode();	
					}
				} else {
					if (prep.preprocessorCode(lexems))
						continue;

					link.buildLabelsAssociativeTable(lexems, pc);

					if (!link.hasDeclaration(lexems) && lexems.size())
						pc++;
				}
			}

			reopen_file(inputs[i], in[i]);
		}
	}

	output.close();
}
