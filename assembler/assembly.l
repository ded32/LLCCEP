digit [0-9]
alpha [a-zA-Z]

%option yylineno

%{
#include <stdio.h>
#include <stdlib.h>

#include <STDExtras.hpp>
#include <os-specific.hpp>
#include <string>

#include "sectionList/sectionList.hpp"
#include "assemblyParser.hpp"

#if __cplusplus > 199711L
#define register
#endif

extern ::std::string yyfilename;
static int yyinputended = 0;
static YYLTYPE yylexloc{};

void yyerror(LLCCEP_ASM::assemblyProgram, const char *str);
static inline void update(void);

#define RET(val) \
{ \
	yylval.string = (char *)malloc(strlen(yylexloc.buf)); \
	strcpy(yylval.string, yylexloc.buf); \
	update(); \
	return val; \
}

%}

%%
COMMENT.*ENDCOMMENT {update();}
"#".*               {update();}
[ \t]+              {update();}
[\r\n]              {RET(NEWLINE);}

section             {RET(SECTION);}

({alpha}|_)({alpha}|{digit}|_)* {RET(ID);}
{digit}+("."{digit}*)?          {RET(NUMBER);}
\'(\\.|[^\\\])*\'               {RET(LITERAL);}
%%

