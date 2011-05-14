/******************************************************************************
 * @file ConstantRecord.h                                                     *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - ConstantRecord                         *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ConstantRecord represents a ConstantRecord identifier.              *
 *****************************************************************************/

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
	int_const_factor = 0;
	str_const_factor = "";
	isBool           = false;
	isString         = false;
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
ConstantRecord::~ConstantRecord() {}


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
	if (isString == true) cout << str_const_factor;
	else if (isBool == true)   cout << (int_const_factor == 1 ? "true" : "false");
	else cout << int_const_factor;
}


//---------------------setConstFactor------------------------------------------
/**
 * @brief Sets the int constant factor value for this constant.
 *
 * Preconditions: None.
 *
 * Postconditions: The constant factor was set to the provided value.
 *
 * @param factor The constant factor value.
	 */
void ConstantRecord::setConstFactor (int factor) {
	int_const_factor = factor;
}


//---------------------setConstFactor------------------------------------------
/**
 * @brief Sets the int constant factor value for this constant.
 *
 * Preconditions: None.
 *
 * Postconditions: The constant factor was set to the provided value.
 *
 * @param factor The constant factor value.
	 */
void ConstantRecord::setConstFactor (string factor) {
	isString = true;
	str_const_factor = factor;
}


//---------------------setIsBool-----------------------------------------------
/**
 * @brief Sets this constant record as a bool value. With this set, the
 *        const_factor represents true (1) or false (0) respectively.
 *
 * Preconditions: None.
 *
 * Postconditions: The constant factor now represents a bool value.
 */
void ConstantRecord::setIsBool () {
	isBool = true;
}
