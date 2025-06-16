/*************************************************************************
Title:    OSTDIO (WRAPPER)
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdio.h.c, v 0.1 2025/06/16$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
	
*************************************************************************/
#ifndef OSTDIO_H
#define OSTDIO_H

#include <stdio.h>

typedef struct {
    FILE *(*fopen)(const char *path, const char *mode);
    int   (*fclose)(FILE *fp);
    size_t (*fread)(void *ptr, size_t size, size_t nmemb, FILE *fp);
    size_t (*fwrite)(const void *ptr, size_t size, size_t nmemb, FILE *fp);
    char *(*fgets)(char *s, int size, FILE *fp);
    int   (*fputs)(const char *s, FILE *fp);
    int   (*fprintf)(FILE *fp, const char *fmt, ...);
    int   (*fscanf)(FILE *fp, const char *fmt, ...);
    int   (*fflush)(FILE *fp);
    int   (*fseek)(FILE *fp, long offset, int whence);
    long  (*ftell)(FILE *fp);
    void  (*rewind)(FILE *fp);
} OSTDIO;

OSTDIO *OSTDIOenable(void);

#endif // OSTDIO_H
/***EOF***/

