%{ 
#include "ast/ast.hpp"
%}

%union {
	LLCCEP_SiHi::ast tree;
	const char *string;
}

%%
program: declaration_list;

declaration_list: declaration
                | declaration_list declaration;

declaration: function_declaration
           | class_declaration
           | variable_declaration
           | enum_declaration;

function_declaration: function_prototype function_body;

function_prototype: function_prototype_name function_prototype_arguments function_type;

function_prototype_name: FUNCTION ID;

function_prototype_arguments:
                            | '('  function_prototype_arguments_list ')';

function_prototype_arguments_list: 
                                 | function_prototype_argument
                                 | function_prototype_arguments_list ',' function_prototype_argument;

function_prototype_argument: VAR ID ':' data_type;

function_type: ARROW data_type;

function_body: compound_statement;

data_type: REAL
         | EMPTY
         | ID;

compound_statement: '{' statements_list '}';

statements_list: statement
               | statements_list statement;

statement: expression
         | invokation_statement
         | branched_statement
         | cased_statement
         | jump_statement
         | label_statement;

expression: ';' 
          | math_expression
          | boolean_expression
          | assignment_expression
          | '(' expression ')';

math_expression: top_level_math_expression;

top_level_math_expression: low_level_math_expression
                         | top_level_math_expression top_level_math_operator top_level_math_expression;

top_level_math_operator: '+'
                       | '-';

low_level_math_expression: lower_level_math_expression
                         | low_level_math_expression low_level_math_operator low_level_math_expression;

low_level_math_operator: '*'
                       | '/'
                       | '%';

lower_level_math_expression: expression
                           | lower_level_math_expression EXP lower_level_math_expression;

boolean_expression: top_level_boolean_expression;

top_level_boolean_expression: low_level_boolean_expression
                            | top_level_boolean_expression '&' top_level_boolean_expression;

low_level_boolean_expression: lower_level_boolean_expression
                            | low_level_boolean_expression '|' low_level_boolean_expression;

lower_level_boolean_expression: expression
                              | lower_level_boolean_expression '^' lower_level_boolean_expression;
%%
