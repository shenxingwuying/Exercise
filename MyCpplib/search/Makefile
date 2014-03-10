CC=g++


main:main.o
	$(CC) -Wall -o main main.o
main.o:main.cpp BinarySearch.h
	$(CC) -Wall -c main.cpp
clean:
	rm -f main *.o *.s *.i *.gch
