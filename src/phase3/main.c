extern int yyparse();
#include    <stdio.h> 

int main (int argc, char **argv) 
{
    yyparse();
    printf ("**** Parsed! ****\n"); 
    return 0;
}

