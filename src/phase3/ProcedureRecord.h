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

	/**
	 * @brief The arguments of this procedure.
	 */
	vector<IdentifierRecord *> * args;

	/**
	 * @brief The function return type.
	 */
	IdentifierRecord * returnType;
};

#endif /* PROCEDURERECORD_H_ */
