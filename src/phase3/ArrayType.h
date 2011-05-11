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
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print ArrayType.
 * 	- Allows clients to compare ArrayType for equality.
 * 	- Allows clients to compare ArrayTypes for less than value.
 */
//-----------------------------------------------------------------------------
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
	virtual bool operator< (const IdentifierRecord &the_other) const;


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
	virtual bool operator== (const IdentifierRecord &the_other) const;


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
