extern int yyparse();
#include    <iostream>
using namespace std; 

int main (int argc, char **argv) 
{
    yyparse();
    cout << "*** Parsed! ****" << endl; 
    return 0;
}

