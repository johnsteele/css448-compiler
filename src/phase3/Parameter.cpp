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
 * @param is_var If this identifier is a variable.
 */
Parameter::Parameter(string name, bool is_var) : IdentifierRecord (name){
	isVar = is_var;
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
	for (int i = 0; i < scope; i++) {
		cout << "   ";
	}

	if (isVar) {
		cout << "var ";
	}

	IdentifierRecord::print(0);

	if (getType() != NULL) {

		if (getType()->getName() == "") {
			getType()->print(0);
		}

		else {
			cout << getType()->getName();
		}
	}
}
