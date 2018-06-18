%{
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
%}

%union {int num; char w[20];}         /* Yacc definitions */
%start begin
%token print
%token exit_command
%token <w> word 
%token IF
%token ELSE
%token WHILE
%token GT
%token LT
%token GTE
%token LTE
%token EQ
%token NEQ
%token MOD
%token <num> number
%token <w>identifier
%type <num> begin exp term condition
%type <w> assignment
%type <num> loopstat



%%

/* descriptions of expected inputs     corresponding actions (in C) */

begin   : 	  assignment ';'		{++yylineno;;}
		| begin assignment ';'		{++yylineno;;}
		| exit_command ';'		{++yylineno;exit(EXIT_SUCCESS);}
		| print exp ';'			{++yylineno;printf(":%d\n", $2); fprintf(yyout,"%s := %d;\nprint %s;\n\n",temps[0],$2,temps[0]); ;}
                | print word ';'                {++yylineno;printf(":%s \n",$2); fprintf(yyout,"%s := %s;\nprint %s;\n\n",temps[0],$2,temps[0]); ;}
		| condition            		{++yylineno;;}
		| condstat			{++yylineno;;}
		| loopstat 			{++yylineno;;}
		| begin condstat		{++yylineno;;}
		| begin condition       	{++yylineno;;}
		| begin loopstat 		{++yylineno;;}
		| begin print exp ';'		{++yylineno;printf(":%d\n", $3); fprintf(yyout,"%s := %d;\nprint %s;\n\n",temps[0],$3,temps[0]); ;}
                | begin print word ';'          {++yylineno;printf(":%s \n",$3); fprintf(yyout,"%s := %s;\nprint %s;\n\n",temps[0],$3,temps[0]); ;}
		| begin exit_command ';'	{++yylineno;exit(EXIT_SUCCESS);}
                ;

assignment : identifier '=' exp  { updateSymbolVal($1,$3); fprintf(yyout,"%s := %d;\n %s := %s;\n\n",temps[0],$3,$1,temps[0]); ; }
	   ;
exp    	: term                  {$$ = $1;}
       	| exp '+' term          {$$ = $1 + $3;}
       	| exp '-' term          {$$ = $1 - $3;}
        | exp MOD term          {$$ = $1 % $3;}
        | exp '*' term		{$$ = $1 * $3;}
        | exp '/' term		{$$ = $1 / $3;}
       	;
term   	: number                {$$ = $1;}
	| identifier		{$$ = symbolVal($1);}
		; 
condstat	: IF'('condition')''{'print word';''}'           
		  {if ( $3 == 1){ printf("%s\n",$7); } 
                  fprintf(yyout,"if nz %s; \n%s := %s \nprint %s\n\n",temps[0],temps[1],$7,temps[1]); ;}	
		| IF '(' condition ')' '{' print word ';' '}' ELSE '{' print word  ';' '}' 
                  {if ($3==1){printf("%s\n",$7);} else {printf("%s\n",$13);} 
                  fprintf(yyout,"if z %s goto _L0;\n%s := %s \nprint %s;\n_LO : else;\n%s := %s \nprint %s\n\n",temps[0],temps[1],$7,temps[1],temps[2],$13,temps[2]); ;}
		

		| IF'('condition')''{'print exp';''}'           
		  {if ( $3 == 1){ printf("%d\n",$7); } 
                  fprintf(yyout,"if nz %s; \n%s := %s \nprint %s\n\n",temps[0],temps[1],$7,temps[1]); ;}
		|IF '(' condition ')' '{' print exp ';' '}' ELSE '{' print exp  ';' '}' 
                  {if ($3==1){printf("%d\n",$7);} else {printf("%d\n",$13);} 
                  fprintf(yyout,"if z %s goto _L0;\n%s := %s \nprint %s;\n_LO : else;\n%s := %s \nprint %s\n\n",temps[0],temps[1],$7,temps[1],temps[2],$13,temps[2]); ;}	
		

		|IF '(' condition ')' '{' identifier '=' exp  ';' '}'						
		  {if( $3 == 1 ) { updateSymbolVal($6,$8); }  fprintf(yyout,"if nz %s;\n%s := %d;\n%s := %s;\n\n",temps[0],temps[1],$8,$6,temps[1]); ;}
        	
        	| IF '(' condition ')' '{' identifier '=' exp  ';' '}' ELSE '{'	identifier '=' exp  ';' '}' 	
        	  {if( $3 == 1 ) { updateSymbolVal($6,$8); } else{ updateSymbolVal($13,$15);} fprintf(yyout,"if z %s goto _L0;\n%s := %d;\n%s := %s;\n_LO : else;\n%s := %d;\n%s := %s;\n\n",temps[0],temps[1],$8,$6,temps[1],temps[2],$15,$13,temps[2]); ;}
		;
loopstat	: WHILE '(' identifier GT term ')' '{' print exp ';' identifier '=' identifier '-' number ';' '}'           
		  {if( symbolVal($3) > $5 ) {$$=$5;} while( symbolVal($3) > $$  ){ printf("%d\n",$9); updateSymbolVal($3,symbolVal($3)-1);} 
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		| WHILE '(' identifier LT term ')' '{' print exp ';' identifier '=' identifier '+' number ';' '}'
		  {if( symbolVal($3) < $5 ) {$$=$5;} while( symbolVal($3) < $$  ){ printf("%d\n",$9); updateSymbolVal($3,symbolVal($3)+1);} 
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		| WHILE '(' identifier GTE term ')' '{' print exp ';'	 identifier '=' identifier '-' number ';' '}'
		  {if( symbolVal($3) >= $5 ) {$$=$5;} while( symbolVal($3) >= $$  ){ printf("%d\n",$9); updateSymbolVal($3,symbolVal($3)-1);}   
		  
		  
		  fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		
		| WHILE '(' identifier LTE term ')' '{' print exp ';' identifier '=' identifier '+' number ';' '}'
		  {if( symbolVal($3) <= $5 ) {$$=$5;} while( symbolVal($3) <= $$  ){ printf("%d\n",$9); updateSymbolVal($3,symbolVal($3)+1);}
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := %d;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		
		| WHILE '(' identifier GT term ')' '{' identifier '=' identifier '-' number ';'print exp ';' '}'           
		  {if( symbolVal($3) > $5 ) {$$=$5;} while( symbolVal($3) > $$  ){ updateSymbolVal($8,symbolVal($8)-1); printf("%d\n",$15);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		
		
		| WHILE '(' identifier LT term ')' '{' identifier '=' identifier '+' number ';' print exp ';' '}'
		  {if( symbolVal($3) < $5 ) {$$=$5;} while( symbolVal($3) < $$  ){ updateSymbolVal($8,symbolVal($8)+1); printf("%d\n",$15);} 
		  
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		
		
		| WHILE '(' identifier GTE term ')' '{' identifier '=' identifier '-' number ';' print exp ';' '}'
		  {if( symbolVal($3) >= $5 ) {$$=$5;} while( symbolVal($3) >= $$  ){ updateSymbolVal($8,symbolVal($8)-1); printf("%d\n",$15);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		
		
		
		| WHILE '(' identifier LTE term ')' '{' identifier '=' identifier '+' number ';' print exp ';' '}'
		  {if( symbolVal($3) <= $5 ) {$$=$5;} while( symbolVal($3) <= $$  ){ updateSymbolVal($8,symbolVal($8)+1); printf("%d\n",$15);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %d;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		

	

	
		| WHILE '(' identifier GT term ')' '{' print word  ';' identifier '=' identifier '-' number ';' '}'           
		  {if( symbolVal($3) > $5 ) {$$=$5;} while( symbolVal($3) > $$  ){ printf("%s\n",$9); updateSymbolVal($3,symbolVal($3)-1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		
		| WHILE '(' identifier LT term ')' '{'  print word ';'identifier '=' identifier '+' number';' '}'
		  {if( symbolVal($3) < $5 ) {$$=$5;} while( symbolVal($3) < $$  ){ printf("%s\n",$9); updateSymbolVal($3,symbolVal($3)+1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}

		
		| WHILE '(' identifier GTE term ')' '{'  print word ';'identifier '=' identifier '-' number ';' '}'
		  {if( symbolVal($3) >= $5 ) {$$=$5;} while( symbolVal($3) >= $$  ){ printf("%s\n",$9); updateSymbolVal($3,symbolVal($3)-1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		| WHILE '(' identifier LTE term ')' '{'  print word ';' identifier '=' identifier '+' number ';' '}'
		  {if( symbolVal($3) <= $5 ) {$$=$5;} while( symbolVal($3) <= $$  ){ printf("%s\n",$9); updateSymbolVal($3,symbolVal($3)+1);} 
		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := %s;\nprint %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],$9,temps[2],temps[3],temps[4],$3,temps[3]) ; ;}
		
		
		
		| WHILE '(' identifier GT term ')' '{' identifier '=' identifier '-' number ';'  print  word ';' '}'          
		  {if( symbolVal($3) > $5 ) {$$=$5;} while( symbolVal($3) > $$  ){ updateSymbolVal($8,symbolVal($8)-1); printf("%s\n",$15);} 
		 		  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s > %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
	
		
		| WHILE '(' identifier LT term ')' '{' identifier '=' identifier '+' number ';'  print word ';' '}'
		  {if( symbolVal($3) < $5 ) {$$=$5;} while( symbolVal($3) < $$  ){ updateSymbolVal($8,symbolVal($8)+1); printf("%s\n",$15);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s < %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		
		
		| WHILE '(' identifier GTE term ')' '{' identifier '=' identifier '-' number ';'  print word ';' '}'
		  {if( symbolVal($3) >= $5 ) {$$=$5;} while( symbolVal($3) >= $$  ){ updateSymbolVal($8,symbolVal($8)-1); printf("%s\n",$15);} 
				  
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s >= %s;\nif nz %s;\n%s := 1;\n%s := %s - %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]) ; ;}
		
		
		
		| WHILE '(' identifier LTE term ')' '{' identifier '=' identifier '+' number ';'  print word ';' '}'
		  {if( symbolVal($3) <= $5 ) {$$=$5;} while( symbolVal($3) <= $$  ){ updateSymbolVal($8,symbolVal($8)+1); printf("%s\n",$15);} 
				  		
		    fprintf(yyout,"%s := %d;\n_LO : %s := %s <= %s;\nif nz %s;\n%s := 1;\n%s := %s + %s;\ngoto _LO;%s := %s;\nprint %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[3],temps[4],$3,temps[3],temps[2],$15,temps[2]); ;}
		
		
		| WHILE '(' identifier NEQ term ')' '{' identifier '=' identifier MOD number ';' identifier '=' identifier '*' number '+' identifier ';' identifier '=' identifier '/' number ';' '}'
		{if(symbolVal($3) != $5 ) {$$=$5;} while( symbolVal($3) != $$){ updateSymbolVal($8,symbolVal($3)%10); updateSymbolVal($14,(symbolVal($14)*10)+symbolVal($8)); updateSymbolVal($3,symbolVal($3)/10);}
		
		fprintf(yyout,"%s := %d; \n_L0 : %s := %s != %s; \nif nz %s;\n%s := 10;\n%s := %s % %s;\n%s := %s;\n%s := %s * %s;\n%s := %s + %s;\n%s := %s;\n%s := %s / %s;\n\n",temps[0],$5,temps[1],$3,temps[0],temps[1],temps[2],temps[3],$3,temps[2],$8,temps[3],temps[4],$14,temps[2],temps[5],temps[4],$8,$14,temps[5],temps[6],$3,temps[2]); ;}
		;
condition 	: identifier GT term					{if( symbolVal($1) > $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s > %d;\n ",temps[0],$1,$3); ;}
                | identifier LT term					{if( symbolVal($1) < $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s < %d;\n ",temps[0],$1,$3); ;}
                | identifier GTE term					{if( symbolVal($1) >= $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s >= %d;\n ",temps[0],$1,$3); ;}
                | identifier LTE term					{if( symbolVal($1) <= $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s <= %d;\n ",temps[0],$1,$3); ;}
                | identifier EQ term					{if( symbolVal($1) == $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s == %d;\n ",temps[0],$1,$3); ;}
                | identifier NEQ term					{if( symbolVal($1) != $3 ) {$$=1;} else {$$=0;} fprintf(yyout,"%s := %s != %d;\n ",temps[0],$1,$3); ;}
                ;

%%                    /* C code */

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

