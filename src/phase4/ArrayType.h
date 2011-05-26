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
	virtual void print (int scope);


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


	//---------------------setLowDimenstion------------------------------------
	/**
	 * @brief Sets the low value of a new dimension.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: A new dimension was created with the provided low value.
	 *
	 * @param lowDim The low value to a new dimension of this ArrayType.
 	 */
	void setLowDimension (string lowDim);


	//---------------------setHighDimenstion-----------------------------------
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
	void setHighDimension (string highDim);


	//---------------------setLowDimenstion------------------------------------
	/**
	 * @brief Sets the low value of a new dimension.
	 *
	 * Preconditions: lowDim is not NULL.
	 *
	 * Postconditions: A new dimension was created with the provided low value.
	 *
	 * @param lowDim The low value to a new dimension of this ArrayType.
 	 */
	void setLowDimension (IdentifierRecord * lowDim);


	//---------------------setHighDimenstion-----------------------------------
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
	void setHighDimension (IdentifierRecord *highDIm);


	//---------------------lowBool---------------------------------------------
	/**
	 * @brief Sets the lower bound value to a boolean value.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The lower bound was set to the provided value.
	 *
	 * @param lowBool The boolean value.
	 */
	void setLowBool (int lowBool);


	//---------------------setHighBool-----------------------------------------
	/**
	 * @brief Sets the high bound value to a boolean value.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The high bound was set to the provided value.
	 *
	 * @param highBool The boolean value.
	 */
	void setHighBool (int highBool);


/**
 * @private
 */
//private:

	/**
	 * @brief A dimension in the the array.
	 */
	struct Dimension {

		/* If range is integer. */
		int low;
		int high;

		/*
		 * If low or high value is a string.
		 * If so, the value used is the first char of the string.
		 * It is converted to ascii, and that bool flag is set.
		 */
		string str_low;
		string str_high;

		/* If low or high is an identifier. */
		IdentifierRecord * low_ident;
		IdentifierRecord * high_ident;

		/* If low or high value is represented as ascii. */
		bool low_ascii;
		bool high_ascii;

		/* If low or high value is boolean. The low and high int's are used.*/
		bool low_isBool;
		bool high_isBool;

		/* If low or high is an identifier. */
		bool low_isIdent;
		bool high_isIdent;

		/* If low or high is a NIL */
		bool low_isNil;
		bool high_isNil;
	};

	/**
	 * @brief The current dimension being built.
	 */
	Dimension * currentDimension;
        bool isInt;
        bool isChar;
	/**
	 * @brief The dimensions in the array.
	 */
	vector <Dimension *> * dimensions;
};

#endif /* ARRAYTYTPE_H_ */
