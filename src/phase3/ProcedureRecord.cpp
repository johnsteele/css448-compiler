/******************************************************************************
 * @file ProcedureRecord.h                                                    *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - ProcedureRecord                        *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ProcedureRecord represents a function or procedure identifier.      *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to << an ProcedureRecord.
 * 	- Allows clients to compare ProcedureRecord for equality.
 * 	- Allows clients to compare ProcedureRecords for less than value.
 *	- Allows clients to print the ProcedureRecord.
 */
//-----------------------------------------------------------------------------
#include "ProcedureRecord.h"


//---------------------Constructor-----------------------------------------
/**
 * @brief Creates a ProcedureRecord with default values.
 *
 * Preconditions: None.
 *
 * Postconditions: This ProcedureRecord was instantiated.
 *
 * @param name The name of the ProcedureRecord.
 */
ProcedureRecord::ProcedureRecord(string name) : IdentifierRecord(name) {
	args = new vector<string>();
}


//---------------------Destructor------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the
 *        ProcedureRecord.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
ProcedureRecord::~ProcedureRecord() {

}


//---------------------clone-----------------------------------------------
/**
 * @brief Clones this IdentifierRecord.
 *
 * Preconditions: None.
 *
 * Postconditions: A pointer to a cloned identfifier is returned.
 *
 * @return The pointer to the cloned object.
 */
ProcedureRecord * ProcedureRecord::clone() const {
	return NULL;
}


//---------------------operator<-------------------------------------------
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
bool ProcedureRecord::operator<(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
}


//---------------------operator==------------------------------------------
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
bool ProcedureRecord::operator==(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
}


//---------------------print-----------------------------------------------
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
void ProcedureRecord::print(ostream &output) const {
	output << "FuncSymbol::print()";
}

