/*************************************************************************
Title:    OSTDLIB
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdlib.c$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    Singleton implementation wrapping stdlib.h functions.
*************************************************************************/
#include "ostdlib.h"
#include <stdlib.h>

static OSTDLIB iface = {0};

void ostdlib_enable(void)
{
/*** interface ***/
    iface.malloc = malloc;
    iface.calloc = calloc;
    iface.realloc = realloc;
    iface.free = free;

    iface.atoi = atoi;
    iface.atol = atol;
    iface.atoll = atoll;
    iface.atof = atof;

    iface.strtol = strtol;
    iface.strtoul = strtoul;
    iface.strtoll = strtoll;
    iface.strtoull = strtoull;

    iface.abs = abs;
    iface.labs = labs;
    iface.llabs = llabs;

//    iface.div = div;
//    iface.ldiv = ldiv;
//    iface.lldiv = lldiv;

//    iface.rand = rand;
//    iface.srand = srand;

    iface.exit = exit;
//    iface.abort = abort;
//    iface.atexit = atexit;
//    iface.system = system;

//    iface.bsearch = bsearch;
//    iface.qsort = qsort;

//    iface.getenv = getenv;
}

/*** singleton accessor ***/
OSTDLIB *ostdlib(void) {
    return &iface;
}

/*** EOF ***/

