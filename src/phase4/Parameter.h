/******************************************************************************
 * @file Parameter.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - Parameter                              *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief Parameter represents a Parameter identifier.                        *
 *****************************************************************************/
#ifndef PARAMETER_H_
#define PARAMETER_H_

#include "IdentifierRecord.h"

/**
 * @class Parameter
 */
class Parameter : public IdentifierRecord  {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a Parameter with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This Parameter was instantiated.
	 *
	 * @param name The name of the Parameter.
	 * @param is_var If this identifier is a variable.
	 */
	Parameter(string name, bool is_var);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        Parameter.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~Parameter();


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
	virtual void print (int scope);


	//---------------------setIsVar--------------------------------------------
	/**
	 * @brief Sets this parameter as a var.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This var is now marked as a var.
 	 */
	void setIsVar ();

/**
 * @public
 */
private:

	/**
	 * @brief If this identifier is a variable.
	 */
	bool isVar;
};

#endif /* PARAMETER_H_ */
