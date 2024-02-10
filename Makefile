# Compiler settings
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

# Source files and executable name
SRC = main.cpp
EXE = my_program

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(EXE)

# Compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files into executable
$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE)

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXE)
