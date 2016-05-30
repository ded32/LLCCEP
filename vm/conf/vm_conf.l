size_sub[bkmgBKMG]
alpha[a-zA-Z]
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

%%
#         skip();
[ \t\n\r] update();

"(" RET('(');
")" RET(')');

"{" RET('{');
"}" RET('}');

{alpha}+ RET(NAME);

({digit}+{size_sub}) RET(SIZE);
{digit}+ RET(DIGIT);

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
			pos.charno = 0;
			pos.lineno++;
			break;

		case '\t':
			pos.charno += 8;
			break;

		default:
			pos.charno++;
		}
	}
}

int yywrap(void)
{
	return 1;
}
