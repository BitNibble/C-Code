/************************************************************************
Title:    poop
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: poop.h$
Software: GCC
Hardware: PC
License:  Free beer
************************************************************************/
#ifndef _POOP_H_
	#define _POOP_H_

#include "PCficheiro.h"
#include <stddef.h>

typedef struct POOP {
    int  (*strtotok)(char* line, char* token[], const char* parser);
    void (*rmcrnl)(char* str);
    void (*fplfsm)(const char* seq_name, const char* search, size_t buff_size, FICHEIRO* file, char* logic, char* feedback);
    char* (*logsnprintf)(const char* search);
    char* (*seqsnprintf)(const char* seq_name, const char* search, const char* feedback);
    void (*pooplfsm)(const char* poopin, const char* parser, size_t line_size, FICHEIRO* file, char* poopout);
} POOP;

POOP* opoop(void);

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

