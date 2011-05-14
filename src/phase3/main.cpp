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
#include "ProcedureRecord.h"
#include "ConstantRecord.h"
#include "Parameter.h"
#include "ArrayType.h"
#include "PointerType.h"
#include "SITtype.h"
#include "SITtable.h"
#include "SetType.h"
#include "RecordType.h"
#include "TypeRecord.h"

extern int yyparse();
#define DEBUG 1
int main(void) {

	SITtable *table = new SITtable ();
	bool found = table->lookup("true");
	if (found) cout << "Found: " << found << endl;
	else   cout << "Not Found: " << found << endl;
	delete table;


	cout << "=================== Started parsing ===================" << endl;
	// yyparse();
	cout << "=================== Finished parsing ==================" << endl;

#if DEBUG
	cout << "=============== Start Print Symbol Table ==============" << endl;

	SymbolTable * symbolTable = new SymbolTable ();

	IdentifierRecord *proc    = new ProcedureRecord ("program1");
	IdentifierRecord *proc1   = new ProcedureRecord ("function1");
	IdentifierRecord *proc2   = new ProcedureRecord ("function2");
	IdentifierRecord *proc3   = new ProcedureRecord ("function3");
	IdentifierRecord *proc4   = new ProcedureRecord ("function4");
	IdentifierRecord *proc5   = new ProcedureRecord ("function5");
	IdentifierRecord *proc6   = new ProcedureRecord ("function6");
	IdentifierRecord *proc7   = new ProcedureRecord ("function7");
	IdentifierRecord *proc8   = new ProcedureRecord ("function8");
	IdentifierRecord *proc9   = new ProcedureRecord ("function9");


	IdentifierRecord *ptr1     = new PointerType ("ptrVal");
	IdentifierRecord *ptr2     = new PointerType ("ptrVal2");
	IdentifierRecord *ptr3     = new PointerType ("ptrVal3");
	IdentifierRecord *ptr4     = new PointerType ("ptrVal4");
	IdentifierRecord *ptr5     = new PointerType ("ptrVal5");
	IdentifierRecord *ptr6     = new PointerType ("ptrVal6");
	IdentifierRecord *ptr7     = new PointerType ("ptrVal7");

	IdentifierRecord *array1     = new ArrayType ("array1Val");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array1);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				char * val = "a";
				r.setLowDimension(atoi (val));
				r.isAscii();
				val = "b";
				r.setHighDimension(atoi (val));
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array2     = new ArrayType ("array2Val2");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array2);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array3     = new ArrayType ("array3Val3");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array3);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array4     = new ArrayType ("array4Val4");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array4);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array5     = new ArrayType ("array5Val5");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array5);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array6     = new ArrayType ("array6Val6");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array6);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}
	IdentifierRecord *array7     = new ArrayType ("array7Val7");
	try {
				ArrayType &r = dynamic_cast<ArrayType &> (*array7);
				r.setLowDimension(1);
				r.setHighDimension(5);
				r.setLowDimension(2);
				r.setHighDimension(6);
				r.setLowDimension(3);
				r.setHighDimension(7);
			} catch (exception &e) {
				cout << "Exception: " << e.what() << endl;
			}









	IdentifierRecord *const1     = new ConstantRecord ("constVal1");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const1);
			r.setConstFactor(5);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}

	IdentifierRecord *const2     = new ConstantRecord ("constVal2");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const2);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}
	IdentifierRecord *const3     = new ConstantRecord ("constVal3");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const3);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}
	IdentifierRecord *const4     = new ConstantRecord ("constVal4");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const3);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}
	IdentifierRecord *const5     = new ConstantRecord ("constVal5");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const5);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}
	IdentifierRecord *const6     = new ConstantRecord ("constVal6");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const6);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}
	IdentifierRecord *const7     = new ConstantRecord ("constVal7");
	try {
			ConstantRecord &r = dynamic_cast<ConstantRecord &> (*const7);
			r.setConstFactor(6);
		} catch (exception &e) {
			cout << "Exception: " << e.what() << endl;
		}


	IdentifierRecord *param1     = new Parameter ("paramVal1");
	IdentifierRecord *param2     = new Parameter ("paramVal2");
	IdentifierRecord *param3     = new Parameter ("paramVal3");
	IdentifierRecord *param4     = new Parameter ("paramVal4");
	IdentifierRecord *param5     = new Parameter ("paramVal5");
	IdentifierRecord *param6     = new Parameter ("paramVal6");
	IdentifierRecord *param7     = new Parameter ("paramVal7");


	symbolTable->enterScope(proc);   // enter the program.
	bool result = symbolTable->addSymbol(const1);  // add const1
	result      =  symbolTable->addSymbol(const2); // add const2
	result      =  symbolTable->addSymbol(array1); // add array1
	result      =  symbolTable->addSymbol(array2); // add array2


	symbolTable->enterScope(proc1);  // enter function1
	result      =  symbolTable->addSymbol(const3); // add const3
	result      =  symbolTable->addSymbol(const4); // add const4
	result      =  symbolTable->addSymbol(array3); // add array3
	result      =  symbolTable->addSymbol(array4); // add array4
	symbolTable->enterScope(proc2);  // enter function2

	symbolTable->exitScope();        // exit function2
	symbolTable->exitScope();        // exit function1

	symbolTable->enterScope(proc3);  // enter function3
	result      =  symbolTable->addSymbol(const5); // add const5
	result      =  symbolTable->addSymbol(array5); // add array5
	symbolTable->exitScope();        // exit  function3

	symbolTable->enterScope(proc4);  // enter function4
	symbolTable->exitScope();        // exit  function4

	symbolTable->enterScope(proc5);  // enter function5
	symbolTable->enterScope(proc6);  // enter function6
	symbolTable->enterScope(proc7);  // enter function7
	result      =  symbolTable->addSymbol(const6); // add const6
	result      =  symbolTable->addSymbol(const7); // add const7
	result      =  symbolTable->addSymbol(array6); // add array6
	result      =  symbolTable->addSymbol(array7); // add array7



	symbolTable->exitScope();        // exit  function5
	symbolTable->exitScope();        // exit  function6
	symbolTable->exitScope();        // exit  function7

	symbolTable->enterScope(proc8);  // enter function8
	symbolTable->enterScope(proc9);  // enter function9

	symbolTable->exitScope();        // exit  function8
	symbolTable->exitScope();        // exit  function9


	symbolTable->exitScope();

	symbolTable->printTable();
	delete symbolTable;

	cout << "=============== End Print Symbol Table ==============" << endl;

#endif
	return EXIT_SUCCESS;
}
