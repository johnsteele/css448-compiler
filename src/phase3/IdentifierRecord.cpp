/******************************************************************************
 * @file IdentifierRecord.cpp                                                 *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentifierRecord                       *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief IdentifierRecord in an abstract base class for all identifier types *
 *        to inherit from.                       					          *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to compare IdentifierRecords for equality.
 * 	- Allows clients to compare IdentifierRecords for less than value.
 *	- Allows clients to print the IdentifierRecord.
 *
 * Assumptions:
 * 	- All derived classes of IdentifierRecord implement getNewInstance,
 * 	  and within the method return a dynamically allocated object of
 *	  the derived type.
 */
//-----------------------------------------------------------------------------

#include "IdentifierRecord.h"


//---------------------Constructor---------------------------------------------
/**
 * @brief Creates an IdentifierRecord object with the specified values.
 *
 * Preconditions: None.
 *
 * Postconditions: The data members of this Item have been set to the
 *                 specified values.
 *
 * @param the_name The name of the identifier record.
 */
IdentifierRecord::IdentifierRecord (string the_name) {
	name = the_name;
	type = "";
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all memory associated with this identifier.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources have been released.
 */
IdentifierRecord::~IdentifierRecord() {

}


//---------------------getName-------------------------------------------------
/**
 * @brief An accessor method for derived classes to use for comparisons.
 *
 * Preconditions: name is initialized.
 *
 * Postconditions: name was returned.
 *
 * @return The name of this IdentifierRecord.
 */
const string IdentifierRecord::getName () const {
	return name;
}


//---------------------setType-------------------------------------------------
/**
 * @brief Sets the name of the type for this identifier.
 *
 * Preconditions: type is initialized.
 *
 * Postconditions: type was returned.
 *
 * @param the_type The name of the type of identifier.
 */
void IdentifierRecord::setType (string the_type) {
	type = the_type;
}


//---------------------getType-------------------------------------------------
/**
 * @brief An accessor method for derived classes.
 *
 * Preconditions: type is initialized.
 *
 * Postconditions: type was returned.
 *
 * @return The type of this IdentifierRecord.
 */
const string IdentifierRecord::getType () const {
	return type;
}


//---------------------print---------------------------------------------------
/**
 * @brief Prints the data members of this IdentifierRecord to the standard
 *        output stream.
 *
 * Preconditions: None.
 *
 * Postconditions: For every level of scope, three spaces were printed.
 *
 * @param scope The scope of this identifier (used for indenting purposes).
 */
void IdentifierRecord::print (int scope) const {

	for (int i = 0; i < scope; i++) {
		cout << "   ";
	}
}

