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

	::std::ofstream output;
	OPEN_FILE(output, out);

	auto generateCode = [&codegen, &output](::std::vector<LLCCEP_ASM::lexem> lexems) {
		if (lexems.size()) {
			auto opData = codegen.prepareOperation(lexems);
			codegen.dumpOperationBitset(output, opData);
		}
	};

	for (unsigned pass = 0; pass < 2; pass++) { 
		if (pass) {
			output << static_cast<uint8_t>(sizeof(size_t));
			dump_bytes(output, to_bytes(link.getMainAddress()));
		}

		for (const auto &i: in) {
			::std::ifstream input;
			OPEN_FILE(input, i);

			LLCCEP_ASM::lexer lex;
			lex.setProcessingPath(i);
			lex.setProcessingFile(&input);
	
			while (!input.eof()) { 
				::std::vector<LLCCEP_ASM::lexem> lexems; 
				lex.getNextLine(lexems); 

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
								generateCode(lexems);
								lexems.clear();
							} else {
								lexems.push_back(i);
							}
						}

						link.substituteWithAddresses(lexems);
						generateCode(lexems);	
					}
				} else {
					if (prep.preprocessorCode(lexems))
						continue;

					link.buildLabelsAssociativeTable(lexems, pc);

					if (!link.hasDeclaration(lexems) && lexems.size())
						pc++;
				}
			}
		}
	}

	output.close();
}
