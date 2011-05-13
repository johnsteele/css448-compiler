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
#include "SymbolTable.h"
#include "ProcedureRecord.h"
#include "ConstantRecord.h"
using namespace std;
SymbolTable * table = NULL;
ProcedureRecord * program = NULL;
ProcedureRecord * aProcedure = NULL;
ProcedureRecord * parent = NULL;
ConstantRecord * constant = NULL;
//TypeRecord * theType = NULL;
//VariableRecord * v = NULL;
Parameter * param = NULL;
int scope;
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
                            parent = program;
                            aProcedure = program;
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
                            program-> insertParam(param);
                     }
                   | Identifier
                     { 
                            ProcedureRecord &r = dynamic_cast<ProcedureRecord &> (*program);
                            r.insertParam(param);
                            param = new Parameter(yylval.str);
                            program-> insertParam(param);
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
                     table->addSymbol(constant);
                  ;
TypeDef           :  Identifier { /*theType = new TypeRecord(yylval.str);*/}
                     yequal  Type {/*theType ->setType(yylval.str);*/}
                  ;
VariableDecl      :  IdentList { /*v = new VariableRecord(yylval.str);*/}
                     ycolon  Type {/*v ->setType(yylval.str);*/}
                  ;

/***************************  Const/Type Stuff  ******************************/

ConstExpression   :  UnaryOperator ConstFactor
                  {    /*have to figure out a way to deal with unary operator*/
                  }
                  |  ConstFactor
                  {   $$ = $1;
                  }

                  |  ystring /*not handling any const but numbers right now*/
                  ;
ConstFactor       :  Identifier
                  |  ynumber 
                    {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                     r.setConstFactor(atoi(yylval.str));}}
                  |  ytrue   
                     {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(1);
                      r.setIsBool();
                     }
                  |  yfalse  {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(1);
                      r.setIsBool();}
                  |  ynil    {ConstantRecord &r = dynamic_cast<ConstantRecord &> (*constant);
                      r.setConstFactor(atoi(yylval.str));}
                  ;
Type              :  Identifier /*will have to work out how to leave the pointer*/
                  |  ArrayType
                  |  PointerType
                  |  RecordType
                  |  SetType
                  ;
ArrayType         :  yarray yleftbracket SubrangeList yrightbracket  yof Type
                  ;
SubrangeList      :  Subrange
                  |  SubrangeList ycomma Subrange
                  ;
Subrange          :  ConstFactor ydotdot ConstFactor
                  |  ystring ydotdot  ystring
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

UnaryOperator     :  yplus
                  |  yminus
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
