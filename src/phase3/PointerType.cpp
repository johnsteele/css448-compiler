/******************************************************************************
 * @file PointerType.h                                                        *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief PointerType represents a PointerType identifier.                    *
 *****************************************************************************/

#include "PointerType.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a PointerType with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This PointerType was instantiated.
 *
 * @param name The name of the PointerType.
 * @param ptr_name The name of the pointer it points to.
 */
PointerType::PointerType(string name, ptr_name) : IdentifierRecord (name) {
	my_name = ptr_name;
}


//---------------------Destructor----------------------------------------------
/**
 * @brief Deletes all dynamically allocated objects within the PointerType.
 *
 * Preconditions: None.
 *
 * Postconditions: Resources were released.
 */
PointerType::~PointerType() {}


//---------------------print---------------------------------------------------
/**
 * @brief Prints the data members of this IdentifierRecord to the output stream.
 *
 * Preconditions: Data members have been initialized.
 *
 * Postconditions: This IdentifierRecord's members have been printed.
 *
 * @param scope The scope of this identifier (used for indenting purposes).
 */
void PointerType::print(int scope) const {
	//IdentifierRecord::print (scope);
	cout << "^ " << my_name;
}


//---------------------setIdent------------------------------------------------
/**
 * @brief Sets the name of the identifier this PointerType points to.
 *
 * Preconditions: None.
 *
 * Postconditions: The name of the identifier this PointerType points to
 *                 was set.
 *
 * @param name The the_name of the identifier.
	 */
void PointerType::setIdent (IdentifierRecord * the_ident) {
	ident = the_name;
}


//---------------------getIdent------------------------------------------------
/**
 * @brief Returns the name of the identifier this pointer type points to.
 *
 * Preconditions: None.
 *
 * Postconditions: The name of the identifier this PointerType points to
 *                 was returned.
 *
 * @return The the_name of the identifier pointed to was returned.
	 */
string PointerType::getIdent () const {
	return my_name;
}
