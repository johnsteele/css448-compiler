/******************************************************************************
 * @file VariableRecord.h                                                     *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentifierRecord                       *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief VariableRecord represents an integer identifier. 				      *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print a VariableRecord.
 * 	- Allows clients to compare VariableRecord for equality.
 * 	- Allows clients to compare VariableRecords for less than value.
 */
//-----------------------------------------------------------------------------

#include "VariableRecord.h"


//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a VariableRecord with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This VariableRecord was instantiated.
 *
 * @param name The name of the ProcedureRecord.
 * @param ref  True if reference, false if not reference.
 */
VariableRecord::VariableRecord(string name) : IdentifierRecord (name) {

}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the VariableRecord.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
VariableRecord::~VariableRecord() {

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
bool VariableRecord::operator<(const IdentifierRecord &the_other) const {
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
bool VariableRecord::operator==(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
}


//---------------------print---------------------------------------------------
/**
 * @brief Prints the data members of this IdentifierRecord to the output
 *        stream.
 *
 * Preconditions: Data members have been initialized.
 *
 * Postconditions: This IdentifierRecord's members have been printed.
 *
 * @param scope The scope of this identifier (used for indenting purposes).
 */
void VariableRecord::print (int scope) const {
	IdentifierRecord::print(scope);
	cout << getName();
}
