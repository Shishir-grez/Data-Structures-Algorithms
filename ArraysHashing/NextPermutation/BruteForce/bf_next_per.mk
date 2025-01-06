# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -std=c++11  # Optional flags for compiler, e.g., enabling all warnings

# Output file
OUTPUT = bf_next_per.exe

# Source file
SRC = bf_next_per.cpp

# Default target: compile and run the program
all: $(OUTPUT)
	./$(OUTPUT)

# Compile the source file into the executable
$(OUTPUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUTPUT)

# Clean up generated files
clean:
	rm -f $(OUTPUT)

.PHONY: all clean
