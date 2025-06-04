###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
# Author: Sergio Santos                                   #
# Mail: sergio.salazar.santos@gmail.com (year: 2012)      #
#                                                         #
###########################################################

CC = gcc
CXX = g++
AS = as

CFLAGS = -g -Wall -Wextra -I. -I./user_lib/inc/
LDFLAGS = -lm

PROJECT = out

USERLIBINC = ./user_lib/inc/
USERLIBSRC = ./user_lib/src/

CFILES = $(wildcard *.c $(USERLIBSRC)*.c)
OFILES = $(CFILES:.c=.o)

.PHONY: all run message clean

## Build target
all: $(PROJECT)

$(PROJECT): $(OFILES)
	@echo "Linking..."
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@
	
## Compile .c to .S first (assembly)
%.S: %.c
	@echo "Generating assembly for $<"
	$(CC) -S $(WARNING) $< -o $@

## Compile .c to .o depends on .S (so .S is generated first)
%.o: %.c %.S
	@echo "Compiling $< to object"
	$(CC) -c $(WARNING) $< -o $@

## Run the program
run: $(PROJECT)
	@./$(PROJECT)

## Print file info
message:
	@echo "CFILES: $(CFILES)"
	@echo "OFILES: $(OFILES)"
	
## Clean artifacts
clean:
ifeq ($(OS),Windows_NT)
	@echo "Cleaning on Windows"
	-del /Q *.o *.s *.ppj *.tag *.exe *.ppx out 2>nul
	-del /Q user_lib\src\*.o 2>nul
else
	@echo "Cleaning on Linux/macOS"
	-rm -vf *.o *.s *.ppj *.tag *.exe *.ppx $(PROJECT) $(USERLIBSRC)*.o
endif
