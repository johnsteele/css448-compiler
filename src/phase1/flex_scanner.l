    /***************************************************************************
     *  @file    css448-compiler/src/phase1/flex_scanner.l                     *
     *  @author  John Steele      <EMAIL:programjsteele {at} gmail  {dot} com> *
     *  @author  Alicia Flinchum  <EMAIL:aliciaflinchum {at} yahoot {dot} com> *
     *  @version    1.0.0                                                      *
     *  @date Created: Wed 3 Mar 2011 11:05:24 AM PDT \n                       *
     *  Last Update:   Wed 30 Mar 2011 11:05:24 AM PDT                         *
     *                                                                         * 
     *  Description: This is a scanner for a Pascal-like language used for     *
     *               a compiler project in css-448. It is to be used with      *
     *               the (f)lex lexical analyser.                              *
     **************************************************************************/



    /* Finish after EOF. */
%option noyywrap 



    /* ======================== Token Header ================================= */
%{
#include "tokenconst.h"    
%}

    

    /* ======================== Definition Section ========================== */

    /* The language is not case sensitive. */    
LETTER          [a-zA-Z] 

    /* One single digit. */
DIGIT           [0-9]

    /* Spaces, tabs, newlines, and returns */
WHITESPACE      [ \t\n\r] 

    /* Any letter or digit. */
CHARACTER       [a-zA-Z0-9] 

    /* One-or-more sequence of digits, and must not contain spaces. */
INTEGER         {DIGIT}+

    /* e or E, zero-or-one sign, one-or-more digits. */
EXPONENT        [eE][+\-]?[0-9]+

    /* One-or-more digits, decimal, one-or-more digits, zero-or-one exponent. */
REAL            {DIGIT}+"."{DIGIT}+{EXPONENT}?

    /* An integer, or a real. */
NUMBER          {INTEGER}|{REAL}

    /* Quote-Characters-Quote or Apostrophy-Characters-Apostrophy */
D_QUOTE         \"
S_QUOTE         \'
STRING          {D_QUOTE}{CHARACTER}*{D_QUOTE}|{S_QUOTE}{CHARACTER}*{S_QUOTE} 
    
    /* One-or-more letters, followed by zoro-or-more letters, digits, or underscores. */
    /* Flex throws a bitch fit over this, haven't figured it out yet. */
IDENTIFIER      {LETTER}({LETTER}|{DIGIT})* 

S_COMMENT       (*
E_COMMENT       *) 


    /* ======================== Rules Section =============================== */
%% 
[aA][nN][dD]				                        { return yand; }
[aA][rR][rR][aA][yY] 			                    { return yarray; }
":=" 					                            { return yassign; }
[bB][eE][gG][iI][nN] 			                    { return ybegin; }
"^" 					                            { return ycaret; }
[cC][aA][sS][eE] 			                        { return ycase; }
":" 					                            { return ycolon; }
"," 					                            { return ycomma; }
[cC][oO][nN][sS][tT]			                    { return yconst; }
[dD][iI][sS][pP][oO][sS][eE] 	                    { return ydispose; }
[dD][iI][vV] 				                        { return ydiv; }
"/" 					                            { return ydivide; }
[dD][oO] 				                            { return ydo; }
"." 					                            { return ydot; }
".." 					                            { return ydotdot; }
[dD][oO][wW][nN][tT][oO] 		                    { return ydownto; }
[eE][lL][sS][eE] 			                        { return yelse; }
[eE][nN][dD] 				                        { return yend; }
"=" 					                            { return yequal; }
[fF][aA][lL][sS][eE] 			                    { return yfalse; }
[fF][oO][rR] 				                        { return yfor; }
[fF][uU][nN][cC][tT][iI][oO][nN]	                { return yfunction; }
">" 					                            { return ygreater; }
">=" 					                            { return ygreaterequal; }
[iI][fF] 				                            { return yif; }
[iI][nN]				                            { return yin; }
"{" 					                            { return yleftbracket; }
"(" 					                            { return yleftparen; }
"<" 					                            { return yless; }
"<=" 					                            { return ylessequal; }
"-" 					                            { return yminus; }
[mM][oO][dD] 				                        { return ymod; }
"*" 					                            { return ymultiply; }
[nN][eE][wW] 				                        { return ynew; }
[nN][iI][lL] 				                        { return ynil; }
[nN][oO][tT] 				                        { return ynot; }
"<>" 					                            { return ynotequal; }
{NUMBER} 				                            { return ynumber; }
[rR][eE][cC][oO][rR][dD]  		                    { return yrecord; }
[oO][fF]	 			                            { return yof; }
[oO][rR]				                            { return yor; }
"+" 					                            { return yplus; }
[pP][rR][oO][cC][eE][dD][uU][rR][eE] 	            { return yprocedure; }
[pP][rR][oO][gG][rR][aA][mM] 		                { return yprogram; }
[rR][eE][aA][dD] 			                        { return yread; }
[rR][eE][aA][dD][lL][nN]	 	                    { return yreadln; }
[rR][eE][pP][eE][aA][tT] 		                    { return yrepeat; }
"}" 					                            { return yrightbracket; }
")" 					                            { return yrightparen; }
";" 					                            { return ysemicolon; }
[sS][eE][tT] 				                        { return yset; }
{STRING} 				                            { return ystring; }
[tT][hH][eE][nN] 			                        { return ythen; }
[tT][oO] 				                            { return yto; }
[tT][rR][uU][eE] 			                        { return ytrue; }
[tT][yY][pP][eE] 			                        { return ytype; }
[uU][nN][iI][tT]			                        { return yuntil; }
var|VAR|V                                           { return yvar; }
[wW][hH][iI][lL][eE]		                        { return ywhile; }
[wW][rR][iI][tT][eE]	                            { return ywrite; }
[wW][rR][iI][tT][eE][lL][eE][nN]                    { return ywriteln; }
{IDENTIFIER} 	                                    { return yident; } 
"*)"                                                { return -5; }
"(*"                                                { 
                                                      while (1) {
                                                        int token  = yylex (); 
                                                        if (token == -5) break; 
                                                        printf ("%s", yytext);
                                                        if (*yytext == ' ') printf (" ");
                                                    } 
                                                      printf ("\n");
                                                    }
{WHITESPACE} 				                        { /* discard */ }
. 					                                { return yunknown; }
%%



 /* ======================== main ======================================== */ 
 /**
  * @brief Processes stdin, and prints the token's string representation
  *        and its associated value.  
  */
 /* ====================================================================== */ 
 int main (int argc, char **argv)
 { 
    /* Process file until EOF (i.e. yywrap() returns 0) */
    int token;
    while ((token = yylex()) != 0) printf ("%i %s\n", token, yytext); 

    /* Houston we have lift off */
    return 0;
 } /* end main () */

