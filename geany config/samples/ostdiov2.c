/*************************************************************************
Title:    OSTDIO
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: ostdio.c$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
    Singleton implementation wrapping stdio.h functions.
*************************************************************************/
#include "ostdio.h"
#include <stdio.h>

/*** interface ***/
static OSTDIO iface = {
    .fopen = fopen,
    .fclose = fclose,
    .fread = fread,
    .fwrite = fwrite,
    .fflush = fflush,
    .fseek = fseek,
    .ftell = ftell,
    .rewind = rewind,
    .ferror = ferror,
    .clearerr = clearerr,
    .feof = feof,

    .fprintf = fprintf,
    .fscanf = fscanf,

    .printf = printf,
    .scanf = scanf,
    .sprintf = sprintf,
    .snprintf = snprintf,
    .sscanf = sscanf,

    .remove = remove,
    .rename = rename,
    .tmpfile = tmpfile,
    .tmpnam = tmpnam,

    .perror = perror,

    .setvbuf = setvbuf,
    .setbuf = setbuf
};

/*** singleton accessor ***/
OSTDIO *OSTDIOenable(void) {
    return &iface;
}

/*** EOF ***/

