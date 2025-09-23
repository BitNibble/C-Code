/*************************************************************************
Title:    OSTDIO
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdio.h$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    Singleton module interface wrapping stdio.h functions.
*************************************************************************/
#ifndef OSTDIO_H
#define OSTDIO_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdio.h>

typedef struct {
    FILE *(*fopen)(const char *filename, const char *mode);
    int (*fclose)(FILE *stream);
    size_t (*fread)(void *ptr, size_t size, size_t nmemb, FILE *stream);
    size_t (*fwrite)(const void *ptr, size_t size, size_t nmemb, FILE *stream);
    int (*fflush)(FILE *stream);
    int (*fseek)(FILE *stream, long offset, int whence);
    long (*ftell)(FILE *stream);
    void (*rewind)(FILE *stream);
    int (*ferror)(FILE *stream);
    void (*clearerr)(FILE *stream);
    int (*feof)(FILE *stream);

    int (*fprintf)(FILE *stream, const char *format, ...);
    int (*fscanf)(FILE *stream, const char *format, ...);

    int (*printf)(const char *format, ...);
    int (*scanf)(const char *format, ...);
    int (*sprintf)(char *str, const char *format, ...);
    int (*snprintf)(char *str, size_t size, const char *format, ...);
    int (*sscanf)(const char *str, const char *format, ...);

    int (*remove)(const char *filename);
    int (*rename)(const char *oldname, const char *newname);
    FILE *(*tmpfile)(void);
    char *(*tmpnam)(char *str);

    void (*perror)(const char *s);

    int (*setvbuf)(FILE *stream, char *buf, int mode, size_t size);
    void (*setbuf)(FILE *stream, char *buf);
} OSTDIO;

OSTDIO *OSTDIOenable(void);

#ifdef __cplusplus
}
#endif

#endif /* OSTDIO_H */
/*** EOF ***/

