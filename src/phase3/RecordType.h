/******************************************************************************
 * @file ArrayType.h                                                          *
 *                                                                            *
 * @brief CSS 448 - Compiler Phase 3 - IdentRecord                            *
 *                                                                            *
 * @author John Steele      \<steelejr@u.washington.edu\>                     *
 * @author Alicia Flinchum  \<aliciaflinchum@yahoo.com\>                      *
 *                                                                            *
 * @version 1.0.0                                                             *
 * @date May 1, 2011                                                          *
 *                                                                            *
 * @brief ArrayType represents a ArrayType identifier.                        *
 *****************************************************************************/

#ifndef RECORDTYPE_H_
#define RECORDTYPE_H_

#include <string>
#include <vector>

#include "IdentifierRecord.h"
#include "TypeRecord.h"

class RecordType : public IdentifierRecord {
public:

	//---------------------Constructor-----------------------------------------
	/**
	 * @brief Creates a RecordType with the provided name.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: This RecordType was instantiated.
	 *
	 * @param name The name of the RecordType.
	 */
	RecordType(string name);


	//---------------------Destructor------------------------------------------
	/**
	 * @brief Deletes all dynamically allocated objects within the
	 *        RecordType.
	 *
	 * Preconditions: None.
	 *
	 * Postconditions: Resources were released.
	 */
	virtual ~RecordType();


	//---------------------addField--------------------------------------------
	/**
	 * @brief Adds the provided field to this Record.
	 *
	 * Preconditions: The field is not NULL.
	 *
	 * Postconditions: The field, and its name were added to this Record.
	 *
	 * @param type The type of field.
	 * @param name The name fo the field.
	 */
	void addField (const IdentifierRecord * type, string name);


	//---------------------print-----------------------------------------------
	/**
	 * @brief Prints the data members of this RecordType to the
	 *        output stream.
	 *
	 * Preconditions: Data members have been initialized.
	 *
	 * Postconditions: This RecordType members have been printed.
	 *
	 * @param scope The scope of this identifier (used for indenting purposes).
 	 */
	virtual void print (int scope) const;


private:

	/**
	 * @brief A field in the Record.
	 */
	struct Field {
		/* The type for this field. */
		const IdentifierRecord * type;
		/* The name of this field. */
		string name;
	};

	/**
	 * @brief The list of fields fot this record.
	 */
	vector<Field *> * field_list;
};

#endif /* RECORDTYPE_H_ */
