/************************************************************************
Title:    PCFUNCTION
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: PCfunction.h,v 0.1 2015/08/01 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:

************************************************************************/
#ifndef _PCFUNCTION_H_
	#define _PCFUNCTION_H_

#include <stdio.h> // fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdlib.h> // calloc free realloc malloc
#include <string.h> // strcpy strcmp strcat memcmp
#include <stdarg.h>
#include<inttypes.h>
//#include <termios.h> // termios tcflush
//#include <time.h> // nanosleep sleep
//#include <unistd.h> // tcflsuh read write close
#include <errno.h> // perror
//#include <sys/types.h> // open
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>

struct func{
	int (*stringlength)(const char string[]);
	void (*reverse)(char s[]);
	char* (*ftoa)(float n, char* res, uint8_t afterpoint);
	char* (*fltos)(FILE* stream);
	char* (*ftos)(FILE* stream);
	int (*strtotok)(char* line,char* token[],const char* parser);
	int (*getnum)(char* x);
	unsigned int (*getnumv2)(char* x);
	int (*readint)(int nmin, int nmax);
	char* (*print_binary)(unsigned int n_bits, int number);
	unsigned int (*decimal_binary)(unsigned int n);
	unsigned int (*binary_decimal)(unsigned int n);
	void (*strflip)(char* s);
	char* (*print)(char *format, ... );
};
typedef struct func FUNC;

void ofunc_enable(void);
FUNC* ofunc(void);
#endif
/***EOF***/

