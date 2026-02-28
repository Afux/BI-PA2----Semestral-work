CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++17 -O2
EXECUTABLE = main
SOURCES := $(wildcard src/*.cpp)
OBJECTS := $(SOURCES:.cpp=.o)
LDLIBS = -lstdc++fs
DOXYGEN = doxygen
DOXYGENCONF = Doxyfile

CONFIG_FILE = My_config.txt

SRC_DIR = examples/src
TEST_DIR = examples/TESTER

WIDTH = $(shell tput cols 2>/dev/null || echo 100)
HEIGHT = $(shell tput lines 2>/dev/null || echo 30)

.PHONY: all compile run clean doc config-gen prepare-tester

all: compile

compile: prepare-tester config-gen $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

prepare-tester:
	rm -rf $(TEST_DIR)
	mkdir -p examples
	cp -r $(SRC_DIR) $(TEST_DIR)

config-gen:
	@echo "path=$(shell pwd)/$(TEST_DIR)" > $(CONFIG_FILE)
	@echo "width=$(WIDTH)" >> $(CONFIG_FILE)
	@echo "height=$(HEIGHT)" >> $(CONFIG_FILE)

run: compile
	./$(EXECUTABLE)

doc:
	$(DOXYGEN) $(DOXYGENCONF)

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) $(CONFIG_FILE)
	rm -rf $(TEST_DIR)
