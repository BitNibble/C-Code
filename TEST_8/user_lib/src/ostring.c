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

static OSTRING iface = {0};

void ostring_enable(void)
{
    iface.len = strlen;
    iface.cpy = strcpy;
    iface.ncpy = strncpy;
    iface.cmp = strcmp;
    iface.ncmp = strncmp;
    iface.cat = strcat;
    iface.ncat = strncat;
    iface.memset = memset;
    iface.memcpy = memcpy;
    iface.memmove = memmove;
    iface.memcmp = memcmp;
}

OSTRING *ostring(void) {
    return &iface;
}
/***EOF***/

