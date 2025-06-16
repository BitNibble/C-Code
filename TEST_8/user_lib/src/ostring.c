/*************************************************************************
Title:    OSTRING (WRAPPER)
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostring.h.c, v 0.1 2025/06/16$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
	
*************************************************************************/
#include "ostring.h"
#include <string.h>

static size_t _strlen(const char *s) {
    return strlen(s);
}

static char *_strcpy(char *dest, const char *src) {
    return strcpy(dest, src);
}

static char *_strncpy(char *dest, const char *src, size_t n) {
    return strncpy(dest, src, n);
}

static int _strcmp(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

static int _strncmp(const char *s1, const char *s2, size_t n) {
    return strncmp(s1, s2, n);
}

static char *_strcat(char *dest, const char *src) {
    return strcat(dest, src);
}

static char *_strncat(char *dest, const char *src, size_t n) {
    return strncat(dest, src, n);
}

static void *_memset(void *s, int c, size_t n) {
    return memset(s, c, n);
}

static void *_memcpy(void *dest, const void *src, size_t n) {
    return memcpy(dest, src, n);
}

static void *_memmove(void *dest, const void *src, size_t n) {
    return memmove(dest, src, n);
}

static int _memcmp(const void *s1, const void *s2, size_t n) {
    return memcmp(s1, s2, n);
}

static OSTRING iface = {
    .len = _strlen,
    .cpy = _strcpy,
    .ncpy = _strncpy,
    .cmp = _strcmp,
    .ncmp = _strncmp,
    .cat = _strcat,
    .ncat = _strncat,
    .memset = _memset,
    .memcpy = _memcpy,
    .memmove = _memmove,
    .memcmp = _memcmp,
};

OSTRING *OSTRINGenable(void) {
    return &iface;
}
