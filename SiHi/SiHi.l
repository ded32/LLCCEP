alpha [a-zA-Z]
digit [0-9]

%{
#include <stdio.h>
#include <string>

#include <STDExtras.hpp>
#include <os-specific.hpp>

#include "SiHiParser.hpp"

#ifndef YY_PARSER_EXISTS
size_t yycharno = 0;
#define RET(val) ({update(); yylval.string = yytext; return val;})
#else
#define RET(val) ({update(); printf("%s", #val);})
#endif // YY_PARSER_EXISTS

static inline void update(void);
static inline void lexerIssue(const char *fmt, ...);

%}

%%
"#begin".*?"#end" {update();}
"#".*             {update();}
[ \n\r\t]         {update();}

reinterpret_cast {RET(REINTERPRET_CAST);}
Empty            {RET(EMPTY);}
Real             {RET(REAL);}
String           {RET(STRING);}
other            {RET(OTHER);}
pass             {RET(PASS);}
if               {RET(IF);}
else             {RET(ELSE);}
case             {RET(CASE);}
while            {RET(WHILE);}
do               {RET(DO);}
for              {RET(FOR);}
jump             {RET(JUMP);}
next             {RET(NEXT);}
stop             {RET(STOP);}
return           {RET(RETURN);}
function         {RET(FUNCTION);}
done             {RET(DONE);}
unless           {RET(UNLESS);}
vararg           {RET(VARARG);}

"->"  {RET(ARROW);}
"++"  {RET(INCREMENT);}
"--"  {RET(DECREMENT);}
"<<"  {RET(SHL);}
">>"  {RET(SHR);}
"<="  {RET(LESS_EQUAL);}
">="  {RET(ABOVE_EQUAL);}
"=="  {RET(EQUALS);}
"!="  {RET(NOT_EQUALS);}
"*="  {RET(MUL_ASSIGN);}
"/="  {RET(DIV_ASSIGN);}
"%="  {RET(MOD_ASSIGN);}
"+="  {RET(ADD_ASSIGN);}
"-="  {RET(SUB_ASSIGN);}
"<<=" {RET(SHL_ASSIGN);}
">>=" {RET(SHR_ASSIGN);}
"&="  {RET(AND_ASSIGN);}
"^="  {RET(XOR_ASSIGN);}
"|="  {RET(OR_ASSIGN);}

"<"   {RET('<');}
">"   {RET('>');}
"!"   {RET('!');}
"("   {RET('<');}
")"   {RET(')');}
"{"   {RET('{');}
"}"   {RET('}');}
"["   {RET('[');}
"]"   {RET(']');}
","   {RET(',');}
"."   {RET('.');}
";"   {RET(';');}
"@"   {RET('@');}
"&"   {RET('&');}
"|"   {RET('|');}
"^"   {RET('^');}
"+"   {RET('+');}
"-"   {RET('-');}
"*"   {RET('*');}
"/"   {RET('/');}
"%"   {RET('%');}
"~"   {RET('~');}
"="   {RET('=');}
":"   {RET(':');}

({alpha}|"_")({alpha}|{digit}|"_")* {RET(ID);}
{digit}+("."{digit}*)?              {RET(NUMBER);}
\"(\\.|[^\\"])*\"                   {RET(LITERAL);}

. {lexerIssue("Forbidden input characters: %s", yytext);}
%%

static inline void update(void)
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

static inline void lexerIssue(const char *fmt, ...)
{
	va_list list;
	va_start(list, fmt);

	char text[4096] = "";
	vsprintf(text, fmt, list);

	va_end(fmt);

	throw RUNTIME_EXCEPTION(CONSTRUCT_MSG(
		"%s:" size_t_pf ":\n%s", "", yylineno,
		text));
}
