alpha [a-zA-Z]
digit [0-9]

%option yylineno
%option noyywrap

%{
#include <stdio.h>
#include <string>

#include <STDExtras.hpp>
#include <os-specific.hpp>

#include "yyltype.h"
#include "ast/ast.hpp"
#include "SiHiParser.hpp"

YYLTYPE yylexloc{};
int yyinputended = 0;
#define RET(val) ({yybegintok(yytext + yylexloc.posbuf); yylval.string = yytext; return val;})

extern int yyparse(LLCCEP_SiHi::ast **ast);

::std::string yyfilename = "";

static inline void update(void);
static inline void lexerIssue(const char *fmt, ...);
void yyerror(LLCCEP_SiHi::ast **ast, const char *str);

#if __cplusplus > 199711L
#define register      // Deprecated in C++11.
#endif 

#define YY_INPUT(buf, res, max) \
{ \
        res = yygetnextchar(buf); \
	if (res <= 0) \
		res = YY_NULL; \
}

static inline int yygetline(void);
static inline int yygetnextchar(char *cb);
static inline void yybegintok(const char *tok);
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

class            {RET(CLASS);}
typealias        {RET(TYPEALIAS);}
public           {RET(PUBLIC);}
private          {RET(PRIVATE);}
protected        {RET(PROTECTED);}
static           {RET(STATIC);}

"<-"  {RET(BACKARROW);}
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
"("   {RET('(');}
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
\'(\\.|[^\\"])*\'                   {RET(LITERAL);}

<<EOF>> {yyterminate();}
%%

static inline void update(void)
{
	for (size_t i = 0; yytext[i]; i++) {
		switch (yytext[i]) {
		case '\n':
		case '\r':
			yylexloc.first_column = 0;
			break;
				
		case '\t':
			yylexloc.first_column += 8;
			break;
				
		default:
		        yylexloc.first_column++;
		}
	}
}

static inline void lexerIssue(const char *fmt, ...)
{
	char str[8192] = "";
	va_list list;

	va_start(list, fmt);
	vsprintf(str, fmt, list);
	va_end(list);

	yyerror(0, str);
}

static inline void yydumprow(void)
{
	fprintf(stderr, "%6d | %s", yylineno, yylexloc.buf);
}

static inline void yymarktok(void)
{
	int start = yylexloc.first_column;
	int end = yylexloc.last_column;

	for (int i = 0; i < start + 8; i++)
		fprintf(stderr, " ");
	for (int i = start; i <= end; i++)
		fprintf(stderr, "^");

	fprintf(stderr, "\n");
}

void yyerror(LLCCEP_SiHi::ast **ast, const char *str)
{
	fprintf(stderr, "[%s:%d]:\n%s\n", yyfilename.c_str(),
	        yylineno, str);
	yydumprow();
	yymarktok();
}

static inline int yygetline(void)
{
	free((void *)yylexloc.buf);
	yylexloc.buf = 0;

	yylexloc.posbuf = 0;
	yylexloc.first_column = -1;
	yylexloc.last_column = 0;
	yylexloc.next_tok_first_column = 1;
	yyinputended = 0;

        size_t sz = 0;
	if (getline(&yylexloc.buf, &sz, yyin) < 0) {
		if (ferror(yyin))
			return -1;

		yyinputended = true;
		return 1;
	}

	return 0;
}

static inline int yygetnextchar(char *cb)
{
	if (yyinputended)
		return 0;

	while (!yylexloc.buf || yylexloc.posbuf >= strlen(yylexloc.buf))
		if (yygetline())
			return 0;

	*cb = yylexloc.buf[yylexloc.posbuf];
	yylexloc.posbuf++;

	return *cb != 0;
}

static inline void yybegintok(const char *tok)
{
	yylexloc.line = yylineno;
	yylexloc.first_column = yylexloc.next_tok_first_column;
	yylexloc.last_column = yylexloc.first_column + strlen(tok);
	yylexloc.next_tok_first_column = yylexloc.posbuf;
}

int main()
{
	yyin = stdin;

	LLCCEP_SiHi::ast *res = 0;
	yyparse(&res);

	if (res) {
		res->dumpImage("out.ast");
		DotViz::dvRender("out.ast", "out.png");
	} else {
		::std::cerr << "invalid output";
	}

	delete res;

	return 0;
}
