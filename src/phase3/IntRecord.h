/******************************************************************************
 * @file IntRecord.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
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

class IntRecord : public IdentifierRecord  {

public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a IntRecord with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This IntRecord was instantiated.
	 *
	 * @param name The name of the ProcedureRecord.
	 */
	IntRecord(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the IntRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~IntRecord();


	//---------------------clone-----------------------------------------------
	/**
	 * @brief Clones this IdentifierRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: A pointer to a cloned identifier is returned.
	 *
	 * @return The pointer to the cloned object.
	 */
	virtual IntRecord * clone () const;


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
	 * @param output The output stream.
	 */
	virtual void print (ostream &output) const;

};

#endif /* INTRECORD_H_ */
