/***************************************************************************
 *   @file   css448-compiler/src/phase1/flex_scanner.l                     *
 *   @author   John Steele <EMAIL:programjsteele   {at} gmail {dot} com>   *
 *   @author   Alicia Flinchum <EMAIL:aliciaflinchum {at} yahoo {dot} com> *
 *   @version   1.0.0                                                      *
 *   @date  Created: Wed 3 Mar 2011 11:05:24 AM PDT \n                     *
 *   Last Update: Wed 30 Mar 2011 11:05:24 AM PDT                          *
 *                                                                         *
 *   Description: This is a scanner for a Pascal-like Language used for    *
 *               a compiler project in css-448. It is to be used with      *
 *               the (f)lex lexical analyser.                              *
 **************************************************************************/



/* Finish after EOF. */
%option   noyywrap   



/* ======================== Token Header ================================= */
%{
#include "tokenconst.h"   

%}



/* ======================== Definition Section ========================== */


   /* The language is not case sensitive. */      
LETTER       [a-zA-Z]   

   /* One single digit. */
DIGIT        [0-9]

   /* Spaces, tabs, newlines, and returns */
WHITESPACE   [ \t\n\r]   

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
[aA][nN][dD]                              { 
                                             printf("%i   ", yand);
                                             printf("yand\n");
                                             return yand;
                                          }
[aA][rR][rR][aA][yY]                      {
                                             printf("%i   ", yarray);
                                             printf("yarray\n");
                                             return yarray;   
                                          }
":="                                      {   
                                             printf("%i   ", yassign);
                                             printf("yassign\n");
                                             return yassign;
                                          }
[bB][eE][gG][iI][nN]                      {   
                                             printf("%i   ", ybegin);
                                             printf("ybegin\n");
                                             return ybegin;   
                                          }
"^"                                       {   
                                             printf("%i   ", ycaret);
                                             printf("ycaret\n");
                                             return ycaret;
                                          }
[cC][aA][sS][eE]                          {   
                                             printf("%i   ", ycase);
                                             printf("ycase\n");
                                             return ycase;
                                          }
":"                                       {   
                                             printf("%i   ", ycolon);
                                             printf("ycolon\n");
                                             return ycolon;  
                                          }
","                                       {   
                                             printf("%i   ", ycomma);
                                             printf("ycomma\n");
                                             return ycomma;   
                                          }
[cC][oO][nN][sS][tT]                      {   
                                             printf("%i   ", yconst);
                                             printf("yconst\n");
                                             return yconst;
                                          }
[dD][iI][sS][pP][oO][sS][eE]              {   
                                             printf("%i   ", ydispose);
                                             printf("ydispose\n");
                                             return ydispose;   
                                          }
[dD][iI][vV]                              {   
                                             printf("%i   ", ydiv);
                                             printf("ydiv\n");
                                             return ydiv;   
                                          }
"/"                                       {   
                                             printf("%i   ", ydivide);
                                             printf("ydivide\n");
                                             return ydivide;  
                                          }
[dD][oO]                                  {   
                                             printf("%i   ", ydo);
                                             printf("ydo\n");
                                             return ydo;  
                                          }
"."                                       {   
                                             printf("%i   ", ydot);
                                             printf("ydot\n");
                                             return ydot;   
                                          }
".."                                      {   
                                             printf("%i   ", ydotdot);
                                             printf("ydotdot\n");
                                             return ydotdot;   
                                          }
[dD][oO][wW][nN][tT][oO]                  {   
                                             printf("%i   ", ydownto);
                                             printf("ydownto\n");
                                             return ydownto;   
                                          }
[eE][lL][sS][eE]                          {   
                                             printf("%i   ", yelse);
                                             printf("yelse\n");
                                             return yelse;  
                                          }
[eE][nN][dD]                              {   
                                             printf("%i   ", yend);
                                             printf("yend\n");
                                             return yend;   
                                          }
"="                                       {   
                                             printf("%i   ", yequal);
                                             printf("yequal\n");
                                             return yequal;   
                                          }
[fF][aA][lL][sS][eE]                      {   
                                             printf("%i   ", yfalse);
                                             printf("yfalse\n");
                                             return yfalse;   
                                          }
[fF][oO][rR]                              {   
                                             printf("%i   ", yfor);
                                             printf("yfor\n");
                                             return yfor;   
                                          }
[fF][uU][nN][cC][tT][iI][oO][nN]          {   
                                             printf("%i   ", yfunction);
                                             printf("yfunction\n");
                                             return yfunction;   
                                          }
">"                                       {   
                                             printf("%i   ", ygreater);
                                             printf("ygreater\n");
                                             return ygreater;   
                                          }
">="                                      {   
                                             printf("%i   ", ygreaterequal);
                                             printf("ygreaterequal\n");
                                             return ygreaterequal;   
                                          }
[iI][fF]                                  {   
                                             printf("%i   ", yif);
                                             printf("yif\n");
                                             return yif;   
                                          }
[iI][nN]                                  {   
                                             printf("%i   ", yin);
                                             printf("yin\n");
                                             return yin;   
                                          }
\[                                        {   
                                             printf("%i   ", yleftbracket);
                                             printf("yleftbracket\n");
                                             return   yleftbracket;   
                                          }
"("                                       {   
                                             printf("%i   ", yleftparen);
                                             printf("yleftparen\n");
                                             return yleftparen;   
                                          }
"<"                                       {   
                                             printf("%i   ", yless);
                                             printf("yless\n");
                                             return yless;   
                                          }
"<="                                      {   
                                             printf("%i   ", ylessequal);
                                             printf("ylessequal\n");
                                             return ylessequal;  
                                          }
"-"                                       {   
                                             printf("%i   ", yminus);
                                             printf("yminus\n");
                                             return yminus;   
                                          }
[mM][oO][dD]                              {   
                                             printf("%i   ", ymod);
                                             printf("ymod\n");
                                             return ymod;   
                                          }
"*"                                       {   
                                             printf("%i   ", ymultiply);
                                             printf("ymultiply\n");
                                             return ymultiply;   
                                          }
[nN][eE][wW]                              {   
                                             printf("%i   ", ynew);
                                             printf("ynew\n");
                                             return   ynew;   
                                          }
[nN][iI][lL]                              {   
                                             printf("%i   ", ynil);
                                             printf("ynil\n");
                                             return   ynil;   
                                          }
[nN][oO][tT]                              {   
                                             printf("%i   ", ynot);
                                             printf("ynot\n");
                                             return ynot;   
                                          }
"<>"                                      {   
                                             printf("%i   ", ynotequal);
                                             printf("ynotequal\n");
                                             return ynotequal;   }
{NUMBER}                                  {   
                                             printf("%i   ", ynumber);
                                             printf("ynumber");
                                             printf("   %s\n",   yytext);
                                             return ynumber;   
                                          }
[rR][eE][cC][oO][rR][dD]                  {   
                                             printf("%i   ", yrecord);
                                             printf("yrecord\n");
                                             return yrecord;   
                                          }
[oO][fF]                                  {   
                                             printf("%i   ", yof);
                                             printf("yof\n");
                                             return yof;   
                                          }
[oO][rR]                                  {   
                                             printf("%i   ", yor);
                                             printf("yor\n");
                                             return yor;   
                                          }
"+"                                       {   
                                             printf("%i   ", yplus);
                                             printf("yplus\n");
                                             return yplus;   
                                          }
[pP][rR][oO][cC][eE][dD][uU][rR][eE]      {   
                                             printf("%i   ", yprocedure);
                                             printf("yprocedure\n");
                                             return yprocedure;   
                                          }
[pP][rR][oO][gG][rR][aA][mM]              {   
                                             printf("%i   ", yprogram);
                                             printf("yprogram\n");
                                             return yprogram;  
                                          }
[rR][eE][aA][dD]                          {   
                                             printf("%i   ", yread);
                                             printf("yread\n");
                                             return yread;   
                                          }
[rR][eE][aA][dD][lL][nN]                  {   
                                             printf("%i   ", yreadln);
                                             printf("yreadln\n");
                                             return yreadln;
                                          }
[rR][eE][pP][eE][aA][tT]                  {   
                                             printf("%i   ", yrepeat);
                                             printf("yrepeat\n");
                                             return yrepeat;   
                                          }
\]                                        {   
                                             printf("%i   ", yrightbracket);
                                             printf("yrightbracket\n");
                                             return yrightbracket;   
                                          }
")"                                       {   
                                             printf("%i   ", yrightparen);
                                             printf("yrightparen\n");
                                             return yrightparen;   
                                          }
";"                                       {   
                                             printf("%i   ", ysemicolon);
                                             printf("ysemicolon\n");
                                             return ysemicolon;   
                                          }
[sS][eE][tT]                              {   
                                             printf("%i   ", yset);
                                             printf("yset\n");
                                             return yset;   
                                          }
{STRING}                                  {   
                                             /*next 2 lines remove quotes*/
                                             yytext++;
                                             yytext[yyleng - 2] = '\0';
                                             printf("%i   ", ystring);
                                             printf("ystring");
                                             printf("   %s\n", yytext);
                                             return ystring;   
                                          }
[tT][hH][eE][nN]                          {   
                                             printf("%i   ", ythen);
                                             printf("ythen\n");
                                             return ythen;   
                                          }
[tT][oO]                                  {   
                                             printf("%i   ", yto);
                                             printf("yto\n");
                                             return yto;   
                                          }
[tT][rR][uU][eE]                          {   
                                             printf("%i   ", ytrue);
                                             printf("ytrue\n");
                                             return ytrue;   
                                          }
[tT][yY][pP][eE]                          {   
                                             printf("%i   ", ytype);
                                             printf("ytype\n");
                                             return ytype;   
                                          }
[uU][nN][iI][tT]                          {   
                                             printf("%i   ", yuntil);
                                             printf("yuntil\n");
                                             return yuntil;   
                                          }
var|VAR|V                                 {   
                                             printf("%i   ", yvar);
                                             printf("yvar\n");
                                             return yvar;   
                                          }
[wW][hH][iI][lL][eE]                      {   
                                             printf("%i   ", ywhile);
                                             printf("ywhile\n");
                                             return ywhile;   
                                          }
[wW][rR][iI][tT][eE]                      {   
                                             printf("%i   ", ywrite);
                                             printf("ywrite\n");
                                             return ywrite;   
                                          }
[wW][rR][iI][tT][eE][lL][nN]              {   
                                             printf("%i   ", ywriteln);
                                             printf("ywriteln\n");
                                             return ywriteln;   
                                          }
{IDENTIFIER}                              {   
                                             printf("%i   ", yident);
                                             printf("yident");
                                             printf("   %s\n", yytext);
                                             return yident;
                                          }   
{COMMENT}                                 {   
                                             printf("%s   \n", yytext);
                                             return   -1;
                                          }
{WHITESPACE}                              { /* discard */ }
.                                         {   
                                             printf("%i   ", yunknown);
                                             printf("yunknown\n");
                                             return yunknown;
                                          }
%%


/* ======================== main ======================================== */ 
 /**
 *   @brief Processes stdin, and prints the token's string representation
 *   and its associated value.
 */
/* ====================================================================== */
   int main (int argc, char **argv)
   {   
      /* Process file until EOF (i.e. yywrap() returns 0) */
      int token;
      while ((token = yylex()) != 0);

      /* Houston we have lift off */
      return 0;
   }   /* end main() */

