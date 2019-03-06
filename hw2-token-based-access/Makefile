CXX=g++
CXXFLAGS=-g -std=c++11 -flto -Os -Wall
SRC = $(shell find . -name "*.cc")
BIN=token_based_simulation

all:
	$(CXX) -o $(BIN) $(SRC) $(CXXFLAGS)

run:
	./$(BIN)

clean:
	rm $(BIN)
