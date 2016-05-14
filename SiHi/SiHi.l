digit [0-9]
alpha [a-zA-Z]

%{
#include <stdio.h>
#include <stdlib.h>

#include "SiHi_parser.hpp"

#define RET(VAL)  {update_pos(); return VAL;};

enum comment_type {
        COMMENT_T_SINGLELINE,
        COMMENT_T_MULTILINE
};

void forbidden_char(void);
void update_pos(void);
void skip_comment(enum comment_type type);
int yywarp(void);
%}

%%
"\n" yylineno++;
[ \t\n\r] update_pos();

"#force_compiler_exit" exit(EXIT_SUCCESS);

"{" RET('{');
"}" RET('}');
"(" RET('(');
")" RET(')');
";" RET(';');
":" RET(':');

"+" RET('+');
"-" RET('-');
"*" RET('*');
"/" RET('/');
"%" RET('%');
"=" RET('=');
"!" RET('!');
"~" RET('~');
"&" RET('&');

switch   RET(SWITCH);
case     RET(CASE);
default  RET(DEFAULT);
while    RET(WHILE);
do       RET(DO);
for      RET(FOR);
continue RET(CONTINUE);
break    RET(BREAK);
if       RET(IF);
else     RET(ELSE);
goto     RET(GOTO);
return   RET(RETURN);

void  RET(VOID);
real  RET(REAL);
bool  RET(BOOL);

"<=" RET(OP_CMP_LE);
">=" RET(OP_CMP_AE);
"==" RET(OP_CMP_EQ);
"!=" RET(OP_CMP_NE);

"++" RET(OP_INC);
"--" RET(OP_DEC);

"<<"  RET(OP_OFFSET_L);
">>"  RET(OP_OFFSET_R);
"<<=" RET(OP_OFFSET_L_EQ);
">>=" RET(OP_OFFSET_R_EQ);

"+=" RET(OP_ADD_EQ);
"-=" RET(OP_SUB_EQ);
"*=" RET(OP_MUL_EQ);
"/=" RET(OP_DIV_EQ);
"%=" RET(OP_MOD_EQ);

"&=" RET(OP_AND_EQ);
"|=" RET(OP_OR_EQ);
"^=" RET(OP_XOR_EQ);

typedef RET(TYPEDEF);
extern  RET(EXTERN);
static  RET(STATIC);
auto    RET(AUTO);

struct RET(STRUCT);
union  RET(UNION);
enum   RET(ENUM);

"..." RET(MANY_DOTS);
"->"  RET(PTR_ACS);

"//" skip_comment(COMMENT_T_SINGLELINE);
"/*" skip_comment(COMMENT_T_MULTILINE);

{digit}+(.{digit}+)? RET(VAL);
({alpha}|"_")({alpha}|{digit}|"_")* RET(ID);
\"(\\.|[^\\"])*\" RET(LITERAL);

. forbidden_char();
%%

void forbidden_char(void)
{
	char str[32] = "";
	sprintf(str, "Forbidden character \'%c\'", *yytext);

	yyerror(str);
}

void update_pos(void)
{
	unsigned i;
	for (i = 0; yytext[i]; i++) {
		if (yytext[i] == '\n')
			pos_x = 0;
		else if (yytext[i] == '\t')
			pos_x += 8;
		else
			pos_x++;
	}
}

void skip_comment(enum comment_type type)
{
/*
	char tmp = 0;
	char tmp1 = 0;

	if (type == COMMENT_T_SINGLELINE) {
		return;
	} else if (type == COMMENT_T_MULTILINE) {
		do {
			//tmp = ();
			//tmp1 = input();
		} while (tmp && tmp1 && (tmp != '*' || tmp1 != '/'));
	}
*/
}

int yywrap(void)
{
	return 1;
}
