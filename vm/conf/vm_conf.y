%{
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "section.h"

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
	section_declaration {$$ = section_list_init()}
	| section_declaration_list section_declaration
          {$$ = $1 = section_list_append($1, $2)};

section_declaration:
	NAME ':' value {$$ = section_field_init(
	                             extract_field_t($<str>1),
	                             field_val_make($<str>3));};

value:
	SIZE {$$ = $<str>1}
	| NUMBER {$$ = $<str>1}
	| path {$$ = $<str>1};

path:
	'"' NAME '"' {$$ = $<str>2};
%%

int yylex(void)
{
	
}
