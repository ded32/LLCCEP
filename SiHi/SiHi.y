%{
#include <string>
#include "ast/ast.hpp"
%}

%union {
	LLCCEP_SiHi::ast ast;
	::std::string string;
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
%type <ast> function_definition function_prototype function_name function_args function_type
%type <ast> labeled_statement_list

%%
primary_expression: ID {
                            $$ = LLCCEP_SiHi::ast({}, 
                                                      "Identifier: " + $<string>1,
                                                      ID);
                    } | NUMBER {
                            $$ = LLCCEP_SiHi::ast({},
                                                      "Number: " + $<string>1,
                                                      NUMBER);
                    } | LITERAL {
                            $$ = LLCCEP_SiHi::ast({},
                                                      "Literal: " + $<string>1,
                                                      LITERAL);
                    } | '(' expression ')' {
                            $$ = $<ast>2;
                    };

postfix_expression: primary_expression {
                            $$ = $<ast>1;
	            } | postfix_expression '[' expression ']' {
                            $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      "[]",
                                                      ACCESS_ARRAY_MEMBER);
                    } | postfix_expression '(' ')' {
                            $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                      "()",
                                                      INVOKE);
		    } | postfix_expression '(' argument_expression_list ')' {
                            $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      "()",
                                                      INVOKE);
                    } | postfix_expression '.' ID {
                            $$ = LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "Identifier: " + $<string>3, ID)},
                                                      "."
                                                      ACCESS_MEMBER);
                    } | postfix_expression ARROW ID {
                            $$ = LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "Identifier: " + $<string>3, ID)},
                                                      "->",
                                                      ACCESS_MEMBER_BY_PTR);
                    } | postfix_expression INCREMENT {
                            $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                      "++",
                                                      INCREMENT);
                    } | postfix_expression DECREMENT {
                            $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                      "--",
                                                      DECREMENT);
                    };

argument_expression_list: assignment_expression {
                                $$ = $<ast>1; 
                        } | argument_expression_list ',' assignment_expression {
                                $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                          $<ast>1.value() + " " + $<ast>1.value(),
                                                          "Argument expression list");
                        };

unary_expression: postfix_expression {
                        $$ = $<ast>1;
                } | INCREMENT unary_expression {
                        $$ = LLCCEP_SiHi::ast({$<ast>2}, 
                                                  "++",
                                                  INCREMENT);
                } | DECREMENT unary_expression {
                        $$ = LLCCEP_SiHi::ast({$<ast>2},
                                                  "--",
                                                  DECREMENT);
	        } | unary_operator cast_expression {
		        $$ = $1;
                        $$->insert_child($<ast>2);
		};

unary_operator: '&' {
                      $$ = LLCCEP_SiHi::ast({}, "&", '&');
	      } | '@' {
                      $$ = LLCCEP_SiHi::ast({}, "@", '@');
              } | '+' {
                      $$ = LLCCEP_SiHi::ast({}, "+", '+');
              } | '-' {
                      $$ = LLCCEP_SiHi::ast({}, "-", '-');
              } | '~' {
                      $$ = LLCCEP_SiHi::ast({}, "~", '~');
	      } | '!' {
                      $$ = LLCCEP_SiHi::ast({}, "!", '!');
              };

cast_expression: unary_expression {
                       $$ = $<ast>1;
	       } | REINTERPRET_CAST '<' type_name '>' '(' cast_expression ')' {
                       $$ = LLCCEP_SiHi::ast({$<ast>3, $<ast>6}, "reinterpret_cast", REINTERPRET_CAST);
               };

multiplicative_expression: cast_expression {
                                  $$ = $<ast>1;
                         } | multiplicative_expression multiplicative_operator cast_expression {
                                  $$ = $<ast>2; 
                                  $$->insert_child($<ast>1); 
                                  $$->insert_child($<ast>3);
                         };

multiplicative_operator: '*' {
                               $$ = LLCCEP_SiHi::ast({}, "*", '*');
                       } | '/' {
                               $$ = LLCCEP_SiHi::ast({}, "/", '/');
                       } | '%' {
                               $$ = LLCCEP_SiHi::ast({}, "%", '%');
                       };

additive_expression: multiplicative_expression {
                           $$ = $<ast>1;
                   } | additive_expression additive_operator multiplicative_expression {
                           $$ = $<ast>2;
                           $$->insert_child($<ast>1);
                           $$->insert_child($<ast>3);
                   };

additive_operator: '+' {
                         $$ = LLCCEP_SiHi::ast({}, "+", '+');
                 } | '-' {
                         $$ = LLCCEP_SiHi::ast({}, "-", '-');
                 };

shift_expression: additive_expression {
                         $$ = $<ast>1;
	        } | shift_expression shift_operator additive_expression {
                         $$ = $<ast>2;
                         $$->insert_child($<ast>1);
                         $$->insert_child($<ast>3);
                };

shift_operator: SHL {
                      $$ = LLCCEP_SiHi::ast({}, "<<", SHL);
              } | SHR {
                      $$ = LLCCEP_SiHi::ast({}, ">>", SHR);
              };

relational_expression: shift_expression {
                             $$ = $<ast>1;
	             } | relational_expression relational_operator shift_expression {
                             $$ = $<ast>2;
                             $$->insert_child($<ast>1);
                             $$->insert_child($<ast>3);
                     };

relational_operator: '<' {
                           $$ = LLCCEP_SiHi::ast({}, "<", '<');
                   } | '>' {
                           $$ = LLCCEP_SiHi::ast({}, ">", '>');
                   } | LESS_EQUAL {
                           $$ = LLCCEP_SiHi::ast({}, "<=", LESS_EQUAL);
                   } | ABOVE_EQUAL {
                           $$ = LLCCEP_SiHi::ast({}, ">=", ABOVE_EQUAL);
                   };

equality_expression: relational_expression {
		           $$ = $<ast>1;
	           } | equality_expression equality_operator relational_expression {
                           $$ = $<ast>2;
                           $$->insert_child($<ast>1);
                           $$->insert_child($<ast>3);
                   };

equality_operator: EQUALS {
		         $$ = LLCCEP_SiHi::ast({}, "==", EQUALS);
                 } | NOT_EQUALS {
                         $$ = LLCCEP_SiHi::ast({}, "!=", NOT_EQUALS);
                 };

and_expression: equality_expression {
	              $$ = $<ast>1;
	      } | and_expression '&' equality_expression {
                      $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                "&",
                                                '&');
              };

exclusive_or_expression: and_expression {
		               $$ =$<ast>1;
  	               } | exclusive_or_expression '^' and_expression {
                               $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                         "^",
                                                         '^');
                       };

inclusive_or_expression: exclusive_or_expression {
		               $$ = $<ast>1;
 	               } | inclusive_or_expression '|' exclusive_or_expression {
                               $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                         "|",
                                                         '|');
                       };

conditional_expression: inclusive_or_expression {
		              $$ = $1;
	              } | inclusive_or_expression DONE expression UNLESS conditional_expression { 
                              $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3, $<ast>5},
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
		           $$ = LLCCEP_SiHi::ast({},
                                                     "=",
                                                     '=');
	           } | MUL_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "*=",
                                                     MUL_ASSIGN);
	           } | DIV_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "/=",
                                                     DIV_ASSIGN);
	           } | MOD_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "%=",
                                                     MOD_ASSIGN);
	           } | ADD_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "+=",
                                                     ADD_ASSIGN);
	           } | SUB_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "-=",
                                                     SIB_ASSIGN);
	           } | SHL_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "<<=",
                                                     SHL_ASSIGN);
	           } | SHR_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     ">>=",
                                                     SHR_ASSIGN);
	           } | AND_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "&=",
                                                     AND_ASSIGN);
	           } | XOR_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "^=",
                                                     XOR_ASSIGN);
	           } | OR_ASSIGN {
                           $$ = LLCCEP_SiHi::ast({},
                                                     "|=",
                                                     OR_ASSIGN);
                   };

expression: assignment_expression {
	          $$ = $<ast>1;
  	  } | expression ',' assignment_expression {
                  $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                            ",", ',');
          };

constant_expression: conditional_expression {
		           $$ = $<ast>1;
		   };

declaration: declaration_specifiers {
	           $$ = $<ast>1;
   	   } | declaration_specifiers init_declarator_list {
                   $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2}, 
                                             "declaration",
                                             DECLARATION);
           };
 
declaration_specifiers: type_specifier {
		              $$ = $<ast>1;
		      };

init_declarator_list: init_declarator {
		            $$ = $<ast>1;
	            } | init_declarator_list ',' init_declarator {
                            $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                      ",",
                                                      ',');
                    };

init_declarator: declarator {
	               $$ = <ast>1;
	       } | declarator '=' initializer {
                       $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                 "=",
                                                 '=');
               };

type_specifier: EMPTY {
	              $$ = LLCCEP_SiHi::ast({},
                                                "empty",
                                                EMPTY);
   	      } | REAL {
                      $$ = LLCCEP_SiHi::ast({},
                                                "real",
                                                REAL);
	      } | STRING {
                      $$ = LLCCEP_SiHi::ast({},
                                                "string",
                                                STRING);
	      } | ID {
                      $$ = LLCCEP_SiHi::ast({},
                                                "typename: " + $<string>1,
                                                TYPENAME);
              };

declarator: pointer direct_declarator {
	          $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                            "declarator",
                                            DECLARATOR);
	  } | direct_declarator {
                  $$ = $<ast>1;
          };

direct_declarator: ID {
		         $$ = LLCCEP_SiHi::ast({}, 
                                                   $<string>1, 
                                                   ID);
 	         } | '(' declarator ')' {
                         $$ = $<ast>2;
                 } | direct_declarator '[' constant_expression ']' {
                         $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                   "[]",
                                                   ARRAY_DECLARATION);
                 } | direct_declarator '[' ']' {
                         $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                   "[]",
                                                   ARRAY_DECLARATION);
	         } | direct_declarator '(' parameter_type_list ')' {
                 } | direct_declarator '(' identifier_list ')' {
	         } | direct_declarator '(' ')' {
                 };

pointer: '*' {
                 $$ = LLCCEP_SiHi::ast({}, "*", POINTER);
       } | '*' pointer {
                 $$ = LLCCEP_SiHi::ast({}, "*", POINTER);
       };


parameter_type_list: parameter_list {
		           $$ = $<ast>1;
	           } | parameter_list ',' VARARG {
                           $$ = LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, "vararg", VARARG)}, 
                                                     ",",
                                                     PARAM_TYPE_LIST);
                   };

parameter_list: parameter_declaration {
                      $$ = $<ast>1;
	      } | parameter_list ',' parameter_declaration {
                      $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                ",",
                                                PARAMETER_LIST);
              };

parameter_declaration: declaration_specifiers declarator {
		             $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
		     } | declaration_specifiers abstract_declarator {
                             $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     } | declaration_specifiers {
                             $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     };

identifier_list: ID {
	               $$ = LLCCEP_SiHi::ast({},
                                                 $<string>1,
                                                 ID);
	       } | identifier_list ',' ID {
                       $$ = LLCCEP_SiHi::ast({$<ast>1, new LLCCEP_SiHi::ast({}, $<string>2, ID)},
                                                 ",",
                                                 IDENTIFIER_LIST);
               };

type_name: abstract_declarator {
                 $$ = LLCCEP_SiHi::ast({$<ast>1},
                                           "typename",
                                           TYPENAME);
         };

abstract_declarator: pointer {
		           $$ = $<ast>1;
 	           } | direct_abstract_declarator {
                           $$ = $<ast>1;
	           } | pointer direct_abstract_declarator {
                           $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                     "Abstract declarator",
                                                     ABSTRACT_DECLARATOR);
                   };

direct_abstract_declarator: '(' abstract_declarator ')' {
			          $$ = $<ast>2;
	                  } | '[' ']' {
                                  $$ = LLCCEP_SiHi::ast({}, 
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
	                  } | '[' constant_expression ']' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>2},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '[' ']' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '[' constant_expression ']' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | '(' ')' {
                                  $$ = LLCCEP_SiHi::ast({},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | '(' parameter_type_list ')' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>2},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '(' ')' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          } | direct_abstract_declarator '(' parameter_type_list ')' {
                                  $$ = LLCCEP_SiHi::ast({$<ast>1},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          };

initializer: assignment_expression {
                   $$ = $<ast>1;
           } | '{' initializer_list '}' {
                   $$ = LLCCEP_SiHi::ast({$<ast>2},
                                             "{}",
                                             INITIALIZER);
           };

initializer_list: initializer {
                        $$ = $<ast>1;
                } | initializer_list ',' initializer {
                        $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
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
                         $$ = LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, $<string>1, ID), $<ast>3},
                                                   ":",
                                                   ':');
                 } | constant_expression ':' statement {
                         $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>3},
                                                   ":",
                                                   ':');
                 } | OTHER ':' statement {
                         $$ = LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, "other", OTHER), $<ast>3},
                                                   ":",
                                                   ':');
                 };

compound_statement: '{' '}' {
                          $$ = LLCCEP_SiHi::ast({},
                                                    "Compound statement",
                                                    COMPOUND_STATEMENT);
                  } | '{' declaration_statement_list '}' {
                          $$ = LLCCEP_SiHi::ast({$<ast>2},
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
                                  $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                            "Declaration|statement list",
                                                            DECLARATION_STATEMENT_LIST);
                          };

expression_statement: PASS {
                            $$ = LLCCEP_SiHi::ast({},
                                                      "pass",
                                                      PASS);
                    } | expression {
                            $$ = $<ast>1;
                    };

labeled_statement_list: labeled_statement {
                              $$ = $<ast>1;
                      } | labeled_statement_list labeled_statement {
                              $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                        "Labeled statement list",
                                                        LABELED_STATEMENT_LIST);
                      };

branched_statement: IF expression statement {
                           $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>3},
                                                     "if",
                                                     IF)
                   } | IF expression statement ELSE statement {
                           $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>3, $<ast>4}.
                                                     "if -- else",
                                                     IF);
                   } | CASE expression '{' labeled_statement_list '}' {
                           $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>4},
                                                     "case",
                                                     CASE);
                   };

looped_statement: WHILE expression statement {
                        $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>3},
                                              "loop",
                                              WHILE);
                } | DO expression statement WHILE statement {
                        $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>4, $<ast>5},
                                              "loop",
                                              DO);
	        } | FOR expression_statement ';' expression_statement ';' expression statement {
                        $$ = LLCCEP_SiHi::ast({$<ast>2, $<ast>4, $<ast>6, $<ast>7},
                                              "loop",
                                              FOR);
                };

jump_statement: JUMP ID {
                      $$ = LLCCEP_SiHi::ast({new LLCCEP_SiHi::ast({}, $<string>2, ID)},
                                            "jump",
                                            JUMP);
              } | NEXT {
                      $$ = LLCCEP_SiHi::ast({},
                                            "next",
                                            NEXT);
              } | STOP {
                      $$ = LLCCEP_SiHi::ast({},
                                            "stop",
                                            STOP);
              } | RETURN {
                      $$ = LLCCEP_SiHi::ast({},
                                            "return",
                                            RETURN);
	      } | RETURN expression {
                      $$ = LLCCEP_SiHi::ast({$<ast>2},
                                            "return",
                                            RETURN);
              };

translation_unit: external_declaration {
                        buildSyntaxTree = $$ = $<ast>1;
                } | translation_unit external_declaration {
                        builtSyntaxTree = $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                                "external declaration list",
                                                                EXTERNAL_DECLARATION_LIST);
                };

external_declaration: function_definition {
                            $$ = $<ast>1;
                    } | declaration {
                            $$ = $<ast>1;
                    };

function_definition: function_prototype compound_statement {
                           $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2},
                                                 "function definition");
                   };

function_prototype: function_name function_args function_type {
                           $$ = LLCCEP_SiHi::ast({$<ast>1, $<ast>2, $<ast>3},
                                                 "function prototype",
                                                 FUNCTION_SIGNATURE);
                  };

function_name: FUNCTION ID {
	             $$ = LLCCEP_SiHi::ast({},
                                           $<string>2,
	  	  	                   ID);
	     };

function_args: {
	             $$ = LLCCEP_SiHi::ast({}, 
					   "Function arguments",
                                           FUNCTION_ARGUMENTS);
             } | '(' ')' {
                     $$ = LLCCEP_SiHi::ast({},
                                           "Function arguments",
                                           FUNCTION_ARGUMENTS);
             } | '(' parameter_type_list ')' {
                     $$ = LLCCEP_SiHi::ast({$<ast>2},
                                           "Function arguments",
                                           FUNCTION_ARGUMENTS);
             };

function_type: {
	             $$ = LLCCEP_SiHi::ast({},
                                           "empty",
                                           EMPTY);
             } | ARROW type_specifier {
                     $$ = $<ast>2;
             };
%%

int main()
{
	yyin = stdin;
	yyparse();

	builtSyntaxTree.dumpImage("out.gv");

	return 0;
}
