/*Default C code*/

%{
#include <stdio.h>
#include <stdlib.h>

//extern FILE *fp;
%}

/* Tokens */
%token VOID REAL                /* Data types */
%token LOOP DO IF ELSE          /* Main language constructions */
%token NUM ID                   /* number & name token types */
%token IMPORT                   /* importing files: preprocessor feature */
%token OBB CBB OAB CAB OSB CSB  /* Braces */
%token COMMA SEMICOLON COLON    /* Misc */
%token VAR FUNC                 /* data */

/* Right - asocciated operators */
%right EQ

/* Left - associated operators */
%left AND OR XOR POW PLUS MINUS ASTERISK SLASH
%left LESS LESSEQ MORE MOREEQ EQEQ NOTEQ

%%
TYPE: VOID
    | REAL;

TYPE_CONV: TYPE OSB VAL CSB
	 | TYPE OSB CSB;

VAR_DECL: VAR ID COLON TYPE COMMA VAR_DECL
        | VAR ID COLON TYPE;

%%
