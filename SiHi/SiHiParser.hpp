/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_USERS_ANDREW_DOCUMENTS_PROJECTS_PERSONAL_LLCCEP_SIHI_SIHIPARSER_HPP_INCLUDED
# define YY_YY_USERS_ANDREW_DOCUMENTS_PROJECTS_PERSONAL_LLCCEP_SIHI_SIHIPARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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
    FUNCTION = 299,
    CLASS = 300,
    TYPEALIAS = 301,
    BACKARROW = 302,
    PUBLIC = 303,
    PRIVATE = 304,
    PROTECTED = 305,
    STATIC = 306,
    INIT = 307,
    DEINIT = 308,
    RELEASE = 309,
    TRY = 310,
    CATCH = 311,
    FINALLY = 312,
    THROW = 313,
    ASM = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1915  */

	::LLCCEP_SiHi::ast *ast;
	char *string;

#line 119 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.hpp" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (LLCCEP_SiHi::ast **ast);

#endif /* !YY_YY_USERS_ANDREW_DOCUMENTS_PROJECTS_PERSONAL_LLCCEP_SIHI_SIHIPARSER_HPP_INCLUDED  */