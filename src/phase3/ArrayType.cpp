/******************************************************************************
 * @file ArrayType.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ArrayType represents a ArrayType identifier.                        *
 *****************************************************************************/

#include "ArrayType.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a ArrayType with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This ArrayType was instantiated.
 *
 * @param name The name of the ArrayType.
 */
ArrayType::ArrayType(string name) : IdentifierRecord (name) {
	dimensions       = new vector <Dimension *> ();
	currentDimension = NULL;
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the
 *        ArrayType.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
ArrayType::~ArrayType() {
	dimensions->empty();
	delete dimensions;
	if (currentDimension != NULL) {
		delete currentDimension;
	}
	dimensions       = NULL;
	currentDimension = NULL;
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
void ArrayType::print(int scope) const {

	// Print the name.
	IdentifierRecord::print(scope);

	// Print the dimensions.
	for (int i = 0; i < (long)dimensions->size(); i++) {

		Dimension * dimension = dimensions->at(i);

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

		if ((i + 1) < (long)dimensions->size()) cout << ", ";
	}

	cout << " ";

	// Print the type.
	if (getType() != NULL) getType()->print(0);
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value to a new dimension of this ArrayType.
 *
 * Preconditions: None.
 *
 * Postconditions: A new dimension was created with the provided low value.
 *
 * @param lowDim The low value to a new dimension of this ArrayType.
	 */
void ArrayType::setLowDimension (int lowDim) {

	// If setLowDimension was called twice in a row w/out
	// completing it by calling setHighDimension.
	if (currentDimension != NULL) delete currentDimension;
	currentDimension = new Dimension ();
	currentDimension->low_isNil   = false;
	currentDimension->high_isNil  = false;
	currentDimension->low_isBool  = false;
	currentDimension->high_isBool = false;
	currentDimension->low_ascii   = false;
	currentDimension->high_ascii  = false;
	currentDimension->low_isIdent = false;
	currentDimension->high_isIdent= false;
	currentDimension->low_ident   = NULL;
	currentDimension->high_ident  = NULL;
	currentDimension->str_low     = "";
	currentDimension->str_high    = "";
	currentDimension->low         = 0;
	currentDimension->high        = 0;

	currentDimension->low = lowDim;
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the dimension of this ArrayType.
 *
 * Preconditions: setLowDimension has already been called, which created a
 *                new dimension to the array and set it's low value.
 *
 * Postconditions: The high value to the dimension of this ArrayType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this ArrayType.
	 */
void ArrayType::setHighDimension (int highDim) {
	if (currentDimension != NULL) {
		currentDimension->high = highDim;
		dimensions->push_back(currentDimension);
		currentDimension = NULL;
	}
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value of a new dimension.
 *
 * Preconditions: None.
 *
 * Postconditions: A new dimension was created with the provided low value.
 *
 * @param lowDim The low value to a new dimension of this ArrayType.
 */
void ArrayType::setLowDimension (string lowDim) {
	// If setLowDimension was called twice in a row w/out
	// completing it by calling setHighDimension.
	if (currentDimension != NULL) delete currentDimension;
	currentDimension = new Dimension ();
	currentDimension->low_isNil   = false;
	currentDimension->high_isNil  = false;
	currentDimension->low_isBool  = false;
	currentDimension->high_isBool = false;
	currentDimension->high_ascii  = false;
	currentDimension->low_isIdent = false;
	currentDimension->high_isIdent= false;
	currentDimension->low_ident   = NULL;
	currentDimension->high_ident  = NULL;
	currentDimension->str_high    = "";
	currentDimension->low         = 0;
	currentDimension->high        = 0;

	currentDimension->low_ascii   = true;
	currentDimension->str_low     = lowDim;
	currentDimension->low         = (int)lowDim.at(0);
}


//---------------------setLowDimenstion----------------------------------------
/**
 * @brief Sets the low value of a new dimension.
 *
 * Preconditions: lowDim is not NULL.
 *
 * Postconditions: A new dimension was created with the provided low value.
 *
 * @param lowDim The low value to a new dimension of this ArrayType.
 */
void ArrayType::setLowDimension (IdentifierRecord * lowDim) {
	// If setLowDimension was called twice in a row w/out
	// completing it by calling setHighDimension.
	if (currentDimension != NULL) delete currentDimension;
	currentDimension = new Dimension ();
	currentDimension->low_isNil   = false;
	currentDimension->high_isNil  = false;
	currentDimension->low_isBool  = false;
	currentDimension->high_isBool = false;
	currentDimension->low_ascii   = false;
	currentDimension->high_ascii  = false;
	currentDimension->low_isIdent = false;
	currentDimension->high_isIdent= false;
	currentDimension->low_ident   = NULL;
	currentDimension->high_ident  = NULL;
	currentDimension->str_low     = "";
	currentDimension->str_high    = "";
	currentDimension->low         = 0;
	currentDimension->high        = 0;

	if (lowDim != NULL) {
		currentDimension->low_isIdent = true;
		currentDimension->low_ident   = lowDim;
	}

	/* If it's NULL, it's a ynil token. */
	else {
		currentDimension->low_isNil = true;
	}
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the current dimension of this ArrayType.
 *
 * Preconditions: setLowDimension has already been called, which created a
 *                new dimension to the array and set it's low value.
 *
 * Postconditions: The high value to the dimension of this ArrayType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this ArrayType.
 */
void ArrayType::setHighDimension (IdentifierRecord *highDim) {

	if (currentDimension != NULL) {

		if (highDim != NULL) {
			currentDimension->high_isIdent = true;
			currentDimension->high_ident   = highDim;
		}

		// If it's NULL, it's a ynil token. */
		else {
			currentDimension->high_isNil = true;
		}

		dimensions->push_back(currentDimension);
		currentDimension = NULL;
	}
}


//---------------------setHighDimenstion---------------------------------------
/**
 * @brief Sets the high value to the current dimension of this ArrayType.
 *
 * Preconditions: setLowDimension has already been called, which created a
 *                new dimension to the array and set it's low value.
 *
 * Postconditions: The high value to the dimension of this ArrayType was
 *                 set to the provided value.
 *
 * @param highDim The high value to a dimension of this ArrayType.
 */
void ArrayType::setHighDimension (string highDim) {

	if (currentDimension != NULL) {
		currentDimension->high_ascii   = true;
		currentDimension->str_high     = highDim;
		currentDimension->high         = (int)highDim.at(0);
		dimensions->push_back(currentDimension);
		currentDimension = NULL;
	}
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
void ArrayType::setLowBool (int lowBool) {

	// If setLowBool was called twice in a row w/out
	// completing it by calling setHighDimension.
	if (currentDimension != NULL) delete currentDimension;
	currentDimension = new Dimension ();
	currentDimension->low_isNil   = false;
	currentDimension->high_isNil  = false;
	currentDimension->high_isBool = false;
	currentDimension->low_ascii   = false;
	currentDimension->high_ascii  = false;
	currentDimension->low_isIdent = false;
	currentDimension->high_isIdent= false;
	currentDimension->low_ident   = NULL;
	currentDimension->high_ident  = NULL;
	currentDimension->str_low     = "";
	currentDimension->str_high    = "";
	currentDimension->low         = 0;
	currentDimension->high        = 0;

	currentDimension->low_isBool  = true;
	currentDimension->low         = lowBool;
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
void ArrayType::setHighBool (int highBool) {

	if (currentDimension != NULL) {
			currentDimension->high_isBool = true;
			currentDimension->high        = highBool;
			dimensions->push_back(currentDimension);
			currentDimension = NULL;
	}
}
