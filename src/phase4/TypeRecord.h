/******************************************************************************
 * @file TypeRecord.h                                                         *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - TypeRecord                             *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief TypeRecord represents a generic record type.                        *
 *****************************************************************************/

#ifndef TYPERECORD_H_
#define TYPERECORD_H_

#include "IdentifierRecord.h"

/**
 * @class TypeRecord
 */
class TypeRecord : public IdentifierRecord {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a TypeRecord with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This TypeRecord was instantiated.
	 *
	 * @param name The name of the TypeRecord
	 */
	TypeRecord(string name);


	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a TypeRecord with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This TypeRecord was instantiated.
	 *
	 * @param name The name of the TypeRecord
	 */
	virtual ~TypeRecord();


	//---------------------print-----------------------------------------------
	/**
	 * @brief Prints the data members of this IdentifierRecord to the standard
	 *        output stream.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: For every level of scope, three spaces were printed.
	 *
	 * @param scope The scope of this identifier (used for indenting purposes).
 	 */
	virtual void print(int scope);
};

#endif /* TYPERECORD_H_ */
