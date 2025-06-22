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

/*** static passthroughs ***/
int _fprintf(FILE *fp, const char *fmt, ...);
int _fscanf(FILE *fp, const char *fmt, ...);
int _printf(const char *fmt, ...);

static OSTDIO iface = {0};

void ostdio_enable(void){
/*** singleton interface ***/
    iface.fopen   = fopen;
    iface.fclose  = fclose;
    iface.fread   = fread;
    iface.fwrite  = fwrite;
    iface.fgets   = fgets;
    iface.fputs   = fputs;
    iface.fprintf = _fprintf;
    iface.fscanf  = _fscanf;
    iface.fflush  = fflush;
    iface.fseek   = fseek;
    iface.ftell   = ftell;
    iface.rewind  = rewind;
    iface.printf  = printf;
    iface.scanf   = scanf;
    iface.getchar = getchar;
    iface.perror  = perror;
}

OSTDIO *ostdio(void) {
    return &iface;
}

/*** static passthroughs ***/
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

