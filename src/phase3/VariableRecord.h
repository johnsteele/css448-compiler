/******************************************************************************
 * @file VariableRecord.h                                                     *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief VariableRecord represents an variable identifier.                   *
 *****************************************************************************/

#ifndef VARIABLERECORD_H_
#define VARIABLERECORD_H_

#include "IdentifierRecord.h"

/**
 * @class VariableRecord
 */
class VariableRecord : public IdentifierRecord  {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a VariableRecord with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This VariableRecord was instantiated.
	 *
	 * @param name The name of the VariableRecord.
	 */
	VariableRecord(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        VariableRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~VariableRecord();


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

#endif /* VARIABLERECORD_H_ */
