%option prefix="vm_conf_"
%option yylineno;
size_sub[bkmgBKMG]
char[0-9a-zA-Z\/\\!@#$%^&*()\-\+'~<>\.,|{}'\"_:]
digit[0-9]

%{
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

{alpha}+ RET(NAME);

({digit}+{size_sub}) RET(SIZE);
{digit}+ RET(NUMBER);

{size_sub} RET(*yytext);

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
	for (unsigned i = 0; yytext[i] && yytext[i] != '\n'; i++)
}

void update(void)
{
	for (unsigned i = 0; yytext[i]; i++) {
		switch (yytext[i]) {
		case '\n':
			pos = 0;
			yylineno++;
			break;

		case '\t':
			pos += 8;
			break;

		default:
			pos++;
		}
	}
}

int yywrap(void)
{
	return 1;
}
