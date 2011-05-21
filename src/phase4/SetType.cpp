/******************************************************************************
 * @file SetType.h                                                            *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - SetType                                *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief SetType represents a SetType identifier.                            *
 *****************************************************************************/

#include "SetType.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a SetType with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This SetType was instantiated.
 *
 * @param name The name of the SetType.
 */
SetType::SetType(string name) : IdentifierRecord (name) {
	dimension = new Dimension ();
	dimension->low_ascii   = false;
	dimension->high_ascii  = false;
	dimension->str_high    = "";
	dimension->str_low     = "";
	dimension->low_isBool  = false;
	dimension->high_isBool = false;
	dimension->low_isNil   = false;
	dimension->high_isNil  = false;
	dimension->low_isBool  = false;
	dimension->high_isBool = false;
	dimension->low_ascii   = false;
	dimension->high_ascii  = false;
	dimension->low_isIdent = false;
	dimension->high_isIdent= false;
	dimension->low_ident   = NULL;
	dimension->high_ident  = NULL;
	dimension->str_low     = "";
	dimension->str_high    = "";
	dimension->low         = 0;
	dimension->high        = 0;
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the
 *        SetType.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
SetType::~SetType() {
	dimension->low_ident  = NULL;
	dimension->high_ident = NULL;
	delete dimension;
	dimension = NULL;
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
void SetType::print(int scope) const {

	// Print the name.
	IdentifierRecord::print(scope);

	// If low value is string.
	if (dimension->low_ascii == true) {
		cout << dimension->str_low;
	}

	// If low value is bool.
	else if (dimension->low_isBool) {
		string low = (dimension->low == 1 ? "true" : "false");
		cout << low;
	}

	// If low value is an identifier.
	else if (dimension->low_isIdent == true) {
		if (dimension->low_ident != NULL) {
			cout << dimension->low_ident->getName();
		}
	}

	// If low value is a nil.
	else if (dimension->low_isNil == true) {
		cout << "nil";
	}

	// Otherwise, low value is an integer.
	else
		cout << dimension->low;

	cout << "..";

	// If high value is string.
	if (dimension->high_ascii == true) {
		cout << dimension->str_high;
	}

	// If high value is bool.
	else if (dimension->high_isBool == true) {
		string high = (dimension->high == 1 ? "true" : "false");
		cout << high;
	}

	// If high value is an identifier.
	else if (dimension->high_isIdent == true) {
		if (dimension->high_ident != NULL) {
			cout << dimension->high_ident->getName();
		}
	}

	// If high value is a nil.
	else if (dimension->high_isNil == true) {
		cout << "nil";
	}

	// Otherwise, high value is an integer.
	else
		cout << dimension->high;
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value to the dimension of this SetType.
 *
 * Preconditions: None.
 *
 * Postconditions: The low dimension of this SetType was set.
 *
 * @param lowDim The low value of this SetType was set.
 */
void SetType::setLowDimension (int lowDim) {
	dimension->low = lowDim;
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the dimension of this SetType.
 *
 * Preconditions: None.
 *
 * Postconditions: The high value to the dimension of this SetType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this SetType.
 */
void SetType::setHighDimension (int highDim) {
	dimension->high = highDim;
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value to a new dimension of this RecordType.
 *
 * Preconditions: None.
 *
 * Postconditions: The low dimension of this SetType was set.
 *
 * @param lowDim The low value of this SetType was set.
 */
void SetType::setLowDimension (string lowDim) {
	dimension->low_ascii = true;
	dimension->str_low   = lowDim;
	// We're using the first char of string as ascii value.
	dimension->low       = (int)lowDim.at(0);
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the dimension of this SetType.
 *
 * Preconditions: None.
 *
 * Postconditions: The high value to the dimension of this SetType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this SetType.
 */
void SetType::setHighDimension (string highDim) {
	dimension->high_ascii = true;
	dimension->str_high   = highDim;
	// We're using the first char of string as ascii value.
	dimension->high       = (int)highDim.at(0);
}


//---------------------lowBool-------------------------------------------------
/**
 * @brief Sets the lower bound value to a boolean value.
 *
 * Preconditions: None.
 *
 * Postconditions: The lower bound was set to the provided value.
 *
 * @param lowBool The boolean value.
 */
void SetType::setLowBool (int lowBool) {
	dimension->low_isBool = true;
	dimension->low = lowBool;
}


//---------------------setHighBool---------------------------------------------
/**
 * @brief Sets the high bound value to a boolean value.
 *
 * Preconditions: None.
 *
 * Postconditions: The high bound was set to the provided value.
 *
 * @param highBool The boolean value.
 */
void SetType::setHighBool (int highBool) {
	dimension->high_isBool = true;
	dimension->high = highBool;
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value of a new dimension.
 *
 * Preconditions: lowDim is not NULL.
 *
 * Postconditions: A new dimension was created with the provided low value.
 *
 * @param lowDim The low value to a new dimension of this SetType.
 */
void SetType::setLowDimension (IdentifierRecord * lowDim) {

	if (lowDim != NULL) {
		dimension->low_isIdent = true;
		dimension->low_ident   = lowDim;
	}

	/* If it's NULL, it's a ynil token. */
	else {
		dimension->low_isNil = true;
	}
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the current dimension of this SetType.
 *
 * Preconditions: setLowDimension has already been called, which created a
 *                new dimension to the array and set it's low value.
 *
 * Postconditions: The high value to the dimension of this SetType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this SetType.
 */
void SetType::setHighDimension (IdentifierRecord *highDim) {
	if (highDim != NULL) {
		dimension->high_isIdent = true;
		dimension->high_ident   = highDim;
	}

	// If it's NULL, it's a ynil token. */
	else {
		dimension->high_isNil = true;
	}
}
