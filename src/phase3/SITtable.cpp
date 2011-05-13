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

#include "SITtable.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates an SITtable object with the specified value.
 *
 * Preconditions: None.
 *
 * Postconditions: The name of the identifier was set.
 *
 * @param the_name The name of this identifier.
 */
SITtable::SITtable () {
	standard_idents = new vector<string> ();
	initIdents();
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes the vector of identifiers.
 *
 * Preconditions: None.
 *
 * Postconditions: The identifier vector was deleted.
 */
SITtable::~SITtable() {
	delete standard_idents;
	standard_idents = NULL;
}


//---------------------initIdents------------------------------------------
/**
 * @brief Initializes the standard identifiers.
 *
 * Preconditions: standard_idents was instantiated.
 *
 * Postconditions: Returns true if found, false otherwise.
	 */
void SITtable::initIdents () {
	standard_idents->push_back("False");
	standard_idents->push_back("True");
	standard_idents->push_back("Integer");
	standard_idents->push_back("Boolean");
	standard_idents->push_back("Real");
	standard_idents->push_back("Char");
	standard_idents->push_back("Abs");
	standard_idents->push_back("ArcTan");
	standard_idents->push_back("Chr");
	standard_idents->push_back("Cos");
	standard_idents->push_back("EOF");
	standard_idents->push_back("EOLN");
	standard_idents->push_back("Exp");
	standard_idents->push_back("Ln");
	standard_idents->push_back("Odd");
	standard_idents->push_back("Ord");
	standard_idents->push_back("Pred");
	standard_idents->push_back("Round");
	standard_idents->push_back("Sin");
	standard_idents->push_back("Sqr");
	standard_idents->push_back("Sqrt");
	standard_idents->push_back("Succ");
	standard_idents->push_back("Trunc");
	standard_idents->push_back("Get");
	standard_idents->push_back("New");
	standard_idents->push_back("Dispose");
	standard_idents->push_back("Pack");
	standard_idents->push_back("Page");
	standard_idents->push_back("Put");
	standard_idents->push_back("Read");
	standard_idents->push_back("Readln");
	standard_idents->push_back("Reset");
	standard_idents->push_back("Rewrite");
	standard_idents->push_back("Unpack");
	standard_idents->push_back("Write");
	standard_idents->push_back("Writeln");
}


//---------------------print---------------------------------------------------
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
bool SITtable::lookup(const string ident) const {

	// Check in identifier vector.
	for (int i = 0; i < (long) standard_idents->size(); i++)
		if (standard_idents->at(i) == ident) return true;

	// Not found.
	return false;
}
