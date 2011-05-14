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
	totalDimensions  = 0;
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
	delete dimensions;
	if (currentDimension != NULL)
		delete currentDimension;
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
		Dimension * dim = dimensions->at(i);
		if (dim->isAscii == true) {
			int low = dim->low + '0';
			int high = dim->high + '0';
			cout << low << ".." << high;
		}
		else {
			cout << dim->low << ".." << dim->high;
		}
		if ((i + 1) < (long)dimensions->size()) cout << ", ";
	}

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


//---------------------isAscii-------------------------------------------------
/**
 * @brief Sets the current dimension's low and high values as
 *        Ascii value.
 *
 * Preconditions: setLowDimension must be called prior to calling
 *                this method.
 *
 * Postconditions: The current dimension's low and high value have been
 *                 marked as ascii values.
 */
void ArrayType::isAscii () {
	currentDimension->isAscii = true;
}
