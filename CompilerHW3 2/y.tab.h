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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 76 "p.y"
{
    typeDef type;
    char* input;
}
/* Line 1529 of yacc.c.  */
#line 174 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

