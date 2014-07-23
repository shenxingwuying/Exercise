CC=g++
BIN=main
OBJ=main.o sort.o
SRC=main.cpp sort.cpp

$(BIN):$(OBJ)
	$(CC) -o $(BIN) $(OBJ)
$(OBJ):$(SRC)
	$(CC) -c $(SRC)
clean:
	rm -rf $(BIN) $(OBJ) *.h.gch
