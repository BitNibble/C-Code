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

## Detect OS and set RM command accordingly
ifeq ($(OS),Windows_NT)
	RM = del /Q
	RMFLAGS = 2>nul
else
	RM = rm -vf
	RMFLAGS =
endif

## Clean artifacts
clean:
	@echo "Cleaning build files..."
	-$(RM) *.o *.s *.ppj *.tag *.exe *.ppx $(PROJECT) $(USERLIBSRC)*.o $(RMFLAGS)
