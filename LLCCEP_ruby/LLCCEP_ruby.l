letter [a-zA-Z]
digit [0-9]

%{
#include <stddef.h>

static void update(void);
#define RET(val) ({update(); return (val);})
%}

%%
{digit}+                                {RET(INT);}
{digit}*'.'{digit}+                     {RET(FLOAT);}
({letter}|"_")({letter}|{digit}|"_")    {RET(ID);}
"$"({letter}|"_")({letter}|{digit}|"_") {RET(GLOB_ID);}
({letter}|"_")({letter}|{digit}|"_")[?] {RET(FUNC_ID);}

"#"[.]*             {update();}
'='begin(.*)?'='end {update();}
[ \n\r\t]           {update();}

"\""("\\\""|[^\n\r])*"\"" {RET(LITERAL);}

"," {RET(COMMA);}
";" {RET(SEMICOLON);}

require {RET(REQUIRE);}
end     {RET(END);}
def     {RET(DEF);}
return  {RET(RETURN);}
pir     {RET(PIR);}

if     {RET(IF);}
else   {RET(ELSE);}
elsif  {RET(ELSIF);}
unless {RET(UNLESS);}
while  {RET(WHILE);}
retry  {RET(RETRY);}
break  {RET(BREAK);}
for    {RET(FOR);}

true  {RET(TRUE);}
false {RET(FALSE);}
nil   {RET(NIL);}

"+"  {RET('+');}
"-"  {RET('-');}
"*"  {RET('*');}
"/"  {RET('/');}
"%"  {RET('%');}
"**" {RET(EXP);}

"==" {RET(EQUAL);}
"!=" {RET(NOT_EQUAL);}
"<"  {RET('<');}
'>'  {RET('>');}
"<=" {RET(LESS_EQUAL);}
">=" {RET(ABOVE_EQUAL);}

"="   {RET(ASSIGN);}
"+="  {RET(ADD);}
"-="  {RET(SUB);}
"*="  {RET(MUL);}
"/="  {RET(DIV);}
"%="  {RET(MOD);}
"**=" {RET(EXP_ASSIGN);}

"&" {RET(BIT_AND);}
"|" {RET(BIT_OR);}
"^" {RET(XOR);}
"~" {RET(BIT_NOT);}
"<<" {RET(BIT_SHL);}
">>" {RET(BIT_SHR);}

and|"&&" {RET(AND);}
or|"||"  {RET(OR);}
not|"!"  {RET(NOT);}

"(" {RET('(');}
")" {RET(')');}
"[" {RET('[');}
"]" {RET(']');}
%%

static void update(void)
{
	for (size_t i = 0; yytext[i]; i++) {
		switch (yytext[i]) {
		case '\n':
		case '\r':
			yycharno = 0;
			break;

		case '\t':
			yycharno += 8;
			break;

		default:
			yycharno++;
		}
	}
}
