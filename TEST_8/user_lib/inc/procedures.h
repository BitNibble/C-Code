/************************************************************************
Title:    procedures
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: procedures.h$
Software: GCC
Hardware: OS
License:  Free beer
************************************************************************/
#ifndef _PROCEDURES_H_
	#define _PROCEDURES_H_

#include <stdint.h>

typedef struct {
	int  (*change_directory)(const char* dirname);
	int  (*launch_excel)(void);
	int  (*launch_word)(void);
	int  (*launch_powerpoint)(void);
	int  (*launch_flowchart)(void);
	int  (*launch_formula)(void);
}PROCEDURES;

PROCEDURES* PROCEDURESenable(void);

#endif

/***EOF***/

