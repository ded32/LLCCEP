%{
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <list.h>

#include "section.h"

#define YY_(val) ((char const *)val)

int yylex(void);
int yyerror(char const *str);

size_t yycharno = 0;
char yyfilename[PATH_MAX] = "";
%}

%union {
	struct section sect;
	struct section_field field;

	struct unidirected_list *sects;
	struct unidirected_list *fields;
	char const *string;
}

%token <string> NAME SIZE NUMBER;

%type <sects> section_list
%type <sect> section
%type <fields> section_declaration_list
%type <field> section_declaration
%type <string> value path

%start section_list

%%
section_list:
	section {$$ = unidirected_list_init(&$<sect>1);}
	| section_list section {$$ = unidirected_list_insert_head($<sects>1, &$<sect>2);};

section:
	'(' NAME ')' '{' section_declaration_list '}' {$$ = {.type = get_section_type($<string>2), .fields = $<fields>5};};

section_declaration_list:
	section_declaration {$$ = unidirected_list_init(&$<field>1);}
	| section_declaration_list section_declaration {$$ = unidirected_list_insert_head($<fields>1, &$<field>2);};

section_declaration:
	NAME ':' value {$$ = {get_section_type($<string>1), $<string>3};};

value:
	SIZE {$$ = $<string>1;}
	| NUMBER {$$ = $<string>1;}
	| path {$$ = $<string>1;};

path:
	'"' NAME '"' {$$ = $<string>2;};
%%

int yyerror(char const *str)
{
	fprintf(stderr, "%s:%d:%d:\n%s\n"
	                "%s\n",
	        yyfilename, yylineno, yycharno, str, yytext);

	return 0;
}

int main(void)
{
	yyin = stdin;
	strcpy(yyfilename, "stdin");

	yyparse();

	return 0;
}
