CXX=gcc
SRC=$(wildcard *.c)
BIN=main

all:
	$(CXX) -o $(BIN) $(SRC) -lm

%.clean:
	rm $(BIN)

run:
	./$(BIN)
