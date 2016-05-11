#ifndef AST_H
#define AST_H

struct SiHi_ast_function_def {
	
};

struct SiHi_ast_external {
	enum type {
		SIHI_AST_EXTERNAL_FUNC_DEF,
		SIHI_AST_EXTERNAL_DECL
	};

	union value {
		struct SiHi_ast_function_def *def;
		struct SiHi_ast_declaration *decl;
	};
};

struct SiHi_ast_root {
	enum type {
		SIHI_AST_ROOT_EXTERN,
		SIHI_AST_ROOT_EXTERNAL_LIST
	} type;

	union value {
		struct SiHi_ast_external *extrn;
		
		struct {
			struct SiHi_ast_root *extrn_rt;
			struct SiHi_ast_external *extrn;
		} extrn_list;
	} val;
};

#endif // AST_H
