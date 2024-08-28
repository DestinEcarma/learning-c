# Source and header files
SOURCES = runner.c main.c
HEADERS = runner.h
SOURCES_ARRAY = stackArray.c $(SOURCES)
HEADERS_ARRAY = stackArray.h $(HEADERS)
SOURCES_LL = stackLinkedList.c $(SOURCES)
HEADERS_LL = stackLinkedList.h $(HEADERS)

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# Directory
TARGET_DIR = target
BIN_DIR = $(TARGET_DIR)/bin
OBJ_DIR = $(TARGET_DIR)/obj

# Object files
OBJECTS_ARRAY = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES_ARRAY))
OBJECTS_LL = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES_LL))

# Target executable
TARGET_LL = $(BIN_DIR)/linkedlist
TARGET_ARRAY = $(BIN_DIR)/array

# Rule to link the object files to create the executable
array: $(OBJECTS_ARRAY) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET_ARRAY) $(OBJECTS_ARRAY)
	./$(TARGET_ARRAY)

ll: $(OBJECTS_LL) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $(TARGET_LL) $(OBJECTS_LL)
	./$(TARGET_LL)

# Rule to compile the .c files into .o files
$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the target directories if they don't exist
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Rule to clean up the compiled files
clean:
	rm -rf $(TARGET_DIR)
