/*
 * @file HashTable.cpp
 * 
 * @brief This class implements a HashTable, which maps char keys to
 *	  	  values. Any non NULL IdentifierRecord can be used as a value.
 *
 * @brief CSS 448 - Compiler - Phase 3
 *
 * @author John Steele      \<steelejr@u.washington.edu\>
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>
 *  
 * @version 1.0.0
 * @date April 30, 2011
 */
//--------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows creating a HashTable with a specified size.
 * 	- Allows adding an key / value pair.
 *	- Allows getting the value of associated with a specific key.
 *	- Allows making the HashTable empty.
 * 
 * Assumptions:
 * 	- The objects stored in the HashTable are non-NULL.
 */
//--------------------------------------------------------------------

#include "HashTable.h"

//---------------------Constructor------------------------------------
/**
 * @brief Creates a HashTable with a default capacity.
 *
 * Preconditions: None.
 * 
 * Postconditions: This HashTable was created with the default size.
 */
HashTable::HashTable() {
	my_array = new IdentifierRecord *[DEFAULT_SIZE + 1];
	my_size = DEFAULT_SIZE + 1;
	init_table();
}

//---------------------Destructor-----------------------------
/**
 * @brief Deletes all dynamically allocated memory.
 *
 * Preconditions: None.
 *
 * Postconditions: All dynamic memory has been released.
 */
HashTable::~HashTable() {
	// TODO: Decide if the table is responsible for the
	//       identifier memory.
	delete [] my_array;
}

//---------------------init_table-------------------------------------
/**
 * @brief Initializes the values of the table. 
 *
 * Preconditions: my_size is the size of the table array.
 *
 * Postconditions: The values of each index have been initialized.
 */
void HashTable::init_table() {
	int i;
	for (i = 0; i < my_size; i++)
		my_array[i] = NULL;
}

//---------------------put--------------------------------------------
/**
 * @brief Maps the specified key to the specified value in this
 *	  HashTable. Neither the key or the value can be NULL.
 *
 * Preconditions: The key is valid.
 * 	
 * Postconditions: The value was added to this HashTable.
 * 	
 * @param key The HashTable key.
 * @param value The value to insert.
 */
void HashTable::add(char key, IdentifierRecord *value) {
	int index = hashCode(key);
	if (index > my_size)
		makeBigger(index);

	my_array[index] = value;
}

//---------------------hashCode-------------------------------
/**
 * @brief Returns the hash code for the provided key.
 * 
 * Preconditions: None.
 * 
 * Postconditions: A hash code was returned.
 * 
 * @param key The key to hash.
 * @return The hash code for the key.
 */
int HashTable::hashCode(char key) const {
	return key - '0';
}

//---------------------get--------------------------------------------
/**
 * @brief Returns a pointer to the value which the specified key is
 *	  mapped in this HashTable.
 *
 * Preconditions: The hashed key is valid index of array. 
 *
 * Postconditions: A pointer to the value was returned.
 *
 * @param key A key in the HashTable.
 *
 * @return The value to which the key is mapped in this HashTable;
 *	   NULL if the key is not mapped to any value in this
 *	   HashTable.
 */
IdentifierRecord * HashTable::get(char key) const {
	if (((hashCode(key)) < my_size) && ((hashCode(key)) >= 0)) {
		return my_array[hashCode(key)];
	} else {
		return NULL;
	}
}

//---------------------resize-----------------------------------------
/**
 * @brief Creates a bigger array and copies over the data.
 *
 * Preconditions: size is bigger than my_size.
 * 
 * Postconditions: my_array has been increased to size, and the data 
 *		   has been copied over. 
 */
void HashTable::makeBigger(int size) {
	int index;

	// The bigger array.
	IdentifierRecord **copy = new IdentifierRecord *[size + 1];

	// Initialize the pointers.
	for (index = 0; index <= size; index++)
		copy[index] = NULL;

	// Copy over old data.
	for (index = 0; index <= my_size; index++)
		copy[index] = my_array[index];

	// Delete the old array.	
	delete my_array;

	// Now hold her hand.
	my_array = copy;

	// Now set our new size.
	my_size = size + 1;

	// Stay away dangly leaches!
	copy = NULL;
}

