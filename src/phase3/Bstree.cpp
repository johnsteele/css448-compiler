/******************************************************************************
 * @file Bstree.cpp                                                           *
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

#include "Bstree.h"


//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a BSTree with a NULL root.
 *
 * Preconditions: None.
 *
 * Postconditions: The BSTree was instantiated with its root set to NULL.
 */
BSTree::BSTree ()
{
	my_root = NULL;
}


//---------------------Copy-Constructor----------------------------------------
/**
 * @brief Copies the other tree into this tree.
 *
 * Preconditions: The other trees' root points to NULL if it is empty,
 *		          otherwise the root of the tree.
 *
 * Postconditions: The other tree was copied into this tree.
 */
BSTree::BSTree (const BSTree &the_other)
{
	my_root = NULL;
	*this = the_other;
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the tree.
 *
 * Preconditions: makeEmpty is implemented.
 *
 * Postconditions: This BSTree is empty with a NULL root.
 */
BSTree::~BSTree()
{
	makeEmpty();
}


//---------------------retrieve------------------------------------------------
/**
 * @brief Searches the tree for the given target, if found true is returned.
 *
 * Preconditions: target is non-NULL.
 *
 * Postconditions: Returns true if found, false otherwise.
 *
 * @param target The identifier to search for.
 * @return True if found, false otherwise.
 */
bool BSTree::retrieve (IdentifierRecord * target) const
{
	return retrieveHelper(my_root, target);
}


//---------------------retrieveHelper---------------------------------
/**
 * @brief A helper method for recursively finding the provided item in
 *	      the tree. Returns true if found, false otherwise.
 *
 * Preconditions: item is not NULL, and my_root points to the root of
 *		          the tree, or NULL if the tree is empty.
 *
 * Postconditions: Returns true if found, false otherwise.
 *
 * @param root The root of the subtree.
 * @param the_item The item being retrieved.
 * @return True if found, false otherwise.
 */
bool BSTree::retrieveHelper (const Node *root, IdentifierRecord * the_item) const
{
	if (root == NULL) return false;

	else if (*the_item == *root->item)
		return true;

	else if (*the_item < *root->item)
		return retrieveHelper (root->left, the_item);

	else
		return retrieveHelper (root->right, the_item);
}

//---------------------insert--------------------------------------------------
/**
 * @brief Inserts an IdentifierRecord into the tree.
 *
 * Preconditions: The identifier is not NULL, and there must be enough memory
 *                for allocating the new Node.
 *
 * Postconditions: The identifier was inserted into the tree.
 *
 * @param ident The item to insert into the tree.
 * @return True if successfully inserted, false otherwise.
 */
bool BSTree::insert (IdentifierRecord *ident)
{
	return insertHelper (my_root, ident);
}


//---------------------insertHelper--------------------------------------------
/**
 * @brief A helper method for recursively inserting an item into the tree. If
 *        the identifier is already in the tree false it returned.
 *
 * Preconditions: ident is not NULL, and  my_root points to the root of
 *	  	          the tree, or NULL if the tree is empty.
 *
 * Postconditions: Returns true if the identifier was inserted, false
 *		           otherwise.
 *
 * @param root The root of the subtree.
 * @param ident The identifier being inserted.
 * @return True if the identifier was inserted, false otherwise.
 */
bool BSTree::insertHelper (Node *&the_root, IdentifierRecord * ident)
{
	if (the_root == NULL) {
		the_root        = new Node;
		// We're taking ownership of the Object.
		the_root->item  = ident;
		the_root->left  = NULL;
		the_root->right = NULL;
		return true;
	}

	else if (*the_root->item == *ident) {
		// Already in tree.
		delete ident;
		return false;
	}

	else if (*ident < *the_root->item)
		return insertHelper(the_root->left, ident);

	 else
		return insertHelper(the_root->right, ident);
}


//---------------------deleteRoot-------------------------------------
/**
 * @brief Deletes the node the provided pointer points to. If the left
 *	  and right pointers of the node are not NULL we delete the
 *	  item in the node and replace it with the most left node in
 *	  its right subtree.
 *
 * Preconditions: root is not NULL.
 *
 * Postconditions: The root has been deleted.
 *
 * @param root The root to delete.
 */
void BSTree::deleteRoot (Node *&root)
{
	// Only node in the tree, or a leaf, so delete it.
	if (root->left == NULL && root->right == NULL) {
		delete root->item;
		delete root;
		root = NULL;
	}

	else if (root->left == NULL) {
		Node *temp = root;
		root = root->right;
		delete temp->item;
		delete temp;
	}

	else if (root->right == NULL) {
		Node *temp = root;
		root = root->left;
		delete temp->item;
		delete temp;
	}

	// We have a subtree on both sides, delete the root's item.
	// Replace it with the most left item in the right subtree.
	else {
		delete root->item;
		//root->item = findAndDeleteMostLeft(root->right);
		root->item = findAndDeleteMostLeft(root->right, root);
	}
}


//---------------------findAndDeleteMostLeft--------------------------
/**
 * @brief Returns the Object item from the node that is located at the
 *	  most left subtree of the give root.
 *
 * Preconditions: root is not NULL.
 *
 * Postconditions: A pointer to the Object item of the most left node
 *		   is returned. That node that previously stored item
 *		   is then deleted. The occurance cound is also
 *		   handled.
 *
 * @param root The root of the subtree.
 * @param m_root The root of the tree being replaced.
 * @return A pointer to the furthest left node.
 */
IdentifierRecord * BSTree::findAndDeleteMostLeft (Node *&root, Node *m_root)
{
	// If we reached the furthest left node.
	if (root->left == NULL) {
		// Get the item to return.
		IdentifierRecord *result = root->item;

		// Keep a hold on the node to delete.
		Node *temp     = root;

		// Move the root pointer to the right child.
		root           = root->right;
		delete temp;
		return result;
	}

	else  // Keep going left until we're NULL.
		return findAndDeleteMostLeft (root->left, m_root);
}


//---------------------makeEmpty--------------------------------------
/**
 * @brief Empties this tree.
 *
 * Preconditions: my_root points to the root of the tree or NULL if
 *		  the tree is empty.
 *
 * Postconditions: The tree is empty.
 */
void BSTree::makeEmpty ()
{
	makeEmptyHelper (my_root);
}


//---------------------makeEmptyHelper--------------------------------
/**
 * @brief Recursively empties the provided subtree.
 *
 * Preconditions: root points to the first node in the tree, or NULL
 *		  if the tree is empty.
 *
 * Postconditions: The provided tree is empty with a NULL root.
 *
 * @param root The root of the subtree.
 */
void BSTree::makeEmptyHelper (Node *&root)
{
	if (root != NULL) {
		makeEmptyHelper (root->left);
		makeEmptyHelper (root->right);
		delete root->item;
		root->item = NULL;
		delete root;
	}
	root = NULL;
}


//---------------------operator(=)------------------------------------
/**
 * @brief Overloaded assignment operator.
 *
 * Preconditions: the_other.my_root points to the first Node in the
 *		  tree, or NULL.
 *
 * Postconditions: the_other is copied into this.
 *
 * @param the_other The other tree to copy into this.
 * @return this is returned.
 */
const BSTree& BSTree::operator=  (const BSTree &the_other)
{
	// Check for self assignment.
	if (this != &the_other) {
		// Delete our current memory.
		makeEmpty();
		// Now copy the other's tree.
		clone (my_root, the_other.my_root);
	}
	return *this;
}


//---------------------clone------------------------------------------
/**
 * @brief Clones the given originalTree into the subtree of copy
 *		 recursively.
 *
 * Preconditions: originalTree is not NULL. Object has a copy
 *		  constructor.
 *
 * Postconditions: copy contains its own copy of the original tree.
 *
 * @param copy The tree to copy into.
 * @param originalTree The tree to copy from.
 */
void BSTree::clone (Node *&copy, const Node *originalTree)
{
	if (originalTree == NULL) {
		copy = NULL;
	}

	else {
		// Our new Node.
		copy = new Node;
		// Link the data into our new Node.
		//copy->item       = new Object (*originalTree->item);
		// Clone the object.
		// TODO: Need to figure this out. copy->item = originalTree->item->clone();

		// Now clone left and right subtrees.
		clone(copy->left,  originalTree->left);
		clone(copy->right, originalTree->right);
	}
}


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
void BSTree::print (int scope) const {
	printHelper (my_root, scope);
	cout << endl;
}


//---------------------printHelper------------------------------------
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
void BSTree::printHelper (const Node *root, int scope) const
{
	if (root != NULL) {
		printHelper (root->left, scope);
		root->item->print(scope);
		cout << endl;
		printHelper (root->right, scope);
	}
}
