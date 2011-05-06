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

	SymbolTable * symbolTable = new SymbolTable ();
	IdentifierRecord *rec     = new IntRecord ("intVal");
	IdentifierRecord *proc1    = new ProcedureRecord ("program1");
	IdentifierRecord *proc2    = new ProcedureRecord ("function1");
	IdentifierRecord *proc3    = new ProcedureRecord ("function2");
	IdentifierRecord *proc4    = new ProcedureRecord ("function3");

	symbolTable->enterScope(proc1);
	symbolTable->enterScope(proc2);
	symbolTable->enterScope(proc3);
	symbolTable->enterScope(proc4);

	symbolTable->printTable();

	delete rec;
	delete proc1;
	delete proc2;
	delete proc3;
	delete proc4;
	delete symbolTable;

	cout << "=================== Finished parsing ==================" << endl;
	return EXIT_SUCCESS;
}
