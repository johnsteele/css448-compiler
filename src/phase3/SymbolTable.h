/******************************************************************************
 * @file SymbolTable.h                                                        *
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
 * 	- TODO: More assumptions
 */
//-----------------------------------------------------------------------------

#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_


#include <iostream>
#include <fstream>

/**
 * @namespace std
 */
using namespace std;

#include "Bstree.h"
#include "IdentifierRecord.h"


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
	 * Preconditions: The ident_name is non-NULL.
	 *
	 * Postconditions: True is returned if the identifier was added, false
	 *                 otherwise.
	 *
	 * @param ident A pointer to an IdentifierRecord.
	 * @param scope The scope of the identifier (0 for global).
	 * @return True if identifier was added, false otherwise.
 	 */
	bool addSymbol (const IdentifierRecord* ident, int scope);


	//---------------------printTable------------------------------------------
	/**
 	 * @brief Prints this symbol table.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This symbol table was printed to the standard output.
 	 */
	void printTable () const;


/**
 * @private
 */
private:

	/**
	 * @brief The node stored in the tree.
	 */
	struct Node {
		int scope;
		BSTree* identTree;
		Node* sibling;
		Node* parent;
	};


	/**
	 * @brief The root of the identifier records.
	 */
	Node* root;


	//---------------------init_symbolTable------------------------------------
	/**
	 * @brief Initializes this symbol table.
	 *
	 * Preconditions:
	 *
	 * Postconditions:
	 */
	void init_symbolTable ();
};

#endif /* SYMBOLTABLE_H_ */
