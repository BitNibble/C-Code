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
	Very Stable
************************************************************************/
#ifndef _PCFICHEIRO_H_
	#define _PCFICHEIRO_H_
/*
** library
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<inttypes.h>
#include <errno.h>
/*
** constant and macro
*/
#define FILENAMESIZE 128
/*
** variable
*/
struct ficheiro{
	//Local Variables
	struct ficheiro *self;
	FILE *fp;
	int fd;
	int errcode;
	char filename[FILENAMESIZE];
	char permision[8];
	int whence;
    long offset;
	// Function Pointers
	void (*open)(const char *filename, const char *permision);
	int (*close)(void);
	int (*putch)(int c);
	int (*puts)(const char* s);
	int (*read)(void *ptr, size_t size, size_t nmemb);
	int (*write)(const void *ptr, size_t size, size_t nmemb);
	void (*rewind)(void);
	FILE* (*filepointer)(void);
	int (*filedescriptor)(void);
};
typedef struct ficheiro FICHEIRO;
/*
** procedure and function header
*/
FICHEIRO FICHEIROenable(struct ficheiro *self);
#endif
/***EOF***/
