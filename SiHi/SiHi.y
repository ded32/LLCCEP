%{
#include "ast/ast.hpp"
%}

%union {
	LLCCEP_SiHi::ast tree;
	const char *string;
}

%token <string> ID NUMBER LITERAL ARROW INCREMENT DECREMENT
%token <string> NOT REINTERPRET_CAST SHL SHR LESS_EQUAL ABOVE_EQUAL
%token <string> EQUALS NOT_EQUALS MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <string> ADD_ASSIGN SUB_ASSIGN SHL_ASSIGN SHR_ASSIGN AND_ASSIGN
%token <string> XOR_ASSIGN OR_ASSIGN EMPTY REAL STRING OTHER PASS
%token <string> IF ELSE CASE LOOP JUMP NEXT STOP RETURN FUNCTION ARROW

%type 

%%
primary_expression: ID {
                            $$ = new LLCCEP_SiHi::ast({}, 
                                                      "Identifier: " + $<string>1,
                                                      ID);
                    } | NUMBER {
                            $$ = new LLCCEP_SiHi::ast({},
                                                      "Number: " + $<string>1,
                                                      NUMBER);
                    } | LITERAL {
                            $$ = new LLCCEP_SiHi::ast({},
                                                      "Literal: " + $<string>1,
                                                      LITERAL);
                    } | '(' expression ')' {
                            $$ = $<ast>2;
                    };

postfix_expression: primary_expression {
                            $$ = $<ast>1;
	            } | postfix_expression '[' expression ']' {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      "[]",
                                                      ACCESS_ARRAY_MEMBER);
                    } | postfix_expression '(' ')' {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                      "()",
                                                      INVOKE);
		    } | postfix_expression '(' argument_expression_list ')' {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      "()",
                                                      INVOKE);
                    } | postfix_expression '.' ID {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "Identifier: " + $<string>3, ID)},
                                                      "."
                                                      ACCESS_MEMBER);
                    } | postfix_expression ARROW ID {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "Identifier: " + $<string>3, ID)},
                                                      "->",
                                                      ACCESS_MEMBER_BY_PTR);
                    } | postfix_expression INCREMENT {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                      "++",
                                                      INCREMENT);
                    } | postfix_expression DECREMENT {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                      "--",
                                                      DECREMENT);
                    };

argument_expression_list: assignment_expression {
                                $$ = $<ast>1; 
                        } | argument_expression_list ',' assignment_expression {
                                $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                          $<ast>1.value() + " " + $<ast>1.value(),
                                                          "Argument expression list");
                        };

unary_expression: postfix_expression {
                        $$ = $<ast>1;
                } | INCREMENT unary_expression {

                } | DECREMENT unary_expression {
	        } | unary_operator cast_expression;

unary_operator: '&'
	      | '@'
	      | '+'
	      | '-'
	      | '~'
	      | NOT;

cast_expression: unary_expression
	       | REINTERPRET_CAST '<' type_name '>' '(' cast_expression ')';

multiplicative_expression: cast_expression
 	                 | multiplicative_expression multiplicative_operator cast_expression;

multiplicative_operator: '*'
                       | '/'
                       | '%';

additive_expression: multiplicative_expression
	           | additive_expression additive_operator multiplicative_expression;

additive_operator: '+'
                 | '-';

shift_expression: additive_expression
	        | shift_expression shift_operator additive_expression;

shift_operator: SHL
              | SHR;

relational_expression: shift_expression
	             | relational_expression relational_operator shift_expression;

relational_operator: '<'
                   | '>'
                   | LESS_EQUAL
                   | ABOVE_EQUAL;

equality_expression: relational_expression
	| equality_expression equilaty_operator relational_expression;

equality_operator: EQUALS
                   NOT_EQUALS;

and_expression: equality_expression
	      | and_expression '&' equality_expression;

exclusive_or_expression: and_expression
  	               | exclusive_or_expression '^' and_expression;

inclusive_or_expression: exclusive_or_expression
 	               | inclusive_or_expression '|' exclusive_or_expression;

conditional_expression: inclusive_or_expression
	              | logical_or_expression DONE expression UNLESS conditional_expression;

assignment_expression: conditional_expression
	             | unary_expression assignment_operator assignment_expression;

assignment_operator: '='
	           | MUL_ASSIGN
	           | DIV_ASSIGN
	           | MOD_ASSIGN
	           | ADD_ASSIGN
	           | SUB_ASSIGN
	           | SHL_ASSIGN
	           | SHR_ASSIGN
	           | AND_ASSIGN
	           | XOR_ASSIGN
	           | OR_ASSIGN;

expression: assignment_expression
  	  | expression ',' assignment_expression;

constant_expression: conditional_expression;

declaration: declaration_specifiers
   	   | declaration_specifiers init_declarator_list;
 
declaration_specifiers: type_specifier
	              | type_specifier declaration_specifiers
	              | type_qualifier
	              | type_qualifier declaration_specifiers;

init_declarator_list: init_declarator
	            | init_declarator_list ',' init_declarator;

init_declarator: declarator
	       | declarator '=' initializer;

type_specifier: EMPTY
   	      | REAL
	      | STRING
	      | ID;

declarator: pointer direct_declarator
	  | direct_declarator;

direct_declarator: ID
 	         | '(' declarator ')'
	         | direct_declarator '[' constant_expression ']'
	         | direct_declarator '[' ']'
	         | direct_declarator '(' parameter_type_list ')'
	         | direct_declarator '(' identifier_list ')'
	         | direct_declarator '(' ')';

pointer: '*'
       | '*' pointer;


parameter_type_list: parameter_list
	           | parameter_list ',' VARARG;

parameter_list: parameter_declaration
	      | parameter_list ',' parameter_declaration;

parameter_declaration: declaration_specifiers declarator
	             | declaration_specifiers abstract_declarator
	             | declaration_specifiers;

identifier_list: ID
	       | identifier_list ',' ID;

type_name: specifier_qualifier_list
	 | specifier_qualifier_list abstract_declarator;

abstract_declarator: pointer
 	           | direct_abstract_declarator
	           | pointer direct_abstract_declarator;

direct_abstract_declarator: '(' abstract_declarator ')'
	                  | '[' ']'
	                  | '[' constant_expression ']'
 	                  | direct_abstract_declarator '[' ']'
	                  | direct_abstract_declarator '[' constant_expression ']'
 	                  | '(' ')'
	                  | '(' parameter_type_list ')'
	                  | direct_abstract_declarator '(' ')'
	                  | direct_abstract_declarator '(' parameter_type_list ')';

initializer: assignment_expression
	   | '{' initializer_list '}'
	   | '{' initializer_list ',' '}';

initializer_list: initializer
	        | initializer_list ',' initializer;

statement: labeled_statement
	 | compound_statement
	 | expression_statement
	 | selection_statement
	 | loop_statement
	 | jump_statement;

labeled_statement: ID ':' statement
  	         | constant_expression ':' statement
	         | OTHER ':' statement;

compound_statement: '{' '}'
	          | '{' statement_list '}'
	          | '{' declaration_list '}'
	          | '{' declaration_list statement_list '}';

declaration_list: declaration
	        | declaration_list declaration;

statement_list: statement
	      | statement_list statement;

expression_statement: PASS
  	            | expression;

selection_statement: IF expression statement
	           | IF expression statement ELSE statement
	           | CASE expression statement;

iteration_statement: LOOP expression statement
 	           | LOOP expression ';' expression statement
	           | LOOP expression_statement ';' expression_statement ';' expression statement;

jump_statement: JUMP ID
              | NEXT
	      | STOP
	      | RETURN
	      | RETURN expression;

translation_unit: external_declaration
	        | translation_unit external_declaration;

external_declaration: function_definition
 	            | declaration;

function_definition: function_prototype compound_statement;

function_prototype: function_name function_args function_type;

function_name: FUNCTION ID;

function_args: 
             | '(' ')'
             | '(' parameter_type_list ')';

function_type:
             | ARROW type_specifier;
%%
