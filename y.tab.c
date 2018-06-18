/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "go.y"
void yyerror (char *s);
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include  <string.h>
#include <ctype.h>
int symbols[100];
int symbolVal(char symbol[]);
void updateSymbolVal(char symbol[], int val);
char temps[7][10]={"t1","t2","t3","t4","t5","t6","t7"};

extern FILE *yyin;
extern FILE *yyout;

extern int yylex();
extern char *yytext;
extern char yylineno;
#line 20 "go.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {int num; char w[20];} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define print 257
#define exit_command 258
#define word 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define GT 263
#define LT 264
#define GTE 265
#define LTE 266
#define EQ 267
#define NEQ 268
#define MOD 269
#define number 270
#define identifier 271
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    4,    1,    1,    1,    1,    1,
    1,    2,    2,    6,    6,    6,    6,    6,    6,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    3,    3,    3,    3,
    3,    3,
};
static const YYINT yylen[] = {                            2,
    2,    3,    2,    3,    3,    1,    1,    1,    2,    2,
    2,    4,    4,    3,    3,    1,    3,    3,    3,    3,
    3,    1,    1,    9,   15,    9,   15,   10,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   28,    3,    3,    3,    3,
    3,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    6,    0,    8,    7,
    0,   22,   23,    0,   16,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,    0,   11,
    9,    1,    5,    0,    4,    0,    0,    0,    0,    0,
    0,    0,   47,   48,   49,   50,   51,   52,    0,    0,
    0,   14,    2,   19,   17,   18,   20,   21,    0,    0,
    0,    0,    0,    0,   13,   12,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   25,   27,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   29,   38,   30,   42,   34,   39,   31,
   43,   35,   40,   32,   44,   36,   41,   33,   45,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   46,
};
static const YYINT yydgoto[] = {                          6,
   14,   15,    7,    8,    9,   10,
};
static const YYINT yysindex[] = {                      -213,
 -123,  -57,  -35,  -29,  -61, -133,    0,  -44,    0,    0,
  -41,    0,    0,  -39,    0,    0, -247, -240, -162, -162,
 -162, -162, -162, -162, -162, -120,  -22,    0,  -18,    0,
    0,    0,    0, -162,    0, -162, -162, -162, -162,  -55,
   19,  -49,    0,    0,    0,    0,    0,    0,   60,    6,
  -33,    0,    0,    0,    0,    0,    0,    0,  -52, -162,
 -162, -162, -162, -162,    0,    0, -229,   43,   50,   63,
   69,   78, -118,   17,  -48,    3,   20,   22,   23,   29,
  -26, -162, -209, -160, -137, -136, -170,   12,   15,  -20,
 -110,   81,  -97,   83,  -95,   98,  -93,  102,  104,  -94,
  -89,   62,  109,  -13,  -86,  130,   -7,  -80,  134,    8,
  -72,  141,   14,  -70,  -53,   99,  100,  -40,  -51,  -47,
  180,  -45,  -43,  184,  -42,  -38,  186,  -37,  -36,  189,
  -32,  -19,  -17,  116,  181,  183,  -25,  187,  190,  -23,
  191,  192,  -16,  194,  196,  -10,   -4,   -9, -162,  -30,
   -3,    5,  215,    9,   10,  227,   16,   18,  233,   24,
   26,  234,  235,  239,   21,  238,  255,  256,   45,  261,
  262,   49,  263,  265,   54,  264,  269,   56,   44,  193,
  195, -162,   51,   55,  -90,   57,   58,  -88,   61,   64,
  -75,   65,   66,  -73,  253,    0,    0,   27,  258,  260,
  267,   34,  271,  273,  274,   40,  278,  279,  280,   47,
  281,  282,  283,   53,   52,  199,  218,  219,  220,  221,
  222,  223,  224,  225,  226,  228,  229,  230,  231,  232,
  236,  237,  310,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,  316,   89,  304,   93,  305,   96,  318,  101,  309,
  244,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  311,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    1,
    7,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   13,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
static const YYINT yygindex[] = {                         0,
   97,   94,   37,  366,  367,  368,
};
#define YYTABLESIZE 374
static const YYINT yytable[] = {                         25,
   24,   16,   38,   36,   17,   37,   26,   39,   38,   36,
   18,   37,   28,   39,   32,   38,   36,   33,   37,   35,
   39,   38,   36,   40,   37,   66,   39,   73,   38,   36,
   42,   37,   89,   39,   38,   36,   52,   37,  102,   39,
   53,   74,   28,    1,    2,  120,    3,   91,    4,   38,
   36,  123,   37,   41,   39,   38,   36,    5,   37,   59,
   39,   92,   38,   36,   65,   37,  126,   39,   38,   36,
   67,   37,  129,   39,   83,   38,   36,   82,   37,  181,
   39,   38,   36,   75,   37,  216,   39,   88,   38,   36,
   76,   37,  220,   39,   38,   36,   93,   37,  224,   39,
   99,   38,   36,   77,   37,  228,   39,   12,   13,   78,
   94,  232,   43,   44,   45,   46,   47,   48,   79,   95,
   97,   49,   51,   26,   27,   84,    3,   54,    4,   55,
   56,   57,   58,   96,   98,   11,  100,    5,   50,  101,
   80,  105,   85,  108,   86,   87,   12,   13,  103,   12,
   13,   12,   13,   68,   69,   70,   71,   72,  111,   12,
   13,  106,  114,  109,  115,  112,  116,  119,  201,   81,
  205,  117,   12,   13,   12,   13,   12,   13,   90,   12,
   13,   12,   13,  209,  121,  213,  118,  104,  122,  107,
  124,  110,  125,  113,   12,   13,   12,   13,  127,  128,
  130,   19,   20,   21,   22,   23,   24,   19,   20,   21,
   22,   23,   24,   60,   61,   62,   63,  131,   64,  135,
  134,  132,  133,  136,  137,  138,  140,  139,  141,   34,
  143,  146,  142,  144,  145,   34,  147,  148,  150,  149,
  166,  151,   34,  152,  153,  165,  156,  154,   34,  164,
  155,  157,  158,  159,  160,   34,  161,   24,   24,  162,
   24,   34,   24,   26,   26,  163,   26,  167,   26,   28,
   28,   24,   28,  169,   28,  168,   34,   26,  198,  170,
  171,  202,   34,   28,  206,  172,  173,  210,  174,   34,
  214,  175,  178,  179,  176,   34,  177,  180,  182,  183,
  184,  185,   34,  186,  187,  188,  192,  189,   34,  190,
  191,  193,  194,  215,  195,   34,  217,  196,  218,  197,
  199,   34,  233,  234,  200,  219,  203,  204,   34,  221,
  207,  222,  223,  208,  211,  212,  225,  226,  227,  229,
  230,  231,  235,  236,  237,  238,  239,  240,  241,  242,
  243,  251,  244,  245,  246,  247,  248,  252,  253,  254,
  249,  250,  255,  256,  259,  257,  258,  261,  262,   15,
  260,   29,   30,   31,
};
static const YYINT yycheck[] = {                         61,
    0,   59,   42,   43,   40,   45,    0,   47,   42,   43,
   40,   45,    0,   47,   59,   42,   43,   59,   45,   59,
   47,   42,   43,  271,   45,   59,   47,  257,   42,   43,
  271,   45,   59,   47,   42,   43,   59,   45,   59,   47,
   59,  271,    6,  257,  258,   59,  260,  257,  262,   42,
   43,   59,   45,   17,   47,   42,   43,  271,   45,   41,
   47,  271,   42,   43,   59,   45,   59,   47,   42,   43,
  123,   45,   59,   47,  123,   42,   43,   61,   45,   59,
   47,   42,   43,   41,   45,   59,   47,   59,   42,   43,
   41,   45,   59,   47,   42,   43,  257,   45,   59,   47,
  271,   42,   43,   41,   45,   59,   47,  270,  271,   41,
  271,   59,   19,   20,   21,   22,   23,   24,   41,  257,
  257,   25,   26,  257,  258,  123,  260,   34,  262,   36,
   37,   38,   39,  271,  271,  259,  125,  271,  259,  125,
  259,   61,  123,   61,  123,  123,  270,  271,  259,  270,
  271,  270,  271,   60,   61,   62,   63,   64,   61,  270,
  271,  259,   61,  259,   61,  259,  261,   59,  259,   73,
  259,  261,  270,  271,  270,  271,  270,  271,   82,  270,
  271,  270,  271,  259,  271,  259,  125,   91,   59,   93,
  271,   95,   59,   97,  270,  271,  270,  271,  271,   59,
  271,  263,  264,  265,  266,  267,  268,  263,  264,  265,
  266,  267,  268,  263,  264,  265,  266,  271,  268,  271,
  261,  123,  123,  271,   45,  271,   43,  271,  271,  269,
   45,   43,  271,  271,  271,  269,  269,  257,  123,  257,
  271,   61,  269,   61,  270,  149,  270,   61,  269,  259,
   61,   61,   61,  270,   61,  269,   61,  257,  258,  270,
  260,  269,  262,  257,  258,  270,  260,  271,  262,  257,
  258,  271,  260,   59,  262,  271,  269,  271,  182,  271,
  271,  185,  269,  271,  188,   59,  271,  191,  271,  269,
  194,   59,   59,   59,  271,  269,  271,   59,   61,   45,
   45,  257,  269,   43,   43,  257,   43,   45,  269,   45,
  257,   43,  257,   61,  271,  269,   59,  125,   59,  125,
  270,  269,  271,  125,  270,   59,  270,  270,  269,   59,
  270,   59,   59,  270,  270,  270,   59,   59,   59,   59,
   59,   59,  125,  125,  125,  125,  125,  125,  125,  125,
  125,   42,  125,  125,  125,  125,  125,  270,   43,  271,
  125,  125,   59,  271,   47,   61,  271,   59,  125,   59,
  270,    6,    6,    6,
};
#define YYFINAL 6
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 271
#define YYUNDFTOKEN 280
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'",0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,0,"';'",
0,"'='",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"print","exit_command","word","IF","ELSE","WHILE","GT","LT","GTE","LTE",
"EQ","NEQ","MOD","number","identifier",0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : begin",
"begin : assignment ';'",
"begin : begin assignment ';'",
"begin : exit_command ';'",
"begin : print exp ';'",
"begin : print word ';'",
"begin : condition",
"begin : condstat",
"begin : loopstat",
"begin : begin condstat",
"begin : begin condition",
"begin : begin loopstat",
"begin : begin print exp ';'",
"begin : begin print word ';'",
"begin : begin exit_command ';'",
"assignment : identifier '=' exp",
"exp : term",
"exp : exp '+' term",
"exp : exp '-' term",
"exp : exp MOD term",
"exp : exp '*' term",
"exp : exp '/' term",
"term : number",
"term : identifier",
"condstat : IF '(' condition ')' '{' print word ';' '}'",
"condstat : IF '(' condition ')' '{' print word ';' '}' ELSE '{' print word ';' '}'",
"condstat : IF '(' condition ')' '{' print exp ';' '}'",
"condstat : IF '(' condition ')' '{' print exp ';' '}' ELSE '{' print exp ';' '}'",
"condstat : IF '(' condition ')' '{' identifier '=' exp ';' '}'",
"condstat : IF '(' condition ')' '{' identifier '=' exp ';' '}' ELSE '{' identifier '=' exp ';' '}'",
"loopstat : WHILE '(' identifier GT term ')' '{' print exp ';' identifier '=' identifier '-' number ';' '}'",
"loopstat : WHILE '(' identifier LT term ')' '{' print exp ';' identifier '=' identifier '+' number ';' '}'",
"loopstat : WHILE '(' identifier GTE term ')' '{' print exp ';' identifier '=' identifier '-' number ';' '}'",
"loopstat : WHILE '(' identifier LTE term ')' '{' print exp ';' identifier '=' identifier '+' number ';' '}'",
"loopstat : WHILE '(' identifier GT term ')' '{' identifier '=' identifier '-' number ';' print exp ';' '}'",
"loopstat : WHILE '(' identifier LT term ')' '{' identifier '=' identifier '+' number ';' print exp ';' '}'",
"loopstat : WHILE '(' identifier GTE term ')' '{' identifier '=' identifier '-' number ';' print exp ';' '}'",
"loopstat : WHILE '(' identifier LTE term ')' '{' identifier '=' identifier '+' number ';' print exp ';' '}'",
"loopstat : WHILE '(' identifier GT term ')' '{' print word ';' identifier '=' identifier '-' number ';' '}'",
"loopstat : WHILE '(' identifier LT term ')' '{' print word ';' identifier '=' identifier '+' number ';' '}'",
"loopstat : WHILE '(' identifier GTE term ')' '{' print word ';' identifier '=' identifier '-' number ';' '}'",
"loopstat : WHILE '(' identifier LTE term ')' '{' print word ';' identifier '=' identifier '+' number ';' '}'",
"loopstat : WHILE '(' identifier GT term ')' '{' identifier '=' identifier '-' number ';' print word ';' '}'",
"loopstat : WHILE '(' identifier LT term ')' '{' identifier '=' identifier '+' number ';' print word ';' '}'",
"loopstat : WHILE '(' identifier GTE term ')' '{' identifier '=' identifier '-' number ';' print word ';' '}'",
"loopstat : WHILE '(' identifier LTE term ')' '{' identifier '=' identifier '+' number ';' print word ';' '}'",
"loopstat : WHILE '(' identifier NEQ term ')' '{' identifier '=' identifier MOD number ';' identifier '=' identifier '*' number '+' identifier ';' identifier '=' identifier '/' number ';' '}'",
"condition : identifier GT term",
"condition : identifier LT term",
"condition : identifier GTE term",
"condition : identifier LTE term",
"condition : identifier EQ term",
"condition : identifier NEQ term",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 223 "go.y"
                    /* C code */

int computeSymbolIndex(char token[])
{
	int idx = 0,i;
	for(i=0;token[i]!='\0';i++)
		idx+=token[i];
	idx=idx%100;



	return idx;
} 

/* returns the value of a given symbol */
int symbolVal(char symbol[])
{
	int bucket = computeSymbolIndex(symbol);
	return symbols[bucket];
}

/* updates the value of a given symbol */
void updateSymbolVal(char symbol[], int val)
{
	int bucket = computeSymbolIndex(symbol);
	symbols[bucket] = val;
}

int main (int argc, char * argv[]) {
	/* init symbol table */
	int i;
	for(i=0; i<100; i++) {
		symbols[i] = 0;
	}
	yyin=fopen(argv[1],"r+");
	yyout=fopen("tac.txt","w");
	if(yyin==NULL)
	{
		printf("No File detected, Type Directly\n\n");
		return yyparse();
	}
	else{
		return yyparse();
	}	
	
}

void yyerror (char *s) {fprintf (stderr, "%s at position %d , Unexpected character %s\n", s,yylineno,yytext);} 

#line 448 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 47 "go.y"
	{++yylineno;;}
break;
case 2:
#line 48 "go.y"
	{++yylineno;;}
break;
case 3:
#line 49 "go.y"
	{++yylineno;exit(EXIT_SUCCESS);}
break;
case 4:
#line 50 "go.y"
	{++yylineno;printf(":%d\n", yystack.l_mark[-1].num); fprintf(yyout,"%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-1].num,temps[0]); ;}
break;
case 5:
#line 51 "go.y"
	{++yylineno;printf(":%s \n",yystack.l_mark[-1].w); fprintf(yyout,"%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-1].w,temps[0]); ;}
break;
case 6:
#line 52 "go.y"
	{++yylineno;;}
break;
case 7:
#line 53 "go.y"
	{++yylineno;;}
break;
case 8:
#line 54 "go.y"
	{++yylineno;;}
break;
case 9:
#line 55 "go.y"
	{++yylineno;;}
break;
case 10:
#line 56 "go.y"
	{++yylineno;;}
break;
case 11:
#line 57 "go.y"
	{++yylineno;;}
break;
case 12:
#line 58 "go.y"
	{++yylineno;printf(":%d\n", yystack.l_mark[-1].num); fprintf(yyout,"%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-1].num,temps[0]); ;}
break;
case 13:
#line 59 "go.y"
	{++yylineno;printf(":%s \n",yystack.l_mark[-1].w); fprintf(yyout,"%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-1].w,temps[0]); ;}
break;
case 14:
#line 60 "go.y"
	{++yylineno;exit(EXIT_SUCCESS);}
break;
case 15:
#line 63 "go.y"
	{ updateSymbolVal(yystack.l_mark[-2].w,yystack.l_mark[0].num); fprintf(yyout,"%s := %d;\n %s := %s;\n\n",temps[0],yystack.l_mark[0].num,yystack.l_mark[-2].w,temps[0]); ; }
break;
case 16:
#line 65 "go.y"
	{yyval.num = yystack.l_mark[0].num;}
break;
case 17:
#line 66 "go.y"
	{yyval.num = yystack.l_mark[-2].num + yystack.l_mark[0].num;}
break;
case 18:
#line 67 "go.y"
	{yyval.num = yystack.l_mark[-2].num - yystack.l_mark[0].num;}
break;
case 19:
#line 68 "go.y"
	{yyval.num = yystack.l_mark[-2].num % yystack.l_mark[0].num;}
break;
case 20:
#line 69 "go.y"
	{yyval.num = yystack.l_mark[-2].num * yystack.l_mark[0].num;}
break;
case 21:
#line 70 "go.y"
	{yyval.num = yystack.l_mark[-2].num / yystack.l_mark[0].num;}
break;
case 22:
#line 72 "go.y"
	{yyval.num = yystack.l_mark[0].num;}
break;
case 23:
#line 73 "go.y"
	{yyval.num = symbolVal(yystack.l_mark[0].w);}
break;
case 24:
#line 76 "go.y"
	{if ( yystack.l_mark[-6].num == 1){ printf("%s\n",yystack.l_mark[-2].w); } 
                  fprintf(yyout,"if nz %s; \n%s := %s \nprint %s\n\n",temps[0],temps[1],yystack.l_mark[-2].w,temps[1]); ;}
break;
case 25:
#line 79 "go.y"
	{if (yystack.l_mark[-12].num==1){printf("%s\n",yystack.l_mark[-8].w);} else {printf("%s\n",yystack.l_mark[-2].w);} 
                  fprintf(yyout,"if z %s goto _L0;\n%s := %s \nprint %s;\n_LO : else;\n%s := %s \nprint %s\n\n",temps[0],temps[1],yystack.l_mark[-8].w,temps[1],temps[2],yystack.l_mark[-2].w,temps[2]); ;}
break;
case 26:
#line 84 "go.y"
	{if ( yystack.l_mark[-6].num == 1){ printf("%d\n",yystack.l_mark[-2].num); } 
                  fprintf(yyout,"if nz %s; \n%s := %s \nprint %s\n\n",temps[0],temps[1],yystack.l_mark[-2].num,temps[1]); ;}
break;
case 27:
#line 87 "go.y"
	{if (yystack.l_mark[-12].num==1){printf("%d\n",yystack.l_mark[-8].num);} else {printf("%d\n",yystack.l_mark[-2].num);} 
                  fprintf(yyout,"if z %s goto _L0;\n%s := %s \nprint %s;\n_LO : else;\n%s := %s \nprint %s\n\n",temps[0],temps[1],yystack.l_mark[-8].num,temps[1],temps[2],yystack.l_mark[-2].num,temps[2]); ;}
break;
case 28:
#line 92 "go.y"
	{if( yystack.l_mark[-7].num == 1 ) { updateSymbolVal(yystack.l_mark[-4].w,yystack.l_mark[-2].num); }  fprintf(yyout,"if nz %s;\n%s := %d;\n%s := %s;\n\n",temps[0],temps[1],yystack.l_mark[-2].num,yystack.l_mark[-4].w,temps[1]); ;}
break;
case 29:
#line 95 "go.y"
	{if( yystack.l_mark[-14].num == 1 ) { updateSymbolVal(yystack.l_mark[-11].w,yystack.l_mark[-9].num); } else{ updateSymbolVal(yystack.l_mark[-4].w,yystack.l_mark[-2].num);} fprintf(yyout,"if z %s goto _L0;\n%s := %d;\n%s := %s;\n_LO : else;\n%s := %d;\n%s := %s;\n\n",temps[0],temps[1],yystack.l_mark[-9].num,yystack.l_mark[-11].w,temps[1],temps[2],yystack.l_mark[-2].num,yystack.l_mark[-4].w,temps[2]); ;}
break;
case 30:
#line 98 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) > yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) > yyval.num  ){ printf("%d\n",yystack.l_mark[-8].num); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)-1);} 
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].num,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 31:
#line 104 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) < yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) < yyval.num  ){ printf("%d\n",yystack.l_mark[-8].num); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)+1);} 
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].num,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 32:
#line 110 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) >= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) >= yyval.num  ){ printf("%d\n",yystack.l_mark[-8].num); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)-1);}   
		  
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].num,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 33:
#line 118 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) <= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) <= yyval.num  ){ printf("%d\n",yystack.l_mark[-8].num); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)+1);}
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].num,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 34:
#line 125 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) > yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) > yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)-1); printf("%d\n",yystack.l_mark[-2].num);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].num,temps[2]) ; ;}
break;
case 35:
#line 132 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) < yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) < yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)+1); printf("%d\n",yystack.l_mark[-2].num);} 
		  
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].num,temps[2]) ; ;}
break;
case 36:
#line 140 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) >= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) >= yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)-1); printf("%d\n",yystack.l_mark[-2].num);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].num,temps[2]) ; ;}
break;
case 37:
#line 148 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) <= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) <= yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)+1); printf("%d\n",yystack.l_mark[-2].num);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].num,temps[2]) ; ;}
break;
case 38:
#line 158 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) > yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) > yyval.num  ){ printf("%s\n",yystack.l_mark[-8].w); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)-1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].w,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 39:
#line 165 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) < yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) < yyval.num  ){ printf("%s\n",yystack.l_mark[-8].w); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)+1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].w,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 40:
#line 171 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) >= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) >= yyval.num  ){ printf("%s\n",yystack.l_mark[-8].w); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)-1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].w,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 41:
#line 177 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) <= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) <= yyval.num  ){ printf("%s\n",yystack.l_mark[-8].w); updateSymbolVal(yystack.l_mark[-14].w,symbolVal(yystack.l_mark[-14].w)+1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[2],yystack.l_mark[-8].w,temps[2],temps[3],temps[4],yystack.l_mark[-14].w,temps[3]) ; ;}
break;
case 42:
#line 184 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) > yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) > yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)-1); printf("%s\n",yystack.l_mark[-2].w);} 
		 		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].w,temps[2]) ; ;}
break;
case 43:
#line 191 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) < yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) < yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)+1); printf("%s\n",yystack.l_mark[-2].w);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].w,temps[2]) ; ;}
break;
case 44:
#line 198 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) >= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) >= yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)-1); printf("%s\n",yystack.l_mark[-2].w);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].w,temps[2]) ; ;}
break;
case 45:
#line 205 "go.y"
	{if( symbolVal(yystack.l_mark[-14].w) <= yystack.l_mark[-12].num ) {yyval.num=yystack.l_mark[-12].num;} while( symbolVal(yystack.l_mark[-14].w) <= yyval.num  ){ updateSymbolVal(yystack.l_mark[-9].w,symbolVal(yystack.l_mark[-9].w)+1); printf("%s\n",yystack.l_mark[-2].w);} 
				  		
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],yystack.l_mark[-12].num,temps[1],yystack.l_mark[-14].w,temps[0],temps[1],temps[3],temps[4],yystack.l_mark[-14].w,temps[3],temps[2],yystack.l_mark[-2].w,temps[2]); ;}
break;
case 46:
#line 211 "go.y"
	{if(symbolVal(yystack.l_mark[-25].w) != yystack.l_mark[-23].num ) {yyval.num=yystack.l_mark[-23].num;} while( symbolVal(yystack.l_mark[-25].w) != yyval.num){ updateSymbolVal(yystack.l_mark[-20].w,symbolVal(yystack.l_mark[-25].w)%10); updateSymbolVal(yystack.l_mark[-14].w,(symbolVal(yystack.l_mark[-14].w)*10)+symbolVal(yystack.l_mark[-20].w)); updateSymbolVal(yystack.l_mark[-25].w,symbolVal(yystack.l_mark[-25].w)/10);}
		
		fprintf(yyout,"%s := %d; \n_L0 : %s := %s != %s; \nif nz %s;\n%s := 10;\n%s := %s % %s;\n%s := %s;\n%s := %s * %s;\n%s := %s + %s;\n%s := %s;\n%s := %s / %s;\n\n",temps[0],yystack.l_mark[-23].num,temps[1],yystack.l_mark[-25].w,temps[0],temps[1],temps[2],temps[3],yystack.l_mark[-25].w,temps[2],yystack.l_mark[-20].w,temps[3],temps[4],yystack.l_mark[-14].w,temps[2],temps[5],temps[4],yystack.l_mark[-20].w,yystack.l_mark[-14].w,temps[5],temps[6],yystack.l_mark[-25].w,temps[2]); ;}
break;
case 47:
#line 215 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) > yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s > %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
case 48:
#line 216 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) < yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s < %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
case 49:
#line 217 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) >= yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s >= %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
case 50:
#line 218 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) <= yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s <= %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
case 51:
#line 219 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) == yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s == %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
case 52:
#line 220 "go.y"
	{if( symbolVal(yystack.l_mark[-2].w) != yystack.l_mark[0].num ) {yyval.num=1;} else {yyval.num=0;} fprintf(yyout,"%s := %s != %d;\n ",temps[0],yystack.l_mark[-2].w,yystack.l_mark[0].num); ;}
break;
#line 898 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
