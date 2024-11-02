CC = gcc
CXX = gcc
CFLAGS = -c -Wall
SFLAGS = -S -Wall
LIBS = -lm
PROJECT = clisocket 
SOURCES = client.c clientsocket.c
OBJECTS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.s)

# Targets
all: $(PROJECT)

$(PROJECT): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(PROJECT) $(LIBS)

%.o: %.c
	$(CXX) $(CFLAGS) $< -o $@

%.s: %.c
	$(CXX) $(SFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS) $(ASMS) $(PROJECT)

.PHONY: all clean
