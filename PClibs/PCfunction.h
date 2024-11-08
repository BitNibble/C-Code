/************************************************************************
Title:    PCFUNCTION
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.h,v 0.1 2015/08/01 14:00:00 sergio Exp $
Software: GCC
Hardware:
License:  GNU General Public License
Usage:
LICENSE:
    Copyright (C) 2015
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	Very Stable
************************************************************************/
#ifndef _PCFUNCTION_H_
	#define _PCFUNCTION_H_
/*
** library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
#include <stdlib.h>
// strcpy strcmp strcat memcmp
#include <string.h>
#include<inttypes.h>
// termios tcflush
//#include <termios.h>
// nanosleep sleep
//#include <time.h>
// tcflsuh read write close
//#include <unistd.h>
// perror
#include <errno.h>
// open
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
/*
** constant and macro
*/
/*
** variable
*/
struct func{
	//char *value;
	/***PROTOTYPES VTABLE***/
	int (*stringlength)(const char string[]);
	void (*reverse)(char s[]);
	char* (*ftoa)(float n, char* res, uint8_t afterpoint);
	/***/
	char* (*fltos)(FILE* stream);
	char* (*ftos)(FILE* stream);
	int (*strtotok)(char* line,char* token[],const char* parser);
	char* (*putstr)(char* str);
	int (*getnum)(char* x);
	unsigned int (*getnumv2)(char* x);
	int (*readint)(int nmin, int nmax);
	unsigned int (*mayia)(unsigned int xi, unsigned int xf, unsigned int nbits);
	unsigned int (*pinmatch)(unsigned int match, unsigned int pin, unsigned int HL);
	unsigned int (*lh)(unsigned int xi, unsigned int xf);
	unsigned int (*hl)(unsigned int xi, unsigned int xf);
	unsigned int (*diff)(unsigned int xi, unsigned int xf);
	char* (*print_binary)(unsigned int n_bits, int number);
	unsigned int (*decimal_binary)(unsigned int n);
	unsigned int (*binary_decimal)(unsigned int n);
	void (*strflip)(char* s);
	//char (*mm74c923_read)(char c);
};
typedef struct func FUNC;
/*
** procedure and function header
*/
FUNC FUNCenable(void);
#endif
/***EOF***/
