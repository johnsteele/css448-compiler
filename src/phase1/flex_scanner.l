	/******************************************************************************
	 *	@file      css448-compiler/src/phase1/tokenconst.h                        *
	 *	@author	   John Steele <EMAIL:programjsteele {at} gmail  {dot} com>       *
	 *	@author    Alicia Flinchum	<EMAIL:aliciaflinchum {at} yahoot {dot} com>  *
 	 *	@version	 1.0.0                                                          *
 	 *	@date Created: Wed 30 Mar 2011 11:05:24 AM PDT \n                         *
 	 *	Last Update:	 Wed 30 Mar 2011 11:05:24 AM PDT                            *
   *                                                                            *
   *  Description: This is a scanner for a Pascal-like language used for        *
   *							 a compiler project in css-448. It is to be used with         *
 	 *  						 flex (lexical analyser).                                     *
   *                                                                            *
	 *  Usage: > flex flex_scanner.l                                              *
   *         > gcc -g -o lex.yy.c scanner                                       *
   *	       > ./scanner < datafile                                             * 
	 ******************************************************************************/

	/* Lets assume yywrap() will return 1 (i.e. finish after EOF). */
%option noyywrap 



