/*************************************************************************
Title:    OSTRING (WRAPPER)
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostring.h.c, v 0.1 2025/06/16$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
	
*************************************************************************/
#ifndef OSTRING_H
#define OSTRING_H

#include <stddef.h>

typedef struct OSTRING {
    size_t (*len)(const char *s);
    char *(*cpy)(char *dest, const char *src);
    char *(*ncpy)(char *dest, const char *src, size_t n);
    int (*cmp)(const char *s1, const char *s2);
    int (*ncmp)(const char *s1, const char *s2, size_t n);
    char *(*cat)(char *dest, const char *src);
    char *(*ncat)(char *dest, const char *src, size_t n);
    void *(*memset)(void *s, int c, size_t n);
    void *(*memcpy)(void *dest, const void *src, size_t n);
    void *(*memmove)(void *dest, const void *src, size_t n);
    int (*memcmp)(const void *s1, const void *s2, size_t n);
} OSTRING;

OSTRING *OSTRINGenable(void);

#endif
