/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_INCLUDE_H_INCLUDED
# define YY_YY_INCLUDE_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 5 "./lex/parser.y"

  #include "ast.h"
  
  extern void yyerror(Ast* ast, const char* s);

#line 55 "./include/.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PLUS = 258,                    /* PLUS  */
    MINUS = 259,                   /* MINUS  */
    STAR = 260,                    /* STAR  */
    SLASH = 261,                   /* SLASH  */
    PERCENT = 262,                 /* PERCENT  */
    EQUAL = 263,                   /* EQUAL  */
    NOTEQUAL = 264,                /* NOTEQUAL  */
    LESSTHAN = 265,                /* LESSTHAN  */
    GREATERTHAN = 266,             /* GREATERTHAN  */
    LESSTHANEQ = 267,              /* LESSTHANEQ  */
    GREATERTHANEQ = 268,           /* GREATERTHANEQ  */
    AND = 269,                     /* AND  */
    OR = 270,                      /* OR  */
    NOT = 271,                     /* NOT  */
    IDENTIFIER = 272,              /* IDENTIFIER  */
    STR = 273,                     /* STR  */
    COMMA = 274,                   /* COMMA  */
    CHAR = 275,                    /* CHAR  */
    BIN = 276,                     /* BIN  */
    HEX = 277,                     /* HEX  */
    DEC = 278,                     /* DEC  */
    TRUE = 279,                    /* TRUE  */
    FALSE = 280,                   /* FALSE  */
    IF = 281,                      /* IF  */
    THEN = 282,                    /* THEN  */
    ELSE = 283,                    /* ELSE  */
    LOOP = 284,                    /* LOOP  */
    WHILE = 285,                   /* WHILE  */
    UNTIL = 286,                   /* UNTIL  */
    DO = 287,                      /* DO  */
    BREAK = 288,                   /* BREAK  */
    END = 289,                     /* END  */
    WEND = 290,                    /* WEND  */
    SEMICOLON = 291,               /* SEMICOLON  */
    LPAREN = 292,                  /* LPAREN  */
    RPAREN = 293,                  /* RPAREN  */
    TYPEDEF = 294,                 /* TYPEDEF  */
    DIM = 295,                     /* DIM  */
    AS = 296,                      /* AS  */
    FUNCTION = 297,                /* FUNCTION  */
    ARRAY_COMMAS = 298             /* ARRAY_COMMAS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "./lex/parser.y"

  AstNode* node;

#line 119 "./include/.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (Ast* ast);


#endif /* !YY_YY_INCLUDE_H_INCLUDED  */
