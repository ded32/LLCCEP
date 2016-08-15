#ifndef DEF_INST_HPP
#define DEF_INST_HPP

#include <string>
#include "./../../assembler/lexer/lexer.hpp"

namespace LLCCEP_ASM {
	struct inst {
		::std::string name;
		lex_t types[3];
	};

	static const int INST_NUM = 29;
	static const inst INSTRUCTIONS[] = {
		{"mov",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"mva",   {LEX_T_VAL,  LEX_T_VAL,  LEX_T_NO}},
		{"push",  {LEX_T_VAL,  LEX_T_NO,   LEX_T_NO}},
		{"pop",   {LEX_T_NO,   LEX_T_NO,   LEX_T_NO}},
		{"top",   {LEX_T_MEM,  LEX_T_NO,   LEX_T_NO}},
		{"add",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"sub",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"mul",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"div",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"and",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"or",    {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"xor",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"off",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_VAL}},
		{"nop",   {LEX_T_NO,   LEX_T_NO,   LEX_T_NO}},
		{"swi",   {LEX_T_VAL,  LEX_T_NO,   LEX_T_NO}},
		{"cmp",   {LEX_T_VAL,  LEX_T_VAL,  LEX_T_NO}},
		{"inc",   {LEX_T_MEM,  LEX_T_NO,   LEX_T_NO}},
		{"dec",   {LEX_T_MEM,  LEX_T_NO,   LEX_T_NO}},
		{"sqrt",  {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"sin",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"cos",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"ptan",  {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
		{"patan", {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
	        {"ldc",   {LEX_T_MEM,  LEX_T_VAL,  LEX_T_NO}},
	        {"call",  {LEX_T_COND, LEX_T_VAL,   LEX_T_NO}},
		{"jmp",   {LEX_T_COND, LEX_T_VAL,   LEX_T_NO}},
		{"ret",   {LEX_T_NO,   LEX_T_NO,    LEX_T_NO}}
	};

	::std::string get_mnemonic_by_opcode(uint8_t op);
}

#endif // DEF_INST_HPP
