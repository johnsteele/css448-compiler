/******************************************************************************
 * @file SITtype.h                                                            *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - SITtype                                *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief SITtype represents a standard identifier type.   		              *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to compare SITtypes for equality.
 * 	- Allows clients to compare SITtypes for less than value.
 *	- Allows clients to print the SITtype.
 */
//-----------------------------------------------------------------------------

#ifndef SITTYPE_H_
#define SITTYPE_H_

#include <iostream>
#include <string>

/**
 * @namespace std
 */
using namespace std;

/**
 * @class SITtype
 */
class SITtype {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
 	 * @brief Creates an SITtype object with the specified value.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The name of the identifier was set.
	 *
	 * @param the_name The name of this identifier.
 	 */
	SITtype (string the_name);


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
	virtual bool operator< (const SITtype &the_other) const = 0;


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
	 * @return True if the_other is equal to this SITtype,
	 *	       false otherwise.
 	 */
	virtual bool operator== (const SITtype &the_other) const = 0;


	//---------------------print-----------------------------------------------
	/**
	 * @brief Prints the data members of this SITtype to the standard
	 *        output stream.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: For every level of scope, three spaces were printed.
 	 */
	void print () const;


	//---------------------getName---------------------------------------------
	/**
	 * @brief An accessor method for derived classes.
	 *
	 * Preconditions: name is initialized.
	 *
	 * Postconditions: name was returned.
	 *
	 * @return The name of this SITtype.
	 */
	const string getType () const;

/**
 * @private
 */
private:

	/**
	 * @brief The type of this identifier.
	 */
	string type;
};

#endif /* SITTYPE_H_ */
