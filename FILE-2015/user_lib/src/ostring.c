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

static OSTRING iface = {
    .len = strlen,
    .cpy = strcpy,
    .ncpy = strncpy,
    .cmp = strcmp,
    .ncmp = strncmp,
    .cat = strcat,
    .ncat = strncat,
    .memset = memset,
    .memcpy = memcpy,
    .memmove = memmove,
    .memcmp = memcmp,
};

OSTRING *OSTRINGenable(void) {
    return &iface;
}
/***EOF***/

