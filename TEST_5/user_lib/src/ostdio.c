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
FILE *_fopen(const char *path, const char *mode);
int _fclose(FILE *fp);
size_t _fread(void *ptr, size_t size, size_t nmemb, FILE *fp);
size_t _fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp);
char *_fgets(char *s, int size, FILE *fp);
int _fputs(const char *s, FILE *fp);
int _fprintf(FILE *fp, const char *fmt, ...);
int _fscanf(FILE *fp, const char *fmt, ...);
int _fflush(FILE *fp);
int _fseek(FILE *fp, long offset, int whence);
long _ftell(FILE *fp);
void _rewind(FILE *fp);

/*** singleton interface ***/
static OSTDIO iface = {
    .fopen   = _fopen,
    .fclose  = _fclose,
    .fread   = _fread,
    .fwrite  = _fwrite,
    .fgets   = _fgets,
    .fputs   = _fputs,
    .fprintf = _fprintf,
    .fscanf  = _fscanf,
    .fflush  = _fflush,
    .fseek   = _fseek,
    .ftell   = _ftell,
    .rewind  = _rewind,
};

/*** static passthroughs ***/
FILE *_fopen(const char *path, const char *mode) {
    return fopen(path, mode);
}

int _fclose(FILE *fp) {
    return fclose(fp);
}

size_t _fread(void *ptr, size_t size, size_t nmemb, FILE *fp) {
    return fread(ptr, size, nmemb, fp);
}

size_t _fwrite(const void *ptr, size_t size, size_t nmemb, FILE *fp) {
    return fwrite(ptr, size, nmemb, fp);
}

char *_fgets(char *s, int size, FILE *fp) {
    return fgets(s, size, fp);
}

int _fputs(const char *s, FILE *fp) {
    return fputs(s, fp);
}

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

int _fflush(FILE *fp) {
    return fflush(fp);
}

int _fseek(FILE *fp, long offset, int whence) {
    return fseek(fp, offset, whence);
}

long _ftell(FILE *fp) {
    return ftell(fp);
}

void _rewind(FILE *fp) {
    rewind(fp);
}

OSTDIO *OSTDIOenable(void) {
    return &iface;
}
/***EOF***/


