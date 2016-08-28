/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"

#include <string>
#include "ast/ast.hpp"


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 6 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
{
	LLCCEP_SiHi::ast ast;
	::std::string string;
}
/* Line 193 of yacc.c.  */
#line 194 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 207 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNRULES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    61,    51,     2,
      45,    46,    59,    53,    50,    54,    49,    60,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    67,    68,
      57,    64,    58,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    62,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    63,    66,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    13,    15,    20,    24,
      29,    33,    37,    40,    43,    45,    49,    51,    54,    57,
      60,    62,    64,    66,    68,    70,    72,    74,    82,    84,
      88,    90,    92,    94,    96,   100,   102,   104,   106,   110,
     112,   114,   116,   120,   122,   124,   126,   128,   130,   134,
     136,   138,   140,   144,   146,   150,   152,   156,   158,   164,
     166,   170,   172,   174,   176,   178,   180,   182,   184,   186,
     188,   190,   192,   194,   198,   200,   202,   204,   206,   208,
     210,   213,   215,   217,   221,   226,   230,   235,   240,   244,
     246,   249,   251,   255,   257,   261,   264,   267,   269,   271,
     275,   277,   279,   281,   284,   288,   291,   295,   299,   304,
     307,   311,   315
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      70,     0,    -1,     3,    -1,     4,    -1,     5,    -1,    45,
      92,    46,    -1,    70,    -1,    71,    47,    92,    48,    -1,
      71,    45,    46,    -1,    71,    45,    72,    46,    -1,    71,
      49,     3,    -1,    71,     6,     3,    -1,    71,     7,    -1,
      71,     8,    -1,    90,    -1,    72,    50,    90,    -1,    71,
      -1,     7,    73,    -1,     8,    73,    -1,    74,    75,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,
      56,    -1,    73,    -1,     9,    57,   103,    58,    45,    75,
      46,    -1,    75,    -1,    76,    77,    75,    -1,    59,    -1,
      60,    -1,    61,    -1,    76,    -1,    78,    79,    76,    -1,
      53,    -1,    54,    -1,    78,    -1,    80,    81,    78,    -1,
      10,    -1,    11,    -1,    80,    -1,    82,    83,    80,    -1,
      57,    -1,    58,    -1,    12,    -1,    13,    -1,    82,    -1,
      84,    85,    82,    -1,    14,    -1,    15,    -1,    84,    -1,
      86,    51,    84,    -1,    86,    -1,    87,    62,    86,    -1,
      87,    -1,    88,    63,    87,    -1,    88,    -1,    88,    41,
      92,    42,    89,    -1,    89,    -1,    73,    91,    90,    -1,
      64,    -1,    16,    -1,    17,    -1,    18,    -1,    19,    -1,
      20,    -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,
      25,    -1,    90,    -1,    92,    50,    90,    -1,    89,    -1,
      95,    -1,    26,    -1,    27,    -1,    28,    -1,     3,    -1,
      98,    97,    -1,    97,    -1,     3,    -1,    45,    96,    46,
      -1,    97,    47,    93,    48,    -1,    97,    47,    48,    -1,
      97,    45,    99,    46,    -1,    97,    45,   102,    46,    -1,
      97,    45,    46,    -1,    59,    -1,    59,    98,    -1,   100,
      -1,   100,    50,    43,    -1,   101,    -1,   100,    50,   101,
      -1,    94,    96,    -1,    94,   104,    -1,    94,    -1,     3,
      -1,   102,    50,     3,    -1,   104,    -1,    98,    -1,   105,
      -1,    98,   105,    -1,    45,   104,    46,    -1,    47,    48,
      -1,    47,    93,    48,    -1,   105,    47,    48,    -1,   105,
      47,    93,    48,    -1,    45,    46,    -1,    45,    99,    46,
      -1,   105,    45,    46,    -1,   105,    45,    99,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    41,    45,    49,    53,    55,    59,    63,
      67,    71,    75,    79,    85,    87,    93,    95,    99,   103,
     108,   110,   112,   114,   116,   118,   122,   124,   128,   130,
     136,   138,   140,   144,   146,   152,   154,   158,   160,   166,
     168,   172,   174,   180,   182,   184,   186,   190,   192,   198,
     200,   204,   206,   212,   214,   220,   222,   228,   230,   235,
     237,   243,   247,   251,   255,   259,   263,   267,   271,   275,
     279,   283,   289,   291,   296,   308,   328,   332,   336,   340,
     346,   350,   354,   358,   360,   364,   368,   369,   370,   373,
     375,   380,   382,   388,   390,   396,   400,   404,   410,   414,
     420,   426,   428,   430,   436,   438,   442,   446,   450,   454,
     458,   462,   466
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "NUMBER", "LITERAL", "ARROW",
  "INCREMENT", "DECREMENT", "REINTERPRET_CAST", "SHL", "SHR", "LESS_EQUAL",
  "ABOVE_EQUAL", "EQUALS", "NOT_EQUALS", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "SHL_ASSIGN", "SHR_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "EMPTY", "REAL", "STRING",
  "OTHER", "PASS", "IF", "ELSE", "CASE", "WHILE", "DO", "FOR", "JUMP",
  "NEXT", "STOP", "RETURN", "DONE", "UNLESS", "VARARG", "FUNCTION", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'@'", "'+'", "'-'", "'~'",
  "'!'", "'<'", "'>'", "'*'", "'/'", "'%'", "'^'", "'|'", "'='", "'{'",
  "'}'", "':'", "';'", "$accept", "primary_expression",
  "postfix_expression", "argument_expression_list", "unary_expression",
  "unary_operator", "cast_expression", "multiplicative_expression",
  "multiplicative_operator", "additive_expression", "additive_operator",
  "shift_expression", "shift_operator", "relational_expression",
  "relational_operator", "equality_expression", "equality_operator",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration_specifiers",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,    40,    41,    91,    93,    46,
      44,    38,    64,    43,    45,   126,    33,    60,    62,    42,
      47,    37,    94,   124,    61,   123,   125,    58,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    69,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      77,    77,    77,    78,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    93,    94,    95,    95,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   101,   102,   102,
     103,   104,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     7,     1,     3,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     3,     4,     3,     4,     4,     3,     1,
       2,     1,     3,     1,     3,     2,     2,     1,     1,     3,
       1,     1,     1,     2,     3,     2,     3,     3,     4,     2,
       3,     3,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     3,     4,     0,     0,     0,     0,     0,    20,
      21,    22,    23,    24,    25,     6,    16,    26,     0,    28,
      33,    37,    41,    47,    51,    53,    55,    57,    59,    72,
       0,     1,    17,    18,     0,     0,    12,    13,     0,     0,
       0,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    61,     0,    26,    19,    30,    31,    32,     0,    35,
      36,     0,    39,    40,     0,    45,    46,    43,    44,     0,
      49,    50,     0,     0,     0,     0,     0,     5,     0,     0,
       0,    89,   101,     0,   100,   102,    11,     8,     0,    14,
       0,    10,    60,    29,    34,    38,    42,    48,    52,    54,
       0,    56,    73,    79,    76,    77,    78,   109,    97,    75,
       0,    91,    93,     0,   105,    74,     0,    90,   103,     0,
       0,     0,     9,     0,     7,     0,    82,     0,    95,    81,
     101,    96,   110,     0,   104,   106,     0,   111,     0,   107,
       0,    15,    58,    79,     0,     0,     0,    80,    92,    94,
       0,   112,   108,    83,    79,    88,     0,     0,    85,     0,
      27,    86,    87,     0,    84,    99
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    15,    16,    88,    53,    18,    19,    20,    58,    21,
      61,    22,    64,    23,    69,    24,    72,    25,    26,    27,
      28,    29,    52,    30,   116,   108,   109,   128,   129,    82,
     110,   111,   112,   157,    83,   113,    85
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -94
static const yytype_int16 yypact[] =
{
       4,   -94,   -94,   -94,   174,    27,   186,   186,   -11,   -94,
     -94,   -94,   -94,   -94,   -94,   -94,   198,     1,   174,   -94,
      64,    89,    87,    18,   131,    22,   -22,    39,   -94,   -94,
     -17,   -94,   -94,   -94,    73,    58,   -94,   -94,    84,   174,
      82,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,   -94,
     -94,   -94,   174,   -94,   -94,   -94,   -94,   -94,   174,   -94,
     -94,   174,   -94,   -94,   174,   -94,   -94,   -94,   -94,   174,
     -94,   -94,   174,   174,   174,   174,   174,   -94,   174,    10,
      96,    55,   -33,    63,   -94,    -2,   -94,   -94,    44,   -94,
      78,   -94,   -94,   -94,    64,    89,    87,    18,   131,    22,
      28,   -22,   -94,   -94,   -94,   -94,   -94,   -94,     7,   -94,
      88,   104,   -94,   109,   -94,   -94,   110,   -94,    -2,   112,
      81,   108,   -94,   174,   -94,   174,   -94,    36,   -94,    86,
      13,   -94,   -94,   169,   -94,   -94,   174,   -94,   122,   -94,
     125,   -94,   -94,   -94,   128,   206,   162,    86,   -94,   -94,
     129,   -94,   -94,   -94,   -94,   -94,   130,    60,   -94,   132,
     -94,   -94,   -94,   181,   -94,   -94
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -94,   185,   -94,   -94,    -4,   -94,   -14,   126,   -94,   124,
     -94,   117,   -94,   120,   -94,   127,   -94,   134,   123,   -94,
     -74,   -37,   -94,    -7,   -93,   -94,   -94,    71,    72,   -31,
     -78,   -94,    68,   -94,   -94,   -29,   -71
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      17,    89,    32,    33,    54,    84,   115,     1,     2,     3,
     126,   118,    79,   103,    80,    92,   126,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    31,   140,    77,
      65,    66,    90,    78,    17,    17,   104,   105,   106,   143,
      74,   102,   138,   120,    93,   121,    34,   115,    17,     4,
     117,   142,   127,   159,    80,    79,   107,    80,   127,   118,
      80,    86,   104,   105,   106,    51,    81,   156,   100,    81,
     125,    17,   115,    73,    17,    67,    68,   130,    78,   131,
      75,   127,   107,    80,   103,    91,   141,     1,     2,     3,
     122,     6,     7,     8,   123,    81,   130,    62,    63,     1,
       2,     3,    76,     6,     7,     8,   162,   104,   105,   106,
     163,     1,     2,     3,    81,     6,     7,     8,    79,    17,
      80,   119,   150,    55,    56,    57,   124,   137,    78,     4,
      87,   145,    81,   146,   132,     9,    10,    11,    12,    13,
      14,     4,    59,    60,   114,    70,    71,     9,    10,    11,
      12,    13,    14,     4,   133,   134,   139,   136,   135,     9,
      10,    11,    12,    13,    14,     1,     2,     3,   151,     6,
       7,     8,   103,   152,   153,   160,   161,     1,     2,     3,
     164,     6,     7,     8,   165,     5,    96,    94,    95,     1,
       2,     3,    97,     6,     7,   104,   105,   106,   144,   101,
      98,   149,   147,     0,    35,    36,    37,     4,    99,   154,
     158,     0,   148,     9,    10,    11,    12,    13,    14,     4,
       0,     0,     0,     0,     0,     9,    10,    11,    12,    13,
      14,     4,   104,   105,   106,     0,     0,     9,    10,    11,
      12,    13,    14,    38,     0,    39,     0,    40,     0,     0,
       0,     0,   155
};

static const yytype_int16 yycheck[] =
{
       4,    38,     6,     7,    18,    34,    80,     3,     4,     5,
       3,    82,    45,     3,    47,    52,     3,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,     0,   121,    46,
      12,    13,    39,    50,    38,    39,    26,    27,    28,     3,
      62,    78,   120,    45,    58,    47,    57,   121,    52,    45,
      81,   125,    45,   146,    47,    45,    46,    47,    45,   130,
      47,     3,    26,    27,    28,    64,    59,   145,    75,    59,
      42,    75,   146,    51,    78,    57,    58,   108,    50,   108,
      41,    45,    46,    47,     3,     3,   123,     3,     4,     5,
      46,     7,     8,     9,    50,    59,   127,    10,    11,     3,
       4,     5,    63,     7,     8,     9,    46,    26,    27,    28,
      50,     3,     4,     5,    59,     7,     8,     9,    45,   123,
      47,    58,   136,    59,    60,    61,    48,    46,    50,    45,
      46,    45,    59,    47,    46,    51,    52,    53,    54,    55,
      56,    45,    53,    54,    48,    14,    15,    51,    52,    53,
      54,    55,    56,    45,    50,    46,    48,    45,    48,    51,
      52,    53,    54,    55,    56,     3,     4,     5,    46,     7,
       8,     9,     3,    48,    46,    46,    46,     3,     4,     5,
      48,     7,     8,     9,     3,     0,    69,    61,    64,     3,
       4,     5,    72,     7,     8,    26,    27,    28,   127,    76,
      73,   133,   130,    -1,     6,     7,     8,    45,    74,     3,
      48,    -1,    43,    51,    52,    53,    54,    55,    56,    45,
      -1,    -1,    -1,    -1,    -1,    51,    52,    53,    54,    55,
      56,    45,    26,    27,    28,    -1,    -1,    51,    52,    53,
      54,    55,    56,    45,    -1,    47,    -1,    49,    -1,    -1,
      -1,    -1,    46
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,    45,    70,     7,     8,     9,    51,
      52,    53,    54,    55,    56,    70,    71,    73,    74,    75,
      76,    78,    80,    82,    84,    86,    87,    88,    89,    90,
      92,     0,    73,    73,    57,     6,     7,     8,    45,    47,
      49,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    64,    91,    73,    75,    59,    60,    61,    77,    53,
      54,    79,    10,    11,    81,    12,    13,    57,    58,    83,
      14,    15,    85,    51,    62,    41,    63,    46,    50,    45,
      47,    59,    98,   103,   104,   105,     3,    46,    72,    90,
      92,     3,    90,    75,    76,    78,    80,    82,    84,    86,
      92,    87,    90,     3,    26,    27,    28,    46,    94,    95,
      99,   100,   101,   104,    48,    89,    93,    98,   105,    58,
      45,    47,    46,    50,    48,    42,     3,    45,    96,    97,
      98,   104,    46,    50,    46,    48,    45,    46,    99,    48,
      93,    90,    89,     3,    96,    45,    47,    97,    43,   101,
      75,    46,    48,    46,     3,    46,    99,   102,    48,    93,
      46,    46,    46,    50,    48,     3
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 37 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({}, 
                                                      "Identifier: " + (yyvsp[(1) - (1)].string),
                                                      ID);
                    ;}
    break;

  case 3:
#line 41 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({},
                                                      "Number: " + (yyvsp[(1) - (1)].string),
                                                      NUMBER);
                    ;}
    break;

  case 4:
#line 45 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({},
                                                      "Literal: " + (yyvsp[(1) - (1)].string),
                                                      LITERAL);
                    ;}
    break;

  case 5:
#line 49 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = (yyvsp[(2) - (3)].ast);
                    ;}
    break;

  case 6:
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = (yyvsp[(1) - (1)].ast);
	            ;}
    break;

  case 7:
#line 55 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (4)].ast), (yyvsp[(3) - (4)].ast)},
                                                      "[]",
                                                      ACCESS_ARRAY_MEMBER);
                    ;}
    break;

  case 8:
#line 59 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast)},
                                                      "()",
                                                      INVOKE);
		    ;}
    break;

  case 9:
#line 63 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (4)].ast), (yyvsp[(3) - (4)].ast)},
                                                      "()",
                                                      INVOKE);
                    ;}
    break;

  case 10:
#line 67 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), new LLCCEP_SiHi::ast({}, "Identifier: " + (yyvsp[(3) - (3)].string), ID)},
                                                      "."
                                                      ACCESS_MEMBER);
                    ;}
    break;

  case 11:
#line 71 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), new LLCCEP_SiHi::ast({}, "Identifier: " + (yyvsp[(3) - (3)].string), ID)},
                                                      "->",
                                                      ACCESS_MEMBER_BY_PTR);
                    ;}
    break;

  case 12:
#line 75 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast)},
                                                      "++",
                                                      INCREMENT);
                    ;}
    break;

  case 13:
#line 79 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                            (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast)},
                                                      "--",
                                                      DECREMENT);
                    ;}
    break;

  case 14:
#line 85 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                (yyval.ast) = (yyvsp[(1) - (1)].ast); 
                        ;}
    break;

  case 15:
#line 87 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                                          (yyvsp[(1) - (3)].ast).value() + " " + (yyvsp[(1) - (3)].ast).value(),
                                                          "Argument expression list");
                        ;}
    break;

  case 16:
#line 93 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                        (yyval.ast) = (yyvsp[(1) - (1)].ast);
                ;}
    break;

  case 17:
#line 95 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                        (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(2) - (2)].ast)}, 
                                                  "++",
                                                  INCREMENT);
                ;}
    break;

  case 18:
#line 99 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                        (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(2) - (2)].ast)},
                                                  "--",
                                                  DECREMENT);
	        ;}
    break;

  case 19:
#line 103 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		        (yyval.ast) = (yyvsp[(1) - (2)].ast);
                        (yyval.ast)->insert_child((yyvsp[(2) - (2)].ast));
		;}
    break;

  case 20:
#line 108 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "&", '&');
	      ;}
    break;

  case 21:
#line 110 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "@", '@');
              ;}
    break;

  case 22:
#line 112 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "+", '+');
              ;}
    break;

  case 23:
#line 114 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "-", '-');
              ;}
    break;

  case 24:
#line 116 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "~", '~');
	      ;}
    break;

  case 25:
#line 118 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "!", '!');
              ;}
    break;

  case 26:
#line 122 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                       (yyval.ast) = (yyvsp[(1) - (1)].ast);
	       ;}
    break;

  case 27:
#line 124 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                       (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(3) - (7)].ast), (yyvsp[(6) - (7)].ast)}, "reinterpret_cast", REINTERPRET_CAST);
               ;}
    break;

  case 28:
#line 128 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = (yyvsp[(1) - (1)].ast);
                         ;}
    break;

  case 29:
#line 130 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = (yyvsp[(2) - (3)].ast); 
                                  (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast)); 
                                  (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                         ;}
    break;

  case 30:
#line 136 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                               (yyval.ast) = LLCCEP_SiHi::ast({}, "*", '*');
                       ;}
    break;

  case 31:
#line 138 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                               (yyval.ast) = LLCCEP_SiHi::ast({}, "/", '/');
                       ;}
    break;

  case 32:
#line 140 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                               (yyval.ast) = LLCCEP_SiHi::ast({}, "%", '%');
                       ;}
    break;

  case 33:
#line 144 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = (yyvsp[(1) - (1)].ast);
                   ;}
    break;

  case 34:
#line 146 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = (yyvsp[(2) - (3)].ast);
                           (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast));
                           (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                   ;}
    break;

  case 35:
#line 152 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = LLCCEP_SiHi::ast({}, "+", '+');
                 ;}
    break;

  case 36:
#line 154 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = LLCCEP_SiHi::ast({}, "-", '-');
                 ;}
    break;

  case 37:
#line 158 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = (yyvsp[(1) - (1)].ast);
	        ;}
    break;

  case 38:
#line 160 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = (yyvsp[(2) - (3)].ast);
                         (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast));
                         (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                ;}
    break;

  case 39:
#line 166 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, "<<", SHL);
              ;}
    break;

  case 40:
#line 168 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({}, ">>", SHR);
              ;}
    break;

  case 41:
#line 172 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                             (yyval.ast) = (yyvsp[(1) - (1)].ast);
	             ;}
    break;

  case 42:
#line 174 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                             (yyval.ast) = (yyvsp[(2) - (3)].ast);
                             (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast));
                             (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                     ;}
    break;

  case 43:
#line 180 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({}, "<", '<');
                   ;}
    break;

  case 44:
#line 182 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({}, ">", '>');
                   ;}
    break;

  case 45:
#line 184 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({}, "<=", LESS_EQUAL);
                   ;}
    break;

  case 46:
#line 186 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({}, ">=", ABOVE_EQUAL);
                   ;}
    break;

  case 47:
#line 190 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		           (yyval.ast) = (yyvsp[(1) - (1)].ast);
	           ;}
    break;

  case 48:
#line 192 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = (yyvsp[(2) - (3)].ast);
                           (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast));
                           (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                   ;}
    break;

  case 49:
#line 198 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		         (yyval.ast) = LLCCEP_SiHi::ast({}, "==", EQUALS);
                 ;}
    break;

  case 50:
#line 200 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = LLCCEP_SiHi::ast({}, "!=", NOT_EQUALS);
                 ;}
    break;

  case 51:
#line 204 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	              (yyval.ast) = (yyvsp[(1) - (1)].ast);
	      ;}
    break;

  case 52:
#line 206 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                                "&",
                                                '&');
              ;}
    break;

  case 53:
#line 212 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		               (yyval.ast) =(yyvsp[(1) - (1)].ast);
  	               ;}
    break;

  case 54:
#line 214 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                               (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                                         "^",
                                                         '^');
                       ;}
    break;

  case 55:
#line 220 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		               (yyval.ast) = (yyvsp[(1) - (1)].ast);
 	               ;}
    break;

  case 56:
#line 222 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                               (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                                         "|",
                                                         '|');
                       ;}
    break;

  case 57:
#line 228 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		              (yyval.ast) = (yyvsp[(1) - (1)].ast);
	              ;}
    break;

  case 58:
#line 230 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    { 
                              (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (5)].ast), (yyvsp[(3) - (5)].ast), (yyvsp[(5) - (5)].ast)},
                                                        "if -- else");
                      ;}
    break;

  case 59:
#line 235 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		             (yyval.ast) = (yyvsp[(1) - (1)].ast);
	             ;}
    break;

  case 60:
#line 237 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                             (yyval.ast) = (yyvsp[(2) - (3)].ast);
                             (yyval.ast)->insert_child((yyvsp[(1) - (3)].ast));
                             (yyval.ast)->insert_child((yyvsp[(3) - (3)].ast));
                     ;}
    break;

  case 61:
#line 243 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "=",
                                                     '=');
	           ;}
    break;

  case 62:
#line 247 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "*=",
                                                     MUL_ASSIGN);
	           ;}
    break;

  case 63:
#line 251 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "/=",
                                                     DIV_ASSIGN);
	           ;}
    break;

  case 64:
#line 255 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "%=",
                                                     MOD_ASSIGN);
	           ;}
    break;

  case 65:
#line 259 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "+=",
                                                     ADD_ASSIGN);
	           ;}
    break;

  case 66:
#line 263 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "-=",
                                                     SIB_ASSIGN);
	           ;}
    break;

  case 67:
#line 267 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "<<=",
                                                     SHL_ASSIGN);
	           ;}
    break;

  case 68:
#line 271 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     ">>=",
                                                     SHR_ASSIGN);
	           ;}
    break;

  case 69:
#line 275 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "&=",
                                                     AND_ASSIGN);
	           ;}
    break;

  case 70:
#line 279 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "^=",
                                                     XOR_ASSIGN);
	           ;}
    break;

  case 71:
#line 283 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({},
                                                     "|=",
                                                     OR_ASSIGN);
                   ;}
    break;

  case 72:
#line 289 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	          (yyval.ast) = (yyvsp[(1) - (1)].ast);
  	  ;}
    break;

  case 73:
#line 291 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                            ",", ',');
          ;}
    break;

  case 74:
#line 296 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		           (yyval.ast) = (yyvsp[(1) - (1)].ast);
		   ;}
    break;

  case 75:
#line 308 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		              (yyval.ast) = (yyvsp[(1) - (1)].ast);
		      ;}
    break;

  case 76:
#line 328 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	              (yyval.ast) = LLCCEP_SiHi::ast({},
                                                "empty",
                                                EMPTY);
   	      ;}
    break;

  case 77:
#line 332 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({},
                                                "real",
                                                REAL);
	      ;}
    break;

  case 78:
#line 336 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({},
                                                "string",
                                                STRING);
	      ;}
    break;

  case 79:
#line 340 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({},
                                                "typename: " + (yyvsp[(1) - (1)].string),
                                                TYPENAME);
              ;}
    break;

  case 80:
#line 346 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	          (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)},
                                            "declarator",
                                            DECLARATOR);
	  ;}
    break;

  case 81:
#line 350 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                  (yyval.ast) = (yyvsp[(1) - (1)].ast);
          ;}
    break;

  case 82:
#line 354 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		         (yyval.ast) = LLCCEP_SiHi::ast({}, 
                                                   (yyvsp[(1) - (1)].string), 
                                                   ID);
 	         ;}
    break;

  case 83:
#line 358 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = (yyvsp[(2) - (3)].ast);
                 ;}
    break;

  case 84:
#line 360 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (4)].ast), (yyvsp[(3) - (4)].ast)},
                                                   "[]",
                                                   ARRAY_DECLARATION);
                 ;}
    break;

  case 85:
#line 364 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                         (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast)},
                                                   "[]",
                                                   ARRAY_DECLARATION);
	         ;}
    break;

  case 86:
#line 368 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                 ;}
    break;

  case 87:
#line 369 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	         ;}
    break;

  case 88:
#line 370 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                 ;}
    break;

  case 89:
#line 373 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                 (yyval.ast) = LLCCEP_SiHi::ast({}, "*", POINTER);
       ;}
    break;

  case 90:
#line 375 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                 (yyval.ast) = LLCCEP_SiHi::ast({}, "*", POINTER);
       ;}
    break;

  case 91:
#line 380 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		           (yyval.ast) = (yyvsp[(1) - (1)].ast);
	           ;}
    break;

  case 92:
#line 382 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), new LLCCEP_SiHi::ast({}, "vararg", VARARG)}, 
                                                     ",",
                                                     PARAM_TYPE_LIST);
                   ;}
    break;

  case 93:
#line 388 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = (yyvsp[(1) - (1)].ast);
	      ;}
    break;

  case 94:
#line 390 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                      (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), (yyvsp[(3) - (3)].ast)},
                                                ",",
                                                PARAMETER_LIST);
              ;}
    break;

  case 95:
#line 396 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		             (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
		     ;}
    break;

  case 96:
#line 400 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                             (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     ;}
    break;

  case 97:
#line 404 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                             (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (1)].ast)},
                                                       "Parameter declaration",
                                                       PARAMETER_DECLARATION);
                     ;}
    break;

  case 98:
#line 410 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
	               (yyval.ast) = LLCCEP_SiHi::ast({},
                                                 (yyvsp[(1) - (1)].string),
                                                 ID);
	       ;}
    break;

  case 99:
#line 414 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                       (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast), new LLCCEP_SiHi::ast({}, (yyvsp[(2) - (3)].string), ID)},
                                                 ",",
                                                 IDENTIFIER_LIST);
               ;}
    break;

  case 100:
#line 420 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                 (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (1)].ast)},
                                           "typename",
                                           TYPENAME);
         ;}
    break;

  case 101:
#line 426 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
		           (yyval.ast) = (yyvsp[(1) - (1)].ast);
 	           ;}
    break;

  case 102:
#line 428 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = (yyvsp[(1) - (1)].ast);
	           ;}
    break;

  case 103:
#line 430 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                           (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (2)].ast), (yyvsp[(2) - (2)].ast)},
                                                     "Abstract declarator",
                                                     ABSTRACT_DECLARATOR);
                   ;}
    break;

  case 104:
#line 436 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
			          (yyval.ast) = (yyvsp[(2) - (3)].ast);
	                  ;}
    break;

  case 105:
#line 438 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({}, 
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
	                  ;}
    break;

  case 106:
#line 442 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(2) - (3)].ast)},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 107:
#line 446 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast)},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 108:
#line 450 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (4)].ast), (yyvsp[(2) - (4)].ast)},
                                                            "[]",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 109:
#line 454 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 110:
#line 458 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(2) - (3)].ast)},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 111:
#line 462 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (3)].ast)},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;

  case 112:
#line 466 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"
    {
                                  (yyval.ast) = LLCCEP_SiHi::ast({(yyvsp[(1) - (4)].ast)},
                                                            "()",
                                                            DIRECT_ABSTRACT_DECLARATOR);
                          ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2488 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 658 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y"


int main()
{
	yyin = stdin;
	yyparse();

	builtSyntaxTree.dumpImage("out.gv");

	return 0;
}

