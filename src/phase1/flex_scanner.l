    /***************************************************************************
     *  @file    css448-compiler/src/phase1/tokenconst.h                       *
     *  @author  John Steele <EMAIL:programjsteele {at} gmail  {dot} com>      *
     *  @author  Alicia Flinchum  <EMAIL:aliciaflinchum {at} yahoot {dot} com> *
     *  @version    1.0.0                                                      *
     *  @date Created: Wed 3 Mar 2011 11:05:24 AM PDT \n                       *
     *  Last Update:   Wed 30 Mar 2011 11:05:24 AM PDT                         *
     *                                                                         * 
     *  Description: This is a scanner for a Pascal-like language used for     *
     *  a compiler project in css-448. It is to be used with                   *
     *               flex (lexical analyser).                                  *
     *                                                                         *
     *  Usage: > flex flex_scanner.l                                           *
     *         > gcc -g -o lex.yy.c scanner                                    * 
     *         > ./scanner < datafile                                          * 
     **************************************************************************/

    /* Lets assume yywrap() finish after EOF). */
%option noyywrap 


    /* ======================== Definition Section ========================== */
DIGIT   [0-9]
ID      [a-z][a-z0-9]*


    
    /* ======================== Rules Section =============================== */
%%
	/* Rules Section */
	/* Pattern 			Action */
{DIGIT}+ 		{
						printf ("An integer: %s (%d)\n", yytext, atoi (yytext));	
						}

{DIGIT}+"."{DIGIT}*			{
						printf ("A float: %s (%d)\n", yytext, atof (yytext));	
						}

xxx					return 55;

if|then|begin|end|procedure|function 		{
						printf ("A keyword: %s\n", yytext);	
						}

{ID}				printf ("An identifier: %s\n", yytext);


"+"|"-"|"*"|"/"		printf ("An operator: %s\n", yytext);

"{"[\^{}}\n]*"}" 		/* eat up one-line comments */

[ \t\n]+						/* eat up whitespace */

.						printf ("Uncrecognized character: %s\n", yytext); 

%%

    

    /* ======================== Subroutine Section ========================== */

int main (int argc, char **argv)
{
	++argv, --argc; /* Skip over program name */

	if (argc > 0)
			yyin = fopen (argv [0], "r");

	else
			yyin = stdin;

	int temp;

	temp = yylex ();	

	printf ("The returned value: %i\n\n", temp);
	return 0;
} /* end main () */




