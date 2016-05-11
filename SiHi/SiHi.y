%{
#include <stdio.h>
#include <stdlib.h>

//#define YYSTYPE ast_node *

int yylex();
int yyerror(char *str);

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

%token VOID REAL BOOL TRUE FALSE
%token OP_LOGIC_AND OP_LOGIC_OR

%start main_parsing_unit

%%
primary_expression: 
	ID
	| VAL
	| LITERAL
	| '(' expression ')';

postfix_expression: 
	primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' ID
	| postfix_expression PTR_ACS ID
	| postfix_expression OP_INC
	| postfix_expression OP_DEC;

argument_expression_list: 
	assignment_expression
	| argument_expression_list ',' assignment_expression;

unary_expression: 
	postfix_expression
	| OP_INC unary_expression
	| OP_DEC unary_expression
	| unary_operator cast_expression;

unary_operator: 
	'&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!';

cast_expression: 
	unary_expression
	| '(' type_name ')' cast_expression
	| type_name '(' cast_expression ')';

multiplicative_expression: 
	cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression;

additive_expression: 
	multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression;

shift_expression: 
	additive_expression
	| shift_expression OP_OFFSET_L additive_expression
	| shift_expression OP_OFFSET_R additive_expression;

relational_expression: 
	shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression OP_CMP_LE shift_expression
	| relational_expression OP_CMP_AE shift_expression;

equality_expression: 
	relational_expression
	| equality_expression OP_CMP_EQ relational_expression
	| equality_expression OP_CMP_NE relational_expression;

and_expression: 
	equality_expression
	| and_expression '&' equality_expression;

exclusive_or_expression: 
	and_expression
	| exclusive_or_expression '^' and_expression;

inclusive_or_expression: 
	exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression;

logical_and_expression: 
	inclusive_or_expression
	| logical_and_expression OP_LOGIC_AND inclusive_or_expression;

logical_or_expression: 
	logical_and_expression
	| logical_or_expression OP_LOGIC_OR logical_and_expression;

conditional_expression: 
	logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression;

assignment_expression: 
	conditional_expression
	| unary_expression assignment_operator assignment_expression;

assignment_operator: 
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
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union ID;

struct_or_union: 
	STRUCT
	| UNION;

struct_declaration_list: 
	struct_declaration
	| struct_declaration_list struct_declaration;

struct_declaration: 
	specifier_list struct_declarator_list ';';

specifier_list: 
	type_specifier specifier_list
	| type_specifier;

struct_declarator_list: 
	struct_declarator
	| struct_declarator_list ',' struct_declarator;

struct_declarator: 
	declarator
	| ':' constant_expression
	| declarator ':' constant_expression;

enum_specifier: 
	ENUM '{' enumerator_list '}'
	| ENUM ID '{' enumerator_list '}'
	| ENUM ID;

enumerator_list:
	enumerator
	| enumerator_list ',' enumerator;

enumerator: 
	ID
	| ID '=' constant_expression;

declarator: 
	pointer direct_declarator
	| direct_declarator;

direct_declarator: 
	ID
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')';

pointer
	: '*'
	| '*' pointer;

parameter_type_list: 
	parameter_list
	| parameter_list ',' MANY_DOTS;

parameter_list: 
	parameter_declaration
	| parameter_list ',' parameter_declaration;

parameter_declaration: 
	declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers;

identifier_list: 
	ID
	| identifier_list ',' ID;

type_name: 
	specifier_list
	| specifier_list abstract_declarator;

abstract_declarator: 
	pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator;

direct_abstract_declarator: 
	'(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')';

initializer: 
	assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}';

initializer_list: 
	initializer
	| initializer_list ',' initializer;

statement: 
	labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement;

labeled_statement: 
	ID ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement;

compound_statement: 
	'{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}';

declaration_list: 
	declaration
	| declaration_list declaration;

statement_list: 
	statement
	| statement_list statement;

expression_statement: 
	';'
	| expression ';';

selection_statement: 
	IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement;

iteration_statement: 
	WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement;

jump_statement: 
	GOTO ID ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';';

main_parsing_unit: 
	external_declaration
	| main_parsing_unit external_declaration;

external_declaration: 
	function_definition
	| declaration;

function_definition: 
	declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement;
%%

int yyerror(char *str)
{
	fprintf(stderr, "%s:%d:%d: %s:\n"
	                "%s\n", "here should be path", yylineno, pos_x, str, yytext);

	return 0;
}
