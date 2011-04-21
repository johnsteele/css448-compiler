# File:   Makefile
# Author: John Steele
# Date:	  March 2, 2011
# Description: Makefile for flex_scanner and yacc_parser used in CSS448.



# bison_scanner depends on everything.
a.out: y.tab.o main.o flex_scanner.o y.tab.h 
	gcc y.tab.o lex.yy.o main.o 

# main.o depends on main.c 
main.o: main.c
	gcc -c main.c

# lex.yy.o depends on lex.yy.c
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c 

# lex.yy.c depends on the flex file.
lex.yy.c: flex_scanner.l
	flex flex_scanner.l 

# y.tab.o depends on y.tab.c.
y.tab.o: y.tab.c
	gcc -c y.tab.c

# y.tab.c depends on bison_parser.
y.tab.c: bison_parser.y
	yacc -d -v bison_parser.y

