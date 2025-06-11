/************************************************************************
Title:    PCFICHEIRO
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.h,v 0.1 2015/08/12 14:00:00 sergio Exp $
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

************************************************************************/
#ifndef _PCFICHEIRO_H_
	#define _PCFICHEIRO_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

