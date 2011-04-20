/***************************************************************************
 *   @file   css448-compiler/src/phase1/flex_scanner.l                     *
 *   @author   John Steele <EMAIL:programjsteele   {at} gmail {dot} com>   *
 *   @author   Alicia Flinchum <EMAIL:aliciaflinchum {at} yahoo {dot} com> *
 *   @version   1.0.0                                                      *
 *   @date  Created: Wed 3 Mar 2011 11:05:24 AM PDT \n                     *
 *   Last Update: Wed 30 Mar 2011 11:05:24 AM PDT                      *
 *                                                                         *
 *   Description: This is a scanner for a Pascal-like Language used for    *
 *               a compiler project in css-448. It is to be used with      *
 *               the (f)lex lexical analyser.                              *
 **************************************************************************/



/* Finish after EOF. */
%option   noyywrap   



/* ======================== Token Header ================================= */
%{
#include <string.h>
#include "y.tab.h" 
/* Bison does this automatically, not sure about yacc. */
// extern YYSTYPE yylval; 
%}



/* ======================== Definition Section ========================== */ 

   /* The language is not case sensitive. */      
LETTER       [a-zA-Z]   

   /* One single digit. */
DIGIT        [0-9]

   /* Spaces, tabs, newlines, and returns */
WHITESPACE   [ \t\r]

   /* Any letter or digit. */
CHARACTER    [^(\"\')]   

   /* One-or-more sequence of digits, and must not contain spaces. */
INTEGER      {DIGIT}+

   /* e or E, zero-or-one sign, one-or-more digits. */
EXPONENT     [eE][+\-]?[0-9]+

   /* One-or-more digits, decimal, one-or-more digits, zero-or-one exponent. */
REAL         {DIGIT}+"."{DIGIT}+{EXPONENT}?

   /* An integer, or a real. */
NUMBER       {INTEGER}|{REAL}

   /* Quote-Characters-Quote or Apostrophy-Characters-Apostrophy */
D_QUOTE      \"
S_QUOTE      \'
   /* A String value which can start and end with either single or double  
      quotes andcontain any printable character inside. */
STRING       (\"({CHARACTER}|\')*\")|(\'({CHARACTER}|\")*\')   

   /*   One-or-more letters, followed  by zero-or-more letters, digits.*/
IDENTIFIER   {LETTER}({LETTER}|{DIGIT})*   

   /*Start of a comment. */
S_COMMENT         \(\*(.)*

   /* A full comment, beginning with "(*" and ending with "*)"*/
COMMENT      {S_COMMENT}({WHITESPACE}|{CHARACTER}|{D_QUOTE}|{S_QUOTE}|\*)*\*\)


 /* ======================== Rules Section =============================== */
%%   
[aA][nN][dD]                              { return yand;}
[aA][rR][rR][aA][yY]                      { return yarray;}
":="                                      { return yassign;}
[bB][eE][gG][iI][nN]                      { return ybegin;}
"^"                                       { return ycaret;}
[cC][aA][sS][eE]                          { return ycase;}
":"                                       { return ycolon;}
","                                       { return ycomma; }
[cC][oO][nN][sS][tT]                      { return yconst;}
[dD][iI][sS][pP][oO][sS][eE]              { return ydispose;}
[dD][iI][vV]                              { return ydiv; }
"/"                                       { return ydivide;}
[dD][oO]                                  { return ydo; }
"."                                       { return ydot;}
".."                                      { return ydotdot; }
[dD][oO][wW][nN][tT][oO]                  { return ydownto; }
[eE][lL][sS][eE]                          { return yelse;}
[eE][nN][dD]                              { return yend; }
"="                                       { return yequal;}
[fF][aA][lL][sS][eE]                      { return yfalse; }
[fF][oO][rR]                              { return yfor; }
[fF][uU][nN][cC][tT][iI][oO][nN]          { return yfunction; }
">"                                       { return ygreater; }
">="                                      { return ygreaterequal; }
[iI][fF]                                  { return yif; }
[iI][nN]                                  { return yin;}
\[                                        { return yleftbracket; }
"("                                       { return yleftparen; }
"<"                                       { return yless; }
"<="                                      { return ylessequal;}
"-"                                       { return yminus; }
[mM][oO][dD]                              { return ymod; }
"*"                                       { return ymultiply;}
[nN][eE][wW]                              { return ynew; }
[nN][iI][lL]                              { return ynil; }
[nN][oO][tT]                              { return ynot; }
"<>"                                      { return ynotequal; }
{NUMBER}                                  { return ynumber; }
[rR][eE][cC][oO][rR][dD]                  { return yrecord; }
[oO][fF]                                  { return yof; }
[oO][rR]                                  { return yor; }
"+"                                       { return yplus; }
[pP][rR][oO][cC][eE][dD][uU][rR][eE]      { return yprocedure; }
[pP][rR][oO][gG][rR][aA][mM]              { return yprogram;}
[rR][eE][aA][dD]                          { return yread; }
[rR][eE][aA][dD][lL][nN]                  { return yreadln;}
[rR][eE][pP][eE][aA][tT]                  { return yrepeat; }
\]                                        { return yrightbracket; }
")"                                       { return yrightparen; }
";"                                       { return ysemicolon; }
[sS][eE][tT]                              { return yset; }
{STRING}                                  {   
                                            /*next 2 lines remove quotes*/
                                            yytext++;
                                            yytext[yyleng - 2] = '\0';
                                            return ystring;   
                                          }
[tT][hH][eE][nN]                          { return ythen; }
[tT][oO]                                  { return yto; }
[tT][rR][uU][eE]                          { return ytrue; }
[tT][yY][pP][eE]                          { return ytype; }
[uU][nN][iI][tT]                          { return yuntil; }
var|VAR|V                                 { return yvar; }
[wW][hH][iI][lL][eE]                      { return ywhile; }
[wW][rR][iI][tT][eE]                      { return ywrite; }
[wW][rR][iI][tT][eE][lL][nN]              { return ywriteln; }
{IDENTIFIER}                              { 
					    yylval.str = strdup (yytext); 
					    return yident; 
					  }   
{COMMENT}                                 { /* This needs to be fixed to printf(the comment) return   -1; */ }
"\n"					  { printf ("\n"); }
{WHITESPACE}                              { /* discard */ }
.                                         { return yunknown; }
%%

    /* ======================== main ======================================== */ 
    /**
     *   @brief Processes stdin, and prints the token's string representation
     *   and its associated value.
     */
    /* ====================================================================== */ 
    int main (int argc, char **argv)
    {
      yyparse (); 
      printf ("Parsed!\n");
      return 0; 
    }  /* end main() */

