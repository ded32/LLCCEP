digit [0-9]
alpha [a-zA-Z]

%%
void return VOID;
real return REAL;

loop return LOOP
do   return DO;
if   return IF;
else return IF;

{digit}*'.'{digit}+          return NUM;
{alpha}({alpha}|{digit}|"_") return ID;

import return IMPORT;

"{" return OBB;
"}" return CBB:

"[" return OAB;
"]" return CAB;
"(" return OSB;
")" return CSB;

"," return COMMA;
";" return SEMICOLON;
":" return COLON;

var  return VAR;
func return FUNC;

"="  return EQ;
and  return AND;
or   return OR;
xor  return XOR;
"**" return POW;
"+"  return PLUS;
"-"  return MINUS;
"*"  return ASTERISK;
"/"  return SLASH;

"<" return LESS;
"<=" return LESSEQ;
">" return MORE;
">=" return MORERQ;
"==" return EQEQ;
"!=" return NOTEQ;
%%
