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

CFLAGS = -g -Wall -Wextra -Werror -m64 -I. -I./user_lib/inc/
LDFLAGS = -m64 -lm

PROJECT = out.exe

USERLIBINC = ./user_lib/inc
USERLIBSRC = ./user_lib/src
WUSERLIBINC = user_lib\inc
WUSERLIBSRC = user_lib\src

CFILES = $(wildcard *.c $(USERLIBSRC)/*.c)
OFILES = $(CFILES:.c=.o)
##OFILES = $(CFILES:%.c=%.o)
##OFILES = $(patsubst %.c,%.o,$(CFILES))

.PHONY: all run message clean

## Build target
all: $(PROJECT)

$(PROJECT): $(OFILES)
	@echo "Linking..."
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

## Compile .c to .S first (assembly)
%.S: %.c
	@echo "Generating assembly for $<"
	$(CC) -S $(CFLAGS) $< -o $@

## Compile .c to .o depends on .S (so .S is generated first)
%.o: %.c
	@echo "Compiling $< to object"
	$(CC) -c $(CFLAGS) $< -o $@

## Run the program
run: $(PROJECT)
	@echo "Running Program $<"
ifeq ($(OS),Windows_NT)
	@$(PROJECT)
else
	@chmod 755 $(PROJECT)
	@./$(PROJECT)
endif
## Print file info
message:
	@echo "CFILES: $(CFILES)"
	@echo "OFILES: $(OFILES)"
## Clean artifacts
clean:
	@echo "Cleaning build files..."
ifeq ($(OS),Windows_NT)
	-del /Q $(WUSERLIBINC)\*.gch 2>nul
	-del /Q *.o *.s *.ppj *.tag *.ppx $(PROJECT) 2>nul
	-del /Q $(WUSERLIBSRC)\*.o 2>nul
else
	rm -vf $(USERLIBINC)/*.gch
	rm -vf *.o *.s *.ppj *.tag *.ppx $(PROJECT)
	rm -vf $(USERLIBSRC)/*.o
endif

