/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 14 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:339  */

#include <string>
#include "yyltype.h"
#include "ast/ast.hpp"

/**************************************************
 * Intermodular functions
 *************************************************/
extern void yyerror(LLCCEP_SiHi::ast **, const char *msg);
extern int yylex(void);

#line 78 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "SiHiParser.hpp".  */
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
#line 44 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:355  */

	::LLCCEP_SiHi::ast *ast;
	char *string;

#line 183 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (LLCCEP_SiHi::ast **ast);

#endif /* !YY_YY_USERS_ANDREW_DOCUMENTS_PROJECTS_PERSONAL_LLCCEP_SIHI_SIHIPARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   721

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  75
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  305

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    75,    66,     2,
      60,    61,    73,    68,    65,    69,    64,    74,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    81,    82,
      71,    78,    72,     2,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    62,     2,    63,    76,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    79,    77,    80,    70,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   150,   150,   152,   154,   156,   160,   162,   164,   166,
     168,   170,   172,   174,   178,   180,   185,   187,   192,   194,
     196,   198,   200,   202,   204,   208,   210,   214,   216,   222,
     224,   226,   230,   232,   238,   240,   244,   246,   252,   254,
     258,   260,   266,   268,   270,   272,   276,   278,   284,   286,
     290,   292,   296,   298,   302,   304,   308,   310,   314,   316,
     320,   322,   324,   326,   328,   330,   332,   334,   336,   338,
     340,   344,   346,   350,   354,   358,   362,   364,   369,   371,
     375,   377,   379,   381,   385,   387,   391,   393,   395,   397,
     399,   401,   405,   407,   412,   414,   416,   421,   423,   428,
     430,   432,   436,   438,   443,   447,   449,   451,   455,   457,
     459,   461,   463,   465,   467,   469,   471,   475,   477,   481,
     483,   488,   490,   492,   494,   496,   498,   500,   502,   504,
     508,   512,   514,   516,   520,   522,   526,   528,   532,   534,
     538,   540,   544,   546,   550,   552,   557,   559,   563,   565,
     570,   572,   574,   578,   580,   582,   586,   588,   590,   592,
     594,   598,   600,   604,   608,   610,   615,   617,   619,   623,
     627,   631,   636,   638,   642,   644,   648,   652,   656,   658,
     662,   666,   668,   673,   675,   677,   681,   685,   689,   692,
     696,   698,   700
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "\"identifier\"", "\"numeric value\"",
  "\"literal value\"", "\"->\"", "\"++\"", "\"--\"",
  "\"reinterpret_cast\"", "\"<<\"", "\">>\"", "\"<=\"", "\">=\"", "\"==\"",
  "\"!=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"+=\"", "\"-=\"", "\"<<=\"",
  "\">>=\"", "\"&=\"", "\"^=\"", "\"|=\"", "\"empty\"", "\"real\"",
  "\"string\"", "\"other\"", "\"pass\"", "\"if\"", "\"else\"", "\"case\"",
  "\"while\"", "\"do\"", "\"for\"", "\"jump\"", "\"next\"", "\"stop\"",
  "\"return\"", "\"done\"", "\"unless\"", "\"vararg\"", "\"function\"",
  "\"class\"", "\"typealias\"", "\"<-\"", "\"public\"", "\"private\"",
  "\"protected\"", "\"static\"", "\"init\"", "\"deinit\"", "\"release\"",
  "\"try\"", "\"catch\"", "\"finally\"", "\"throw\"", "\"asm\"", "'('",
  "')'", "'['", "']'", "'.'", "','", "'&'", "'@'", "'+'", "'-'", "'~'",
  "'<'", "'>'", "'*'", "'/'", "'%'", "'^'", "'|'", "'='", "'{'", "'}'",
  "':'", "';'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression",
  "multiplicative_operator", "additive_expression", "additive_operator",
  "shift_expression", "shift_operator", "relational_expression",
  "relational_operator", "equality_expression", "equality_operator",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "type_specifier", "declarator", "direct_declarator", "pointer",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "abstract_declarator",
  "direct_abstract_declarator", "initializer", "initializer_list",
  "statement", "releasement_statement", "labeled_statement",
  "compound_statement", "declaration_statement",
  "declaration_optional_semicolon", "statement_optional_semicolon",
  "declaration_statement_optional_semicolon", "declaration_statement_list",
  "expression_statement", "labeled_statement_list", "branched_statement",
  "looped_statement", "jump_statement", "exception_handling_statement",
  "exception_throw_statement", "translation_unit", "external_declaration",
  "function_definition", "function_signature", "function_name",
  "function_args", "function_type", "class_declaration", "classname",
  "predecessor", "class_body", "method_property_list", "method_property",
  "init_declaration", "deinit_declaration", "access_rule_optional_static",
  "access_rule", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
      40,    41,    91,    93,    46,    44,    38,    64,    43,    45,
     126,    60,    62,    42,    47,    37,    94,   124,    61,   123,
     125,    58,    59
};
# endif

#define YYPACT_NINF -204

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-204)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     415,  -204,  -204,  -204,  -204,    45,    59,    -9,    47,  -204,
    -204,   668,  -204,  -204,    39,   148,  -204,    29,  -204,  -204,
    -204,  -204,    47,    54,    60,  -204,    63,    19,    25,  -204,
    -204,   247,  -204,    42,    43,  -204,    67,  -204,   124,   137,
      83,   110,  -204,    47,   412,   303,   202,    19,   103,  -204,
    -204,  -204,  -204,   118,   111,  -204,   651,   651,   651,   651,
     398,   191,  -204,  -204,   651,   194,   534,   534,   651,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,   159,    36,   651,  -204,
      95,   -32,    33,    65,   188,   134,   139,    -6,   132,  -204,
     157,   143,   138,  -204,  -204,  -204,  -204,  -204,  -204,   315,
    -204,  -204,  -204,  -204,  -204,  -204,   164,    62,   548,  -204,
      31,  -204,    24,   155,    42,  -204,  -204,   245,  -204,  -204,
    -204,  -204,   412,  -204,  -204,  -204,  -204,   165,    94,  -204,
    -204,  -204,   166,   534,    87,   534,   466,    18,   466,   466,
    -204,  -204,   146,  -204,   157,  -204,   167,   103,   175,  -204,
     130,   231,  -204,  -204,   572,   651,   232,  -204,  -204,  -204,
    -204,  -204,  -204,  -204,  -204,  -204,  -204,  -204,   651,  -204,
    -204,  -204,  -204,   651,  -204,  -204,   651,  -204,  -204,   651,
    -204,  -204,  -204,  -204,   651,  -204,  -204,   651,   651,   651,
     651,   651,   651,   534,  -204,  -204,  -204,  -204,  -204,  -204,
     177,   186,  -204,   196,    24,   264,   616,  -204,  -204,  -204,
    -204,  -204,  -204,   129,   148,    39,   312,  -204,  -204,  -204,
     415,  -204,  -204,   -16,  -204,  -204,   246,  -204,  -204,   126,
      48,   185,  -204,  -204,   228,   480,  -204,   227,   640,    42,
    -204,  -204,  -204,   153,  -204,    52,  -204,  -204,  -204,    95,
     -32,    33,    65,   188,   134,    30,   139,  -204,  -204,  -204,
    -204,  -204,  -204,   205,  -204,   216,  -204,    39,  -204,  -204,
    -204,  -204,   412,  -204,  -204,   229,   534,  -204,   330,   534,
     206,   534,  -204,   651,  -204,   651,  -204,  -204,  -204,  -204,
     651,  -204,  -204,  -204,  -204,   534,   242,  -204,  -204,   239,
     534,   534,  -204,  -204,  -204
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    83,    80,    81,    82,     0,     0,   139,     0,    75,
     167,     0,   164,   166,     0,    94,   168,   178,   171,   177,
     138,    86,     0,    92,    74,    76,    78,    85,     0,     1,
     165,     0,   169,    94,   101,   172,    95,    97,   174,     0,
       0,     0,    93,     0,     0,    94,     0,    84,     2,     3,
       4,    18,    19,     0,     0,   146,     0,     0,     0,     0,
       0,     0,   157,   158,   159,     0,     0,     0,     0,    20,
      21,    22,    23,    24,   134,     6,    16,    25,     0,    27,
      32,    36,    40,    46,    50,    52,    54,    56,    58,    71,
     147,     0,   141,   129,   121,   122,   142,   143,   144,     0,
     123,   124,   125,   126,   127,   128,     0,     0,     0,    99,
     105,   100,   106,     0,     0,   170,   179,     0,   176,    87,
      77,     2,     0,    58,   117,    79,    83,     0,     0,    89,
      25,    73,     0,     0,     0,     0,     0,     0,     0,     0,
     136,   137,     0,   156,   160,   102,   130,     2,     0,   163,
       0,     0,    12,    13,     0,     0,     0,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    60,     0,    17,
      29,    30,    31,     0,    34,    35,     0,    38,    39,     0,
      44,    45,    42,    43,     0,    48,    49,     0,     0,     0,
       0,     0,     0,     0,   140,   135,   145,   173,    83,   113,
       0,     0,   109,     0,   107,     0,     0,    96,    98,   175,
     190,   192,   191,     0,    94,     0,     0,   181,   184,   185,
       0,   189,   119,     0,    90,    91,     0,    88,   131,     0,
     105,     0,   104,   133,   150,     0,   153,     0,     0,     0,
       5,    11,     8,     0,    14,     0,    10,    59,    28,    33,
      37,    41,    47,    51,    53,     0,    55,    72,   132,   114,
     108,   110,   115,     0,   111,     0,   188,     0,   187,   180,
     182,   183,     0,   118,   103,     0,     0,   148,     0,     0,
       0,     0,     9,     0,     7,     0,   116,   112,   186,   120,
       0,   151,   152,   149,   154,     0,   161,    15,    57,     0,
       0,     0,    26,   155,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -204,  -204,  -204,  -204,   -45,  -204,   -73,   127,  -204,   125,
    -204,   128,  -204,   121,  -204,   122,  -204,   120,   141,  -204,
     -42,   -35,  -204,   -17,   -34,   -54,     7,  -204,   268,   207,
      -3,    -1,   -13,   -25,  -204,   215,   271,  -204,   -23,   -85,
    -109,  -204,   -37,  -204,  -203,   -14,  -204,    -7,  -204,   241,
    -204,   109,  -204,  -204,  -204,  -204,  -204,  -204,  -204,    -8,
    -204,  -204,  -204,   142,  -204,  -204,  -204,  -204,  -204,  -204,
     150,  -204,  -204,  -204,   144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,    76,   243,    77,    78,    79,    80,   173,    81,
     176,    82,   179,    83,   184,    84,   187,    85,    86,    87,
      88,    89,   168,    90,    91,     7,    34,    24,    25,     9,
      26,    27,    28,    35,    36,    37,   128,   231,   201,   112,
     125,   223,    92,    93,    94,    95,   142,    10,    97,    98,
      99,   100,   278,   101,   102,   103,   104,   105,    11,    12,
      13,    14,    15,    38,   115,    16,    17,    40,   118,   216,
     217,   218,   219,   220,   221
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,   130,   123,    30,   131,   169,   140,     8,   106,   124,
      42,   111,   132,   222,   123,   123,   123,   123,     8,    41,
     127,   110,   123,   141,    96,   204,   123,    47,    21,   148,
     149,   109,   277,   130,    21,   190,   174,   175,     8,   136,
     137,   138,   139,   177,   178,     1,    21,   144,    18,   272,
      21,   150,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,    19,   130,   273,   198,   131,     8,     2,     3,
       4,   191,   285,    20,   203,   293,    39,   180,   181,    45,
     123,    46,   200,   192,   205,    22,   206,   124,     2,     3,
       4,   107,    96,   108,   110,   192,   228,   235,   233,   234,
     248,   236,   237,   107,    41,   108,     8,    22,   229,    47,
     108,   232,   123,   123,   167,   284,    23,   192,    31,   244,
      23,   230,   107,   199,   108,    43,   123,    23,   130,     1,
     114,   130,   113,   247,   130,    23,   182,   183,   245,   130,
     116,    44,   130,   130,   130,   204,   130,   229,   123,   108,
     123,     1,     2,     3,     4,   225,   258,   257,     1,   226,
      23,   130,   117,   289,   131,   151,   152,   153,   170,   171,
     172,   119,   265,   255,     2,     3,     4,   210,   211,   212,
     263,     2,     3,     4,   133,   281,   229,   199,   108,   134,
     130,   240,   135,   131,   143,   192,   123,   145,   207,    23,
     188,   268,   185,   186,   200,   121,    49,    50,    33,    51,
      52,    53,   271,   -73,   282,   189,   230,   299,   283,   154,
     194,   155,   192,   156,   193,   197,   224,     8,   238,   227,
     123,   239,   226,   130,   241,   246,   131,   124,   259,   291,
     130,   123,   294,   298,   296,   130,     8,   260,   297,   274,
      48,    49,    50,   288,    51,    52,    53,   275,   300,   261,
     276,   279,    68,   303,   304,   129,   286,     1,    69,    70,
      71,    72,    73,     2,     3,     4,    54,    55,    56,   287,
      57,    58,    59,    60,    61,    62,    63,    64,   295,   290,
       2,     3,     4,   210,   211,   212,   213,   214,   215,   301,
     302,    65,    66,   249,   250,    67,   126,    68,   252,   254,
     253,   120,   251,    69,    70,    71,    72,    73,    48,    49,
      50,   209,    51,    52,    53,   262,    31,    74,   208,     2,
       3,     4,   256,   147,    49,    50,   146,    51,    52,    53,
     196,     2,     3,     4,    54,    55,    56,   280,    57,    58,
      59,    60,    61,    62,    63,    64,   267,   266,     0,    54,
     210,   211,   212,   213,   214,   215,   270,     0,     0,    65,
      66,     0,     0,    67,     0,    68,     0,     0,     0,     0,
       0,    69,    70,    71,    72,    73,     0,     0,     0,     0,
      68,     0,   269,     0,    31,   195,    69,    70,    71,    72,
      73,    48,    49,    50,     0,    51,    52,    53,     0,     0,
     292,     0,     0,     0,     0,   121,    49,    50,     1,    51,
      52,    53,     0,     0,     2,     3,     4,    54,    55,    56,
       0,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,    65,    66,     0,     0,    67,     0,    68,     5,
       6,     0,     0,     0,    69,    70,    71,    72,    73,   147,
      49,    50,    68,    51,    52,    53,     0,    31,    69,    70,
      71,    72,    73,   147,    49,    50,     0,    51,    52,    53,
       0,   122,     0,     0,     0,    54,    55,    56,     0,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,     0,    67,     0,    68,     0,     0,     0,
       0,   192,    69,    70,    71,    72,    73,   147,    49,    50,
      68,    51,    52,    53,     0,    31,    69,    70,    71,    72,
      73,   121,    49,    50,     0,    51,    52,    53,     0,     0,
       0,     0,     0,    54,    55,    56,     0,    57,    58,    59,
      60,    61,    62,    63,    64,   121,    49,    50,     0,    51,
      52,    53,     0,     0,     0,     0,     0,     0,    65,    66,
       0,     0,    67,     0,    68,     0,     0,     0,     0,     0,
      69,    70,    71,    72,    73,     0,     0,     0,    68,     0,
       0,   202,     0,    31,    69,    70,    71,    72,    73,   121,
      49,    50,     0,    51,    52,    53,     0,     0,     0,     0,
       0,     0,    68,   242,     0,     0,     0,     0,    69,    70,
      71,    72,    73,   121,    49,    50,     0,    51,    52,    53,
       0,     0,     0,     0,   121,    49,    50,     0,    51,    52,
      53,     0,     0,     0,     0,     0,     0,     0,    29,     0,
      55,     1,     0,     0,     0,     0,    68,     0,     0,   264,
       0,     0,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     2,     3,     4,     0,     0,     0,
      68,     0,     0,     0,     0,     0,    69,    70,    71,    72,
      73,    68,     5,     6,     0,     0,     0,    69,    70,    71,
      72,    73
};

static const yytype_int16 yycheck[] =
{
      14,    46,    44,    11,    46,    78,    60,     0,    33,    44,
      23,    34,    46,   122,    56,    57,    58,    59,    11,    22,
      45,    34,    64,    60,    31,   110,    68,    28,     3,    66,
      67,    34,   235,    78,     3,    41,    68,    69,    31,    56,
      57,    58,    59,    10,    11,     3,     3,    64,     3,    65,
       3,    68,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,     3,   108,    80,     3,   108,    60,    26,    27,
      28,    77,    42,    82,   108,   278,    47,    12,    13,    60,
     122,    62,   107,    65,    60,    60,    62,   122,    26,    27,
      28,    60,    99,    62,   107,    65,   133,    79,   135,   136,
     173,   138,   139,    60,   107,    62,    99,    60,    60,   110,
      62,   134,   154,   155,    78,    63,    73,    65,    79,   154,
      73,   134,    60,    61,    62,    65,   168,    73,   173,     3,
       6,   176,    65,   168,   179,    73,    71,    72,   155,   184,
       3,    78,   187,   188,   189,   230,   191,    60,   190,    62,
     192,     3,    26,    27,    28,    61,   193,   192,     3,    65,
      73,   206,    79,   272,   206,     6,     7,     8,    73,    74,
      75,    61,   206,   190,    26,    27,    28,    48,    49,    50,
     205,    26,    27,    28,    81,   239,    60,    61,    62,    71,
     235,    61,    81,   235,     3,    65,   238,     3,    43,    73,
      66,   215,    14,    15,   229,     3,     4,     5,    60,     7,
       8,     9,   220,    81,    61,    76,   229,   290,    65,    60,
      82,    62,    65,    64,    81,    61,    61,   220,    82,    63,
     272,    56,    65,   278,     3,     3,   278,   272,    61,   276,
     285,   283,   279,   285,   281,   290,   239,    61,   283,     3,
       3,     4,     5,   267,     7,     8,     9,    72,   295,    63,
      32,    34,    60,   300,   301,    63,    61,     3,    66,    67,
      68,    69,    70,    26,    27,    28,    29,    30,    31,    63,
      33,    34,    35,    36,    37,    38,    39,    40,    82,    60,
      26,    27,    28,    48,    49,    50,    51,    52,    53,    57,
      61,    54,    55,   176,   179,    58,     3,    60,   187,   189,
     188,    43,   184,    66,    67,    68,    69,    70,     3,     4,
       5,   114,     7,     8,     9,    61,    79,    80,   113,    26,
      27,    28,   191,     3,     4,     5,    65,     7,     8,     9,
      99,    26,    27,    28,    29,    30,    31,   238,    33,    34,
      35,    36,    37,    38,    39,    40,   214,   213,    -1,    29,
      48,    49,    50,    51,    52,    53,   216,    -1,    -1,    54,
      55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,    -1,
      60,    -1,    80,    -1,    79,    80,    66,    67,    68,    69,
      70,     3,     4,     5,    -1,     7,     8,     9,    -1,    -1,
      80,    -1,    -1,    -1,    -1,     3,     4,     5,     3,     7,
       8,     9,    -1,    -1,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    58,    -1,    60,    44,
      45,    -1,    -1,    -1,    66,    67,    68,    69,    70,     3,
       4,     5,    60,     7,     8,     9,    -1,    79,    66,    67,
      68,    69,    70,     3,     4,     5,    -1,     7,     8,     9,
      -1,    79,    -1,    -1,    -1,    29,    30,    31,    -1,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    29,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    58,    -1,    60,    -1,    -1,    -1,
      -1,    65,    66,    67,    68,    69,    70,     3,     4,     5,
      60,     7,     8,     9,    -1,    79,    66,    67,    68,    69,
      70,     3,     4,     5,    -1,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,     3,     4,     5,    -1,     7,
       8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,
      -1,    -1,    58,    -1,    60,    -1,    -1,    -1,    -1,    -1,
      66,    67,    68,    69,    70,    -1,    -1,    -1,    60,    -1,
      -1,    63,    -1,    79,    66,    67,    68,    69,    70,     3,
       4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    60,    61,    -1,    -1,    -1,    -1,    66,    67,
      68,    69,    70,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     0,    -1,
      30,     3,    -1,    -1,    -1,    -1,    60,    -1,    -1,    63,
      -1,    -1,    66,    67,    68,    69,    70,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      60,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    60,    44,    45,    -1,    -1,    -1,    66,    67,    68,
      69,    70
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    26,    27,    28,    44,    45,   108,   109,   112,
     130,   141,   142,   143,   144,   145,   148,   149,     3,     3,
      82,     3,    60,    73,   110,   111,   113,   114,   115,     0,
     142,    79,   128,    60,   109,   116,   117,   118,   146,    47,
     150,   113,   115,    65,    78,    60,    62,   114,     3,     4,
       5,     7,     8,     9,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    54,    55,    58,    60,    66,
      67,    68,    69,    70,    80,    84,    85,    87,    88,    89,
      90,    92,    94,    96,    98,   100,   101,   102,   103,   104,
     106,   107,   125,   126,   127,   128,   130,   131,   132,   133,
     134,   136,   137,   138,   139,   140,   116,    60,    62,   113,
     115,   121,   122,    65,     6,   147,     3,    79,   151,    61,
     111,     3,    79,   103,   104,   123,     3,   116,   119,    63,
      87,   103,   107,    81,    71,    81,   106,   106,   106,   106,
     108,   125,   129,     3,   106,     3,   119,     3,   125,   125,
     106,     6,     7,     8,    60,    62,    64,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    78,   105,    89,
      73,    74,    75,    91,    68,    69,    93,    10,    11,    95,
      12,    13,    71,    72,    97,    14,    15,    99,    66,    76,
      41,    77,    65,    81,    82,    80,   132,    61,     3,    61,
     116,   121,    63,   107,   122,    60,    62,    43,   118,   112,
      48,    49,    50,    51,    52,    53,   152,   153,   154,   155,
     156,   157,   123,   124,    61,    61,    65,    63,   125,    60,
     115,   120,   121,   125,   125,    79,   125,   125,    82,    56,
      61,     3,    61,    86,   104,   106,     3,   104,    89,    90,
      92,    94,    96,    98,   100,   106,   101,   104,   125,    61,
      61,    63,    61,   116,    63,   107,   157,   146,   128,    80,
     153,   142,    65,    80,     3,    72,    32,   127,   135,    34,
     134,   108,    61,    65,    63,    42,    61,    63,   128,   123,
      60,   125,    80,   127,   125,    82,   125,   104,   103,    89,
     125,    57,    61,   125,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    84,    84,    84,    85,    85,    85,    85,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   107,   108,   109,   110,   110,   111,   111,
     112,   112,   112,   112,   113,   113,   114,   114,   114,   114,
     114,   114,   115,   115,   116,   116,   116,   117,   117,   118,
     118,   118,   119,   119,   120,   121,   121,   121,   122,   122,
     122,   122,   122,   122,   122,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     131,   131,   132,   132,   133,   133,   134,   134,   135,   135,
     136,   136,   136,   137,   137,   137,   138,   138,   138,   138,
     138,   139,   139,   140,   141,   141,   142,   142,   142,   143,
     144,   145,   146,   146,   147,   147,   148,   149,   150,   150,
     151,   152,   152,   153,   153,   153,   154,   155,   156,   156,
     157,   157,   157
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     7,     1,     3,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     3,     1,     3,     1,     5,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     1,     1,     3,     1,     3,
       1,     1,     1,     1,     2,     1,     1,     3,     4,     3,
       4,     4,     1,     2,     0,     1,     3,     1,     3,     2,
       2,     1,     1,     3,     1,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     3,     3,     3,     2,     3,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     2,
       3,     5,     5,     3,     5,     7,     2,     1,     1,     1,
       2,     5,     7,     2,     1,     2,     1,     1,     1,     2,
       3,     2,     1,     3,     0,     2,     3,     2,     0,     2,
       3,     1,     2,     2,     1,     1,     3,     2,     2,     1,
       1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (ast, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, LLCCEP_SiHi::ast **ast)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (ast);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, LLCCEP_SiHi::ast **ast)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, ast);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule, LLCCEP_SiHi::ast **ast)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              , ast);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, ast); \
} while (0)

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
#ifndef YYINITDEPTH
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, LLCCEP_SiHi::ast **ast)
{
  YYUSE (yyvaluep);
  YYUSE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yytype)
    {
          case 3: /* "identifier"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1586 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* "numeric value"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1592 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* "literal value"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1598 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* "->"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1604 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* "++"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1610 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* "--"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1616 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* "reinterpret_cast"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1622 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 10: /* "<<"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1628 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 11: /* ">>"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1634 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 12: /* "<="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1640 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 13: /* ">="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1646 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 14: /* "=="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1652 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 15: /* "!="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1658 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 16: /* "*="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1664 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 17: /* "/="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1670 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 18: /* "%="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1676 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 19: /* "+="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1682 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 20: /* "-="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1688 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 21: /* "<<="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1694 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 22: /* ">>="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1700 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 23: /* "&="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1706 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 24: /* "^="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1712 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 25: /* "|="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1718 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 26: /* "empty"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1724 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 27: /* "real"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1730 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 28: /* "string"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1736 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 29: /* "other"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1742 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 30: /* "pass"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1748 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 31: /* "if"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1754 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 32: /* "else"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1760 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 33: /* "case"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1766 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 34: /* "while"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1772 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 35: /* "do"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1778 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 36: /* "for"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1784 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 37: /* "jump"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1790 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 38: /* "next"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1796 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 39: /* "stop"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1802 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 40: /* "return"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1808 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 41: /* "done"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1814 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 42: /* "unless"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1820 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 43: /* "vararg"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1826 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 44: /* "function"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1832 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 45: /* "class"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1838 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 46: /* "typealias"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1844 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 47: /* "<-"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1850 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 48: /* "public"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1856 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 49: /* "private"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1862 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 50: /* "protected"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1868 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 51: /* "static"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1874 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 52: /* "init"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1880 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 53: /* "deinit"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1886 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 54: /* "release"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1892 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 55: /* "try"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1898 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 56: /* "catch"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1904 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 57: /* "finally"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1910 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 58: /* "throw"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1916 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 59: /* "asm"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1922 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;


      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (LLCCEP_SiHi::ast **ast)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 150 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
                    }
#line 2205 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 152 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), NUMBER}};
                    }
#line 2213 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 154 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), LITERAL}};
                    }
#line 2221 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 156 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2229 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 160 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
	            }
#line 2237 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 162 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                    }
#line 2245 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 164 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {(yyvsp[-2].ast)}};
		    }
#line 2253 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 166 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                    }
#line 2261 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 168 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_LEXEM, {(yyvsp[-2].ast), createAst{createLexem{(yyvsp[0].string), ID}}}};
                    }
#line 2269 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 170 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR_LEXEM, {(yyvsp[-2].ast), createAst{createLexem{(yyvsp[0].string), ID}}}};
                    }
#line 2277 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 172 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_INCREMENT_LEXEM, {(yyvsp[-1].ast)}};
                    }
#line 2285 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 174 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_DECREMENT_LEXEM, {(yyvsp[-1].ast)}};
                    }
#line 2293 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 178 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                (yyval.ast) = createAst{ARGUMENT_EXPRESSION_LIST_LEXEM, {(yyvsp[0].ast)}};
                        }
#line 2301 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 180 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                (yyval.ast) = (yyvsp[-2].ast);
                                (yyval.ast)->addChild((yyvsp[0].ast));
                        }
#line 2310 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 185 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                }
#line 2318 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 187 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-1].ast);
                        (yyval.ast)->addChild((yyvsp[0].ast));
		}
#line 2327 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 192 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), INCREMENT}}}};
              }
#line 2335 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 194 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), DECREMENT}}}};
	      }
#line 2343 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 196 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '&'}}}};
	      }
#line 2351 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 198 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '@'}}}};
              }
#line 2359 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 200 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '+'}}}};
              }
#line 2367 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 202 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '-'}}}};
              }
#line 2375 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 204 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '~'}}}};
	      }
#line 2383 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 208 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[0].ast);
	       }
#line 2391 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 210 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = createAst{CAST_EXPRESSION_LEXEM, {(yyvsp[-4].ast), (yyvsp[-1].ast)}};
               }
#line 2399 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 214 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[0].ast);
                         }
#line 2407 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 216 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[-1].ast); 
                                  (yyval.ast)->addChild((yyvsp[-2].ast)); 
                                  (yyval.ast)->addChild((yyvsp[0].ast));
                         }
#line 2417 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 222 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '*'}}}};
                       }
#line 2425 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 224 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '/'}}}};
                       }
#line 2433 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 226 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '%'}}}};
                       }
#line 2441 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 230 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
                   }
#line 2449 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 232 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-1].ast);
                           (yyval.ast)->addChild((yyvsp[-2].ast));
                           (yyval.ast)->addChild((yyvsp[0].ast));
                   }
#line 2459 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 238 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '+'}}}};
                 }
#line 2467 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 240 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '-'}}}};
                 }
#line 2475 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 244 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = (yyvsp[0].ast);
	        }
#line 2483 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 246 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = (yyvsp[-1].ast);
                         (yyval.ast)->addChild((yyvsp[-2].ast));
                         (yyval.ast)->addChild((yyvsp[0].ast));
                }
#line 2493 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 252 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), SHL}}}};
              }
#line 2501 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 254 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), SHR}}}};
              }
#line 2509 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 258 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
	             }
#line 2517 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 260 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[-1].ast);
                             (yyval.ast)->addChild((yyvsp[-2].ast));
                             (yyval.ast)->addChild((yyvsp[0].ast));
                     }
#line 2527 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 266 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '<'}}}};
                   }
#line 2535 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 268 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '>'}}}}; 
                   }
#line 2543 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 270 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), LESS_EQUAL}}}};
                   }
#line 2551 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 272 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), ABOVE_EQUAL}}}};
	           }
#line 2559 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 276 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 2567 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 278 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-1].ast);
                           (yyval.ast)->addChild((yyvsp[-2].ast));
                           (yyval.ast)->addChild((yyvsp[0].ast));
                   }
#line 2577 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 284 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		         (yyval.ast) = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), EQUALS}}}};
                 }
#line 2585 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 286 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), NOT_EQUALS}}}};
                 }
#line 2593 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 290 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = (yyvsp[0].ast);
	      }
#line 2601 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 292 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{AND_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
              }
#line 2609 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 296 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		               (yyval.ast) = (yyvsp[0].ast);
  	               }
#line 2617 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 298 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{EXCLUSIVE_OR_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                       }
#line 2625 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 302 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		               (yyval.ast) = (yyvsp[0].ast);
 	               }
#line 2633 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 304 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{INCLUSIVE_OR_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                       }
#line 2641 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 308 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = (yyvsp[0].ast);
	              }
#line 2649 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 310 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    { 
                              (yyval.ast) = createAst{CONDITIONAL_EXPRESSION_LEXEM, {(yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
                      }
#line 2657 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 314 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		             (yyval.ast) = (yyvsp[0].ast);
	             }
#line 2665 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 316 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{ASSIGNMENT_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                     }
#line 2673 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 320 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = createAst{createLexem{"=", '='}};
	           }
#line 2681 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 322 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"*=", MUL_ASSIGN}};
	           }
#line 2689 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 324 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"/=", DIV_ASSIGN}};
	           }
#line 2697 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 326 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"%=", MOD_ASSIGN}};
	           }
#line 2705 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 328 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"+=", ADD_ASSIGN}};
	           }
#line 2713 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 330 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"-=", SUB_ASSIGN}};
	           }
#line 2721 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 332 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"<<=", SHL_ASSIGN}};
	           }
#line 2729 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 334 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{">>=", SHR_ASSIGN}};
	           }
#line 2737 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 336 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"&=", AND_ASSIGN}};
	           }
#line 2745 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 338 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"^=", XOR_ASSIGN}};
	           }
#line 2753 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 340 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"|=", OR_ASSIGN}};
                   }
#line 2761 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 344 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = (yyvsp[0].ast);
  	  }
#line 2769 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 346 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                  (yyval.ast) = createAst{EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
          }
#line 2777 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 350 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
		   }
#line 2785 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 354 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}}; 
           }
#line 2793 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 358 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = (yyvsp[0].ast);
		      }
#line 2801 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 362 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = createAst{INIT_DECLARATOR_LIST_LEXEM, {(yyvsp[0].ast)}};
	            }
#line 2809 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 364 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-2].ast);
                            (yyval.ast)->addChild((yyvsp[-1].ast));
                    }
#line 2818 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 369 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = (yyvsp[0].ast);
	       }
#line 2826 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 371 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = createAst{INIT_DECLARATOR_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
               }
#line 2834 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 375 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = createAst{createLexem{(yyvsp[0].string), EMPTY}};
   	      }
#line 2842 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 377 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), REAL}};
	      }
#line 2850 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 379 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), STRING}};
	      }
#line 2858 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 381 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
              }
#line 2866 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 385 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = createAst{DECLARATOR_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
	  }
#line 2874 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 387 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                  (yyval.ast) = (yyvsp[0].ast);
          }
#line 2882 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 391 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		         (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
 	         }
#line 2890 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 393 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_SCOPED_LEXEM, {(yyvsp[-1].ast)}};
                 }
#line 2898 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 395 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_ARRAYED_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                 }
#line 2906 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 397 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_AUTO_ARRAYED_LEXEM, {(yyvsp[-2].ast)}};
	         }
#line 2914 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 399 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_PARAMETERS_LIST_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                 }
#line 2922 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 401 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_IDENTIFIERS_LIST_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
	         }
#line 2930 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 405 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = createAst{POINTER_LEXEM};
       }
#line 2938 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 407 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = createAst{POINTER_LEXEM, {(yyvsp[0].ast)}};
       }
#line 2946 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 412 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = createAst(PARAMETER_TYPE_LIST_LEXEM, {});
		   }
#line 2954 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 414 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 2962 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 416 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-2].ast);
                           (yyval.ast)->addChild(createAst{createLexem{"...", VARARG}});
                   }
#line 2971 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 421 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{PARAMETER_LIST_LEXEM, {(yyvsp[0].ast)}};
	      }
#line 2979 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 423 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = (yyvsp[-2].ast);
                      (yyval.ast)->addChild((yyvsp[0].ast));
              }
#line 2988 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 428 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
		     }
#line 2996 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 430 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                     }
#line 3004 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 432 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[0].ast)}};
                     }
#line 3012 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 436 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = createAst{IDENTIFIER_LIST_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
	       }
#line 3020 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 438 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[-2].ast);
                       (yyval.ast)->addChild(createAst{createLexem{(yyvsp[0].string), ID}});
               }
#line 3029 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 443 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3037 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 447 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
 	           }
#line 3045 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 449 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 3053 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 451 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3061 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 455 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			          (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  }
#line 3069 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 457 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  }
#line 3077 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 459 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3085 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 461 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3093 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 463 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                          }
#line 3101 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 465 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
                          }
#line 3109 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 467 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-1].ast)}};
                          }
#line 3117 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 469 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3125 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 471 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast)}};
                          }
#line 3133 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 475 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = (yyvsp[0].ast);
           }
#line 3141 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 477 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = (yyvsp[-1].ast);
           }
#line 3149 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 481 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{INITIALIZER_LIST_LEXEM, {(yyvsp[0].ast)}};
                }
#line 3157 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 483 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-2].ast);
                        (yyval.ast)->addChild((yyvsp[-1].ast));
                }
#line 3166 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 488 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3174 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 490 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3182 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 492 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3190 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 494 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3198 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 496 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3206 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 498 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3214 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 500 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3222 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 502 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3230 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 504 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3238 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 508 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = createAst{RELEASEMENT_LEXEM, {(yyvsp[0].ast)}};
                     }
#line 3246 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 512 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {createAst{createLexem{(yyvsp[-2].string), ID}}, (yyvsp[0].ast)}};
                 }
#line 3254 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 514 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                 }
#line 3262 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 516 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
                 }
#line 3270 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 520 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                          (yyval.ast) = 0;
                  }
#line 3278 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 522 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                          (yyval.ast) = (yyvsp[-1].ast);
                  }
#line 3286 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 526 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
                     }
#line 3294 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 528 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
                     }
#line 3302 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 532 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			             (yyval.ast) = (yyvsp[-1].ast);
                              }
#line 3310 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 534 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                     (yyval.ast) = (yyvsp[0].ast);
                              }
#line 3318 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 538 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			          (yyval.ast) = (yyvsp[-1].ast);
                            }
#line 3326 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 540 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[0].ast);
                            }
#line 3334 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 544 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
					        (yyval.ast) = (yyvsp[0].ast);
					}
#line 3342 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 546 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                                (yyval.ast) = (yyvsp[0].ast);
                                        }
#line 3350 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 550 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DECLARATION_STATEMENT_LIST_LEXEM, {(yyvsp[0].ast)}};
                          }
#line 3358 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 552 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[-1].ast);
                                  (yyval.ast)->addChild((yyvsp[0].ast));
                          }
#line 3367 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 557 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{PASS_STATEMENT_LEXEM};
                    }
#line 3375 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 559 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3383 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 563 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                              (yyval.ast) = createAst{LABELED_STATEMENT_LIST_LEXEM, {(yyvsp[0].ast)}};
                      }
#line 3391 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 565 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                              (yyval.ast) = (yyvsp[-1].ast);
 	                      (yyval.ast)->addChild((yyvsp[0].ast));
                      }
#line 3400 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 570 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3408 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 572 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
                   }
#line 3416 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 574 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                   }
#line 3424 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 578 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                }
#line 3432 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 580 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
	        }
#line 3440 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 582 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                }
#line 3448 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 586 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{JUMP_STATEMENT_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
              }
#line 3456 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 588 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{NEXT_STATEMENT_LEXEM};
              }
#line 3464 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 590 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{STOP_STATEMENT_LEXEM};
              }
#line 3472 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 592 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{RETURN_STATEMENT_LEXEM};
	      }
#line 3480 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 594 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{RETURN_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
              }
#line 3488 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 598 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			            (yyval.ast) = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
			    }
#line 3496 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 600 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                    (yyval.ast) = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {(yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast)}};
                            }
#line 3504 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 604 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			         (yyval.ast) = createAst{EXCEPTION_THROW_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
			 }
#line 3512 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 608 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        *ast = (yyval.ast) = createAst{EXTERNAL_DECLARATION_LEXEM, {(yyvsp[0].ast)}};
                }
#line 3520 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 610 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-1].ast);
                        (yyval.ast)->addChild((yyvsp[0].ast));
                }
#line 3529 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 615 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3537 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 617 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3545 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 619 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3553 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 623 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{FUNCTION_DEFINITION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3561 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 627 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{FUNCTION_SIGNATURE_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                  }
#line 3569 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 631 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = createAst{FUNCTION_NAME_LEXEM, 
                                    {createAst{createLexem{(yyvsp[0].string), ID}}}};
	     }
#line 3578 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 636 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = (yyvsp[0].ast);
	     }
#line 3586 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 638 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                     (yyval.ast) = (yyvsp[-1].ast);
             }
#line 3594 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 642 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = createAst{FUNCTION_TYPE_LEXEM, {createAst{createLexem{"Empty", EMPTY}}}};
             }
#line 3602 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 644 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                     (yyval.ast) = createAst{FUNCTION_TYPE_LEXEM, {(yyvsp[0].ast)}};
             }
#line 3610 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 648 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		        (yyval.ast) = createAst{CLASS_DECLARATION_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                 }
#line 3618 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 652 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	         (yyval.ast) = createAst{CLASSNAME_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
         }
#line 3626 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 656 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{PREDECESSOR_LEXEM};
           }
#line 3634 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 658 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{PREDECESSOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
           }
#line 3642 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 662 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = (yyvsp[-1].ast);
          }
#line 3650 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 666 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = createAst{METHOD_PROPERTY_LIST_LEXEM, {(yyvsp[0].ast)}};
		    }
#line 3658 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 668 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-1].ast);
                            (yyval.ast)->addChild((yyvsp[0].ast));
                    }
#line 3667 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 673 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = createAst{METHOD_PROPERTY_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
               }
#line 3675 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 675 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[0].ast);
               }
#line 3683 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 677 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[0].ast);
               }
#line 3691 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 681 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	                (yyval.ast) = createAst{INIT_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                }
#line 3699 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 685 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		          (yyval.ast) = createAst{DEINIT_LEXEM, {(yyvsp[0].ast)}};
                  }
#line 3707 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 689 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			           (yyval.ast) = (yyvsp[0].ast);
                                   (yyval.ast)->addChild(createAst{createLexem{"static", STATIC}});
                           }
#line 3716 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 189:
#line 692 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                   (yyval.ast) = (yyvsp[0].ast);
                           }
#line 3724 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 190:
#line 696 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"public", PUBLIC}}}};
           }
#line 3732 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 191:
#line 698 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"protected", PROTECTED}}}};
           }
#line 3740 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 192:
#line 700 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"private", PRIVATE}}}};
           }
#line 3748 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;


#line 3752 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
  }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (ast, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (ast, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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
                      yytoken, &yylval, ast);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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
                  yystos[yystate], yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, ast);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 703 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1906  */

