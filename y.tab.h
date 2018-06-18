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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {int num; char w[20];} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
