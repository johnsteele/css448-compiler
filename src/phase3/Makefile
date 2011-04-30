# File:   Makefile
# Author: John Steele
# Date:	  March 2, 2011
# Description: Makefile for flex_scanner and yacc_parser used in CSS448.

OBJ = main.o lex.yy.o y.tab.o      # all object files, the .o  files
                                   # change lex.o to lex.yy.o if (f)lex used
H = y.tab.h tokenconst.h

# The $ is a macro reference.  The following ident is replaced with the
# specified list.  Parens must be used if the ident is longer than one char.

a.out: $(OBJ) $H                   # a.out depends on everything
	g++ $(OBJ) -o a.out

main.o: main.cpp                   # main.o depends on main.cpp
	g++ -c  main.cpp

lex.yy.c: $H flex_scanner.l        # lex.yy.c depend on the lex file, lex.l -> I removed $H b/c I get error no rule for y.tab.h
	flex flex_scanner.l

lex.yy.o: lex.yy.c                 # lex.yy.o depend on lex.yy.c
	g++ -c lex.yy.c   

y.tab.o: y.tab.c                   # y.tab.o depends on y.tab.c
	g++ -c y.tab.c

y.tab.%: bison_parser.y            # y.tab.c depends on the yacc file, y   
	yacc -d -v bison_parser.y

