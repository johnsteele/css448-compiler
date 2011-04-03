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
     **************************************************************************/

    /* Finish after EOF. */
%option noyywrap 


    /* Header with token declarations. */
%{
#include "tokenconst.h"    
%}
    

    /* ======================== Definition Section ========================== */




    /* ======================== Rules Section =============================== */
%% 

"and"           { return yand;          }
"array"         { return yarray;        } 
":="            { return yassign;       } 
"begin"         { return ybegin;        } 
"^"             { return ycaret;        }
"case"          { return ycase;         }
":"             { return ycolon;        }
","             { return ycomma;        }
"const"         { return yconst;        }
    /* return ydispose; */

    /* TODO: Not sure if I have the division ass backwards */
"div"           { return ydiv;          } 
"/"             { return ydivide;       }

"do"            { return ydo;           }
"."             { return ydot;          }
".."            { return ydotdot;       }
    /* return ydownto;  */
"else"          { return yelse;         }
    /* return yend;     */
"="             { return yequal;        }
"false"         { return yfalse;        }
"for"           { return yfor;          }
"function"      { return yfunction;     }
">"             { return ygreater;      }
">="            { return ygreaterequal; }
    /* return yident;   */
"if"            { return yif;           }
"in"            { return yin;           } 
"{"             { return yleftbracket;  }
"("             { return yleftparen;    }
"<"             { return yless;         }
"<="            { return ylessequal;    }
"-"             { return yminus;        }
"mod"           { return ymod;          }
"*"             { return ymultiply;     }
"new"           { return ynew;          }
    /* return ynil;     */
"not"           { return ynot;          }
"<>"            { return ynotequal;     }
    /* return ynumber;  */
    /* return yof;      */
"or"            { return yor;           }
"+"             { return yplus;         }
    /*return yprocedure;*/
    /* return yprogram; */
    /* return yread;    */
    /* return yreadln;  */
    /* return yrecord;  */
    /* return yrepeat;  */
"}"             { return yrightbracket; }
")"             { return yrightparen;   }
";"             { return ysemicolon;    }
    /* return yset;     */
    /* return ystring;  */
    /* return ythen;    */
    /* return yto;      */
    /* return ytrue;    */
    /* return ytype;    */
    /* return yuntil;   */
    /* return yvar;     */
"while"         { return ywhile;        }
    /* return ywrite;   */
    /* return ywriteln; */
.               { return yunknown;      }

%%

    /* ======================== Subroutine Section ========================== */



/**
 * @brief main processes the input file. 
 */
int main (int argc, char **argv)
{
    /* Skip over the program name. */
    ++argv, --argc; 


    /* Open the file. */
    if (argc > 0) yyin = fopen (argv [0], "r");
    else          yyin = stdin;


    /* Process file until EOF (i.e. yywrap() returns 0) */
    while (yylex() != 0) printf ("Token : %s\n", yytext); 


    /* Houston we have lift off */
    return 0;
} /* end main () */

