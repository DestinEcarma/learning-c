# Change the commands that needs to be used for Windows and Unix systems
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
    MKDIR = mkdir
    RM = rmdir /S /Q
	SEP = \\
else
    EXE_EXT = 
    MKDIR = mkdir -p
    RM = rm -rf
	SEP = /
endif

# Source and header files
SOURCES = min-heap.c
HEADERS = min-heap.h defs.h

KRUSKAL_SOURCES = $(SOURCES) kruskal.c
PRIM_SOURCES = $(SOURCES) prim.c
DIJKSTRA_SOURCES = $(SOURCES) dijkstra.c

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directory
TARGET_DIR = target
BIN_DIR = $(TARGET_DIR)$(SEP)bin
OBJ_DIR = $(TARGET_DIR)$(SEP)obj

# Object files
KRUSKAL_OBJECTS = $(patsubst %.c,$(OBJ_DIR)$(SEP)%.o,$(KRUSKAL_SOURCES))
PRIM_OBJECTS = $(patsubst %.c,$(OBJ_DIR)$(SEP)%.o,$(PRIM_SOURCES))
DIJKSTRA_OBJECTS = $(patsubst %.c,$(OBJ_DIR)$(SEP)%.o,$(DIJKSTRA_SOURCES))

# Target executable
KRUSKAL_TARGET = $(BIN_DIR)$(SEP)krusjal$(EXE_EXT)
PRIM_TARGET = $(BIN_DIR)$(SEP)prim$(EXE_EXT)
DIJKSTRA_TARGET = $(BIN_DIR)$(SEP)dijkstra$(EXE_EXT)

# Default rule to run the program
default: kruskal
all: $(KRUSKAL_TARGET) $(PRIM_TARGET) $(DIJKSTRA_TARGET)

# Rule to link the object files to create the Kruskal's executable
$(KRUSKAL_TARGET): $(KRUSKAL_OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(KRUSKAL_TARGET) $(KRUSKAL_OBJECTS)

# Rule to link the object files to create the Prim's executable
$(PRIM_TARGET): $(PRIM_OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(PRIM_TARGET) $(PRIM_OBJECTS)

# Rule to link the object files to create the Dijkstra's executable
$(DIJKSTRA_TARGET): $(DIJKSTRA_OBJECTS) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(DIJKSTRA_TARGET) $(DIJKSTRA_OBJECTS)

# Rule to compile the .c files into .o files
$(OBJ_DIR)$(SEP)%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the target directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	$(MKDIR) $@

# Rule to clean up the compiled files
clean:
	$(RM) $(TARGET_DIR)

# Rule to run the Kruskal's program
kruskal: $(KRUSKAL_TARGET)
	.$(SEP)$(KRUSKAL_TARGET)

# Rule to run the Prim's program
prim: $(PRIM_TARGET)
	.$(SEP)$(PRIM_TARGET)

dijkstra: $(DIJKSTRA_TARGET)
	.$(SEP)$(DIJKSTRA_TARGET)
