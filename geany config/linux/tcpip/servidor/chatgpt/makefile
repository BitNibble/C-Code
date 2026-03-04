CC = gcc
CXX = gcc
CFLAGS = -c -Wall
SFLAGS = -S -Wall
LIBS = -lm
LDFLAGS =
PROJECT = servsocket 
SOURCE_FILES = server.c serversocket.c
OBJECT_FILES = $(SOURCE_FILES:.c=.o)
ASM_FILES = $(SOURCE_FILES:.c=.s)

# Default target
all: $(PROJECT)

# Link object files to create the executable
$(PROJECT): $(OBJECT_FILES)
	$(CXX) $(OBJECT_FILES) -o $(PROJECT) $(LIBS)

# Compile C source files to object files
%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

# Assemble source files to assembly files
%.s: %.c
	$(CC) $(SFLAGS) $< -o $@

# Clean up generated files
clean:
	rm -rf $(OBJECT_FILES) $(ASM_FILES) $(PROJECT)
