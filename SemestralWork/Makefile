CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -O2 -ggdb3
EXECUTABLE = afu
SOURCES := $(wildcard src/*.cpp libs/*.hpp src/*.h)
CHECK = valgrind
CHECKFLAGS = --leak-check=full
LDLIBS=-lstdc++fs

.PHONY: all compile run clean

all: compile run clean

compile: 
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS)


run: compile
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
