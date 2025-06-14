/************************************************************************
Title:    poop
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: poop.h$
Software: GCC
Hardware: OS
License:  Free beer
************************************************************************/
#ifndef _POOP_H_
	#define _POOP_H_
#include "PCficheiro.h"
/***strtotok***/
int strtotok(char* line, char* token[], const char* parser);
void rmcrnl(char* str);
void fplfsm( const char* seq_name, const char* search, size_t buff_size, FICHEIRO* file, char* logic, char* feedback );
char* logsnprintf( const char* search );
char* seqsnprintf( const char* seq_name, const char* search, const char* feedback );
void pooplfsm( const char* poopin, const char* parser, const size_t line_size, FICHEIRO* file, char* poopout );
#endif
/***EOF***/

