%{
#include <stdio.h>
#include <stdlib.h>

#include "ast/ast.hpp"
#include "ast/node_types.hpp"

#define YY_(str) ((char const *)str)

int yylex();
int yyerror(char const *str);

int pos_x;
%}

%union {
	LLCCEP_SiHi::ast *ast;
	char *str;
}

%token <str> VAL ID LITERAL 

%token <str> SWITCH CASE DEFAULT WHILE DO FOR CONTINUE BREAK
%token <str> IF ELSE
%token <str> GOTO RETURN

%token <str> OP_CMP_LE OP_CMP_AE OP_CMP_EQ OP_CMP_NE

%token <str> OP_INC OP_DEC

%token <str> OP_OFFSET_L OP_OFFSET_R

%token <str> OP_OFFSET_L_EQ OP_OFFSET_R_EQ
%token <str> OP_ADD_EQ OP_SUB_EQ OP_MUL_EQ OP_DIV_EQ OP_MOD_EQ
%token <str> OP_AND_EQ OP_OR_EQ OP_XOR_EQ

%token <str> TYPEDEF EXTERN STATIC AUTO
%token <str> STRUCT UNION ENUM

%token <str> MANY_DOTS

%token <str> PTR_ACS

%token <str> VOID REAL BOOL
%token <str> OP_LOGIC_AND OP_LOGIC_OR

%start main_parsing_unit

%type <ast> primary_expression postfix_expression argument_expression_list
%type <ast> unary_expression unary_operator cast_expression multiplicative_expression
%type <ast> additive_expression shift_expression relational_expression
%type <ast> equality_expression and_expression exclusive_or_expression
%type <ast> inclusive_or_expression logical_and_expression logical_or_expression
%type <ast> conditional_expression assignment_expression assignment_operator
%type <ast> expression constant_expression declaration
%type <ast> declaration_specifiers init_declarator_list
%type <ast> init_declarator storage_class_specifier type_specifier
%type <ast> struct_or_union_specifier struct_or_union struct_declaration_list
%type <ast> struct_declaration specifier_list struct_declarator_list
%type <ast> struct_declarator enum_specifier enumerator_list enumerator
%type <ast> declarator direct_declarator pointer parameter_type_list
%type <ast> parameter_list parameter_declaration identifier_list
%type <ast> type_name abstract_declarator direct_abstract_declarator
%type <ast> initializer initializer_list statement labeled_statement
%type <ast> expression_statement selection_statement iteration_statement compound_statement
%type <ast> jump_statement main_parsing_unit  external_declaration function_definition
%type <ast> declaration_list statement_list

%%
primary_expression: 
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, $<str>1);}
	| VAL {$$ = new LLCCEP_SiHi::ast({}, VAL, $<str>1);}
	| LITERAL {$$ = new LLCCEP_SiHi::ast({}, LITERAL, $<str>1);}
	| '(' expression ')' {$$ = $<ast>2;};

postfix_expression: 
	primary_expression {$$ = $<ast>1;}
	| postfix_expression '[' expression ']' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ARRAY_ACCESS, "[]");}
	| postfix_expression '(' ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1}, INVOKATION, "Invokation");}
	| postfix_expression '(' argument_expression_list ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, INVOKATION, "Invokation");}
	| postfix_expression '.' ID {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '.', ".");}
	| postfix_expression PTR_ACS ID {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, PTR_ACS, "->");}
	| postfix_expression OP_INC {$$ = new LLCCEP_SiHi::ast({$<ast>1}, OP_INC, "++");}
	| postfix_expression OP_DEC {$$ = new LLCCEP_SiHi::ast({$<ast>1}, OP_DEC, "++");};

argument_expression_list: 
	assignment_expression {$$ = $<ast>1;}
	| argument_expression_list ',' assignment_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ARGUMENT_EXPRESSION_LIST, "Argument expression list");};

unary_expression:
	postfix_expression {$$ = $<ast>1;}
	| OP_INC unary_expression {$$ = new LLCCEP_SiHi::ast({$<ast>2}, OP_INC, "++");}
	| OP_DEC unary_expression {$$ = new LLCCEP_SiHi::ast({$<ast>2}, OP_DEC, "--");}
	| unary_operator cast_expression {$$ = $<ast>1; $$->insert_child($<ast>2);};

unary_operator:
	'&' {$$ = new LLCCEP_SiHi::ast({}, '&', "Unary &(address reviever)");}
	| '*' {$$ = new LLCCEP_SiHi::ast({}, '*', "Unary *(poiner dereferencer)");}
	| '+' {$$ = new LLCCEP_SiHi::ast({}, '+', "Unary +");}
	| '-' {$$ = new LLCCEP_SiHi::ast({}, '-', "Unary -");}
	| '~' {$$ = new LLCCEP_SiHi::ast({}, '~', "~");}
	| '!' {$$ = new LLCCEP_SiHi::ast({}, '!', "!");};

cast_expression:
	unary_expression {$$ = $<ast>1;}
	| '(' type_name ')' cast_expression {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4}, CAST_EXPRESSION, "Reinterpreting cast");}
	| type_name '(' cast_expression ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, CAST_EXPRESSION, "Reinterpreting cast");};

multiplicative_expression: 
	cast_expression {$$ = $<ast>1;}
	| multiplicative_expression '*' cast_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, MULTIPLICATION, "*");}
	| multiplicative_expression '/' cast_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, DIVISION, "/");}
	| multiplicative_expression '%' cast_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, MODULO, "%");};

additive_expression: 
	multiplicative_expression {$$ = $<ast>1;}
	| additive_expression '+' multiplicative_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ADDITION, "+");}
	| additive_expression '-' multiplicative_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, SEGMENTATION, "-");};

shift_expression: 
	additive_expression {$$ = $<ast>1;}
	| shift_expression OP_OFFSET_L additive_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_OFFSET_L, "<<");}
	| shift_expression OP_OFFSET_R additive_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_OFFSET_R, ">>");}; 

relational_expression: 
	shift_expression {$$ = $<ast>1;}
	| relational_expression '<' shift_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '<', "<");}
	| relational_expression '>' shift_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '>', ">");}
	| relational_expression OP_CMP_LE shift_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_CMP_LE, "<=");}
	| relational_expression OP_CMP_AE shift_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_CMP_AE, ">=");};

equality_expression: 
	relational_expression {$$ = $<ast>1;}
	| equality_expression OP_CMP_EQ relational_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_CMP_EQ, "==");}
	| equality_expression OP_CMP_NE relational_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_CMP_NE, "!=");};

and_expression: 
	equality_expression {$$ = $<ast>1;}
	| and_expression '&' equality_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '&', "&");};

exclusive_or_expression:
	and_expression {$$ = $<ast>1;}
	| exclusive_or_expression '^' and_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '^', "^");};

inclusive_or_expression: 
	exclusive_or_expression {$$ = $<ast>1;}
	| inclusive_or_expression '|' exclusive_or_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '|', "|");};

logical_and_expression: 
	inclusive_or_expression {$$ = $<ast>1;}
	| logical_and_expression OP_LOGIC_AND inclusive_or_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_LOGIC_AND, "&&");};

logical_or_expression: 
	logical_and_expression {$$ = $<ast>1;}
	| logical_or_expression OP_LOGIC_OR logical_and_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, OP_LOGIC_OR, "||");};

conditional_expression: 
	logical_or_expression {$$ = $<ast>1;}
	| logical_or_expression '?' expression ':' conditional_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3}, IF_ELSE, "if-else");};

assignment_expression: 
	conditional_expression {$$ = $<ast>1;}
	| unary_expression assignment_operator assignment_expression {$$ = $<ast>2; $$->insert_child($<ast>1); $$->insert_child($<ast>3);};

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
	assignment_expression {$$ = $<ast>1;}
	| expression ',' assignment_expression {$$ = $<ast>1; $$->insert_child($<ast>3);};

constant_expression:
	conditional_expression {$$ = $<ast>1;};

declaration: 
	declaration_specifiers ';' {$$ = $<ast>1;}
	| declaration_specifiers init_declarator_list ';' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, DECLARATION, "declaration");};

declaration_specifiers: 
	storage_class_specifier {$$ = $<ast>1;}
	| storage_class_specifier declaration_specifiers {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, DECL_SPEC, "declaration specifiers");}
	| type_specifier {$$ = $<ast>1;}
	| type_specifier declaration_specifiers {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, DECL_SPEC, "declaration specifiers");};

init_declarator_list: 
	init_declarator {$$ = $<ast>1;}
	| init_declarator_list ',' init_declarator {$$ = $<ast>1; $$->insert_child($<ast>3);};

init_declarator: 
	declarator {$$ = $<ast>1;}
	| declarator '=' initializer {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, '=', "=");};

storage_class_specifier: 
	TYPEDEF {$$ = new LLCCEP_SiHi::ast({}, TYPEDEF, "typedef");}
	| EXTERN {$$ = new LLCCEP_SiHi::ast({}, EXTERN, "extern");}
	| STATIC {$$ = new LLCCEP_SiHi::ast({}, STATIC, "static");}
	| AUTO {$$ = new LLCCEP_SiHi::ast({}, AUTO, "auto");};

type_specifier:
	VOID {$$ = new LLCCEP_SiHi::ast({}, VOID, "void");}
	| REAL {$$ = new LLCCEP_SiHi::ast({}, REAL, "real");}
	| BOOL {$$ = new LLCCEP_SiHi::ast({}, BOOL, "bool");}
	| struct_or_union_specifier {$$ = $<ast>1;}
	| enum_specifier {$$ = $<ast>1;};

struct_or_union_specifier: 
	struct_or_union ID '{' struct_declaration_list '}' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>4}, STRUCT_UNION_SPEC, "Struct or union");}
	| struct_or_union '{' struct_declaration_list '}' {$$ = new LLCCEP_SiHi::ast({$<ast>1,  $<ast>3}, STRUCT_UNION_ANON_SPEC, "Anonymous struct or union");}
	| struct_or_union ID {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, STRUCT_UNION_PRE_DEF, "Struct or union pre-def");};

struct_or_union:
	STRUCT {$$ = new LLCCEP_SiHi::ast({}, STRUCT, "struct");}
	| UNION {$$ = new LLCCEP_SiHi::ast({}, UNION, "union");};

struct_declaration_list: 
	struct_declaration {$$ = $<ast>1;}
	| struct_declaration_list struct_declaration {$$ = $<ast>1; $$->insert_child($<ast>2);};

struct_declaration: 
	specifier_list struct_declarator_list ';' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, STRUCT_DECL,"Struct declaration");};

specifier_list: 
	type_specifier specifier_list {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, SPECIFIER_LIST, "Specifier list");}
	| type_specifier {$$ = $<ast>1;};

struct_declarator_list: 
	struct_declarator {$$ = $<ast>1;}
	| struct_declarator_list ',' struct_declarator {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, STRUCT_DECL_LIST, "Struct declarator list");};

struct_declarator:
	declarator {$$ = $<ast>1;}
	| ':' constant_expression {$$ = $<ast>2; /* ought to be debugged*/}
	| declarator ':' constant_expression {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, STRUCT_DECLARATOR, "struct declarator");};

enum_specifier: 
	ENUM '{' enumerator_list '}' {$$ = new LLCCEP_SiHi::ast({$<ast>3}, ENUM, "Anonynous enumeration");}
	| ENUM ID '{' enumerator_list '}' {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3}, ENUM, "Named enumeration");}
	| ENUM ID {$$ = new LLCCEP_SiHi::ast({$<ast>2}, ENUM, "Empty enumeration");};

enumerator_list:
	enumerator {$$ = $<ast>1;}
	| enumerator_list ',' enumerator {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ENUMERATOR_LIST, "Enumerator list");};

enumerator:
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, $<str>1);}
	| ID '=' constant_expression {$$ = new LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, ID, $<str>1), $<ast>3}, '=', "Numbered enumerator");};

declarator: 
	pointer direct_declarator {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, DECLARATOR, "Ptr declarator");}
	| direct_declarator {$$ = $<ast>1;};

direct_declarator:
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| '(' declarator ')' {$$ = $<ast>2;}
	| direct_declarator '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ARRAY_DECL, "Array declaration");}
	| direct_declarator '[' ']' {$$ = new LLCCEP_SiHi::ast({$<ast>1}, ARRAY_DECL, "Array declaration");}
	| direct_declarator '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, FUNC_DECL, "Function declaration");}
	| direct_declarator '(' identifier_list ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, FUNC_INVOKE, "Function invokation");}
	| direct_declarator '(' ')';

pointer: 
	'*' {$$ = new LLCCEP_SiHi::ast({}, PTR, "Pointer");}
	| '*' pointer {$$ = new LLCCEP_SiHi::ast({$<ast>2}, PTR, "Pointer");};

parameter_type_list: 
	parameter_list {$$ = $<ast>1;}
	| parameter_list ',' MANY_DOTS {$$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, MANY_DOTS, "va_list")}, PARAMETER_VAR_LIST, "Parameters var list");};

parameter_list: 
	parameter_declaration {$$ = $<ast>1;}
	| parameter_list ',' parameter_declaration {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, PARAM_LIST, "Parameter list");};

parameter_declaration: 
	declaration_specifiers declarator {}
	| declaration_specifiers abstract_declarator
	| declaration_specifiers;

identifier_list: 
	ID {$$ = new LLCCEP_SiHi::ast({}, ID, yytext);}
	| identifier_list ',' ID {$$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, ID, yytext)}, ID_LIST, "Identifier list");/* see it later */}; 

type_name: 
	specifier_list {$$ = $<ast>1;}
	| specifier_list abstract_declarator {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, TYPENAME, "Type name");};

abstract_declarator:
	pointer {$$ = $<ast>1;}
	| direct_abstract_declarator {$$ = $<ast>1;}
	| pointer direct_abstract_declarator {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, ABSTRACT_DECL, "Abstract declarator");};

direct_abstract_declarator: 
	'(' abstract_declarator ')' {$$ = $<ast>2;}
	| '[' ']' {$$ = new LLCCEP_SiHi::ast({}, ARR_BRACES, "Array braces");}
	| '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$<ast>2}, ARR_BRACES, "Array braces");}
	| direct_abstract_declarator '[' ']' {$$ = new LLCCEP_SiHi::ast({$<ast>1}, ARRAY, "Array");}
	| direct_abstract_declarator '[' constant_expression ']' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, ARRAY, "array");}
	| '(' ')' {$$ = new LLCCEP_SiHi::ast({}, RND_BRACES, "Round braces");}
	| '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$<ast>2}, RESULT_UNIFICATION, "Unification");}
	| direct_abstract_declarator '(' ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1}, FUNCTION_DECL, "Function");}
	| direct_abstract_declarator '(' parameter_type_list ')' {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, FUNCTION_DECL, "Function");};

initializer: 
	assignment_expression {$$ = $<ast>1;}
	| '{' initializer_list '}' {$$ = $<ast>2;};

initializer_list: 
	initializer {$$ = $<ast>1;}
	| initializer_list ',' initializer {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, INITIALIZER_LIST, "Initializer list");};

statement: 
	labeled_statement {$$ = $<ast>1;}
	| compound_statement {$$ = $<ast>1;}
	| expression_statement {$$ = $<ast>1;}
	| selection_statement {$$ = $<ast>1;}
	| iteration_statement {$$ = $<ast>1;}
	| jump_statement {$$ = $<ast>1;};

labeled_statement: 
	ID ':' statement {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3}, LABELED_STATEMENT, "Marked statement");}
	| CASE constant_expression ':' statement {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4}, CASE, "Case statement");}
	| DEFAULT ':' statement {$$ = new LLCCEP_SiHi::ast({$<ast>3}, DEFAULT, "Default statement");};

compound_statement: 
	'{' '}' {$$ = nullptr;}
	| '{' declaration_list '}' {$$ = $<ast>2;}
	| '{' declaration_list statement_list '}' {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3}, DECL_STMT_LIST, "compound statement");}
	| '{' statement_list '}' {$$ = $<ast>2;};

declaration_list: 
	declaration {$$ = $<ast>1;}
	| declaration_list declaration {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, DECL_LIST, "Declaration list");};

statement_list: 
	statement {$$ = $<ast>1;}
	| statement_list statement {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, STMT_LIST, "Statement list");};

expression_statement:
	';' {$$ = nullptr;}
	| expression ';' {$$ = $<ast>1;};

selection_statement: 
	IF '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$<ast>3, $<ast>5}, IF_ELSE, "If-else");}
	| IF '(' expression ')' statement ELSE statement {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4, $<ast>6}, IF_ELSE, "If-else");}
	| SWITCH '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$<ast>3, $<ast>5}, SWITCH, "Switch");};

iteration_statement: 
	WHILE '(' expression ')' statement {$$ = new LLCCEP_SiHi::ast({$<ast>3, $<ast>5}, WHILE, "While");}
	| DO statement WHILE '(' expression ')' ';' {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>5}, DO_WHILE, "do while");}
	| FOR '(' expression_statement expression_statement ')' statement {$$ = new LLCCEP_SiHi::ast({$<ast>3, $<ast>4, $<ast>6}, FOR, "for");}
	| FOR '(' expression_statement expression_statement expression ')' statement {$$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3, $<ast>4, $<ast>6}, FOR, "for");};

jump_statement: 
	GOTO ID ';' {$$ = new LLCCEP_SiHi::ast({$<ast>2}, GOTO, "Goto");}
	| CONTINUE ';' {$$ = new LLCCEP_SiHi::ast({}, CONTINUE, "continue");}
	| BREAK ';' {$$ = new LLCCEP_SiHi::ast({}, BREAK, "break");}
	| RETURN ';' {$$ = new LLCCEP_SiHi::ast({}, RETURN, "return");}
	| RETURN expression ';' {$$ = new LLCCEP_SiHi::ast({$<ast>2}, RETURN, "return");};

main_parsing_unit: 
	external_declaration {$$ = $<ast>1;}
	| main_parsing_unit external_declaration {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, MAIN, "Main");}
	| {yyerror("syntax error");};

external_declaration:
	function_definition {$$ = $<ast>1;}
	| declaration {$$ = $<ast>1;};

function_definition: 
	declaration_specifiers declarator declaration_list compound_statement {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3, $<ast>4}, FUNCTION_DEFINITION, "Function definition");}
	| declaration_specifiers declarator compound_statement {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3}, FUNCTION_DEFINITION, "Function definition");}
	| declarator declaration_list compound_statement {$$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3}, FUNCTION_DEFINITION, "Function definition");}
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
