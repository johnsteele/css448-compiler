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
 * 	- Allows clients to compare ProcedureRecord for equality.
 * 	- Allows clients to compare ProcedureRecords for less than value.
 *	- Allows clients to print the ProcedureRecord.
 */
//-----------------------------------------------------------------------------
#include "ProcedureRecord.h"


//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a ProcedureRecord with the specified name.
 *
 * Preconditions: None.
 *
 * Postconditions: This ProcedureRecord was instantiated.
 *
 * @param name The name of the ProcedureRecord.
 */
ProcedureRecord::ProcedureRecord(string name) : IdentifierRecord(name) {

	args       = new vector <IdentifierRecord *> ();
	returnType = NULL;
}


//---------------------Destructor----------------------------------------------
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
bool ProcedureRecord::operator<(const IdentifierRecord &the_other) const {
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
bool ProcedureRecord::operator==(const IdentifierRecord &the_other) const {
	bool result = false;

	return result;
}


//---------------------print---------------------------------------------------
/**
 * @brief Prints the return type if the procedure is a function, followed
 *        by the parameters.
 *
 * Preconditions: Data members have been initialized.
 *
 * Postconditions: This IdentifierRecord's members have been printed.
 *
 * @param scope The scope of this identifier (used for indenting purposes).
 */
void ProcedureRecord::print (int scope) const {

	IdentifierRecord::print(scope);

	// Print name.
	cout << getName();

	// Print return type (if this Procedure is a function).
	if (returnType != NULL)
		cout << " " << returnType;

	// cout << endl;

	// Print parameters (if there is any).
	for (int i = 0; i < (long) args->size(); i++) {
		args->at(i)->print(scope);
		cout << endl;
	}
}


//---------------------setReturnType-------------------------------------------
/**
 * @brief Sets the return type of this Procedure to the provided return type.
 *
 * Preconditions: returnType is not NULL.
 *
 * Postconditions: The return type was set.
 *
 * @param the_returnType The return type for this Procedure.
 */
void ProcedureRecord::setReturnType (IdentifierRecord * the_returnType) {
	returnType = the_returnType;
}


//---------------------insertParam---------------------------------------------
/**
 * @brief Inserts the provided Parameter into this Procedure.
 *
 * Preconditions: parameter is not NULL.
 *
 * Postconditions: The parameter is not NULL.
 *
 * @param parameter The parameter to add to this Procedure.
 */
void ProcedureRecord::insertParam (Parameter * parameter) {
	args->push_back(parameter);
}
