CC=gcc
PROGS=P1 P2 P3 P4 P5

all=$(PROGS)
objs=P1.o P2.o P3.o P4.o P5.o
#srcs=P1.c P2.c


$(all):$(objs)
	$(CC) -Wall -o P1 P1.o
	$(CC) -Wall -o P2 P2.o -lm
	$(CC) -Wall -o P3 P3.o -lm
	$(CC) -Wall -o P4 P4.o -lm
	$(CC) -Wall -o P5 P5.o -lm
$(objs):
.PHONY : clean
clean:
	-rm $(PROGS) $(objs)
