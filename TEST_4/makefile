###########################################################
#                                                         #
#                       MAKEFILE                          #
#                                                         #
# author: sergio santos                                   #
# mail: sergio.salazar.santos@gmail.com] (year: 2012)     #
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

USERLIBINC=./user_lib/inc/
USERLIBSRC=./user_lib/src/
PROJECT=out

HFILES=$(wildcard $(USERLIBINC)*.h)
CFILES=$(wildcard *.c $(USERLIBSRC)*.c)

ALLFILES=$(wildcard *.c $(USERLIBINC)*.h $(USERLIBSRC)*.c)

OFILES=$(patsubst %.c, %.o,$(ALLFILES))
ASMFILES=$(patsubst %.c, %.S,$(ALLFILES))

##PROCEDURES HEADER
.PHONY: clean run message

##PROJECT
$(PROJECT): $(HFILES) $(OFILES)
	@echo "PROJECT"
	$(CC) $(WARNING) $(OFILES) $(LIBMATH) -o $@

##COMPILER
%.o:%.c  $(HFILES) $(CFILES)
	@echo "COMPILER"
	$(CC) $(COMPILE) $(WARNING) $< -o $@

##PROCEDURES
clean:
	-rm -vf *.o *.s *.ppj *.tag *.exe *.ppx $(PROJECT)
run: $(PROJECT)
##	chmod 775 $(PROJECT)
	./$(PROJECT)
message:
	@echo "$(ASMFILES) -- $(OFILES) -- $(HFILES) -- $(CFILES)"
##EOF
