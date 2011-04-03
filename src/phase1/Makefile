# File:   Makefile
# Author: John Steele
# Date:   March 2, 2011 
# Description: Makefile for flex_scanner used in CSS448.

BIN=flex_scanner
CC= -g -o 
SRCS=$(BIN).l
OBJS=lex.yy.o
LIBS= -lfl

$(BIN):$(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBS) -o $(BIN)

lex.yy.c: $(BIN).l
	flex $(BIN).l

clean:
	rm -f $(OBJS) $(BIN) lex.yy.c 

