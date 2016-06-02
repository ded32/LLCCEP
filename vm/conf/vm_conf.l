size_sub[bkmgBKMG]
char[0-9a-zA-Z\/\\!@#$%^&*()\-\+'~<>\.,|{}'\"_:]
digit[0-9]
alpha[a-zA-Z]

%{
#include "parser.h"

#include <stdio.h>
#include <stdlib.h>

void forbidden(void);
void skip(void);
void update(void);
int yywrap(void);

#define RET(val) {update(); return val;};
%}

str {char}+

%%
#         skip();
[ \t\n\r] update();

"("  RET('(');
")"  RET(')');
"{"  RET('{');
"}"  RET('}');
"\"" RET('"');
":"  RET(':');

{size_sub} RET(*yytext);

{alpha}+ RET(NAME);

({digit}+{size_sub}) RET(SIZE);
{digit}+ RET(NUMBER);


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
		switch (yytext[i]) {
		case '\n':
			yycharno = 0;
			yylineno++;
			break;

		case '\t':
			yycharno += 8;
			break;

		default:
			yycharno++;
		}
	}
}

int yywrap(void)
{
	return 1;
}
