/******************************************************************************
 * @file IntRecord.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentifierRecord                       *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief IntRecord represents an integer identifier. 				          *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to << an IntRecord.
 * 	- Allows clients to compare IntRecord for equality.
 * 	- Allows clients to compare IntRecords for less than value.
 *	- Allows clients to print the IntRecord.
 */
//-----------------------------------------------------------------------------
#ifndef INTRECORD_H_
#define INTRECORD_H_

#include "IdentifierRecord.h"

class IntRecord : public IdentifierRecord {
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a IntRecord with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This IntRecord was instantiated.
	 */
	IntRecord();


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the IntRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~IntRecord();
};

#endif /* INTRECORD_H_ */
