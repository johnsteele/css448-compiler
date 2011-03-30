//========================================================================
/**
 * @file		css448-compiler/src/phase1/tokenconst.h
 * @author	John Steele <EMAIL:programjsteele {at} gmail {dot} com>
 * @version	1.0.0
 * @date
 * 	Created:	Wed 30 Mar 2011 11:05:24 AM PDT \n
 * 	Last Update:	Wed 30 Mar 2011 11:05:24 AM PDT
 */
/*------------------------------------------------------------------------
 * Description: Contains the token constants used by the lexical 
 * 						  analyzer.  	 
 *------------------------------------------------------------------------
 * History:	johns - march 30, 2011
 *========================================================================
 */

#ifndef _TOKENCONST_H_
#define _TOKENCONST_H_

// yacc uses numbers through 256, starts your token count at 257
// tokens are in alphabetical order, except yunknown, which is last
int const yand = 257;
int const yarray = 258;
int const yassign = 259;
int const ybegin = 260;
int const ycaret = 261;
int const ycase = 262;
int const ycolon = 263;
int const ycomma = 264;
int const yconst = 265;
int const ydispose = 266;
int const ydiv = 267;
int const ydivide = 268;
int const ydo = 269;
int const ydot = 270;
int const ydotdot = 271;
int const ydownto = 272;
int const yelse = 273;
int const yend = 274;
int const yequal = 275;
int const yfalse = 276;
int const yfor = 277;
int const yfunction = 278;
int const ygreater = 279;
int const ygreaterequal = 280;
int const yident = 281;
int const yif = 282;
int const yin = 283;
int const yleftbracket = 284;
int const yleftparen = 285;
int const yless = 286;
int const ylessequal = 287;
int const yminus = 288;
int const ymod = 289;
int const ymultiply = 290;
int const ynew = 291;
int const ynil = 292;
int const ynot  = 293;
int const ynotequal = 294;
int const ynumber = 295;
int const yof = 296;
int const yor = 297;
int const yplus = 298;
int const yprocedure = 299;
int const yprogram = 300;
int const yread = 301;
int const yreadln = 302;
int const yrecord = 303;
int const yrepeat = 304;
int const yrightbracket = 305;
int const yrightparen = 306;
int const ysemicolon = 307;
int const yset = 308;
int const ystring = 309;
int const ythen = 310;
int const yto = 311;
int const ytrue = 312;
int const ytype = 313;
int const yuntil = 314;
int const yvar = 315;
int const ywhile = 316;
int const ywrite = 317;
int const ywriteln = 318;
int const yunknown = 319; 

#endif /* _TOKENCONST_H_ */ 

