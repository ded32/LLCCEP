#ifndef DEF_INST_HPP
#define DEF_INST_HPP

namespace LLCCEP_ASM {
	struct inst {
		std::string name;
        lex_t types[3];
	};

	static const int INST_NUM = 17;

	static const inst INSTRUCTIONS[] = {{"mov",  {LEX_T_MEM, LEX_T_VAL, LEX_T_NO}},
	                                    {"mva",  {LEX_T_VAL, LEX_T_VAL, LEX_T_NO}},
	                                    {"push", {LEX_T_VAL, LEX_T_NO,  LEX_T_NO}},
	                                    {"pop",  {LEX_T_NO,  LEX_T_NO,  LEX_T_NO}},
	                                    {"top",  {LEX_T_MEM, LEX_T_NO,  LEX_T_NO}},
	                                    {"add",  {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"sub",  {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"mul",  {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"dev",  {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"and",  {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"or",   {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"xor",  {LEX_T_MEM, LEX_T_VAL, LEX_T_NO}},
	                                    {"loff", {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"roff", {LEX_T_MEM, LEX_T_VAL, LEX_T_VAL}},
	                                    {"nop",  {LEX_T_NO,  LEX_T_NO,  LEX_T_NO}},
	                                    {"swi",  {LEX_T_VAL, LEX_T_NO,  LEX_T_NO}},
	                                    {"cmp",  {LEX_T_VAL, LEX_T_VAL, LEX_T_NO}}};
}

#endif // DEF_INST_HPP
