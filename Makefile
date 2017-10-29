#分割コンパイルする

CC = gcc
objs = main.o ini.o ana.o

ex1: $(objs)
	$(CC) -Wall -O2 -o $@ $(objs)

main.o: main.c
	$(CC) -c $*.c

main.o: lib1.h

ini.o: ini.c
	$(CC) -c $*.c

ana.o: ana.c
	$(CC) -c $*.c

.PHONY: clean
clean:
	$(RM) ex1 $(objs)
