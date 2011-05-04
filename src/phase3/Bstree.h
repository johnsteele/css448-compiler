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
 *	- Allows displaying the contents of a BSTree using <<.
 * 	- Allows inserting an IdentifierRecord into the tree.
 *	- Allows retrieving a specified IdentifierRecord from the tree.
 *	- Allows removing an IdentifierRecord from the tree.
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

	//---------------------operator<<------------------------------------------
	/**
	 * @brief Overloaded operator <<.
	 *
	 * Preconditions: The root pointer of the tree must point to the root of
	 *                the tree or NULL.
	 *
	 * Postconditions: The elements of the bstree were sent to the std output
	 *                 stream.
	 *
	 * @param output The output stream.
	 * @param the_other The BSTree to output.
	 * @return The output stream.
	 */
	 friend ostream& operator<< (ostream &output,
					const BSTree &the_other);

/**
 * @public
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a BSTree with a NULL root.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The BSTree was instantiated with its root
	 *		           set to NULL.
	 */
	BSTree ();


	//---------------------Copy-Constructor-----------------------
	/**
	 * @brief Copies the other tree into this tree.
	 *
	 * Preconditions: The other trees' root points to NULL if it
	 *		          is empty, otherwise the root of the tree.
	 *
 	 * Postconditions: The other tree was copied into this tree.
	 */
	BSTree (const BSTree &other);


	//---------------------Destructor-----------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within
	 *	  the tree.
	 *
	 * Preconditions: makeEmpty is implemented.
	 *IdentifierRecord
	 * Postconditions: This BSTree is empty with a NULL root.
	 */
	~BSTree ();


	//---------------------insert---------------------------------
	/**
	 * @brief Inserts an item into the tree.
	 *
	 * Preconditions: The item is not NULL, and there must be
	 * 		  enough memory for allocating the new Node.
	 *
 	 * Postconditions: The item was inserted into the tree.
	 *
	 * @param item The item to insert into the tree.
	 * @return True if successfully inserted, false otherwise.
	 */
	bool insert (Object *item);


	//---------------------retrieve-------------------------------
	/**
	 * @brief Searches the tree for the given target, if found
	 *	  a pointer to the object is returned, NULL otherwise.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: A pointer to the object was returned if it
	 *		   was found, NULL otherwise.
	 *
	 * @param target The item to search for.
	 * @return Pointer to the object if found, NULL otherwise.
	 */
	const Object * retrieve (const Object &target) const;


	//---------------------remove---------------------------------
	/**
	 * @brief Removes one occurance of the provided item from
	 *	  the tree. If it is the last occurance, the objet
	 *	  is removed. Calls a helper recursive method.
	 *
	 * Preconditions: item is a reference to a non NULL object.
	 *
 	 * Postconditions: True was returned if the item was was
	 *		   found and removed, false otherwise.
	 *
	 * @param item The item to remove from the tree.
	 * @return True if removed, false otherwise.
	 */
	bool remove (const Object &item);


	//---------------------makeEmpty------------------------------
	/**
	 * @brief Empties this tree.
	 *
 	 * Preconditions: my_root points to the root of the tree or
	 *		  NULL if the tree is empty.
	 *
	 * Postconditions: The tree is empty.
	 */
	void makeEmpty ();


	//---------------------getOccurrence---------------------------
	/* @brief Returns the occurence of the item.
	 *
	 * Preconditions: item is not NULL.
	 *
	 * Postconditions: occurrnce was returned.
	 *
	 * @param item The item to get the count of.
	 * @return occurence count of the item.
	 */
	int getOccurrence (const Object &item) const;


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
	const BSTree& operator=  (const BSTree &the_other);

/**
 * @private
 */
private:

	/**
	 * @brief The node stored in the tree.
	 */
	struct Node {
		Object *item;	// Object data being stored.
		Node   *left;	// Left child subtree.
	 	Node   *right;	// Right child subtree.
		int occurences;	// Occurrences of the character.
	};


	/**
	 * @brief The root of this tree.
	 */
	Node *my_root;


	//---------------------clone----------------------------------
	/**
	 * @brief Clones the given originalTree into the subtree of
	 *	  copy recursively.
	 *
	 * Preconditions: originalTree is not NULL. Object has a
	 *		  copy constructor.
	 *
	 * Postconditions: copy contains its own copy of the original
	 *		   tree.
	 *
	 * @param copy The tree to copy into.
	 * @param originalTree The tree to copy from.
	 */
	void clone (Node *&copy, const Node *originalTree);


	//---------------------makeEmptyHelper------------------------
	/**
	 * @brief Recursively empties the provided subtree.
	 *
	 * Preconditions: root points to the first node in the
	 *		  tree, or NULL if the tree is empty.
	 *
	 * Postconditions: The provided tree is empty with a NULL
	 * 		   root.
	 *
	 * @param root The root of the subtree.
	 */
	void makeEmptyHelper (Node *&root);


	//---------------------insertHelper---------------------------
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
	 * @param item The item being inserted.
	 * @return True if the item was inserted, false otherwise.
	 */
	bool insertHelper (Node *&root, Object *item);


	//---------------------retrieveHelper-------------------------
	/**
	 * @brief A helper method for recursively finding the provided
	 *	  item in the tree. Returns NULL if the item is not
	 *	  found.
	 *
	 * Preconditions: item is not NULL, and my_root points to the
	 *		  root of the tree, or NULL if the tree is
	 *		  empty.
	 *
	 * Postconditions: A pointer to the found item is returned,
	 *		   NULL is returned otherwise.
	 *
	 * @param root The root of the subtree.
	 * @param item The item being retrieved.
	 * @return A pointer to the found item, NULL otherwise.
	 */
	const Object * retrieveHelper (const Node *root,
					const Object &item) const;


	//---------------------removeHelper---------------------------
	/**
	 * @brief Removes an occurance of the provided item from the
	 *	  tree. If it is its last occurance the Object it is
	 *	  removed.
	 *
	 * Preconditions: item is a reference to a non-NULL Object.
	 *
	 * Postconditions: True was retuned if the item was found and
	 *		   removed, false otherwise.
	 *
	 * @param root The root of the subtree.
	 * @param item The item to remove from the tree.
	 * @return True if item was removed, false otherwise.
	 */
	bool removeHelper (Node *&root, const Object &item);


	//---------------------deleteRoot-----------------------------
	/**
	 * @brief Deletes the node the provided pointer points to.
 	 * 	  If the left and right pointers of the node are not
	 *	  NULL we delete the item in the node and replace it
	 *        with the most left node in its right subtree.
	 *
	 * Preconditions: root is not NULL.
	 *
	 * Postconditions: The root has been deleted.
	 *
	 * @param root The root to delete.
	 */
	void deleteRoot (Node *&root);


	//---------------------findAndDeleteMostLeft------------------
	/**
	 * @brief Returns the Object item from the node that is
	 *	  located at the most left subtree of the give root.
	 *
	 * Preconditions: root is not NULL.
	 *
	 * Postconditions: A pointer to the Object item of the most
	 *		   left node is returned. That node that
	 *		   previously stored item is then deleted. The
	 *		   occurance cound is also handled.
	 *
	 * @param root The root of the subtree.
	 * @param m_root The root of the tree being replaced.
	 * @return A pointer to the furthest left node.
	 */
	Object * findAndDeleteMostLeft (Node *&root, Node *m_root);


	//---------------------printHelper----------------------------
	/**
	 * A helper method that recursively prints the given tree
	 * in order.
	 *
	 * Preconditions: root is not NULL.
	 *
	 * Postconditions: The tree is sent to the output.
	 *
	 * @param output The output stream to to send the data.
	 * @param root The root of the subtree.
	 */
	void printHelper (ostream &output, const Node *root) const;


	//---------------------occurrenceHelper-----------------------
	/**
	 * @brief Returns the Node of the provided object.
	 *
	 * Preconditions: The object is not NULL.
	 *
	 * Postconditions: The node or NULL was returned.
	 *
	 * @param item The item being searched for.
	 * @param root The root of the subtree.
	 */
	int occurrenceHelper (const Object &item, const Node *root) const;
};
#endif /* BSTREE_H */
