CXX=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -O2

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)
BIN := quick_queue

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BIN)
