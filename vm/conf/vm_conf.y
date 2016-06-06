%code requires {
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#include <list.h>

#include "section.h"
#include "reader.h"

struct unidirected_list *configuration_file_data;

#define YY_(val) ((char const *)val)

int yylex(void);
int yyerror(char const *str);

size_t yycharno = 0;
char yyfilename[PATH_MAX] = "";

#define MSG(fmt, ...) \
({\
	char *__str__ = calloc(1, 1024);\
	sprintf(__str__, fmt, ##__VA_ARGS__);\
	__str__;\
})

#define ERROR(fmt, ...) \
({\
	char *str = MSG(fmt, ##__VA_ARGS__);\
	yyerror(str);\
	free(str);\
});

#define REMOVE(val) free((void *)val);
}

%union {
	struct section sect;
	struct section_field field;

	struct unidirected_list *sects;
	struct unidirected_list *fields;

	char *string;
}

%token <string> NAME SIZE NUMBER LITERAL

%type <sects> section_list main
%type <sect> section
%type <fields> section_declaration_list
%type <field> section_declaration
%type <string> value path

%start main

%%
main:
	section_list {
		configuration_file_data = $$ = $1;
	};

section_list:
	section {
		$$ = unidirected_list_insert_head(0, &$1);
	} | section_list section {
		$$ = unidirected_list_insert_head($1, &$2);
	};

section:
	'(' NAME ')' '{' section_declaration_list '}' {
		if (($$.type = get_section_type($2)) == SECT_T_INVALID)
			ERROR("Invalid '%s' section!\n", $2);

		$$.fields = $5;

		REMOVE($2)
	};

section_declaration_list:
	| section_declaration {
		$$ = unidirected_list_insert_head(0, &$1);
	} | section_declaration_list section_declaration {
		$$ = unidirected_list_insert_head($1, &$2);
	};

section_declaration:
	NAME ':' value {
		if (($$.type = get_field_type($1)) == SECT_FIELD_T_INVALID)
			ERROR("Invalid '%s' field!\n", $1);

		strcpy($$.str, $3);

		REMOVE($1)
		REMOVE($3)
	};

value:
	SIZE {
		$$ = $1;
	} | NUMBER {
		$$ = $1;
	} | path {
		$$ = $1;
	};

path:
	LITERAL {
		$$ = $1;
	};
%%

int yyerror(char const *str)
{
	fprintf(stderr, "%s:%d:%zu:\n%s\n",
	        yyfilename, yylineno, yycharno, str);

}
