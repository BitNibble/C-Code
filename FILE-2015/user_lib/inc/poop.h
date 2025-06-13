/************************************************************************
Title:    poop
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: poop.h$
Software: GCC
Hardware: OS
License: Free beer
************************************************************************/
#include "PCficheiro.h"
#ifndef _POOP_H_
	#define _POOP_H_
int strtotok(char* line, char* token[], const char* parser);
void rmcrnl(char* str);
void fplfsm( const char* seq_name, const char* search, size_t buff_size, FICHEIRO* file, char* logic, char* feedback );
#endif
/***EOF***/

