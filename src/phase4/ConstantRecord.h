/******************************************************************************
 * @file ConstantRecord.h                                                     *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - ConstantRecord                         *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ConstantRecord represents a ConstantRecord identifier.              *
 *****************************************************************************/

#ifndef CONSTANTRECORD_H_
#define CONSTANTRECORD_H_

#include <string>

#include "IdentifierRecord.h"

/**
 * @class ConstantRecord
 */
class ConstantRecord : public IdentifierRecord  {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a ConstantRecord with the specified name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This ConstantRecord was instantiated.
	 *
	 * @param name The name of the ConstantRecord.
	 */
	ConstantRecord(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        ConstantRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~ConstantRecord();


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


	//---------------------setConstFactor--------------------------------------
	/**
	 * @brief Sets the int constant factor value for this constant.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The constant factor was set to the provided value.
	 *
	 * @param factor The constant factor value.
 	 */
	void setConstFactor (int factor);


	//---------------------setConstFactor--------------------------------------
	/**
	 * @brief Sets the string constant factor value for this constant.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The constant factor was set to the provided value.
	 *
	 * @param factor The constant factor value.
 	 */
	void setConstFactor (string factor);


	//---------------------setConstFactor--------------------------------------
	/**
	 * @brief Sets the constant factor value for this constant.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The constant factor was set to the provided value.
	 *
	 * @param factor The constant factor value.
 	 */
	void setConstFactor (IdentifierRecord * the_ident);


	//---------------------setIsBool-------------------------------------------
	/**
	 * @brief Sets this constant record as a bool value. With this set, the
	 *        const_factor represents true (1) or false (0) respectively.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The constant factor now represents a bool value.
	 */
	void setIsBool ();


	//---------------------setIsBool-------------------------------------------
	/**
	 * @brief Returns a bool value for if the constant factor of this
	 *        ConstantRecord is a string value.
	 *
	 * Preconditions: isString is initialized.
	 *
	 * Postconditions: True was returned if the constant factor is a string,
	 *                 returns false otherwise.
	 *
	 * @return True if the constant factor is a string, false otherwise.
	 */
	bool isStringType() const;


	//---------------------getConstVal-----------------------------------------
	/**
	 * @brief Returns the integer constant factor of this ConstantRecord.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The integer constant factor was returned.
	 *
	 * @return The integer constant factor.
	 */
	int getConstVal() const;

/**
 * @private
 */
//private:

	/**
	 * @brief The integer constant factor value.
	 */
	int int_const_factor;

	/**
	 * @brief The string constant factor value.
	 */
	string str_const_factor;

	/**
	 * @brief If this constant factor is a boolean value.
	 */
	bool isBool;

	/**
	 * @brief If this constant factor is a string value.
	 */
	bool isString;

	/**
	 * @brief If this constant factor is an identifier.
	 */
	bool isIdent;

	/**
	 * @brief The identifier if the const factor is an identifier.
	 */
	IdentifierRecord * ident;

	/**
	 * @brief If the const factor is nil.
	 */
	bool isNil;
};

#endif /* CONSTANTRECORD_H_ */
