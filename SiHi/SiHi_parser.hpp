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
#line 1 "SiHi.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>

#include "ast/ast.hpp"
#include "ast/node_types.hpp"

#define YY_(str) ((char const *)str)

int yylex();
int yyerror(char const *str);

int pos_x;

#line 81 "SiHi_parser.hpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif


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
    VAL = 258,
    ID = 259,
    LITERAL = 260,
    SWITCH = 261,
    CASE = 262,
    DEFAULT = 263,
    WHILE = 264,
    DO = 265,
    FOR = 266,
    CONTINUE = 267,
    BREAK = 268,
    IF = 269,
    ELSE = 270,
    GOTO = 271,
    RETURN = 272,
    OP_CMP_LE = 273,
    OP_CMP_AE = 274,
    OP_CMP_EQ = 275,
    OP_CMP_NE = 276,
    OP_INC = 277,
    OP_DEC = 278,
    OP_OFFSET_L = 279,
    OP_OFFSET_R = 280,
    OP_OFFSET_L_EQ = 281,
    OP_OFFSET_R_EQ = 282,
    OP_ADD_EQ = 283,
    OP_SUB_EQ = 284,
    OP_MUL_EQ = 285,
    OP_DIV_EQ = 286,
    OP_MOD_EQ = 287,
    OP_AND_EQ = 288,
    OP_OR_EQ = 289,
    OP_XOR_EQ = 290,
    TYPEDEF = 291,
    EXTERN = 292,
    STATIC = 293,
    AUTO = 294,
    STRUCT = 295,
    UNION = 296,
    ENUM = 297,
    MANY_DOTS = 298,
    PTR_ACS = 299,
    VOID = 300,
    REAL = 301,
    BOOL = 302,
    OP_LOGIC_AND = 303,
    OP_LOGIC_OR = 304
  };
#endif
/* Tokens.  */
#define VAL 258
#define ID 259
#define LITERAL 260
#define SWITCH 261
#define CASE 262
#define DEFAULT 263
#define WHILE 264
#define DO 265
#define FOR 266
#define CONTINUE 267
#define BREAK 268
#define IF 269
#define ELSE 270
#define GOTO 271
#define RETURN 272
#define OP_CMP_LE 273
#define OP_CMP_AE 274
#define OP_CMP_EQ 275
#define OP_CMP_NE 276
#define OP_INC 277
#define OP_DEC 278
#define OP_OFFSET_L 279
#define OP_OFFSET_R 280
#define OP_OFFSET_L_EQ 281
#define OP_OFFSET_R_EQ 282
#define OP_ADD_EQ 283
#define OP_SUB_EQ 284
#define OP_MUL_EQ 285
#define OP_DIV_EQ 286
#define OP_MOD_EQ 287
#define OP_AND_EQ 288
#define OP_OR_EQ 289
#define OP_XOR_EQ 290
#define TYPEDEF 291
#define EXTERN 292
#define STATIC 293
#define AUTO 294
#define STRUCT 295
#define UNION 296
#define ENUM 297
#define MANY_DOTS 298
#define PTR_ACS 299
#define VOID 300
#define REAL 301
#define BOOL 302
#define OP_LOGIC_AND 303
#define OP_LOGIC_OR 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "SiHi.y" /* yacc.c:355  */

	LLCCEP_SiHi::ast *ast;
	char *str;

#line 221 "SiHi_parser.hpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 238 "SiHi_parser.hpp" /* yacc.c:358  */

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1048

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  193
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  331

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   304

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    61,     2,     2,     2,    63,    56,     2,
      50,    51,    57,    58,    55,    59,    54,    62,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    69,    71,
      64,    70,    65,    68,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,    66,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,    67,    73,    60,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    72,    73,    74,    77,    78,    79,    80,
      81,    82,    83,    84,    87,    88,    91,    92,    93,    94,
      97,    98,    99,   100,   101,   102,   105,   106,   107,   110,
     111,   112,   113,   116,   117,   118,   121,   122,   123,   126,
     127,   128,   129,   130,   133,   134,   135,   138,   139,   142,
     143,   146,   147,   150,   151,   154,   155,   158,   159,   162,
     163,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   179,   180,   183,   186,   187,   190,   191,   192,
     193,   196,   197,   200,   201,   204,   205,   206,   207,   210,
     211,   212,   213,   214,   217,   218,   219,   222,   223,   226,
     227,   230,   233,   234,   237,   238,   241,   242,   243,   246,
     247,   248,   251,   252,   255,   256,   259,   260,   263,   264,
     265,   266,   267,   268,   269,   272,   273,   276,   277,   280,
     281,   284,   285,   286,   289,   290,   293,   294,   297,   298,
     299,   302,   303,   304,   305,   306,   307,   308,   309,   310,
     313,   314,   317,   318,   321,   322,   323,   324,   325,   326,
     329,   330,   331,   334,   335,   336,   337,   340,   341,   344,
     345,   348,   349,   352,   353,   354,   357,   358,   359,   360,
     363,   364,   365,   366,   367,   370,   371,   372,   375,   376,
     379,   380,   381,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAL", "ID", "LITERAL", "SWITCH", "CASE",
  "DEFAULT", "WHILE", "DO", "FOR", "CONTINUE", "BREAK", "IF", "ELSE",
  "GOTO", "RETURN", "OP_CMP_LE", "OP_CMP_AE", "OP_CMP_EQ", "OP_CMP_NE",
  "OP_INC", "OP_DEC", "OP_OFFSET_L", "OP_OFFSET_R", "OP_OFFSET_L_EQ",
  "OP_OFFSET_R_EQ", "OP_ADD_EQ", "OP_SUB_EQ", "OP_MUL_EQ", "OP_DIV_EQ",
  "OP_MOD_EQ", "OP_AND_EQ", "OP_OR_EQ", "OP_XOR_EQ", "TYPEDEF", "EXTERN",
  "STATIC", "AUTO", "STRUCT", "UNION", "ENUM", "MANY_DOTS", "PTR_ACS",
  "VOID", "REAL", "BOOL", "OP_LOGIC_AND", "OP_LOGIC_OR", "'('", "')'",
  "'['", "']'", "'.'", "','", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'",
  "'/'", "'%'", "'<'", "'>'", "'^'", "'|'", "'?'", "':'", "'='", "';'",
  "'{'", "'}'", "$accept", "primary_expression", "postfix_expression",
  "argument_expression_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "specifier_list", "struct_declarator_list", "struct_declarator",
  "enum_specifier", "enumerator_list", "enumerator", "declarator",
  "direct_declarator", "pointer", "parameter_type_list", "parameter_list",
  "parameter_declaration", "identifier_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "main_parsing_unit", "external_declaration",
  "function_definition", YY_NULLPTR
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
      40,    41,    91,    93,    46,    44,    38,    42,    43,    45,
     126,    33,    47,    37,    60,    62,    94,   124,    63,    58,
      61,    59,   123,   125
};
# endif

#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -104

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     951,  -167,  -167,  -167,  -167,  -167,  -167,  -167,     5,  -167,
    -167,  -167,    72,   -44,  -167,    11,  1001,  1001,  -167,     6,
    -167,   973,   189,    21,   903,  -167,  -167,   -30,    46,    14,
    -167,  -167,    57,  -167,   490,  -167,  -167,   -15,   341,   285,
    -167,    11,  -167,   973,   415,   721,   189,  -167,  -167,    46,
      53,   -33,  -167,  -167,    72,  -167,   628,  -167,   973,   341,
     341,   233,  -167,    16,  -167,    47,  -167,    81,   871,    74,
     147,   569,   154,   123,   136,   160,   213,   657,   211,   211,
     871,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
     168,   153,   871,  -167,    70,    29,   257,    61,   283,   169,
     164,   177,   201,    -1,  -167,  -167,    64,   560,    84,   208,
    -167,  -167,  -167,   356,   427,  -167,  -167,  -167,  -167,   206,
    -167,  -167,  -167,  -167,    48,   215,   229,  -167,    38,  -167,
    -167,  -167,  -167,   247,    65,   871,    46,  -167,  -167,   628,
    -167,  -167,  -167,   307,  -167,  -167,  -167,   871,    69,  -167,
     236,   569,   871,   248,   569,   871,   331,   689,  -167,  -167,
     871,   284,  -167,   122,   871,  -167,  -167,   144,   278,  -167,
    -167,   367,   750,   871,   372,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,   871,  -167,   871,   871,
     871,   871,   871,   871,   871,   871,   871,   871,   871,   871,
     871,   871,   871,   871,   871,   871,   871,   871,  -167,   607,
     780,   205,  -167,   212,   871,  -167,   498,  -167,  -167,   929,
    -167,    49,  -167,  -167,   273,  -167,   373,  -167,  -167,  -167,
    -167,  -167,    66,  -167,  -167,    16,  -167,   871,  -167,   151,
     569,  -167,   180,   334,   689,   181,  -167,  -167,  -167,   871,
    -167,  -167,   187,  -167,   117,  -167,  -167,  -167,  -167,  -167,
      70,    70,    29,    29,   257,   257,   257,   257,    61,    61,
     283,   169,   164,   177,   201,   120,  -167,  -167,   338,   339,
    -167,   332,   212,   985,   809,   340,  -167,  -167,  -167,  -167,
     628,  -167,  -167,  -167,   569,  -167,   569,   871,   841,   569,
    -167,  -167,   871,  -167,   871,  -167,  -167,  -167,  -167,   348,
    -167,   347,  -167,  -167,  -167,  -167,   195,   569,   196,   389,
    -167,  -167,  -167,  -167,   336,  -167,   569,   569,  -167,  -167,
    -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     187,   118,    85,    86,    87,    88,    97,    98,     0,    89,
      90,    91,     0,   125,   189,     0,    77,    79,    92,     0,
      93,     0,   117,     0,     0,   185,   188,   111,     0,     0,
     126,    75,     0,    81,    83,    78,    80,    96,     0,     0,
     167,     0,   193,     0,     0,     0,   116,     1,   186,     0,
     114,     0,   112,   119,     0,    76,     0,   191,     0,     0,
     103,     0,    99,     0,     3,     2,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,   171,   163,     6,
      16,    26,     0,    29,    33,    36,    39,    44,    47,    49,
      51,    53,    55,    57,    59,    72,     0,    79,   136,     0,
     169,   154,   155,     0,     0,   156,   157,   158,   159,    83,
     168,   192,   134,   124,   133,     0,   127,   129,     0,     2,
     121,    26,    74,     0,     0,     0,     0,   109,    82,     0,
     150,    84,   190,     0,   102,    95,   100,     0,     0,   104,
     106,     0,     0,     0,     0,     0,     0,     0,   181,   182,
       0,     0,   183,     0,     0,    17,    18,     0,     0,    12,
      13,     0,     0,     0,     0,    67,    68,    65,    66,    62,
      63,    64,    69,    71,    70,    61,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,   138,   137,   139,     0,   164,     0,   166,   170,     0,
     131,   138,   132,   122,     0,   123,     0,   120,   110,   115,
     113,   152,     0,    94,   107,     0,   101,     0,   160,     0,
       0,   162,     0,     0,     0,     0,   180,   184,     5,     0,
      11,     8,     0,    14,     0,    10,    60,    30,    31,    32,
      34,    35,    37,    38,    42,    43,    40,    41,    45,    46,
      48,    50,    52,    54,    56,     0,    73,   146,     0,     0,
     142,     0,   140,     0,     0,     0,   165,   128,   130,   135,
       0,   151,   105,   108,     0,   161,     0,     0,     0,     0,
      27,     9,     0,     7,     0,   147,   141,   143,   148,     0,
     144,     0,    28,   153,   175,   176,     0,     0,     0,   173,
      15,    58,   149,   145,     0,   178,     0,     0,   177,   179,
     174
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,   -41,  -167,   -22,   142,   157,   141,
     175,   204,   207,   217,   214,   203,  -167,   -39,   -42,  -167,
     -69,   -32,    32,     2,  -167,   357,  -167,     0,  -167,  -167,
     351,   -26,     3,  -167,   186,  -167,   374,   286,    18,   -20,
      -6,   -43,  -167,   200,  -167,   345,   -96,  -166,  -116,  -167,
     -40,  -167,    26,    15,   313,  -152,  -167,  -167,  -167,  -167,
     418,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    89,    90,   252,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   186,
     106,   133,    40,    41,    32,    33,    16,    60,    18,    19,
      61,    62,   108,   148,   149,    20,    51,    52,    21,    22,
      23,   278,   126,   127,   128,   109,   279,   213,   141,   232,
     110,   111,   112,    43,   114,   115,   116,   117,   118,    24,
      25,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      17,   125,    15,    46,   131,   244,   132,    30,   163,    27,
      37,   167,   212,    13,   140,     1,    17,    17,    35,    36,
       1,    17,   136,   231,    17,     1,    15,   131,   222,   132,
      29,   156,    14,    34,    17,   146,   153,   165,   166,   107,
     137,    63,    49,    17,    17,   282,   124,    42,   205,    58,
      50,   131,     1,     1,   113,   282,    14,    59,    17,   119,
      57,    12,    63,   144,    63,    53,    12,   206,    13,   121,
     187,    12,   119,    13,   218,   120,     1,    28,    38,   195,
     196,   150,    31,   239,   142,   147,   242,   191,   192,   225,
     120,   245,   298,   226,   131,   167,   132,   140,   219,   219,
     210,   210,   211,   229,   254,    13,   131,   107,   132,    36,
     144,   238,    54,   107,   241,   234,   151,   146,   221,   207,
     136,   290,    12,   135,   235,   197,   198,   188,    55,    13,
     253,   152,   189,   190,   209,   208,   210,   275,   228,   291,
     236,    13,   220,   154,   256,   120,    63,   131,   131,   131,
     131,   131,   131,   131,   131,   131,   131,   131,   131,   131,
     131,   131,   131,   131,   131,   276,   257,   258,   259,   131,
     303,   132,   207,   131,   313,   207,   218,   207,   281,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   304,
     169,   170,   285,   247,   158,   248,   131,   155,   132,   207,
     295,    46,   294,   211,   157,   293,   207,   159,   131,    17,
     160,   124,   171,   221,    64,   129,    66,   161,   172,    17,
     173,   124,   174,   185,    17,   201,   124,   300,   316,   318,
     202,   296,   299,    78,    79,   207,   207,    29,   301,    44,
     309,    45,   302,   131,   203,   132,   324,   326,   140,   204,
     207,   207,   311,   150,   314,   209,   315,   210,   214,   319,
     320,   164,   283,   131,   284,   321,   223,    81,    82,    83,
      84,    85,    86,     6,     7,     8,    56,   325,     9,    10,
      11,   193,   194,    17,   224,   124,   329,   330,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
     227,    76,    77,   199,   200,   237,   145,    78,    79,     2,
       3,     4,     5,     6,     7,     8,   287,   240,     9,    10,
      11,     2,     3,     4,     5,     6,     7,     8,   214,   249,
       9,    10,    11,   260,   261,    80,   264,   265,   266,   267,
     243,    81,    82,    83,    84,    85,    86,     6,     7,     8,
     262,   263,     9,    10,    11,   246,    87,    39,    88,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,   250,    76,    77,   268,   269,   255,   289,    78,    79,
     233,     6,     7,     8,   297,   307,     9,    10,    11,   305,
     306,   312,     2,     3,     4,     5,     6,     7,     8,   322,
     323,     9,    10,    11,   327,   270,    80,   328,   274,   271,
     143,   138,    81,    82,    83,    84,    85,    86,   273,   122,
     272,   292,   230,   134,   288,   168,   216,    87,    39,   215,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    48,    76,    77,     0,     0,     0,     0,    78,
      79,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       9,    10,    11,     0,     0,     0,   123,     6,     7,     8,
       0,     0,     9,    10,    11,     0,     0,    80,     0,     0,
       0,     0,     0,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    87,    39,
     217,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,     0,    76,    77,     0,     0,     0,     0,
      78,    79,     0,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     9,    10,    11,     6,     7,
       8,     0,     0,     9,    10,    11,     0,     0,    80,     0,
       0,     0,     0,     0,    81,    82,    83,    84,    85,    86,
      56,     0,    39,     0,     0,     0,     0,     0,     0,    87,
      39,   286,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,     0,    76,    77,     0,     0,     0,
       0,    78,    79,     0,     0,     0,     2,     3,     4,     5,
       6,     7,     8,     0,     0,     9,    10,    11,     0,     6,
       7,     8,  -103,     0,     9,    10,    11,     0,     0,    80,
       0,     0,     0,     0,     0,    81,    82,    83,    84,    85,
      86,    64,   129,    66,     0,     0,     0,     0,     0,     0,
      87,    39,     0,     2,     3,     4,     5,     6,     7,     8,
      78,    79,     9,    10,    11,     0,     0,   209,   277,   210,
      64,   129,    66,     0,    13,     0,     0,     0,     6,     7,
       8,     0,     0,     9,    10,    11,     0,     0,    80,    78,
      79,     0,     0,     0,    81,    82,    83,    84,    85,    86,
       0,     0,    64,   129,    66,     0,     0,     6,     7,     8,
     139,     0,     9,    10,    11,     0,     0,    80,     0,     0,
       0,    78,    79,    81,    82,    83,    84,    85,    86,     0,
       0,     0,     0,     0,    64,   129,    66,     0,   162,     6,
       7,     8,     0,     0,     9,    10,    11,     0,     0,    80,
       0,     0,     0,    78,    79,    81,    82,    83,    84,    85,
      86,     0,     0,    64,   129,    66,     0,     0,     0,     0,
      87,     6,     7,     8,     0,     0,     9,    10,    11,     0,
       0,    80,    78,    79,   130,     0,     0,    81,    82,    83,
      84,    85,    86,    64,   129,    66,     0,     0,     0,     0,
       6,     7,     8,     0,     0,     9,    10,    11,     0,     0,
      80,   251,    78,    79,     0,     0,    81,    82,    83,    84,
      85,    86,    64,   129,    66,     0,     0,     0,     0,     0,
       6,     7,     8,     0,     0,     9,    10,    11,     0,     0,
      80,    78,    79,   280,     0,     0,    81,    82,    83,    84,
      85,    86,     0,     0,    64,   129,    66,     0,     0,     6,
       7,     8,     0,     0,     9,    10,    11,     0,     0,    80,
       0,     0,   310,    78,    79,    81,    82,    83,    84,    85,
      86,     0,     0,     0,    64,   129,    66,     0,     0,     0,
       0,     6,     7,     8,     0,     0,     9,    10,    11,     0,
       0,    80,   317,    78,    79,     0,     0,    81,    82,    83,
      84,    85,    86,    47,     0,     0,     0,     1,     0,     0,
       0,     6,     7,     8,     0,     0,     9,    10,    11,     0,
       0,    80,     0,     0,     0,     0,     0,    81,    82,    83,
      84,    85,    86,     1,     0,     0,     0,     0,     0,     2,
       3,     4,     5,     6,     7,     8,     0,     0,     9,    10,
      11,     0,     0,    12,     0,     1,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     0,     0,     9,    10,    11,     0,     0,   219,
     277,   210,     0,     0,     0,     0,    13,     2,     3,     4,
       5,     6,     7,     8,     0,     0,     9,    10,    11,     0,
       0,    12,     0,     0,     0,     0,     0,     0,    13,     2,
       3,     4,     5,     6,     7,     8,     0,     0,     9,    10,
      11,     2,     3,     4,     5,     6,     7,     8,     0,     0,
       9,    10,    11,     0,     0,     0,   308,     2,     3,     4,
       5,     6,     7,     8,     0,    39,     9,    10,    11
};

static const yytype_int16 yycheck[] =
{
       0,    44,     0,    23,    45,   157,    45,    13,    77,     4,
       4,    80,   108,    57,    56,     4,    16,    17,    16,    17,
       4,    21,    55,   139,    24,     4,    24,    68,   124,    68,
      12,    71,     0,    15,    34,    61,    68,    78,    79,    39,
      73,    38,    72,    43,    44,   211,    44,    21,    49,    34,
       4,    92,     4,     4,    39,   221,    24,    72,    58,    41,
      34,    50,    59,    60,    61,    51,    50,    68,    57,    43,
      92,    50,    54,    57,   114,    43,     4,    72,    72,    18,
      19,    63,    71,   152,    58,    69,   155,    58,    59,    51,
      58,   160,   244,    55,   135,   164,   135,   139,    50,    50,
      52,    52,   108,   135,   173,    57,   147,   107,   147,   107,
     107,   151,    55,   113,   154,   147,    69,   143,   124,    55,
      55,    55,    50,    70,    55,    64,    65,    57,    71,    57,
     172,    50,    62,    63,    50,    71,    52,   206,    73,    73,
      71,    57,   124,    69,   186,   113,   143,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   207,   188,   189,   190,   210,
      53,   210,    55,   214,   290,    55,   216,    55,   210,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    69,
      22,    23,   214,    71,    71,    51,   237,    50,   237,    55,
     240,   221,    51,   209,    50,   237,    55,    71,   249,   209,
      50,   209,    44,   219,     3,     4,     5,     4,    50,   219,
      52,   219,    54,    70,   224,    56,   224,   249,   297,   298,
      66,    51,    51,    22,    23,    55,    55,   219,    51,    50,
     283,    52,    55,   284,    67,   284,    51,    51,   290,    48,
      55,    55,   284,   235,   294,    50,   296,    52,    50,   299,
     302,    50,    50,   304,    52,   304,    51,    56,    57,    58,
      59,    60,    61,    40,    41,    42,    70,   317,    45,    46,
      47,    24,    25,   283,    55,   283,   326,   327,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      53,    16,    17,    20,    21,    69,    73,    22,    23,    36,
      37,    38,    39,    40,    41,    42,    43,    69,    45,    46,
      47,    36,    37,    38,    39,    40,    41,    42,    50,    51,
      45,    46,    47,   191,   192,    50,   195,   196,   197,   198,
       9,    56,    57,    58,    59,    60,    61,    40,    41,    42,
     193,   194,    45,    46,    47,    71,    71,    72,    73,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     4,    16,    17,   199,   200,     4,     4,    22,    23,
      73,    40,    41,    42,    50,    53,    45,    46,    47,    51,
      51,    51,    36,    37,    38,    39,    40,    41,    42,    51,
      53,    45,    46,    47,    15,   201,    50,    71,   205,   202,
      59,    54,    56,    57,    58,    59,    60,    61,   204,     4,
     203,   235,   136,    49,   224,    80,   113,    71,    72,    73,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    24,    16,    17,    -1,    -1,    -1,    -1,    22,
      23,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    51,    40,    41,    42,
      -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    71,    72,
      73,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,    -1,
      22,    23,    -1,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    40,    41,
      42,    -1,    -1,    45,    46,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      70,    -1,    72,    -1,    -1,    -1,    -1,    -1,    -1,    71,
      72,    73,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    -1,    16,    17,    -1,    -1,    -1,
      -1,    22,    23,    -1,    -1,    -1,    36,    37,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    47,    -1,    40,
      41,    42,    52,    -1,    45,    46,    47,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,
      71,    72,    -1,    36,    37,    38,    39,    40,    41,    42,
      22,    23,    45,    46,    47,    -1,    -1,    50,    51,    52,
       3,     4,     5,    -1,    57,    -1,    -1,    -1,    40,    41,
      42,    -1,    -1,    45,    46,    47,    -1,    -1,    50,    22,
      23,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      -1,    -1,     3,     4,     5,    -1,    -1,    40,    41,    42,
      72,    -1,    45,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    22,    23,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,    -1,    71,    40,
      41,    42,    -1,    -1,    45,    46,    47,    -1,    -1,    50,
      -1,    -1,    -1,    22,    23,    56,    57,    58,    59,    60,
      61,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
      71,    40,    41,    42,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    22,    23,    53,    -1,    -1,    56,    57,    58,
      59,    60,    61,     3,     4,     5,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    51,    22,    23,    -1,    -1,    56,    57,    58,    59,
      60,    61,     3,     4,     5,    -1,    -1,    -1,    -1,    -1,
      40,    41,    42,    -1,    -1,    45,    46,    47,    -1,    -1,
      50,    22,    23,    53,    -1,    -1,    56,    57,    58,    59,
      60,    61,    -1,    -1,     3,     4,     5,    -1,    -1,    40,
      41,    42,    -1,    -1,    45,    46,    47,    -1,    -1,    50,
      -1,    -1,    53,    22,    23,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,     3,     4,     5,    -1,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    51,    22,    23,    -1,    -1,    56,    57,    58,
      59,    60,    61,     0,    -1,    -1,    -1,     4,    -1,    -1,
      -1,    40,    41,    42,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,     4,    -1,    -1,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    -1,    -1,    50,    -1,     4,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    36,    37,    38,    39,    40,
      41,    42,    -1,    -1,    45,    46,    47,    -1,    -1,    50,
      51,    52,    -1,    -1,    -1,    -1,    57,    36,    37,    38,
      39,    40,    41,    42,    -1,    -1,    45,    46,    47,    -1,
      -1,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,    36,
      37,    38,    39,    40,    41,    42,    -1,    -1,    45,    46,
      47,    36,    37,    38,    39,    40,    41,    42,    -1,    -1,
      45,    46,    47,    -1,    -1,    -1,    51,    36,    37,    38,
      39,    40,    41,    42,    -1,    72,    45,    46,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    36,    37,    38,    39,    40,    41,    42,    45,
      46,    47,    50,    57,    96,    97,   100,   101,   102,   103,
     109,   112,   113,   114,   133,   134,   135,     4,    72,   112,
     114,    71,    98,    99,   112,    97,    97,     4,    72,    72,
      96,    97,   126,   127,    50,    52,   113,     0,   134,    72,
       4,   110,   111,    51,    55,    71,    70,   126,   127,    72,
     101,   104,   105,   106,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    16,    17,    22,    23,
      50,    56,    57,    58,    59,    60,    61,    71,    73,    75,
      76,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    94,   101,   106,   119,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   112,
      96,   126,     4,    51,    97,   115,   116,   117,   118,     4,
      53,    78,    91,    95,   110,    70,    55,    73,    99,    72,
      92,   122,   126,   104,   106,    73,   105,    69,   107,   108,
     112,    69,    50,    95,    69,    50,   124,    50,    71,    71,
      50,     4,    71,    94,    50,    78,    78,    94,   119,    22,
      23,    44,    50,    52,    54,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    70,    93,    80,    57,    62,
      63,    58,    59,    24,    25,    18,    19,    64,    65,    20,
      21,    56,    66,    67,    48,    49,    68,    55,    71,    50,
      52,   114,   120,   121,    50,    73,   128,    73,   124,    50,
     112,   114,   120,    51,    55,    51,    55,    53,    73,    95,
     111,   122,   123,    73,    95,    55,    71,    69,   124,    94,
      69,   124,    94,     9,   129,    94,    71,    71,    51,    51,
       4,    51,    77,    92,    94,     4,    92,    80,    80,    80,
      81,    81,    82,    82,    83,    83,    83,    83,    84,    84,
      85,    86,    87,    88,    89,    94,    92,    51,   115,   120,
      53,    95,   121,    50,    52,    80,    73,    43,   117,     4,
      55,    73,   108,    95,    51,   124,    51,    50,   129,    51,
      80,    51,    55,    53,    69,    51,    51,    53,    51,   115,
      53,    95,    51,   122,   124,   124,    94,    51,    94,   124,
      92,    91,    51,    53,    51,   124,    51,    15,    71,   124,
     124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    80,    80,    80,    81,
      81,    81,    81,    82,    82,    82,    83,    83,    83,    84,
      84,    84,    84,    84,    85,    85,    85,    86,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    96,    96,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   102,   102,   102,   103,   103,   104,
     104,   105,   106,   106,   107,   107,   108,   108,   108,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   117,   118,   118,   119,   119,   120,   120,
     120,   121,   121,   121,   121,   121,   121,   121,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   124,   124,
     125,   125,   125,   126,   126,   126,   126,   127,   127,   128,
     128,   129,   129,   130,   130,   130,   131,   131,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   133,   134,   134,
     135,   135,   135,   135
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     4,     2,     1,     1,     1,
       2,     3,     2,     1,     1,     3,     1,     2,     3,     4,
       5,     2,     1,     3,     1,     3,     2,     1,     1,     3,
       4,     3,     4,     4,     3,     1,     2,     1,     3,     1,
       3,     2,     2,     1,     1,     3,     1,     2,     1,     1,
       2,     3,     2,     3,     3,     4,     2,     3,     3,     4,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     4,     3,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     2,     0,     1,     1,
       4,     3,     3,     2
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
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
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
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
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
yyparse (void)
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
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
  switch (yyn)
    {
        case 2:
#line 71 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, ID, (yyvsp[0].str));}
#line 1720 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 3:
#line 72 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, VAL, (yyvsp[0].str));}
#line 1726 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, LITERAL, (yyvsp[0].str));}
#line 1732 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 5:
#line 74 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 1738 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 6:
#line 77 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1744 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 7:
#line 78 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, ARRAY_ACCESS, "[]");}
#line 1750 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast)}, INVOKATION, "Invokation");}
#line 1756 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 9:
#line 80 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, INVOKATION, "Invokation");}
#line 1762 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 10:
#line 81 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '.', ".");}
#line 1768 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 11:
#line 82 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, PTR_ACS, "->");}
#line 1774 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 12:
#line 83 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, OP_INC, "++");}
#line 1780 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 13:
#line 84 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, OP_DEC, "++");}
#line 1786 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 14:
#line 87 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1792 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 15:
#line 88 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, ARGUMENT_EXPRESSION_LIST, "Argument expression list");}
#line 1798 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 16:
#line 91 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1804 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 17:
#line 92 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[0].ast)}, OP_INC, "++");}
#line 1810 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 18:
#line 93 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[0].ast)}, OP_DEC, "--");}
#line 1816 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast); (yyval.ast)->insert_child((yyvsp[0].ast));}
#line 1822 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 20:
#line 97 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '&', "Unary &(address reviever)");}
#line 1828 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 21:
#line 98 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '*', "Unary *(poiner dereferencer)");}
#line 1834 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 22:
#line 99 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '+', "Unary +");}
#line 1840 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 23:
#line 100 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '-', "Unary -");}
#line 1846 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 24:
#line 101 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '~', "~");}
#line 1852 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 25:
#line 102 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '!', "!");}
#line 1858 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 26:
#line 105 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1864 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 27:
#line 106 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, CAST_EXPRESSION, "Reinterpreting cast");}
#line 1870 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 28:
#line 107 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, CAST_EXPRESSION, "Reinterpreting cast");}
#line 1876 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 29:
#line 110 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1882 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 30:
#line 111 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, MULTIPLICATION, "*");}
#line 1888 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 31:
#line 112 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, DIVISION, "/");}
#line 1894 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 32:
#line 113 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, MODULO, "%");}
#line 1900 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 33:
#line 116 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1906 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 34:
#line 117 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, ADDITION, "+");}
#line 1912 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 35:
#line 118 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, SEGMENTATION, "-");}
#line 1918 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 36:
#line 121 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1924 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 37:
#line 122 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_OFFSET_L, "<<");}
#line 1930 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 38:
#line 123 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_OFFSET_R, ">>");}
#line 1936 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 39:
#line 126 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1942 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 40:
#line 127 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '<', "<");}
#line 1948 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 41:
#line 128 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '>', ">");}
#line 1954 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 42:
#line 129 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_CMP_LE, "<=");}
#line 1960 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 43:
#line 130 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_CMP_AE, ">=");}
#line 1966 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 44:
#line 133 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1972 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 45:
#line 134 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_CMP_EQ, "==");}
#line 1978 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 46:
#line 135 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_CMP_NE, "!=");}
#line 1984 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 47:
#line 138 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 1990 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 48:
#line 139 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '&', "&");}
#line 1996 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 49:
#line 142 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2002 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 50:
#line 143 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '^', "^");}
#line 2008 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 51:
#line 146 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2014 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 52:
#line 147 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '|', "|");}
#line 2020 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 53:
#line 150 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2026 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 54:
#line 151 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_LOGIC_AND, "&&");}
#line 2032 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 55:
#line 154 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2038 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 56:
#line 155 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, OP_LOGIC_OR, "||");}
#line 2044 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 57:
#line 158 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2050 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-2].ast)}, IF_ELSE, "if-else");}
#line 2056 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 59:
#line 162 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2062 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 60:
#line 163 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast); (yyval.ast)->insert_child((yyvsp[-2].ast)); (yyval.ast)->insert_child((yyvsp[0].ast));}
#line 2068 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 61:
#line 166 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, '=', "=");}
#line 2074 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 62:
#line 167 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_MUL_EQ, "*=");}
#line 2080 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 63:
#line 168 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_DIV_EQ, "/=");}
#line 2086 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 64:
#line 169 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_MOD_EQ, "%=");}
#line 2092 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 65:
#line 170 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_ADD_EQ, "+=");}
#line 2098 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 66:
#line 171 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_SUB_EQ, "-=");}
#line 2104 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 67:
#line 172 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_OFFSET_L_EQ, "<<=");}
#line 2110 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 68:
#line 173 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_OFFSET_R_EQ, ">>=");}
#line 2116 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 69:
#line 174 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_AND_EQ, "&=");}
#line 2122 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 70:
#line 175 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_XOR_EQ, "^=");}
#line 2128 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 71:
#line 176 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, OP_OR_EQ, "|=");}
#line 2134 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 72:
#line 179 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2140 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 73:
#line 180 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-2].ast); (yyval.ast)->insert_child((yyvsp[0].ast));}
#line 2146 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 74:
#line 183 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2152 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 75:
#line 186 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2158 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 76:
#line 187 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[-1].ast)}, DECLARATION, "declaration");}
#line 2164 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 77:
#line 190 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2170 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 78:
#line 191 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, DECL_SPEC, "declaration specifiers");}
#line 2176 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 79:
#line 192 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2182 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 80:
#line 193 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, DECL_SPEC, "declaration specifiers");}
#line 2188 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 81:
#line 196 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2194 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 82:
#line 197 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-2].ast); (yyval.ast)->insert_child((yyvsp[0].ast));}
#line 2200 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 83:
#line 200 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2206 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 84:
#line 201 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, '=', "=");}
#line 2212 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 85:
#line 204 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, TYPEDEF, "typedef");}
#line 2218 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 86:
#line 205 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, EXTERN, "extern");}
#line 2224 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 87:
#line 206 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, STATIC, "static");}
#line 2230 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 88:
#line 207 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, AUTO, "auto");}
#line 2236 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 89:
#line 210 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, VOID, "void");}
#line 2242 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 90:
#line 211 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, REAL, "real");}
#line 2248 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 91:
#line 212 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, BOOL, "bool");}
#line 2254 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 92:
#line 213 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2260 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 93:
#line 214 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2266 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 94:
#line 217 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)}, STRUCT_UNION_SPEC, "Struct or union");}
#line 2272 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 95:
#line 218 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast),  (yyvsp[-1].ast)}, STRUCT_UNION_ANON_SPEC, "Anonymous struct or union");}
#line 2278 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 96:
#line 219 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, STRUCT_UNION_PRE_DEF, "Struct or union pre-def");}
#line 2284 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 97:
#line 222 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, STRUCT, "struct");}
#line 2290 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 98:
#line 223 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, UNION, "union");}
#line 2296 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 99:
#line 226 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2302 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 100:
#line 227 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast); (yyval.ast)->insert_child((yyvsp[0].ast));}
#line 2308 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 101:
#line 230 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[-1].ast)}, STRUCT_DECL,"Struct declaration");}
#line 2314 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 102:
#line 233 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, SPECIFIER_LIST, "Specifier list");}
#line 2320 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 103:
#line 234 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2326 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 104:
#line 237 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2332 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 105:
#line 238 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, STRUCT_DECL_LIST, "Struct declarator list");}
#line 2338 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 106:
#line 241 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2344 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 107:
#line 242 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast); /* ought to be debugged*/}
#line 2350 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 108:
#line 243 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, STRUCT_DECLARATOR, "struct declarator");}
#line 2356 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 109:
#line 246 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, ENUM, "Anonynous enumeration");}
#line 2362 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 110:
#line 247 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-2].ast)}, ENUM, "Named enumeration");}
#line 2368 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 111:
#line 248 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[0].ast)}, ENUM, "Empty enumeration");}
#line 2374 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 112:
#line 251 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2380 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 113:
#line 252 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, ENUMERATOR_LIST, "Enumerator list");}
#line 2386 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 114:
#line 255 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, ID, (yyvsp[0].str));}
#line 2392 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 115:
#line 256 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({new ast({}, ID, (yyvsp[-2].str)), (yyvsp[0].ast)}, '=', "Numbered enumerator");}
#line 2398 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 116:
#line 259 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, DECLARATOR, "Ptr declarator");}
#line 2404 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 117:
#line 260 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2410 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 118:
#line 263 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, ID, yytext);}
#line 2416 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 119:
#line 264 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2422 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 120:
#line 265 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, ARRAY_DECL, "Array declaration");}
#line 2428 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 121:
#line 266 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast)}, ARRAY_DECL, "Array declaration");}
#line 2434 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 122:
#line 267 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, FUNC_DECL, "Function declaration");}
#line 2440 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 123:
#line 268 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, FUNC_INVOKE, "Function invokation");}
#line 2446 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 125:
#line 272 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, PTR, "Pointer");}
#line 2452 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 126:
#line 273 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[0].ast)}, PTR, "Pointer");}
#line 2458 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 127:
#line 276 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2464 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 128:
#line 277 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), new LLCCEP_SiHi::ast({}, MANY_DOTS, "va_list")}, PARAMETER_VAR_LIST, "Parameters var list");}
#line 2470 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 129:
#line 280 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2476 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 130:
#line 281 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, PARAM_LIST, "Parameter list");}
#line 2482 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 131:
#line 284 "SiHi.y" /* yacc.c:1646  */
    {}
#line 2488 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 134:
#line 289 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, ID, yytext);}
#line 2494 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 135:
#line 290 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), new LLCCEP_SiHi::ast({}, ID, yytext)}, ID_LIST, "Identifier list");/* see it later */}
#line 2500 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 136:
#line 293 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2506 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 137:
#line 294 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, TYPENAME, "Type name");}
#line 2512 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 138:
#line 297 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2518 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 139:
#line 298 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2524 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 140:
#line 299 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, ABSTRACT_DECL, "Abstract declarator");}
#line 2530 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 141:
#line 302 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2536 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 142:
#line 303 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, ARR_BRACES, "Array braces");}
#line 2542 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 143:
#line 304 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, ARR_BRACES, "Array braces");}
#line 2548 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 144:
#line 305 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast)}, ARRAY, "Array");}
#line 2554 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 145:
#line 306 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, ARRAY, "array");}
#line 2560 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 146:
#line 307 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, RND_BRACES, "Round braces");}
#line 2566 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 147:
#line 308 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, RESULT_UNIFICATION, "Unification");}
#line 2572 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 148:
#line 309 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast)}, FUNCTION_DECL, "Function");}
#line 2578 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 149:
#line 310 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-1].ast)}, FUNCTION_DECL, "Function");}
#line 2584 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 150:
#line 313 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2590 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 151:
#line 314 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2596 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 152:
#line 317 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2602 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 153:
#line 318 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, INITIALIZER_LIST, "Initializer list");}
#line 2608 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 154:
#line 321 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2614 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 155:
#line 322 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2620 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 156:
#line 323 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2626 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 157:
#line 324 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2632 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 158:
#line 325 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2638 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 159:
#line 326 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2644 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 160:
#line 329 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, LABELED_STATEMENT, "Marked statement");}
#line 2650 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 161:
#line 330 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, CASE, "Case statement");}
#line 2656 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 162:
#line 331 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[0].ast)}, DEFAULT, "Default statement");}
#line 2662 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 163:
#line 334 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = nullptr;}
#line 2668 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 164:
#line 335 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2674 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 165:
#line 336 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), %<ast>3}, DECL_STMT_LIST, "compound statement");}
#line 2680 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 166:
#line 337 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast)}
#line 2686 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 167:
#line 340 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2692 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 168:
#line 341 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, DECL_LIST, "Declaration list");}
#line 2698 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 169:
#line 344 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2704 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 170:
#line 345 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, STMT_LIST, "Statement list");}
#line 2710 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 171:
#line 348 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = nullptr;}
#line 2716 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 172:
#line 349 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[-1].ast);}
#line 2722 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 173:
#line 352 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, IF_ELSE, "If-else");}
#line 2728 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 174:
#line 353 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-5].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)}, IF_ELSE, "If-else");}
#line 2734 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 175:
#line 354 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, SWITCH, "Switch");}
#line 2740 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 176:
#line 357 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[0].ast)}, WHILE, "While");}
#line 2746 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 177:
#line 358 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-5].ast), (yyvsp[-2].ast)}, DO_WHILE, "do while");}
#line 2752 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 178:
#line 359 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[0].ast)}, FOR, "for");}
#line 2758 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 179:
#line 360 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-5].ast), (yyvsp[-4].ast), (yyvsp[-3].ast), (yyvsp[-1].ast)}, FOR, "for");}
#line 2764 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 180:
#line 363 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, GOTO, "Goto");}
#line 2770 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 181:
#line 364 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, CONTINUE, "continue");}
#line 2776 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 182:
#line 365 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, BREAK, "break");}
#line 2782 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 183:
#line 366 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({}, RETURN, "return");}
#line 2788 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 184:
#line 367 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast)}, RETURN, "return");}
#line 2794 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 185:
#line 370 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2800 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 186:
#line 371 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, MAIN, "Main");}
#line 2806 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 187:
#line 372 "SiHi.y" /* yacc.c:1646  */
    {yyerror("syntax error");}
#line 2812 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 188:
#line 375 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2818 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 189:
#line 376 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = (yyvsp[0].ast);}
#line 2824 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 190:
#line 379 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-3].ast), (yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}, FUNCTION_DEFINITION, "Function definition");}
#line 2830 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 191:
#line 380 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}, FUNCTION_DEFINITION, "Function definition");}
#line 2836 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 192:
#line 381 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-2].ast), (yyvsp[-1].ast), (yyvsp[0].ast)}, FUNCTION_DEFINITION, "Function definition");}
#line 2842 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;

  case 193:
#line 382 "SiHi.y" /* yacc.c:1646  */
    {(yyval.ast) = new LLCCEP_SiHi::ast({(yyvsp[-1].ast), (yyvsp[0].ast)}, FUNCTION_DEFINITION, "Function definition");}
#line 2848 "SiHi_parser.hpp" /* yacc.c:1646  */
    break;


#line 2852 "SiHi_parser.hpp" /* yacc.c:1646  */
      default: break;
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
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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
        yyerror (yymsgp);
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
                      yytoken, &yylval);
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 383 "SiHi.y" /* yacc.c:1906  */


int yyerror(char const *str)
{
	fprintf(stderr, "%s:%d:%d: %s:\n"
	                "%s\n", "here should be path", yylineno, pos_x, str, yytext);

	return 0;
}

int main()
{
	yyin = stdin;

	yyparse();

	return 0;
}
