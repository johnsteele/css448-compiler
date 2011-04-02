    /***************************************************************************
     *  @file    css448-compiler/src/phase1/tokenconst.h                       *
     *  @author  John Steele      <EMAIL:programjsteele {at} gmail  {dot} com> *
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


    /* Header with token declarations. */
%{
#include "tokenconst.h"    
%}
    

    /* ======================== Definition Section ========================== */




    /* ======================== Rules Section =============================== */
%%

%%

    /* ======================== Subroutine Section ========================== */



/**
 * @brief main processes the input file. 
 */
int main (argc, char **argv)
{
    /* Skip over the program name. */
    ++argv, --argc; 


    /* Open the file. */
    if (argc > 0) yyin = fopen (argv [0], "r");
    else          yyin = stdin;


    /* Process the file */
    yylex ();


    return 0;
} /* end main() */ 

