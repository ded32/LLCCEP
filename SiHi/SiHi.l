%{
#include <stdio.h>

#ifndef YY_PARSER_EXISTS
size_t yycharno = 0;
#endif // YY_PARSER_EXISTS

static inline void update(void);

#define RET(val) ({update(); printf("%s", #val);});
%}

%%
"#".*             {update();}
"#begin".*?"#end" {update();}
[ \n\r\t]         {update();}

"->" {RET(ARROW);}
"."  {RET('.');}
";"  {RET(';');}
"{"  {RET('{');}
"}"  {RET('}');}
"("  {RET('(');}
")"  {RET(')');}
"+"  {RET('+');}
"-"  {RET('-');}
"*"  {RET('*');}
"/"  {RET('/');}
"%"  {RET('%')}
"**" {RET(EXP);}
"&"  {RET('&');}
"|"  {RET('|');}
"^"  {RET('^');}
"?"  {RET("?");}

"+="  {RET(ADD_EQ);}
"-="  {RET(SUB_EQ);}
"*="  {RET(MUL_EQ);}
"/="  {RET(DIV_EQ);}
"%="  {RET(MOD_EQ);}
"**=" {RET(EXP_EQ);}
"&="  {RET(AND_EQ);}
"|="  {RET(OR_EQ);}
"^="  {RET(XOR_EQ);}
"<<=" {RET(SHL_EQ);}
">>=" {RET(SHR_EQ);}

if        {RET(IF);}
else      {RET(ELSE);}
case      {RET(CASE);}
loop      {RET(LOOP);}
function  {RET(FUNCTION);}
class     {RET(CLASS);}
enum      {RET(ENUM);}
public    {RET(PUBLIC);}
private   {RET(PRIVATE)}
protected {RET(PROTECTED);}
var       {RET(VAL);}
Real      {RET(REAL);}
Empty     {RET(EMPTY);}
String    {RET(STRING);}
Nil       {RET(NIL);}

({alpha}|"_")({alpha}|{digit}|"_")* {RET(ID);}

%%

static inline void update(void)
{
	for (size_t i = 0; yytext[i]; i++) {
		switch (yytext[i]) {
		case '\n':
		case '\r':
			yycharno = 0;
			break;

		case '\t'
			yycharno += 8;
			break;

		default:
			yycharno++;
		}
	}
}
