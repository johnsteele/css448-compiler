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
using namespace std;

#include "SymbolTable.h"
#include "IdentifierRecord.h"
#include "VariableRecord.h"
#include "ProcedureRecord.h"
#include "ConstantRecord.h"
#include "Parameter.h"
#include "ArrayType.h"
#include "PointerType.h"
#include "SITtype.h"
#include "SITtable.h"

SymbolTable * table = NULL;
IdentifierRecord * program = NULL; //used to always hold program record
IdentifierRecord * aProcedure = NULL; //holds procedure in current scope
//IdentifierRecord * parent = NULL;
IdentifierRecord * constant = NULL; //holds const variable while being entered
IdentifierRecord * aType = NULL;    //holds type vaiable while being entered
IdentifierRecord * subType = NULL;  //holds type of type variable while being entered
//VariableRecord * v = NULL;
Parameter * param = NULL;  //holds parameter while being entered
string uOperator = "";   //keeps track of unary operator
ArrayType * array = NULL; //holds array while being setup and entered
//int scope;

	//SITtable *sitTable = new SITtable ();
	//bool found = sitTable->lookup("true");
	//if (found) cout << "Found: " << found << endl;
	//else   cout << "Not Found: " << found << endl;
	//delete sitTable;
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
   char *str;
   int i;
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
                            scope = 0;
                            program = new ProcedureRecord(yylval.str);
                            table-> enterScope(program);
                     }
                     ProgramParameters ysemicolon Block  ydot
                     { table->printTable(); }
                   ;
ProgramParameters  : yleftparen  ParamList yrightparen //added paramlist to differentiate
                   ;
ParamList          : ParamList ycomma Identifier
                     { 
                            ProcedureRecord &r = dynamic_cast<ProcedureRecord &> (*program);
                            r.insertParam(param);
                            param = new Parameter(yylval.str);
                            r.insertParam(param);
                     }
                   | Identifier
                     { 
                            ProcedureRecord &r = dynamic_cast<ProcedureRecord &> (*program);
                            r.insertParam(param);
                            param = new Parameter(yylval.str);
                            r.insertParam(param);
                     }
                   ;
IdentList          :  Identifier
                   |  IdentList ycomma Identifier
                   ;
Identifier         :  yident { /*cout << yylval.str;*/ }
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
ConstantDefList   :  ConstantDef ysemicolon
                  |  ConstantDefList ConstantDef ysemicolon
                  ;
TypeDefBlock      :  /*** empty ***/
                  |  ytype  TypeDefList
                  ;
TypeDefList       :  TypeDef  ysemicolon
                  |  TypeDefList TypeDef ysemicolon
                  ;
VariableDeclBlock :  /*** empty ***/
                  |  yvar VariableDeclList
                  ;
VariableDeclList  :  VariableDecl ysemicolon
                  |  VariableDeclList VariableDecl ysemicolon
                  ;
ConstantDef       :  Identifier {constant = new ConstantRecord(yylval.str);}
                     yequal  ConstExpression
                     {table->addSymbol(constant);}
                  ;
TypeDef           :  Identifier { aType = new IdentifierRecord(yylval.str);}
                     yequal  Type 
                  ;
VariableDecl      :  IdentList { /*v = new VariableRecord(yylval.str);*/}
                     ycolon  Type {/*v ->setType(yylval.str);*/}
                  ;

/***************************  Const/Type Stuff  ******************************/

ConstExpression   :  UnaryOperator 
                     ConstFactor
                  |  ConstFactor

                  |  ystring /*not handling any const but numbers right now*/
                  ;
ConstFactor       :  Identifier /*const setConstFactor only takes ints.... hmmm*/
                  |  ynumber 
                    {
                      int n = atoi(yylval.str);
                      if(!uOperator.empty()){
                         if(uOperator == "-")
                            n *= -1;
                      } //unaray op will count now if negative
                      ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(n);
                      uOperator = "";
                    }
                  |  ytrue   
                     {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      int n = 1;
                      if(uOperator == "-")
                         n *= -1;
                      r.setConstFactor(n);
                      r.setIsBool();
                      uOperator = "";
                     }
                  |  yfalse
                     {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(0);
                      r.setIsBool();
                      uOperator = "";
                     }
                  |  ynil
                     {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(atoi(yylval.str));
                      uOperator = "";
                      //I don't really know how to handle ynil. Is it ""?
                     }
                  ;
Type              :  Identifier 
                     {/* need to do SITtable lookup for type and pass in matching
                       identRecord found from SitTable. If not found, return error.*/
                     }
                  |  ArrayType
                  |  PointerType
                  |  RecordType
                  |  SetType
                  ;
ArrayType         :  yarray 
                     {array = new ArrayType(aType->getName());
                     }
                     yleftbracket SubrangeList yrightbracket  yof
                     Type
                     {array ->setType(yylval.str)
                  ;
SubrangeList      :  Subrange
                  |  SubrangeList ycomma Subrange
                  ;
Subrange          :  ConstFactor{array->setLowDimension(atoi(yylval.str);}
                     ydotdot
                     ConstFactor{array->setHighDimension(atoi(yylval.str);}
                  |  ystring ydotdot  ystring /*we may need an overloaded operator
                                                that can handle strings for diminsions*/
                  ;
RecordType        :  yrecord  FieldListSequence  yend
                  ;
SetType           :  yset  yof  Subrange
                  ;
PointerType       :  ycaret  Identifier
                  ;
FieldListSequence :  FieldList
                  |  FieldListSequence  ysemicolon  FieldList
                  ;
FieldList         :  IdentList  ycolon  Type
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
                  |  Identifier ActualParameters
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
                  | ywrite yleftparen ExpList yrightparen
                  | ywriteln
                  | ywriteln yleftparen ExpList yrightparen
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
                  | ystring
                  | Designator
                  | yleftparen Expression yrightparen
                  | ynot Factor
                  | Setvalue
                  | FunctionCall
                  ;
/*  Functions with no parameters have no parens, but you don't need         */
/*  to handle that in FunctionCall because it is handled by Designator.     */
/*  A FunctionCall has at least one parameter in parens, more are           */
/*  separated with commas.                                                  */
FunctionCall      : Identifier 
					{
                     	if(!table->lookup(aProcedure)){}
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
FunctionDecl      : FunctionHeading  ycolon  Identifier  ysemicolon  Block 
                    {table->exitScope();}
                  ;
ProcedureHeading  : yprocedure 
					Identifier 
					{
                        aProcedure = new ProcedureRecord(yylval.str);
                        table ->enterScope(aProcedure);
               }
                  | yprocedure Identifier
                    {
                        aProcedure = new ProcedureRecord(yylval.str);
                        table ->enterScope(aProcedure);
                    }
                    FormalParameters
                  ;
FunctionHeading   : yfunction Identifier 
					{
                        aProcedure = new ProcedureRecord(yylval.str);
                        table ->enterScope(aProcedure);
                    }
                  | yfunction Identifier 
                  	{
                        aProcedure = new ProcedureRecord(yylval.str);
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
                  |  IdentList  ycolon Identifier
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
