digit [0-9]
alpha [a-zA-Z]

%{
#include <stdio.h>
#include "y.tab.c"

#define RET(VAL)  {update_pos(); return VAL;};

enum comment_type {
        COMMENT_T_SINGLELINE,
        COMMENT_T_MULTILINE
};

unsigned posX = 0;

void update_pos(void);
void skip_comment(enum comment_type type);
int yywarp(void);
%}

%%
"\n" yylineno++;

"{" RET('{');
"}" RET('}');
"(" RET('(');
")" RET(')');
";" RET(';');

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
true  RET(TRUE);
false RET(FALSE);

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
%%

void update_pos(void)
{
	unsigned i;
	for (i = 0; yytext[i]; i++) {
		if (yytext[i] == '\n')
			posX = 0;
		else if (yytext[i] == '\t')
			posX += 8;
		else
			posX++;
	}
}

void skip_comment(enum comment_type type)
{
	char chr = 0;
	char chr1 = 0;

	if (type == COMMENT_T_SINGLELINE)
		while ((chr = input()) && chr != '\n');
	else if (type == COMMENT_T_MULTILINE) {
		while (chr = input() && chr != '*') {
			if (!(chr1 = input()))
				yyerror("sudden end after comment");
			else if (chr1 == '/')
				break;
		}
	}
}

int yywrap(void)
{
	return 1;
}
