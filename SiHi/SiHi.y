%{
#include <stdio.h>
#include <stdlib.h>
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

%start main_parsing_unit

%%
PRIME: 
	ID
	| VAL
     	| LITERAL
     	| '(' EXPR ')';

POSTFIX_EXPR: 
	PRIME
	| POSTFIX_EXPR OP_INC
	| POSTFIX_EXPR OP_DEC
	| POSTFIX_EXPR '(' ')'
	| POSTFIX_EXPR '(' ARGS_LIST ')'
	| POSTFIX_EXPR PTR_ACS ID;

UNARY_EXPR: 
	POSTFIX_EXPR
	| OP_INC UNARY_EXPR
	| OP_DEC UNARY_EXPR
	| UNARY_OP REINTERPRET_EXPR;

REINTERPRET_EXPR: 
	TYPE_NAME '(' REINTERPRET_EXPR ')'
	| '(' TYPE_NAME ')' REINTERPRET_EXPR
	| UNARY_EXPR;

TOP_LEVEL_EXPR: 
	REINTERPRET_EXPR
	| TOP_LEVEL_EXPR '*' REINTERPRET_EXPR
	| TOP_LEVEL_EXPR '/' REINTERPRET_EXPR
	| TO_LEVEL_EXPR '%' REINTERPRET_EXPR;

LOW_LEVEL_EXPR: 
	TOP_LEVEL_EXPR
	| LOW_LEVEL_EXPR '+' TOP_LEVEL_EXPR
	| LOW_LEVEL_EXPR '-' TOP_LEVEL_EXPR;

OFFSET_EXPR: 
	LOW_LEVEL_EXPR /* Zero offset */
	| OFFSET_EXPR OP_OFFSET_L LOW_LEVEL_EXPR
	| OFFSET_EXPR OP_OFFSET_R LOW_LEVEL_EXPR;

COMPARISION_EXPR: 
	OFFSET_EXPR /*to_unsigned > 0*/
	| COMPARISION_EXPR '>' OFFSET_EXPR
	| COMPARISION_EXPR '<' OFFSET_EXPR
	| COMPARISION_EXPR OP_CMP_LE OFFSET_EXPR
	| COMPARISION_EXPR OP_CMP_AE OFFSET_EXPR;

EQUIVALENCY_EXPR: 
	COMPARISION_EXPR
	| EQUIVALENCY_EXPR OP_CMP_EQ COMPARISION_EXPR
	| EQUIVALENCY_EXPR OP_CMP_NE COMPARISION_EXPR;

AND_EXPR: 
	EQUIVALENCY_EXPR
	| AND_EXPR '&' EQUIVALENCY_EXPR;

XOR_EXPR: 
	AND_EXPR
	| XOR_EXPR '^' AND_EXPR;

OR_EXPR: 
	XOR_EXPR
	| OR_EXPR '|' XOR_EXPR;

LOGIC_AND_EXPR: 
	OR_EXPR
	| LOGIC_AND_EXPR OP_LOGIC_AND OR_EXPR;

LOGIC_OR_EXPR:
	LOGIC_AND_EXPR
        | LOGIC_OR_EXPR OP_LOGIC_OR LOGIC_AND_EXPR;

COND_EXPR:
	LOGIC_OR_EXPR
	| LOGIC_OR_EXPR '?' EXPR ':' COND_EXPR;

ASSIGNMENT_EXPR:
	COND_EXPR
	| UNARY_EXPR ASSIGNMENT_OP ASSIGNMENT_EXPR;

ASSIGNMENT_OP:
	'='
	| OP_MUL_EQ
	| OP_DIV_EQ
	| OP_MOD_EQ
	| OP_ADD_EQ
	| OP_SUB_EQ
	| OP_OFFSET_L_EQ
	| OP_OFFSET_R_EQ
	| OP_AND_EQ
	| OP_XOR_EQ
	| OP_OR_EQ;

EXPR:
	ASSIGNMENT_EXPR
	| EXPR ',' ASSIGNMENT_EXPR;

CONST_EXPR:
	COND_EXPR;

DECL_EXPR:
	DECLSPEC ';'
	| DECLSPEC DECL_LIST ';';

DECLSPEC:
	STORE_CLASS
	| STORE_CLASS DECLSPEC
	| TYPESPEC
	| TYPESPEC DECLSPEC;

DECL_LIST:
	DECL_INIT
	| DECL_LIST ',' DECL_INIT;
%%
