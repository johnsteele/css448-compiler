/******************************************************************************
 * @file SITtable.h                                                           *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - SITtable                               *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief SITtable represents a standard identifier table.                    *
 *****************************************************************************/
//-----------------------------------------------------------------------------
/**
 * Includes following features:
 * 	- Allows clients to lookup an identifier.
 */
//-----------------------------------------------------------------------------

#ifndef SITtable_H_
#define SITtable_H_

#include <iostream>
#include <string>
#include <vector>

/**
 * @namespace std
 */
using namespace std;

/**
 * @class SITtable
 */
class SITtable {

/**
 * @public
 */
public:

	//---------------------Constructor-----------------------------------------
	/**
 	 * @brief Creates an SITtable object with the specified value.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The name of the identifier was set.
	 *
	 * @param the_name The name of this identifier.
 	 */
	SITtable ();


	//---------------------Destructor------------------------------------------
	/**
 	 * @brief Deletes the vector of identifiers.
 	 *
	 * Preconditions: None.
	 *
	 * Postconditions: The identifier vector was deleted.
 	 */
	~SITtable ();


	//---------------------print-----------------------------------------------
	/**
	 * @brief Checks if the provided identifier is in this SIT.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Returns true if found, false otherwise.
	 *
	 * @param ident The identifier to lookup.
	 *
	 * @return True if found, false otherwise.
 	 */
	bool lookup (const string ident) const;


/**
 * @private
 */
private:

	//---------------------initIdents------------------------------------------
	/**
	 * @brief Initializes the standard identifiers.
	 *
	 * Preconditions: standard_idents was instantiated.
	 *
	 * Postconditions: Returns true if found, false otherwise.
 	 */
	void initIdents ();

	/**
	 * @brief The type of this identifier.
	 */
	vector <string> * standard_idents;
};

#endif /* SITTABLE_H_ */
