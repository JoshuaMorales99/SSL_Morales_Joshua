
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "BNF.y"


    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>

    int yylex();
    int yyerror (char *);
    int yywrap(){
        return(1);
    }



/* Line 189 of yacc.c  */
#line 89 "BNF.tab.c"

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CONSTANTE_OCTAL = 258,
     CONSTANTE_DECIMAL = 259,
     CONSTANTE_HEXADECIMAL = 260,
     CONSTANTE_REAL = 261,
     CONSTANTE_CARACTER = 262,
     OR = 263,
     AND = 264,
     IGUALIGUAL = 265,
     DIFERENTE = 266,
     MAYORIGUAL = 267,
     MENORIGUAL = 268,
     MASIGUAL = 269,
     MENOSIGUAL = 270,
     PORIGUAL = 271,
     DIVISIONGUAL = 272,
     MASMAS = 273,
     MENOSMENOS = 274,
     FLECHA = 275,
     AUTO = 276,
     TYPEDEF = 277,
     STATIC = 278,
     REGISTER = 279,
     EXTERN = 280,
     ENUM = 281,
     SIZEOF = 282,
     UNION = 283,
     STRUCT = 284,
     GOTO = 285,
     RETURN = 286,
     CONTINUE = 287,
     BREAK = 288,
     VOLATILE = 289,
     CONST = 290,
     WHILE = 291,
     DO = 292,
     FOR = 293,
     IF = 294,
     ELSE = 295,
     SWITCH = 296,
     CASE = 297,
     DEFAULT = 298,
     VOID = 299,
     CHAR = 300,
     DOUBLE = 301,
     FLOAT = 302,
     INT = 303,
     LONG = 304,
     SHORT = 305,
     SIGNED = 306,
     UNSIGNED = 307,
     IDENTIFICADOR = 308,
     LITERAL_CADENA = 309,
     COMENTARIO_UNA_LINEA = 310,
     COMENTARIO_VARIAS_LINEAS = 311
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 16 "BNF.y"

    int ival;
    float fval;
    char * cadena;



/* Line 214 of yacc.c  */
#line 189 "BNF.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 201 "BNF.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  125
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   832

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  78
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNRULES -- Number of states.  */
#define YYNSTATES  258

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   311

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    70,     2,     2,     2,    66,    69,     2,
      67,    68,    64,    62,    74,    63,    73,    65,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    77,
      60,    57,    61,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    71,     2,    72,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    75,     2,    76,     2,     2,     2,     2,
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
      55,    56
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    15,    17,    19,
      21,    23,    25,    27,    33,    35,    39,    41,    45,    47,
      51,    55,    57,    61,    65,    69,    73,    75,    79,    83,
      85,    89,    93,    97,    99,   102,   105,   108,   113,   116,
     118,   120,   122,   124,   126,   128,   133,   138,   142,   146,
     150,   153,   156,   158,   162,   164,   166,   168,   172,   174,
     176,   178,   180,   182,   184,   189,   193,   197,   200,   202,
     205,   208,   210,   213,   215,   218,   220,   223,   225,   227,
     231,   233,   236,   238,   240,   242,   244,   246,   248,   250,
     252,   254,   256,   258,   260,   262,   264,   266,   268,   270,
     272,   278,   283,   286,   288,   290,   292,   295,   299,   302,
     304,   307,   309,   311,   315,   318,   320,   323,   325,   329,
     332,   334,   337,   339,   343,   348,   352,   355,   357,   360,
     362,   370,   376,   382,   392,   399,   405,   408,   414,   422,
     428,   434,   439,   444,   449,   453,   457,   461,   464,   467,
     471,   474,   477,   479,   481,   483,   485,   487
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      95,     0,    -1,    55,    -1,    56,    -1,    81,    -1,    83,
      -1,    90,    82,    81,    -1,    57,    -1,    14,    -1,    15,
      -1,    16,    -1,    17,    -1,    84,    -1,    84,    58,    80,
      59,    83,    -1,    85,    -1,    85,     8,    84,    -1,    86,
      -1,    86,     9,    85,    -1,    87,    -1,    87,    10,    86,
      -1,    87,    11,    86,    -1,    88,    -1,    88,    12,    87,
      -1,    88,    13,    87,    -1,    88,    60,    87,    -1,    88,
      61,    87,    -1,    89,    -1,    89,    62,    88,    -1,    89,
      63,    88,    -1,    90,    -1,    90,    64,    89,    -1,    90,
      65,    89,    -1,    90,    66,    89,    -1,    92,    -1,    18,
      90,    -1,    19,    90,    -1,    91,    90,    -1,    27,    67,
     103,    68,    -1,    27,    90,    -1,    69,    -1,    64,    -1,
      62,    -1,    63,    -1,    70,    -1,    94,    -1,    92,    71,
      80,    72,    -1,    92,    67,    93,    68,    -1,    92,    67,
      68,    -1,    92,    73,    53,    -1,    92,    20,    53,    -1,
      92,    18,    -1,    92,    19,    -1,    81,    -1,    81,    74,
      93,    -1,    53,    -1,   122,    -1,    54,    -1,    67,    80,
      68,    -1,    96,    -1,   116,    -1,   117,    -1,   119,    -1,
     121,    -1,    79,    -1,    75,    97,   115,    76,    -1,    75,
      97,    76,    -1,    75,   115,    76,    -1,    75,    76,    -1,
      98,    -1,    98,    97,    -1,    99,   100,    -1,    99,    -1,
     102,    99,    -1,   102,    -1,   103,    99,    -1,   103,    -1,
     104,    99,    -1,   104,    -1,   101,    -1,   101,    74,   100,
      -1,   111,    -1,   111,    81,    -1,    22,    -1,    23,    -1,
      21,    -1,    24,    -1,    25,    -1,    44,    -1,    45,    -1,
      50,    -1,    48,    -1,    49,    -1,    47,    -1,    46,    -1,
      51,    -1,    52,    -1,   105,    -1,    53,    -1,    35,    -1,
      34,    -1,   106,    53,    75,   107,    76,    -1,   106,    75,
     107,    76,    -1,   106,    53,    -1,    29,    -1,    28,    -1,
     108,    -1,   108,   107,    -1,   109,   110,    77,    -1,   103,
     109,    -1,   103,    -1,   104,   109,    -1,   104,    -1,   111,
      -1,   110,    74,   111,    -1,   112,   114,    -1,   114,    -1,
      64,   113,    -1,    64,    -1,    64,   113,   112,    -1,    64,
     112,    -1,   104,    -1,   104,   113,    -1,    53,    -1,    67,
     111,    68,    -1,   114,    71,   122,    72,    -1,   114,    71,
      72,    -1,   115,    95,    -1,    95,    -1,    80,    77,    -1,
      77,    -1,    39,    67,    80,    68,    95,    40,    95,    -1,
      39,    67,    80,    68,    95,    -1,    41,    67,    80,    68,
     118,    -1,    75,    42,   122,    59,    95,    43,    59,    95,
      76,    -1,    75,    42,   122,    59,    95,    76,    -1,    75,
      43,    59,    95,    76,    -1,    75,    76,    -1,    36,    67,
      80,    68,    95,    -1,    37,    95,    36,    67,    80,    68,
      77,    -1,    38,    67,   120,    68,    95,    -1,    80,    77,
      80,    77,    80,    -1,    77,    80,    77,    80,    -1,    80,
      77,    77,    80,    -1,    80,    77,    80,    77,    -1,    77,
      77,    80,    -1,    80,    77,    77,    -1,    77,    77,    77,
      -1,    33,    77,    -1,    32,    77,    -1,    31,    80,    77,
      -1,    31,    77,    -1,    30,    77,    -1,   123,    -1,     7,
      -1,     6,    -1,     3,    -1,     4,    -1,     5,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    48,    48,    49,    52,    55,    56,    59,    60,    61,
      62,    63,    66,    67,    70,    71,    74,    75,    78,    79,
      80,    83,    84,    85,    86,    87,    90,    91,    92,    95,
      96,    97,    98,   101,   102,   103,   104,   105,   106,   109,
     110,   111,   112,   113,   116,   117,   118,   119,   120,   121,
     122,   123,   126,   127,   130,   131,   132,   133,   136,   137,
     138,   139,   140,   141,   144,   145,   146,   147,   150,   151,
     154,   155,   158,   159,   160,   161,   162,   163,   166,   167,
     170,   171,   174,   175,   176,   177,   178,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   194,   195,
     198,   199,   200,   203,   204,   207,   208,   211,   214,   215,
     216,   217,   220,   221,   224,   225,   228,   229,   230,   231,
     234,   235,   238,   239,   240,   241,   244,   245,   248,   249,
     252,   253,   254,   257,   258,   259,   260,   263,   264,   265,
     268,   269,   270,   271,   272,   273,   274,   277,   278,   279,
     280,   281,   284,   285,   286,   289,   290,   291
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONSTANTE_OCTAL", "CONSTANTE_DECIMAL",
  "CONSTANTE_HEXADECIMAL", "CONSTANTE_REAL", "CONSTANTE_CARACTER", "OR",
  "AND", "IGUALIGUAL", "DIFERENTE", "MAYORIGUAL", "MENORIGUAL", "MASIGUAL",
  "MENOSIGUAL", "PORIGUAL", "DIVISIONGUAL", "MASMAS", "MENOSMENOS",
  "FLECHA", "AUTO", "TYPEDEF", "STATIC", "REGISTER", "EXTERN", "ENUM",
  "SIZEOF", "UNION", "STRUCT", "GOTO", "RETURN", "CONTINUE", "BREAK",
  "VOLATILE", "CONST", "WHILE", "DO", "FOR", "IF", "ELSE", "SWITCH",
  "CASE", "DEFAULT", "VOID", "CHAR", "DOUBLE", "FLOAT", "INT", "LONG",
  "SHORT", "SIGNED", "UNSIGNED", "IDENTIFICADOR", "LITERAL_CADENA",
  "COMENTARIO_UNA_LINEA", "COMENTARIO_VARIAS_LINEAS", "'='", "'?'", "':'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'('", "')'", "'&'",
  "'!'", "'['", "']'", "'.'", "','", "'{'", "'}'", "';'", "$accept", "noC",
  "expresion", "expAsignacion", "operAsignacion", "expCondicional",
  "expOr", "expAnd", "expIgualdad", "expRelacional", "expAditiva",
  "expMultiplicativa", "expUnaria", "operUnario", "expSufijo",
  "listaArgumentos", "expPrimaria", "sentencia", "sentCompuesta",
  "listaDeclaraciones", "declaracion", "espDeclaracion",
  "listaDeclaradores", "declarador", "espAlmacenamiento", "espTipo",
  "calificadorTipo", "espStructUnion", "structUnion", "listaStruct",
  "declaracionStruct", "listaCalificadores", "declaradoresStruct", "decla",
  "puntero", "listaCalificadoresTipo", "declaradorDirecto",
  "listaSentencias", "sentExpresion", "sentSeleccion", "sentSwitch",
  "sentIteracion", "cuerpoFor", "sentSalto", "constante",
  "constanteEntera", 0
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
     305,   306,   307,   308,   309,   310,   311,    61,    63,    58,
      60,    62,    43,    45,    42,    47,    37,    40,    41,    38,
      33,    91,    93,    46,    44,   123,   125,    59
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    78,    79,    79,    80,    81,    81,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    94,    94,    94,    94,    95,    95,
      95,    95,    95,    95,    96,    96,    96,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   106,   106,   107,   107,   108,   109,   109,
     109,   109,   110,   110,   111,   111,   112,   112,   112,   112,
     113,   113,   114,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   117,   118,   118,   118,   118,   119,   119,   119,
     120,   120,   120,   120,   120,   120,   120,   121,   121,   121,
     121,   121,   122,   122,   122,   123,   123,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     5,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     4,     2,     1,
       1,     1,     1,     1,     1,     4,     4,     3,     3,     3,
       2,     2,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     4,     3,     3,     2,     1,     2,
       2,     1,     2,     1,     2,     1,     2,     1,     1,     3,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     4,     2,     1,     1,     1,     2,     3,     2,     1,
       2,     1,     1,     3,     2,     1,     2,     1,     3,     2,
       1,     2,     1,     3,     4,     3,     2,     1,     2,     1,
       7,     5,     5,     9,     6,     5,     2,     5,     7,     5,
       5,     4,     4,     4,     3,     3,     3,     2,     2,     3,
       2,     2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   155,   156,   157,   154,   153,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    54,    56,
       2,     3,    41,    42,    40,     0,    39,    43,     0,   129,
      63,     0,     4,     5,    12,    14,    16,    18,    21,    26,
      29,     0,    33,    44,     0,    58,    59,    60,    61,    62,
      55,   152,    34,    35,     0,    38,   151,   150,     0,   148,
     147,     0,     0,     0,     0,     0,     0,    84,    82,    83,
      85,    86,   104,   103,    99,    98,    87,    88,    93,    92,
      90,    91,    89,    94,    95,    97,    67,   127,     0,    68,
      71,    73,    75,    77,    96,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,    11,     7,     0,     0,     0,     0,    36,    50,
      51,     0,     0,     0,     0,     1,     0,   149,     0,     0,
       0,     0,     0,     0,     0,    57,    65,     0,    97,    69,
     122,   117,     0,    70,    78,    80,     0,   115,    72,    74,
      76,   102,     0,    66,   126,     0,    15,    29,    17,    19,
      20,    22,    23,    24,    25,    27,    28,    30,    31,    32,
       6,    49,    47,    52,     0,     0,    48,    37,     0,     0,
       0,     0,     0,     0,     0,     0,    64,   120,   119,   116,
       0,     0,    81,   114,     0,     0,   109,   111,     0,   105,
       0,     0,     0,    46,    45,   137,     0,   146,   144,     0,
     145,     0,   139,   131,     0,   132,   121,   118,   123,    79,
     125,     0,     0,   108,   110,   101,   106,     0,   112,    13,
      53,     0,   141,   142,   143,     0,     0,     0,   136,   124,
     100,     0,   107,   138,   140,   130,     0,     0,   113,     0,
       0,     0,   135,     0,   134,     0,     0,   133
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    30,    31,    32,   117,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,   174,    43,    87,    45,    88,
      89,    90,   143,   144,    91,    92,    93,    94,    95,   198,
     199,   200,   227,   145,   146,   189,   147,    96,    46,    47,
     215,    48,   132,    49,    50,    51
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -193
static const yytype_int16 yypact[] =
{
     451,  -193,  -193,  -193,  -193,  -193,   596,   596,   649,   -66,
      16,   -24,    -3,   -10,   451,    10,    17,    28,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,   596,  -193,  -193,   235,  -193,
    -193,    34,  -193,  -193,    55,    60,   127,    30,     5,   -15,
     165,   596,   146,  -193,   143,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,   703,  -193,  -193,  -193,    72,  -193,
    -193,   596,   120,   141,   596,   596,    90,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,   628,  -193,  -193,   289,   753,
       8,   753,   753,   753,  -193,   -29,   343,  -193,   596,   596,
     596,   596,   596,   596,   596,   596,   596,   596,   596,  -193,
    -193,  -193,  -193,  -193,   596,   596,   596,   596,  -193,  -193,
    -193,   108,   123,   596,   109,  -193,    95,  -193,    99,   102,
     490,    97,   104,   107,   121,  -193,  -193,   397,  -193,  -193,
    -193,     3,     8,  -193,   114,   596,    -4,   125,  -193,  -193,
    -193,   122,   779,  -193,  -193,   139,  -193,    33,  -193,  -193,
    -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,  -193,
    -193,  -193,  -193,   132,   131,   135,  -193,  -193,   451,   596,
     528,   137,   558,   451,   451,   134,  -193,    53,  -193,   148,
     147,     8,  -193,   125,    22,   779,   779,   779,   140,   779,
       8,   596,   596,  -193,  -193,  -193,   152,  -193,  -193,   596,
     596,   144,  -193,   183,   -12,  -193,  -193,  -193,  -193,  -193,
    -193,   154,   151,  -193,  -193,  -193,  -193,    -1,  -193,  -193,
    -193,   155,  -193,  -193,   596,   451,   128,   169,  -193,  -193,
    -193,     8,  -193,  -193,  -193,  -193,   174,   451,  -193,   451,
     158,   -37,  -193,   177,  -193,   451,   161,  -193
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -193,  -193,    -9,  -112,  -193,    23,   145,   150,   -20,    19,
     -16,     4,     1,  -193,  -193,    41,  -193,     0,  -193,   156,
    -193,    47,    57,  -193,  -193,   -42,  -137,  -193,  -193,  -163,
    -193,   -45,  -193,  -129,  -138,    59,   105,   164,  -193,  -193,
    -193,  -193,  -193,  -193,  -192,  -193
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -55
static const yytype_int16 yytable[] =
{
      44,    58,   221,   188,   187,   170,   253,    52,    53,    55,
     173,    56,   126,   190,    62,   197,    66,   103,   104,     1,
       2,     3,     4,     5,   151,     1,     2,     3,     4,     5,
     236,   237,   222,   192,     6,     7,   226,    74,    75,   254,
     101,   102,   118,     8,   246,    66,   152,   107,   108,   140,
     187,   217,   128,    59,   131,   133,   134,    61,   197,   197,
     197,   140,   197,   142,   238,   105,   106,   141,    99,    18,
      19,   228,   141,   241,    60,   142,   242,    63,    22,    23,
      24,   159,   160,    25,    64,    26,    27,    74,    75,   155,
     173,   165,   166,    57,   220,    65,   154,   114,   115,   116,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     196,    97,   248,    98,   175,   157,   157,   157,   167,   168,
     169,   181,   161,   162,   163,   164,     1,     2,     3,     4,
       5,     1,     2,     3,     4,     5,   100,   154,   148,   149,
     150,     6,     7,   125,     1,     2,     3,     4,     5,   127,
       8,   223,   224,   196,   196,   196,   129,   196,   135,     6,
       7,   171,   176,   177,   119,   120,   121,   178,     8,   179,
     206,   208,   183,   211,   182,   184,    18,    19,   205,   109,
     110,   111,   112,   212,   213,    22,    23,    24,   191,   185,
      25,   172,    26,    27,    18,    19,   194,   195,   201,   203,
     232,   233,   157,    22,    23,    24,   202,   204,    25,   214,
      26,    27,   141,   122,   209,   218,   225,   123,   130,   124,
     231,   234,   113,   235,   229,   244,   239,   240,   247,   114,
     115,   116,   243,   249,   252,   245,   255,   257,     1,     2,
       3,     4,     5,   230,   156,   139,   216,   250,   219,   251,
     158,   193,   137,     6,     7,   256,    67,    68,    69,    70,
      71,     0,     8,    72,    73,     9,    10,    11,    12,    74,
      75,    13,    14,    15,    16,     0,    17,     0,     0,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    19,
      20,    21,     1,     2,     3,     4,     5,    22,    23,    24,
       0,     0,    25,     0,    26,    27,     0,     6,     7,     0,
      28,    86,    29,     0,     0,     0,     8,     0,     0,     9,
      10,    11,    12,     0,     0,    13,    14,    15,    16,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,    20,    21,     1,     2,     3,     4,
       5,    22,    23,    24,     0,     0,    25,     0,    26,    27,
       0,     6,     7,     0,    28,   136,    29,     0,     0,     0,
       8,     0,     0,     9,    10,    11,    12,     0,     0,    13,
      14,    15,    16,     0,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,    20,    21,
       1,     2,     3,     4,     5,    22,    23,    24,     0,     0,
      25,     0,    26,    27,     0,     6,     7,     0,    28,   153,
      29,     0,     0,     0,     8,     0,     0,     9,    10,    11,
      12,     0,     0,    13,    14,    15,    16,     0,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,    19,    20,    21,     1,     2,     3,     4,     5,    22,
      23,    24,     0,     0,    25,     0,    26,    27,     0,     6,
       7,     0,    28,   186,    29,     0,     0,     0,     8,     0,
       0,     9,    10,    11,    12,     0,     0,    13,    14,    15,
      16,     0,    17,     1,     2,     3,     4,     5,     0,     0,
       0,     0,     0,     0,    18,    19,    20,    21,     6,     7,
       0,     0,     0,    22,    23,    24,     0,     8,    25,     0,
      26,    27,     0,     0,     0,     0,    28,     0,    29,     0,
       0,     1,     2,     3,     4,     5,     0,     0,     0,     0,
       0,     0,     0,    18,    19,     0,     6,     7,     0,     0,
       0,     0,    22,    23,    24,     8,     0,    25,     0,    26,
      27,     1,     2,     3,     4,     5,     0,   180,     0,     0,
       0,     0,     0,     0,     0,     0,     6,     7,     0,     0,
       0,    18,    19,     0,     0,     8,     0,     0,     0,     0,
      22,    23,    24,     0,     0,    25,     0,    26,    27,     1,
       2,     3,     4,     5,     0,   207,     0,     0,     0,     0,
       0,    18,    19,     0,     6,     7,     0,     0,     0,     0,
      22,    23,    24,     8,     0,    25,     0,    26,    27,     0,
       0,     0,     0,     0,     0,   210,   -54,   -54,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,   -54,    18,
      19,     0,     1,     2,     3,     4,     5,     0,    22,    23,
      24,     0,     0,    25,     0,    26,    27,     6,     7,     0,
       0,     0,     0,     0,     0,     0,     8,     0,     0,     0,
       0,     0,     0,     0,     0,   -54,   -54,     0,   -54,   -54,
     -54,   -54,   -54,   -54,   -54,   -54,   -54,     0,     0,   -54,
       0,   -54,    18,    19,     0,   -54,     1,     2,     3,     4,
       5,    22,    23,    24,     0,     0,    54,     0,    26,    27,
       0,     6,     7,     0,     0,     0,     0,     0,     0,     0,
       8,    72,    73,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    19,     0,     0,
       0,     0,     0,     0,     0,    22,    23,    24,     0,     0,
      25,     0,    26,    27,    67,    68,    69,    70,    71,     0,
       0,    72,    73,     0,     0,     0,     0,    74,    75,     0,
       0,     0,     0,     0,     0,     0,     0,    76,    77,    78,
      79,    80,    81,    82,    83,    84,   138,    72,    73,     0,
       0,     0,     0,    74,    75,     0,     0,     0,     0,     0,
       0,     0,     0,    76,    77,    78,    79,    80,    81,    82,
      83,    84,   138
};

static const yytype_int16 yycheck[] =
{
       0,    10,   194,   141,   141,   117,    43,     6,     7,     8,
     122,    77,    54,   142,    14,   152,    25,    12,    13,     3,
       4,     5,     6,     7,    53,     3,     4,     5,     6,     7,
      42,    43,   195,   145,    18,    19,   199,    34,    35,    76,
      10,    11,    41,    27,   236,    54,    75,    62,    63,    53,
     187,   189,    61,    77,    63,    64,    65,    67,   195,   196,
     197,    53,   199,    67,    76,    60,    61,    64,     8,    53,
      54,   200,    64,    74,    77,    67,    77,    67,    62,    63,
      64,   101,   102,    67,    67,    69,    70,    34,    35,    98,
     202,   107,   108,    77,    72,    67,    96,    64,    65,    66,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     152,    77,   241,    58,   123,   114,   115,   116,   114,   115,
     116,   130,   103,   104,   105,   106,     3,     4,     5,     6,
       7,     3,     4,     5,     6,     7,     9,   137,    91,    92,
      93,    18,    19,     0,     3,     4,     5,     6,     7,    77,
      27,   196,   197,   195,   196,   197,    36,   199,    68,    18,
      19,    53,    53,    68,    18,    19,    20,    68,    27,    67,
     179,   180,    68,   182,    77,    68,    53,    54,   178,    14,
      15,    16,    17,   183,   184,    62,    63,    64,    74,    68,
      67,    68,    69,    70,    53,    54,    71,    75,    59,    68,
     209,   210,   201,    62,    63,    64,    74,    72,    67,    75,
      69,    70,    64,    67,    77,    68,    76,    71,    77,    73,
      68,    77,    57,    40,   201,   234,    72,    76,    59,    64,
      65,    66,    77,    59,    76,   235,    59,    76,     3,     4,
       5,     6,     7,   202,    99,    89,   187,   247,   191,   249,
     100,   146,    88,    18,    19,   255,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    41,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,     3,     4,     5,     6,     7,    62,    63,    64,
      -1,    -1,    67,    -1,    69,    70,    -1,    18,    19,    -1,
      75,    76,    77,    -1,    -1,    -1,    27,    -1,    -1,    30,
      31,    32,    33,    -1,    -1,    36,    37,    38,    39,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,     3,     4,     5,     6,
       7,    62,    63,    64,    -1,    -1,    67,    -1,    69,    70,
      -1,    18,    19,    -1,    75,    76,    77,    -1,    -1,    -1,
      27,    -1,    -1,    30,    31,    32,    33,    -1,    -1,    36,
      37,    38,    39,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
       3,     4,     5,     6,     7,    62,    63,    64,    -1,    -1,
      67,    -1,    69,    70,    -1,    18,    19,    -1,    75,    76,
      77,    -1,    -1,    -1,    27,    -1,    -1,    30,    31,    32,
      33,    -1,    -1,    36,    37,    38,    39,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    54,    55,    56,     3,     4,     5,     6,     7,    62,
      63,    64,    -1,    -1,    67,    -1,    69,    70,    -1,    18,
      19,    -1,    75,    76,    77,    -1,    -1,    -1,    27,    -1,
      -1,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    -1,    41,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    18,    19,
      -1,    -1,    -1,    62,    63,    64,    -1,    27,    67,    -1,
      69,    70,    -1,    -1,    -1,    -1,    75,    -1,    77,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    -1,    18,    19,    -1,    -1,
      -1,    -1,    62,    63,    64,    27,    -1,    67,    -1,    69,
      70,     3,     4,     5,     6,     7,    -1,    77,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    -1,
      -1,    53,    54,    -1,    -1,    27,    -1,    -1,    -1,    -1,
      62,    63,    64,    -1,    -1,    67,    -1,    69,    70,     3,
       4,     5,     6,     7,    -1,    77,    -1,    -1,    -1,    -1,
      -1,    53,    54,    -1,    18,    19,    -1,    -1,    -1,    -1,
      62,    63,    64,    27,    -1,    67,    -1,    69,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    77,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    53,
      54,    -1,     3,     4,     5,     6,     7,    -1,    62,    63,
      64,    -1,    -1,    67,    -1,    69,    70,    18,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    58,    -1,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    -1,    71,
      -1,    73,    53,    54,    -1,    77,     3,     4,     5,     6,
       7,    62,    63,    64,    -1,    -1,    67,    -1,    69,    70,
      -1,    18,    19,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    63,    64,    -1,    -1,
      67,    -1,    69,    70,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    28,    29,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,    18,    19,    27,    30,
      31,    32,    33,    36,    37,    38,    39,    41,    53,    54,
      55,    56,    62,    63,    64,    67,    69,    70,    75,    77,
      79,    80,    81,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,    94,    95,    96,   116,   117,   119,   121,
     122,   123,    90,    90,    67,    90,    77,    77,    80,    77,
      77,    67,    95,    67,    67,    67,    80,    21,    22,    23,
      24,    25,    28,    29,    34,    35,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    76,    95,    97,    98,
      99,   102,   103,   104,   105,   106,   115,    77,    58,     8,
       9,    10,    11,    12,    13,    60,    61,    62,    63,    14,
      15,    16,    17,    57,    64,    65,    66,    82,    90,    18,
      19,    20,    67,    71,    73,     0,   103,    77,    80,    36,
      77,    80,   120,    80,    80,    68,    76,   115,    53,    97,
      53,    64,    67,   100,   101,   111,   112,   114,    99,    99,
      99,    53,    75,    76,    95,    80,    84,    90,    85,    86,
      86,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      81,    53,    68,    81,    93,    80,    53,    68,    68,    67,
      77,    80,    77,    68,    68,    68,    76,   104,   112,   113,
     111,    74,    81,   114,    71,    75,   103,   104,   107,   108,
     109,    59,    74,    68,    72,    95,    80,    77,    80,    77,
      77,    80,    95,    95,    75,   118,   113,   112,    68,   100,
      72,   122,   107,   109,   109,    76,   107,   110,   111,    83,
      93,    68,    80,    80,    77,    40,    42,    43,    76,    72,
      76,    74,    77,    77,    80,    95,   122,    59,   111,    59,
      95,    95,    76,    43,    76,    59,    95,    76
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 27:

/* Line 1455 of yacc.c  */
#line 91 "BNF.y"
    {printf("Suma");;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 252 "BNF.y"
    {printf("if con else");;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 253 "BNF.y"
    {printf("if sin else");;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 285 "BNF.y"
    {printf("Caracter\n");;}
    break;

  case 154:

/* Line 1455 of yacc.c  */
#line 286 "BNF.y"
    {printf("Real\n");;}
    break;

  case 155:

/* Line 1455 of yacc.c  */
#line 289 "BNF.y"
    {printf("Octal\n");;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 290 "BNF.y"
    {printf("Decimal\n");;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 291 "BNF.y"
    {printf("Hexadecimal\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 1826 "BNF.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 294 "BNF.y"

int yyerror(char * mensaje){
    printf("Error: %s\n", mensaje);
}

int main(){

    #ifdef BISON_DEBUG
        yydebug = 1;
    #endif

    printf("> ");
    
return yyparse();
}
