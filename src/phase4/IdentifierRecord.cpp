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
 * @brief IdentifierRecord in a base class for all identifier types           *
 *        to inherit from.                       					          *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to compare IdentifierRecords for equality.
 * 	- Allows clients to compare IdentifierRecords for less than value.
 *	- Allows clients to print the IdentifierRecord.
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
	type = NULL;
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
	SITtable sits;
	if (sits.lookup(name) == true)
		delete type;

	type = NULL;
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
	if (name != "_array" && name != "_ptr" && name != "_set" && name != "_record")
			return name;
	else
		return "";
}


//---------------------setType-------------------------------------------------
/**
 * @brief Sets the type of this identifier.
 *
 * Preconditions: type is initialized.
 *
 * Postconditions: type was set.
 *
 * @param the_type The identifier type.
 */
void IdentifierRecord::setType (IdentifierRecord * the_type) {
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
const IdentifierRecord * IdentifierRecord::getType () {
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

	if (name != "_array" && name != "_ptr" && name != "_set" && name != "_record") {
		cout << name;
		cout << " ";
	}
}


//---------------------operator<-----------------------------------------------
/**
 * @brief Compares this IdentfierRecord with the_other for less than value.
 *
 * Preconditions: The data members of this IdentfierRecord have been
 *                initialized.
 *
 * Postconditions: Returned true if this IdentfierRecord was less than
 *		           the_other.
 *
 * @param the_other The other IdentfierRecord to compare with this.
 *
 * @return True if this IdentfierRecord is less than the_other,
 *	       false otherwise.
 */
bool IdentifierRecord::operator< (const IdentifierRecord &the_other) const {
	return (name < the_other.name);
}


//---------------------operator==----------------------------------------------
/**
 * @brief Compares this IdentfierRecord with the_other IdentfierRecord.
 *
 * Preconditions: The data members of this IdentfierRecord have been
 *		          initialized.
 *
 * Postconditions: Returned true if this IdentfierRecord was equal to
 *		           the_other.
 *
 * @param the_other The other IdentfierRecord to compare with this
 *                  IdentfierRecord.
 *
 * @return True if the_other is equal to this IdentifierRecord,
 *	       false otherwise.
 */
bool IdentifierRecord::operator== (const IdentifierRecord &the_other) const {
	return (name == the_other.name);
}
