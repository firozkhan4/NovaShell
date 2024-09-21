# Makefile for Novashell

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -std=c++20

# Source files
SRCS = main.cpp shell.cpp file.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = novashell

# Default target
all: $(EXEC)

# Rule to link object files to create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $<

# Clean target to remove object files and the executable
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean

