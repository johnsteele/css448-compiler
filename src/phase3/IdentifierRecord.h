/******************************************************************************
 * @file IdentifierRecord.h                                                   *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentifierRecord                       *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief IdentifierRecord in an abstract base class for all identifier types *
 *        to inherit from.                       					          *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 *	- Allows client to << a IdentifierRecord.
 * 	- Allows clients to compare IdentifierRecords for equality.
 * 	- Allows clients to compare IdentifierRecords for less than value.
 *	- Allows clients to print the IdentifierRecord.
 *
 * Assumptions:
 * 	- All derived classes of IdentifierRecord implement getNewInstance,
 * 	  and within the method return a dynamically allocated object of
 *	  the derived type.
 */
//-----------------------------------------------------------------------------

#ifndef IDENTIFIERRECORD_H_
#define IDENTIFIERRECORD_H_

#include <iostream>
#include <fstream>
#include <string>

/**
 * @namespace std
 */
using namespace std;

/**
 * @class IdentifierRecord
 */
class IdentifierRecord {

	//---------------------operator<<------------------------------------------
	/**
	 * @brief Overloaded output operator.
	 *
	 * Preconditions: The IdentfierRecord is not NULL.
	 *
	 * Postconditions: The data members of IdentfierRecord have been sent to
	 *                 the output stream.
	 *
	 * @param output The output stream.
	 * @param item The IdentfierRecord to output.
	 *
	 * @return The output stream.
	 */
	friend ostream& operator<< (ostream &output, const IdentifierRecord &ident)
	{
		ident.print(output);
		return output;
	}

/**
 * @public
 */
public:

	//---------------------Default Constructor---------------------------------
	/**
 	 * @brief Creates an IdentifierRecord object with default values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The data members of this IdentifierRecord have been
	 *		           initialized with default values.
 	 */
	IdentifierRecord ();


	//---------------------Constructor-----------------------------------------
	/**
 	 * @brief Creates an IdentifierRecord object with the specified values.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The data members of this Item have been set to the
	 *                 specified values.
	 *
	 * @param the_name The name of this identifier.
	 * TODO: finish params, if anymore are needed.
 	 */
	IdentifierRecord (string the_name);


	//---------------------Destructor------------------------------------------
	/**
 	 * @brief Deletes all memory associated with this identifier.
	 *
 	 * Preconditions: None.
	 *
 	 * Postconditions: Resources have been released.
	 */
	virtual ~IdentifierRecord ();


	//---------------------clone-----------------------------------------------
	/**
	 * @brief Clones this IdentifierRecord.
	 *
	 * Preconditions: None.
	 *
 	 * Postconditions: A pointer to a cloned identfifier is returned.
	 *
	 * @return The pointer to the cloned object.
	 */
	virtual IdentifierRecord * clone () const = 0;


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
	virtual bool operator< (const IdentifierRecord &the_other) const = 0;


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
	virtual bool operator== (const IdentifierRecord &the_other) const = 0;


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


/**
 * @protected
 */
protected:

	//---------------------getName---------------------------------------------
	/**
	 * @brief An accessor method for derived classes to use for comparisons.
	 *
	 * Preconditions: name is initialized.
	 *
	 * Postconditions: name was returned.
	 *
	 * @return The name of this IdentifierRecord.
	 */
	const string getName () const;


/**
 * @private
 */
private:

	/**
	 * @brief The name of this identifier.
	 */
	string name;
};

#endif /* IDENTIFIERRECORD_H_ */
