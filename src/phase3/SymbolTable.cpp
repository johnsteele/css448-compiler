/******************************************************************************
 * @file SymbolTable.cpp                                                      *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - Symbol Table	                          *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date April 30, 2011                                                       *
 *                                                                            *
 * @brief SymbolTable class is responsible for managing a compilers           *
 * 	      identifier symbols. The table uses lists of lists.                  *
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
 * 	- TODO: More assumptions
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
	root = new Node;
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

	root = NULL;
}


//---------------------addSymbol-----------------------------------------------
/**
 * @brief Attempts to add the provided identifier to this symbol table.
 *        If the identifier already exists within the same scope false is
 *        returned.
 *
 * Preconditions: The ident_name is non-NULL.
 *
 * Postconditions: True is returned if the identifier was added, false
 *                 otherwise.
 *
 * @param ident_name A pointer to the name of the identifier.
 * @param scope  The scope of the identifier (0 for global).
 * @return True if identifier was added, false otherwise.
 */
bool SymbolTable::addSymbol(const IdentifierRecord* ident, int scope) {
	bool result = false;

	return result;
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

}


//---------------------init_symbolTable----------------------------------------
/**
 * @brief Initializes this symbol table.
 *
 * Preconditions:
 *
 * Postconditions:
 */
void SymbolTable::init_symbolTable() {

}
