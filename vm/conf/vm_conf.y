%{
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <list.h>

#include "./section.h"
#include "./reader.h"

struct undirected_list *configuration_file_data;

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

%token <string> NAME SIZE NUMBER
%token <string> SIZE_SUBSCRIPT LITERAL

%type <sects> section_list main
%type <sect> section
%type <fields> section_declaration_list
%type <field> section_declaration
%type <string> value path

%start main

%%
main:
	section_list {configuration_file_data = $$ = $<sects>1;};

section_list:
	section {$$ = unidirected_list_init(&$<sect>1);}
	| section_list section {$$ = unidirected_list_insert_head($<sects>1, &$<sect>2);};

section:
	'(' NAME ')' '{' section_declaration_list '}' {$$.type = get_section_type($<string>2); $$.fields = $<fields>5;};

section_declaration_list:
	| section_declaration {$$ = unidirected_list_init(&$<field>1);}
	| section_declaration_list section_declaration {$$ = unidirected_list_insert_head($<fields>1, &$<field>2);};

section_declaration:
	NAME ':' value {$$;};

value:
	SIZE {$$ = $<string>1;}
	| NUMBER {$$ = $<string>1;}
	| path {$$ = $<string>1;};

path:
	LITERAL {$$ = $<string>1;};
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
	strcpy(yyfilename, "stdin");
	yyin = stdin;

	yyparse();

	undirected_list_delete(configuration_file_data);

	return 0;	
}

