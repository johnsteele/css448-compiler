/******************************************************************************
 * @file SymbolTable.h                                                        *
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
 * program A             Consider the code in procedure F.                    *
 *  |   var x, y, z       If you access x, you use the x defined there, in F. *
 *  |                     If you access y, you need to use the y defined in D.*
 *  |   procedure B       If you access z, you need to use the z defined in A.*
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

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_


#include <iostream>
#include <fstream>
#include <iomanip>

/**
 * @namespace std
 */
using namespace std;

#include "Bstree.h"
#include "IdentifierRecord.h"
#include "ProcedureRecord.h"


/**
 * @class SymbolTable
 */
class SymbolTable {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a SymbolTable with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This SymbolTable was created with the default values.
	 */
	SymbolTable();


	//---------------------Destructor------------------------------------------
	/**
 	 * @brief Deletes all dynamically allocated memory.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: All dynamic memory has been released.
 	 */
	~SymbolTable();


	//---------------------addSymbol-------------------------------------------
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
	 * @param ident A pointer to an IdentifierRecord.
	 * @return True if identifier was added, false otherwise.
 	 */
	bool addSymbol (IdentifierRecord* ident);


	//---------------------lookup----------------------------------------------
	/**
 	 * @brief Does a lookup for the provided identifier name. If it is not
 	 *        in the current scope, a lookup is done on all the scopes above
 	 *        the current. Returns false if the identifier is not in the
 	 *        current or above scopes.
	 *
	 * Preconditions: current scope is not NULL.
	 *
	 * Postconditions: Returns true if the identifier is found in either the
	 *                 current or above scopes.
	 *
	 * @param ident The name of the identifier to search for.
	 *
	 * @return True if the identifier was found, false otherwise.
 	 */
	bool lookup (string ident) const;


	//---------------------lookupScope-----------------------------------------
	/**
 	 * @brief Does a lookup for the provided identifier name only in the
 	 *        current scope. If it is not in the current scope false is
 	 *        returned.
	 *
	 * Preconditions: current scope is not NULL.
	 *
	 * Postconditions: Returns true if the identifier is found in current
	 *                 scope.
	 *
	 * @param ident The name of the identifier to search for.
	 *
	 * @return True if the identifier was found, false otherwise.
 	 */
	bool lookupScope (string ident) const;


	//---------------------retrieve--------------------------------------------
	/**
 	 * @brief Retrieves the provided identifier from this symbol table. Returns
 	 *        NULL if not found.
	 *
	 * Preconditions: current scope is not NULL.
	 *
	 * Postconditions: Returns the identifier if found, NULL otherwise.
	 *
	 * @param ident The name of the identifier to search for.
	 *
	 * @return The identifier if found, NULL otherwise.
 	 */
	IdentifierRecord * retrieve (string ident) const;


	//---------------------printTable------------------------------------------
	/**
 	 * @brief Prints this symbol table.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This symbol table was printed to the standard output.
 	 */
	void printTable () const;


	//---------------------enterScope------------------------------------------
	/**
 	 * @brief Notifies the symbol table of an entry to a new scope.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: A new scope has been entered.
 	 */
	void enterScope (const ProcedureRecord * procedure);


	//---------------------exitScope-------------------------------------------
	/**
 	 * @brief Notifies the symbol table of an exit to the current scope.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The current scope was exited.
 	 */
	void exitScope ();


/**
 * @private
 */
private:

	/**
	 * @brief The node stored in the tree.
	 */
	struct Node {
		const ProcedureRecord * procedure;
		int     scope;
		BSTree* identifiers;
		Node*   sibling;
		Node*   parent;
		Node*   child;
	};


	/**
	 * @brief The root of the identifier records (scope is 0).
	 */
	Node* rootScope;

	/**
	 * @brief The current node at the current scope of insertion.
	 */
	Node* currentScope;


	//---------------------init_symbolTable------------------------------------
	/**
	 * @brief Initializes this symbol table.
	 *
	 * Preconditions:
	 *
	 * Postconditions:
	 */
	void init_symbolTable ();


	//---------------------emptyTable------------------------------------------
	/**
	 * @brief Deletes all dynamic memory in the table.
	 *
	 * Preconditions: root points to the top-most Node of the list of lists.
	 *
	 * Postconditions: The symbol table is empty, root is NULL.
	 *
	 * @param the_root The current root.
	 */
	void emptyTable (Node * the_root);


	//---------------------printTableHelper------------------------------------
	/**
 	 * @brief A helper method that prints this symbol table.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This symbol table was printed to the standard output.
	 *
     * @param root The root at which to print siblings and children
 	 */
	void printTableHelper (const Node * root) const;


	//---------------------lookupHelper----------------------------------------
	/**
 	 * @brief A helper method to lookup.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: returns true if found, false otherwise.
	 *
     * @param root The root at which to search for the identifier.
     * @param ident The name of identifier to search for.
     * @return True if found, false otherwise.
 	 */
	bool lookupHelper (const Node * root, string ident) const;


	//---------------------retrieveHelper--------------------------------------
	/**
 	 * @brief Retrieves the provided identifier from this symbol table. Returns
 	 *        NULL if not found.
	 *
	 * Preconditions: current scope is not NULL.
	 *
	 * Postconditions: Returns the identifier if found, NULL otherwise.
	 *
	 * @param root The scope to search.
	 * @param ident The name of the identifier to search for.
	 *
	 * @return The identifier if found, NULL otherwise.
 	 */
	IdentifierRecord * retrieveHelper (const Node * root, string ident) const;
};

#endif /* SYMBOLTABLE_H_ */
