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
[aA][nN][dD]                                                  { 
                                                                       printf("%i   ", yand);
                                                                       printf("yand");
                                                                       return yand; 
                                                                     }
[aA][rR][rR][aA][yY] 		                            { 
                                                                       printf("%i   ", yarray);
                                                                       printf("yarray");
                                                                       return yarray; 
                                                                    }
":=" 					                            {  printf("%i   ", yassign);
                                                                       printf("yassign");
                                                                       return yassign; 
                                                                    }
[bB][eE][gG][iI][nN] 			                    { 
                                                                       printf("%i   ", ybegin);
                                                                       printf("ybegin");
                                                                       return ybegin; }
"^" 					                            { 
                                                                       printf("%i   ", ycaret);
                                                                       printf("ycaret");
                                                                       return ycaret; }
[cC][aA][sS][eE] 			                     { 
                                                                       printf("%i   ", ycase);
                                                                       printf("ycase");
                                                                       return ycase; }
":" 					                            { 
                                                                       printf("%i   ", ycolon);
                                                                       printf("ycolon");
                                                                       return ycolon; }
"," 					                            { 
                                                                       printf("%i   ", ycomma);
                                                                       printf("ycomma");
                                                                       return ycomma; }
[cC][oO][nN][sS][tT]			                    { 
                                                                       printf("%i   ", yconst);
                                                                       printf("yconst");
                                                                       return yconst; }
[dD][iI][sS][pP][oO][sS][eE] 	                    { 
                                                                       printf("%i   ", ydispose);
                                                                       printf("ydispose");
                                                                       return ydispose; }
[dD][iI][vV] 				                    { 
                                                                       printf("%i   ", ydiv);
                                                                       printf("ydiv");
                                                                       return ydiv; }
"/" 					                            { 
                                                                       printf("%i   ", ydivide);
                                                                       printf("ydivide");
                                                                       return ydivide; }
[dD][oO] 				                            { 
                                                                       printf("%i   ", ydo);
                                                                       printf("ydo");
                                                                       return ydo; }
"." 					                            { 
                                                                       printf("%i   ", ydot);
                                                                       printf("ydot");
                                                                       return ydot; }
".." 					                            { 
                                                                       printf("%i   ", ydotdot);
                                                                       printf("ydotdot");
                                                                       return ydotdot; }
[dD][oO][wW][nN][tT][oO] 		                    {  
                                                                       printf("%i   ", ydownto);
                                                                       printf("ydownto");
                                                                       return ydownto; }
[eE][lL][sS][eE] 			                            { 

                                                                       printf("%i   ", yelse);
                                                                       printf("yelse");
                                                                       return yelse; }
[eE][nN][dD] 				                     { 
                                                                       printf("%i   ", yend);
                                                                       printf("yend");
                                                                       return yend; }
"=" 					                            { 
                                                                       printf("%i   ", yequal);
                                                                       printf("yequal");
                                                                       return yequal; }
[fF][aA][lL][sS][eE] 			                    { 
                                                                       printf("%i   ", yfalse);
                                                                       printf("yfalse");
                                                                       return yfalse; }
[fF][oO][rR] 				                    { 
                                                                       printf("%i   ", yfor);
                                                                       printf("yfor");
                                                                       return yfor; }
[fF][uU][nN][cC][tT][iI][oO][nN]	                    { 
                                                                       printf("%i   ", yfunction);
                                                                       printf("yfunction");
                                                                       return yfunction; }
">" 					                            { 
                                                                       printf("%i   ", ygreater);
                                                                       printf("ygreater");
                                                                       return ygreater; }
">=" 					                            { 
                                                                       printf("%i   ", ygreaterequal);
                                                                       printf("ygreaterequal");
                                                                       return ygreaterequal; }
[iI][fF] 				                            { 
                                                                       printf("%i   ", yif);
                                                                       printf("yif");
                                                                       return yif; }
[iI][nN]				                            { 
                                                                       printf("%i   ", yin);
                                                                       printf("yin");
                                                                       return yin; }
"{" 					                            { 
                                                                       printf("%i   ", yleftbracket);
                                                                       printf("yleftbracket");
                                                                       return yleftbracket; }
"(" 					                            { 
                                                                       printf("%i   ", yleftparen);
                                                                       printf("yleftparen");
                                                                       return yleftparen; }
"<" 					                            { 
                                                                       printf("%i   ", yless);
                                                                       printf("yless");
                                                                       return yless; }
"<=" 					                            { 
                                                                       printf("%i   ", ylessequal);
                                                                       printf("ylessequal");
                                                                       return ylessequal; }
"-" 					                            { 
                                                                       printf("%i   ", yminus);
                                                                       printf("yminus");
                                                                       return yminus; }
[mM][oO][dD] 				                    { 
                                                                       printf("%i   ", ymod);
                                                                       printf("ymod");
                                                                       return ymod; }
"*" 					                            { 
                                                                       printf("%i   ", ymultiply);
                                                                       printf("ymultiply");
                                                                       return ymultiply; }
[nN][eE][wW] 				                    { 
                                                                       printf("%i   ", yand);
                                                                       printf("ynew");
                                                                       return ynew; }
[nN][iI][lL] 				                            { 
                                                                       printf("%i   ", ynil);
                                                                       printf("ynil");
                                                                       return ynil; }
[nN][oO][tT] 				                    { 
                                                                       printf("%i   ", ynot);
                                                                       printf("ynot");
                                                                       return ynot; }
"<>" 					                            { 
                                                                       printf("%i   ", ynotequal);
                                                                       printf("ynotequal");
                                                                       return ynotequal; }
{NUMBER} 				                    { 
                                                                       printf("%i   ", ynumber);
                                                                       printf("ynumber");
                                                                       return ynumber; }
[rR][eE][cC][oO][rR][dD]  		                    { 
                                                                       printf("%i   ", yrecord);
                                                                       printf("yrecord");
                                                                       return yrecord; }
[oO][fF]	 			                            { 
                                                                       printf("%i   ", yof);
                                                                       printf("yof");
                                                                       return yof; }
[oO][rR]				                            { 
                                                                       printf("%i   ", yor);
                                                                       printf("yor");
                                                                       return yor; }
"+" 					                            { 
                                                                       printf("%i   ", yplus);
                                                                       printf("yplus");
                                                                       return yplus; }
[pP][rR][oO][cC][eE][dD][uU][rR][eE] 	            { 
                                                                       printf("%i   ", yprocedure);
                                                                       printf("yprocedure");
                                                                       return yprocedure; }
[pP][rR][oO][gG][rR][aA][mM] 		            { 
                                                                       printf("%i   ", yprogram);
                                                                       printf("yprogram");
                                                                       return yprogram; }
[rR][eE][aA][dD] 			                    { 
                                                                       printf("%i   ", yread);
                                                                       printf("yread");
                                                                       return yread; }
[rR][eE][aA][dD][lL][nN]	 	                    { 
                                                                       printf("%i   ", yreadln);
                                                                       printf("yreadln");
                                                                       return yreadln; }
[rR][eE][pP][eE][aA][tT] 		                    { 
                                                                       printf("%i   ", yrepeat);
                                                                       printf("yrepeat");
                                                                       return yrepeat; }
"}" 					                            { 
                                                                       printf("%i   ", yrightbracket);
                                                                       printf("yrightbracket");
                                                                       return yrightbracket; }
")" 					                            { 
                                                                       printf("%i   ", yrightparen);
                                                                       printf("yrightparen");
                                                                       return yrightparen; }
";" 					                            { 
                                                                       printf("%i   ", ysemicolon);
                                                                       printf("ysemicolon");
                                                                       return ysemicolon; }
[sS][eE][tT] 				                    { 
                                                                       printf("%i   ", yset);
                                                                       printf("yset");
                                                                       return yset; }
{STRING} 				                            { 
                                                                       printf("%i   ", ystring);
                                                                       printf("ystring");
                                                                       return ystring; }
[tT][hH][eE][nN] 			                            { 
                                                                       printf("%i   ", ythen);
                                                                       printf("ythen");
                                                                       return ythen; }
[tT][oO] 				                            { 
                                                                       printf("%i   ", yto);
                                                                       printf("yto");
                                                                       return yto; }
[tT][rR][uU][eE] 			                            { 
                                                                       printf("%i   ", ytrue);
                                                                       printf("ytrue");
                                                                       return ytrue; }
[tT][yY][pP][eE] 			                            { 
                                                                       printf("%i   ", ytype);
                                                                       printf("ytype");
                                                                       return ytype; }
[uU][nN][iI][tT]			                            { 
                                                                       printf("%i   ", yuntil);
                                                                       printf("yuntil");
                                                                       return yuntil; }
var|VAR|V                                                      { 
                                                                       printf("%i   ", yvar);
                                                                       printf("yvar");
                                                                       return yvar; }
[wW][hH][iI][lL][eE]		                            { 
                                                                       printf("%i   ", ywhile);
                                                                       printf("ywhile");
                                                                       return ywhile; }
[wW][rR][iI][tT][eE]	                                    { 
                                                                       printf("%i   ", ywrite);
                                                                       printf("ywrite");
                                                                       return ywrite; }
[wW][rR][iI][tT][eE][lL][eE][nN]                        { 
                                                                       printf("%i   ", ywriteln);
                                                                       printf("ywriteln");
                                                                       return ywriteln; }
{IDENTIFIER} 	                                            { 
                                                                       printf("%i   ", yident);
                                                                       printf("yident");
                                                                       printf("   %s", yytext);
                                                                       return yident; } 
"*)"                                                               {  return -5; }
"(*"                                                               { 
                                                                       while (1) {
                                                                          int token  = yylex (); 
                                                                          if (token == -5)
                                                                          {
                                                                             printf("*)");
                                                                             break;
                                                                          }				 
                                                                          printf ("%s", yytext);
                                                                           // if (yytext == " ") printf (" ");
                                                                       } 
                                                                       printf ("\n");
                                                                    }
[ ]                                                                 { printf (" "); }
{WHITESPACE} 				            { /* discard */ }
. 					                            { 
                                                                       printf("%i   ", yunknown);
                                                                       printf("yunknown");
                                                                       return yunknown; }
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

