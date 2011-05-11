/******************************************************************************
 * @file ProcedureRecord.h                                                    *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - ProcedureRecord                        *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ProcedureRecord represents a function or procedure identifier.      *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to print ProcedureRecord.
 * 	- Allows clients to compare ProcedureRecord for equality.
 * 	- Allows clients to compare ProcedureRecords for less than value.
 * 	- Allows clients to insert a Parameter for the procedure.
 */
//-----------------------------------------------------------------------------
#ifndef PROCEDURERECORD_H_
#define PROCEDURERECORD_H_

#include <vector>
#include "IdentifierRecord.h"
#include "Parameter.h"

/**
 * @class ProcedureRecord
 */
class ProcedureRecord: public IdentifierRecord {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a ProcedureRecord with the specified name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This ProcedureRecord was instantiated.
	 *
	 * @param name The name of the ProcedureRecord.
	 */
	ProcedureRecord(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        ProcedureRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~ProcedureRecord();


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
	virtual bool operator<(const IdentifierRecord &the_other) const;


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
	virtual bool operator==(const IdentifierRecord &the_other) const;


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


	//---------------------insertParam-----------------------------------------
	/**
	 * @brief Inserts the provided Parameter into this Procedure.
	 *
	 * Preconditions: parameter is not NULL.
	 *
	 * Postconditions: The parameter is not NULL.
	 *
	 * @param parameter The parameter to add to this Procedure.
 	 */
	void insertParam (Parameter * parameter);


	//---------------------setReturnType---------------------------------------
	/**
	 * @brief Sets the return type of this Procedure to the provided
	 *        return type.
	 *
	 * Preconditions: returnType is not NULL.
	 *
	 * Postconditions: The return type was set.
	 *
	 * @param the_returnType The return type for this Procedure.
 	 */
	void setReturnType (IdentifierRecord * the_returnType);


/**
 * @private
 */
private:

	vector<IdentifierRecord *> * args;
	IdentifierRecord * returnType;
};

#endif /* PROCEDURERECORD_H_ */
