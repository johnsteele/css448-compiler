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
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>
#include "IdentifierRecord.h"

/**
 * @namespace std
 */
using namespace std;

/**
 * @class HashTable
 */
class HashTable {

/**
 * @public 
 */
public:

	//---------------------Constructor----------------------------
	/**
	 * @brief Creates a HashTable with a default capacity.
	 *
	 * Preconditions: None.
	 * 
	 * Postconditions: This HashTable was created with the default
	 *		   size.
	 */
	HashTable ();


	//---------------------put------------------------------------
	/**
	 * @brief Maps the specified key to the specified value in 	
 	 *	  this HashTable. Neither the key or the value can be
	 *	  NULL.
	 *
	 * Preconditions: The key is valid.
	 * 	
 	 * Postconditions: The value was added to this HashTable.
	 * 	
 	 * @param key The HashTable key.
	 * @param value The value to insert.
	 */
	void add (char key, IdentifierRecord *value);

	
	//---------------------get------------------------------------
	/**
	 * @brief Returns a pointer to the value which the specified
	 *	  key is mapped in this HashTable.
	 *
	 * Preconditions: The key is valid.
	 *
	 * Postconditions: A pointer to the value was returned.
	 *
	 * @param key A key in the HashTable.
	 * @return The value to which the key is mapped in this 
	 *	   HashTable; NULL if the key is not mapped to any
	 *	   value in this HashTable.
	 */
	IdentifierRecord * get (char key) const;

/**
 * @private
 */
private:

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
	int hashCode (char key) const;


	//---------------------resize---------------------------------
	/**
	 * @brief Creates a bigger array and copies over the data.
	 *
 	 * Preconditions: size is bigger than my_size.
	 * 
	 * Postconditions: my_array has been increased to size, and
 	 * 		   the data has been copied over. 
	 */
	void makeBigger (int size);


	//---------------------init_table-----------------------------
	/**
	 * @brief Initializes the values of the table. 
	 *
	 * Preconditions: my_size is the size of the table array.
	 *
	 * Postconditions: The values of each index have been 
 	 *		   initialized.
	 */
	void init_table();

	/**
	 * @brief The size of the array. 
	 */
	int my_size;
	
	/**
	 * @brief The array of stored objects.
	 */	
	IdentifierRecord **my_array;

	/**
  	 * @brief Default size of table array.
	 */
	const static int DEFAULT_SIZE = 10;
};
#endif

