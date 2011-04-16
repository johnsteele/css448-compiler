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
{IDENTIFIER}                              { return yident; }   
{COMMENT}                                 { return   -1; }
{WHITESPACE}                              { /* discard */ }
.                                         { return yunknown; }
%%



    /* ======================== printToken ================================== */ 
    /**
     *   @brief A helper method to print the provided token and it's 
     *          associated string representation. If the token corresponds
     *          to a number, string, or identifier it is printed as well.  
     */
    /* ====================================================================== */ 
    void printToken(int tkn, char data[], char* txt);


    /* ======================== main ======================================== */ 
    /**
     *   @brief Processes stdin, and prints the token's string representation
     *   and its associated value.
     */
    /* ====================================================================== */ 
   int main (int argc, char **argv)
   {   
      
      char data[50];
      /* Process file until EOF (i.e. yywrap() returns 0) */
      int token;
      while ((token = yylex()) != 0)
         printToken(token, data, yytext);
   
      /* Houston we have lift off */
      return 0;
   }   /* end main() */


    /* ======================== printToken ================================== */ 
    /**
     *   @brief A helper method to print the provided token and it's 
     *          associated string representation. If the token corresponds
     *          to a number, string, or identifier it is printed as well.  
     */
    /* ====================================================================== */ 
    void printToken(int tkn, char data[], char* txt)
    { 
        
        switch (tkn){
         case 257:
            data = "yand";
            break;
         case 258:
            data = "yarray";
            break;
         case 259:
            data = "yassign";
            break;
         case 260: 
            data = "ybegin";
            break;
         case 261:
            data = "ycarat";
            break;
         case 262:
            data = "ycase";
            break;
         case 263:
            data = "ycolon";
            break;
         case 264:
            data = "ycomma";
            break;
         case 265:
            data = "yconst";
            break;
         case 266:
            data = "ydispose";
            break;
         case 267:
            data = "ydiv";
            break;
         case 268:
            data = "ydivide";
            break;
         case 269:
            data = "ydo";
            break;
         case 270:
            data = "ydot";
            break;
         case 271:
            data = "ydotdot";
            break;
         case 272:
            data = "ydownto";
            break;
         case 273:
            data = "yelse";
            break;
         case 274:
            data = "yend";
            break;
         case 275:
            data = "yequal";
            break;
         case 276:
            data = "yfalse";
            break;
         case 277:
            data = "yfor";
            break;
         case 278:
            data = "yfunction";
            break;
         case 279:
            data = "ygreater";
            break;
         case 280:
            data = "ygreaterequal";
            break;
         case 281:
            data = "yident";
            break;
         case 282:
            data = "yif";
            break;
         case 283:
            data = "yin";
            break;
         case 284:
            data = "yleftbracket";
            break;
         case 285:
            data = "yleftparen";
            break;
         case 286:
            data = "yless";
            break;
         case 287:
            data = "ylessequal";
            break;
         case 288:
            data = "yminus ";
            break;
         case 289:
            data = "ymod ";
            break;
         case 290:
            data = "ymultiply";
            break;
         case 291:
            data = "ynew";
            break;
         case 292:
            data = "ynil";
            break;
         case 293:
            data = "ynot";
            break;
         case 294:
            data = "ynotequal";
            break;
         case 295:
            data = "ynumber";
            break;
         case 296:
            data = "yof";
            break;
         case 297:
            data = "yor";
            break;
         case 298:
            data = "yplus";
            break;
         case 299:
            data = "yprocdure";
            break;
         case 300:
            data = "yprogram";
            break;
         case 301:
            data = "yread";
            break;
         case 302:
            data = "yreadln";
            break;
         case 303:
            data = "yrecord";
            break;
         case 304:
            data = "yrepeat";
            break;
         case 305:
            data = "yrightbracket";
            break;
         case 306:
            data = "yrightparen";
            break;
         case 307:
            data = "ysemicolon";
            break;
         case 308:
            data = "yset";
            break;
         case 309:
            data = "ystring";
            break;
         case 310:
            data = "ythen";
            break;
         case 311:
            data = "yto";
            break;
         case 312:
            data = "ytrue";
            break;
         case 313:
            data = "ytype";
            break;   
         case 314:
            data = "yuntil";
            break;
         case 315:
            data = "yvar";
            break;
         case 316:
            data = "ywhile";
            break;
         case 317:
            data = "ywrite";
            break;
         case 318:
            data = "ywriteln";
            break;
         case 319:
            data = "yunknown";
            break;
         default:
            data = "";
            break;
      }

      if(tkn != -1){
         printf("%i   %s   ", tkn, data);
    
         if(tkn == 295 || tkn == 281 || tkn == 309 )
            /* Number, Identifier, or String.  */
            printf("%s", txt);
         printf(" \n");
      }

      
      if(tkn == -1){
         printf("%s   \n", txt);
      }
   } /* end printToken () */

