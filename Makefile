
#=============================================================================
# Contents   : 電気情報系実験3 C1 CKY法
#              Makefile
# Author     : B15T2017C 太田悠介
# LastUpdate : 2017/10/30
# Since      : 2017/10/28
#=============================================================================


CC = gcc
objs = main.o ini.o cky.o display.o possearch.o ckyini.o dictionaryini.o queini.o
option = -Wall -O2 -o
progname = ex1

ex1: $(objs)
	$(CC) $(option) $(progname) $(objs)

main.o: main.c
	$(CC) -c $*.c

main.o: lib1.h

ini.o: ini.c
	$(CC) -c $*.c

ana.o: ana.c
	$(CC) -c $*.c

display.o: display.c
	$(CC) -c $*.c

cky.o: cky.c
	$(CC) -c $*.c

possearch.o: possearch.c
	$(CC) -c $*.c

ckyini.o: ckyini.c
	$(CC) -c $*.c

dictionaryini.o: dictionaryini.c
	$(CC) -c $*.c

queini.o: queini.c
	$(CC) -c $*.c

.PHONY: clean
clean:
	$(RM) $(progname) $(objs)
