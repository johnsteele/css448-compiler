/**
 * @file SymbolTable.h
 *
 * @brief CSS 448 - Compiler Phase 3 - Symbol Table
 *
 * @author John Steele      \<steelejr@u.washington.edu\>
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>
 *
 * @version 1.0.0
 * @date April 30, 2011
 *
 * @brief SymbolTable class is responsible for managing a compilers
 *   	  identifier symbols. It uses a hash table to store each
 *   	  identifier. A second array is used to maintain the scope
 *   	  (level) of the identifiers.
 *
 *		  Scope Array:
 *
 *		  - Each index of the scope array corresponds to the scope of
 *		    the identifiers (0 for global identifiers). Each index of
 *		    the array has a pointer to the list of identifiers in that
 *		    scope.
 *
 *		  - The scope array could be removed if each identifier record
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
 *		  - TODO: More about how scope is managed.
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
 * 	- Allows searching for an IdentifierRecord object.
 * 	- TODO: Perhaps allow for clearing a scope and empty the table.
 *
 * Assumptions:
 * 	- The IdentifierRecord objects are not NULL when adding them.
 * 	- TODO: More assumptions
 */
//--------------------------------------------------------------------
#include "SymbolTable.h"


//---------------------Constructor----------------------------
/**
 * @brief Creates a SymbolTable with default values.
 *
 * Preconditions: None.
 *
 * Postconditions: This SymbolTable was created with the default
 *		           values.
 */
SymbolTable::SymbolTable() {
	identifierTable = new HashTable ();
	scopeArray      = new IdentifierRecord *[DEFAULT_SIZE + 1];
}


//---------------------Destructor-----------------------------
/**
	 * @brief Deletes all dynamically allocated memory.
 *
 * Preconditions: None.
 *
 * Postconditions: All dynamic memory has been released.
	 */
SymbolTable::~SymbolTable() {

	delete identifierTable;
	delete [] scopeArray;

}
