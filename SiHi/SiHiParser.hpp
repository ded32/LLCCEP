/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER = 259,
     LITERAL = 260,
     ARROW = 261,
     INCREMENT = 262,
     DECREMENT = 263,
     REINTERPRET_CAST = 264,
     SHL = 265,
     SHR = 266,
     LESS_EQUAL = 267,
     ABOVE_EQUAL = 268,
     EQUALS = 269,
     NOT_EQUALS = 270,
     MUL_ASSIGN = 271,
     DIV_ASSIGN = 272,
     MOD_ASSIGN = 273,
     ADD_ASSIGN = 274,
     SUB_ASSIGN = 275,
     SHL_ASSIGN = 276,
     SHR_ASSIGN = 277,
     AND_ASSIGN = 278,
     XOR_ASSIGN = 279,
     OR_ASSIGN = 280,
     EMPTY = 281,
     REAL = 282,
     STRING = 283,
     OTHER = 284,
     PASS = 285,
     IF = 286,
     ELSE = 287,
     CASE = 288,
     WHILE = 289,
     DO = 290,
     FOR = 291,
     JUMP = 292,
     NEXT = 293,
     STOP = 294,
     RETURN = 295,
     DONE = 296,
     UNLESS = 297,
     VARARG = 298,
     FUNCTION = 299
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER 259
#define LITERAL 260
#define ARROW 261
#define INCREMENT 262
#define DECREMENT 263
#define REINTERPRET_CAST 264
#define SHL 265
#define SHR 266
#define LESS_EQUAL 267
#define ABOVE_EQUAL 268
#define EQUALS 269
#define NOT_EQUALS 270
#define MUL_ASSIGN 271
#define DIV_ASSIGN 272
#define MOD_ASSIGN 273
#define ADD_ASSIGN 274
#define SUB_ASSIGN 275
#define SHL_ASSIGN 276
#define SHR_ASSIGN 277
#define AND_ASSIGN 278
#define XOR_ASSIGN 279
#define OR_ASSIGN 280
#define EMPTY 281
#define REAL 282
#define STRING 283
#define OTHER 284
#define PASS 285
#define IF 286
#define ELSE 287
#define CASE 288
#define WHILE 289
#define DO 290
#define FOR 291
#define JUMP 292
#define NEXT 293
#define STOP 294
#define RETURN 295
#define DONE 296
#define UNLESS 297
#define VARARG 298
#define FUNCTION 299




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 6 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
{
	LLCCEP_SiHi::ast ast;
	::std::string string;
}
/* Line 1529 of yacc.c.  */
#line 142 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

