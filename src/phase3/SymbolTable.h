/**
 * @file SymbolTable.h
 *
 * @brief CSS 448 - Compiler Phase 3 - Symbol Table
 *
 * @author John Steele  \<steelejr@u.washington.edu\>
 * @author Alicia ...
 *
 * @version 1.0.0
 * @date November 9, 2010
 *
 * @brief SymbolTable class is responsible for managing the compilers
 *   	  identifier symbols (IdentifierSymbol). It uses a hash table
 *   	  to store each identifier. A second vector is used to
 *   	  maintain the scope (level) of the identifiers. The figure
 *   	  below shows the relationship:
 *
 *   	  			   	       Scope Vector
 *   	             [*][*][*][*][*][*][*][*][*][*][*]
 *
 *		  H  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  a  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  s  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  h  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		     [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  T  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  a  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  b  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  l  [*]--> [identifierRecord]--> [identifierRecord] ...
 *		  e  [*]--> [identifierRecord]--> [identifierRecord] ...
 *
 *
 *		  Scope Vector:
 *
 *		  - Each index of the Scope vector corresponds to the scope of
 *		    the identifiers (0 for global identifiers). Each index of
 *		    the vector has a pointer to the list of identifiers in that
 *		    scope. The objects are the same objects within the identifier
 *		    hash table, therefore it is not responsible for the memory.
 *
 *		  - The scope vector could be removed if each identifier record
 *		    were to maintain a variable to store their scope; however,
 *		    this seems to be less efficient since one would have to keep
 *		    traversing just to check the scope.
 *
 *		  - Function parameters are considered part of the function's
 *		    inner scope.
 *
 *		  - The scope vector needs to be updated whenever a symbol is added
 *		    or removed from the hash table to prevent a dangling pointer.
 *
 *
 *		  Hash Table:
 *
 *		  - Each index of the hash table is a pointer to a doubly-linked list
 *		    of all the identifiers which hashed to that location.
 *
 *		  - If a collision occurs, the identifier element is added to the front
 *		    of the doubly-linked list at that index of the table.
 */
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows adding a IdentifierRecord object.
 * 	- Allows removing a IdentifierRecord object.
 * 	- Allows finding a IdentifierRecord object.
 *
 * Assumptions:
 * 	- The Customers, Transactions, and Items are not NULL when
 *	  adding them.
 */
//--------------------------------------------------------------------

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_


#include <iostream>
#include <vector>
#include "IdentifierRecord.h"

/**
 * @namespace std
 */
using namespace std;

/**
 * @class SymbolTable
 */
class SymbolTable {


/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a SymbolTable with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This SymbolTable was created with the default
	 *		           values.
	 */
	SymbolTable();


	//---------------------Destructor-----------------------------
	/**
 	 * @brief Deletes all dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: All dynamic memory has been released.
 	 */
	virtual ~SymbolTable();


/**
 * @private
 */
private:



	/**
	 * @brief
	 */
	vector<IdentifierRecord *> *scopeTable;
	vector<IdentifierRecord *> *IdenthashTable;
};

#endif /* SYMBOLTABLE_H_ */
