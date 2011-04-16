# File:   Makefile
# Author: John Steele
# Date:	  March 2, 2011
# Description: Makefile for flex_scanner and yacc_parser used in CSS448.
BIN_1=flex_scanner
BIN_2=yacc_parser

CC=gcc
LEXER=flex
PARSER=yacc 
CFLAGS=-g -o

SRCS=$(BIN_1).l
OBJS=lex.yy

$(BIN_1): $(OBJS)
	$(CC) $(CFLAGS) $(BIN) $(OBJS).c 

%.o:%.c  
	$(LEXER) $(SRCS)

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c 

