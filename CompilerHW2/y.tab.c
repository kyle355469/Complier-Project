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
     DOT = 258,
     COMMA = 259,
     COLON = 260,
     SEMICOLON = 261,
     U_PAREN = 262,
     L_PAREN = 263,
     U_BRACKET = 264,
     L_BRACKET = 265,
     U_B_PAREN = 266,
     L_B_PAREN = 267,
     GIVEN_EQUAL = 268,
     ARRAY = 269,
     BBEGIN = 270,
     BOOL = 271,
     CHAR = 272,
     CONST = 273,
     DECREASING = 274,
     DEFAULT = 275,
     DO = 276,
     ELSE = 277,
     END = 278,
     T_EXIT = 279,
     T_FALSE = 280,
     FOR = 281,
     FUNCTION = 282,
     GET = 283,
     T_IF = 284,
     INT = 285,
     LOOP = 286,
     OF = 287,
     PUT = 288,
     PROCEDURE = 289,
     REAL = 290,
     RESULT = 291,
     RETURN = 292,
     SKIP = 293,
     STRING = 294,
     THEN = 295,
     T_TRUE = 296,
     VAR = 297,
     WHEN = 298,
     ID = 299,
     INT_NUM = 300,
     REAL_NUM = 301,
     STR_CONT = 302,
     OR = 303,
     AND = 304,
     MINUS = 305,
     PLUS = 306,
     MOD = 307,
     DIV = 308,
     TIMES = 309,
     UMINUS = 310,
     NOT = 311,
     NOT_EQ = 312,
     EQUAL = 313,
     EM_T = 314,
     M_T = 315,
     EL_T = 316,
     L_T = 317
   };
#endif
/* Tokens.  */
#define DOT 258
#define COMMA 259
#define COLON 260
#define SEMICOLON 261
#define U_PAREN 262
#define L_PAREN 263
#define U_BRACKET 264
#define L_BRACKET 265
#define U_B_PAREN 266
#define L_B_PAREN 267
#define GIVEN_EQUAL 268
#define ARRAY 269
#define BBEGIN 270
#define BOOL 271
#define CHAR 272
#define CONST 273
#define DECREASING 274
#define DEFAULT 275
#define DO 276
#define ELSE 277
#define END 278
#define T_EXIT 279
#define T_FALSE 280
#define FOR 281
#define FUNCTION 282
#define GET 283
#define T_IF 284
#define INT 285
#define LOOP 286
#define OF 287
#define PUT 288
#define PROCEDURE 289
#define REAL 290
#define RESULT 291
#define RETURN 292
#define SKIP 293
#define STRING 294
#define THEN 295
#define T_TRUE 296
#define VAR 297
#define WHEN 298
#define ID 299
#define INT_NUM 300
#define REAL_NUM 301
#define STR_CONT 302
#define OR 303
#define AND 304
#define MINUS 305
#define PLUS 306
#define MOD 307
#define DIV 308
#define TIMES 309
#define UMINUS 310
#define NOT 311
#define NOT_EQ 312
#define EQUAL 313
#define EM_T 314
#define M_T 315
#define EL_T 316
#define L_T 317




/* Copy the first part of user declarations.  */
#line 1 "p.y"

#ifndef TABLE_DIF
#define TABLE_DIF
#include "table.h"
#endif

#define Trace(t)        if(NMode) {printf("\t-note: %s\n", t);}
int yylex();
int yyerror(const char *);
void yywarning(const char *msg);

#ifndef STDIO_DIF
#define STDIO_DIF
#include <stdio.h>
#endif

#ifndef STDLIB_DIF
#define STDLIB_DIF
#include <stdlib.h>
#endif

#ifndef STRING_DIF
#define STRING_DIF
#include <string.h>
#endif

LT* nowPointer;
LT* tailPointer;
extern int linenum;
extern FILE *yyin;
extern int yydebug;
#define YYDEBUG 1

char* nowIDName;
char* nowIDName2;
char* nowValue;
char* nowFuncName;
int exprChecker = 0;
int functionCall_counter = 0;       // count function's reference element
int outOfBlockCheck = 0;            // check if the block get any return or exit
const int NMode = 0;

const char* t_name[] = {"","int", "real", "bool", "string", "non"};



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
#line 49 "p.y"
{
    typeDef type;
    char* input;
}
/* Line 193 of yacc.c.  */
#line 271 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 284 "y.tab.c"

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   288

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   317

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     9,    10,    16,    17,    19,    22,
      24,    26,    28,    30,    31,    37,    38,    46,    48,    50,
      52,    54,    56,    58,    60,    62,    64,    71,    76,    81,
      92,    93,    99,   100,   111,   112,   121,   122,   126,   128,
     132,   142,   143,   145,   148,   150,   151,   156,   158,   160,
     162,   164,   165,   170,   171,   175,   178,   181,   183,   186,
     188,   189,   192,   193,   202,   203,   209,   212,   213,   219,
     220,   221,   222,   223,   239,   240,   242,   243,   247,   250,
     254,   255,   260,   264,   265,   270,   272,   276,   280,   284,
     288,   292,   295,   299,   301,   303,   307,   311,   315,   319,
     323,   327,   331,   335
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      64,     0,    -1,    67,    77,    83,    -1,    44,    -1,    -1,
      44,    66,     9,    45,    10,    -1,    -1,    68,    -1,    68,
      69,    -1,    69,    -1,    70,    -1,    75,    -1,    76,    -1,
      -1,    18,    65,    71,    13,   108,    -1,    -1,    18,    65,
      72,     5,    73,    13,   108,    -1,    16,    -1,    39,    -1,
      30,    -1,    35,    -1,    47,    -1,    45,    -1,    46,    -1,
      41,    -1,    25,    -1,    42,    65,     5,    73,    13,   108,
      -1,    42,    65,    13,   108,    -1,    42,    65,     5,    73,
      -1,    42,    65,     5,    14,    45,     3,     3,    45,    32,
      73,    -1,    -1,    79,    67,    83,    23,    65,    -1,    -1,
      34,    65,    78,     7,    81,     8,    67,    83,    23,    65,
      -1,    -1,    27,    65,    80,     7,    81,     8,     5,    73,
      -1,    -1,    81,     4,    82,    -1,    82,    -1,    65,     5,
      73,    -1,    65,     5,    14,    45,     3,     3,    45,    32,
      73,    -1,    -1,    84,    -1,    84,    85,    -1,    85,    -1,
      -1,    15,    86,    64,    23,    -1,    87,    -1,    91,    -1,
      95,    -1,   102,    -1,    -1,    65,    88,    13,   108,    -1,
      -1,    33,    89,   108,    -1,    28,    65,    -1,    36,   108,
      -1,    37,    -1,    24,    90,    -1,    38,    -1,    -1,    43,
     108,    -1,    -1,    29,    92,     7,   108,     8,    40,    64,
      93,    -1,    -1,    22,    94,    64,    23,    29,    -1,    23,
      29,    -1,    -1,    31,    96,    64,    23,    31,    -1,    -1,
      -1,    -1,    -1,    26,    97,   101,    65,    98,     5,   108,
      99,     3,     3,   108,   100,    64,    23,    26,    -1,    -1,
      19,    -1,    -1,    65,   103,   104,    -1,     7,     8,    -1,
       7,   106,     8,    -1,    -1,     7,   108,   105,     8,    -1,
     106,     4,   108,    -1,    -1,   108,   107,     4,   108,    -1,
      74,    -1,   108,    51,   108,    -1,   108,    50,   108,    -1,
     108,    54,   108,    -1,   108,    53,   108,    -1,   108,    52,
     108,    -1,    50,   108,    -1,     7,   108,     8,    -1,    65,
      -1,   102,    -1,   108,    62,   108,    -1,   108,    61,   108,
      -1,   108,    59,   108,    -1,   108,    60,   108,    -1,   108,
      58,   108,    -1,   108,    57,   108,    -1,   108,    49,   108,
      -1,   108,    48,   108,    -1,    56,   108,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   101,   112,   111,   134,   135,   137,   138,
     142,   143,   144,   149,   148,   173,   172,   211,   217,   223,
     229,   239,   240,   241,   242,   243,   246,   255,   262,   271,
     300,   301,   313,   312,   331,   330,   347,   348,   349,   353,
     357,   372,   373,   376,   377,   381,   380,   393,   394,   395,
     396,   401,   400,   429,   429,   440,   444,   460,   469,   477,
     480,   480,   484,   483,   492,   491,   509,   520,   519,   533,
     538,   551,   559,   532,   577,   578,   582,   581,   609,   610,
     612,   611,   628,   642,   641,   675,   683,   698,   713,   728,
     742,   760,   771,   772,   777,   778,   788,   798,   809,   819,
     829,   839,   849,   859
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "COMMA", "COLON", "SEMICOLON",
  "U_PAREN", "L_PAREN", "U_BRACKET", "L_BRACKET", "U_B_PAREN", "L_B_PAREN",
  "GIVEN_EQUAL", "ARRAY", "BBEGIN", "BOOL", "CHAR", "CONST", "DECREASING",
  "DEFAULT", "DO", "ELSE", "END", "T_EXIT", "T_FALSE", "FOR", "FUNCTION",
  "GET", "T_IF", "INT", "LOOP", "OF", "PUT", "PROCEDURE", "REAL", "RESULT",
  "RETURN", "SKIP", "STRING", "THEN", "T_TRUE", "VAR", "WHEN", "ID",
  "INT_NUM", "REAL_NUM", "STR_CONT", "OR", "AND", "MINUS", "PLUS", "MOD",
  "DIV", "TIMES", "UMINUS", "NOT", "NOT_EQ", "EQUAL", "EM_T", "M_T",
  "EL_T", "L_T", "$accept", "program", "identifier", "@1", "pre_var_dec",
  "variable_dec", "variable_type", "const_dec", "@2", "@3", "type_dec",
  "const_val_expr", "var_dec", "var_array_dec", "function_dec", "@4",
  "function_def", "@5", "argument_dec", "identi_req", "pre_stmt",
  "statments", "statment", "@6", "simple_statment", "@7", "@8",
  "cond_check", "cond_statment", "@9", "else_block", "@10",
  "loop_statment", "@11", "@12", "@13", "@14", "@15", "decreasing",
  "func_proc_call", "@16", "func_call_input", "@17", "func_input", "@18",
  "expr", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    65,    66,    65,    67,    67,    68,    68,
      69,    69,    69,    71,    70,    72,    70,    73,    73,    73,
      73,    74,    74,    74,    74,    74,    75,    75,    75,    76,
      77,    77,    78,    77,    80,    79,    81,    81,    81,    82,
      82,    83,    83,    84,    84,    86,    85,    85,    85,    85,
      85,    88,    87,    89,    87,    87,    87,    87,    87,    87,
      90,    90,    92,    91,    94,    93,    93,    96,    95,    97,
      98,    99,   100,    95,   101,   101,   103,   102,   104,   104,
     105,   104,   106,   107,   106,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     1,     0,     5,     0,     1,     2,     1,
       1,     1,     1,     0,     5,     0,     7,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     6,     4,     4,    10,
       0,     5,     0,    10,     0,     8,     0,     3,     1,     3,
       9,     0,     1,     2,     1,     0,     4,     1,     1,     1,
       1,     0,     4,     0,     3,     2,     2,     1,     2,     1,
       0,     2,     0,     8,     0,     5,     2,     0,     5,     0,
       0,     0,     0,    15,     0,     1,     0,     3,     2,     3,
       0,     4,     3,     0,     4,     1,     3,     3,     3,     3,
       3,     2,     3,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,     0,    30,     7,     9,    10,    11,    12,
       3,    13,     0,     1,     0,     0,    41,     6,     8,     0,
       0,     0,     0,     0,    34,    32,    45,    60,    69,     0,
      62,    67,    53,     0,    57,    59,    51,     2,    42,    44,
      47,    48,    49,    50,    41,     0,     0,     0,     0,    17,
      19,    20,    18,    28,     0,    25,    24,    22,    23,    21,
       0,     0,    93,    85,    94,    27,     0,     0,     6,     0,
      58,    74,    55,     0,     6,     0,    56,     0,     0,    43,
       0,     0,    14,     0,     0,     0,     0,    91,   103,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    36,    36,     0,    61,    75,     0,     0,     0,
      54,     0,     0,    77,     0,     5,     0,     0,    26,    92,
     102,   101,    87,    86,    90,    89,    88,   100,    99,    97,
      98,    96,    95,     0,     0,    38,     0,    46,    70,     0,
       0,    52,    78,     0,    80,    31,    16,     0,     0,     0,
       0,     6,     0,     0,    68,     0,    79,     0,     0,     0,
       0,    39,    37,     0,    41,     0,     6,    82,    81,     0,
       0,     0,    35,     0,    71,     0,    84,    29,     0,     0,
       0,    64,     0,    63,     0,    33,     0,     6,    66,     0,
       0,     0,     0,    72,     0,    40,     6,    65,     0,     0,
      73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    62,    19,     4,     5,     6,     7,    20,    21,
      53,    63,     8,     9,    16,    67,    17,    66,   134,   135,
      37,    38,    39,    68,    40,    77,    75,    70,    41,    73,
     183,   187,    42,    74,    71,   152,   180,   196,   107,    64,
      78,   113,   157,   143,   158,    65
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -64
static const yytype_int16 yypact[] =
{
      -8,   -26,   -26,    23,    -5,    -8,   -64,   -64,   -64,   -64,
      27,    53,     7,   -64,   -26,   -26,   193,    -8,   -64,    63,
      41,    68,     3,   109,   -64,   -64,   -64,    32,   -64,   -26,
     -64,   -64,   -64,   109,   -64,   -64,    69,   -64,   193,   -64,
     -64,   -64,   -64,   -64,   193,    34,   109,     5,    35,   -64,
     -64,   -64,   -64,    64,   109,   -64,   -64,   -64,   -64,   -64,
     109,   109,    69,   -64,   -64,   190,    76,    77,    -8,   109,
     -64,    66,   -64,    80,    -8,   109,   190,    75,    82,   -64,
      74,    81,   190,    79,    95,   109,   137,   220,   220,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   -26,   -26,    85,   190,   -64,   -26,   109,    86,
     190,   109,    49,   -64,   -26,   -64,   109,    97,   190,   -64,
     203,   203,   214,   214,   220,   220,   220,   226,   226,   226,
     226,   226,   226,    99,    43,   -64,    44,   -64,   -64,   153,
      83,   190,   -64,    45,   122,   -64,   190,    65,    11,   -26,
     106,    -8,   107,    78,   -64,   109,   -64,   111,   113,    88,
      70,   -64,   -64,     5,   193,   109,    -8,   190,   -64,   109,
       5,   118,   -64,   100,   190,   -14,   190,   -64,   125,   -26,
     127,   -64,   102,   -64,    87,   -64,   134,    -8,   -64,   108,
     109,   115,     5,   190,   112,   -64,    -8,   -64,   119,   117,
     -64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -64,   -63,    -1,   -64,   -15,   -64,   139,   -64,   -64,   -64,
     -41,   -64,   -64,   -64,   -64,   -64,   -64,   -64,    46,    -3,
     -37,   -64,   120,   -64,   -64,   -64,   -64,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -64,   -12,
     -64,   -64,   -64,   -64,   -64,   -30
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -84
static const yytype_int16 yytable[] =
{
      11,    12,    44,    76,    43,   104,    83,    80,   181,   182,
       1,   109,    22,    24,    25,    36,    82,    48,    10,    49,
      23,    49,    14,    13,    86,   160,    43,    49,    72,    15,
      87,    88,    43,    50,     2,    50,    -4,    36,    51,   105,
      51,    50,    52,    36,    52,   110,    51,   149,   149,   155,
      52,   150,   151,   156,    46,   118,    54,   142,   -15,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,    45,    47,    55,    69,   -76,    85,   139,    81,
      84,   141,   144,   102,   103,   106,   146,   108,   111,   112,
      56,   115,   116,    10,    57,    58,    59,   114,   117,    60,
     147,   133,   133,   175,   148,    61,   138,   161,   137,   140,
     159,   163,   165,   145,   154,   171,    54,   169,   166,   168,
     170,   178,   172,   179,   191,   167,   -83,   173,   184,   177,
     186,   188,   189,   198,    55,   174,   164,   190,   194,   176,
     192,   197,   199,   200,    18,   119,   162,     0,   133,   136,
      56,   195,    43,    10,    57,    58,    59,     0,    79,    60,
     193,   153,     0,    36,     0,    61,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    95,     0,   185,    96,
      97,    98,    99,   100,   101,    89,    90,    91,    92,    93,
      94,    95,     0,     0,    96,    97,    98,    99,   100,   101,
       0,    89,    90,    91,    92,    93,    94,    95,    26,     0,
      96,    97,    98,    99,   100,   101,     0,    27,     0,    28,
       0,    29,    30,     0,    31,     0,    32,     0,     0,    33,
      34,    35,     0,     0,     0,     0,     0,    10,    89,    90,
      91,    92,    93,    94,    95,     0,     0,    96,    97,    98,
      99,   100,   101,    91,    92,    93,    94,    95,     0,     0,
      96,    97,    98,    99,   100,   101,    93,    94,    95,     0,
       0,    96,    97,    98,    99,   100,   101,    96,    97,    98,
      99,   100,   101,   -84,   -84,   -84,   -84,   -84,   -84
};

static const yytype_int16 yycheck[] =
{
       1,     2,    17,    33,    16,    68,    47,    44,    22,    23,
      18,    74,     5,    14,    15,    16,    46,    14,    44,    16,
      13,    16,    27,     0,    54,    14,    38,    16,    29,    34,
      60,    61,    44,    30,    42,    30,     9,    38,    35,    69,
      35,    30,    39,    44,    39,    75,    35,     4,     4,     4,
      39,     8,     8,     8,    13,    85,     7,     8,     5,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,     9,     5,    25,    43,     7,    13,   108,    45,
      45,   111,   112,     7,     7,    19,   116,     7,    13,     7,
      41,    10,    13,    44,    45,    46,    47,    23,     3,    50,
       3,   102,   103,   166,     5,    56,   107,   148,    23,    23,
      45,     5,     5,   114,    31,    45,     7,     4,    40,     8,
      32,     3,   163,    23,   187,   155,     4,   164,     3,   170,
       3,    29,    45,   196,    25,   165,   151,     3,    23,   169,
      32,    29,    23,    26,     5,     8,   149,    -1,   149,   103,
      41,   192,   164,    44,    45,    46,    47,    -1,    38,    50,
     190,     8,    -1,   164,    -1,    56,    -1,    -1,    -1,    -1,
      48,    49,    50,    51,    52,    53,    54,    -1,   179,    57,
      58,    59,    60,    61,    62,    48,    49,    50,    51,    52,
      53,    54,    -1,    -1,    57,    58,    59,    60,    61,    62,
      -1,    48,    49,    50,    51,    52,    53,    54,    15,    -1,
      57,    58,    59,    60,    61,    62,    -1,    24,    -1,    26,
      -1,    28,    29,    -1,    31,    -1,    33,    -1,    -1,    36,
      37,    38,    -1,    -1,    -1,    -1,    -1,    44,    48,    49,
      50,    51,    52,    53,    54,    -1,    -1,    57,    58,    59,
      60,    61,    62,    50,    51,    52,    53,    54,    -1,    -1,
      57,    58,    59,    60,    61,    62,    52,    53,    54,    -1,
      -1,    57,    58,    59,    60,    61,    62,    57,    58,    59,
      60,    61,    62,    57,    58,    59,    60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    42,    64,    67,    68,    69,    70,    75,    76,
      44,    65,    65,     0,    27,    34,    77,    79,    69,    66,
      71,    72,     5,    13,    65,    65,    15,    24,    26,    28,
      29,    31,    33,    36,    37,    38,    65,    83,    84,    85,
      87,    91,    95,   102,    67,     9,    13,     5,    14,    16,
      30,    35,    39,    73,     7,    25,    41,    45,    46,    47,
      50,    56,    65,    74,   102,   108,    80,    78,    86,    43,
      90,    97,    65,    92,    96,    89,   108,    88,   103,    85,
      83,    45,   108,    73,    45,    13,   108,   108,   108,    48,
      49,    50,    51,    52,    53,    54,    57,    58,    59,    60,
      61,    62,     7,     7,    64,   108,    19,   101,     7,    64,
     108,    13,     7,   104,    23,    10,    13,     3,   108,     8,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,    65,    81,    82,    81,    23,    65,   108,
      23,   108,     8,   106,   108,    65,   108,     3,     5,     4,
       8,     8,    98,     8,    31,     4,     8,   105,   107,    45,
      14,    73,    82,     5,    67,     5,    40,   108,     8,     4,
      32,    45,    73,    83,   108,    64,   108,    73,     3,    23,
      99,    22,    23,    93,     3,    65,     3,    94,    29,    45,
       3,    64,    32,   108,    23,    73,   100,    29,    64,    23,
      26
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
        case 3:
#line 102 "p.y"
    {
                    Trace("ID:");
                    Trace((yyvsp[(1) - (1)].input));
                    for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                        nowIDName[i] = (yyvsp[(1) - (1)].input)[i];
                        nowIDName[i + 1] = '\0';
                    }
                    (yyval.type) = typeLookUp(nowPointer, nowIDName, -1);
                }
    break;

  case 4:
#line 112 "p.y"
    {
                    Trace("ID:");
                    Trace((yyvsp[(1) - (1)].input));
                    for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                        nowIDName[i] = (yyvsp[(1) - (1)].input)[i];
                        nowIDName[i + 1] = '\0';
                    }

                }
    break;

  case 5:
#line 122 "p.y"
    {
                    int a = atoi((yyvsp[(4) - (5)].input));
                    //printf("%d\n", a);
                    if(!isInTheRange(nowPointer, nowIDName, a)){
                        yywarning("array index not in range");
                    }
                    (yyval.type) = typeLookUp(nowPointer, nowIDName, -1);
                }
    break;

  case 10:
#line 142 "p.y"
    {exprChecker = 0;}
    break;

  case 11:
#line 143 "p.y"
    {exprChecker = 0;}
    break;

  case 12:
#line 144 "p.y"
    {exprChecker = 0;}
    break;

  case 13:
#line 149 "p.y"
    {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                }
    break;

  case 14:
#line 156 "p.y"
    {
                    if (exprChecker == 1){
                        yywarning("no support expression calculate inside count variable");
                    }
                    if (exprChecker == 2){
                        int a = lookup(nowPointer, nowIDName);
                        if(a != -1){
                            if(!nowPointer->t.id[a].isConst){
                                yywarning("can't assign variable to const");
                            }
                            constInsertion(nowPointer, nowIDName2, nowPointer->t.id[a].type, nowPointer->t.id[a].value);
                        }
                    }else{
                        constInsertion(nowPointer, nowIDName2, (yyvsp[(5) - (5)].type), nowValue);
                    }
                }
    break;

  case 15:
#line 173 "p.y"
    {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                }
    break;

  case 16:
#line 180 "p.y"
    {
                    if (exprChecker == 1){
                        yywarning("no support expression calculate inside count variable");
                    }   
                    if (exprChecker == 2){
                        int a = lookup(nowPointer, nowIDName);
                        if(a != -1){
                            if(!nowPointer->t.id[a].isConst){
                                yywarning("can't assign variable to const");
                            }
                            if(nowPointer->t.id[a].type.type != (yyvsp[(2) - (7)].type).type){
                                yywarning("different type around assignment(:=)");
                            }
                            constInsertion(nowPointer, nowIDName2, (yyvsp[(5) - (7)].type), nowPointer->t.id[a].value);
                        }
                    }else{
                        Trace("const element generating...");
                        Trace(nowIDName);
                        //insert(nowPointer, nowIDName, $5, 1, -1);
                        
                        typeDef a = (yyvsp[(7) - (7)].type); 
                        if((yyvsp[(5) - (7)].type).type != a.type && !((yyvsp[(5) - (7)].type).type == real_type && a.type == bool_type || a.type == int_type)){
                            yywarning("wrong assignment for const variable");
                        }    
                        constInsertion(nowPointer, nowIDName, (yyvsp[(5) - (7)].type), nowValue);
                    }
                    
                }
    break;

  case 17:
#line 212 "p.y"
    {
                    typeDef a;
                    a.type = bool_type;
                    (yyval.type) = a;
                }
    break;

  case 18:
#line 218 "p.y"
    {
                    typeDef a;
                    a.type = str_type;
                    (yyval.type) = a;
                }
    break;

  case 19:
#line 224 "p.y"
    {
                    typeDef a;
                    a.type = int_type;
                    (yyval.type) = a;
                }
    break;

  case 20:
#line 230 "p.y"
    {
                    typeDef a;
                    a.type = real_type;
                    (yyval.type) = a;
                }
    break;

  case 21:
#line 239 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 22:
#line 240 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 23:
#line 241 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);}
    break;

  case 24:
#line 242 "p.y"
    {(yyval.input) = "true";}
    break;

  case 25:
#line 243 "p.y"
    {(yyval.input) = "false";}
    break;

  case 26:
#line 247 "p.y"
    {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    if((yyvsp[(4) - (6)].type).type != (yyvsp[(6) - (6)].type).type && !((yyvsp[(4) - (6)].type).type == real_type && (yyvsp[(6) - (6)].type).type == bool_type || (yyvsp[(6) - (6)].type).type == int_type)){
                        yywarning("wrong assignment for var variable");
                    } 
                    insert(nowPointer, nowIDName, (yyvsp[(4) - (6)].type), 0, -1);
                }
    break;

  case 27:
#line 256 "p.y"
    {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    typeDef a = (yyvsp[(4) - (4)].type);      
                    insert(nowPointer, nowIDName, a, 0, -1);
                }
    break;

  case 28:
#line 263 "p.y"
    {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, (yyvsp[(4) - (4)].type), 0, -1);
                }
    break;

  case 29:
#line 272 "p.y"
    {
                    int st = atoi((yyvsp[(5) - (10)].input));
                    int ed = atoi((yyvsp[(8) - (10)].input));
                    //printf("%s\n", nowIDName);
                    char* a = (char*)malloc(50);
                    int j;
                    for(j = 0; nowIDName[j] != '\0'; j++){
                        a[j] = nowIDName[j];
                    }
                    arrayInsertion(nowPointer, a, (yyvsp[(10) - (10)].type), st, ed);
                    // for(int i = st; i <= ed; i++){
                    //     char* k = intToChar(i);
                    //     printf("%c\n", k[0]);
                        
                    //     int size = strlen(nowIDName) + strlen(k) + 1;
                    //     a[j] = '[';
                    //     for(int l = j + 1; l < size; l++){
                    //         a[l] = k[l - j - 1];
                    //     }
                    //     a[size] = ']';
                    //     insert(nowPointer, a, $10, 0, i-st);
                    // }
                    Trace("array declear");
                }
    break;

  case 31:
#line 305 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
    break;

  case 32:
#line 313 "p.y"
    {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                }
    break;

  case 33:
#line 321 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
    break;

  case 34:
#line 331 "p.y"
    {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                    Trace("inside function Table");
                    Trace(nowIDName);
                }
    break;

  case 35:
#line 338 "p.y"
    {
                    Trace("function return type set:");
                    Trace(t_name[(yyvsp[(8) - (8)].type).type]);
                    setReturnType(nowPointer, (yyvsp[(8) - (8)].type));
                }
    break;

  case 39:
#line 354 "p.y"
    {
                    insert(nowPointer->innerLink, nowIDName, (yyvsp[(3) - (3)].type), 0, -1); // function input 有const嗎
                }
    break;

  case 40:
#line 358 "p.y"
    {
                    int st = atoi((yyvsp[(4) - (9)].input));
                    int ed = atoi((yyvsp[(7) - (9)].input));
                    char* a = (char*)malloc(50);
                    int j;
                    for(j = 0; nowIDName[j] != '\0'; j++){
                        a[j] = nowIDName[j];
                    }
                    arrayInsertion(nowPointer->innerLink, a, (yyvsp[(9) - (9)].type), st, ed);
                }
    break;

  case 45:
#line 381 "p.y"
    {
                    nowPointer = createTable(nowPointer, tailPointer, "begin_block", linenum);
                    tailPointer = nowPointer;
                }
    break;

  case 46:
#line 386 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
    break;

  case 51:
#line 401 "p.y"
    {
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            nowIDName2[i] = nowIDName[i];
                            nowIDName2[i + 1] = '\0';
                        }
                    }
    break;

  case 52:
#line 408 "p.y"
    {
                        Trace(nowIDName);
                        int a = changeValue(nowPointer, nowIDName2);
                        LT* b = findTable(tailPointer, nowIDName);
                        typeDef c = typeLookUp(nowPointer, nowIDName, -1);
                        //printf("%s\n", nowIDName);
                        if (a == -1){
                            yywarning("no variable exist");
                        }else if (a == -2){
                            yywarning("type const cannot be modify");
                        }
                        // if (b == NULL && c.type != $1.type){
                        //     yywarning("different type around assignment(:=)");
                        // }   
                        if(b != NULL){
                            //printf("%s\n", b->tableName);
                            if((yyvsp[(1) - (4)].type).type != b->returnType.type){
                                yywarning("cannot assign value due to wrong type");
                            }
                        }
                    }
    break;

  case 53:
#line 429 "p.y"
    {exprChecker = 0;}
    break;

  case 54:
#line 430 "p.y"
    {
                        (yyval.type) = (yyvsp[(3) - (3)].type);
                        if (exprChecker == 2){
                            int a = allLookUp(nowPointer, nowIDName);
                            //printf("%d\n", a);
                            if(a == -1){
                                yywarning("variable not exist");
                            }
                        }
                    }
    break;

  case 55:
#line 441 "p.y"
    {
                        (yyval.type) = (yyvsp[(2) - (2)].type);
                    }
    break;

  case 56:
#line 445 "p.y"
    {
                        typeDef a = typeCalculateCheck(tableReturnType(nowPointer, nowPointer->tableName), (yyvsp[(2) - (2)].type));
                        if(a.type == (yyvsp[(2) - (2)].type).type){
                            (yyval.type) = (yyvsp[(2) - (2)].type);
                        }else{
                            yywarning("wrong return type");
                            // 隱式行變轉換？ -> done
                        }
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }

                    }
    break;

  case 57:
#line 461 "p.y"
    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }

                    }
    break;

  case 58:
#line 470 "p.y"
    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                    }
    break;

  case 62:
#line 484 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "if_block", linenum);
                        tailPointer = nowPointer;
                    }
    break;

  case 64:
#line 492 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        nowPointer = createTable(nowPointer, tailPointer, "else_block", linenum);
                        tailPointer = nowPointer;
                    }
    break;

  case 65:
#line 502 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
    break;

  case 66:
#line 510 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
    break;

  case 67:
#line 520 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "loop_block", linenum);
                        tailPointer = nowPointer;
                    }
    break;

  case 68:
#line 525 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
    break;

  case 69:
#line 533 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "for_loop_block", linenum);
                        tailPointer = nowPointer;
                    }
    break;

  case 70:
#line 538 "p.y"
    {
                        typeDef a;
                        a.type = int_type;
                        int b = lookup(nowPointer->l, nowIDName);
                        if(b == -1){
                            yywarning("no variable exist");
                        }
                        if(b != -1 && nowPointer->l->t.id[b].type.type != int_type){
                            yywarning("variable no int type");
                        }
                        //insert(nowPointer, nowIDName, a, 0, -1);
                    }
    break;

  case 71:
#line 551 "p.y"
    {
                        typeDef a;
                        a.type = int_type;
                        if((yyvsp[(7) - (7)].type).type != a.type){
                            yywarning("loop lower range must be type of int");
                        }
                    }
    break;

  case 72:
#line 559 "p.y"
    {
                        typeDef a;
                        a.type = int_type;
                        if((yyvsp[(11) - (11)].type).type != a.type){
                            yywarning("loop upper range must be type of int");
                        }
                    }
    break;

  case 73:
#line 567 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                    }
    break;

  case 76:
#line 582 "p.y"
    {
                        //printf("%s\n", nowIDName);
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            nowFuncName[i] = nowIDName[i];
                            nowFuncName[i + 1] = '\0';
                        }

                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("%s\n", func_tab->tableName);
                        if(func_tab == NULL){
                            yywarning(strcat(strcat("no function with name ", nowFuncName) ," exsit"));
                        }
                        typeDef a = tableReturnType(func_tab, nowFuncName);
                        (yyval.type) = a;
                        printf("%s\n", t_name[a.type]);
                    }
    break;

  case 77:
#line 599 "p.y"
    {
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        
                        if (func_tab->innerLink->t.tableSize != functionCall_counter){
                            yywarning(strcat(strcat("not the correct form for function ", nowFuncName), " "));
                        }
                        functionCall_counter = 0;
                    }
    break;

  case 80:
#line 612 "p.y"
    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $2.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $2.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if((yyvsp[(2) - (2)].type).type != a.type){
                            //printf("%s\n%s\n", t_name[$2.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
    break;

  case 82:
#line 629 "p.y"
    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $3.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $3.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if((yyvsp[(3) - (3)].type).type != a.type){
                            //printf("%s\n%s\n", t_name[$3.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
    break;

  case 83:
#line 642 "p.y"
    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $1.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $1.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if((yyvsp[(1) - (1)].type).type != a.type){
                            //printf("%s\n%s\n", t_name[$1.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
    break;

  case 84:
#line 655 "p.y"
    {
                        //printf("--------------%s\n", nowFuncName);
                        //printf("table:%s\t now type:%u\n", nowPointer->tableName, $4.type);
                        LT* func_tab = findTable(tailPointer, nowFuncName);
                        //printf("table:%s\t now type:%u\n", func_tab->tableName, $4.type);
                        typeDef a = getFunctionInputType(func_tab, functionCall_counter);
                        functionCall_counter++;
                        if((yyvsp[(4) - (4)].type).type != a.type){
                            //printf("%s\n%s\n", t_name[$4.type], t_name[a.type]);
                            yywarning("uncorrect parameter type");
                        }
                    }
    break;

  case 85:
#line 676 "p.y"
    {
                for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                    nowValue[i] = (yyvsp[(1) - (1)].input)[i];
                    nowValue[i + 1] = '\0';
                }
                (yyval.type) = typeCheck((yyvsp[(1) - (1)].input));     
            }
    break;

  case 86:
#line 684 "p.y"
    {
                exprChecker = 1;
                typeDef a,b;
                a = (yyvsp[(1) - (3)].type);
                b = (yyvsp[(3) - (3)].type);
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                (yyval.type) = check;
                
            }
    break;

  case 87:
#line 699 "p.y"
    {
                exprChecker = 1;
                typeDef a,b;
                a = (yyvsp[(1) - (3)].type);
                b = (yyvsp[(3) - (3)].type);
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                (yyval.type) = check;
                
            }
    break;

  case 88:
#line 714 "p.y"
    {
                exprChecker = 1;
                typeDef a,b;
                a = (yyvsp[(1) - (3)].type);
                b = (yyvsp[(3) - (3)].type);
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                (yyval.type) = check;
                
            }
    break;

  case 89:
#line 729 "p.y"
    {
                exprChecker = 1;
                typeDef a,b;       // 要多check b 不能是 0
                a = (yyvsp[(1) - (3)].type);
                b = (yyvsp[(3) - (3)].type);
                typeDef c;
                c.type = str_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }
                (yyval.type) = check;
            }
    break;

  case 90:
#line 743 "p.y"
    {
                exprChecker = 1;
                typeDef a,b;       // 要多check b 不能是 0 而且 b 要是 int 
                a = (yyvsp[(1) - (3)].type);
                b = (yyvsp[(3) - (3)].type);
                typeDef c;
                c.type = str_type;
                typeDef d;
                d.type = int_type;
                typeDef check = typeCalculateCheck(a, b);
                if(a.type == c.type || b.type == c.type){
                    yywarning("warning: can't calculate string type");
                }else if(b.type != d.type){
                    yywarning("right identifier must be int type!");
                }
                (yyval.type) = check;
            }
    break;

  case 91:
#line 761 "p.y"
    {
                exprChecker = 1;
                typeDef a = (yyvsp[(2) - (2)].type);
                typeDef b;
                b.type = str_type;
                if(a.type == b.type){
                    yywarning("can't plus minus in front of type string");
                }
                (yyval.type) = (yyvsp[(2) - (2)].type);
            }
    break;

  case 92:
#line 771 "p.y"
    {(yyval.type) = (yyvsp[(2) - (3)].type);}
    break;

  case 93:
#line 773 "p.y"
    {
                (yyval.type) = (yyvsp[(1) - (1)].type); 
                exprChecker = 2;   
            }
    break;

  case 94:
#line 777 "p.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);}
    break;

  case 95:
#line 779 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around <=");
                }
                (yyval.type) = a;
            }
    break;

  case 96:
#line 789 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around <");
                }
                (yyval.type) = a;
            }
    break;

  case 97:
#line 799 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around >=");
                }
                
                (yyval.type) = a;
            }
    break;

  case 98:
#line 810 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around >");
                }
                (yyval.type) = a;
            }
    break;

  case 99:
#line 820 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around EQUAL(=)");
                }
                (yyval.type) = a;
            }
    break;

  case 100:
#line 830 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around EQUAL(=)");
                }
                (yyval.type) = a;
            }
    break;

  case 101:
#line 840 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != a.type || (yyvsp[(3) - (3)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
            }
    break;

  case 102:
#line 850 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != a.type || (yyvsp[(3) - (3)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
            }
    break;

  case 103:
#line 860 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(2) - (2)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
            }
    break;


/* Line 1267 of yacc.c.  */
#line 2592 "y.tab.c"
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


#line 870 "p.y"

//#include "lex.yy.c"

int yyerror(const char *msg)
{
    fprintf(stderr, "\t---error: %s\n", msg);
    //fprintf(stderr, "%d\n", linenum);
    exit(0);
    return 0;
}

void yywarning(const char *msg)
{
    fprintf(stderr, "\t--warning: %s\n", msg);
    //fprintf(stderr, "%d\n", linenum);
}

int main(int argc, char* argv[])
{
    nowIDName = (char*)malloc(50);
    nowIDName2 = (char*)malloc(50);
    nowFuncName = (char*)malloc(50);
    nowValue = (char*)malloc(50);
    nowPointer = starter("main");
    tailPointer = nowPointer;
    /* open the source program file */
    if (argc < 2) {
        printf ("Usage: sc filename\n");
        //exit(1);
        return 0;
    }
    if(!strcmp(argv[1], "--debug")){
        yydebug = 1;
    }
    yyin = fopen(argv[argc - 1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */

    allTableDump(tailPointer);
}



