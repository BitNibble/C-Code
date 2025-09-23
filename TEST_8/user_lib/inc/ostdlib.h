/*************************************************************************
Title:    OSTDLIB
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdlib.h$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    Singleton module interface wrapping stdlib.h functions.
*************************************************************************/
#ifndef OSTDLIB_H
	#define OSTDLIB_H

#include <stddef.h>  // size_t
#include <limits.h>  // for div_t, etc.

typedef struct {
    void *(*malloc)(size_t size);
    void *(*calloc)(size_t num, size_t size);
    void *(*realloc)(void *ptr, size_t size);
    void (*free)(void *ptr);

    int   (*atoi)(const char *str);
    long  (*atol)(const char *str);
    long long (*atoll)(const char *str);
    double (*atof)(const char *str);

    long (*strtol)(const char *nptr, char **endptr, int base);
    unsigned long (*strtoul)(const char *nptr, char **endptr, int base);
    long long (*strtoll)(const char *nptr, char **endptr, int base);
    unsigned long long (*strtoull)(const char *nptr, char **endptr, int base);

    int (*abs)(int n);
    long (*labs)(long n);
    long long (*llabs)(long long n);

//    div_t (*div)(int numer, int denom);
//    ldiv_t (*ldiv)(long numer, long denom);
//    lldiv_t (*lldiv)(long long numer, long long denom);

//    int (*rand)(void);
//    void (*srand)(unsigned int seed);

    void (*exit)(int status);
//    void (*abort)(void);
//    int (*atexit)(void (*func)(void));
//    int (*system)(const char *command);

//    void *(*bsearch)(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
//    void (*qsort)(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));

//    char *(*getenv)(const char *name);
} OSTDLIB;

OSTDLIB *ostdlib(void);

#endif /* OSTDLIB_H */
/*** EOF ***/

