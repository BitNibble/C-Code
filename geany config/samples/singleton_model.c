/*************************************************************************
Title:    SINGLETON_MODEL
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: singleton_model.c$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    
*************************************************************************/
#include "singleton_model.h"
#include <string.h>  // For memcpy or strcpy

/*** function prototypes ***/
static int _read(char *buf, unsigned int len);
static void _close(void);

/*** interface ***/
static MODULE iface = {
    .par = {
        .fd = -1,
        .step = 0,
        .buffer = {0}  // initialize buffer to zeros
    },
    .read = _read,
    .close = _close
};

/*** function definitions ***/
static int _read(char *buf, unsigned int len) {
    (void)buf;
    (void)len;
    return 0;
}

static void _close(void) {
    // No operation
}

/*** singleton accessor ***/
MODULE *MODULEenable(void) {
    return &iface;
}

/*** EOF ***/

