#ifndef DEF_INST_HPP
#define DEF_INST_HPP

namespace LLCCEP_ASM {
	enum arg_t {
		ARG_T_REG = 0,
		ARG_T_MEM = 1,
		ARG_T_VAL = 2,
		ARG_T_NO  = 3
	};

	struct inst {
		std::string name;
		arg_t types[3];
	};

	static const int INST_NUM = 17;

	static const inst INSTRUCTIONS[] = {{"mov",  {ARG_T_MEM, ARG_T_VAL, ARG_T_NO}},
	                                    {"mva",  {ARG_T_VAL, ARG_T_VAL, ARG_T_NO}},
	                                    {"push", {ARG_T_VAL, ARG_T_NO,  ARG_T_NO}},
	                                    {"pop",  {ARG_T_NO,  ARG_T_NO,  ARG_T_NO}},
	                                    {"top",  {ARG_T_MEM, ARG_T_NO,  ARG_T_NO}},
	                                    {"add",  {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"sub",  {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"mul",  {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"dev",  {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"and",  {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"or",   {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"xor",  {ARG_T_MEM, ARG_T_VAL, ARG_T_NO}},
	                                    {"loff", {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"roff", {ARG_T_MEM, ARG_T_VAL, ARG_T_VAL}},
	                                    {"nop",  {ARG_T_NO,  ARG_T_NO,  ARG_T_NO}},
	                                    {"swi",  {ARG_T_VAL, ARG_T_NO,  ARG_T_NO}},
	                                    {"cmp",  {ARG_T_VAL, ARG_T_VAL, ARG_T_NO}}};
}

#endif // DEF_INST_HPP
