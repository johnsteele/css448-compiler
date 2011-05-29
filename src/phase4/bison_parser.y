   /***************************************************************************
   *   @file   css448-compiler/src/phase2/bison_parser.y                     *
   *   @author John Steele     <EMAIL:programjsteele {at} gmail {dot} com>   *
   *   @author Alicia Flinchum <EMAIL:aliciaflinchum {at} yahoo {dot} com>   *
   *   @version 1.0.0                                                        *
   *   @date  Created: Fri 15 Apr 2011 11:05:24 AM PDT \n                    *
   *   Last Update: Sat 16 Apr 2011 11:05:24 AM PDT                          *
   *                                                                         *
   *   Description: This is a parser for a Pascal-like Language used for     *
   *               a compiler project in css-448. It is to be used with      *
   *               the (f)lex scanner built in phase1                        *
   **************************************************************************/


   /************************ C-Declarations Section **************************/
%{

#include <iostream>
#include <stdlib.h>
#include <stack>
#include <queue>
using namespace std;

#include "SymbolTable.h"
#include "IdentifierRecord.h"
#include "ProcedureRecord.h"
#include "ConstantRecord.h"
#include "Parameter.h"
#include "ArrayType.h"
#include "PointerType.h"
#include "TypeRecord.h"
#include "SITtype.h"
#include "SITtable.h"
#include "SetType.h"
#include "RecordType.h"


SymbolTable * table = NULL;         //points to symbolTable

ProcedureRecord * program = NULL;   //used to always hold program record
ProcedureRecord * aProcedure = NULL;//holds procedure in current scope

ConstantRecord * constant = NULL; //holds const variable while being entered
string uOperator = "";          //keeps track of unary operator
IdentifierRecord * aType = NULL;    //holds type vaiable while being entered
IdentifierRecord * subType = NULL;  //holds type of type variable while being entered
Parameter * param = NULL;       //holds parameter while being entered

ArrayType * array = NULL;       //holds array while being setup and entered
PointerType * pointer = NULL; //holds pointer type while being entered
RecordType * rec = NULL;
SetType * set = NULL;          //holds set type while being entered
bool isArray = false;          //used to determine if subrange is for array or set
bool isPointer = false;
bool isRecord = false;
Parameter * v = NULL;    //used to hold variable while entering into vector
queue <Parameter *> vars; //holds vector of vars for identlist
stack <IdentifierRecord *> subTypes; //holds typed
IdentifierRecord * nullPtr = NULL;
bool isFound = false;

bool isNum = false;
bool isNil = false;
bool isTrue = false;
bool isFalse = false;
SITtable sitTable; //points to SIT table
string name = "";
bool validType = false;
bool validVar = false;
bool validConst = false;
TypeRecord* anInt = new TypeRecord("integer");
TypeRecord* aReal = new TypeRecord("real");
TypeRecord* aBool = new TypeRecord("boolean");
TypeRecord* aChar = new TypeRecord("char");
queue <IdentifierRecord*> pointerHolder;
int indent = 0;
//void setLowVal();
int constType = -1;
bool inElse = false;
int countIfs = 0;
string typeString = "";
bool forUp = false;
%}


   /*********************** Yacc-Declarations Section ************************/
%start  CompilationUnit
%token  yand yarray yassign ybegin ycaret ycase ycolon ycomma yconst ydispose
      ydiv ydivide ydo  ydot ydotdot ydownto yelse yend yequal yfalse
      yfor yfunction ygreater ygreaterequal yident  yif yin yleftbracket
      yleftparen yless ylessequal yminus ymod ymultiply ynew ynil ynot
      ynotequal ynumber yof  yor yplus yprocedure yprogram yread yreadln
      yrecord yrepeat yrightbracket yrightparen  ysemicolon yset ystring
      ythen  yto ytrue ytype  yuntil  yvar ywhile ywrite ywriteln
      yunknown


%union
{
   /* The identifier which is set from within the lexer. */
   char * str;
   int int_value;
   bool b;
}


/************************* Grammar Rules Section *************************/
%%

/**************************  Pascal program **********************************/

CompilationUnit    : ProgramModule
                   ;
ProgramModule      : yprogram 
                   {
                        table = new SymbolTable();
                   }
                     Identifier
                   {
                            program = new ProcedureRecord(name);
                            table->enterScope(program);
                            cout<< "#include <iostream>"    <<endl;
                            cout<< "using namespace std;"   << endl << endl;
                            cout<< "int " << name <<" () {" << endl << endl;
                   }
                     ProgramParameters ysemicolon Block  ydot
                   {
                         cout << "return 0;" << endl;
                         cout << "}" << endl;

                        //table->printTable();
                        //delete table;
                        //delete anInt;
                        //delete aChar;
                        //delete aBool;
                        //delete aReal;
                        table = NULL;
                        anInt = NULL;
                        aChar = NULL;
                        aBool = NULL;
                        aReal = NULL;
                   }
                   ;
ProgramParameters  : yleftparen  ParamList yrightparen //added paramlist to differentiate
                   ;
ParamList          : ParamList ycomma Identifier
                   { 
                        param = new Parameter(name, false);
                        ProcedureRecord &r = dynamic_cast<ProcedureRecord &> (*program);
                        r.insertParam(param);
                   }
                   | Identifier
                   {
                        param = new Parameter(name, false);
                        ProcedureRecord &r = dynamic_cast<ProcedureRecord &> (*program);
                        r.insertParam(param);
                   }
                   ;
IdentList          :  Identifier 
                   {
                        if(!table->lookupScope(name)){
                          v = new Parameter(name, false );
							     vars.push(v);
                          v = NULL;

                        }

                        else {
                          cout << "Error: (" << name << ") already exists in this scope." << endl;
                        }
				       }
                   |  IdentList ycomma Identifier
                   {
                        if(!table->lookupScope(name)){
                          v = new Parameter(name, false );
							     vars.push(v);
                          v = NULL;
                        }

                        else
                          cout<< "Error: (" <<name<<") already exists in this scope."<<endl;
				       }
				       ;
Identifier         :  yident
                   {
                        name = yylval.str;
                        for (int i = 0; yylval.str[i] != '\0'; i++) {
                           name.at(i) = tolower (name[i]);
                        }
                        delete yylval.str;
                   }
                   ;
/* We need to put the print Identifier here. */
/**************************  Declarations section ***************************/

Block             :  Declarations  ybegin  StatementSequence  yend
                  ;
Declarations      :  ConstantDefBlock TypeDefBlock VariableDeclBlock SubprogDeclList
                  ;
ConstantDefBlock  :  /*** empty ***/
                  |  yconst ConstantDefList
                  ;
ConstantDefList   :  ConstantDef
                  {
						if(validConst){
							table->addSymbol(constant);
                     cout<<"const "<<typeString<<" ";
                     constant->print(0);
                     cout<<";"<<endl;
						}
				  }
                     ysemicolon
                  |  ConstantDefList ConstantDef 
                  {
					    if(validConst){
							table->addSymbol(constant);
                     cout<<"const "<<typeString<<" ";
                     constant->print(0);
                     cout<<";"<<endl;
						}
				  }
                     ysemicolon
                  ;
TypeDefBlock      :  /*** empty ***/
                  |  ytype  TypeDefList
                     {
                        while(!pointerHolder.empty()){
                           TypeRecord &type = dynamic_cast<TypeRecord &>(*pointerHolder.front());
                           PointerType &p = dynamic_cast<PointerType &> (*type.getType());

                           if(table->lookup(p.getIdent())){

                              p.setType(table->retrieve(p.getIdent()));
                              table->addSymbol(pointerHolder.front());
                              pointerHolder.front() = NULL;
                              pointerHolder.pop();
                           }
                           else{
                              cout<<"Error: Unable to instantiate pointer " << pointerHolder.front()->getName();
                              cout<<". Pointer type does not exist in this scope. "<<endl;

                              pointerHolder.pop();
                           }


                        }
                     }
                  ;
TypeDefList       :  TypeDef ysemicolon
                  { 
                     if(validType){
                        table->addSymbol(aType);
                        cout<< "typedef ";
                        if(aType->type->name == "_array"){

                           ArrayType &a = dynamic_cast<ArrayType &>(*aType->type);
                           if(a.type->getName() == "integer")
                              cout<< "int ";
                           cout<<aType->name;
                           a.print(0);
                           cout<<";"<<endl;
                        }
                     }
					    
                        else {
						    cout<<"Error: "<< name <<" is an invalid type."<<endl;
						} 
				  }
                  |  TypeDefList TypeDef ysemicolon
                  {
						if(validType){
							table->addSymbol(aType);
                        }
									
					    else{
						    cout<<"Error: "<< name <<" already exists in this scope."<<endl;
						} 
				  }
                  ;
VariableDeclBlock :  /*** empty ***/
                  |  yvar VariableDeclList
                  ;
VariableDeclList  :  VariableDecl ysemicolon
                  |  VariableDeclList VariableDecl ysemicolon
                  ;
ConstantDef       :  Identifier
                     {
							if(!table->lookupScope(name)){
								constant = new ConstantRecord(name);
								validConst = true;
							 }
							 else{
								cout<<"Identifier already exists in this scope."<<endl;
								validConst = false;
							 }
							}
                     yequal  ConstExpression
                     
                  ;
TypeDef           :  Identifier

                     { 	
                        if(!table->lookupScope(name)){
								   aType = new TypeRecord(name);
									validType = true;
									}
									
								else{
								   cout<< "Error: Type " << name <<" already exists in this scope." <<endl;
									validType = false;
								}
							}
                     yequal 
                     Type 
                     {
                       if(validType && aType != NULL){
							   aType->setType(subTypes.top());
                        subTypes.top() = NULL;
                        subTypes.pop();
							  }
							}
                  ;
VariableDecl      :  IdentList
                     ycolon  Type 
                     {
                        if(validType){
                           while(!vars.empty()){
                                 vars.front()->setType(subTypes.top());

                                 if(vars.front()->getType()->getName() == "integer")
                                   cout<< "int";
                                 else if(subTypes.top()->getName() == "real")
                                   cout<<"float";
                                 else if(subTypes.top()->getName() == "char")
                                    cout<<"char";
                                 else if(subTypes.top()->getName() == "boolean")
                                    cout<<"bool";
                                 else
                                    cout<<subTypes.top()->getName();

                                 cout<<" "<<vars.front()->getName()<<";"<<endl;
                                 table->addSymbol(vars.front());
                                 vars.front() = NULL;
                                 vars.pop();
                           }
                           subTypes.top() = NULL;
                           subTypes.pop();
                        }
                        else{
                           while(!vars.empty()){
                               vars.pop();
                           }
                        }
                        validType = true;
                      }
                  ;

/***************************  Const/Type Stuff  ******************************/

ConstExpression   :  UnaryOperator ConstFactor 
							{if(validConst){
								  if(constType == 0 && uOperator != "-")
									{
										int n = yylval.int_value;
                              typeString = "int";
										constant-> setConstFactor(n);
										isNum = false;
										uOperator = "";
                              typeString = "int";
									}
								  else if(constType == 0 && uOperator == "-")
									{
										int n = yylval.int_value * -1;
                              typeString = "int";
										constant-> setConstFactor(n);
										isNum = false;
										uOperator = "";
                              typeString = "int";
									}
									else if(constType == 1)
									{
                              constant->setIsBool();
										constant-> setConstFactor(1);
										uOperator = "";
                              typeString = "bool";

									}
                           else if(constType == 2)
									{
                              constant->setIsBool();
										constant-> setConstFactor(0);
										uOperator = "";
                              typeString = "bool";

									}

                           else if(constType == 3)
                           {
                              constant ->setConstFactor(nullPtr);
										uOperator = "";
                              typeString = "NULL";
									}
									else if (constType == 4){
										if(table->lookup(name))
                            	  constant->setConstFactor(table->retrieve(name));
									}
                           else{
                              validConst = false;
                              cout<<" Error: invalid assignment of type: ";
                              cout<< name<<endl;
                              }
                       }
							}
                  |  ConstFactor{
							if(validConst){
								if(constType == 0)
							   {
							      int n = yylval.int_value;
								   constant-> setConstFactor(n);
                           typeString = "int";
								}
								else if(constType == 3)
								{
									constant ->setConstFactor(nullPtr);

								}	
								else if(constType == 1){
								   constant-> setConstFactor(1);
									constant->setIsBool();
                           typeString = "bool";
								}
								
								else if(constType == 2){
									constant->setConstFactor(0);
									constant->setIsBool();
                           typeString = "bool";
								}
								
                        else if (constType == 4){
									if(table->lookup(name)){
                             IdentifierRecord* temp = table->retrieve(name);
                             if(temp->recordType = 1){
                                ConstantRecord &c = dynamic_cast<ConstantRecord &>(*temp);
                            	  constant->setConstFactor(table->retrieve(name));
                                if(c.isString)
                                    typeString = "string";
                                else if(c.isBool)
                                    typeString = "bool";
                                else if(c.isNil)
                                    typeString = "";
                                else
                                    typeString = "int";
                             }
                           }
                        }
                        else{
                           validConst = false;
                           cout<<" Error: invalid assignment of type: "; cout<< name<<endl;
                        }
							}
						}
                  |  
								ystring 
                     {
                        if(validConst) {
                            typeString = "string";
                            constant->setConstFactor(yylval.str);
                        }
                        else{
                           validConst = false;
                           cout<<" Error: invalid assignment of type: ";
                           cout<< yylval.str<<endl;
                        }
                        delete yylval.str;
                     }
                  ;
ConstFactor       :  Identifier {constType = 4;}
                  |  ynumber {constType = 0;}
                  |  ytrue   { constType = 1;}
                  |  yfalse  { constType = 2;}
                  |  ynil    { constType = 3;}
                  ;
Type              :  Identifier 
                     {
							  if(sitTable.lookup(name)){
                           if(name == "integer"){
                              subType = anInt;
                           }
                           if(name == "real")
                              subType = aReal;
                           if(name == "boolean")
                              subType = aBool;
                           if(name == "char")
                              subType = aChar;
                          subTypes.push(subType);
                          subType = NULL;
                          validType = true;
                          
							  }
							  else if(table->lookup(name) == true){
								  IdentifierRecord* temp = table->retrieve(name);
							     subTypes.push(temp);
								}

							  else
							  {
                           IdentifierRecord* temp = NULL;
                           int size = pointerHolder.size();
                           isFound = false;
                           if(pointerHolder.size() != 0 && isRecord){
                              for (int i = 0; i < size; i++){
                                 if(name == pointerHolder.front()->getName()){
                                    subTypes.push(pointerHolder.front());
                                    isFound = true;
                                 }

                                 temp = pointerHolder.front();
                                 pointerHolder.front() = NULL;
                                 pointerHolder.pop();
                                 pointerHolder.push(temp); //move it to the back
                              }
                           }
                           if(!isFound){
                              cout<< "Error: " << name;
                              cout<< " is not a valid type in this scope."<<endl;
                              validType = false;
                           }
                        }
                     }
                  |  ArrayType 
                  |  PointerType
                  |  RecordType 
                  |  SetType
                  ;
ArrayType         :  yarray 
                     { if(validType){
								array = new ArrayType("_array");
								isArray = true;
								subTypes.push(array);}
							 }		  
                     yleftbracket SubrangeList yrightbracket  yof 
                     Type
                     {
                       if(validType){

                          array->setType(subTypes.top());
									subTypes.top() = NULL;
									subTypes.pop();
                       }
								else{
									cout<<"Error: Type not valid"<<endl;
									subTypes.pop();
								}
                     }
                  ;
SubrangeList      :  Subrange
                  |  SubrangeList ycomma Subrange
                  ;

Subrange          :  ConstFactor
                     {
					    if(validType){
                        if(isArray){
                           if(constType == 0)
                                 array->setLowDimension(yylval.int_value);

                            else if(constType == 4 && table->lookup(name)){
                              IdentifierRecord* temp = table->retrieve(name);
                              if(temp->recordType == 1){
                                 ConstantRecord &c = dynamic_cast<ConstantRecord &>(*temp);
                                 if(c.isString && c.str_const_factor.size() == 1)
                                    array->setLowDimension(c.str_const_factor);
                                 else{
                                    cout<<" Error: Invalid type for subrange."<<endl;
                                    validType = false;
                                 }
                              }
                              else{
                                 cout<<" Error: Invalid type for subrange."<<endl;
                                 validType = false;
                              }
                           }
                           else{
                              cout<<" Error: Invalid type for subrange."<<endl;
                              validType = false;
                           }
                        }
                      else{
								if(constType == 0)
                              set->setLowDimension(yylval.int_value);

								 else if(constType == 4 && table->lookup(name)){
                           IdentifierRecord* temp = table->retrieve(name);
                           if(temp->recordType == 1){
                              ConstantRecord &c = dynamic_cast<ConstantRecord &>(*temp);
                              if(c.isString && c.str_const_factor.size() == 1)
                                 set->setLowDimension(c.str_const_factor);
                              else{
                                 cout<<" Error: Invalid type for subrange."<<endl;
                                 validType = false;
                              }
                           }
                           else{
                              cout<<" Error: Invalid type for subrange."<<endl;
                              validType = false;
                           }
                        }

                        else{
                           cout<<" Error: Invalid type for subrange."<<endl;
                           validType = false;
                        }
                     }
                     }
                     }

                     ydotdot ConstFactor{
							if(validType){
                      if(isArray){
								 if(constType == 0 && array->isInt == true
                           && array->currentDimension->low < yylval.int_value){
                              array->setHighDimension(yylval.int_value);
									}

                        else if (constType == 4 && table->lookup(name)){
                            IdentifierRecord* temp = table->retrieve(name);
                            if(temp->recordType == 1){ //only if const record
                              ConstantRecord &c = dynamic_cast<ConstantRecord &>(*temp);
                               if(c.isString && c.str_const_factor.size() == 1
                                 && array->currentDimension!= NULL
                                 && array->isChar){
                                    array->setHighDimension(c.str_const_factor);
                               }

                               else if (!c.isString && !c.isBool && !c.isNil
                                 && array->currentDimension!= NULL
                                 && c.int_const_factor > array->currentDimension->low
                                 && array->isInt){
                                    array->setHighDimension(c.int_const_factor);
                               }
                               else{
                                 cout<<" Error: Invalid type for subrange."<<endl;
                                 validType = false;
                               }
                            }
								}

								else{
                           cout<<" Error: Invalid type for subrange."<<endl;
                           validType = false;
								}
							 }
                      else{
								 if(constType == 0 && array->isInt == true
                           && set->dimension->low < yylval.int_value){
                              array->setHighDimension(yylval.int_value);
									}

                        else if (constType == 4 && table->lookup(name)){
                            IdentifierRecord* temp = table->retrieve(name);
                            if(temp->recordType == 1){ //only if const record
                                ConstantRecord &c = dynamic_cast<ConstantRecord &>(*temp);
                               if(c.isString && c.str_const_factor.size() == 1
                                 && set->isChar
                                 && set->dimension->str_low.compare(c.str_const_factor) < 0)
                                    set->setHighDimension(c.str_const_factor);
                               else{
                                 cout<<" Error: Invalid type for subrange."<<endl;
                                 validType = false;
                               }
                            }
								}

								else{
                           cout<<" Error: Invalid type for subrange."<<endl;
                           validType = false;
								}
							}							 
                    }
                  }

                  |  ystring
                     {     
								if(validType){
									string s(yylval.str);

									 if(isArray && s.size() == 1){
											array->setLowDimension(s);
									 }
									 else if(!isArray && s.size() == 1){
											set-> setLowDimension(s);
									 }
                            else{
                               cout<<" Error: Invalid type for subrange."<<endl;
                               validType = false;
                            }
                         }
                         else{
                            cout<<" Error: Invalid type for subrange."<<endl;
                            validType = false;
                         }
                         delete yylval.str;
									
                      }  ydotdot  
                      ystring
                      {
								if(validType){
									string s(yylval.str);

									 if(isArray && s.size() == 1 && array->isChar){
											array->setLowDimension(s);
									 }
									 else if(!isArray && s.size() == 1 && set->isChar){
											set-> setLowDimension(s);
									 }
                            else{
                               cout<<" Error: Invalid type for subrange."<<endl;
                               validType = false;
                            }
                         }
                         else{
                            cout<<" Error: Invalid type for subrange."<<endl;
                            validType = false;
                         }
                         delete yylval.str;
                      }
                  ;
RecordType        :  yrecord {
                        if(validType){
                           cout<<"record type is valid"<<endl;
                           isRecord = true;
                           rec = new RecordType("_record");
                           subTypes.push(rec);
                        }
                     }

                     FieldListSequence {validType = true;} yend
                  ;
SetType           :  yset 
                  {
						set = new SetType("_set");
					    subTypes.push(set); 
						isArray = false;
				  } 
                     yof Subrange
                  ;
PointerType       :  ycaret  Identifier 
                     {
                      isPointer = true;
                      IdentifierRecord* pType;
							 pointer = new PointerType("_ptr", name);
                      if(table->lookup(name)){
                           pType = table->retrieve(name);
                           pointer->setType(pType);
                           //pointer->setValid();
                           subTypes.push(pointer);
                       }
                      else if(sitTable.lookup(name)){
                           if(name == "integer")
                              pType = anInt;
                           if(name == "real")
                              pType = aReal;
                           if(name == "boolean")
                              pType = aBool;
                           if(name == "char")
                              pType = aChar;

                           pointer->setType(pType);
                           //pointer->setValid();
                           subTypes.push(pointer);
                      }

                      else{
                           aType->setType(pointer);
                           pointerHolder.push(aType);
                           aType = NULL;
                           validType = false;
                           //aType->print(0);

                          } 
                     }
                  ;
FieldListSequence :  FieldList
                  |  FieldListSequence  ysemicolon  FieldList
                  ;
FieldList         :  IdentList 
                     ycolon  Type 
				  {	
                       if(table->lookup(subTypes.top()->getName())
                           || sitTable.lookup(subTypes.top()->getName()) || isFound){
                           while(!vars.empty()){
										bool isDup = false;
                              if(!table->lookupScope(vars.front()->getName())){
											for(int i = 0; i < rec->getFieldSize(); i++){
											  if(vars.front()->getName() == rec->getFieldName(i)){
													cout<< "Error: " <<vars.front()->getName();
                                       cout<< " already exists" << endl;
													vars.pop();

													isDup = true;
													break;
											  }
												  
											}
											if(!isDup){
												vars.front()->setType(subTypes.top());
												rec->addField( vars.front()->getType(),
                                       vars.front()->getName());
												vars.front()=NULL;
												vars.pop();
											}

                              }
										
										else{
											cout<< "Error: " <<vars.front()->getName();
                                 cout<< "already exists" << endl;
										   vars.pop();

										}
                           }
											subTypes.top() = NULL;
                                 subTypes.pop();
                       }
				  }   
                  ;

/***************************  Statements  ************************************/

StatementSequence :  Statement
                  |  StatementSequence  ysemicolon  Statement
                  ;
Statement         :  Assignment
                  |  ProcedureCall
                  |  IfStatement
                  |  CaseStatement
                  |  WhileStatement
                  |  RepeatStatement
                  |  ForStatement
                  |  IOStatement
                  |  MemoryStatement
                  |  ybegin StatementSequence yend
                  |  /*** empty ***/
                  ;
Assignment        :
                     Designator yassign {cout<<" = ";}
                     Expression
                  ;
ProcedureCall     :
                     Identifier
                  {
                        cout<<name<<endl;
                        if (!table->lookup(name))
						    cout << name << " is not defined in this scope." << endl;
                  }
                  |
                     Identifier
				  {
                     cout<<name<<" ";
                      //  if (!table->lookup(name)) //something's wrong with finding procedures in table
						    //cout << name << " is not defined in this scope." << endl;
                  }
				     ActualParameters {cout<<";"<<endl;}
                  ;
IfStatement       :  yif 
                  {
                        if (inElse)
                            inElse = false;

                        cout << "  if ( ";
                  }
                     Expression  
                  { 
                        cout << " ) {" << endl;
                  }

                     ythen  Statement
                  {
                        cout << "}" << endl;
                  }
                     ElsePart 
                  {
                        if (countIfs == 0) {
                           cout << "}" << endl;
                        }
                  }
                  ;
ElsePart          :  /*** empty ***/
                  |  yelse
                  {
                        cout<< "else ";
                        countIfs++;
                        inElse = true;
                  }
                    Statement
                  {
                        //if(inElse)
                        //   cout<<"}"<<endl;
                        countIfs--;
                  }
                  ;
CaseStatement     :  ycase  Expression  yof  CaseList  yend
                  ;
CaseList          :  Case
                  |  CaseList  ysemicolon  Case
                  ;
Case              :  CaseLabelList  ycolon  Statement
                  ;
CaseLabelList     :  ConstExpression
                  |  CaseLabelList  ycomma  ConstExpression
                  ;
WhileStatement    :  ywhile 
                  {  
                        cout << "while (";
                  }
                     Expression  
                  {  
                        cout << ") {" << endl; 
                  }
                    ydo  Statement 
                  {
                        cout << "}" << endl;
                  }
                  ;
RepeatStatement   :  yrepeat StatementSequence yuntil Expression
                  ;
ForStatement      :  yfor {cout<< "for (";}
                     Identifier {cout<<name<<" ";}
                     yassign {cout<<"= ";}
                     Expression {cout<<"; ";}
                     WhichWay  { if(forUp){ cout<<" "<<name<<" <= ";}}
                     Expression
                  {  cout<< "; "<<name;
                     if(forUp)
                        cout<<"++ ){"<<endl;
                  }
                     ydo
                     Statement
                  { cout<<endl<<"}"<<endl;}
                  ;
WhichWay          : yto {forUp = true;}
                  | ydownto {forUp = false;}
                  ;
IOStatement       : yread 
                  { 
                        cout << "cin>>"; 
                  } 
                    yleftparen DesignatorList yrightparen 
                  {
                        cout << ";" << endl;
                  }
                  | yreadln 
                  { 
                        cout << "cin>> ;"; 
                  }
                  | yreadln
                  { 
                        cout << "cin>>";
                  } 
                    yleftparen DesignatorList yrightparen
                  {
                        cout << "; << endl;" << endl;
                  }
                  | ywrite 
                  {  
                       if (inElse) cout << "{" << endl;
                       cout << "   ";
                       cout << "cout <<";
                  }
                    yleftparen ExpList yrightparen
                  {
                        cout << ";";
                  } 
                  | ywriteln 
                  {
                        cout << "cout << endl;";
                  }
                  | ywriteln 
                  {
                        cout << "cout <<";
                  }
                    yleftparen ExpList yrightparen
                  { 
                        cout << "<< endl;" << endl;
                  }
                  ;

/***************************  Designator Stuff  ******************************/

DesignatorList    : Designator
                  | DesignatorList ycomma Designator
                  ;
Designator        : Identifier
                  {    
                        if(table->lookup(name))
                            cout << name;
                        
                        else
                            cout << "Error: identifier " << name << " is invalid." << endl;
                  } 
                    DesignatorStuff
                  ;
DesignatorStuff   : /*** empty ***/
                  | DesignatorStuff theDesignatorStuff
                  ;
theDesignatorStuff: ydot {cout<< ".";}
                    Identifier
                  {
                        if(table->lookup(name))
                            cout << name;

                        else
                            cout << "Error: identifier " << name << " is invalid." << endl;
                  }
                  | yleftbracket {cout<< "[";}
                    ExpList
                    yrightbracket {cout<< "]";}
                  | ycaret {cout<< "*";}
                  ;
ActualParameters  : yleftparen {cout<<"( ";}
                    ExpList
                    yrightparen {cout<<" )";}
                  ;
ExpList           : Expression
                  | ExpList ycomma {cout<<", ";}
                    Expression
                  ;
MemoryStatement   : ynew yleftparen Identifier yrightparen
                  | ydispose yleftparen Identifier yrightparen
                  ;

/***************************  Expression Stuff  ******************************/

Expression        : SimpleExpression
                  | SimpleExpression Relation SimpleExpression
                  ;
SimpleExpression  : TermExpr
                  | UnaryOperator TermExpr
                  ;
TermExpr          : Term
                  | TermExpr AddOperator Term
                  ;
Term              : Factor
                  | Term MultOperator Factor
                  ;
Factor            : ynumber 
                  {     
                        cout << yylval.int_value;
                  }
                  | ytrue {cout<<"true";}
                  | yfalse {cout<<"false";}
                  | ynil {cout<<"NULL";}
                  | ystring 
                  {
                        cout << '"' << yylval.str << '"';
                  }
                  | Designator
                  | yleftparen  {cout<<" ( ";}
                    Expression
                    yrightparen {cout<<" ) ";}
                  | ynot {cout<<" !";}
                    Factor
                  | Setvalue
                  | FunctionCall 
                  ;
/*  Functions with no parameters have no parens, but you don't need         */
/*  to handle that in FunctionCall because it is handled by Designator.     */
/*  A FunctionCall has at least one parameter in parens, more are           */
/*  separated with commas.                                                  */
FunctionCall      : Identifier 
                  {
                    if(!table->lookup(name)) {
                       cout<<"Error: Function does not exist";
                    }

                    else {
                        cout<<name<<" ";
                    }

                  }
                    ActualParameters
                  ;
Setvalue          : yleftbracket ElementList  yrightbracket
                  | yleftbracket yrightbracket
                  ;
ElementList       : Element
                  | ElementList  ycomma  Element
                  ;
Element           : ConstExpression
                  | ConstExpression  
                    ydotdot {cout<<"..";}  //need type checking here
                    ConstExpression
                  ;

/***************************  Subprogram Stuff  ******************************/

SubprogDeclList   : /*** empty ***/
                  | SubprogDeclList ProcedureDecl ysemicolon
                  | SubprogDeclList FunctionDecl ysemicolon
                  ;
ProcedureDecl     : ProcedureHeading  ysemicolon  Block 
                  {
                        table->exitScope();
                  }
                  ;
FunctionDecl      : FunctionHeading  ycolon  Identifier
			      {
                        if(sitTable.lookup(name)) {
                             if(name == "integer")
                                  aProcedure->setReturnType(anInt);
                             else if(name == "real")
                                  aProcedure->setReturnType(aReal);
                             else if(name == "boolean")
                                  aProcedure->setReturnType(aBool);
                             else if(name == "char")
                                  aProcedure->setReturnType(aChar);
                        }

					    else if(table->lookup(name)){
                            aType = table->retrieve(name);
                            if(aType != NULL)
                               aProcedure->setReturnType(aType);
                        }

					    else {
                            cout<<"Error: Return type invalid"<<endl;
                        }
                  }
                    ysemicolon  Block 
                  {
                        table->exitScope();
                  }
                  ;
ProcedureHeading  : yprocedure Identifier
                  {
                        aProcedure = new ProcedureRecord(name);
                        table ->enterScope(aProcedure);
                  }
                  | yprocedure Identifier
                  {
                        aProcedure = new ProcedureRecord(name);
                        table ->enterScope(aProcedure);
                  }
                    FormalParameters
                  ;
FunctionHeading   : yfunction Identifier 
				  {
                        aProcedure = new ProcedureRecord(name);
                        table ->enterScope(aProcedure);
                  }
                  | yfunction Identifier 
                  {
                        aProcedure = new ProcedureRecord(name);
                        table ->enterScope(aProcedure);
                  }     
                    FormalParameters
                  ;
FormalParameters  :  yleftparen FormalParamList yrightparen
                  ;
FormalParamList   :  OneFormalParam
                  |  FormalParamList ysemicolon OneFormalParam
                  ;
OneFormalParam    :  yvar  IdentList  ycolon Identifier 
                     {
                       if(table->lookup(name)){
                          subTypes.push(table->retrieve(name));
                          while(!vars.empty()){
                             if(!table->lookupScope(vars.front()->getName()) &&
                                !sitTable.lookup(vars.front()->getName())){
                                 vars.front()->setIsVar();
                                 vars.front() ->setType(subTypes.top());
                                 aProcedure->insertParam(vars.front());
                                 vars.front() = NULL;
											vars.pop();
                             }
									  else{
									      cout<< "Error: value " <<vars.front()->getName();
											cout<<" already exists in the current scope."<<endl;
										   vars.pop();
									   }
                           }
									
									subTypes.top() = NULL;
                           subTypes.pop();
                        }
				
						   }
                  |  IdentList ycolon Identifier 
                     {
                       if(table->lookup(name)){
                          subTypes.push(table->retrieve(name));
                          while(!vars.empty()){

                             if(!table->lookupScope(vars.front()->getName()) &&
                                !sitTable.lookup(vars.front()->getName())){
                                 vars.front()->setIsVar();
                                 aProcedure->insertParam(vars.front());
                                 vars.front() = NULL;
											vars.pop();
                             }
									  else{
									      cout<< "Error: value " <<vars.front()->getName();
											cout<<" already exists in the current scope."<<endl;
										   vars.pop();
									   }
                           }
									
									subTypes.top() = NULL;
                           subTypes.pop();
                        }
                     }
                  ;

/***************************  More Operators  ********************************/

UnaryOperator     : yplus           { uOperator = "+"; }
                  | yminus          { uOperator = "-"; }
                  ;
MultOperator      : ymultiply       { cout<<" * "; }
                  | ydivide         { cout<<" / "; }
                  | ydiv
                  | ymod
                  | yand            { cout<<" && "; }
                  ;
AddOperator       : yplus           {cout<<" + ";}
                  | yminus          {cout<<" - ";}
                  | yor             { cout<< " || "; }
                  ;
Relation          : yequal          { cout<<" == "; }
                  | ynotequal       { cout<<" != "; }
                  | yless           { cout<< " < "; }
                  | ygreater        { cout<<" >"; }
                  | ylessequal      { cout<< " <= "; }
                  | ygreaterequal   { cout<< " >= "; }
                  | yin
                  ;
%%

   /************************ Program Section *********************************/

void yyerror(char *s) {
   cout << s << endl;
}

extern int yylex();

