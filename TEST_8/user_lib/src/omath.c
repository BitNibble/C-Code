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
	
static omath_t _handler = {0};

void omath_enable(void)
{
    _handler.sin = sin;
    _handler.cos = cos;
    _handler.tan = tan;
    _handler.asin = asin;
    _handler.acos = acos;
    _handler.atan = atan;
    _handler.atan2 = atan2;
    _handler.sqrt = sqrt;
    _handler.pow = pow;
    _handler.exp = exp;
    _handler.log = log;
    _handler.log10 = log10;
    _handler.fabs = fabs;
    _handler.floor = floor;
    _handler.ceil = ceil;
    _handler.round = round;
    _handler.fmod = fmod;
}

omath_t* omath(){ return &_handler; }
