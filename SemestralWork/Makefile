CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -O2
EXECUTABLE = korytale
SOURCES := $(wildcard src/*.cpp)
OBJECTS :=$(SOURCES:.cpp=.o)
CHECK = valgrind
CHECKFLAGS = --leak-check=full
LDLIBS=-lstdc++fs
DOXYGEN=doxygen
DOXYGENCONF=Doxyfile

.PHONY: all compile run clean doc

all: doc compile

compile: $(EXECUTABLE)

$(EXECUTABLE):$(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
run: compile
	./$(EXECUTABLE)
doc:
	$(DOXYGEN) $(DOXYGENCONF)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
