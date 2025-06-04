###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
# author: sergio santos                                   #
# mail: sergio.salazar.santos@gmail.com  (year: 2025)     #
#                                                         #
###########################################################
PWD=-I.
CC=gcc
CXX=g++
AS=as
COMPILE=-c
WARNING=-g -Wall -Wextra
ASSEMBLY=-S
#LIBS=-lpthread -lrt
LIBMATH=-lm
#LDLIBS=-lefence -pthread
##VARIABLES AND LISTS
PROJECT=out

USERLIB=./user_lib
ALLFILES=$(wildcard *.c $(USERLIB)/*.c)

OFILES=$(patsubst %.c, %.o,$(ALLFILES))
ASMFILES=$(patsubst %.c, %.S,$(ALLFILES))

##PROCEDURES HEADER
.PHONY: clean run message

##PROJECT
$(PROJECT): $(ALLFILES) $(OFILES)
	@echo "PROJECT"
	$(CC) $(WARNING) $(OFILES) $(LIBMATH) -o $@

##COMPILER
%.o:%.c  $(ALLFILES) $(ASMFILES)
	@echo "COMPILER"
	$(CC) $(COMPILE) $(WARNING) $< -o $@

##PROCEDURES
clean:
	-rm -vf *.o *.s $(PROJECT)
run: $(PROJECT)
##	chmod 775 $(PROJECT)
	./$(PROJECT)
message:
	@echo "$(ASMFILES) -- $(OFILES) -- $(ALLFILES)"
##EOF
