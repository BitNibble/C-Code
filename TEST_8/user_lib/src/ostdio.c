/*************************************************************************
Title:    OSTDIO
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdio.c, v 0.1 2025/06/16$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
	
*************************************************************************/
#include "ostdio.h"
#include <stdarg.h>

/*** Procedure and Function declaration ***/
int _fprintf(FILE *fp, const char *fmt, ...);
int _fscanf(FILE *fp, const char *fmt, ...);
int _printf(const char *fmt, ...);

/*** Internal State ***/
static OSTDIO iface = {
    .fopen   = fopen,
    .fclose  = fclose,
    .fread   = fread,
    .fwrite  = fwrite,
    .fgets   = fgets,
    .fputs   = fputs,
    .fprintf = _fprintf,
    .fscanf  = _fscanf,
    .fflush  = fflush,
    .fseek   = fseek,
    .ftell   = ftell,
    .rewind  = rewind,
    .printf  = printf,
    .scanf   = scanf,
    .getchar = getchar,
    .perror  = perror
};

/*** Handler ***/
OSTDIO *ostdio(void) {
    return &iface;
}

/*** Procedure and Function definition ***/
int _fprintf(FILE *fp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vfprintf(fp, fmt, ap);
    va_end(ap);
    return r;
}

int _fscanf(FILE *fp, const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    int r = vfscanf(fp, fmt, ap);
    va_end(ap);
    return r;
}

int _printf(const char *fmt, ...) {
	va_list ap;
    va_start(ap, fmt);
    int r = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return r;
}

/***EOF***/

