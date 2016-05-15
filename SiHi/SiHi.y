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
	| postfix_expression '[' expression ']' {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARRAY_ACCESS, "[]");}
	| postfix_expression '(' ')' {$$ = new LLCCEP_SiHi::ast({$1}, INVOKATION, "Invokation");}
	| postfix_expression '(' argument_expression_list ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, INVOKATION, "Invokation");}
	| postfix_expression '.' ID {$$ = new LLCCEP_SiHi::ast({$1, $3}, '.', ".");}
	| postfix_expression PTR_ACS ID {$$ = new LLCCEP_SiHi::ast({$1, $3}, PTR_ACS, "->");}
	| postfix_expression OP_INC {$$ = new LLCCEP_SiHi::ast({$1}, OP_INC, "++");}
	| postfix_expression OP_DEC {$$ = new LLCCEP_SiHi::ast({$1}, OP_DEC, "++");};

argument_expression_list: 
	assignment_expression {$$ = $1;}
	| argument_expression_list ',' assignment_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARGUMENT_EXPRESSION_LIST, "Argument expression list");};

unary_expression:
	postfix_expression {$$ = $1;}
	| OP_INC unary_expression {$$ = new LLCCEP_SiHi::ast({$2}, OP_INC, "++");}
	| OP_DEC unary_expression {$$ = new LLCCEP_SiHi::ast({$2}, OP_DEC, "--");}
	| unary_operator cast_expression {$$ = $1; $$->insert_child($2);};

unary_operator:
	'&' {$$ = new LLCCEP_SiHi::ast({}, '&', "Unary &(address reviever)");}
	| '*' {$$ = new LLCCEP_SiHi::ast({}, '*', "Unary *(poiner dereferencer)");}
	| '+' {$$ = new LLCCEP_SiHi::ast({}, '+', "Unary +");}
	| '-' {$$ = new LLCCEP_SiHi::ast({}, '-', "Unary -");}
	| '~' {$$ = new LLCCEP_SiHi::ast({}, '~', "~");}
	| '!' {$$ = new LLCCEP_SiHi::ast({}, '!', "!");};

cast_expression:
	unary_expression {$$ = $1;}
	| '(' type_name ')' cast_expression {$$ = new LLCCEP_SiHi::ast({$2, $4}, CAST_EXPRESSION, "Reinterpreting cast");}
	| type_name '(' cast_expression ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, CAST_EXPRESSION, "Reinterpreting cast");};

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
	| and_expression '&' equality_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '&', "&");};

exclusive_or_expression:
	and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '^', "^");};

inclusive_or_expression: 
	exclusive_or_expression {$$ = $1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '|', "|");};

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
	assignment_expression {$$ = $1;}
	| expression ',' assignment_expression {$$ = $1; $$->insert_child($3);};

constant_expression:
	conditional_expression {$$ = $1;};

declaration: 
	declaration_specifiers ';' {$$ = $1;}
	| declaration_specifiers init_declarator_list ';' {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECLARATION, "declaration");};

declaration_specifiers: 
	storage_class_specifier {$$ = $1;}
	| storage_class_specifier declaration_specifiers {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECL_SPEC, "declaration specifiers");}
	| type_specifier {$$ = $1;}
	| type_specifier declaration_specifiers {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECL_SPEC, "declaration specifiers");};

init_declarator_list: 
	init_declarator {$$ = $1;}
	| init_declarator_list ',' init_declarator {$$ = $1; $$->insert_child($3);};

init_declarator: 
	declarator {$$ = $1;}
	| declarator '=' initializer {$$ = new LLCCEP_SiHi::ast({$1, $3}, '=', "=");};

storage_class_specifier: 
	TYPEDEF {$$ = new LLCCEP_SiHi::ast({}, TYPEDEF, "typedef");}
	| EXTERN {$$ = new LLCCEP_SiHi::ast({}, EXTERN, "extern");}
	| STATIC {$$ = new LLCCEP_SiHi::ast({}, STATIC, "static");}
	| AUTO {$$ = new LLCCEP_SiHi::ast({}, AUTO, "auto");};

type_specifier:
	VOID {$$ = new LLCCEP_SiHi::ast({}, VOID, "void");}
	| REAL {$$ = new LLCCEP_SiHi::ast({}, REAL, "real");}
	| BOOL {$$ = new LLCCEP_SiHi::ast({}, BOOL, "bool");}
	| struct_or_union_specifier {$$ = $1;}
	| enum_specifier {$$ = $1;};

struct_or_union_specifier: 
	struct_or_union ID '{' struct_declaration_list '}' {$$ = new LLCCEP_SiHi::ast({$1, $2, $4}, STRUCT_UNION_SPEC, "Struct or union");}
	| struct_or_union '{' struct_declaration_list '}' {$$ = new LLCCEP_SiHi::ast({$1,  $3}, STRUCT_UNION_ANON_SPEC, "Anonymous struct or union");}
	| struct_or_union ID {$$ = new LLCCEP_SiHi::ast({$1, $2}, STRUCT_UNION_PRE_DEF, "Struct or union pre-def");};

struct_or_union:
	STRUCT {$$ = new LLCCEP_SiHi::ast({}, STRUCT, "struct");}
	| UNION {$$ = new LLCCEP_SiHi::ast({}, UNION, "union");};

struct_declaration_list: 
	struct_declaration {$$ = $1;}
	| struct_declaration_list struct_declaration {$$ = $1; $$->insert_child($2);};

struct_declaration: 
	specifier_list struct_declarator_list ';' {$$ = new LLCCEP_SiHi::ast({$1, $2}, STRUCT_DECL,"Struct declaration");};

specifier_list: 
	type_specifier specifier_list {$$ = new LLCCEP_SiHi::ast({$1, $2}, SPECIFIER_LIST, "Specifier list");}
	| type_specifier {$$ = $1;};

struct_declarator_list: 
	struct_declarator {$$ = $1;}
	| struct_declarator_list ',' struct_declarator {$$ = new LLCCEP_SiHi::ast({$1, $3}, STRUCT_DECL_LIST, "Struct declarator list");};

struct_declarator:
	declarator {$$ = $1;}
	| ':' constant_expression {$$ = $2; /* ought to be debugged*/}
	| declarator ':' constant_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, STRUCT_DECLARATOR, "struct declarator");};

enum_specifier: 
	ENUM '{' enumerator_list '}' {$$ = new LLCCEP_SiHi::ast({$3}, ENUM, "Anonynous enumeration");}
	| ENUM ID '{' enumerator_list '}' {$$ = new LLCCEP_SiHi::ast({$2, $3}, ENUM, "Named enumeration");}
	| ENUM ID {$$ = new LLCCEP_SiHi::ast({$2}, ENUM, "Empty enumeration");};

enumerator_list:
	enumerator {$$ = $1;}
	| enumerator_list ',' enumerator {$$ = new LLCCEP_SiHi::ast({$1, $3}, ENUMERATOR_LIST, "Enumerator list");};

enumerator:
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| ID '=' constant_expression {$$ = new LLCCEP_SiHi::ast({$1, $3}, '=', "Numbered enumerator");};

declarator: 
	pointer direct_declarator {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECLARATOR, "Ptr declarator");}
	| direct_declarator {$$ = $1;};

direct_declarator:
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| '(' declarator ')' {$$ = $2;}
	| direct_declarator '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARRAY_DECL, "Array declaration");}
	| direct_declarator '[' ']' {$$ = new LLCCEP_SiHi::ast({$1}, ARRAY_DECL, "Array declaration");}
	| direct_declarator '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, FUNC_DECL, "Function declaration");}
	| direct_declarator '(' identifier_list ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, FUNC_INVOKE, "Function invokation");}
	| direct_declarator '(' ')';

pointer: 
	'*' {$$ = new LLCCEP_SiHi::ast({}, PTR, "Pointer");}
	| '*' pointer {$$ = new LLCCEP_SiHi::ast({$2}, PTR, "Pointer");};

parameter_type_list: 
	parameter_list {$$ = $1;}
	| parameter_list ',' MANY_DOTS {$$ = new LLCCEP_SiHi::ast({$1, new LLCCEP_SiHi::ast({}, MANY_DOTS, "va_list")}, PARAMETER_VAR_LIST, "Parameters var list");};

parameter_list: 
	parameter_declaration {$$ = $1;}
	| parameter_list ',' parameter_declaration {$$ = new LLCCEP_SiHi::ast({$1, $3}, PARAM_LIST, "Parameter list");};

parameter_declaration: 
	declaration_specifiers declarator {}
	| declaration_specifiers abstract_declarator
	| declaration_specifiers;

identifier_list: 
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| identifier_list ',' ID {$$ = new LLCCEP_SiHi::ast({$1, new LLCCEP_SiHi::ast({}, ID, yytext)}, ID_LIST, "Identifier list");/* see it later */}; 

type_name: 
	specifier_list {$$ = $1;}
	| specifier_list abstract_declarator {$$ = new LLCCEP_SiHi::ast({$1, $2}, TYPENAME, "Type name");};

abstract_declarator:
	pointer {$$ = $1;}
	| direct_abstract_declarator {$$ = $1;}
	| pointer direct_abstract_declarator {$$ = new LLCCEP_SiHi::ast({$1, $2}, ABSTRACT_DECL, "Abstract declarator");};

direct_abstract_declarator: 
	'(' abstract_declarator ')' {$$ = $2;}
	| '[' ']' {$$ = new LLCCEP_SiHi::ast({}, ARR_BRACES, "Array braces");}
	| '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$2}, ARR_BRACES, "Array braces");}
	| direct_abstract_declarator '[' ']' {$$ = new LLCCEP_SiHi::ast({$1}, ARRAY, "Array");}
	| direct_abstract_declarator '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$1, $3}, ARRAY, "array");}
	| '(' ')' {$$ = new LLCCEP_SiHi::ast({}, RND_BRACES, "Round braces");}
	| '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$2}, RESULT_UNIFICATION, "Unification");}
	| direct_abstract_declarator '(' ')' {$$ = new LLCCEP_SiHi::ast({$1}, FUNCTION_DECL, "Function");}
	| direct_abstract_declarator '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$1, $3}, FUNCTION_DECL, "Function");};

initializer: 
	assignment_expression {$$ = $1;}
	| '{' initializer_list '}' {$$ = $2;};

initializer_list: 
	initializer {$$ = $1;}
	| initializer_list ',' initializer {$$ = new LLCCEP_SiHi::ast({$1, $3}, INITIALIZER_LIST, "Initializer list");};

statement: 
	labeled_statement {$$ = $1;}
	| compound_statement {$$ = $1;}
	| expression_statement {$$ = $1;}
	| selection_statement {$$ = $1;}
	| iteration_statement {$$ = $1;}
	| jump_statement {$$ = $1;};

labeled_statement: 
	ID ':' statement {$$ = new LLCCEP_SiHi::ast({$1, $3}, LABELED_STATEMENT, "Marked statement");}
	| CASE constant_expression ':' statement {$$ = new LLCCEP_SiHi::ast({$2, $4}, CASE, "Case statement");}
	| DEFAULT ':' statement {$$ = new LLCCEP_SiHi::ast({$3}, DEFAULT, "Default statement");};

compound_statement: 
	'{' '}' {$$ = nullptr;}
	| '{' declaration_statement_list '}' {$$ = $2;};

declaration_statement_list:
	declaration_statement {$$ = $1;}
	| declaration_statement_list declaration_statement {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECL_STMT_LIST, "Declaration statement list");};

declaration_statement:
	declaration {$$ = $1;}
	| statement {$$ = $1;};

declaration_list: 
	declaration {$$ = $1;}
	| declaration_list declaration {$$ = new LLCCEP_SiHi::ast({$1, $2}, DECL_LIST, "Declaration list");};

statement_list: 
	statement {$$ = $1;}
	| statement_list statement {$$ = new LLCCEP_SiHi::ast({$1, $2}, STMT_LIST, "Statement list");};

expression_statement:
	';' {$$ = nullptr;}
	| expression ';' {$$ = $1;};

selection_statement: 
	IF '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$3, $5}, IF_ELSE, "If-else");}
	| IF '(' expression ')' statement ELSE statement {$$ = new LLCCEP_SiHi::ast({$2, $4, $6}, IF_ELSE, "If-else");}
	| SWITCH '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$3, $5}, SWITCH, "Switch");};

iteration_statement: 
	WHILE '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$3, $5}, WHILE, "While");}
	| DO statement WHILE '(' expression ')' ';' {$$ = new LLCCEP_SiHi::ast({$2, $5}, DO_WHILE, "do while");}
	| FOR '(' expression_statement expression_statement ')' statement {$$ = new LLCCEP_SiHi::ast({$3, $4, $6}, FOR, "for");}
	| FOR '(' expression_statement expression_statement expression ')' statement {$$ = new LLCCEP_SiHi::ast({$2, $3, $4, $6}, FOR, "for");};

jump_statement: 
	GOTO ID ';' {$$ = new LLCCEP_SiHi::ast({$2}, GOTO, "Goto");}
	| CONTINUE ';' {$$ = new LLCCEP_SiHi::ast({}, CONTINUE, "continue");}
	| BREAK ';' {$$ = new LLCCEP_SiHi::ast({}, BREAK, "break");}
	| RETURN ';' {$$ = new LLCCEP_SiHi::ast({}, RETURN, "return");}
	| RETURN expression ';' {$$ = new LLCCEP_SiHi::ast({$2}, RETURN, "return");};

main_parsing_unit: 
	external_declaration {$$ = $1;}
	| main_parsing_unit external_declaration {$$ = new LLCCEP_SiHi::ast({$1, $2}, MAIN, "Main");}
	| {yyerror("syntax error");};

external_declaration:
	function_definition {$$ = $1;}
	| declaration {$$ = $1;};

function_definition: 
	declaration_specifiers declarator declaration_list compound_statement {$$ = new LLCCEP_SiHi::ast({$1, $2, $3, $4}, FUNCTION_DEFINITION, "Function definition");}
	| declaration_specifiers declarator compound_statement {$$ = new LLCCEP_SiHi::ast({$1, $2, $3}, FUNCTION_DEFINITION, "Function definition");}
	| declarator declaration_list compound_statement {$$ = new LLCCEP_SiHi::ast({$1, $2, $3}, FUNCTION_DEFINITION, "Function definition");}
	| declarator compound_statement {$$ = new LLCCEP_SiHi::ast({$1, $2}, FUNCTION_DEFINITION, "Function definition");};
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
