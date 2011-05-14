/******************************************************************************
 * @file Bstree.h                                                             *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - Bstree    	                          *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 3, 2011                                                          *
 *                                                                            *
 * @brief This class represents a node-base binary search tree                *
 *	      data-structure, which has the following properties: The             *
 *	      left subtree of a node contains only nodes with keys less           *
 *	      than the node's key; The right subtree of a node contains           *
 *	      only nodes with keys greater than the nodes' key; Both the          *
 *	      left and right subtree must also be binary search trees.            *
 *                                                                            *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows inserting an IdentifierRecord into the tree.
 *	- Allows retrieving a specified IdentifierRecord from the tree.
 *	- Allows making the tree empty.
 * Assumptions:
 * 	- IdentifierRecord objects are not NULL when stored in the tree.
 *	- IdentifierRecord objects have overloaded operator<< for displaying.
 *	- IdentifierRecord objects have overloaded comparison operators for
 *	  sorting.
 */


#ifndef BSTREE_H
#define BSTREE_H_
#include <iostream>
#include "IdentifierRecord.h"

/**
 * @namespace std
 */
using namespace std;


/**
 * @class BSTree
 */
class BSTree {


/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a BSTree with a NULL root.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The BSTree was instantiated with its root set to NULL.
	 */
	BSTree ();


	//---------------------Copy-Constructor------------------------------------
	/**
	 * @brief Copies the other tree into this tree.
	 *
	 * Preconditions: The other trees' root points to NULL if it is empty,
	 *                otherwise the root of the tree.
	 *
 	 * Postconditions: The other tree was copied into this tree.
	 */
	BSTree (const BSTree &other);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the tree.
	 *
	 * Preconditions: makeEmpty is implemented.
	 *
	 * Postconditions: This BSTree is empty with a NULL root.
	 */
	~BSTree ();


	//---------------------lookup----------------------------------------------
	/**
	 * @brief Does a lookup for an IdentifierRecord with the provided name.
	 *        Returns true if found in the tree, false otherwise.
	 *
	 * Preconditions: The tree root is not NULL.
	 *
	 * Postconditions: Returns true if found, false otherwise.
	 *
	 * @param name The name of the identifier to lookup.
	 *
	 * @return True if found, false otherwise.
	 */
	bool lookup (string name) const;


	//---------------------retrieve--------------------------------------------
	/**
	 * @brief Retrieves a pointer to the IdentifierRecord with the provided
	 *        name. Returns a pointer to the IdentifierRecord if found,
	 *	      NULL otherwise.
	 *
	 * Preconditions: my_root points to the root of the tree, or NULL if the
	 *                tree is empty.
	 *
	 * Postconditions: Returns a pointer to the IdentifierRecord if found,
	 *                 NULL otherwise.
	 *
	 * @param name The name of the item being looked up.
	 * @return A pointer to the IdentifierRecord if found, NULL otherwise.
	 */
	IdentifierRecord * retrieve (string name) const;


	//---------------------insert----------------------------------------------
	/**
	 * @brief Inserts an IdentifierRecord into this tree.
	 *
	 * Preconditions: The item is not NULL, and there must be enough memory for
	 *                allocating the new Node.
	 *
 	 * Postconditions: The IdentifierRecord was inserted into the tree.
	 *
	 * @param ident The IdentifierRecord to insert into the tree.
	 * @return True if successfully inserted, false otherwise.
	 */
	bool insert (IdentifierRecord *ident);


	//---------------------makeEmpty-------------------------------------------
	/**
	 * @brief Empties this tree.
	 *
 	 * Preconditions: my_root points to the root of the tree or
	 *		  NULL if the tree is empty.
	 *
	 * Postconditions: The tree is empty.
	 */
	void makeEmpty ();


	//---------------------operator(=)----------------------------
	/**
	 * @brief Overloaded assignment operator.
	 *
	 * Preconditions: the_other.my_root points to the first Node
 	 *		  in the tree, or NULL.
	 *
	 * Postconditions: the_other is copied into this.
	 *
	 * @param the_other The other tree to copy into this.
	 * @return this is returned.
	 */
	const BSTree& operator= (const BSTree &the_other);


	//---------------------print-----------------------------------------------
	/**
	 * @brief Prints the contents of this tree.
	 *
	 * Preconditions: Data members have been initialized.
	 *
	 * Postconditions: This tree has been printed.
	 *
	 * @param scope The scope of the tree (used for indenting purposes).
 	 */
	virtual void print (int scope) const;

/**
 * @private
 */
private:

	/**
	 * @brief The node stored in the tree.
	 */
	struct Node {
		IdentifierRecord *item;	// Object data being stored.
		Node *left;	            // Left child subtree.
	 	Node *right;	        // Right child subtree.
	};


	/**
	 * @brief The root of this tree.
	 */
	Node *my_root;


	//---------------------lookupHelper----------------------------------------
	/**
	 * @brief A helper method for recursively finding the provided name in
	 *	      the tree. Returns true if found, false otherwise.
	 *
	 * Preconditions: my_root points to the root of the tree, or NULL if the
	 *                tree is empty.
	 *
	 * Postconditions: Returns true if found, false otherwise.
	 *
	 * @param root The root of the subtree.
	 * @param name The name of the item being looked up.
	 * @return True if found, false otherwise.
	 */
	bool lookupHelper (const Node *root, string name) const;


	//---------------------retrieveHelper--------------------------------------
	/**
	 * @brief A helper method for recursively retrieving the provided name in
	 *	      the tree. Returns a pointer to the IdentifierRecord if found,
	 *	      NULL otherwise.
	 *
	 * Preconditions: my_root points to the root of the tree, or NULL if the
	 *                tree is empty.
	 *
	 * Postconditions: Returns a pointer to the IdentifierRecord if found,
	 *                 NULL otherwise.
	 *
	 * @param root The root of the subtree.
	 * @param name The name of the item being looked up.
	 * @return A pointer to the IdentifierRecord if found, NULL otherwise.
	 */
	IdentifierRecord * retrieveHelper (const Node *root, string name) const;


	//---------------------clone-----------------------------------------------
	/**
	 * @brief Clones the given originalTree into the subtree of copy
	 *        recursively.
	 *
	 * Preconditions: originalTree is not NULL. IdentifierRecord has a copy
	 *                constructor.
	 *
	 * Postconditions: copy contains its own copy of the original tree.
	 *
	 * @param copy The tree to copy into.
	 * @param originalTree The tree to copy from.
	 */
	void clone (Node *&copy, const Node *originalTree);


	//---------------------makeEmptyHelper-------------------------------------
	/**
	 * @brief Recursively empties the provided subtree.
	 *
	 * Preconditions: root points to the first node in the
	 *		          tree, or NULL if the tree is empty.
	 *
	 * Postconditions: The provided tree is empty with a NULL
	 * 		   root.
	 *
	 * @param root The root of the subtree.
	 */
	void makeEmptyHelper (Node *&root);


	//---------------------insertHelper----------------------------------------
	/**
	 * @brief A helper method for recursively inserting an
	 * 	  item into the tree. If the item already exists in
	 *	  the tree the occurrence will will incremented.
	 *
	 * Preconditions: item is not NULL, and  my_root points to the
	 *		  root of the tree, or NULL if the tree is
	 *		  empty.
	 *
	 * Postconditions: Returns true if the item was inserted, false
	 *		   otherwise.
	 *
	 * @param root The root of the subtree.
	 * @param ident The identifier being inserted.
	 * @return True if the identifier was inserted, false otherwise.
	 */
	bool insertHelper (Node *&root, IdentifierRecord *ident);


	//---------------------printHelper-----------------------------------------
	/**
	 * A helper method that recursively prints the given tree in order.
	 *
	 * Preconditions: root is not NULL.
	 *
	 * Postconditions: The tree is sent to the output.
	 *
	 * @param output The output stream to to send the data.
	 * @param root The root of the subtree.
	 * @param scope The indentation level (3 spaces per scope).
	 */
	void printHelper (const Node *root, int scope) const;
};
#endif /* BSTREE_H */
