%{
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define YY_(val) ((char const *)val)

int yylex(void);
int yyerror(char const *str);

size_t pos = 0;
%}

%union {
	struct section *sect;
	struct section_field *field;
	char const *str;
}

%token <str> NAME SIZE NUMBER;

%type <sect> section_list section
%type <field> section_declaration_list section_declaration
%type <str> value path
%%
section_list:
	section {$$ = $1}
	| section_list section};

section:
	'(' NAME ')' '{' section_declaration_list '}';

section_declaration_list:
	section_declaration
	| section_declaration_list section_declaration;

section_declaration:
	NAME ':' value;

value:
	SIZE
	| NUMBER
	| path;

path:
	'"' NAME '"';
%%

int yylex(void)
{
	
}
