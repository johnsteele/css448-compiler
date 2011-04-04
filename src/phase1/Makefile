# File:   Makefile
# Author: John Steele
# Date:	  March 2, 2011
# Description: Makefile for flex_scanner used in CSS448.

BIN=flex_scanner
CC=gcc
LEXER=flex
CFLAGS=-g -o

SRCS=$(BIN).l
OBJS=lex.yy

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(BIN) $(OBJS).c 

%.o:%.c  
	$(LEXER) $(SRCS)

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c 

