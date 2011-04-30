
#include "SymbolTable.h"


SymbolTable::SymbolTable() {
	hashTable = new vector<IdentifierRecord *>();
}

SymbolTable::~SymbolTable() {

}
