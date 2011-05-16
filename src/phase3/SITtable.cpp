/******************************************************************************
 * @file SITtable.h                                                           *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - SITtable                               *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief SITtable represents a standard identifier table.                    *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to lookup an identifier.
 */
//-----------------------------------------------------------------------------

#include "SITtable.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates an SITtable object with the specified value.
 *
 * Preconditions: None.
 *
 * Postconditions: The name of the identifier was set.
 *
 * @param the_name The name of this identifier.
 */
SITtable::SITtable () {
	standard_idents = new vector<string> ();
	initIdents();
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes the vector of identifiers.
 *
 * Preconditions: None.
 *
 * Postconditions: The identifier vector was deleted.
 */
SITtable::~SITtable() {
	delete standard_idents;
	standard_idents = NULL;
}


//---------------------initIdents------------------------------------------
/**
 * @brief Initializes the standard identifiers.
 *
 * Preconditions: standard_idents was instantiated.
 *
 * Postconditions: Returns true if found, false otherwise.
	 */
void SITtable::initIdents () {
	standard_idents->push_back("false");
	standard_idents->push_back("true");
	standard_idents->push_back("integer");
	standard_idents->push_back("boolean");
	standard_idents->push_back("real");
	standard_idents->push_back("char");
}


//---------------------print---------------------------------------------------
/**
 * @brief Checks if the provided identifier is in this SIT.
 *
 * Preconditions: None.
 *
 * Postconditions: Returns true if found, false otherwise.
 *
 * @param ident The identifier to lookup.
 *
 * @return True if found, false otherwise.
 */
bool SITtable::lookup(const string ident) const {

	/* Convert to lower case. Pascal is not case sensitive. */
	string temp = ident;
	for (int i = 0; temp[i] != '\0'; i++) {
		temp.at(i) = tolower (temp.at(i));
	}

	// Check in identifier vector.
	for (int i = 0; i < (long) standard_idents->size(); i++) {
		if (standard_idents->at(i) == temp) return true;
	}

	// Not found.
	return false;
}
