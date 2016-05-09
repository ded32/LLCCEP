digit [0-9]
alpha [a-zA-Z]

%{
#include <stdio.h>
%}

%%
void printf("VOID");
real printf("REAL");

loop printf("LOOP");
do   printf("DO");
if   printf("IF");
else printf("ELSE");

import printf("IMPORT");

var  printf("VAR");
func printf("FUNC");

and  printf("AND");
or   printf("OR");
xor  printf("XOR");

{digit}+("."{digit}+)?              printf("NUM");
({alpha}|"_")({alpha}|{digit}|"_")* printf("ID");

"{" printf("OBB");
"}" printf("CBB");

"[" printf("OAB");
"]" printf("CAB");
"(" printf("OSB");
")" printf("CSB");

"," printf("COMMA");
";" printf("SEMICOLON");
":" printf("COLON");

"="  printf("EQ");
"**" printf("POW");
"+"  printf("PLUS");
"-"  printf("MINUS");
"*"  printf("ASTERISK");
"/"  printf("SLASH");

"<" printf("LESS");
"<=" printf("LESSEQ");
">" printf("MORE");
">=" printf("MORERQ");
"==" printf("EQEQ");
"!=" printf("NOTEQ");

"\n" yylineno++;
%%
