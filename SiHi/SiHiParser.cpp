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
    RELEASE = 307,
    TRY = 308,
    CATCH = 309,
    FINALLY = 310,
    THROW = 311,
    ASM = 312
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:355  */

	::LLCCEP_SiHi::ast *ast;
	char *string;

#line 181 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (LLCCEP_SiHi::ast **ast);

#endif /* !YY_YY_USERS_ANDREW_DOCUMENTS_PROJECTS_PERSONAL_LLCCEP_SIHI_SIHIPARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 198 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:358  */

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
#define YYLAST   769

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  81
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  73
/* YYNRULES -- Number of rules.  */
#define YYNRULES  188
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  298

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    73,    64,     2,
      58,    59,    71,    66,    63,    67,    62,    72,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    79,    80,
      69,    76,    70,     2,    65,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,    74,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    77,    75,    78,    68,     2,     2,     2,
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
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   147,   147,   149,   151,   153,   157,   159,   161,   163,
     165,   167,   169,   171,   175,   177,   182,   184,   189,   191,
     193,   195,   197,   199,   201,   205,   207,   211,   213,   219,
     221,   223,   227,   229,   235,   237,   241,   243,   249,   251,
     255,   257,   263,   265,   267,   269,   273,   275,   281,   283,
     287,   289,   293,   295,   299,   301,   305,   307,   311,   313,
     317,   319,   321,   323,   325,   327,   329,   331,   333,   335,
     337,   341,   343,   347,   351,   355,   359,   361,   366,   368,
     372,   374,   376,   378,   382,   384,   388,   390,   392,   394,
     396,   398,   402,   404,   409,   411,   413,   418,   420,   425,
     427,   429,   433,   435,   440,   444,   446,   448,   452,   454,
     456,   458,   460,   462,   464,   466,   468,   472,   474,   478,
     480,   485,   487,   489,   491,   493,   495,   497,   499,   501,
     505,   509,   511,   513,   517,   519,   523,   525,   529,   531,
     535,   537,   541,   543,   547,   549,   554,   556,   560,   562,
     567,   569,   571,   575,   577,   579,   583,   585,   587,   589,
     591,   595,   597,   601,   605,   607,   612,   614,   616,   620,
     624,   628,   633,   635,   639,   641,   645,   649,   653,   655,
     659,   663,   665,   670,   674,   677,   681,   683,   685
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
  "\"protected\"", "\"static\"", "\"release\"", "\"try\"", "\"catch\"",
  "\"finally\"", "\"throw\"", "\"asm\"", "'('", "')'", "'['", "']'", "'.'",
  "','", "'&'", "'@'", "'+'", "'-'", "'~'", "'<'", "'>'", "'*'", "'/'",
  "'%'", "'^'", "'|'", "'='", "'{'", "'}'", "':'", "';'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "multiplicative_operator",
  "additive_expression", "additive_operator", "shift_expression",
  "shift_operator", "relational_expression", "relational_operator",
  "equality_expression", "equality_operator", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
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
  "access_rule_optional_static", "access_rule", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,    40,    41,
      91,    93,    46,    44,    38,    64,    43,    45,   126,    60,
      62,    42,    47,    37,    94,   124,    61,   123,   125,    58,
      59
};
# endif

#define YYPACT_NINF -199

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-199)))

#define YYTABLE_NINF -74

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     156,  -199,  -199,  -199,  -199,    21,    44,   -27,    28,  -199,
    -199,   150,  -199,  -199,     1,   145,  -199,    13,  -199,  -199,
    -199,  -199,    28,    24,    55,  -199,    60,    79,    26,  -199,
    -199,   242,  -199,   190,    27,  -199,    77,  -199,   138,   149,
      81,   109,  -199,    28,   403,   232,   535,    79,   100,  -199,
    -199,  -199,  -199,   117,   108,  -199,   668,   668,   668,   668,
     389,   199,  -199,  -199,   668,   208,   521,   521,   668,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,   107,   693,   668,  -199,
      84,   -25,   118,    39,   160,   155,   151,    -3,   152,  -199,
     161,   153,   147,  -199,  -199,  -199,  -199,  -199,  -199,   308,
    -199,  -199,  -199,  -199,  -199,  -199,   171,    17,   559,  -199,
      23,  -199,   104,   178,   190,  -199,  -199,   215,  -199,  -199,
    -199,  -199,   403,  -199,  -199,  -199,  -199,   180,    -9,  -199,
    -199,  -199,   179,   521,    22,   521,   455,    -4,   455,   455,
    -199,  -199,   168,  -199,   161,  -199,   189,   100,   200,  -199,
      61,   250,  -199,  -199,   601,   668,   254,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,   668,  -199,
    -199,  -199,  -199,   668,  -199,  -199,   668,  -199,  -199,   668,
    -199,  -199,  -199,  -199,   668,  -199,  -199,   668,   668,   668,
     668,   668,   668,   521,  -199,  -199,  -199,  -199,  -199,  -199,
     224,   225,  -199,   206,   104,    43,   625,  -199,  -199,  -199,
    -199,  -199,  -199,   148,   164,  -199,   156,  -199,  -199,   -14,
    -199,  -199,   271,  -199,  -199,    63,   132,   216,  -199,  -199,
     253,   469,  -199,   255,   640,   190,  -199,  -199,  -199,    72,
    -199,   159,  -199,  -199,  -199,    84,   -25,   118,    39,   160,
     155,    -2,   151,  -199,  -199,  -199,  -199,  -199,  -199,   228,
    -199,   227,  -199,  -199,  -199,  -199,   403,  -199,  -199,   233,
     521,  -199,   323,   521,   210,   521,  -199,   668,  -199,   668,
    -199,  -199,  -199,   668,  -199,  -199,  -199,  -199,   521,   237,
    -199,  -199,   234,   521,   521,  -199,  -199,  -199
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
     186,   188,   187,     0,     0,   181,     0,   185,   119,     0,
      90,    91,     0,    88,   131,     0,   105,     0,   104,   133,
     150,     0,   153,     0,     0,     0,     5,    11,     8,     0,
      14,     0,    10,    59,    28,    33,    37,    41,    47,    51,
      53,     0,    55,    72,   132,   114,   108,   110,   115,     0,
     111,     0,   184,   180,   182,   183,     0,   118,   103,     0,
       0,   148,     0,     0,     0,     0,     9,     0,     7,     0,
     116,   112,   120,     0,   151,   152,   149,   154,     0,   161,
      15,    57,     0,     0,     0,    26,   155,   162
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -199,  -199,  -199,  -199,   -46,  -199,   -76,   120,  -199,   122,
    -199,   113,  -199,   112,  -199,   114,  -199,   115,   123,  -199,
     -43,   -22,  -199,    -1,   -40,   -55,     3,  -199,   260,   191,
     -11,   -16,   -15,    -6,  -199,   205,   256,  -199,   -17,  -100,
    -115,  -199,   -32,  -199,  -198,   309,  -199,     6,  -199,   223,
    -199,    90,  -199,  -199,  -199,  -199,  -199,  -199,  -199,    -7,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
     111,  -199,   116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    75,    76,   239,    77,    78,    79,    80,   173,    81,
     176,    82,   179,    83,   184,    84,   187,    85,    86,    87,
      88,    89,   168,    90,    91,     7,     8,    24,    25,     9,
      26,    27,    28,   200,    36,    37,   128,   227,   201,   112,
     125,   219,    92,    93,    94,    95,   142,    10,    97,    98,
      99,   100,   272,   101,   102,   103,   104,   105,    11,    12,
      13,    14,    15,    38,   115,    16,    17,    40,   118,   214,
     215,   216,   217
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     130,   123,   169,   131,    30,   140,   132,   218,    42,    35,
     204,    41,    47,   123,   123,   123,   123,   111,    34,   110,
     198,   123,   124,   109,    18,   123,    21,   106,   141,    21,
      21,    21,   130,   271,   148,   149,    34,    96,   190,   127,
     279,   174,   175,     2,     3,     4,     1,    19,    34,   266,
     221,   180,   181,    20,   222,   136,   137,   138,   139,   192,
      39,   192,   130,   144,   267,   131,     1,   150,   203,     2,
       3,     4,   191,   231,   286,   107,   199,   108,    31,   123,
     225,   107,   108,   108,    22,   107,    22,   108,    23,     2,
       3,     4,   110,    23,    47,    23,    41,   244,    23,    23,
     124,   224,   258,   229,   230,    96,   232,   233,   182,   183,
      34,   123,   123,   151,   152,   153,    34,   228,    43,   226,
     236,   225,   199,   108,   192,   123,   204,   130,   177,   178,
     130,   276,   240,   130,    23,   277,    44,    45,   130,    46,
     113,   130,   130,   130,   114,   130,   243,   123,     1,   123,
      29,   282,   116,     1,   241,   170,   171,   172,   117,     1,
     130,   254,   205,   131,   206,   154,   261,   155,   119,   156,
     253,     2,     3,     4,   185,   186,     2,     3,     4,   133,
     275,     1,     2,     3,     4,   130,   134,   135,   131,   251,
     225,   123,   108,     1,     5,     6,   210,   211,   212,   259,
       5,     6,   143,    33,     2,     3,     4,   292,    34,   265,
     226,   145,   210,   211,   212,   213,     2,     3,     4,   188,
     278,   207,   192,   123,   192,   189,   130,   194,    34,   131,
     197,   -73,   193,   130,   123,   126,   291,   130,   284,   220,
     223,   287,   263,   289,   124,    48,    49,    50,   234,    51,
      52,    53,   222,   237,   235,   290,   293,   242,     2,     3,
       4,   296,   297,   210,   211,   212,   213,   257,     2,     3,
       4,    54,    55,    56,   268,    57,    58,    59,    60,    61,
      62,    63,    64,   255,   256,   270,   269,   280,   281,   273,
     288,   283,   294,   295,    65,    66,   245,   247,    67,   248,
      68,   246,   249,   120,   250,   209,    69,    70,    71,    72,
      73,    48,    49,    50,   252,    51,    52,    53,   208,    31,
      74,   146,   196,    32,   274,   264,   147,    49,    50,   262,
      51,    52,    53,     0,     2,     3,     4,    54,    55,    56,
       0,    57,    58,    59,    60,    61,    62,    63,    64,     0,
       0,     0,    54,     0,     0,     0,     0,     0,     0,     0,
      65,    66,     0,     0,    67,     0,    68,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,     0,     0,
       0,    68,     0,     0,     0,    31,   195,    69,    70,    71,
      72,    73,    48,    49,    50,     0,    51,    52,    53,     0,
       0,   285,     0,     0,     0,     0,   121,    49,    50,     0,
      51,    52,    53,     0,     0,     2,     3,     4,    54,    55,
      56,     0,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    66,     0,     0,    67,     0,    68,     0,     0,
       0,     0,     0,    69,    70,    71,    72,    73,   147,    49,
      50,    68,    51,    52,    53,     0,    31,    69,    70,    71,
      72,    73,   147,    49,    50,     0,    51,    52,    53,     0,
     122,     0,     0,     0,    54,    55,    56,     0,    57,    58,
      59,    60,    61,    62,    63,    64,     0,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,    65,    66,     0,
       0,    67,     0,    68,     0,     0,     0,     0,   192,    69,
      70,    71,    72,    73,   147,    49,    50,    68,    51,    52,
      53,     0,    31,    69,    70,    71,    72,    73,   121,    49,
      50,     0,    51,    52,    53,     0,     0,     0,     0,     0,
      54,    55,    56,     0,    57,    58,    59,    60,    61,    62,
      63,    64,   121,    49,    50,     0,    51,    52,    53,     0,
       0,     0,     0,    65,    66,     0,     0,    67,     0,    68,
       0,     0,     0,     0,     0,    69,    70,    71,    72,    73,
       0,     0,     0,    68,     0,     0,   129,     0,    31,    69,
      70,    71,    72,    73,   121,    49,    50,     0,    51,    52,
      53,     0,     0,     0,     0,     0,     0,    68,     0,     0,
     202,     0,     0,    69,    70,    71,    72,    73,   121,    49,
      50,     0,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,   121,    49,    50,     0,    51,    52,    53,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    68,
     238,     0,     0,     0,     0,    69,    70,    71,    72,    73,
      55,   121,    49,    50,     0,    51,    52,    53,     0,     0,
       0,     0,     0,    68,     0,     0,   260,     0,     0,    69,
      70,    71,    72,    73,     0,     0,     0,     0,    68,     0,
       0,     0,     0,     0,    69,    70,    71,    72,    73,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,     0,
       0,     0,     0,     0,     0,     0,    68,     0,     0,     0,
       0,     0,    69,    70,    71,    72,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   167
};

static const yytype_int16 yycheck[] =
{
      46,    44,    78,    46,    11,    60,    46,   122,    23,    15,
     110,    22,    28,    56,    57,    58,    59,    34,    15,    34,
       3,    64,    44,    34,     3,    68,     3,    33,    60,     3,
       3,     3,    78,   231,    66,    67,    33,    31,    41,    45,
      42,    66,    67,    26,    27,    28,     3,     3,    45,    63,
      59,    12,    13,    80,    63,    56,    57,    58,    59,    63,
      47,    63,   108,    64,    78,   108,     3,    68,   108,    26,
      27,    28,    75,    77,   272,    58,    59,    60,    77,   122,
      58,    58,    60,    60,    58,    58,    58,    60,    71,    26,
      27,    28,   107,    71,   110,    71,   107,   173,    71,    71,
     122,   133,    59,   135,   136,    99,   138,   139,    69,    70,
     107,   154,   155,     6,     7,     8,   113,   134,    63,   134,
      59,    58,    59,    60,    63,   168,   226,   173,    10,    11,
     176,    59,   154,   179,    71,    63,    76,    58,   184,    60,
      63,   187,   188,   189,     6,   191,   168,   190,     3,   192,
       0,   266,     3,     3,   155,    71,    72,    73,    77,     3,
     206,   193,    58,   206,    60,    58,   206,    60,    59,    62,
     192,    26,    27,    28,    14,    15,    26,    27,    28,    79,
     235,     3,    26,    27,    28,   231,    69,    79,   231,   190,
      58,   234,    60,     3,    44,    45,    48,    49,    50,   205,
      44,    45,     3,    58,    26,    27,    28,   283,   205,   216,
     225,     3,    48,    49,    50,    51,    26,    27,    28,    64,
      61,    43,    63,   266,    63,    74,   272,    80,   225,   272,
      59,    79,    79,   279,   277,     3,   279,   283,   270,    59,
      61,   273,    78,   275,   266,     3,     4,     5,    80,     7,
       8,     9,    63,     3,    54,   277,   288,     3,    26,    27,
      28,   293,   294,    48,    49,    50,    51,    61,    26,    27,
      28,    29,    30,    31,     3,    33,    34,    35,    36,    37,
      38,    39,    40,    59,    59,    32,    70,    59,    61,    34,
      80,    58,    55,    59,    52,    53,   176,   184,    56,   187,
      58,   179,   188,    43,   189,   114,    64,    65,    66,    67,
      68,     3,     4,     5,   191,     7,     8,     9,   113,    77,
      78,    65,    99,    14,   234,   214,     3,     4,     5,   213,
       7,     8,     9,    -1,    26,    27,    28,    29,    30,    31,
      -1,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    77,    78,    64,    65,    66,
      67,    68,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    78,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    -1,    -1,    26,    27,    28,    29,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    56,    -1,    58,    -1,    -1,
      -1,    -1,    -1,    64,    65,    66,    67,    68,     3,     4,
       5,    58,     7,     8,     9,    -1,    77,    64,    65,    66,
      67,    68,     3,     4,     5,    -1,     7,     8,     9,    -1,
      77,    -1,    -1,    -1,    29,    30,    31,    -1,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    56,    -1,    58,    -1,    -1,    -1,    -1,    63,    64,
      65,    66,    67,    68,     3,     4,     5,    58,     7,     8,
       9,    -1,    77,    64,    65,    66,    67,    68,     3,     4,
       5,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      29,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,    58,
      -1,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    77,    64,
      65,    66,    67,    68,     3,     4,     5,    -1,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    -1,    -1,    64,    65,    66,    67,    68,     3,     4,
       5,    -1,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,     8,     9,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      59,    -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,
      30,     3,     4,     5,    -1,     7,     8,     9,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    -1,    -1,    64,
      65,    66,    67,    68,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    -1,    -1,    64,    65,    66,    67,    68,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      -1,    -1,    64,    65,    66,    67,    68,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    26,    27,    28,    44,    45,   106,   107,   110,
     128,   139,   140,   141,   142,   143,   146,   147,     3,     3,
      80,     3,    58,    71,   108,   109,   111,   112,   113,     0,
     140,    77,   126,    58,   107,   114,   115,   116,   144,    47,
     148,   111,   113,    63,    76,    58,    60,   112,     3,     4,
       5,     7,     8,     9,    29,    30,    31,    33,    34,    35,
      36,    37,    38,    39,    40,    52,    53,    56,    58,    64,
      65,    66,    67,    68,    78,    82,    83,    85,    86,    87,
      88,    90,    92,    94,    96,    98,    99,   100,   101,   102,
     104,   105,   123,   124,   125,   126,   128,   129,   130,   131,
     132,   134,   135,   136,   137,   138,   114,    58,    60,   111,
     113,   119,   120,    63,     6,   145,     3,    77,   149,    59,
     109,     3,    77,   101,   102,   121,     3,   114,   117,    61,
      85,   101,   105,    79,    69,    79,   104,   104,   104,   104,
     106,   123,   127,     3,   104,     3,   117,     3,   123,   123,
     104,     6,     7,     8,    58,    60,    62,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    76,   103,    87,
      71,    72,    73,    89,    66,    67,    91,    10,    11,    93,
      12,    13,    69,    70,    95,    14,    15,    97,    64,    74,
      41,    75,    63,    79,    80,    78,   130,    59,     3,    59,
     114,   119,    61,   105,   120,    58,    60,    43,   116,   110,
      48,    49,    50,    51,   150,   151,   152,   153,   121,   122,
      59,    59,    63,    61,   123,    58,   113,   118,   119,   123,
     123,    77,   123,   123,    80,    54,    59,     3,    59,    84,
     102,   104,     3,   102,    87,    88,    90,    92,    94,    96,
      98,   104,    99,   102,   123,    59,    59,    61,    59,   114,
      61,   105,   153,    78,   151,   140,    63,    78,     3,    70,
      32,   125,   133,    34,   132,   106,    59,    63,    61,    42,
      59,    61,   121,    58,   123,    78,   125,   123,    80,   123,
     102,   101,    87,   123,    55,    59,   123,   123
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    81,    82,    82,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
      89,    89,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    95,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   104,   104,   105,   106,   107,   108,   108,   109,   109,
     110,   110,   110,   110,   111,   111,   112,   112,   112,   112,
     112,   112,   113,   113,   114,   114,   114,   115,   115,   116,
     116,   116,   117,   117,   118,   119,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     124,   125,   125,   125,   126,   126,   127,   127,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     134,   134,   134,   135,   135,   135,   136,   136,   136,   136,
     136,   137,   137,   138,   139,   139,   140,   140,   140,   141,
     142,   143,   144,   144,   145,   145,   146,   147,   148,   148,
     149,   150,   150,   151,   152,   152,   153,   153,   153
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
       3,     1,     2,     2,     2,     1,     1,     1,     1
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
#line 1585 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 4: /* "numeric value"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1591 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 5: /* "literal value"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1597 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 6: /* "->"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1603 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 7: /* "++"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1609 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 8: /* "--"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1615 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 9: /* "reinterpret_cast"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1621 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 10: /* "<<"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1627 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 11: /* ">>"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1633 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 12: /* "<="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1639 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 13: /* ">="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1645 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 14: /* "=="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1651 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 15: /* "!="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1657 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 16: /* "*="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1663 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 17: /* "/="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1669 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 18: /* "%="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1675 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 19: /* "+="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1681 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 20: /* "-="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1687 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 21: /* "<<="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1693 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 22: /* ">>="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1699 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 23: /* "&="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1705 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 24: /* "^="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1711 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 25: /* "|="  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1717 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 26: /* "empty"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1723 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 27: /* "real"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1729 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 28: /* "string"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1735 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 29: /* "other"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1741 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 30: /* "pass"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1747 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 31: /* "if"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1753 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 32: /* "else"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1759 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 33: /* "case"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1765 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 34: /* "while"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1771 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 35: /* "do"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1777 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 36: /* "for"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1783 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 37: /* "jump"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1789 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 38: /* "next"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1795 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 39: /* "stop"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1801 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 40: /* "return"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1807 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 41: /* "done"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1813 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 42: /* "unless"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1819 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 43: /* "vararg"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1825 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 44: /* "function"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1831 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 45: /* "class"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1837 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 46: /* "typealias"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1843 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 47: /* "<-"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1849 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 48: /* "public"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1855 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 49: /* "private"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1861 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 50: /* "protected"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1867 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 51: /* "static"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1873 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 52: /* "release"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1879 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 53: /* "try"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1885 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 54: /* "catch"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1891 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 55: /* "finally"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1897 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 56: /* "throw"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1903 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
        break;

    case 57: /* "asm"  */
#line 53 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1257  */
      {free(((*yyvaluep).string));}
#line 1909 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1257  */
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
#line 147 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
                    }
#line 2192 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 3:
#line 149 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), NUMBER}};
                    }
#line 2200 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 4:
#line 151 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{createLexem{(yyvsp[0].string), LITERAL}};
                    }
#line 2208 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 5:
#line 153 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-1].ast);
                    }
#line 2216 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 6:
#line 157 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
	            }
#line 2224 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 7:
#line 159 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_ARRAY_INDEX_ACCESS_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                    }
#line 2232 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 8:
#line 161 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {(yyvsp[-2].ast)}};
		    }
#line 2240 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 9:
#line 163 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_FUNCTION_CALL_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                    }
#line 2248 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 10:
#line 165 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_LEXEM, {(yyvsp[-2].ast), createAst{createLexem{(yyvsp[0].string), ID}}}};
                    }
#line 2256 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 11:
#line 167 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_MEMBER_ACCESS_PTR_LEXEM, {(yyvsp[-2].ast), createAst{createLexem{(yyvsp[0].string), ID}}}};
                    }
#line 2264 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 12:
#line 169 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_INCREMENT_LEXEM, {(yyvsp[-1].ast)}};
                    }
#line 2272 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 13:
#line 171 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{POSTFIX_EXPRESSION_DECREMENT_LEXEM, {(yyvsp[-1].ast)}};
                    }
#line 2280 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 14:
#line 175 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                (yyval.ast) = createAst{ARGUMENT_EXPRESSION_LIST_LEXEM, {(yyvsp[0].ast)}};
                        }
#line 2288 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 15:
#line 177 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                (yyval.ast) = (yyvsp[-2].ast);
                                (yyval.ast)->addChild((yyvsp[0].ast));
                        }
#line 2297 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 16:
#line 182 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[0].ast);
                }
#line 2305 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 17:
#line 184 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-1].ast);
                        (yyval.ast)->addChild((yyvsp[0].ast));
		}
#line 2314 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 18:
#line 189 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), INCREMENT}}}};
              }
#line 2322 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 19:
#line 191 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), DECREMENT}}}};
	      }
#line 2330 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 20:
#line 193 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '&'}}}};
	      }
#line 2338 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 21:
#line 195 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '@'}}}};
              }
#line 2346 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 22:
#line 197 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '+'}}}};
              }
#line 2354 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 23:
#line 199 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '-'}}}};
              }
#line 2362 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 24:
#line 201 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{UNARY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '~'}}}};
	      }
#line 2370 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 25:
#line 205 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[0].ast);
	       }
#line 2378 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 26:
#line 207 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = createAst{CAST_EXPRESSION_LEXEM, {(yyvsp[-4].ast), (yyvsp[-1].ast)}};
               }
#line 2386 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 27:
#line 211 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[0].ast);
                         }
#line 2394 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 28:
#line 213 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[-1].ast); 
                                  (yyval.ast)->addChild((yyvsp[-2].ast)); 
                                  (yyval.ast)->addChild((yyvsp[0].ast));
                         }
#line 2404 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 29:
#line 219 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '*'}}}};
                       }
#line 2412 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 30:
#line 221 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '/'}}}};
                       }
#line 2420 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 31:
#line 223 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{MULTIPLICATIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '%'}}}};
                       }
#line 2428 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 32:
#line 227 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
                   }
#line 2436 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 33:
#line 229 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-1].ast);
                           (yyval.ast)->addChild((yyvsp[-2].ast));
                           (yyval.ast)->addChild((yyvsp[0].ast));
                   }
#line 2446 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 34:
#line 235 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '+'}}}};
                 }
#line 2454 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 35:
#line 237 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{ADDITIVE_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '-'}}}};
                 }
#line 2462 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 36:
#line 241 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = (yyvsp[0].ast);
	        }
#line 2470 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 37:
#line 243 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = (yyvsp[-1].ast);
                         (yyval.ast)->addChild((yyvsp[-2].ast));
                         (yyval.ast)->addChild((yyvsp[0].ast));
                }
#line 2480 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 38:
#line 249 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), SHL}}}};
              }
#line 2488 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 39:
#line 251 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{SHIFT_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), SHR}}}};
              }
#line 2496 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 40:
#line 255 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
	             }
#line 2504 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 41:
#line 257 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[-1].ast);
                             (yyval.ast)->addChild((yyvsp[-2].ast));
                             (yyval.ast)->addChild((yyvsp[0].ast));
                     }
#line 2514 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 42:
#line 263 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '<'}}}};
                   }
#line 2522 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 43:
#line 265 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), '>'}}}}; 
                   }
#line 2530 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 44:
#line 267 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), LESS_EQUAL}}}};
                   }
#line 2538 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 45:
#line 269 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{RELATIONAL_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), ABOVE_EQUAL}}}};
	           }
#line 2546 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 46:
#line 273 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 2554 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 47:
#line 275 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-1].ast);
                           (yyval.ast)->addChild((yyvsp[-2].ast));
                           (yyval.ast)->addChild((yyvsp[0].ast));
                   }
#line 2564 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 48:
#line 281 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		         (yyval.ast) = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), EQUALS}}}};
                 }
#line 2572 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 49:
#line 283 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{EQUALITY_OPERATOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), NOT_EQUALS}}}};
                 }
#line 2580 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 50:
#line 287 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = (yyvsp[0].ast);
	      }
#line 2588 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 51:
#line 289 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{AND_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
              }
#line 2596 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 52:
#line 293 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		               (yyval.ast) = (yyvsp[0].ast);
  	               }
#line 2604 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 53:
#line 295 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{EXCLUSIVE_OR_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                       }
#line 2612 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 54:
#line 299 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		               (yyval.ast) = (yyvsp[0].ast);
 	               }
#line 2620 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 55:
#line 301 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                               (yyval.ast) = createAst{INCLUSIVE_OR_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                       }
#line 2628 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 56:
#line 305 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = (yyvsp[0].ast);
	              }
#line 2636 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 57:
#line 307 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    { 
                              (yyval.ast) = createAst{CONDITIONAL_EXPRESSION_LEXEM, {(yyvsp[-4].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
                      }
#line 2644 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 58:
#line 311 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		             (yyval.ast) = (yyvsp[0].ast);
	             }
#line 2652 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 59:
#line 313 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{ASSIGNMENT_EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                     }
#line 2660 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 60:
#line 317 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = createAst{createLexem{"=", '='}};
	           }
#line 2668 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 61:
#line 319 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"*=", MUL_ASSIGN}};
	           }
#line 2676 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 62:
#line 321 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"/=", DIV_ASSIGN}};
	           }
#line 2684 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 63:
#line 323 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"%=", MOD_ASSIGN}};
	           }
#line 2692 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 64:
#line 325 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"+=", ADD_ASSIGN}};
	           }
#line 2700 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 65:
#line 327 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"-=", SUB_ASSIGN}};
	           }
#line 2708 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 66:
#line 329 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"<<=", SHL_ASSIGN}};
	           }
#line 2716 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 67:
#line 331 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{">>=", SHR_ASSIGN}};
	           }
#line 2724 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 68:
#line 333 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"&=", AND_ASSIGN}};
	           }
#line 2732 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 69:
#line 335 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"^=", XOR_ASSIGN}};
	           }
#line 2740 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 70:
#line 337 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{createLexem{"|=", OR_ASSIGN}};
                   }
#line 2748 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 71:
#line 341 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = (yyvsp[0].ast);
  	  }
#line 2756 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 72:
#line 343 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                  (yyval.ast) = createAst{EXPRESSION_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
          }
#line 2764 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 73:
#line 347 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
		   }
#line 2772 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 74:
#line 351 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}}; 
           }
#line 2780 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 75:
#line 355 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = (yyvsp[0].ast);
		      }
#line 2788 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 76:
#line 359 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = createAst{INIT_DECLARATOR_LIST_LEXEM, {(yyvsp[0].ast)}};
	            }
#line 2796 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 77:
#line 361 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-2].ast);
                            (yyval.ast)->addChild((yyvsp[-1].ast));
                    }
#line 2805 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 78:
#line 366 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = (yyvsp[0].ast);
	       }
#line 2813 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 79:
#line 368 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = createAst{INIT_DECLARATOR_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
               }
#line 2821 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 80:
#line 372 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	              (yyval.ast) = createAst{createLexem{(yyvsp[0].string), EMPTY}};
   	      }
#line 2829 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 81:
#line 374 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), REAL}};
	      }
#line 2837 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 82:
#line 376 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), STRING}};
	      }
#line 2845 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 83:
#line 378 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
              }
#line 2853 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 84:
#line 382 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = createAst{DECLARATOR_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
	  }
#line 2861 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 85:
#line 384 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                  (yyval.ast) = (yyvsp[0].ast);
          }
#line 2869 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 86:
#line 388 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		         (yyval.ast) = createAst{createLexem{(yyvsp[0].string), ID}};
 	         }
#line 2877 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 87:
#line 390 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_SCOPED_LEXEM, {(yyvsp[-1].ast)}};
                 }
#line 2885 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 88:
#line 392 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_ARRAYED_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                 }
#line 2893 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 89:
#line 394 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_AUTO_ARRAYED_LEXEM, {(yyvsp[-2].ast)}};
	         }
#line 2901 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 90:
#line 396 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_PARAMETERS_LIST_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                 }
#line 2909 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 91:
#line 398 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{DIRECT_DECLARATOR_IDENTIFIERS_LIST_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
	         }
#line 2917 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 92:
#line 402 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = createAst{POINTER_LEXEM};
       }
#line 2925 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 93:
#line 404 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = createAst{POINTER_LEXEM, {(yyvsp[0].ast)}};
       }
#line 2933 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 94:
#line 409 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = createAst(PARAMETER_TYPE_LIST_LEXEM, {});
		   }
#line 2941 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 95:
#line 411 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 2949 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 96:
#line 413 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[-2].ast);
                           (yyval.ast)->addChild(createAst{createLexem{"...", VARARG}});
                   }
#line 2958 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 97:
#line 418 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{PARAMETER_LIST_LEXEM, {(yyvsp[0].ast)}};
	      }
#line 2966 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 98:
#line 420 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = (yyvsp[-2].ast);
                      (yyval.ast)->addChild((yyvsp[0].ast));
              }
#line 2975 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 99:
#line 425 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
		     }
#line 2983 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 100:
#line 427 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                     }
#line 2991 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 101:
#line 429 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = createAst{PARAMETER_DECLARATION_LEXEM, {(yyvsp[0].ast)}};
                     }
#line 2999 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 102:
#line 433 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = createAst{IDENTIFIER_LIST_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
	       }
#line 3007 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 103:
#line 435 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                       (yyval.ast) = (yyvsp[-2].ast);
                       (yyval.ast)->addChild(createAst{createLexem{(yyvsp[0].string), ID}});
               }
#line 3016 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 104:
#line 440 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3024 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 105:
#line 444 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		           (yyval.ast) = (yyvsp[0].ast);
 	           }
#line 3032 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 106:
#line 446 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = (yyvsp[0].ast);
	           }
#line 3040 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 107:
#line 448 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3048 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 108:
#line 452 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			          (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  }
#line 3056 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 109:
#line 454 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
	                  }
#line 3064 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 110:
#line 456 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3072 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 111:
#line 458 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3080 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 112:
#line 460 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                          }
#line 3088 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 113:
#line 462 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {}};
                          }
#line 3096 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 114:
#line 464 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-1].ast)}};
                          }
#line 3104 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 115:
#line 466 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-2].ast)}};
                          }
#line 3112 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 116:
#line 468 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DIRECT_ABSTRACT_DECLARATOR_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast)}};
                          }
#line 3120 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 117:
#line 472 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = (yyvsp[0].ast);
           }
#line 3128 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 118:
#line 474 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = (yyvsp[-1].ast);
           }
#line 3136 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 119:
#line 478 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{INITIALIZER_LIST_LEXEM, {(yyvsp[0].ast)}};
                }
#line 3144 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 120:
#line 480 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-2].ast);
                        (yyval.ast)->addChild((yyvsp[-1].ast));
                }
#line 3153 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 121:
#line 485 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3161 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 122:
#line 487 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3169 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 123:
#line 489 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3177 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 124:
#line 491 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3185 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 125:
#line 493 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
	 }
#line 3193 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 126:
#line 495 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3201 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 127:
#line 497 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3209 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 128:
#line 499 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3217 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 129:
#line 501 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                 (yyval.ast) = (yyvsp[0].ast);
         }
#line 3225 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 130:
#line 505 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		              (yyval.ast) = createAst{RELEASEMENT_LEXEM, {(yyvsp[0].ast)}};
                     }
#line 3233 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 131:
#line 509 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {createAst{createLexem{(yyvsp[-2].string), ID}}, (yyvsp[0].ast)}};
                 }
#line 3241 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 132:
#line 511 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {(yyvsp[-2].ast), (yyvsp[0].ast)}};
                 }
#line 3249 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 133:
#line 513 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                         (yyval.ast) = createAst{LABELED_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
                 }
#line 3257 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 134:
#line 517 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                          (yyval.ast) = 0;
                  }
#line 3265 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 135:
#line 519 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                          (yyval.ast) = (yyvsp[-1].ast);
                  }
#line 3273 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 136:
#line 523 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
                     }
#line 3281 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 137:
#line 525 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                             (yyval.ast) = (yyvsp[0].ast);
                     }
#line 3289 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 138:
#line 529 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			             (yyval.ast) = (yyvsp[-1].ast);
                              }
#line 3297 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 139:
#line 531 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                     (yyval.ast) = (yyvsp[0].ast);
                              }
#line 3305 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 140:
#line 535 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			          (yyval.ast) = (yyvsp[-1].ast);
                            }
#line 3313 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 141:
#line 537 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[0].ast);
                            }
#line 3321 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 142:
#line 541 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
					        (yyval.ast) = (yyvsp[0].ast);
					}
#line 3329 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 143:
#line 543 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                                (yyval.ast) = (yyvsp[0].ast);
                                        }
#line 3337 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 144:
#line 547 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = createAst{DECLARATION_STATEMENT_LIST_LEXEM, {(yyvsp[0].ast)}};
                          }
#line 3345 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 145:
#line 549 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                  (yyval.ast) = (yyvsp[-1].ast);
                                  (yyval.ast)->addChild((yyvsp[0].ast));
                          }
#line 3354 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 146:
#line 554 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = createAst{PASS_STATEMENT_LEXEM};
                    }
#line 3362 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 147:
#line 556 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3370 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 148:
#line 560 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                              (yyval.ast) = createAst{LABELED_STATEMENT_LIST_LEXEM, {(yyvsp[0].ast)}};
                      }
#line 3378 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 149:
#line 562 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                              (yyval.ast) = (yyvsp[-1].ast);
 	                      (yyval.ast)->addChild((yyvsp[0].ast));
                      }
#line 3387 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 150:
#line 567 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3395 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 151:
#line 569 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
                   }
#line 3403 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 152:
#line 571 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{BRANCHED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast)}};
                   }
#line 3411 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 153:
#line 575 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                }
#line 3419 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 154:
#line 577 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}};
	        }
#line 3427 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 155:
#line 579 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = createAst{LOOPED_STATEMENT_LEXEM, {(yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                }
#line 3435 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 156:
#line 583 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{JUMP_STATEMENT_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
              }
#line 3443 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 157:
#line 585 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{NEXT_STATEMENT_LEXEM};
              }
#line 3451 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 158:
#line 587 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{STOP_STATEMENT_LEXEM};
              }
#line 3459 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 159:
#line 589 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{RETURN_STATEMENT_LEXEM};
	      }
#line 3467 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 160:
#line 591 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                      (yyval.ast) = createAst{RETURN_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
              }
#line 3475 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 161:
#line 595 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			            (yyval.ast) = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {(yyvsp[-3].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
			    }
#line 3483 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 162:
#line 597 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                    (yyval.ast) = createAst{EXCEPTION_HANDLING_STATEMENT_LEXEM, {(yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast)}};
                            }
#line 3491 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 163:
#line 601 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			         (yyval.ast) = createAst{EXCEPTION_THROW_STATEMENT_LEXEM, {(yyvsp[0].ast)}};
			 }
#line 3499 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 164:
#line 605 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        *ast = (yyval.ast) = createAst{EXTERNAL_DECLARATION_LEXEM, {(yyvsp[0].ast)}};
                }
#line 3507 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 165:
#line 607 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                        (yyval.ast) = (yyvsp[-1].ast);
                        (yyval.ast)->addChild((yyvsp[0].ast));
                }
#line 3516 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 166:
#line 612 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3524 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 167:
#line 614 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3532 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 168:
#line 616 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[0].ast);
                    }
#line 3540 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 169:
#line 620 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{FUNCTION_DEFINITION_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
                   }
#line 3548 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 170:
#line 624 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                           (yyval.ast) = createAst{FUNCTION_SIGNATURE_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                  }
#line 3556 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 171:
#line 628 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = createAst{FUNCTION_NAME_LEXEM, 
                                    {createAst{createLexem{(yyvsp[0].string), ID}}}};
	     }
#line 3565 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 172:
#line 633 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = (yyvsp[0].ast);
	     }
#line 3573 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 173:
#line 635 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                     (yyval.ast) = (yyvsp[-1].ast);
             }
#line 3581 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 174:
#line 639 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	             (yyval.ast) = createAst{FUNCTION_TYPE_LEXEM, {createAst{createLexem{"Empty", EMPTY}}}};
             }
#line 3589 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 175:
#line 641 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                     (yyval.ast) = createAst{FUNCTION_TYPE_LEXEM, {(yyvsp[0].ast)}};
             }
#line 3597 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 176:
#line 645 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		        (yyval.ast) = createAst{CLASS_DECLARATION_LEXEM, {(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}};
                 }
#line 3605 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 177:
#line 649 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	         (yyval.ast) = createAst{CLASSNAME_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
         }
#line 3613 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 178:
#line 653 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{PREDECESSOR_LEXEM};
           }
#line 3621 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 179:
#line 655 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{PREDECESSOR_LEXEM, {createAst{createLexem{(yyvsp[0].string), ID}}}};
           }
#line 3629 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 180:
#line 659 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	          (yyval.ast) = (yyvsp[-1].ast);
          }
#line 3637 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 181:
#line 663 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
		            (yyval.ast) = createAst{METHOD_PROPERTY_LIST_LEXEM, {(yyvsp[0].ast)}};
		    }
#line 3645 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 182:
#line 665 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                            (yyval.ast) = (yyvsp[-1].ast);
                            (yyval.ast)->addChild((yyvsp[0].ast));
                    }
#line 3654 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 183:
#line 670 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	               (yyval.ast) = createAst{METHOD_PROPERTY_LEXEM, {(yyvsp[-1].ast), (yyvsp[0].ast)}};
               }
#line 3662 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 184:
#line 674 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
			           (yyval.ast) = (yyvsp[0].ast);
                                   (yyval.ast)->addChild(createAst{createLexem{"static", STATIC}});
                           }
#line 3671 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 185:
#line 677 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                                   (yyval.ast) = (yyvsp[0].ast);
                           }
#line 3679 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 186:
#line 681 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
	           (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"public", PUBLIC}}}};
           }
#line 3687 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 187:
#line 683 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"protected", PROTECTED}}}};
           }
#line 3695 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;

  case 188:
#line 685 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1661  */
    {
                   (yyval.ast) = createAst{ACCESS_RULE_LEXEM, {createAst{createLexem{"private", PRIVATE}}}};
           }
#line 3703 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
    break;


#line 3707 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHiParser.cpp" /* yacc.c:1661  */
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
#line 688 "/Users/andrew/Documents/projects/personal/LLCCEP/SiHi/SiHi.y" /* yacc.c:1906  */

