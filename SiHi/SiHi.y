/**************************************************
 * SiHi parser source code
 *
 * Author: Andrew Bezzubtsev
 * Date: 31/08/2016
 * File: SiHi.y
 * Bison version required: 3.0 or later
 *
 * This file contains grammatic and semantic rules
 * needed to build AST, which can be dumped or
 * translated into assembly/bytecode.
 *************************************************/

%{
#include <string>
#include "yyltype.h"
#include "ast/ast.hpp"

/**************************************************
 * Intermodular functions
 *************************************************/
extern void yyerror(LLCCEP_SiHi::ast **, const char *msg);
extern int yylex(void);
%}

/**************************************************
 * Bison defines to get more detailed
 * errors' messages
 *************************************************/
%define parse.lac full
%define parse.error verbose

/**************************************************
 * Add to parser parameters pointer to place,
 * where to put pointer to generated AST.
 *************************************************/
%parse-param {LLCCEP_SiHi::ast **ast}

/**************************************************
 * Lexem's or rule's value now is:
 * a) AST pointer
 * b) pointer to buffer, synthezed by scanner
 *************************************************/
%union {
	::LLCCEP_SiHi::ast *ast;
	char *string;
}

/**************************************************
 * Release buffer, synthezed by scanner on lexem
 * destruction
 *************************************************/
%destructor {free($$);} <string>

/**************************************************
 * Tokens, can be read by scanner and their
 * human-native string literal representation
 *************************************************/
%token <string> ID               "identifier"
%token <string> NUMBER           "numeric value"
%token <string> LITERAL          "literal value"
%token <string> ARROW            "->"
%token <string> INCREMENT        "++"
%token <string> DECREMENT        "--"
%token <string> REINTERPRET_CAST "reinterpret_cast"
%token <string> SHL              "<<"
%token <string> SHR              ">>"
%token <string> LESS_EQUAL       "<="
%token <string> ABOVE_EQUAL      ">="
%token <string> EQUALS           "=="
%token <string> NOT_EQUALS       "!="
%token <string> MUL_ASSIGN       "*="
%token <string> DIV_ASSIGN       "/="
%token <string> MOD_ASSIGN       "%="
%token <string> ADD_ASSIGN       "+="
%token <string> SUB_ASSIGN       "-="
%token <string> SHL_ASSIGN       "<<="
%token <string> SHR_ASSIGN       ">>="
%token <string> AND_ASSIGN       "&="
%token <string> XOR_ASSIGN       "^="
%token <string> OR_ASSIGN        "|="
%token <string> EMPTY            "empty"
%token <string> REAL             "real"
%token <string> STRING           "string"
%token <string> OTHER            "other"
%token <string> PASS             "pass"
%token <string> IF               "if"
%token <string> ELSE             "else"
%token <string> CASE             "case"
%token <string> WHILE            "while"
%token <string> DO               "do"
%token <string> FOR              "for"
%token <string> JUMP             "jump"
%token <string> NEXT             "next"
%token <string> STOP             "stop"
%token <string> RETURN           "return"
%token <string> DONE             "done"
%token <string> UNLESS           "unless"
%token <string> VARARG           "vararg"
%token <string> FUNCTION         "function"
%token <string> CLASS            "class"
%token <string> TYPEALIAS        "typealias"
%token <string> BACKARROW        "<-"
%token <string> PUBLIC           "public"
%token <string> PRIVATE          "private"
%token <string> PROTECTED        "protected"
%token <string> STATIC           "static"
%token <string> RELEASE          "release"
%token <string> TRY              "try"
%token <string> CATCH            "catch"
%token <string> FINALLY          "finally"
%token <string> THROW            "throw"
%token <string> ASM              "asm"

/**************************************************
 * Each rule generates AST node of lexems, given to
 * it, so all they should by typed as <ast>
 *************************************************/
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
%type <ast> statement releasement_statement labeled_statement compound_statement declaration_statement
%type <ast> declaration_statement_optional_semicolon declaration_statement_list 
%type <ast> expression_statement branched_statement looped_statement jump_statement 
%type <ast> translation_unit external_declaration function_definition function_signature 
%type <ast> function_name function_args function_type labeled_statement_list
%type <ast> class_declaration classname predecessor class_body method_property_list
%type <ast> method_property access_rule_optional_static access_rule
%type <ast> declaration_optional_semicolon statement_optional_semicolon
%type <ast> exception_handling_statement exception_throw_statement

/**************************************************
 * Start AST generation from 'translation_unit'
 * rule.
 *************************************************/
%start translation_unit

%%
primary_expression: ID {
                            $$ = createAst{createLexem{$<string>1, ID}};
                    } | NUMBER {
                            $$ = createAst{createLexem{$<string>1, NUMBER}};
                    } | LITERAL {
                            $$ = createAst{createLexem{$<string>1, LITERAL}};
                    } | '(' expression ')' {
                            $$ = $<ast>2;
                    };

postfix_expression: primary_expression {
                            $$ = $<ast>1;
	            } | postfix_expression '[' expression ']' {
                            $$ = createAst{POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS_LEXEM, {$<ast>1, $<ast>3}};
                    } | postfix_expression '(' ')' {
                            $$ = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {$<ast>1}};
		    } | postfix_expression '(' argument_expression_list ')' {
                            $$ = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {$<ast>1, $<ast>3}};
                    } | postfix_expression '.' ID {
                            $$ = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_LEXEM, {$<ast>1, createAst{createLexem{$<string>3, ID}}}};
                    } | postfix_expression ARROW ID {
                            $$ = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR_LEXEM, {$<ast>1, createAst{createLexem{$<string>3, ID}}}};
                    } | postfix_expression INCREMENT {
                            $$ = createAst{POSTFIX_EXPRESSION_INCREMENT_LEXEM, {$<ast>1}};
                    } | postfix_expression DECREMENT {
                            $$ = createAst{POSTFIX_EXPRESSION_DECREMENT_LEXEM, {$<ast>1}};
                    };

argument_expression_list: assignment_expression {
                                $$ = createAst{ARGUMENT_EXPRESSION_LIST_LEXEM, {$<ast>1}};
                        } | argument_expression_list ',' assignment_expression {
                                $$ = $<ast>1;
                                $$->addChild($<ast>3);
                        };

unary_expression: postfix_expression {
                        $$ = $<ast>1;
                } | unary_operator cast_expression {
                        $$ = $<ast>1;
                        $$->addChild($<ast>2);
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
                       $$ = $<ast>1;
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
	              $$ = $<ast>1;
	      } | and_expression '&' equality_expression {
                      $$ = createAst{AND_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
              };

exclusive_or_expression: and_expression {
		               $$ = $<ast>1;
  	               } | exclusive_or_expression '^' and_expression {
                               $$ = createAst{EXCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
                       };

inclusive_or_expression: exclusive_or_expression {
		               $$ = $<ast>1;
 	               } | inclusive_or_expression '|' exclusive_or_expression {
                               $$ = createAst{INCLUSIVE_OR_EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
                       };

conditional_expression: inclusive_or_expression {
		              $$ = $<ast>1;
	              } | inclusive_or_expression DONE expression UNLESS conditional_expression { 
                              $$ = createAst{CONDITIONAL_EXPRESSION_LEXEM, {$<ast>1, $<ast>3, $<ast>5}};
                      };

assignment_expression: conditional_expression {
		             $$ = $<ast>1;
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
	          $$ = $<ast>1;
  	  } | expression ',' assignment_expression {
                  $$ = createAst{EXPRESSION_LEXEM, {$<ast>1, $<ast>3}};
          };

constant_expression: conditional_expression {
		           $$ = $<ast>1;
		   };

declaration: declaration_specifiers init_declarator_list {
                   $$ = createAst{DECLARATION_LEXEM, {$<ast>1, $<ast>2}}; 
           };
 
declaration_specifiers: type_specifier {
		              $$ = $<ast>1;
		      };

init_declarator_list: init_declarator {
		            $$ = createAst{INIT_DECLARATOR_LIST_LEXEM, {$<ast>1}};
	            } | init_declarator_list ',' init_declarator {
                            $$ = $<ast>1;
                            $$->addChild($<ast>2);
                    };

init_declarator: declarator {
	               $$ = $<ast>1;
	       } | declarator '=' initializer {
                       $$ = createAst{INIT_DECLARATOR_LEXEM, {$<ast>1, $<ast>3}};
               };

type_specifier: EMPTY {
	              $$ = createAst{createLexem{$<string>1, EMPTY}};
   	      } | REAL {
                      $$ = createAst{createLexem{$<string>1, REAL}};
	      } | STRING {
                      $$ = createAst{createLexem{$<string>1, STRING}};
	      } | ID {
                      $$ = createAst{createLexem{$<string>1, ID}};
              };

declarator: pointer direct_declarator {
	          $$ = createAst{DECLARATOR_LEXEM, {$<ast>1, $<ast>2}};
	  } | direct_declarator {
                  $$ = $<ast>1;
          };

direct_declarator: ID {
		         $$ = createAst{createLexem{$<string>1, ID}};
 	         } | '(' declarator ')' {
                         $$ = createAst{DIRECT_DECLARATOR_SCOPED_LEXEM, {$<ast>2}};
                 } | direct_declarator '[' constant_expression ']' {
                         $$ = createAst{DIRECT_DECLARATOR_ARRAYED_LEXEM, {$<ast>1, $<ast>3}};
                 } | direct_declarator '[' ']' {
                         $$ = createAst{DIRECT_DECLARATOR_AUTO_ARRAYED_LEXEM, {$<ast>1}};
	         } | direct_declarator '(' parameter_type_list ')' {
                         $$ = createAst{DIRECT_DECLARATOR_PARAMETERS_LIST_LEXEM, {$<ast>1, $<ast>3}};
                 } | direct_declarator '(' identifier_list ')' {
                         $$ = createAst{DIRECT_DECLARATOR_IDENTIFIERS_LIST_LEXEM, {$<ast>1, $<ast>3}};
	         };

pointer: '*' {
                 $$ = createAst{POINTER_LEXEM};
       } | '*' pointer {
                 $$ = createAst{POINTER_LEXEM, {$<ast>2}};
       };


parameter_type_list: {
		           $$ = createAst(PARAMETER_TYPE_LIST_LEXEM, {});
		   } | parameter_list {
                           $$ = $<ast>1;
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
                 $$ = $<ast>1;
         };

abstract_declarator: pointer {
		           $$ = $<ast>1;
 	           } | direct_abstract_declarator {
                           $$ = $<ast>1;
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
                                  $$ = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {$<ast>1}};
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
                   $$ = $<ast>1;
           } | '{' initializer_list '}' {
                   $$ = $<ast>2;
           };

initializer_list: initializer {
                        $$ = createAst{INITIALIZER_LIST_LEXEM, {$<ast>1}};
                } | initializer_list ',' initializer {
                        $$ = $<ast>1;
                        $$->addChild($<ast>2);
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
         } | exception_handling_statement {
                 $$ = $<ast>1;
         } | exception_throw_statement {
                 $$ = $<ast>1;
         } | releasement_statement {
                 $$ = $<ast>1;
         };

releasement_statement: RELEASE identifier_list {
		              $$ = createAst{RELEASEMENT_LEXEM, {$<ast>2}};
                     };

labeled_statement: ID ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {createAst{createLexem{$<string>1, ID}}, $<ast>3}};
                 } | constant_expression ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {$<ast>1, $<ast>3}};
                 } | OTHER ':' statement {
                         $$ = createAst{LABELED_STATEMENT_LEXEM, {$<ast>3}};
                 };

compound_statement: '{' '}' {
                          $$ = 0;
                  } | '{' declaration_statement_list '}' {
                          $$ = $<ast>2;
                  };

declaration_statement: declaration {
                             $$ = $<ast>1;
                     } | statement {
                             $$ = $<ast>1;
                     };

declaration_optional_semicolon: declaration ';' {
			             $$ = $<ast>1;
                              } | declaration {
                                     $$ = $<ast>1;
                              };

statement_optional_semicolon: statement ';' {
			          $$ = $<ast>1;
                            } | statement {
                                  $$ = $<ast>1;
                            };

declaration_statement_optional_semicolon: declaration_optional_semicolon {
					        $$ = $<ast>1;
					} | statement_optional_semicolon {
                                                $$ = $<ast>1;
                                        };

declaration_statement_list: declaration_statement_optional_semicolon {
                                  $$ = createAst{DECLARATION_STATEMENT_LIST_LEXEM, {$<ast>1}};
                          } | declaration_statement_list declaration_statement_optional_semicolon {
                                  $$ = $<ast>1;
                                  $$->addChild($<ast>2);
                          };

expression_statement: PASS {
                            $$ = createAst{PASS_STATEMENT_LEXEM};
                    } | expression {
                            $$ = $<ast>1;
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
                        $$ = createAst{LOOPED_STATEMENT_LEXEM, {$<ast>2, $<ast>3, $<ast>5}};
	        } | FOR declaration_statement ';' expression_statement ';' statement statement {
                        $$ = createAst{LOOPED_STATEMENT_LEXEM, {$<ast>2, $<ast>4, $<ast>6, $<ast>7}};
                };

jump_statement: JUMP ID {
                      $$ = createAst{JUMP_STATEMENT_LEXEM, {createAst{createLexem{$<string>2, ID}}}};
              } | NEXT {
                      $$ = createAst{NEXT_STATEMENT_LEXEM};
              } | STOP {
                      $$ = createAst{STOP_STATEMENT_LEXEM};
              } | RETURN {
                      $$ = createAst{RETURN_STATEMENT_LEXEM};
	      } | RETURN expression {
                      $$ = createAst{RETURN_STATEMENT_LEXEM, {$<ast>2}};
              };

exception_handling_statement: TRY statement CATCH declaration statement {
			            $$ = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {$<ast>2, $<ast>4, $<ast>5}};
			    } | TRY statement CATCH declaration statement FINALLY statement {
                                    $$ = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {$<ast>2, $<ast>4, $<ast>5, $<ast>6}};
                            };

exception_throw_statement: THROW statement {
			         $$ = createAst{EXCEPTION_THROW_STATEMENT_LEXEM, {$<ast>2}};
			 };

translation_unit: external_declaration {
                        *ast = $$ = createAst{EXTERNAL_DECLARATION_LEXEM, {$<ast>1}};
                } | translation_unit external_declaration {
                        $$ = $<ast>1;
                        $$->addChild($<ast>2);
                };

external_declaration: function_definition {
		            $$ = $<ast>1;
                    } | declaration_optional_semicolon {
                            $$ = $<ast>1;
                    } | class_declaration {
                            $$ = $<ast>1;
                    };

function_definition: function_signature compound_statement {
                           $$ = createAst{FUNCTION_DEFINITION_LEXEM, {$<ast>1, $<ast>2}};
                   };

function_signature: function_name function_args function_type {
                           $$ = createAst{FUNCTION_SIGNATURE_LEXEM, {$<ast>1, $<ast>2, $<ast>3}};
                  };

function_name: FUNCTION ID {
	             $$ = createAst{FUNCTION_NAME_LEXEM, 
                                    {createAst{createLexem{$<string>2, ID}}}};
	     };

function_args: parameter_type_list {
	             $$ = $<ast>1;
	     } | '(' parameter_type_list ')' {
                     $$ = $<ast>2;
             };

function_type: {
	             $$ = createAst{FUNCTION_TYPE_LEXEM, {createAst{createLexem{"Empty", EMPTY}}}};
             } | ARROW type_specifier {
                     $$ = createAst{FUNCTION_TYPE_LEXEM, {$<ast>2}};
             };

class_declaration: classname predecessor class_body {
		        $$ = createAst{CLASS_DECLARATION_LEXEM, {$<ast>1, $<ast>2, $<ast>3}};
                 };

classname: CLASS ID {
	         $$ = createAst{CLASSNAME_LEXEM, {createAst{createLexem{$<string>2, ID}}}};
         };

predecessor: {
	           $$ = createAst{PREDECESSOR_LEXEM};
           } | BACKARROW ID {
	           $$ = createAst{PREDECESSOR_LEXEM, {createAst{createLexem{$<string>2, ID}}}};
           };

class_body: '{' method_property_list '}' {
	          $$ = $<ast>2;
          };

method_property_list: method_property {
		            $$ = createAst{METHOD_PROPERTY_LIST_LEXEM, {$<ast>1}};
		    } | method_property_list method_property {
                            $$ = $<ast>1;
                            $$->addChild($<ast>2);
                    };

method_property: access_rule_optional_static external_declaration {
	               $$ = createAst{METHOD_PROPERTY_LEXEM, {$<ast>1, $<ast>2}};
               };

access_rule_optional_static: STATIC access_rule {
			           $$ = $<ast>2;
                                   $$->addChild(createAst{createLexem{"static", STATIC}});
                           } | access_rule {
                                   $$ = $<ast>1;
                           };

access_rule: PUBLIC {
	           $$ = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"public", PUBLIC}}}};
           } | PROTECTED {
                   $$ = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"protected", PROTECTED}}}};
           } | PRIVATE {
                   $$ = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"private", PRIVATE}}}};
           };
%%
