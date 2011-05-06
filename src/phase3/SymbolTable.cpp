/******************************************************************************
 * @file SymbolTable.cpp                                                      *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - Symbol Table                           *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date April 30, 2011                                                       *
 *                                                                            *
 * @brief SymbolTable class is responsible for managing a compilers           *
 *        identifier symbols. The table uses lists of lists.                  *
 *                                                                            *
 *                                                                            *
 * program A            Consider the code in procedure F.                     *
 *  |   var x, y, z      If you access x, you use the x defined there, in F.  *
 *  |                    If you access y, you need to use the y defined in D. *
 *  |   procedure B      If you access z, you need to use the z defined in A. *
 *  |   |                                                                     *
 *  |   |__                                  A                                *
 *  |   procedure C                      /  / \  \                            *
 *  |   |                               B  C   D  G                           *
 *  |   |__                                   / \                             *
 *  |   procedure D                          E   F                            *
 *  |   |   var x, y                                                          *
 *  |   |   procedure E  Scope is maintained via the relationship from parent *
 *  |   |   |            to child. Within each scope you have some data       *
 *  |   |   |__          structure (binary search tree) that holds all the    *
 *  |   |   procedure F  identifiers in that scope.                           *
 *  |   |   |   var x                                                         *
 *  |   |   |__                                                               *
 *  |   |__                                                                   *
 *  |   procedure G                                                           *
 *  |   |                                                                     *
 *  |   |__                                                                   *
 *  |___                                                                      *
 *                                                                            *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows adding a IdentifierRecord object.
 * 	- Allows removing a IdentifierRecord object.
 * 	- Allows searching for an IdentifierRecord object.
 *
 * Assumptions:
 * 	- The IdentifierRecord objects are not NULL when adding them.
 * 	- When adding, removing, or searching for an identifier, an identifier
 * 	  is equal if the name and type match (if procedure, params must match).
 * 	  TODO: Not sure, this needs to get figured out.
 */
//-----------------------------------------------------------------------------

#include "SymbolTable.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a SymbolTable with default values.
 *
 * Preconditions: None.
 *
 * Postconditions: This SymbolTable was created with the default values.
 */
SymbolTable::SymbolTable() {
	rootScope    = NULL;
	currentScope = NULL;
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated memory.
 *
 * Preconditions: None.
 *
 * Postconditions: All dynamic memory has been released.
 */
SymbolTable::~SymbolTable() {

	// TODO: Delete the table.

	delete rootScope;
	rootScope    = NULL;
	currentScope = NULL;
}


//---------------------addSymbol-----------------------------------------------
/**
 * @brief Attempts to add the provided identifier to this symbol table.
 *        If the identifier already exists within the same scope false is
 *        returned.
 *
 * Preconditions: ident is non-NULL.
 *
 * Postconditions: True is returned if the identifier was added, false
 *                 otherwise.
 *
 * @param ident A pointer to the name of the identifier.
 * @return True if identifier was added, false otherwise.
 */
bool SymbolTable::addSymbol(const IdentifierRecord* ident) {
	bool result = false;

	return result;
}


//---------------------lookup--------------------------------------------------
/**
 * @brief Does a lookup for the provided IdentifierRecord. If it is not
 *        in the current scope, a lookup is done on all the scopes above
 *        the current. Returns false if the identifier is not in the
 *        current or above scopes.
 *
 * Preconditions: ident is non-NULL.
 *
 * Postconditions: Returns true if the identifier is found in either the
 *                 current or above scopes.
 *
 * @param ident A pointer to an IdentifierRecord.
 * @return True if the identifier was found, false otherwise.
 */
bool SymbolTable::lookup (const IdentifierRecord* ident) const {
	bool result = false;

	return result;
}


//---------------------retrieve------------------------------------------------
/**
 * @brief Retrieves the provided identifier from this symbol table. Returns
 *        NULL if the identifier was not found.
 *
 * Preconditions: ident is non-NULL.
 *
 * Postconditions: Returns the identifier if found, NULL otherwise.
 *
 * @param ident A pointer to an IdentifierRecord.
 * @return The identifier if found, NULL otherwise.
 */
IdentifierRecord * SymbolTable::retrieve (const IdentifierRecord* ident) const {

	return NULL;
}


//---------------------enterScope----------------------------------------------
/**
 * @brief Notifies the symbol table of an entry to a new scope.
 *
 * Preconditions: None.
 *
 * Postconditions: A new scope has been entered.
 *
 * @param procedure The procedure associated with the scope about to enter.
 */
void SymbolTable::enterScope (const IdentifierRecord* procedure) {

	// The new scope node we're entering.
	Node *node        = new Node ();
	node->procedure   = procedure;
	node->child       = NULL;
	node->sibling     = NULL;
	node->identifiers = NULL;

	// If root is NULL, link it in.
	if (rootScope == NULL) {
		rootScope         = node;
		rootScope->scope  = 0;
		rootScope->parent = NULL;
		// Link in current.
		currentScope = rootScope;
	}

	else {
		// Link current's child to new scope.
		currentScope->child = node;
		// Link new scope in with it's parent.
		node->parent = currentScope;
		// Increment the scope.
		node->scope = currentScope->scope + 1;
		// Move current to our new scope.
		currentScope = node;
	}
}


//---------------------exitScope-----------------------------------------------
/**
 * @brief Notifies the symbol table of an exit to the current scope.
 *
 * Preconditions: None.
 *
 * Postconditions: The current scope was exited.
 */
void SymbolTable::exitScope () {

	// We're at the root if parent is NULL.
	if (currentScope->parent != NULL)
		currentScope = currentScope->parent;
}


//---------------------printTable----------------------------------------------
/**
 * @brief Prints this symbol table.
 *
 * Preconditions: None.
 *
 * Postconditions: This symbol table was printed to the standard output.
 */
void SymbolTable::printTable() const {
	cout << "*********** SymbolTable::printTable() - Start  ***************";
	printTableHelper ();
	cout << "*********** SymbolTable::printTable() - Finish ***************";
}


//---------------------printTableHelper----------------------------------------
/**
 * @brief A helper method that prints this symbol table.
 *
 * Preconditions: None.
 *
 * Postconditions: This symbol table was printed to the standard output.
 */
void SymbolTable::printTableHelper () const {

}

