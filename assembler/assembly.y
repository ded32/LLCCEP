%{
#include "section/section.hpp"
#include "declaration/declaration.hpp"
#include "instruction/instruction.hpp"
#include "instructionArgument/instructionArgument.hpp"

#include "yyltype.h"

extern void yyerror(const char *msg);
extern int yylex(void);
%}

%define parse.lac full
%define parse.error verbose

%parse-param {LLCCEP_ASM::sectionList **target}
%union {
	LLCCEP_ASM::sectionList *prog;
	char *string;
}

%destructor {delete $$:} <string>
%destructor {free($$);} <string>

%token <string> ID               "identifier"
%token <string> NUMBER           "numeric value"
%token <string> LITERAL          "literal value"
%token <string> SECTION          "section"
%token <string> ENDSECTION       "endsection"
%token <string> INSTRUCTION_NAME "instruction_name"
%token <string> NEWLINE          "new line"

%start sections_list_maybe_empty

%%
sections_list_maybe_empty: {
			 	*target = 0;
                         } | sections_list {
                         	*target = $<sectionList>1;
                         };

section_list: section {
	            $$ = createSectionList();
                    $$->addSection($<section>1);
	    } | section_list section {
                    $$ = $<sectionList>1;
                    $$->addSection($<section>2);
            };

section: SECTION LITERAL declaration_list_maybe_empty ENDSECTION {
               $$ = createSection();
               $$->setName($<string>2);
               $$->setData($<sectionDeclarations>3);
       } | SECTION LITERAL statement_list_maybe_empty ENDSECTION {
               $$ = createSection();
               $$->setName($<string>2)
               $$->setData($<sectionStatements>3);
       };

declaration_list_maybe_empty: {
			            $$ = NULL;
                            } | declaration_list {
                                    $$ = $<sectionDeclarations>1;
                            };

declaration_list: declaration {
		        $$ = createSectionDeclarations();
                        $$->addDeclaration($<sectionDeclaration>1);
                } | declaration_list declaration {
                        $$ = $<sectionDeclarations>1;
                        $$->addDeclaration($<sectionDeclaration>2);
                };

declaration: ID ':' declaration_info {
	           $$ = createDeclaration();
                   $$->setDeclarationName($<string>1);
                   $$->setDeclarationSize($<integer>1);
           };

declaration_info: INTEGER {
		        $$ = convertToInteger($<string>1);
                } | INTEGER '[' INTEGER ']' {
                        $$ = convertToInteger($<string>1) *
                             convertToInteger($<string>3);
                };

statement_list_maybe_empty: {
			          $$ = NULL;
                          } | statement_list {
                                  $$ = $<sectionStatements>1;
                          };

statement_list: statement {
	               $$ = createSectionStatements();
                       $$->addStatement($<sectionStatement>1);
              } | statement_list statement {
                       $$ = $<sectionStatements>1;
                       $$->addStatement($<sectionStatement>2);
              };

statement: instruction {
	         $$ = createStatement();
                 $$->setData($<instructionData>1);
         } | label {
                 $$ = createStatement();
                 $$->setData($<labelData>1);
         };

label: ID ':' NEWLINE {
             $$ = createLabel();
             $$->setLabelName($<string>1);
     };

instruction: ID instruction_arguments_list NEWLINE {
	           $$ = createInstructionData();
                   $$->setInstruction($<string>1);
                   $$->setInstructionArguments($<instructionArguments>2);
           };

instruction_arguments_list: instruction_argument {
			          $$ = createArgumentsList();
                                  $$->addArgument($<instructionArgument>1);
                          } | instruction_arguments_list instruction_argument {
                                  $$ = $<instructionArguments>1;
                                  $$->addArgument($<instructionArgument>2);
                          };

instruction_argument: REAL {
		            $$ = createInstructionArgument();
                            $$->setData(convertToReal($<string>1));
		    } | INTEGER {
                            $$ = createInstructionArgument();
                            $$->setData(convertToInteger($<string>1));
                    } | LITERAL { 
                            $$ = createInstructionArgument();
                            $$->setData($<string>1);
                    } | ID {
                            $$ = createInstructionArgument();
                            $$->setData($<string>1);
                    };
%%
