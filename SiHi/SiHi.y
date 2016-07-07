%union {

}

%%
program: declarations_list;

declarations_list: declaration
                 | declarations_list declaration;

declaration: function_declaration
           | class_declaration
           | enum_declaration
           | variable_declaration;

function_declaration: function_prototype compound_statement;

function_prototype: FUNCTION ID function_prototype_arguments_list function_return_type;

function_prototype_arguments_list: function_prototype_argument
                                 | function_prototype_arguments_list function_prototype_argument;

function_prototype_argument: /* None */
                           | data_type ID;

function_return_type: /* None */
                    | ARROW data_type;

compound_statement: '{' statements_list '}';

statements_list: statement
               | statements_list statement;

statement: expression
         | compound_statement
         | STOP
         | RESUME
         | declaration
         | return_statement;

expression: assignment_expression
          | invoke_expression
          | branched_expression
          | looped_expression
          | cased_expression
          | math_expression
          | '(' expression ')';

assignment_expression: rvalue
                     | lvalue assignment_operator assignment_expression;

lvalue: abstract_declarator_data expression;

abstract_declarator_data:
                        | '*'
                        | abstract_declarator_data '*';

rvalue: abstract_reference_data lvalue;

abstract_reference_data: 
                       | '&'
                       | abstract_reference_data '&';

assignment_operator: '='
                   | ADD_EQ
                   | SUB_EQ
                   | MUL_EQ
                   | DIV_EQ
                   | MOD_EQ
                   | EXP_EQ
                   | AND_EQ
                   | OR_EQ
                   | XOR_EQ
                   | SHL_EQ
                   | SHR_EQ;

invoke_expression: ID '(' function_invoke_arguments_list ')';

function_invoke_arguments_list: expression_list;

expression_list: expression
               | expression_list ',' expression;

branched_expression: IF expression statement
                   | IF expression statement ELSE statement;

looped_expression: LOOP expression ';' expression ';' expression statement
                 | LOOP expression ';' expression statement
                 | LOOP expression statement;

cased_expression: CASE expression '{' cased_expression_statements_list '}';

cased_expression_statement_list: cased_expression_statement_label_list statement STOP;

cased_expression_statement_label_list: cased_expression_statement_label
                                     | cased_expression_statement_label_list cased_expression_statement_label;

cased_expression_statement_label: expression '?';

math_expression: top_level_math_expression;

top_level_math_expression: low_level_math_expression
                         | top_level_math_expression top_level_math_operator top_level_math_expression;

low_level_math_expression: lowest_level_math_expression
                         | low_level_math_expression low_level_math_operator low_level_math_expression;

lowest_level_math_expression: expression
                            | lowest_level_math_expression EXP lowest_level_math_expression;

top_level_math_operator: '+'
                       | '-';

low_level_math_operator: '*'
                       | '/';


%%
