/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./lex/parser.y"

  #include <stddef.h>

#line 75 "./src/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PLUS = 3,                       /* PLUS  */
  YYSYMBOL_MINUS = 4,                      /* MINUS  */
  YYSYMBOL_STAR = 5,                       /* STAR  */
  YYSYMBOL_SLASH = 6,                      /* SLASH  */
  YYSYMBOL_PERCENT = 7,                    /* PERCENT  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_NOTEQUAL = 9,                   /* NOTEQUAL  */
  YYSYMBOL_LESSTHAN = 10,                  /* LESSTHAN  */
  YYSYMBOL_GREATERTHAN = 11,               /* GREATERTHAN  */
  YYSYMBOL_LESSTHANEQ = 12,                /* LESSTHANEQ  */
  YYSYMBOL_GREATERTHANEQ = 13,             /* GREATERTHANEQ  */
  YYSYMBOL_AND = 14,                       /* AND  */
  YYSYMBOL_OR = 15,                        /* OR  */
  YYSYMBOL_NOT = 16,                       /* NOT  */
  YYSYMBOL_IDENTIFIER = 17,                /* IDENTIFIER  */
  YYSYMBOL_STR = 18,                       /* STR  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_CHAR = 20,                      /* CHAR  */
  YYSYMBOL_BIN = 21,                       /* BIN  */
  YYSYMBOL_HEX = 22,                       /* HEX  */
  YYSYMBOL_DEC = 23,                       /* DEC  */
  YYSYMBOL_TRUE = 24,                      /* TRUE  */
  YYSYMBOL_FALSE = 25,                     /* FALSE  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_THEN = 27,                      /* THEN  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_LOOP = 29,                      /* LOOP  */
  YYSYMBOL_WHILE = 30,                     /* WHILE  */
  YYSYMBOL_UNTIL = 31,                     /* UNTIL  */
  YYSYMBOL_DO = 32,                        /* DO  */
  YYSYMBOL_BREAK = 33,                     /* BREAK  */
  YYSYMBOL_END = 34,                       /* END  */
  YYSYMBOL_WEND = 35,                      /* WEND  */
  YYSYMBOL_SEMICOLON = 36,                 /* SEMICOLON  */
  YYSYMBOL_LPAREN = 37,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 38,                    /* RPAREN  */
  YYSYMBOL_TYPEDEF = 39,                   /* TYPEDEF  */
  YYSYMBOL_DIM = 40,                       /* DIM  */
  YYSYMBOL_AS = 41,                        /* AS  */
  YYSYMBOL_FUNCTION = 42,                  /* FUNCTION  */
  YYSYMBOL_ARRAY_COMMAS = 43,              /* ARRAY_COMMAS  */
  YYSYMBOL_YYACCEPT = 44,                  /* $accept  */
  YYSYMBOL_source = 45,                    /* source  */
  YYSYMBOL_sourceItem = 46,                /* sourceItem  */
  YYSYMBOL_funcBody = 47,                  /* funcBody  */
  YYSYMBOL_funcSignature = 48,             /* funcSignature  */
  YYSYMBOL_listArgDef = 49,                /* listArgDef  */
  YYSYMBOL_argDef = 50,                    /* argDef  */
  YYSYMBOL_optionalTypeRef = 51,           /* optionalTypeRef  */
  YYSYMBOL_typeRef = 52,                   /* typeRef  */
  YYSYMBOL_builtin = 53,                   /* builtin  */
  YYSYMBOL_custom = 54,                    /* custom  */
  YYSYMBOL_array = 55,                     /* array  */
  YYSYMBOL_statement = 56,                 /* statement  */
  YYSYMBOL_var = 57,                       /* var  */
  YYSYMBOL_listIdentifier = 58,            /* listIdentifier  */
  YYSYMBOL_if = 59,                        /* if  */
  YYSYMBOL_listStatement = 60,             /* listStatement  */
  YYSYMBOL_optionalElseStatement = 61,     /* optionalElseStatement  */
  YYSYMBOL_while = 62,                     /* while  */
  YYSYMBOL_do = 63,                        /* do  */
  YYSYMBOL_break = 64,                     /* break  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_expr = 66,                      /* expr  */
  YYSYMBOL_binary = 67,                    /* binary  */
  YYSYMBOL_unary = 68,                     /* unary  */
  YYSYMBOL_braces = 69,                    /* braces  */
  YYSYMBOL_callOrIndexer = 70,             /* callOrIndexer  */
  YYSYMBOL_optionalListExpr = 71,          /* optionalListExpr  */
  YYSYMBOL_listExpr = 72,                  /* listExpr  */
  YYSYMBOL_place = 73,                     /* place  */
  YYSYMBOL_literal = 74                    /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   316

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  44
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   298


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    76,    78,    82,    84,    85,    86,
      88,    90,    91,    95,    96,    97,    99,   101,   103,   107,
     108,   109,   110,   111,   112,   114,   116,   117,   119,   123,
     124,   126,   127,   129,   131,   132,   134,   136,   140,   141,
     142,   143,   144,   145,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   162,   163,
     164,   166,   168,   170,   171,   173,   174,   176,   178,   179,
     180,   181,   182,   183,   184
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PLUS", "MINUS",
  "STAR", "SLASH", "PERCENT", "EQUAL", "NOTEQUAL", "LESSTHAN",
  "GREATERTHAN", "LESSTHANEQ", "GREATERTHANEQ", "AND", "OR", "NOT",
  "IDENTIFIER", "STR", "COMMA", "CHAR", "BIN", "HEX", "DEC", "TRUE",
  "FALSE", "IF", "THEN", "ELSE", "LOOP", "WHILE", "UNTIL", "DO", "BREAK",
  "END", "WEND", "SEMICOLON", "LPAREN", "RPAREN", "TYPEDEF", "DIM", "AS",
  "FUNCTION", "ARRAY_COMMAS", "$accept", "source", "sourceItem",
  "funcBody", "funcSignature", "listArgDef", "argDef", "optionalTypeRef",
  "typeRef", "builtin", "custom", "array", "statement", "var",
  "listIdentifier", "if", "listStatement", "optionalElseStatement",
  "while", "do", "break", "expression", "expr", "binary", "unary",
  "braces", "callOrIndexer", "optionalListExpr", "listExpr", "place",
  "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-60)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -53,     3,   -53,   -13,   -53,   -31,     4,    -3,   164,   164,
     164,   -28,   -53,   -53,   -53,   -53,   -53,   -53,   -53,   164,
     164,     4,   -53,   164,     1,   -53,     4,   -53,   -53,   -15,
     -53,   -53,   -53,   -53,   199,   -53,   -53,   -53,   -53,   -53,
     -53,   -18,    -7,    13,   301,   301,   301,   164,   259,   107,
       9,   145,    21,     2,   -53,     0,   164,   164,   164,   164,
     164,    64,   164,   164,   164,   164,   164,   164,   164,   -53,
      -4,   -53,   -18,    -3,   284,     8,   -53,     4,   164,   164,
      12,   -14,   -53,     1,    -4,   -53,   301,   301,   301,   301,
     301,   164,   301,   301,   301,   301,   301,   301,   301,   301,
     -53,   -53,    19,   -53,   -53,   -53,   -53,   -53,   164,   -53,
      35,   212,   246,   -53,   164,   164,   -53,    19,   301,   -53,
     -53,     4,    30,   301,   301,     4,    39,   -53,   -53
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     0,     3,     0,    29,     7,     0,     0,
       0,    67,    70,    71,    73,    72,    74,    68,    69,     0,
       0,    29,    36,     0,     0,     4,    29,    19,    20,     0,
      21,    22,    23,    24,     0,    38,    39,    40,    41,    42,
      43,    11,     0,     8,    58,    59,    60,    64,     0,    29,
       0,     0,    26,     0,    30,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    10,    11,     7,    66,     0,    63,    29,     0,     0,
       0,     0,    61,     0,     0,     5,    45,    46,    47,    48,
      49,     0,    44,    51,    52,    53,    54,    55,    56,    57,
      17,    16,    12,    13,    14,    15,     6,     9,     0,    62,
      31,    45,    46,    33,     0,     0,    27,    25,    50,    18,
      65,     0,     0,    34,    35,    29,     0,    32,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -53,   -53,   -53,     5,   -53,    -6,   -11,   -53,
     -53,   -53,   -52,   -53,    -9,   -53,   -16,   -53,   -53,   -53,
     -53,   -53,    -8,   -53,   -53,   -53,   -53,   -53,   -33,   -53,
     -53
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     4,    25,     6,    42,    43,    71,   102,   103,
     104,   105,    26,    27,    53,    28,    29,   122,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    75,    76,    39,
      40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      44,    45,    46,     2,     5,    50,     7,     8,     9,    47,
      54,    48,    49,   100,    41,    51,   114,   115,    52,    55,
      10,    11,    12,    70,    13,    14,    15,    16,    17,    18,
      19,    72,    73,    80,    20,   101,    21,    22,    81,    74,
      83,    23,    85,    84,    24,     3,   109,   113,    86,    87,
      88,    89,    90,    92,    93,    94,    95,    96,    97,    98,
      99,   110,   119,   121,   126,   128,   106,     8,     9,   125,
     111,   112,    91,   117,   116,   120,     0,     0,   107,     0,
      10,    11,    12,   118,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      74,    23,     0,     0,     0,     0,   123,   124,     0,   127,
      78,    79,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    10,    11,    12,     0,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,    20,     0,    21,
      22,     0,     0,     0,    23,     0,     0,    24,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,     0,     0,     0,     0,     0,     0,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    82,    13,    14,    15,    16,    17,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    23,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,     0,     0,
       0,     0,     0,     0,     0,    69,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   -58,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,     0,     0,     0,     0,     0,
       0,     0,   -59,     0,     0,     0,    77,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
       0,     0,     0,   108,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68
};

static const yytype_int8 yycheck[] =
{
       8,     9,    10,     0,    17,    21,    37,     3,     4,    37,
      26,    19,    20,    17,    17,    23,    30,    31,    17,    34,
      16,    17,    18,    41,    20,    21,    22,    23,    24,    25,
      26,    38,    19,    49,    30,    39,    32,    33,    29,    47,
      19,    37,    42,    41,    40,    42,    38,    35,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    77,    43,    28,    34,    26,    72,     3,     4,   121,
      78,    79,     8,    84,    83,   108,    -1,    -1,    73,    -1,
      16,    17,    18,    91,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,    37,    -1,    -1,    -1,    -1,   114,   115,    -1,   125,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    -1,    20,    21,    22,
      23,    24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,
      33,    -1,    -1,    -1,    37,    -1,    -1,    40,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    38,    20,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    36,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    -1,    -1,    -1,    27,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    19,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    45,     0,    42,    46,    17,    48,    37,     3,     4,
      16,    17,    18,    20,    21,    22,    23,    24,    25,    26,
      30,    32,    33,    37,    40,    47,    56,    57,    59,    60,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    73,
      74,    17,    49,    50,    66,    66,    66,    37,    66,    66,
      60,    66,    17,    58,    60,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    36,
      41,    51,    38,    19,    66,    71,    72,    27,     3,     4,
      60,    29,    38,    19,    41,    42,    66,    66,    66,    66,
      66,     8,    66,    66,    66,    66,    66,    66,    66,    66,
      17,    39,    52,    53,    54,    55,    51,    49,    19,    38,
      60,    66,    66,    35,    30,    31,    58,    52,    66,    43,
      72,    28,    61,    66,    66,    56,    34,    60,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    44,    45,    45,    46,    47,    48,    49,    49,    49,
      50,    51,    51,    52,    52,    52,    53,    54,    55,    56,
      56,    56,    56,    56,    56,    57,    58,    58,    59,    60,
      60,    61,    61,    62,    63,    63,    64,    65,    66,    66,
      66,    66,    66,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    70,    71,    71,    72,    72,    73,    74,    74,
      74,    74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     5,     0,     1,     3,
       2,     0,     2,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     4,     1,     3,     7,     0,
       2,     0,     3,     4,     5,     5,     1,     2,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     3,     4,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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
        yyerror (ast, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, ast); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Ast* ast)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (ast);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, Ast* ast)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, ast);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, Ast* ast)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], ast);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, Ast* ast)
{
  YY_USE (yyvaluep);
  YY_USE (ast);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (Ast* ast)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (ast);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* source: %empty  */
#line 70 "./lex/parser.y"
        {{(yyval.node) = NULL;}}
#line 1264 "./src/parser.tab.c"
    break;

  case 3: /* source: source sourceItem  */
#line 71 "./lex/parser.y"
                        {{
        ast->head = ast_create_node(ast, "source", "", (yyvsp[-1].node), (yyvsp[0].node));
        (yyval.node) = ast->head;
    }}
#line 1273 "./src/parser.tab.c"
    break;

  case 4: /* sourceItem: FUNCTION funcSignature funcBody  */
#line 76 "./lex/parser.y"
                                            {{(yyval.node) = ast_create_node(ast, "sourceItem", "", (yyvsp[-2].node), (yyvsp[-1].node));}}
#line 1279 "./src/parser.tab.c"
    break;

  case 5: /* funcBody: listStatement END FUNCTION  */
#line 78 "./lex/parser.y"
                                     {{(yyval.node) = ast_create_node(ast, "funcBody", "", (yyvsp[-2].node), (yyvsp[-1].node));}}
#line 1285 "./src/parser.tab.c"
    break;

  case 6: /* funcSignature: IDENTIFIER LPAREN listArgDef RPAREN optionalTypeRef  */
#line 82 "./lex/parser.y"
                                                                   {{(yyval.node) = ast_create_node(ast, "funcSignature", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1291 "./src/parser.tab.c"
    break;

  case 7: /* listArgDef: %empty  */
#line 84 "./lex/parser.y"
             {{(yyval.node) = NULL;}}
#line 1297 "./src/parser.tab.c"
    break;

  case 8: /* listArgDef: argDef  */
#line 85 "./lex/parser.y"
             {{(yyval.node) = (yyvsp[0].node);}}
#line 1303 "./src/parser.tab.c"
    break;

  case 9: /* listArgDef: argDef COMMA listArgDef  */
#line 86 "./lex/parser.y"
                              {{(yyval.node) = ast_create_node(ast, "listArgDef", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1309 "./src/parser.tab.c"
    break;

  case 10: /* argDef: IDENTIFIER optionalTypeRef  */
#line 88 "./lex/parser.y"
                                   {{(yyval.node) = ast_create_node(ast, "argDef", "", (yyvsp[-1].node), (yyvsp[0].node));}}
#line 1315 "./src/parser.tab.c"
    break;

  case 11: /* optionalTypeRef: %empty  */
#line 90 "./lex/parser.y"
                 {{(yyval.node) = NULL;}}
#line 1321 "./src/parser.tab.c"
    break;

  case 12: /* optionalTypeRef: AS typeRef  */
#line 91 "./lex/parser.y"
                 {{(yyval.node) = (yyvsp[-1].node);}}
#line 1327 "./src/parser.tab.c"
    break;

  case 13: /* typeRef: builtin  */
#line 95 "./lex/parser.y"
                 {{(yyval.node) = (yyvsp[0].node);}}
#line 1333 "./src/parser.tab.c"
    break;

  case 14: /* typeRef: custom  */
#line 96 "./lex/parser.y"
             {{(yyval.node) = (yyvsp[0].node);}}
#line 1339 "./src/parser.tab.c"
    break;

  case 15: /* typeRef: array  */
#line 97 "./lex/parser.y"
            {{(yyval.node) = (yyvsp[0].node);}}
#line 1345 "./src/parser.tab.c"
    break;

  case 16: /* builtin: TYPEDEF  */
#line 99 "./lex/parser.y"
                 {{(yyval.node) = (yyvsp[0].node);}}
#line 1351 "./src/parser.tab.c"
    break;

  case 17: /* custom: IDENTIFIER  */
#line 101 "./lex/parser.y"
                   {{(yyval.node) = (yyvsp[0].node);}}
#line 1357 "./src/parser.tab.c"
    break;

  case 18: /* array: typeRef ARRAY_COMMAS  */
#line 103 "./lex/parser.y"
                            {{(yyval.node) = ast_create_node(ast, "array", (yyvsp[0].node)->value, (yyvsp[-1].node), NULL);}}
#line 1363 "./src/parser.tab.c"
    break;

  case 19: /* statement: var  */
#line 107 "./lex/parser.y"
               {{(yyval.node) =  (yyvsp[0].node);}}
#line 1369 "./src/parser.tab.c"
    break;

  case 20: /* statement: if  */
#line 108 "./lex/parser.y"
         {{(yyval.node) =  (yyvsp[0].node);}}
#line 1375 "./src/parser.tab.c"
    break;

  case 21: /* statement: while  */
#line 109 "./lex/parser.y"
            {{(yyval.node) =  (yyvsp[0].node);}}
#line 1381 "./src/parser.tab.c"
    break;

  case 22: /* statement: do  */
#line 110 "./lex/parser.y"
         {{(yyval.node) =  (yyvsp[0].node);}}
#line 1387 "./src/parser.tab.c"
    break;

  case 23: /* statement: break  */
#line 111 "./lex/parser.y"
            {{(yyval.node) =  (yyvsp[0].node);}}
#line 1393 "./src/parser.tab.c"
    break;

  case 24: /* statement: expression  */
#line 112 "./lex/parser.y"
                 {{(yyval.node) =  (yyvsp[0].node);}}
#line 1399 "./src/parser.tab.c"
    break;

  case 25: /* var: DIM listIdentifier AS typeRef  */
#line 114 "./lex/parser.y"
                                   {{(yyval.node) = ast_create_node(ast, "var", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1405 "./src/parser.tab.c"
    break;

  case 26: /* listIdentifier: IDENTIFIER  */
#line 116 "./lex/parser.y"
                           {{(yyval.node) = ast_create_node(ast, "declaredVar", "", (yyvsp[0].node), NULL);}}
#line 1411 "./src/parser.tab.c"
    break;

  case 27: /* listIdentifier: IDENTIFIER COMMA listIdentifier  */
#line 117 "./lex/parser.y"
                                      {{(yyval.node) = ast_create_node(ast, "listIdentifier", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1417 "./src/parser.tab.c"
    break;

  case 28: /* if: IF expr THEN listStatement optionalElseStatement END IF  */
#line 119 "./lex/parser.y"
                                                            {{
    (yyval.node) = ast_create_node(ast, "if", "", (yyvsp[-5].node), ast_create_node(ast, "ifStatements", "", (yyvsp[-3].node), (yyvsp[-2].node)));
  }}
#line 1425 "./src/parser.tab.c"
    break;

  case 29: /* listStatement: %empty  */
#line 123 "./lex/parser.y"
               {{(yyval.node) = NULL;}}
#line 1431 "./src/parser.tab.c"
    break;

  case 30: /* listStatement: statement listStatement  */
#line 124 "./lex/parser.y"
                              {{(yyval.node) = ast_create_node(ast, "listStatement", "", (yyvsp[-1].node), (yyvsp[0].node));}}
#line 1437 "./src/parser.tab.c"
    break;

  case 31: /* optionalElseStatement: %empty  */
#line 126 "./lex/parser.y"
                       {{(yyval.node) = NULL;}}
#line 1443 "./src/parser.tab.c"
    break;

  case 32: /* optionalElseStatement: ELSE statement listStatement  */
#line 127 "./lex/parser.y"
                                   {{(yyval.node) = ast_create_node(ast, "else", "", (yyvsp[-1].node), (yyvsp[0].node));}}
#line 1449 "./src/parser.tab.c"
    break;

  case 33: /* while: WHILE expr listStatement WEND  */
#line 129 "./lex/parser.y"
                                     {{(yyval.node) = ast_create_node(ast, "while", "", (yyvsp[-2].node), (yyvsp[-1].node));}}
#line 1455 "./src/parser.tab.c"
    break;

  case 34: /* do: DO listStatement LOOP WHILE expr  */
#line 131 "./lex/parser.y"
                                     {{(yyval.node) = ast_create_node(ast, "dowhile", "", (yyvsp[-3].node), (yyvsp[0].node));}}
#line 1461 "./src/parser.tab.c"
    break;

  case 35: /* do: DO listStatement LOOP UNTIL expr  */
#line 132 "./lex/parser.y"
                                     {{(yyval.node) = ast_create_node(ast, "dountil", "", (yyvsp[-3].node), (yyvsp[0].node));}}
#line 1467 "./src/parser.tab.c"
    break;

  case 36: /* break: BREAK  */
#line 134 "./lex/parser.y"
             {{(yyval.node) = ast_create_node(ast, "break", "", NULL, NULL);}}
#line 1473 "./src/parser.tab.c"
    break;

  case 37: /* expression: expr SEMICOLON  */
#line 136 "./lex/parser.y"
                           {{(yyval.node) = (yyvsp[-1].node);}}
#line 1479 "./src/parser.tab.c"
    break;

  case 38: /* expr: binary  */
#line 140 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1485 "./src/parser.tab.c"
    break;

  case 39: /* expr: unary  */
#line 141 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1491 "./src/parser.tab.c"
    break;

  case 40: /* expr: braces  */
#line 142 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1497 "./src/parser.tab.c"
    break;

  case 41: /* expr: callOrIndexer  */
#line 143 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1503 "./src/parser.tab.c"
    break;

  case 42: /* expr: place  */
#line 144 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1509 "./src/parser.tab.c"
    break;

  case 43: /* expr: literal  */
#line 145 "./lex/parser.y"
                     {{(yyval.node) = (yyvsp[0].node);}}
#line 1515 "./src/parser.tab.c"
    break;

  case 44: /* binary: expr EQUAL expr  */
#line 147 "./lex/parser.y"
                        {{(yyval.node) = ast_create_node(ast, "ASSIGNMENT", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1521 "./src/parser.tab.c"
    break;

  case 45: /* binary: expr PLUS expr  */
#line 148 "./lex/parser.y"
                     {{(yyval.node) = ast_create_node(ast, "PLUS", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1527 "./src/parser.tab.c"
    break;

  case 46: /* binary: expr MINUS expr  */
#line 149 "./lex/parser.y"
                      {{(yyval.node) = ast_create_node(ast, "MINUS", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1533 "./src/parser.tab.c"
    break;

  case 47: /* binary: expr STAR expr  */
#line 150 "./lex/parser.y"
                     {{(yyval.node) = ast_create_node(ast, "STAR", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1539 "./src/parser.tab.c"
    break;

  case 48: /* binary: expr SLASH expr  */
#line 151 "./lex/parser.y"
                      {{(yyval.node) = ast_create_node(ast, "SLASH", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1545 "./src/parser.tab.c"
    break;

  case 49: /* binary: expr PERCENT expr  */
#line 152 "./lex/parser.y"
                        {{(yyval.node) = ast_create_node(ast, "PERCENT", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1551 "./src/parser.tab.c"
    break;

  case 50: /* binary: expr EQUAL EQUAL expr  */
#line 153 "./lex/parser.y"
                            {{(yyval.node) = ast_create_node(ast, "EQUALITY", "", (yyvsp[-3].node), (yyvsp[0].node));}}
#line 1557 "./src/parser.tab.c"
    break;

  case 51: /* binary: expr NOTEQUAL expr  */
#line 154 "./lex/parser.y"
                         {{(yyval.node) = ast_create_node(ast, "NOTEQUAL", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1563 "./src/parser.tab.c"
    break;

  case 52: /* binary: expr LESSTHAN expr  */
#line 155 "./lex/parser.y"
                         {{(yyval.node) = ast_create_node(ast, "LESSTHAN", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1569 "./src/parser.tab.c"
    break;

  case 53: /* binary: expr GREATERTHAN expr  */
#line 156 "./lex/parser.y"
                            {{(yyval.node) = ast_create_node(ast, "GREATERTHAN", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1575 "./src/parser.tab.c"
    break;

  case 54: /* binary: expr LESSTHANEQ expr  */
#line 157 "./lex/parser.y"
                           {{(yyval.node) = ast_create_node(ast, "LESSTHANEQ", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1581 "./src/parser.tab.c"
    break;

  case 55: /* binary: expr GREATERTHANEQ expr  */
#line 158 "./lex/parser.y"
                              {{(yyval.node) = ast_create_node(ast, "GREATERTHANEQ", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1587 "./src/parser.tab.c"
    break;

  case 56: /* binary: expr AND expr  */
#line 159 "./lex/parser.y"
                    {{(yyval.node) = ast_create_node(ast, "AND", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1593 "./src/parser.tab.c"
    break;

  case 57: /* binary: expr OR expr  */
#line 160 "./lex/parser.y"
                   {{(yyval.node) = ast_create_node(ast, "OR", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1599 "./src/parser.tab.c"
    break;

  case 58: /* unary: PLUS expr  */
#line 162 "./lex/parser.y"
                 {{(yyval.node) = ast_create_node(ast, "PLUS", "", (yyvsp[0].node), NULL);}}
#line 1605 "./src/parser.tab.c"
    break;

  case 59: /* unary: MINUS expr  */
#line 163 "./lex/parser.y"
                 {{(yyval.node) = ast_create_node(ast, "MINUS", "", (yyvsp[0].node), NULL);}}
#line 1611 "./src/parser.tab.c"
    break;

  case 60: /* unary: NOT expr  */
#line 164 "./lex/parser.y"
               {{(yyval.node) = ast_create_node(ast, "NOT", "", (yyvsp[0].node), NULL);}}
#line 1617 "./src/parser.tab.c"
    break;

  case 61: /* braces: LPAREN expr RPAREN  */
#line 166 "./lex/parser.y"
                            {{(yyval.node) = ast_create_node(ast, "braces", "", (yyvsp[-1].node), NULL);}}
#line 1623 "./src/parser.tab.c"
    break;

  case 62: /* callOrIndexer: IDENTIFIER LPAREN optionalListExpr RPAREN  */
#line 168 "./lex/parser.y"
                                                          {{(yyval.node) = ast_create_node(ast, "CALLORINDEXER", "", (yyvsp[-3].node), (yyvsp[-1].node));}}
#line 1629 "./src/parser.tab.c"
    break;

  case 63: /* optionalListExpr: listExpr  */
#line 170 "./lex/parser.y"
                            {{(yyval.node) = ast_create_node(ast, "optionalListExpr", "", (yyvsp[0].node), NULL);}}
#line 1635 "./src/parser.tab.c"
    break;

  case 64: /* optionalListExpr: %empty  */
#line 171 "./lex/parser.y"
      {{(yyval.node) = ast_create_node(ast, "optionalListExpr", "", NULL, NULL);}}
#line 1641 "./src/parser.tab.c"
    break;

  case 65: /* listExpr: expr COMMA listExpr  */
#line 173 "./lex/parser.y"
                              {{(yyval.node) = ast_create_node(ast, "listExpr", "", (yyvsp[-2].node), (yyvsp[0].node));}}
#line 1647 "./src/parser.tab.c"
    break;

  case 66: /* listExpr: expr  */
#line 174 "./lex/parser.y"
           {{(yyval.node) = ast_create_node(ast, "listExpr", "", (yyvsp[0].node), NULL);}}
#line 1653 "./src/parser.tab.c"
    break;

  case 67: /* place: IDENTIFIER  */
#line 176 "./lex/parser.y"
                  {{(yyval.node) = (yyvsp[0].node);}}
#line 1659 "./src/parser.tab.c"
    break;

  case 68: /* literal: TRUE  */
#line 178 "./lex/parser.y"
              {{(yyval.node) = (yyvsp[0].node);}}
#line 1665 "./src/parser.tab.c"
    break;

  case 69: /* literal: FALSE  */
#line 179 "./lex/parser.y"
            {{(yyval.node) = (yyvsp[0].node);}}
#line 1671 "./src/parser.tab.c"
    break;

  case 70: /* literal: STR  */
#line 180 "./lex/parser.y"
          {{(yyval.node) = (yyvsp[0].node);}}
#line 1677 "./src/parser.tab.c"
    break;

  case 71: /* literal: CHAR  */
#line 181 "./lex/parser.y"
           {{(yyval.node) = (yyvsp[0].node);}}
#line 1683 "./src/parser.tab.c"
    break;

  case 72: /* literal: HEX  */
#line 182 "./lex/parser.y"
          {{(yyval.node) = (yyvsp[0].node);}}
#line 1689 "./src/parser.tab.c"
    break;

  case 73: /* literal: BIN  */
#line 183 "./lex/parser.y"
          {{(yyval.node) = (yyvsp[0].node);}}
#line 1695 "./src/parser.tab.c"
    break;

  case 74: /* literal: DEC  */
#line 184 "./lex/parser.y"
          {{(yyval.node) = (yyvsp[0].node);}}
#line 1701 "./src/parser.tab.c"
    break;


#line 1705 "./src/parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (ast, YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, ast);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (ast, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, ast);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 185 "./lex/parser.y"

