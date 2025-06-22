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

/*** interface ***/
static OSTDLIB iface = {
    .malloc = malloc,
    .calloc = calloc,
    .realloc = realloc,
    .free = free,

    .atoi = atoi,
    .atol = atol,
    .atoll = atoll,
    .atof = atof,

    .strtol = strtol,
    .strtoul = strtoul,
    .strtoll = strtoll,
    .strtoull = strtoull,

    .abs = abs,
    .labs = labs,
    .llabs = llabs,

//    .div = div,
//    .ldiv = ldiv,
//    .lldiv = lldiv,

//    .rand = rand,
//    .srand = srand,

    .exit = exit,
//    .abort = abort,
//    .atexit = atexit,
//    .system = system,

//    .bsearch = bsearch,
//    .qsort = qsort,

//    .getenv = getenv
};

/*** singleton accessor ***/
OSTDLIB *ostdlib(void) {
    return &iface;
}

/*** EOF ***/

