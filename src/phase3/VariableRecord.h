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
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print VariableRecord.
 * 	- Allows clients to compare VariableRecord for equality.
 * 	- Allows clients to compare VariableRecords for less than value.
 */
//-----------------------------------------------------------------------------
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
};

#endif /* VARIABLERECORD_H_ */
