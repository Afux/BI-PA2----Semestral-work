CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -O2 -ggdb3
EXECUTABLE = afu
SOURCES := $(wildcard src/*.cpp)
OBJECTS :=$(SOURCES:.cpp=.o)
CHECK = valgrind
CHECKFLAGS = --leak-check=full
LDLIBS=-lstdc++fs

.PHONY: all compile run clean

all: compile 

compile: 
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 
run: compile
	./$(EXECUTABLE)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
