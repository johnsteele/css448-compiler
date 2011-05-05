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
 *	- Allows client to << a IdentifierRecord.
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


//---------------------Default Constructor-------------------------------------
/**
 * @brief Creates an IdentifierRecord object with default values.
 *
 * Preconditions: None.
 *
 * Postconditions: The data members of this IdentifierRecord have been
 *		           initialized with default values.
 */
IdentifierRecord::IdentifierRecord () {
	name = "";
}


//---------------------Constructor---------------------------------------------
/**
 * @brief Creates an IdentifierRecord object with the specified values.
 *
 * Preconditions: None.
 *
 * Postconditions: The data members of this Item have been set to the
 *                 specified values.
 *
 * @param the_name The name of this identifier.
 * TODO: finish params, if anymore are needed.
 */
IdentifierRecord::IdentifierRecord (string the_name) {
	name = the_name;
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


//---------------------print---------------------------------------------------
/**
 * @brief Prints the data members of this IdentifierRecord to the
 *        output stream.
 *
 * Preconditions: Data members have been initialized.
 *
 * Postconditions: This IdentifierRecord's members have been printed.
 *
 * @param output The output stream.
 */
void IdentifierRecord::print(ostream &output) const {
	output << "IdentifierRecord::print()";
	output << name;
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
const string IdentifierRecord::getName () const
{
	return name;
}

