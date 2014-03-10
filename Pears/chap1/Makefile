CC=gcc
PROGS=bitsort bitsortgen qsortints sortints

all=$(PROGS)
objs=bitsort.o bitsortgen.o qsortints.o sortints.o
srcs=bitsort.c bitsortgen.c qsortints.c sortints.cpp

$(all):$(objs)
	$(CC) -Wall -o bitsort bitsort.o
	$(CC) -Wall -o bitsortgen bitsortgen.o
	$(CC) -Wall -o qsortints qsortints.o
	g++ -Wall -o sortints sortints.cpp
$(objs):
.PHONY : clean
clean:
	-rm $(PROGS) $(objs)
