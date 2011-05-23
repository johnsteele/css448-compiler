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

#include "yaccExecute.cpp"
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


SymbolTable * table = NULL;    //points to symbolTable

ProcedureRecord * program = NULL; //used to always hold program record
ProcedureRecord * aProcedure = NULL; //holds procedure in current scope

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
ProgramModule      : yprogram {table = new SymbolTable();}
                     Identifier
                     {
                            program = new ProcedureRecord(name);
                            table-> enterScope(program);
                            cout<< "int main(){"<<endl;
                     }
                     ProgramParameters ysemicolon Block  ydot
                        {cout<<"return 0;"<<endl;
                         cout<<"}"<<endl;

                      //table->printTable();
                       //delete table;
                       //delete anInt;
                      // delete aChar;
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

                        else{
                          cout<< "Error: (" <<name<<") already exists in this scope."<<endl;
                        }
							}
                   |  IdentList ycomma 
						    Identifier
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
								}
							}
                     ysemicolon
                  |  ConstantDefList ConstantDef 
                     {
								if(validConst){
									table->addSymbol(constant);
								}
							}
                     ysemicolon
                  ;
TypeDefBlock      :  /*** empty ***/
                  |  ytype  TypeDefList
                     {  table->printTable();

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
                         }
								else{
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
								   cout<< "Error: Type " << name<<" already exists in this scope." <<endl;
									validType = false;
								}
							}
                     yequal 
                     Type 
                     { if(!validType)
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
								  if(isNum && uOperator != "-")
									{
										int n = yylval.int_value;
										constant-> setConstFactor(n);
										isNum = false;
										uOperator = "";
									}
									else if(isNum)
									{
										int n = yylval.int_value * -1;
										constant-> setConstFactor(n);
										isNum = false;
										uOperator = "";
									}
									
									else if(isNil)
									{
										constant ->setConstFactor(nullPtr);
										isNil  = false;
										uOperator = "";
									}	
									else if(isTrue){
										int n;
										if(uOperator == "-")
											n = -1;
										else
											n = 1;
										constant-> setConstFactor(n);
										constant->setIsBool();
										isTrue = false;
										uOperator = "";
									}
									
									else if(isFalse){
										constant->setConstFactor(0);
										constant->setIsBool();
										isFalse = false;
										uOperator = "";
									}
									
									else{
										if(table->lookup(name))
                            	  constant->setConstFactor(table->retrieve(name));
											
										else{
											validConst = false;
											cout<<" Error: invalid assignment of type: ";
                                 cout<< name<<endl;
											}
									}
								}
							}
                  |  ConstFactor{
							if(validConst){
								if(isNum)
							   {
							      int n = yylval.int_value;
								   constant-> setConstFactor(n);
									isNum = false;
								}
								else if(isNil)
								{;
									constant ->setConstFactor(nullPtr);
									isNil  = false;
								}	
								else if(isTrue){
								   constant-> setConstFactor(1);
									constant->setIsBool();
									isTrue = false;
								}
								
								else if(isFalse){
									constant->setConstFactor(0);
									constant->setIsBool();
									isFalse = false;
								}
								
								else{
									if(table->lookup(name))
										constant->setConstFactor(table->retrieve(name));
										
									else{
										validConst = false;
										cout<<" Error: invalid assignment of type: "; cout<< name<<endl;
										}
								}
							}
						}
                  |  
								ystring 
                     {
                        if(validConst) {
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
ConstFactor       :  Identifier 
                  |  ynumber {isNum = true;}
                  |  ytrue   { isTrue = true;}
                  |  yfalse  { isFalse = true;}
                  |  ynil    { isNil = true;}
                  ;
Type              :  Identifier 
                     {
							  if(sitTable.lookup(name)){
                           if(name == "integer")
                              subType = anInt;
                           if(name == "real")
                              subType = aReal;
                           if(name == "boolean")
                              subType = aBool;
                           if(name == "char")
                              subType = aChar;
                          subTypes.push(subType);
                          subType = NULL;
                          
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
								 if(isTrue){
									array->setLowBool(1);
									isTrue = false;
								 }
							    else if(isFalse){
									array->setLowBool(0);
									isFalse = false;
								 }
								 else if(isNum){
                           array->setLowDimension(yylval.int_value);
									isNum = false;
								 }
								 
								 else if(isNil){
									array->setLowDimension(nullPtr);
								   isNil = false;
							    }
								 
								else{
									if(table->lookup(name))
										array->setLowDimension(table->retrieve(name));
										
									else{
										validType = false;
										cout<<" Error: invalid assignment of type: ";
                              cout<< name<<endl;
										}
								}
							  }
                      else{
								if(isTrue){
									set->setLowBool(1);
									isTrue = false;
									}
									
							    else if(isFalse){
									set->setLowBool(0);
									isFalse = false;
									}
								 else if(isNum){
                           set->setLowDimension(yylval.int_value);
									isNum = false;
									}
									
								else if(isNil){
									set->setLowDimension(nullPtr);
									isNil = false;
							   }
								 
								else{
									if(table->lookup(name))
										set->setLowDimension(table->retrieve(name));
										
									else{
										validType = false;
										cout<<" Error: invalid assignment of type: ";
                              cout<< name<<endl;
										}
								}
							 }
							}
							
							 else{
							    cout<< "Error: Invalid type"<<endl;
							   }
                     }

                     ydotdot ConstFactor{
							if(validType){
                      if(isArray){
							 
								 if(isTrue){
									array->setHighBool(1);
									isTrue = false;
									}
									
							    else if(isFalse){
									array->setHighBool(0);
									isFalse = false;
								 }
								 else if(isNum){
                           array->setHighDimension(yylval.int_value);
									isNum = false;
								 }
								 
								 else if(isNil){
									array->setHighDimension(nullPtr);
									isNil = false;
							   }
								 
								else{
									if(table->lookup(name))
										array->setHighDimension(table->retrieve(name));
										
									else{
										validType = false;
										cout<<" Error: invalid assignment of type: "; cout<< name<<endl;
										}
								}
							 }
                      else{
								if(isTrue){
									set->setHighBool(1);
									isTrue = false;
									}
									
							    else if(isFalse){
									set->setHighBool(0);
									isFalse = false;
									}
								 else if(isNum){
                           set->setHighDimension(yylval.int_value);
									isNum = false;
								 }
								 
								 else if(isNil){
									set->setHighDimension(nullPtr);
									isNil = false;
							   }
								 
								else{
									if(table->lookup(name))
										set->setHighDimension(table->retrieve(name));
										
									else{
										validType = false;
										cout<<" Error: invalid assignment of type: "; cout<< name<<endl;
										}
								}
								}
							}	
							else
									cout<<"Error: Invalid type"<<endl;
							 
                    }

                  |  ystring
                     {     
								if(validType){
									string s(yylval.str);
									 if(isArray){
											array->setLowDimension(s);
									 }
									 else{
											set-> setLowDimension(s);
									 }
								}
								 else
									cout<<"Error: Invalid type"<<endl;

                         delete yylval.str;
									
                      }  ydotdot  
                      ystring
                      {
								if(validType){
                           string s(yylval.str);
                          if(isArray){
										array->setHighDimension(s);
									}
									else{
										set-> setHighDimension(s);
									}
								}
								else
									cout<<"Error: Invalid type"<<endl;

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

                     FieldListSequence {validType = true;subTypes.top()->print(0); cout<<endl;} yend
                  ;
SetType           :  yset {
							set = new SetType("_set");
							subTypes.push(set); 
							isArray = false;
							 } yof Subrange
                  ;
PointerType       :  ycaret  Identifier 
                     {
                      isPointer = true;
                      IdentifierRecord* pType;
							 pointer = new PointerType("_ptr", name);
                      if(table->lookup(name)){
                           pType = table->retrieve(name);
                           pointer->setType(pType);
                           pointer->setValid();
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
                           pointer->setValid();
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
Assignment        :  Designator yassign Expression
                  ;
ProcedureCall     :  Identifier 
                     {if(!table->lookup(name))
							    cout<< name <<" is not defined in this scope."<<endl;
                     }
                  |  Identifier 
						   {if(!table->lookup(name))
							    cout<< name <<" is not defined in this scope."<<endl;
                     }
						   ActualParameters
                  ;
IfStatement       :  yif  Expression  ythen  Statement  ElsePart
                  ;
ElsePart          :  /*** empty ***/
                  |  yelse  Statement
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
WhileStatement    :  ywhile  Expression  ydo  Statement
                  ;
RepeatStatement   :  yrepeat StatementSequence yuntil Expression
                  ;
ForStatement      :  yfor Identifier yassign Expression WhichWay Expression
                           ydo Statement
                  ;
WhichWay          : yto | ydownto
                  ;
IOStatement       : yread yleftparen DesignatorList yrightparen
                  | yreadln
                  | yreadln yleftparen DesignatorList yrightparen
                  | ywrite {cout<<"cout<<";}yleftparen ExpList yrightparen{cout<<";";}

                  | ywriteln {cout<<"cout<<endl;";}
                  | ywriteln {cout<<"cout<<";}yleftparen ExpList yrightparen{cout<<"<<endl;"<<endl;}
                  ;

/***************************  Designator Stuff  ******************************/

DesignatorList    : Designator
                  | DesignatorList ycomma Designator
                  ;
Designator        : Identifier DesignatorStuff
                  ;
DesignatorStuff   : /*** empty ***/
                  | DesignatorStuff theDesignatorStuff
                  ;
theDesignatorStuff: ydot Identifier
                  | yleftbracket ExpList yrightbracket
                  | ycaret
                  ;
ActualParameters  : yleftparen ExpList yrightparen
                  ;
ExpList           : Expression
                  | ExpList ycomma Expression
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
                  | ytrue
                  | yfalse
                  | ynil
                  | ystring {cout<<'"'<<yylval.str <<'"';}
                  | Designator
                  | yleftparen Expression yrightparen
                  | ynot Factor
                  | Setvalue
                  | FunctionCall {//if (!table->lookup(name))
}						
                  ;
/*  Functions with no parameters have no parens, but you don't need         */
/*  to handle that in FunctionCall because it is handled by Designator.     */
/*  A FunctionCall has at least one parameter in parens, more are           */
/*  separated with commas.                                                  */
FunctionCall      : Identifier 
					{
                     	if(!table->lookup(aProcedure->getName())){}
                        /*throw an error*/
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
                  | ConstExpression  ydotdot  ConstExpression
                  ;

/***************************  Subprogram Stuff  ******************************/

SubprogDeclList   : /*** empty ***/
                  | SubprogDeclList ProcedureDecl ysemicolon
                  | SubprogDeclList FunctionDecl ysemicolon
                  ;
ProcedureDecl     : ProcedureHeading  ysemicolon  Block 
                    {table->exitScope();}
                  ;
FunctionDecl      : FunctionHeading  ycolon  
						  Identifier
						  {
                     if(sitTable.lookup(name)){
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

							else{
                        cout<<"Error: Return type invalid"<<endl;
                     }
                    }
                    ysemicolon  Block 

                    {table->exitScope();}
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

UnaryOperator     :  yplus {uOperator = "+";}
                  |  yminus {uOperator = "-";}
                  ;
MultOperator      :  ymultiply | ydivide | ydiv | ymod | yand
                  ;
AddOperator       :  yplus | yminus | yor
                  ;
Relation          :  yequal  | ynotequal | yless | ygreater
                  |  ylessequal | ygreaterequal | yin
                  ;
%%

   /************************ Program Section *********************************/

void yyerror(char *s) {
   cout << s << endl;
}

extern int yylex();
