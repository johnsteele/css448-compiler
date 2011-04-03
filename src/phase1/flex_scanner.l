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

    /* Numbers are unsigned. */
DIGIT           [0-9]

    /* Spaces, tabs, and newlines. */
WHITESPACE      [ \t\n]

    /* Anything EXCEPT whitespace or newline. */
CHARACTER       [^ \t\n] 

    /* A sequence of digits, and must not contain spaces. */
    /* INTEGER */

    /* One-or-more digits, decimal, one-or-more digits, optional exponent. */
REAL            [0-9]+"."[0-9]+([eE][0-9]+)* 


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
"Dispose"       { return ydispose;      } 
"div"           { return ydiv;          }
"/"             { return ydivide;       } 
"do"            { return ydo;           }
"."             { return ydot;          }
".."            { return ydotdot;       }
"downto"        { return ydownto;       }
"else"          { return yelse;         }
"end"           { return yend;          }
"="             { return yequal;        }
"False"         { return yfalse;        }
"for"           { return yfor;          }
"function"      { return yfunction;     }
">"             { return ygreater;      }
">="            { return ygreaterequal; }
    /* return yident;  identifier --> letter { letter | digit } */
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
"nil"           { return ynil;          }  
"not"           { return ynot;          }
"<>"            { return ynotequal;     }
    /* return ynumber; number --> integer | real  */
"of"            { return yof;           }
"or"            { return yor;           }
"+"             { return yplus;         }
"procedure"     { return yprocedure;    }
"program"       { return yprogram;      }
"Read"          { return yread;         }
"Readln"        { return yreadln;       }
"record"        { return yrecord;       }
"repeat"        { return yrepeat;       }
"}"             { return yrightbracket; }
")"             { return yrightparen;   }
";"             { return ysemicolon;    }
"set"           { return yset;          } 
    /* return ystring;  string --> ' " ' {character} ' " ' | " ' " {character} " ' " */
"then"          { return ythen;         }
"to"            { return yto;           } 
"True"          { return ytrue;         } 
"type"          { return ytype;         }
"unit"          { return yuntil;        } 
"var"           { return yvar;          } 
"while"         { return ywhile;        }
"Write"         { return ywrite;        } 
"Writelen"      { return ywriteln;      } 
.               { return yunknown;      } 
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
    while ((token = yylex()) != 0) printf ("Token : %s (%i)\n", yytext, token); 

    /* Houston we have lift off */
    return 0;
 } /* end main () */

