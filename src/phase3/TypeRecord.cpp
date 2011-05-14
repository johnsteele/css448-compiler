/******************************************************************************
 * @file TypeRecord.h                                                         *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - TypeRecord                             *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief TypeRecord represents a generic record type.                        *
 *****************************************************************************/

#include "TypeRecord.h"

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a TypeRecord with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This TypeRecord was instantiated.
 *
 * @param name The name of the TypeRecord
 */
TypeRecord::TypeRecord(string name) : IdentifierRecord (name){

}

//---------------------Constructor---------------------------------------------
/**
 * @brief Creates a TypeRecord with the provided name.
 *
 * Preconditions: None.
 *
 * Postconditions: This TypeRecord was instantiated.
 *
 * @param name The name of the TypeRecord
 */
TypeRecord::~TypeRecord() {

}
