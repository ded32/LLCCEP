%option yylineno
%option noyywrap

size_sub[bkmgBKMG]
digit[0-9]
alpha[a-zA-Z]

%{
#ifndef LEXER_H
#define LEXER_H

#include "parser.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#if defined(__linux__)
#include <linux/limits.h>
#endif

void forbidden(void);
void skip(void);
void update(void);

#define RET(val) \
{\
	update(); \
	if (val > 255) \
		yylval.string = strdup(yytext); \
	\
	return val; \
};
%}

str {char}+

%%
# skip();
\n {yylineno++; yycharno = 0;}
[ \t\r] update();

"("  RET('(');
")"  RET(')');
"{"  RET('{');
"}"  RET('}');
"\"" RET('"');
":"  RET(':');

\"(\\.|[^\\"])*\"    RET(LITERAL);

{alpha}+             RET(NAME);
({digit}+{size_sub}) RET(SIZE);
{digit}+             RET(NUMBER);

<<EOF>> yyterminate();

[.] forbidden();
%%

void forbidden(void)
{
	char str[32] = "";
	sprintf(str, "Forbidden character: '%c'", *yytext);
	yyerror(str);
}

void skip(void)
{
	for (unsigned i = 0; yytext[i] && yytext[i] != '\n'; i++);
}

void update(void)
{
	for (unsigned i = 0; yytext[i]; i++) {
		if (yytext[i] == '\t')
			yycharno += 8;
		else
			yycharno++;
	}
}

#endif // LEXER_H
