/**
 *  @file main.cpp
 *
 * @brief CSS 448 - Compiler Phase 3 - Symbol Table
 *
 * @author John Steele      \<steelejr@u.washington.edu\>
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>
 *
 * @version 1.0.0
 * @date April 30, 2011
 *
 * @brief This is the compiler "main" driver.
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

#include "SymbolTable.h"
#include "IdentifierRecord.h"
#include "IntRecord.h"
#include "ProcedureRecord.h"

int main(void) {

	cout << "=================== Started parsing ===================" << endl;

	// Just checking to ensure everything can be created and deleted.
	SymbolTable * symbolTable = new SymbolTable ();
	IdentifierRecord *rec     = new IntRecord ();
	IdentifierRecord *func    = new ProcedureRecord ();
	BSTree *tree              = new BSTree ();




	delete rec;
	delete func;
	delete tree;
	delete symbolTable;

	cout << "=================== Finished parsing ==================" << endl;
	return EXIT_SUCCESS;
}
