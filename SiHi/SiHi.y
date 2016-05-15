%{
#include <stdio.h>
#include <stdlib.h>

#include "ast/ast.hpp"
#include "ast/node_types.hpp"

#define YYSTYPE LLCCEP_SiHi::ast *
#define YY_(str) ((char const *)str)

int yylex();
int yyerror(char const *str);

int pos_x;
%}

%token VAL ID LITERAL 

%token SWITCH CASE DEFAULT WHILE DO FOR CONTINUE BREAK
%token IF ELSE
%token GOTO RETURN

%token OP_CMP_LE OP_CMP_AE OP_CMP_EQ OP_CMP_NE

%token OP_INC OP_DEC

%token OP_OFFSET_L OP_OFFSET_R

%token OP_OFFSET_L_EQ OP_OFFSET_R_EQ
%token OP_ADD_EQ OP_SUB_EQ OP_MUL_EQ OP_DIV_EQ OP_MOD_EQ
%token OP_AND_EQ OP_OR_EQ OP_XOR_EQ

%token TYPEDEF EXTERN STATIC AUTO
%token STRUCT UNION ENUM

%token MANY_DOTS

%token PTR_ACS

%token VOID REAL BOOL
%token OP_LOGIC_AND OP_LOGIC_OR

%start main_parsing_unit

%%
primary_expression: 
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| VAL {$$ = new LLCCEP_SiHi::ast({}, VAL, yytext);}
	| LITERAL {$$ = new LLCCEP_SiHi::ast({}, LITERAL, yytext);}
	| '(' expression ')' {$$ = $2;};

postfix_expression: 
	primary_expression {$$ = $1;}
	| postfix_expression '[' expression ']' {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARRAY_ACCESS, "Array usage");}
	| postfix_expression '(' ')' {$$ = new LLCCEP_SiHi::ast({$1}, INVOKATION, "Function invokation");}
	| postfix_expression '(' argument_expression_list ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, INVOKATION, "Function invokation");}
	| postfix_expression '.' ID {$$ = new LLCCEP_SiHi::ast({$1, $3}, '.', "Member access");}
	| postfix_expression PTR_ACS ID {$$ = new LLCCEP_SiHi::ast({$1, $3}, PTR_ACS, "Member access by pointer");}
	| postfix_expression OP_INC {$$ = new LLCCEP_SiHi::ast({$1}, OP_INC, "Postfix increment");}
	| postfix_expression OP_DEC {$$ = new LLCCEP_SiHi::ast({$1}, OP_DEC, "Postfix decrement");};

argument_expression_list: 
	assignment_expression {$$ = $1;}
	| argument_expression_list ',' assignment_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARGUMENT_EXPRESSION_LIST, "Argument expression list");};

unary_expression:
	postfix_expression {$$ = $1;}
	| OP_INC unary_expression {$$ = new LLCCEP_SiHi::ast({$2}, OP_INC, "Prefix increment");}
	| OP_DEC unary_expression {$$ = new LLCCEP_SiHi::ast({$2}, OP_DEC, "Prefix decrement");}
	| unary_operator cast_expression {$$ = $1; $$->insert_child($2);};

unary_operator:
	'&' {$$ = new LLCCEP_SiHi::ast({}, '&', "Address reciever");}
	| '*' {$$ = new LLCCEP_SiHi::ast({}, '*', "Pointer dereferencer");}
	| '+' {$$ = new LLCCEP_SiHi::ast({}, '+', "Unary +");}
	| '-' {$$ = new LLCCEP_SiHi::ast({}, '-', "Unary -");}
	| '~' {$$ = new LLCCEP_SiHi::ast({}, '~', "Bitwise not");}
	| '!' {$$ = new LLCCEP_SiHi::ast({}, '!', "Boolean negative");};

cast_expression:
	unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression {$$ = new LLCCEP_SiHi::ast({$2, $4}, CAST_EXPRESSION, "Cast reinterpreting");}
	| type_name '(' cast_expression ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, CAST_EXPRESSION, "Cast reinterpreting");};

multiplicative_expression: 
	cast_expression {$$ = $1;}
	| multiplicative_expression '*' cast_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, MULTIPLICATION, "*");}
	| multiplicative_expression '/' cast_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, DIVISION, "/");}
	| multiplicative_expression '%' cast_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, MODULO, "%");};

additive_expression: 
	multiplicative_expression {$$ = $1;}
	| additive_expression '+' multiplicative_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, ADDITION, "+");}
	| additive_expression '-' multiplicative_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, SEGMENTATION, "-");};

shift_expression: 
	additive_expression {$$ = $1;}
	| shift_expression OP_OFFSET_L additive_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_OFFSET_L, "<<");}
	| shift_expression OP_OFFSET_R additive_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_OFFSET_R, ">>");}; 

relational_expression: 
	shift_expression {$$ = $1;}
	| relational_expression '<' shift_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '<', "<");}
	| relational_expression '>' shift_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '>', ">");}
	| relational_expression OP_CMP_LE shift_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_CMP_LE, "<=");}
	| relational_expression OP_CMP_AE shift_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_CMP_AE, ">=");};

equality_expression: 
	relational_expression {$$ = $1;}
	| equality_expression OP_CMP_EQ relational_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_CMP_EQ, "==");}
	| equality_expression OP_CMP_NE relational_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_CMP_NE, "!=");};

and_expression: 
	equality_expression {$$ = $1;}
	| and_expression '&' equality_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, BITWISE_AND, "&");};

exclusive_or_expression:
	and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '^', "^");};

inclusive_or_expression: 
	exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, BITWISE_OR, "|");};

logical_and_expression: 
	inclusive_or_expression {$$ = $1;}
	| logical_and_expression OP_LOGIC_AND inclusive_or_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_LOGIC_AND, "&&");};

logical_or_expression: 
	logical_and_expression {$$ = $1;}
	| logical_or_expression OP_LOGIC_OR logical_and_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, OP_LOGIC_OR, "||");};

conditional_expression: 
	logical_or_expression {$$ = $1;}
	| logical_or_expression '?' expression ':' conditional_expression {$$ = new LLCCEP_SiHi::ast({$1, $2, $3}, IF_ELSE, "if-else");};

assignment_expression: 
	conditional_expression {$$ = $1;}
	| unary_expression assignment_operator assignment_expression {$$ = $2; delete $2; $$->insert_child($1); $$->insert_child($3);};

assignment_operator: 
	'=' {$$ = new LLCCEP_SiHi::ast({}, '=', "=");}
	| OP_MUL_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_MUL_EQ, "*=");}
	| OP_DIV_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_DIV_EQ, "/=");}
	| OP_MOD_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_MOD_EQ, "%=");}
	| OP_ADD_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_ADD_EQ, "+=");}
	| OP_SUB_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_SUB_EQ, "-=");}
	| OP_OFFSET_L_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_OFFSET_L_EQ, "<<=");}
	| OP_OFFSET_R_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_OFFSET_R_EQ, ">>=");}
	| OP_AND_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_AND_EQ, "&=");}
	| OP_XOR_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_XOR_EQ, "^=");}
	| OP_OR_EQ {$$ = new LLCCEP_SiHi::ast({}, OP_OR_EQ, "|=");};

expression: 
	assignment_expression
	| expression ',' assignment_expression;

constant_expression: 
	conditional_expression;

declaration: 
	declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';';

declaration_specifiers: 
	storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers;

init_declarator_list: 
	init_declarator
	| init_declarator_list ',' init_declarator;

init_declarator: 
	declarator
	| declarator '=' initializer;

storage_class_specifier: 
	TYPEDEF
	| EXTERN
	| STATIC
	| AUTO;

type_specifier: 
	VOID
	| REAL
	| BOOL
	| struct_or_union_specifier
	| enum_specifier;

struct_or_union_specifier: 
	struct_or_union ID '{' struct_declaration_list '}'
???MANY LINES MISSING
	| declaration;

function_definition: 
	declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement;
%%

int yyerror(char const *str)
{
	fprintf(stderr, "%s:%d:%d: %s:\n"
	                "%s\n", "here should be path", yylineno, pos_x, str, yytext);

	return 0;
}

int main()
{
	yyin = stdin;

	yyparse();

	return 0;
}
