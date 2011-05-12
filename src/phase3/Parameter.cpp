/******************************************************************************
 * @file Parameter.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - Parameter                              *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief Parameter represents a Parameter identifier.                        *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print Parameter.
 * 	- Allows clients to compare Parameter for equality.
 * 	- Allows clients to compare Parameters for less than value.
 *	- Allows clients to prVariable the Parameter.
 */
//-----------------------------------------------------------------------------

#include "Parameter.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a Parameter with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This Parameter was instantiated.
 *
 * @param name The name of the Parameter.
 */
Parameter::Parameter(string name) : IdentifierRecord (name){

}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the
 *        Parameter.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
Parameter::~Parameter() {

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
bool Parameter::operator<(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
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
bool Parameter::operator==(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
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
 * @param scope The scope of this identifier (used for indenting purposes).
 */
void Parameter::print(int scope) const {
	IdentifierRecord::print(scope);
}
