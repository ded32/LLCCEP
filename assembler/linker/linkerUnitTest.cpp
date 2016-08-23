#include <iostream>
#include <string>
#include <vector>

#include <STDExtras.hpp>

#include "./../lexer/lexer.hpp"
#include "linker.hpp"

void dumpLexem(LLCCEP_ASM::lexem lexemData)
{
	::std::cout << "--> Lexem data: " << lexemData.val 
	            << "(" << LLCCEP_ASM::getLexemTypename(lexemData.type) << ")\n";	
}

void dump(::std::vector<LLCCEP_ASM::lexem> lexemData)
{
	for (const auto &i: lexemData)
		dumpLexem(i);
}

int main(void) 
{
	::std::vector<LLCCEP_ASM::lexem> lexems;
	LLCCEP_ASM::lexer lex;
	LLCCEP_ASM::linker linker;

	lex.setProcessingPath("stdin");
	lex.setProcessingFile(&::std::cin);

	size_t iteration = 0;

	try {
		do {
			lexems.clear();
			lex.getNextLine(lexems);
			
			bool res = linker.modifyVariablesTable(lexems);
			res |= linker.buildLabelsAssociativeTable(lexems,
			                                          iteration);

			if (!res && lexems.size()) {
				linker.substituteWithAddresses(lexems);
				iteration++;
			}

			dump(lexems);
		} while ((lexems.size())?(lexems[0].val != "exit"):(1));
	} DEFAULT_HANDLING

	return 0;
}
