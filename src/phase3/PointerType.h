/******************************************************************************
 * @file PointerType.h                                                        *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief PointerType represents a PointerType identifier.                    *
 *****************************************************************************/
#ifndef POINTERTYPE_H_
#define POINTERTYPE_H_

#include "IdentifierRecord.h"

/**
 * @class PointerType
 */
class PointerType : public IdentifierRecord  {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a PointerType with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This PointerType was instantiated.
	 *
	 * @param name The name of the PointerType.
	 */
	PointerType(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        PointerType.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~PointerType();


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
};

#endif /* POINTERTYTPE_H_ */
