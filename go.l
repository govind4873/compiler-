%{
#include "y.tab.h"
#include <stdio.h>     /* C declarations used in actions */
#include <stdlib.h>
#include  <string.h>
%}
%%
"print"					 {return print;}
"exit"				   	 {return exit_command;}
"else"                            	 {return ELSE;}
"if"                               	 {return IF;}
"while"					 {return WHILE;}
"~"[a-zA-Z]+			   	 {sprintf(yylval.w,"%s",yytext); return identifier;}
[a-zA-Z]+                          	 {sprintf(yylval.w,"%s",yytext); return word;}
[0-9]+                 			 {yylval.num = atoi(yytext); return number;}
[ \t\n]                			 ;
">"				          {return GT;}
"<"					 {return LT;}
">="					 {return GTE;}
"<="					 {return LTE;}
"=="					 {return EQ;}
"!=" 	   				 {return NEQ;}
"%"                             	 	 {return MOD;}
[-+=;{}()*/]           	   		 {return yytext[0];}
. {ECHO; yyerror ("Unexpected character");}

%%
int yywrap (void) {return 1;}

