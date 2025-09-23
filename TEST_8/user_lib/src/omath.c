/*************************************************************************
Title:    OMATH
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: omath.c$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
*************************************************************************/
#include "omath.h"
	#include <math.h>
	
static omath_t handler = {
    .sin = sin,
    .cos = cos,
    .tan = tan,
    .asin = asin,
    .acos = acos,
    .atan = atan,
    .atan2 = atan2,
    .sqrt = sqrt,
    .pow = pow,
    .exp = exp,
    .log = log,
    .log10 = log10,
    .fabs = fabs,
    .floor = floor,
    .ceil = ceil,
    .round = round,
    .fmod = fmod
};

omath_t* omath(){ return &handler; }
