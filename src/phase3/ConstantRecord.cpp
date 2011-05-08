/******************************************************************************
 * @file ConstantRecord.h                                                     *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ConstantRecord represents an variable identifier.                   *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print a ConstantRecord.
 * 	- Allows clients to compare ConstantRecord for equality.
 * 	- Allows clients to compare ConstantRecords for less than value.
 */
//-----------------------------------------------------------------------------

#include "ConstantRecord.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a ConstantRecord with the specified name.
 *
 * Preconditions: None.
 *
 * Postconditions: This ConstantRecord was instantiated.
 *
 * @param name The name of the ConstantRecord.
 */
ConstantRecord::ConstantRecord(string name) : IdentifierRecord (name) {
	const_factor = 0;
}

//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the
 *        ConstantRecord.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
ConstantRecord::~ConstantRecord() {

}


//---------------------clone---------------------------------------------------
/**
 * @brief Clones this IdentifierRecord.
 *
 * Preconditions: None.
 *
 * Postconditions: A pointer to a cloned identifier is returned.
 *
 * @return The pointer to the cloned object.
 */
ConstantRecord * ConstantRecord::clone() const {
	return NULL;
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
bool ConstantRecord::operator<(const IdentifierRecord &the_other) const {
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
bool ConstantRecord::operator==(const IdentifierRecord &the_other) const {
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
void ConstantRecord::print(int scope) const {
	IdentifierRecord::print(scope);
	cout << getName() << " " << const_factor;
}


//---------------------setConstFactor------------------------------------------
/**
 * @brief Sets the constant factor value for this constant.
 *
 * Preconditions: None.
 *
 * Postconditions: The constant factor was set to the provided value.
 *
 * @param factor The constant factor value.
	 */
void ConstantRecord::setConstFactor (int factor) {
	const_factor = factor;
}

