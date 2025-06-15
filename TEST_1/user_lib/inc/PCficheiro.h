/************************************************************************
Title:    PCFICHEIRO
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.h,v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  Free beer
Comment:

************************************************************************/
#ifndef _PCFICHEIRO_H_
	#define _PCFICHEIRO_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <errno.h>

#define FILENAMESIZE 128

typedef struct{
	int whence;
    long offset;
	int fd;
	char filename[FILENAMESIZE];
	char permission[4];
	FILE *fp;
}FICHEIRO_par;

typedef struct{
	FICHEIRO_par par;
	void (*openp)(void);
	void (*open)(const char *filename, const char *permission);
	int (*close)(void);
	int (*getc)(void);
	char* (*fgets)(char* buffer, size_t size);
	int (*fputc)(int c);
	int (*fputs)(const char* s);
	void (*printf)(const char* fmt, ...);
	size_t (*read)(void *ptr, size_t size, size_t nmemb);
	size_t (*write)(const void *ptr, size_t size, size_t nmemb);
	void (*rewind)(void);
	FILE* (*filepointer)(void);
	int (*filedescriptor)(void);
}FICHEIRO;

FICHEIRO* FICHEIROenable(void);
#endif
/***EOF***/

