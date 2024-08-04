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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 49 "p.y"
{
    typeDef type;
    char* input;
}
/* Line 1529 of yacc.c.  */
#line 178 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

