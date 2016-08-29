%{
#include <string>
#include "ast/ast.hpp"

void yyerror(LLCCEP_SiHi::ast **, const char *msg);

extern ::std::string yyfilename;
extern int yylex(void);
extern int yylineno;
%}

%error-verbose

%parse-param {LLCCEP_SiHi::ast **ast}

%union {
	::LLCCEP_SiHi::ast *ast;
	const char *string;
}

%token <string> ID NUMBER LITERAL ARROW INCREMENT DECREMENT
%token <string> REINTERPRET_CAST SHL SHR LESS_EQUAL ABOVE_EQUAL
%token <string> EQUALS NOT_EQUALS MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <string> ADD_ASSIGN SUB_ASSIGN SHL_ASSIGN SHR_ASSIGN AND_ASSIGN
%token <string> XOR_ASSIGN OR_ASSIGN EMPTY REAL STRING OTHER PASS
%token <string> IF ELSE CASE WHILE DO FOR JUMP NEXT STOP RETURN
%token <string> DONE UNLESS VARARG FUNCTION

%type <ast> primary_expression postfix_expression argument_expression_list
%type <ast> unary_expression unary_operator cast_expression multiplicative_expression
%type <ast> multiplicative_operator additive_expression additive_operator
%type <ast> shift_expression shift_operator relational_expression
%type <ast> relational_operator equality_expression equality_operator and_expression
%type <ast> exclusive_or_expression inclusive_or_expression conditional_expression
%type <ast> assignment_expression assignment_operator expression constant_expression
%type <ast> declaration declaration_specifiers init_declarator_list init_declarator
%type <ast> type_specifier declarator direct_declarator pointer parameter_type_list
%type <ast> parameter_list parameter_declaration identifier_list type_name
%type <ast> abstract_declarator direct_abstract_declarator initializer initializer_list
%type <ast> statement labeled_statement compound_statement declaration_statement
%type <ast> declaration_statement_list expression_statement branched_statement
%type <ast> looped_statement jump_statement translation_unit external_declaration
%type <ast> function_definition function_signature function_name function_args function_type
%type <ast> labeled_statement_list

%start translation_unit

%left '+' '-' '*' '/' '%' '@' '&'
%%
primary_expression: ID {
                            $$ = createAst{PRIMARY_EXPRESSION_LEXEM, {createAst{createLexem{$<string>1, ID}}}};
                    } | NUMBER {
                            $$ = createAst{PRIMARY_EXPRESSION_LEXEM, {createAst{createLexem{$<string>1, NUMBER}}}};
                    } | LITERAL {
                            $$ = createAst{PRIMARY_EXPRESSION_LEXEM, {createAst{createLexem{$<string>1, LITERAL}}}};
                    } | '(' expression ')' {
                            $$ = createAst{PRIMARY_EXPRESSION_LEXEM, {$<ast>2}};
                    };

postfix_expression: primary_expression {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1}};
	            } | postfix_expression '[' expression ']' {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
                    } | postfix_expression '(' ')' {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1}};
		    } | postfix_expression '(' argument_expression_list ')' {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
                    } | postfix_expression '.' ID {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, createAst{createLexem{$<string>3, ID}}}};
                    } | postfix_expression ARROW ID {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, createAst{createLexem{$<string>3, ID}}}};
                    } | postfix_expression INCREMENT {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, createAst{createLexem{$<string>2, INCREMENT}}}};
                    } | postfix_expression DECREMENT {
                            $$ = createAst{POSTFIX_EXPRESSION_LEXEM, {$<ast>1, createAst{createLexem{$<string>2, DECREMENT}}}};
                    };

argument_expression_list: assignment_expression {
                                $$ = createAst{ARGUMENT_EXPRESSION_LIST_LEXEM, {$<ast>1}};
                        } | argument_expression_list ',' assignment_expression {
                                $$ = $<ast>1;
                                $$->addChild($<ast>3);
                        };

unary_expression: postfix_expression {
                        $$ = createAst{UNARY_EXPRESSION_LEXEM, {$<ast>1}};
                } | unary_operator cast_expression {
                        $$ = createAst{UNARY_EXPRESSION_LEXEM, {$<ast>1, $<ast>2}};
		};

unary_operator: INCREMENT {
	              $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, INCREMENT}}}};
              } | DECREMENT {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, DECREMENT}}}};
	      } | '&' {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '&'}}}};
	      } | '@' {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '@'}}}};
              } | '+' {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '+'}}}};
              } | '-' {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '-'}}}};
              } | '~' {
                      $$ = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '~'}}}};
	      };

cast_expression: unary_expression {
                       $$ = createAst{CAST_EXPRESSION_LEXEM, {$<ast>1}};
	       } | REINTERPRET_CAST '<' type_name '>' '(' cast_expression ')' {
                       $$ = createAst{CAST_EXPRESSION_LEXEM, {$<ast>3, $<ast>6}};
               };

multiplicative_expression: cast_expression {
                                  $$ = $<ast>1;
                         } | multiplicative_expression multiplicative_operator cast_expression {
                                  $$ = $<ast>2; 
                                  $$->addChild($<ast>1); 
                                  $$->addChild($<ast>3);
                         };

multiplicative_operator: '*' {
                               $$ = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '*'}}}};
                       } | '/' {
                               $$ = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '/'}}}};
                       } | '%' {
                               $$ = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '%'}}}};
                       };

additive_expression: multiplicative_expression {
                           $$ = $<ast>1;
                   } | additive_expression additive_operator multiplicative_expression {
                           $$ = $<ast>2;
                           $$->addChild($<ast>1);
                           $$->addChild($<ast>3);
                   };

additive_operator: '+' {
                         $$ = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '+'}}}};
                 } | '-' {
                         $$ = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '-'}}}};
                 };

shift_expression: additive_expression {
                         $$ = $<ast>1;
	        } | shift_expression shift_operator additive_expression {
                         $$ = $<ast>2;
                         $$->addChild($<ast>1);
                         $$->addChild($<ast>3);
                };

shift_operator: SHL {
                      $$ = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, SHL}}}};
              } | SHR {
                      $$ = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, SHR}}}};
              };

relational_expression: shift_expression {
                             $$ = $<ast>1;
	             } | relational_expression relational_operator shift_expression {
                             $$ = $<ast>2;
                             $$->addChild($<ast>1);
                             $$->addChild($<ast>3);
                     };

relational_operator: '<' {
                           $$ = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '<'}}}};
                   } | '>' {
                           $$ = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, '>'}}}}; 
                   } | LESS_EQUAL {
                           $$ = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, LESS_EQUAL}}}};
                   } | ABOVE_EQUAL {
                           $$ = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, ABOVE_EQUAL}}}};
	           };

equality_expression: relational_expression {
		           $$ = $<ast>1;
	           } | equality_expression equality_operator relational_expression {
                           $$ = $<ast>2;
                           $$->addChild($<ast>1);
                           $$->addChild($<ast>3);
                   };

equality_operator: EQUALS {
		         $$ = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, EQUALS}}}};
                 } | NOT_EQUALS {
                         $$ = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{$<string>1, NOT_EQUALS}}}};
                 };

and_expression: equality_expression {
	              $$ = createAst{AND_EXPRESSION_LEXEM, {$<ast>1}};
	      } | and_expression '&' equality_expression {
                      $$ = createAst{AND_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
              };

exclusive_or_expression: and_expression {
		               $$ = createAst{EXCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1}};
  	               } | exclusive_or_expression '^' and_expression {
                               $$ = createAst{EXCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
                       };

inclusive_or_expression: exclusive_or_expression {
		               $$ = createAst{INCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1}};
 	               } | inclusive_or_expression '|' exclusive_or_expression {
                               $$ = createAst{INCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1}};
                       };

conditional_expression: inclusive_or_expression {
		              $$ = createAst{CONDITIONAL_EXPRESSION_LEXEM, {$<ast>1}};
	              } | inclusive_or_expression DONE expression UNLESS conditional_expression { 
                              $$ = createAst{CONDITIONAL_EXPRESSION_LEXEM, {$<ast>1, $<ast>3, $<ast>5}};
                      };

assignment_expression: conditional_expression {
		             $$ = createAst{ASSIGNMENT_EXPRESSION_LEXEM, {$<ast>1}};
	             } | unary_expression assignment_operator assignment_expression {
                             $$ = createAst{ASSIGNMENT_EXPRESSION_LEXEM, {$<ast>1, $<ast>2, $<ast>3}};
                     };

assignment_operator: '=' {
		           $$ = createAst{createLexem{"=", '='}};
	           } | MUL_ASSIGN {
                           $$ = createAst{createLexem{"*=", MUL_ASSIGN}};
	           } | DIV_ASSIGN {
                           $$ = createAst{createLexem{"/=", DIV_ASSIGN}};
	           } | MOD_ASSIGN {
                           $$ = createAst{createLexem{"%=", MOD_ASSIGN}};
	           } | ADD_ASSIGN {
                           $$ = createAst{createLexem{"+=", ADD_ASSIGN}};
	           } | SUB_ASSIGN {
                           $$ = createAst{createLexem{"-=", SUB_ASSIGN}};
	           } | SHL_ASSIGN {
                           $$ = createAst{createLexem{"<<=", SHL_ASSIGN}};
	           } | SHR_ASSIGN {
                           $$ = createAst{createLexem{">>=", SHR_ASSIGN}};
	           } | AND_ASSIGN {
                           $$ = createAst{createLexem{"&=", AND_ASSIGN}};
	           } | XOR_ASSIGN {
                           $$ = createAst{createLexem{"^=", XOR_ASSIGN}};
	           } | OR_ASSIGN {
                           $$ = createAst{createLexem{"|=", OR_ASSIGN}};
                   };

expression: assignment_expression {
	          $$ = createAst{EXPRESSION_LEXEM, {$<ast>1}};
  	  } | expression ',' assignment_expression {
                  $$ = $<ast>1;
                  $$->addChild($<ast>3);
          };

constant_expression: conditional_expression {
		           $$ = createAst{CONSTANT_EXPRESSION_LEXEM, {$<ast>1}};
		   };

declaration: declaration_specifiers {
	           $$ = createAst{DECLARATION_LEXEM, {$<ast>1}};
   	   } | declaration_specifiers init_declarator_list {
                   $$ = createAst{DECLARATION_LEXEM, {$<ast>1, $<ast>2}}; 
           };
 
declaration_specifiers: type_specifier {
		              $$ = createAst{DECLARATION_SPECIFIERS_LEXEM, {$<ast>1}};
		      };

init_declarator_list: init_declarator {
		            $$ = createAst{INIT_DECLARATOR_LIST_LEXEM, {$<ast>1}};
	            } | init_declarator_list ',' init_declarator {
                            $$ = $<ast>1;
                            $$->addChild($<ast>3);
                    };

init_declarator: declarator {
	               $$ = createAst{INIT_DECLARATOR_LEXEM, {$<ast>1}};
	       } | declarator '=' initializer {
                       $$ = createAst{INIT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
               };

type_specifier: EMPTY {
	              $$ = createAst{TYPE_SPECIFIER_LEXEM, {createAst{createLexem{$<string>1, EMPTY}}}};
   	      } | REAL {
                      $$ = createAst{TYPE_SPECIFIER_LEXEM, {createAst{createLexem{$<string>1, REAL}}}};
	      } | STRING {
                      $$ = createAst{TYPE_SPECIFIER_LEXEM, {createAst{createLexem{$<string>1, STRING}}}};
	      } | ID {
                      $$ = createAst{TYPE_SPECIFIER_LEXEM, {createAst{createLexem{$<string>1, ID}}}};
              };

declarator: pointer direct_declarator {
	          $$ = createAst{DECLARATOR_LEXEM, {$<ast>1, $<ast>2}};
	  } | direct_declarator {
                  $$ = createAst{DECLARATOR_LEXEM, {$<ast>1}};
          };

direct_declarator: ID {
		         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {createAst{createLexem{$<string>1, ID}}}};
 	         } | '(' declarator ')' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>2}};
                 } | direct_declarator '[' constant_expression ']' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
                 } | direct_declarator '[' ']' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>1}};
	         } | direct_declarator '(' parameter_type_list ')' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
                 } | direct_declarator '(' identifier_list ')' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
	         } | direct_declarator '(' ')' {
                         $$ = createAst{DIRECT_DECLARATOR_LEXEM, {$<ast>1}};
                 };

pointer: '*' {
                 $$ = createAst{POINTER_LEXEM};
       } | '*' pointer {
                 $$ = createAst{POINTER_LEXEM, {$<ast>2}};
       };


parameter_type_list: parameter_list {
		           $$ = createAst{PARAMETER_TYPE_LIST_LEXEM, {$<ast>1}};
	           } | parameter_list ',' VARARG {
                           $$ = $<ast>1;
                           $$->addChild(createAst{createLexem{"...", VARARG}});
                   };

parameter_list: parameter_declaration {
                      $$ = createAst{PARAMETER_LIST_LEXEM, {$<ast>1}};
	      } | parameter_list ',' parameter_declaration {
                      $$ = $<ast>1;
                      $$->addChild($<ast>3);
              };

parameter_declaration: declaration_specifiers declarator {
		             $$ = createAst{PARAMETER_DECLARATION_LEXEM, {$<ast>1, $<ast>2}};
		     } | declaration_specifiers abstract_declarator {
                             $$ = createAst{PARAMETER_DECLARATION_LEXEM, {$<ast>1, $<ast>2}};
                     } | declaration_specifiers {
                             $$ = createAst{PARAMETER_DECLARATION_LEXEM, {$<ast>1}};
                     };

identifier_list: ID {
	               $$ = createAst{IDENTIFIER_LIST_LEXEM, {createAst{createLexem{$<string>1, ID}}}};
	       } | identifier_list ',' ID {
                       $$ = $<ast>1;
                       $$->addChild(createAst{createLexem{$<string>3, ID}});
               };

type_name: abstract_declarator {
                 $$ = createAst{TYPE_NAME_LEXEM, {$<ast>1}};
         };

abstract_declarator: pointer {
		           $$ = createAst{ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}};
 	           } | direct_abstract_declarator {
                           $$ = createAst{ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}};
	           } | pointer direct_abstract_declarator {
                           $$ = createAst{ABSTRACT_DECLARATOR_LEXEM, {$<ast>1, $<ast>2}};
                   };

direct_abstract_declarator: '(' abstract_declarator ')' {
			          $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  } | '[' ']' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  } | '[' constant_expression ']' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}};
                          } | direct_abstract_declarator '[' ']' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}}
                          } | direct_abstract_declarator '[' constant_expression ']' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
                          } | '(' ')' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
                          } | '(' parameter_type_list ')' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>2}};
                          } | direct_abstract_declarator '(' ')' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}};
                          } | direct_abstract_declarator '(' parameter_type_list ')' {
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1, $<ast>2}};
                          };

initializer: assignment_expression {
                   $$ = createAst{INITIALIZER_LEXEM, {$<ast>1}};
           } | '{' initializer_list '}' {
                   $$ = createAst{INITIALIZER_LEXEM, {$<ast>2}};
           };

initializer_list: initializer {
                        $$ = createAst{INITIALIZER_LIST_LEXEM, {$<ast>1}};
                } | initializer_list ',' initializer {
                        $$ = $<ast>1;
                        $$->addChild($<ast>2);
                };

statement: labeled_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
	 } | compound_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
         } | expression_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
	 } | branched_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
         } | looped_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
	 } | jump_statement {
                 $$ = createAst{STATEMENT_LEXEM, {$<ast>1}};
         };

labeled_statement: ID ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {createAst{createLexem{$<string>1, ID}}, $<ast>3}};
                 } | constant_expression ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {$<ast>1, $<ast>3}};
                 } | OTHER ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {$<ast>3}};
                 };

compound_statement: '{' '}' {
                          $$ = createAst{COMPOUND_STATEMENT_LEXEM, {}};
                  } | '{' declaration_statement_list '}' {
                          $$ = createAst{COMPOUND_STATEMENT_LEXEM, {$<ast>2}};
                  };

declaration_statement: declaration {
                             $$ = createAst{DECLARATION_STATEMENT_LEXEM, {$<ast>1}};
                     } | statement {
                             $$ = createAst{DECLARATION_STATEMENT_LEXEM, {$<ast>1}};
                     };

declaration_statement_list: declaration_statement {
                                  $$ = createAst{DECLARATION_STATEMENT_LIST_LEXEM, {$<ast>1}};
                          } | declaration_statement_list declaration_statement {
                                  $$ = $<ast>1;
                                  $$->addChild($<ast>2);
                          };

expression_statement: PASS {
                            $$ = createAst{EXPRESSION_STATEMENT_LEXEM, {}}
                    } | expression {
                            $$ = createAst{EXPRESSION_STATEMENT_LEXEM, {$<ast>1}};
                    };

labeled_statement_list: labeled_statement {
                              $$ = createAst{LABELED_STATEMENT_LIST_LEXEM, {$<ast>1}};
                      } | labeled_statement_list labeled_statement {
                              $$ = $<ast>1;
 	                      $$->addChild($<ast>2);
                      };

branched_statement: IF expression statement {
                           $$ = createAst{BRANCHED_STATEMENT_LEXEM, {$<ast>2, $<ast>3}};
                   } | IF expression statement ELSE statement {
                           $$ = createAst{BRANCHED_STATEMENT_LEXEM, {$<ast>2, $<ast>3, $<ast>5}};
                   } | CASE expression '{' labeled_statement_list '}' {
                           $$ = createAst{BRANCHED_STATEMENT_LEXEM, {$<ast>2, $<ast>4}};
                   };

looped_statement: WHILE expression statement {
                        $$ = createAst{LOOPED_STATEMENT_LEXEM, {$<ast>2, $<ast>3}};
                } | DO expression statement WHILE statement {
                        $$ = createAst{LOOPED_STATEMENT_LEXEM, {$<ast>2, $<ast>3, $<ast>5}}
	        } | FOR expression_statement ';' expression_statement ';' expression statement {
                        $$ = createAst{LOOPED_STATEMENT_LEXEM, {$<ast>2, $<ast>4, $<ast>6, $<ast>7}};
                };

jump_statement: JUMP ID {
                      $$ = createAst{JUMP_STATEMENT_LEXEM, {createAst{createLexem{$<string>2, ID}}}};
              } | NEXT {
                      $$ = createAst{JUMP_STATEMENT_LEXEM};
              } | STOP {
                      $$ = createAst{JUMP_STATEMENT_LEXEM};
              } | RETURN {
                      $$ = createAst{JUMP_STATEMENT_LEXEM};
	      } | RETURN expression {
                      $$ = createAst{JUMP_STATEMENT_LEXEM, {$<ast>2}};
              };

translation_unit: external_declaration {
                        *ast = $$ = createAst{EXTERNAL_DECLARATION_LEXEM, {$<ast>1}};
                } | translation_unit external_declaration {
                        $$ = $<ast>1;
                        $$->addChild($<ast>2);
                };

external_declaration: function_definition {
		            $$ = createAst{EXTERNAL_DECLARATION_LEXEM, {$<ast>1}};
                    } | declaration {
                            $$ = createAst{EXTERNAL_DECLARATION_LEXEM, {$<ast>1}};
                    };

function_definition: function_signature compound_statement {
                           $$ = createAst{FUNCTION_DEFINITION_LEXEM, {$<ast>1, $<ast>2}};
                   };

function_signature: function_name function_args function_type {
                           $$ = createAst{FUNCTION_SIGNATURE_LEXEM, {$<ast>1, $<ast>2, $<ast>3}};
                  };

function_name: FUNCTION ID {
	             $$ = createAst{FUNCTION_NAME_LEXEM, 
                                    {createAst{createLexem{$<string>1, FUNCTION}},
                                     createAst{createLexem{$<string>2, ID}}}};
	     };

function_args: {
	             $$ = createAst{FUNCTION_ARGS_LEXEM};
             } | '(' ')' {
                     $$ = createAst{FUNCTION_ARGS_LEXEM};
             } | '(' parameter_type_list ')' {
                     $$ = createAst{FUNCTION_ARGS_LEXEM, {$<ast>2}};
             };

function_type: {
	             $$ = createAst{FUNCTION_TYPE_LEXEM, {createAst{createLexem{"Empty", EMPTY}}}};
             } | ARROW type_specifier {
                     $$ = createAst{FUNCTION_TYPE_LEXEM, {$<ast>2}};
             };
%%

void yyerror(LLCCEP_SiHi::ast **, const char *msg)
{
	::std::cerr << "[" << yyfilename << ":" << yylineno << "]:\n"
                    << msg << "\n";
}

