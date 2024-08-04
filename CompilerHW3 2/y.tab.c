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
     BBEGIN = 269,
     BOOL = 270,
     CHAR = 271,
     CONST = 272,
     DECREASING = 273,
     DEFAULT = 274,
     DO = 275,
     ELSE = 276,
     END = 277,
     T_EXIT = 278,
     T_FALSE = 279,
     FOR = 280,
     FUNCTION = 281,
     T_IF = 282,
     INT = 283,
     LOOP = 284,
     OF = 285,
     PUT = 286,
     PROCEDURE = 287,
     REAL = 288,
     RESULT = 289,
     RETURN = 290,
     SKIP = 291,
     STRING = 292,
     THEN = 293,
     T_TRUE = 294,
     VAR = 295,
     WHEN = 296,
     ID = 297,
     INT_NUM = 298,
     REAL_NUM = 299,
     STR_CONT = 300,
     OR = 301,
     AND = 302,
     MINUS = 303,
     PLUS = 304,
     MOD = 305,
     DIV = 306,
     TIMES = 307,
     UMINUS = 308,
     NOT = 309,
     NOT_EQ = 310,
     EQUAL = 311,
     EM_T = 312,
     M_T = 313,
     EL_T = 314,
     L_T = 315
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
#define BBEGIN 269
#define BOOL 270
#define CHAR 271
#define CONST 272
#define DECREASING 273
#define DEFAULT 274
#define DO 275
#define ELSE 276
#define END 277
#define T_EXIT 278
#define T_FALSE 279
#define FOR 280
#define FUNCTION 281
#define T_IF 282
#define INT 283
#define LOOP 284
#define OF 285
#define PUT 286
#define PROCEDURE 287
#define REAL 288
#define RESULT 289
#define RETURN 290
#define SKIP 291
#define STRING 292
#define THEN 293
#define T_TRUE 294
#define VAR 295
#define WHEN 296
#define ID 297
#define INT_NUM 298
#define REAL_NUM 299
#define STR_CONT 300
#define OR 301
#define AND 302
#define MINUS 303
#define PLUS 304
#define MOD 305
#define DIV 306
#define TIMES 307
#define UMINUS 308
#define NOT 309
#define NOT_EQ 310
#define EQUAL 311
#define EM_T 312
#define M_T 313
#define EL_T 314
#define L_T 315




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

FILE *out;

#define YYDEBUG 1

char* nowIDName;
char* nowIDName2;
char* nowIDName3;
char* nowValue;
char* nowFuncName;
char* nowFuncName2;
char* name;
char* funcType;
int exprChecker = 0;
int functionCall_counter = 0;       // count function's reference element
int outOfBlockCheck = 0;            // check if the block get any return or exit
int isInBlock = 0;
int NowScopeCount = 1;
int isNew = 0;
int isInIf = 0;

int ifCheck = 0;
int ifMin = 0;
int ifNow = 0;
int ifMax = 0;

int isDecrease = 0;
int firstForCounter=0;
int isInFunc = 0;
int isCalling = 0;
int isInLoop = 0;

char* nowType;
char* nowCommand;
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
#line 76 "p.y"
{
    typeDef type;
    char* input;
}
/* Line 193 of yacc.c.  */
#line 294 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 307 "y.tab.c"

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   272

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  189

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

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
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     9,    10,    13,    15,    17,    19,
      20,    22,    25,    27,    29,    31,    32,    33,    39,    42,
      47,    49,    51,    53,    55,    57,    59,    61,    63,    65,
      72,    77,    82,    83,    84,    90,    91,    92,   103,   104,
     113,   114,   118,   120,   124,   125,   127,   130,   132,   133,
     138,   140,   142,   144,   146,   147,   152,   153,   157,   160,
     162,   163,   167,   169,   170,   173,   174,   175,   176,   185,
     186,   191,   193,   196,   197,   203,   204,   205,   206,   207,
     208,   225,   226,   228,   229,   233,   236,   240,   241,   246,
     250,   251,   256,   258,   262,   266,   270,   274,   278,   281,
     285,   287,   289,   293,   297,   301,   305,   309,   313,   317,
     321
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      62,     0,    -1,    -1,    67,    77,    63,    85,    -1,    -1,
      65,    64,    -1,    67,    -1,    85,    -1,    42,    -1,    -1,
      68,    -1,    68,    69,    -1,    69,    -1,    70,    -1,    76,
      -1,    -1,    -1,    17,    71,    66,    72,    73,    -1,    13,
     115,    -1,     5,    74,    13,   115,    -1,    15,    -1,    37,
      -1,    28,    -1,    33,    -1,    45,    -1,    43,    -1,    44,
      -1,    39,    -1,    24,    -1,    40,    66,     5,    74,    13,
      75,    -1,    40,    66,    13,    75,    -1,    40,    66,     5,
      74,    -1,    -1,    -1,    81,    78,    64,    22,    66,    -1,
      -1,    -1,    32,    66,    79,     7,    83,     8,    80,    64,
      22,    66,    -1,    -1,    26,    66,    82,     7,    83,     8,
       5,    74,    -1,    -1,    83,     4,    84,    -1,    84,    -1,
      66,     5,    74,    -1,    -1,    86,    -1,    86,    87,    -1,
      87,    -1,    -1,    14,    88,    64,    22,    -1,    89,    -1,
      94,    -1,   101,    -1,   109,    -1,    -1,    42,    90,    13,
     115,    -1,    -1,    31,    91,   115,    -1,    34,   115,    -1,
      35,    -1,    -1,    23,    92,    93,    -1,    36,    -1,    -1,
      41,   115,    -1,    -1,    -1,    -1,    27,    95,   115,    96,
      38,    64,    97,    98,    -1,    -1,    21,    99,    64,   100,
      -1,   100,    -1,    22,    27,    -1,    -1,    29,   102,    64,
      22,    29,    -1,    -1,    -1,    -1,    -1,    -1,    25,   103,
     108,    66,   104,     5,   115,   105,     3,     3,   106,   115,
     107,    64,    22,    25,    -1,    -1,    18,    -1,    -1,    66,
     110,   111,    -1,     7,     8,    -1,     7,   113,     8,    -1,
      -1,     7,   115,   112,     8,    -1,   113,     4,   115,    -1,
      -1,   115,   114,     4,   115,    -1,    75,    -1,   115,    49,
     115,    -1,   115,    48,   115,    -1,   115,    52,   115,    -1,
     115,    51,   115,    -1,   115,    50,   115,    -1,    48,   115,
      -1,     7,   115,     8,    -1,    66,    -1,   109,    -1,   115,
      60,   115,    -1,   115,    59,   115,    -1,   115,    57,   115,
      -1,   115,    58,   115,    -1,   115,    56,   115,    -1,   115,
      55,   115,    -1,   115,    47,   115,    -1,   115,    46,   115,
      -1,    54,   115,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   124,   124,   123,   138,   138,   141,   142,   146,   199,
     200,   202,   203,   207,   208,   212,   213,   212,   221,   239,
     269,   275,   281,   287,   297,   298,   299,   300,   309,   320,
     343,   365,   386,   387,   387,   402,   406,   401,   423,   422,
     474,   475,   476,   480,   489,   490,   493,   494,   498,   497,
     511,   512,   513,   514,   519,   518,   558,   557,   589,   607,
     618,   618,   626,   634,   634,   651,   670,   677,   650,   684,
     683,   694,   696,   713,   712,   751,   772,   790,   808,   821,
     750,   892,   893,   897,   896,   953,   954,   956,   955,   972,
     986,   985,  1019,  1041,  1057,  1073,  1089,  1105,  1125,  1138,
    1139,  1153,  1154,  1173,  1193,  1213,  1232,  1246,  1260,  1272,
    1284
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DOT", "COMMA", "COLON", "SEMICOLON",
  "U_PAREN", "L_PAREN", "U_BRACKET", "L_BRACKET", "U_B_PAREN", "L_B_PAREN",
  "GIVEN_EQUAL", "BBEGIN", "BOOL", "CHAR", "CONST", "DECREASING",
  "DEFAULT", "DO", "ELSE", "END", "T_EXIT", "T_FALSE", "FOR", "FUNCTION",
  "T_IF", "INT", "LOOP", "OF", "PUT", "PROCEDURE", "REAL", "RESULT",
  "RETURN", "SKIP", "STRING", "THEN", "T_TRUE", "VAR", "WHEN", "ID",
  "INT_NUM", "REAL_NUM", "STR_CONT", "OR", "AND", "MINUS", "PLUS", "MOD",
  "DIV", "TIMES", "UMINUS", "NOT", "NOT_EQ", "EQUAL", "EM_T", "M_T",
  "EL_T", "L_T", "$accept", "programss", "@1", "programs", "program",
  "identifier", "pre_var_dec", "variable_dec", "variable_type",
  "const_dec", "@2", "@3", "const_back", "type_dec", "const_val_expr",
  "var_dec", "function_dec", "@4", "@5", "@6", "function_def", "@7",
  "argument_dec", "identi_req", "pre_stmt", "statments", "statment", "@8",
  "simple_statment", "@9", "@10", "@11", "cond_check", "cond_statment",
  "@12", "@13", "@14", "else_block", "@15", "end_if", "loop_statment",
  "@16", "@17", "@18", "@19", "@20", "@21", "decreasing", "func_proc_call",
  "@22", "func_call_input", "@23", "func_input", "@24", "expr", 0
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
     315
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    63,    62,    64,    64,    65,    65,    66,    67,
      67,    68,    68,    69,    69,    71,    72,    70,    73,    73,
      74,    74,    74,    74,    75,    75,    75,    75,    75,    76,
      76,    76,    77,    78,    77,    79,    80,    77,    82,    81,
      83,    83,    83,    84,    85,    85,    86,    86,    88,    87,
      87,    87,    87,    87,    90,    89,    91,    89,    89,    89,
      92,    89,    89,    93,    93,    95,    96,    97,    94,    99,
      98,    98,   100,   102,   101,   103,   104,   105,   106,   107,
     101,   108,   108,   110,   109,   111,   111,   112,   111,   113,
     114,   113,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     4,     0,     2,     1,     1,     1,     0,
       1,     2,     1,     1,     1,     0,     0,     5,     2,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     6,
       4,     4,     0,     0,     5,     0,     0,    10,     0,     8,
       0,     3,     1,     3,     0,     1,     2,     1,     0,     4,
       1,     1,     1,     1,     0,     4,     0,     3,     2,     1,
       0,     3,     1,     0,     2,     0,     0,     0,     8,     0,
       4,     1,     2,     0,     5,     0,     0,     0,     0,     0,
      16,     0,     1,     0,     3,     2,     3,     0,     4,     3,
       0,     4,     1,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       9,    15,     0,     0,    32,    10,    12,    13,    14,     0,
       8,     0,     1,     0,     0,     2,    33,    11,    16,     0,
       0,    38,    35,    44,     4,     0,    20,    22,    23,    21,
      31,    28,    27,    25,    26,    24,    30,     0,     0,    48,
      60,    75,    65,    73,    56,     0,    59,    62,     8,    83,
       3,    45,    47,    50,    51,    52,    53,     0,     4,     6,
       7,     0,     0,    17,     0,    40,    40,     4,    63,    81,
       0,     4,     0,     0,     0,     0,   100,    92,   101,    58,
       0,     0,    46,     0,     5,     0,    18,    29,     0,     0,
      42,     0,     0,     0,    61,    82,     0,    66,     0,    57,
       0,    98,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    84,    34,
       0,     0,     0,     0,    36,    49,    64,    76,     0,     0,
      99,   109,   108,    94,    93,    97,    96,    95,   107,   106,
     104,   105,   103,   102,    55,    85,     0,    87,    19,    43,
      41,     0,     4,     0,     4,    74,     0,    86,     0,     0,
      39,     0,     0,    67,    89,    88,     0,     0,    77,     0,
      91,    37,     0,    69,     0,    68,    71,     0,     4,    72,
      78,     0,     0,    70,    79,     4,     0,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    23,    57,    58,    76,    59,     5,     6,     7,
       9,    25,    63,    30,    77,     8,    15,    24,    38,   152,
      16,    37,    89,    90,    60,    51,    52,    67,    53,    80,
      72,    68,    94,    54,    70,   128,   169,   175,   178,   176,
      55,    71,    69,   153,   172,   182,   185,    96,    78,    81,
     118,   158,   146,   159,    79
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -58
static const yytype_int16 yypact[] =
{
     -12,   -58,   -27,    18,   -13,   -12,   -58,   -58,   -58,   -27,
     -58,     3,   -58,   -27,   -27,   -58,   -58,   -58,   -58,    24,
      68,   -58,   -58,     9,   175,     4,   -58,   -58,   -58,   -58,
      20,   -58,   -58,   -58,   -58,   -58,   -58,    28,    34,   -58,
     -58,   -58,   -58,   -58,   -58,   184,   -58,   -58,    29,   -58,
     -58,     9,   -58,   -58,   -58,   -58,   -58,    25,   175,   -58,
     -58,    24,   184,   -58,    68,   -27,   -27,   175,    12,    37,
     184,   175,   184,   184,   184,   184,    52,   -58,   -58,   193,
      47,    55,   -58,   -27,   -58,    54,   193,   -58,    63,    16,
     -58,    21,    48,   184,   -58,   -58,   -27,   193,    49,   193,
     122,    59,    59,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   177,   -58,   -58,
     184,    24,   -27,    67,   -58,   -58,   193,   -58,    42,    60,
     -58,   206,   206,   103,   103,    59,    59,    59,   212,   212,
     212,   212,   212,   212,   193,   -58,    50,    27,   193,   -58,
     -58,    24,   175,    83,   175,   -58,   184,   -58,    82,    87,
     -58,    76,   184,   -58,   193,   -58,   184,   -27,   193,     5,
     193,   -58,    96,   -58,    73,   -58,   -58,    99,   175,   -58,
     -58,    86,   184,   -58,   193,   175,    88,    84,   -58
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -58,   -58,   -58,   -57,   -58,    -2,   123,   -58,   117,   -58,
     -58,   -58,   -58,   -55,   -16,   -58,   -58,   -58,   -58,   -58,
     -58,   -58,    61,     7,   102,   -58,    75,   -58,   -58,   -58,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -49,
     -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -21,   -58,
     -58,   -58,   -58,   -58,    31
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -91
static const yytype_int16 yytable[] =
{
      11,    84,    56,    56,    36,     1,    85,    18,    19,    61,
      92,    21,    22,    13,    98,    10,    20,    62,    12,    14,
     122,    49,    49,    39,   123,   122,   173,   174,     2,   124,
      56,   -90,    40,    64,    41,    65,    42,    56,    43,    26,
      44,    66,   -54,    45,    46,    47,    56,    83,    87,    49,
      56,    48,    27,    93,   156,    95,    49,    28,   157,   -83,
     116,    29,   117,    88,    88,    49,   149,   120,   121,    49,
     125,   129,   151,   103,   104,   105,   106,   107,   108,   109,
     154,   119,   110,   111,   112,   113,   114,   115,   162,   155,
     165,   166,    31,    86,   127,   161,   160,   163,   167,   177,
     179,    97,   180,    99,   100,   101,   102,    32,   174,   188,
     187,    33,    34,    35,   110,   111,   112,   113,   114,   115,
      88,   181,    17,     4,   126,    50,    82,    91,   186,   150,
     130,    56,   183,    56,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   147,     0,
      49,   148,    49,   107,   108,   109,     0,    56,   110,   111,
     112,   113,   114,   115,    56,   171,     0,     0,   103,   104,
     105,   106,   107,   108,   109,     0,    49,   110,   111,   112,
     113,   114,   115,    49,    73,   145,     0,   164,     0,    39,
       0,    73,     1,   168,     0,     0,     0,   170,    40,     0,
      41,    31,    42,     0,    43,     0,    44,     0,    31,    45,
      46,    47,     0,   184,     0,     2,    32,    48,     0,    10,
      33,    34,    35,    32,     0,    74,    10,    33,    34,    35,
       0,    75,    74,     0,     0,     0,     0,     0,    75,   103,
     104,   105,   106,   107,   108,   109,     0,     0,   110,   111,
     112,   113,   114,   115,   105,   106,   107,   108,   109,     0,
       0,   110,   111,   112,   113,   114,   115,   -91,   -91,   -91,
     -91,   -91,   -91
};

static const yytype_int16 yycheck[] =
{
       2,    58,    23,    24,    20,    17,    61,     9,     5,     5,
      67,    13,    14,    26,    71,    42,    13,    13,     0,    32,
       4,    23,    24,    14,     8,     4,    21,    22,    40,     8,
      51,     4,    23,    13,    25,     7,    27,    58,    29,    15,
      31,     7,    13,    34,    35,    36,    67,    22,    64,    51,
      71,    42,    28,    41,     4,    18,    58,    33,     8,     7,
      13,    37,     7,    65,    66,    67,   121,    13,     5,    71,
      22,    22,     5,    46,    47,    48,    49,    50,    51,    52,
      38,    83,    55,    56,    57,    58,    59,    60,     5,    29,
       8,     4,    24,    62,    96,   152,   151,   154,    22,     3,
      27,    70,     3,    72,    73,    74,    75,    39,    22,    25,
      22,    43,    44,    45,    55,    56,    57,    58,    59,    60,
     122,   178,     5,     0,    93,    23,    51,    66,   185,   122,
       8,   152,   181,   154,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,    -1,
     152,   120,   154,    50,    51,    52,    -1,   178,    55,    56,
      57,    58,    59,    60,   185,   167,    -1,    -1,    46,    47,
      48,    49,    50,    51,    52,    -1,   178,    55,    56,    57,
      58,    59,    60,   185,     7,     8,    -1,   156,    -1,    14,
      -1,     7,    17,   162,    -1,    -1,    -1,   166,    23,    -1,
      25,    24,    27,    -1,    29,    -1,    31,    -1,    24,    34,
      35,    36,    -1,   182,    -1,    40,    39,    42,    -1,    42,
      43,    44,    45,    39,    -1,    48,    42,    43,    44,    45,
      -1,    54,    48,    -1,    -1,    -1,    -1,    -1,    54,    46,
      47,    48,    49,    50,    51,    52,    -1,    -1,    55,    56,
      57,    58,    59,    60,    48,    49,    50,    51,    52,    -1,
      -1,    55,    56,    57,    58,    59,    60,    55,    56,    57,
      58,    59,    60
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    17,    40,    62,    67,    68,    69,    70,    76,    71,
      42,    66,     0,    26,    32,    77,    81,    69,    66,     5,
      13,    66,    66,    63,    78,    72,    15,    28,    33,    37,
      74,    24,    39,    43,    44,    45,    75,    82,    79,    14,
      23,    25,    27,    29,    31,    34,    35,    36,    42,    66,
      85,    86,    87,    89,    94,   101,   109,    64,    65,    67,
      85,     5,    13,    73,    13,     7,     7,    88,    92,   103,
      95,   102,    91,     7,    48,    54,    66,    75,   109,   115,
      90,   110,    87,    22,    64,    74,   115,    75,    66,    83,
      84,    83,    64,    41,    93,    18,   108,   115,    64,   115,
     115,   115,   115,    46,    47,    48,    49,    50,    51,    52,
      55,    56,    57,    58,    59,    60,    13,     7,   111,    66,
      13,     5,     4,     8,     8,    22,   115,    66,    96,    22,
       8,   115,   115,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,     8,   113,   115,   115,    74,
      84,     5,    80,   104,    38,    29,     4,     8,   112,   114,
      74,    64,     5,    64,   115,     8,     4,    22,   115,    97,
     115,    66,   105,    21,    22,    98,   100,     3,    99,    27,
       3,    64,   106,   100,   115,   107,    64,    22,    25
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
#line 124 "p.y"
    {
                    fprintf(out, "\tmethod public static void main(java.lang.String[])\n");
                    fprintf(out, "\tmax_stack 15\n");
                    fprintf(out, "\tmax_locals 15\n");
                    fprintf(out, "\t{\n");
                    NowScopeCount = 2;
                }
    break;

  case 3:
#line 131 "p.y"
    {
                    fprintf(out, "\t\treturn\n");
                    fprintf(out, "\t}\n");
                    fprintf(out, "}\n");
                }
    break;

  case 8:
#line 147 "p.y"
    {
                    Trace("ID:");
                    Trace((yyvsp[(1) - (1)].input));
                    for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                        nowIDName[i] = (yyvsp[(1) - (1)].input)[i];
                        nowIDName[i + 1] = '\0';
                    }
                    Symbol a = getNode(nowPointer, nowIDName);
                    if ( a.index != -100 && isNew == 0) {
                        if ( a.isConst == 1 ) {
                            if (a.type.type == int_type){
                                printTab(NowScopeCount);
                                fprintf(out, "sipush %s\n", a.value);
                            }else if (a.type.type == bool_type){
                                if(strcmp(a.value,"true")){
                                    printTab(NowScopeCount);
                                    fprintf(out, "iconst_1\n");
                                }else{
                                    printTab(NowScopeCount);
                                    fprintf(out, "iconst_0\n");
                                }
                            }else if (a.type.type == str_type){
                                printTab(NowScopeCount);
                                fprintf(out, "ldc \"%s\"", a.value);
                            }
                        }else{
                            LT* getter = getNodesScope(nowPointer, nowIDName);
                            //printf("%s \n", getter->tableName);
                            if(isInFunc == 1){
                                Symbol a = getNode(getter->innerLink, nowIDName);
                                printTab(NowScopeCount);
                                
                                fprintf(out, "iload %d\n", a.index);
                                
                            }else{
                                printTab(NowScopeCount);
                                if (!strcmp(getter->tableName, "main")) {
                                    fprintf(out, "getstatic int %s.%s\n", name, a.name);
                                }else{
                                    fprintf(out, "iload %d\n", a.index);
                                }
                            }
                                
                            
                        }
                    }
                    (yyval.type) = typeLookUp(nowPointer, nowIDName, -1);
                }
    break;

  case 13:
#line 207 "p.y"
    {exprChecker = 0;}
    break;

  case 14:
#line 208 "p.y"
    {exprChecker = 0;}
    break;

  case 15:
#line 212 "p.y"
    {isNew = 1;}
    break;

  case 16:
#line 213 "p.y"
    {
                    for(int i = 0; nowIDName[i] != '\0'; i++){
                        nowIDName2[i] = nowIDName[i];
                        nowIDName2[i + 1] = '\0';
                    }
                    
                }
    break;

  case 18:
#line 222 "p.y"
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
                        constInsertion(nowPointer, nowIDName2, (yyvsp[(2) - (2)].type), nowValue);
                    }
                    isNew = 0;
                }
    break;

  case 19:
#line 240 "p.y"
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
                            constInsertion(nowPointer, nowIDName2, (yyvsp[(2) - (4)].type), nowPointer->t.id[a].value);
                        }
                    }else{
                        Trace("const element generating...");
                        Trace(nowIDName);
                        //insert(nowPointer, nowIDName, $2, 1, -1);
                        
                        typeDef a = (yyvsp[(4) - (4)].type); 
                        if((yyvsp[(2) - (4)].type).type != a.type && !((yyvsp[(2) - (4)].type).type == real_type && a.type == bool_type || a.type == int_type)){
                            yywarning("wrong assignment for const variable");
                        }    
                        constInsertion(nowPointer, nowIDName, (yyvsp[(2) - (4)].type), nowValue);
                    }
                    isNew = 0;
                    
                }
    break;

  case 20:
#line 270 "p.y"
    {
                    typeDef a;
                    a.type = bool_type;
                    (yyval.type) = a;
                }
    break;

  case 21:
#line 276 "p.y"
    {
                    typeDef a;
                    a.type = str_type;
                    (yyval.type) = a;
                }
    break;

  case 22:
#line 282 "p.y"
    {
                    typeDef a;
                    a.type = int_type;
                    (yyval.type) = a;
                }
    break;

  case 23:
#line 288 "p.y"
    {
                    typeDef a;
                    a.type = real_type;
                    (yyval.type) = a;
                }
    break;

  case 24:
#line 297 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);   nowType = "str";}
    break;

  case 25:
#line 298 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);   nowType = "int";}
    break;

  case 26:
#line 299 "p.y"
    {(yyval.input) = (yyvsp[(1) - (1)].input);   nowType = "real";}
    break;

  case 27:
#line 301 "p.y"
    {
                (yyval.input) = "true";   
                nowType = "bool";
                if (isInIf == 1) {
                    nowCommand = "ifeq ";
                    isInIf = 0;
                }
            }
    break;

  case 28:
#line 310 "p.y"
    {   
                (yyval.input) = "false";  
                nowType = "bool";
                if (isInIf == 1) {
                    nowCommand = "ifeq ";
                    isInIf = 0;
                }
            }
    break;

  case 29:
#line 321 "p.y"
    {

                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, (yyvsp[(4) - (6)].type), 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if ((yyvsp[(4) - (6)].type).type == int_type){
                            fprintf(out, "int %s = %s\n",nowIDName, (yyvsp[(6) - (6)].input));
                        }else if ((yyvsp[(4) - (6)].type).type == bool_type){
                            fprintf(out, "bool %s = %s\n",nowIDName, (yyvsp[(6) - (6)].input));
                        }
                    }
                    else {
                        printTab(NowScopeCount);
                        fprintf(out, "sipush %s\n", (yyvsp[(6) - (6)].input));
                        printTab(NowScopeCount);
                        fprintf(out, "istore %d\n", allLookUp(nowPointer, nowIDName));
                    }
                    
                }
    break;

  case 30:
#line 344 "p.y"
    {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    typeDef a = typeCheck((yyvsp[(4) - (4)].input));      
                    insert(nowPointer, nowIDName, a, 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if (a.type == int_type){
                            fprintf(out, "int %s = %s\n",nowIDName, (yyvsp[(4) - (4)].input));
                        }else if (a.type == bool_type){
                            fprintf(out, "bool %s = %s\n",nowIDName, (yyvsp[(4) - (4)].input));
                        }
                    }else{
                        printTab(NowScopeCount);
                        fprintf(out, "sipush %s\n", (yyvsp[(4) - (4)].input));
                        printTab(NowScopeCount);
                        fprintf(out, "istore %d\n", allLookUp(nowPointer, nowIDName));
                    }
                    
                }
    break;

  case 31:
#line 366 "p.y"
    {
                    Trace("var element generating...");
                    Trace(nowIDName);
                    insert(nowPointer, nowIDName, (yyvsp[(4) - (4)].type), 0, -1);
                    if (!isInBlock) {
                        printTab(NowScopeCount);
                        fprintf(out, "field static ");
                        if ((yyvsp[(4) - (4)].type).type == int_type){
                            fprintf(out, "int %s\n",nowIDName);
                        }else if ((yyvsp[(4) - (4)].type).type == bool_type){
                            fprintf(out, "bool %s\n",nowIDName);
                        }
                    }
                }
    break;

  case 33:
#line 387 "p.y"
    { isInBlock = 1; isInFunc = 1;}
    break;

  case 34:
#line 390 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                    NowScopeCount--;
                    printTab(NowScopeCount);
                    fprintf(out, "}\n");
                    isInFunc = 0;
                }
    break;

  case 35:
#line 402 "p.y"
    {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                }
    break;

  case 36:
#line 406 "p.y"
    {isInBlock = 1;isInFunc = 1;}
    break;

  case 37:
#line 409 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                    NowScopeCount--;
                    printTab(NowScopeCount);
                    fprintf(out, "}\n");
                    isInFunc = 0;
                }
    break;

  case 38:
#line 423 "p.y"
    {
                    nowPointer = createTable(nowPointer, tailPointer, nowIDName, linenum);
                    tailPointer = nowPointer;
                    Trace("inside function Table");
                    Trace(nowIDName);
                    for(int i =0; nowIDName[i] != '\0'; i++){
                        nowFuncName[i] = nowIDName[i];
                        nowFuncName[i + 1] = '\0';
                    }
                    isNew = 1;
                }
    break;

  case 39:
#line 435 "p.y"
    {
                    Trace("function return type set:");
                    Trace(t_name[(yyvsp[(8) - (8)].type).type]);
                    setReturnType(nowPointer, (yyvsp[(8) - (8)].type));
                    printTab(NowScopeCount);
                    fprintf(out, "method public static ");
                    if ((yyvsp[(8) - (8)].type).type == int_type){
                        fprintf(out, "int ");
                    }else if ((yyvsp[(8) - (8)].type).type == bool_type){
                        fprintf(out, "bool");
                    }
                    fprintf(out, "%s(", nowFuncName);
                    LT* funcT = findTable(nowPointer, nowFuncName);
                    if(funcT != NULL){
                        for(int i = 0; i < funcT->innerLink->t.tableSize; i++){
                            if(funcT->innerLink->t.id[i].type.type == int_type){
                                fprintf(out, "int");
                            }else if(funcT->innerLink->t.id[i].type.type == bool_type){
                                fprintf(out, "bool");
                            }
                            if(i + 1 < funcT->innerLink->t.tableSize){
                                fprintf(out, ", ");
                            }
                        }
                        fprintf(out, ")\n");
                        printTab(NowScopeCount);
                        fprintf(out, "max_stack 15\n");
                        printTab(NowScopeCount);
                        fprintf(out, "max_locals 15\n");
                        printTab(NowScopeCount);
                        fprintf(out, "{\n");
                        NowScopeCount++;
                    }
                    isNew = 0;
                }
    break;

  case 43:
#line 481 "p.y"
    {
                    insert(nowPointer->innerLink, nowIDName, (yyvsp[(3) - (3)].type), 0, -1); // function input 有const嗎
                    printf("insert success %s\n", nowIDName);
                }
    break;

  case 48:
#line 498 "p.y"
    {
                    isInBlock = 1;
                    nowPointer = createTable(nowPointer, tailPointer, "begin_block", linenum);
                    tailPointer = nowPointer;
                }
    break;

  case 49:
#line 504 "p.y"
    {
                    if (!outOfBlockCheck){
                        nowPointer = nowPointer->l;
                        Trace("out one block");
                    }
                    outOfBlockCheck = 0;
                }
    break;

  case 54:
#line 519 "p.y"
    {
                        for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                            nowIDName2[i] = (yyvsp[(1) - (1)].input)[i];
                            nowIDName2[i + 1] = '\0';
                        }
                    }
    break;

  case 55:
#line 526 "p.y"
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
                        
                        Symbol node = getNode(nowPointer, nowIDName2);
                        LT* getter = getNodesScope(nowPointer, nowIDName2);
                        if (!strcmp(getter->tableName, "main")) {
                            printTab(NowScopeCount);
                            fprintf(out, "putstatic ");
                            if (node.type.type == int_type){
                                fprintf(out, "int ");
                            }else if (node.type.type == bool_type){
                                fprintf(out, "bool ");
                            }
                            fprintf(out, "%s.%s\n", name, node.name);
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "istore %d\n", node.index);
                        }
                    }
    break;

  case 56:
#line 558 "p.y"
    {
                        exprChecker = 0;
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
                    }
    break;

  case 57:
#line 564 "p.y"
    {
                        (yyval.type) = (yyvsp[(3) - (3)].type);
                        if (exprChecker == 2){
                            int a = allLookUp(nowPointer, nowIDName);
                            //printf("%d\n", a);
                            if(a == -1){
                                yywarning("variable not exist");
                            }
                        }
                        
                        printTab(NowScopeCount);
                        if(isCalling == 1){
                            if(!strcmp(funcType, "int")){
                                fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
                            }else{

                            }
                            isCalling = 0;
                        }
                        else if(!strcmp(nowType,"str")){
                            fprintf(out, "invokevirtual void java.io.PrintStream.print(java.lang.String)\n");
                        }else{
                            fprintf(out, "invokevirtual void java.io.PrintStream.println(int)\n");
                        }
                    }
    break;

  case 58:
#line 590 "p.y"
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
                        printTab(NowScopeCount);
                        fprintf(out, "ireturn\n");

                    }
    break;

  case 59:
#line 608 "p.y"
    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "return\n");

                    }
    break;

  case 60:
#line 618 "p.y"
    {isInLoop = 1;}
    break;

  case 61:
#line 619 "p.y"
    {
                        if (!outOfBlockCheck){
                            outOfBlockCheck = 1;
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                    }
    break;

  case 62:
#line 626 "p.y"
    {
                        printTab(NowScopeCount);
                    fprintf(out, "getstatic java.io.PrintStream java.lang.System.out\n");
                        printTab(NowScopeCount);
                    fprintf(out, "invokevirtual void java.io.PrintStream.println()\n");
                }
    break;

  case 64:
#line 635 "p.y"
    {
                        fprintf(out, "Ltrue%d\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_0\n");
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lfalse%d\n", ifNow);
                        fprintf(out, "Ltrue%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_1\n");
                        fprintf(out, "Lfalse%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "ifne Lexit%d\n", ifNow);
                    }
    break;

  case 65:
#line 651 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "if_block", linenum);
                        tailPointer = nowPointer;
                        isInBlock = 1;
                        isInIf = 1;

                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                    }
    break;

  case 66:
#line 670 "p.y"
    {
                        if (isInIf == 0){
                            printTab(NowScopeCount);
                            fprintf(out, "%s ", nowCommand);
                        }
                        fprintf(out, "Lfalse%d\n", ifNow);
                    }
    break;

  case 67:
#line 677 "p.y"
    {
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lexit%d\n", ifNow);
                        fprintf(out, "Lfalse%d:\n", ifNow);
                    }
    break;

  case 69:
#line 684 "p.y"
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

  case 72:
#line 697 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        fprintf(out, "Lexit%d:\n", ifNow);
                        
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                    }
    break;

  case 73:
#line 713 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "loop_block", linenum);
                        tailPointer = nowPointer;
                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                        fprintf(out, "Lbegin%d:\n", ifNow);
                        isInBlock = 1;
                        isInIf = 1;
                        isInLoop = 1;
                        
                    }
    break;

  case 74:
#line 735 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lbegin%d\n", ifNow);
                        fprintf(out, "Lexit%d:\n", ifNow);
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                        isInLoop = 0;
                    }
    break;

  case 75:
#line 751 "p.y"
    {
                        nowPointer = createTable(nowPointer, tailPointer, "for_loop_block", linenum);
                        tailPointer = nowPointer;
                        isInBlock = 1;
                        if (ifCheck == 1){
                            ifNow = ifMax + 1;
                            ifMin = ifMax++;
                            ifCheck = 0;
                        }
                        else{
                            ifNow += 1;
                        }

                        if(ifNow > ifMax){
                            ifMax = ifNow;
                        }
                        isInBlock = 1;
                        isInIf = 1;
                        isNew = 1;
                    }
    break;

  case 76:
#line 772 "p.y"
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
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            //printf("%c\n", nowIDName[i]);
                            nowIDName3[i] = nowIDName[i];
                            nowIDName3[i + 1] = '\0';
                        }isNew = 0;
                        //insert(nowPointer, nowIDName, a, 0, -1);
                    }
    break;

  case 77:
#line 790 "p.y"
    {
                        typeDef a;
                        a.type = int_type;
                        if((yyvsp[(7) - (7)].type).type != a.type){
                            yywarning("loop lower range must be type of int");
                        }
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "putstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        
                    }
    break;

  case 78:
#line 808 "p.y"
    {
                        fprintf(out, "Lbegin%d:\n", ifNow);
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                    }
    break;

  case 79:
#line 821 "p.y"
    {
                        typeDef a;
                        a.type = int_type;
                        if((yyvsp[(12) - (12)].type).type != a.type){
                            yywarning("loop upper range must be type of int");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "isub\n");
                        if (isDecrease == 1){
                            printTab(NowScopeCount);
                            fprintf(out, "iflt ");
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "ifgt ");
                        }
                        fprintf(out, "Ltrue%d\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_0\n");
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lfalse%d\n", ifNow);
                        fprintf(out, "Ltrue%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "iconst_1\n");
                        fprintf(out, "Lfalse%d:\n", ifNow);
                        printTab(NowScopeCount);
                        fprintf(out, "ifne Lexit%d\n", ifNow);
                    }
    break;

  case 80:
#line 849 "p.y"
    {
                        if (!outOfBlockCheck){
                            nowPointer = nowPointer->l;
                            Trace("out one block");
                        }
                        outOfBlockCheck = 0;
                        Symbol gg = getNode(nowPointer, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "getstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "sipush 1\n");
                        if (isDecrease == 1){
                            printTab(NowScopeCount);
                            fprintf(out, "isub\n");
                        }else{
                            printTab(NowScopeCount);
                            fprintf(out, "iadd\n");
                        }
                        printTab(NowScopeCount);
                        fprintf(out, "putstatic ");
                        if(gg.type.type == int_type){
                            fprintf(out, "int ");
                        }else if(gg.type.type == bool_type){
                            fprintf(out, "bool ");
                        } 
                        fprintf(out, "%s.%s\n", name, nowIDName3);
                        printTab(NowScopeCount);
                        fprintf(out, "goto Lbegin%d\n", ifNow);
                        fprintf(out, "Lexit%d:\n", ifNow);
                        ifNow--;
                        if( ifNow == ifMin ){
                            ifCheck = 1;
                        }
                    }
    break;

  case 82:
#line 893 "p.y"
    {isDecrease = 1;}
    break;

  case 83:
#line 897 "p.y"
    {
                        //printf("%s ahufkadfs\n", nowIDName);
                        for(int i = 0; nowIDName[i] != '\0'; i++){
                            //printf("%c\n", nowIDName[i]);
                            nowFuncName2[i] = nowIDName[i];
                            nowFuncName2[i + 1] = '\0';
                        }
                        
                        //printf("%s\n", nowFuncName2);
                        LT* func_tab = findTable(tailPointer, nowFuncName2);
                        //printf("%s ---------------------\n", func_tab->tableName);
                        if(func_tab == NULL){
                            yywarning(strcat(strcat("no function with name ", nowFuncName2) ," exsit"));
                        }
                        typeDef a = tableReturnType(func_tab, nowFuncName2);
                        (yyval.type) = a;
                        //printf("%s\n", t_name[a.type]);
                        isCalling = 1;
                    }
    break;

  case 84:
#line 917 "p.y"
    {
                        //printf("start find %s\n", nowFuncName2);
                        LT* funcT = findTable(tailPointer, nowFuncName2);
                        printTab(NowScopeCount);
                        fprintf(out, "invokestatic ");
                        if(funcT != NULL){
                            if (funcT->innerLink->t.tableSize != functionCall_counter){
                                yywarning(strcat(strcat("not the correct form for function ", nowFuncName2), " "));
                            }
                            functionCall_counter = 0;
                            if(funcT->returnType.type == int_type){
                                fprintf(out, "int ");
                                funcType[0] = '\0';
                                strcat(funcType, "int");
                            }else if(funcT->returnType.type == bool_type){
                                fprintf(out, "bool ");
                                funcType[0] = '\0';
                                strcat(funcType, "int");
                            } 
                            fprintf(out, "%s.%s(", name, funcT->tableName);

                            for(int i = 0; i < funcT->innerLink->t.tableSize; i++){
                                if(funcT->innerLink->t.id[i].type.type == int_type){
                                    fprintf(out, "int");
                                }else if(funcT->innerLink->t.id[i].type.type == bool_type){
                                    fprintf(out, "bool");
                                }
                                if(i + 1 < funcT->innerLink->t.tableSize){
                                    fprintf(out, ", ");
                                }
                            }
                            fprintf(out, ")\n");
                        }
                    }
    break;

  case 87:
#line 956 "p.y"
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

  case 89:
#line 973 "p.y"
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

  case 90:
#line 986 "p.y"
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

  case 91:
#line 999 "p.y"
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

  case 92:
#line 1020 "p.y"
    {
                for(int i = 0; (yyvsp[(1) - (1)].input)[i] != '\0'; i++){
                    nowValue[i] = (yyvsp[(1) - (1)].input)[i];
                    nowValue[i + 1] = '\0';
                }
                (yyval.type) = typeCheck((yyvsp[(1) - (1)].input));  
                if (isNew == 0){
                    printTab(NowScopeCount);
                    if((yyval.type).type == int_type){
                        fprintf(out, "sipush %s\n", (yyvsp[(1) - (1)].input));  
                    }else if((yyval.type).type == bool_type){
                        if(strcmp((yyvsp[(1) - (1)].input) ,"true")){
                            fprintf(out, "iconst_1\n");
                        }else{
                            fprintf(out, "iconst_0\n");
                        }
                    }else if((yyval.type).type == str_type){
                        fprintf(out, "ldc \"%s\"\n", nowValue);
                    }
                }
            }
    break;

  case 93:
#line 1042 "p.y"
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
                printTab(NowScopeCount);
                fprintf(out, "iadd\n");
            }
    break;

  case 94:
#line 1058 "p.y"
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
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
            }
    break;

  case 95:
#line 1074 "p.y"
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
                printTab(NowScopeCount);
                fprintf(out, "imul\n");
            }
    break;

  case 96:
#line 1090 "p.y"
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
                printTab(NowScopeCount);
                fprintf(out, "idiv\n");
            }
    break;

  case 97:
#line 1106 "p.y"
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
                printTab(NowScopeCount);
                fprintf(out, "irem\n");
            }
    break;

  case 98:
#line 1126 "p.y"
    {
                exprChecker = 1;
                typeDef a = (yyvsp[(2) - (2)].type);
                typeDef b;
                b.type = str_type;
                if(a.type == b.type){
                    yywarning("can't plus minus in front of type string");
                }
                (yyval.type) = (yyvsp[(2) - (2)].type);
                printTab(NowScopeCount);
                fprintf(out, "ineg\n");
            }
    break;

  case 99:
#line 1138 "p.y"
    {(yyval.type) = (yyvsp[(2) - (3)].type);}
    break;

  case 100:
#line 1140 "p.y"
    {
                (yyval.type) = (yyvsp[(1) - (1)].type); 
                exprChecker = 2;  
                if((yyvsp[(1) - (1)].type).type == int_type){
                    nowType = "int";
                }else if((yyvsp[(1) - (1)].type).type == bool_type){
                    nowType = "bool";
                }else if((yyvsp[(1) - (1)].type).type == str_type){
                    nowType = "str";
                }
                //printTab(NowScopeCount); 
                //fprintf(out, "iload %d\n", allLookUp(tailPointer, nowIDName));
            }
    break;

  case 101:
#line 1153 "p.y"
    {(yyval.type) = (yyvsp[(1) - (1)].type);isCalling = 1;}
    break;

  case 102:
#line 1155 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around <=");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "iflt ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifge ");
                }
            }
    break;

  case 103:
#line 1174 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around <");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "ifle ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifgt ");
                }
                
            }
    break;

  case 104:
#line 1194 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around >=");
                }
                
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 1){
                    printTab(NowScopeCount);
                    fprintf(out, "ifge ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifit ");
                }
            }
    break;

  case 105:
#line 1214 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around >");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                if(isInLoop == 0){
                    printTab(NowScopeCount);
                    fprintf(out, "ifle ");
                }else{
                    printTab(NowScopeCount);
                    fprintf(out, "ifgt ");
                }
            }
    break;

  case 106:
#line 1233 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around EQUAL(=)");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                printTab(NowScopeCount);
                fprintf(out, "ifeq ");
            }
    break;

  case 107:
#line 1247 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != (yyvsp[(3) - (3)].type).type){
                    yywarning("not same type around EQUAL(=)");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "isub\n");
                printTab(NowScopeCount);
                fprintf(out, "ifne ");
            }
    break;

  case 108:
#line 1261 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != a.type || (yyvsp[(3) - (3)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "iand\n");
            }
    break;

  case 109:
#line 1273 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(1) - (3)].type).type != a.type || (yyvsp[(3) - (3)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "ior\n");
            }
    break;

  case 110:
#line 1285 "p.y"
    {
                exprChecker = 1;
                typeDef a;
                a.type = bool_type;
                if((yyvsp[(2) - (2)].type).type != a.type){
                    yywarning("not bool value inside bool_expr");
                }
                (yyval.type) = a;
                printTab(NowScopeCount);
                fprintf(out, "ixor\n");
            }
    break;


/* Line 1267 of yacc.c.  */
#line 3031 "y.tab.c"
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


#line 1297 "p.y"

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
    name = (char*)malloc(50);
    for(int i = 0; argv[argc - 1][i] != '\0'; i++){
        if(argv[argc - 1][i] == '.'){
            break;
        }
        name[i] = argv[argc - 1][i];
        name[i + 1] = '\0';
    }
    strcat(name, ".jasm");
    out = fopen(name, "w+");
    for(int i = 0; argv[argc - 1][i] != '\0'; i++){
        if(argv[argc - 1][i] == '.'){
            break;
        }
        name[i] = argv[argc - 1][i];
        name[i + 1] = '\0';
    }
    fprintf(out, "class %s\n{\n", name);
    nowIDName = (char*)malloc(50);
    funcType = (char*)malloc(50);
    nowIDName2 = (char*)malloc(50);
    nowIDName3 = (char*)malloc(50);
    nowFuncName = (char*)malloc(50);
    nowFuncName2 = (char*)malloc(50);
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



