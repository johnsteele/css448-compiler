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

	emptyTable(rootScope);
	rootScope    = NULL;
	currentScope = NULL;
}


//---------------------emptyTable----------------------------------------------
/**
 * @brief Deletes all dynamic memory in the table.
 *
 * Preconditions: root points to the top-most Node of the list of lists.
 *
 * Postconditions: The symbol table is empty, root is NULL.
 *
 * @param the_root The current root.
 */
void SymbolTable::emptyTable (Node * the_root) {
	if (the_root == NULL) return;

	emptyTable (the_root->child);
	emptyTable (the_root->sibling);

	delete the_root->identifiers;
	delete the_root->procedure;
	delete the_root;
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
bool SymbolTable::addSymbol(IdentifierRecord * ident) {
	bool inserted = false;

	// Is this the first symbol being added.
	if (currentScope->identifiers == NULL) {
		currentScope->identifiers = new BSTree ();
	}

	inserted = currentScope->identifiers->insert(ident);

	return inserted;
}


//---------------------lookup--------------------------------------------------
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
bool SymbolTable::lookup (string ident) const {
	if (rootScope == NULL)    return false;
	if (currentScope == NULL) return false;
	return lookupHelper(currentScope, ident);
}


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
bool SymbolTable::lookupHelper (const Node * root, string ident) const {

	if (root == NULL) return false;
	bool result = false;

	// First check current scope identifier tree.
	result = root->identifiers->lookup(ident);

	// If not in current scope identifier tree,
	// then check the current scope function parameters.
	if (result == false) {
		result = root->procedure->lookup(ident);
	}

	// If not in current scope's identifier tree, and it's not in the
	// functions parameter list, then go up to the next scope.
	if (result == false) {
		lookupHelper(root->parent, ident);
	}

	// It was found.
	return true;
}


//---------------------retrieve------------------------------------------------
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
IdentifierRecord * SymbolTable::retrieve (string ident) const {
	if (rootScope == NULL)    return false;
	if (currentScope == NULL) return false;
	return retrieveHelper(currentScope, ident);
}


//---------------------retrieveHelper------------------------------------------
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
IdentifierRecord * SymbolTable::retrieveHelper (const Node * root,
													string ident) const {

	if (root == NULL) return NULL;
	IdentifierRecord * result = NULL;

	// First check current scope identifier tree.
	result = root->identifiers->retrieve(ident);

	// If not in current scope identifier tree,
	// then check the current scope function parameters.
	if (result == NULL) {
		result = root->procedure->retrieve(ident);
	}

	// If not in current scope's identifier tree, and it's not in the
	// functions parameter list, then go up to the next scope.
	if (result == NULL) {
		lookupHelper(root->parent, ident);
	}

	// It was found.
	return result;
}


//---------------------lookupScope---------------------------------------------
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
bool SymbolTable::lookupScope (string ident) const {
	if (currentScope == NULL || rootScope == NULL)
		return false;

	bool result = false;

	// First check current scope identifier tree.
	result = currentScope->identifiers->lookup(ident);

	// If not in current scope identifier tree,
	// then check the current scope function parameters.
	if (result == false) {
		result = currentScope->procedure->lookup(ident);
	}

	return result;
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
void SymbolTable::enterScope (const ProcedureRecord * procedure) {
	
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

	// Otherwise, it's a sibling to existing scope or new scope.
	else {

		// If it's a sibling to an already existing scope.
		if (currentScope->child != NULL) {
			Node *rightSib = currentScope->child;

			// Get the farthest right sibling.
			while (rightSib->sibling != NULL) {
				rightSib = rightSib->sibling;
			}

			// We're at the farthest right node, so link it in.
			rightSib->sibling = node;

			// Link the parent to the current scope.
			node->parent = currentScope;
			node->scope = currentScope->scope + 1;

			// Set current to the new scope.
			currentScope = node;
		}

		// Otherwise, it's the first child of a new scope.
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
}


//---------------------exitScope-----------------------------------------------
/**
 * @brief Notifies the symbol table of an exit to the current scope.
 *
 * Preconditions: This method cannot be called if enterScope has not already
 *                been called.
 *
 * Postconditions: The current scope was exited.
 */
void SymbolTable::exitScope () {
	if (currentScope != NULL)
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
	printTableHelper (rootScope);
}


//---------------------printTableHelper----------------------------------------
/**
 * @brief A helper method that prints this symbol table.
 *
 * Preconditions: None.
 *
 * Postconditions: This symbol table was printed to the standard output.
 *
 * @param root The root at which to print siblings and children.
 */
void SymbolTable::printTableHelper (const Node * root) const {
	if (root == NULL) return;
	root->procedure->print(root->scope);
	cout << endl;
	if (root->identifiers != NULL)
		root->identifiers->print(root->scope + 1);
	else
		cout << endl;
	printTableHelper(root->child);
	printTableHelper(root->sibling);
}

