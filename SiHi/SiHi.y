%{
#include "ast/ast.hpp"
%}

%union {
	LLCCEP_SiHi::ast tree;
	const char *string;
}

%token <string> ID NUMBER LITERAL ARROW INCREMENT DECREMENT
%token <string> REINTERPRET_CAST SHL SHR LESS_EQUAL ABOVE_EQUAL
%token <string> EQUALS NOT_EQUALS MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token <string> ADD_ASSIGN SUB_ASSIGN SHL_ASSIGN SHR_ASSIGN AND_ASSIGN
%token <string> XOR_ASSIGN OR_ASSIGN EMPTY REAL STRING OTHER PASS
%token <string> IF ELSE CASE LOOP JUMP NEXT STOP RETURN FUNCTION
%token <string> DONE UNLESS VARARG

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
%type <ast> function_definition function_prototype function_name function_args function_type

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
                        $$ = new LLCCEP_SiHi::ast({$<ast>2}, 
                                                  "++",
                                                  INCREMENT);
                } | DECREMENT unary_expression {
                        $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                                  "--",
                                                  DECREMENT);
	        } | unary_operator cast_expression {
		        $$ = $1;
                        $$->insert_child($<ast>2);
		};

unary_operator: '&' {
                      $$ = new LLCCEP_SiHi::ast({}, "&", '&');
	      } | '@' {
                      $$ = new LLCCEP_SiHi::ast({}, "@", '@');
              } | '+' {
                      $$ = new LLCCEP_SiHi::ast({}, "+", '+');
              } | '-' {
                      $$ = new LLCCEP_SiHi::ast({}, "-", '-');
              } | '~' {
                      $$ = new LLCCEP_SiHi::ast({}, "~", '~');
	      } | '!' {
                      $$ = new LLCCEP_SiHi::ast({}, "!", '!');
              };

cast_expression: unary_expression {
                       $$ = $<ast>1;
	       } | REINTERPRET_CAST '<' type_name '>' '(' cast_expression ')' {
                       $$ = new LLCCEP_SiHi::ast({$<ast>3, $<ast>6}, "reinterpret_cast", REINTERPRET_CAST);
               };

multiplicative_expression: cast_expression {
                                  $$ = $<ast>1;
                         } | multiplicative_expression multiplicative_operator cast_expression {
                                  $$ = $<ast>2; 
                                  $$->insert_child($<ast>1); 
                                  $$->insert_child($<ast>3);
                         };

multiplicative_operator: '*' {
                               $$ = new LLCCEP_SiHi::ast({}, "*", '*');
                       } | '/' {
                               $$ = new LLCCEP_SiHi::ast({}, "/", '/');
                       } | '%' {
                               $$ = new LLCCEP_SiHi::ast({}, "%", '%');
                       };

additive_expression: multiplicative_expression {
                           $$ = $<ast>1;
                   } | additive_expression additive_operator multiplicative_expression {
                           $$ = $<ast>2;
                           $$->insert_child($<ast>1);
                           $$->insert_child($<ast>3);
                   };

additive_operator: '+' {
                         $$ = new LLCCEP_SiHi::ast({}, "+", '+');
                 } | '-' {
                         $$ = new LLCCEP_SiHi::ast({}, "-", '-');
                 };

shift_expression: additive_expression {
                         $$ = $<ast>1;
	        } | shift_expression shift_operator additive_expression {
                         $$ = $<ast>2;
                         $$->insert_child($<ast>1);
                         $$->insert_child($<ast>3);
                };

shift_operator: SHL {
                      $$ = new LLCCEP_SiHi::ast({}, "<<", SHL);
              } | SHR {
                      $$ = new LLCCEP_SiHi::ast({}, ">>", SHR);
              };

relational_expression: shift_expression {
                             $$ = $<ast>1;
	             } | relational_expression relational_operator shift_expression {
                             $$ = $<ast>2;
                             $$->insert_child($<ast>1);
                             $$->insert_child($<ast>3);
                     };

relational_operator: '<' {
                           $$ = new LLCCEP_SiHi::ast({}, "<", '<');
                   } | '>' {
                           $$ = new LLCCEP_SiHi::ast({}, ">", '>');
                   } | LESS_EQUAL {
                           $$ = new LLCCEP_SiHi::ast({}, "<=", LESS_EQUAL);
                   } | ABOVE_EQUAL {
                           $$ = new LLCCEP_SiHi::ast({}, ">=", ABOVE_EQUAL);
                   };

equality_expression: relational_expression {
		           $$ = $<ast>1;
	           } | equality_expression equality_operator relational_expression {
                           $$ = $<ast>2;
                           $$->insert_child($<ast>1);
                           $$->insert_child($<ast>3);
                   };

equality_operator: EQUALS {
		         $$ = new LLCCEP_SiHi::ast({}, "==", EQUALS);
                 } | NOT_EQUALS {
                         $$ = new LLCCEP_SiHi::ast({}, "!=", NOT_EQUALS);
                 };

and_expression: equality_expression {
	              $$ = $<ast>1;
	      } | and_expression '&' equality_expression {
                      $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                "&",
                                                '&');
              };

exclusive_or_expression: and_expression {
		               $$ =$<ast>1;
  	               } | exclusive_or_expression '^' and_expression {
                               $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                         "^",
                                                         '^');
                       };

inclusive_or_expression: exclusive_or_expression {
		               $$ = $<ast>1;
 	               } | inclusive_or_expression '|' exclusive_or_expression {
                               $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                         "|",
                                                         '|');
                       };

conditional_expression: inclusive_or_expression {
		              $$ = $1;
	              } | inclusive_or_expression DONE expression UNLESS conditional_expression { 
                              $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3, $<ast>5},
                                                        "if -- else");
                      };

assignment_expression: conditional_expression {
		             $$ = $<ast>1;
	             } | unary_expression assignment_operator assignment_expression {
                             $$ = $<ast>2;
                             $$->insert_child($<ast>1);
                             $$->insert_child($<ast>3);
                     };

assignment_operator: '=' {
		           $$ = new LLCCEP_SiHi::ast({},
                                                     "=",
                                                     '=');
	           } | MUL_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "*=",
                                                     MUL_ASSIGN);
	           } | DIV_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "/=",
                                                     DIV_ASSIGN);
	           } | MOD_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "%=",
                                                     MOD_ASSIGN);
	           } | ADD_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "+=",
                                                     ADD_ASSIGN);
	           } | SUB_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "-=",
                                                     SIB_ASSIGN);
	           } | SHL_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "<<=",
                                                     SHL_ASSIGN);
	           } | SHR_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     ">>=",
                                                     SHR_ASSIGN);
	           } | AND_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "&=",
                                                     AND_ASSIGN);
	           } | XOR_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "^=",
                                                     XOR_ASSIGN);
	           } | OR_ASSIGN {
                           $$ = new LLCCEP_SiHi::ast({},
                                                     "|=",
                                                     OR_ASSIGN);
                   };

expression: assignment_expression {
	          $$ = $<ast>1;
  	  } | expression ',' assignment_expression {
                  $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                            ",", ',');
          };

constant_expression: conditional_expression {
		           $$ = $<ast>1;
		   };

declaration: declaration_specifiers {
	           $$ = $<ast>1;
   	   } | declaration_specifiers init_declarator_list {
                   $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, 
                                             "declaration",
                                             DECLARATION);
           };
 
declaration_specifiers: type_specifier {
		              $$ = $<ast>1;
		      };

init_declarator_list: init_declarator {
		            $$ = $<ast>1;
	            } | init_declarator_list ',' init_declarator {
                            $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      ",",
                                                      ',');
                    };

init_declarator: declarator {
	               $$ = <ast>1;
	       } | declarator '=' initializer {
                       $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                 "=",
                                                 '=');
               };

type_specifier: EMPTY {
	              $$ = new LLCCEP_SiHi::ast({},
                                                "empty",
                                                EMPTY);
   	      } | REAL {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "real",
                                                REAL);
	      } | STRING {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "string",
                                                STRING);
	      } | ID {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "typename: " + $<string>1,
                                                TYPENAME);
              };

declarator: pointer direct_declarator {
	          $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                            "declarator",
                                            DECLARATOR);
	  } | direct_declarator {
                  $$ = $<ast>1;
          };

direct_declarator: ID {
		         $$ = new LLCCEP_SiHi::ast({}, 
                                                   $<string>1, 
                                                   ID);
 	         } | '(' declarator ')' {
                         $$ = $<ast>2;
                 } | direct_declarator '[' constant_expression ']' {
                         $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                   "[]",
                                                   ARRAY_DECLARATION);
                 } | direct_declarator '[' ']' {
                         $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                   "[]",
                                                   ARRAY_DECLARATION);
	         } | direct_declarator '(' parameter_type_list ')' {
                 } | direct_declarator '(' identifier_list ')' {
	         } | direct_declarator '(' ')' {
                 };

pointer: '*' {
                 $$ = new LLCCEP_SiHi::ast({}, "*", POINTER);
       } | '*' pointer {
                 $$ = new LLCCEP_SiHi::ast({}, "*", POINTER);
       };


parameter_type_list: parameter_list {
		           $$ = $<ast>1;
	           } | parameter_list ',' VARARG {
                           $$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "vararg", VARARG)}, 
                                                     ",",
                                                     PARAM_TYPE_LIST);
                   };

parameter_list: parameter_declaration {
                      $$ = $<ast>1;
	      } | parameter_list ',' parameter_declaration {
                      $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                ",",
                                                PARAMETER_LIST);
              };

parameter_declaration: declaration_specifiers declarator {
		             $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
		     } | declaration_specifiers abstract_declarator {
                             $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     } | declaration_specifiers {
                             $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     };

identifier_list: ID {
	               $$ = new LLCCEP_SiHi::ast({},
                                                 $<string>1,
                                                 ID);
	       } | identifier_list ',' ID {
                       $$ = new LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, $<string>2, ID)},
                                                 ",",
                                                 IDENTIFIER_LIST);
               };

type_name: abstract_declarator {
                 $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                           "typename",
                                           TYPENAME);
         };

abstract_declarator: pointer {
		           $$ = $<ast>1;
 	           } | direct_abstract_declarator {
                           $$ = $<ast>1;
	           } | pointer direct_abstract_declarator {
                           $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                     "Abstract declarator",
                                                     ABSTRACT_DECLARATOR);
                   };

direct_abstract_declarator: '(' abstract_declarator ')' {
			          $$ = $<ast>2;
	                  } | '[' ']' {
                                  $$ = new LLCCEP_SiHi::ast({}, 
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
	                  } | '[' constant_expression ']' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '[' ']' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '[' constant_expression ']' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | '(' ')' {
                                  $$ = new LLCCEP_SiHi::ast({},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | '(' parameter_type_list ')' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '(' ')' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '(' parameter_type_list ')' {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>1},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          };

initializer: assignment_expression {
                   $$ = $<ast>1;
           } | '{' initializer_list '}' {
                   $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                             "{}",
                                             INITIALIZER);
           };

initializer_list: initializer {
                        $$ = $<ast>1;
                } | initializer_list ',' initializer {
                        $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                  ",",
                                                  INITIALIZER_LIST);
                };

statement: labeled_statement {
                 $$ = $<ast>1;
	 } | compound_statement {
                 $$ = $<ast>1;
         } | expression_statement {
                 $$ = $<ast>1;
	 } | branched_statement {
                 $$ = $<ast>1;
         } | looped_statement {
                 $$ = $<ast>1;
	 } | jump_statement {
                 $$ = $<ast>1;
         };

labeled_statement: ID ':' statement {
                         $$ = new LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, $<string>1, ID), $<ast>3},
                                                   ":",
                                                   ':');
                 } | constant_expression ':' statement {
                         $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                   ":",
                                                   ':');
                 } | OTHER ':' statement {
                         $$ = new LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, "other", OTHER), $<ast>3},
                                                   ":",
                                                   ':');
                 };

compound_statement: '{' '}' {
                          $$ = new LLCCEP_SiHi::ast({},
                                                    "Compound statement",
                                                    COMPOUND_STATEMENT);
                  } | '{' declaration_statement_list '}' {
                          $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                                    "Compound statement",
                                                    COMPOUND_STATEMENT);
                  };

declaration_statement: declaration {
                             $$ = $<ast>1;
                     } | statement {
                             $$ = $<ast>1;
                     };

declaration_statement_list: declaration_statement {
                                  $$ = $<ast>1;
                          } | declaration_statement_list declaration_statement {
                                  $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                            "Declaration|statement list",
                                                            DECLARATION_STATEMENT_LIST);
                          };

expression_statement: PASS {
                            $$ = new LLCCEP_SiHi::ast({},
                                                      "pass",
                                                      PASS);
                    } | expression {
                            $$ = $<ast>1;
                    };

labeled_statement_list: labeled_statement {
                              $$ = $<ast>1;
                      } | labeled_statement_list labeled_statement {
                              $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                        "Labeled statement list",
                                                        LABELED_STATEMENT_LIST);
                      };

branched_statement: IF expression statement {
                           $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3},
                                                     "if",
                                                     IF)
                   } | IF expression statement ELSE statement {
                           $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3, $<ast>4}.
                                                     "if -- else",
                                                     IF);
                   } | CASE expression '{' labeled_statement_list '}' {
                           $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4},
                                                     "case",
                                                     CASE);
                   };

looped_statement: LOOP expression statement {
                        $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>3},
                                                  "loop",
                                                  LOOP);
                } | LOOP expression ';' expression statement {
                        $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4, $<ast>5},
                                                  "loop",
                                                  LOOP);
	        } | LOOP expression_statement ';' expression_statement ';' expression statement {
                        $$ = new LLCCEP_SiHi::ast({$<ast>2, $<ast>4, $<ast>6, $<ast>7},
                                                  "loop",
                                                  LOOP);
                };

jump_statement: JUMP ID {
                      $$ = new LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, $<string>2, ID)},
                                                "jump",
                                                JUMP);
              } | NEXT {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "next",
                                                NEXT);
              } | STOP {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "stop",
                                                STOP);
              } | RETURN {
                      $$ = new LLCCEP_SiHi::ast({},
                                                "return",
                                                RETURN);
	      } | RETURN expression {
                      $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                                "return",
                                                RETURN);
              };

translation_unit: external_declaration {
                        $$ = $<ast>1;
                } | translation_unit external_declaration {
                        $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                  "external declaration list",
                                                  EXTERNAL_DECLARATION_LIST);
                };

external_declaration: function_definition {
                            $$ = $<ast>1;
                    } | declaration {
                            $$ = $<ast>1;
                    };

function_definition: function_prototype compound_statement {
                           $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                     "function definition");
                   };

function_prototype: function_name function_args function_type {
                           $$ = new LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3},
                                                     "function prototype",
                                                     FUNCTION_PROTOTYPE);
                  };

function_name: FUNCTION ID {
	             $$ = new LLCCEP_SiHi::ast({},
                                               $<string>2,
                                               ID);
	     };

function_args: {
	             $$ = new LLCCEP_SiHi::ast({},
                                               "Function arguments",
                                               FUNCTION_ARGUMENTS);
             } | '(' ')' {
                     $$ = new LLCCEP_SiHi::ast({},
                                               "Function arguments",
                                               FUNCTION_ARGUMENTS);
             } | '(' parameter_type_list ')' {
                     $$ = new LLCCEP_SiHi::ast({$<ast>2},
                                               "Function arguments",
                                               FUNCTION_ARGUMENTS);
             };

function_type: {
	             $$ = new LLCCEP_SiHi::ast({},
                                               "empty",
                                               EMPTY);
             } | ARROW type_specifier {
                     $$ = $<ast>2;
             };
%%
