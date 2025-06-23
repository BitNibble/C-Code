/************************************************************************
Title:    procedures
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: procedures.h$
Software: GCC
Hardware: PC
License:  Free beer
************************************************************************/
#ifndef _PROCEDURES_H_
	#define _PROCEDURES_H_

#include <stdlib.h>
#include <stdint.h>

typedef struct {
	int (*strtotok)(char* line, char* token[], const char* parser);
	void (*rmcrnl)(char* str);
	char* (*vsnprintf)(char *s, ... );
	int  (*change_directory)(const char* dirname);
	int  (*launch_excel)(void);
	int  (*launch_word)(void);
	int  (*launch_powerpoint)(void);
	int  (*launch_flowchart)(void);
	int  (*launch_formula)(void);
	int (*launch_bash)(void);
	char* (*time)(void);
	
}PROCEDURES;

void oprocedure_enable(void);
PROCEDURES* oprocedure(void);

#endif

/***EOF***/

/******
1º Sequence
2º Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3º Pointer and Variable
4º Casting
******/

