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
#ifndef ARRAYTYPE_H_
#define ARRAYTYPE_H_

#include <vector>
#include "IdentifierRecord.h"

/**
 * @class ArrayType
 */
class ArrayType : public IdentifierRecord  {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a ArrayType with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This ArrayType was instantiated.
	 *
	 * @param name The name of the ArrayType.
	 */
	ArrayType(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        ArrayType.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~ArrayType();


	//---------------------print-----------------------------------------------
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
	virtual void print (int scope) const;


	//---------------------setLowDimenstion------------------------------------
	/**
	 * @brief Sets the low value to a new dimension of this ArrayType.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: A new dimension was created with the provided low value.
	 *
	 * @param lowDim The low value to a new dimension of this ArrayType.
 	 */
	void setLowDimension (int lowDim);


	//---------------------setHighDimenstion-----------------------------------
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
	void setHighDimension (int highDim);


	//---------------------isAscii---------------------------------------------
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
	void isAscii ();


/**
 * @private
 */
private:

	/**
	 * @brief A dimension in the the array.
	 */
	struct Dimension {
		int low;
		int high;
		bool isAscii;
	};

	/**
	 * @brief The total number of dimensions in the array.
	 */
	int totalDimensions;

	/**
	 * @brief The current dimension being built.
	 */
	Dimension * currentDimension;

	/**
	 * @brief The dimensions in the array.
	 */
	vector <Dimension *> * dimensions;
};

#endif /* ARRAYTYTPE_H_ */
