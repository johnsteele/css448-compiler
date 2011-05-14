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
}
