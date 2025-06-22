/*************************************************************************
Title:    OMATH
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: omath.h$
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
*************************************************************************/
#ifndef OMATH_H
	#define OMATH_H
	
#include <stdlib.h>

typedef struct {
    double (*sin)(double x);
    double (*cos)(double x);
    double (*tan)(double x);
    double (*asin)(double x);
    double (*acos)(double x);
    double (*atan)(double x);
    double (*atan2)(double y, double x);
    double (*sqrt)(double x);
    double (*pow)(double base, double exp);
    double (*exp)(double x);
    double (*log)(double x);
    double (*log10)(double x);
    double (*fabs)(double x);
    double (*floor)(double x);
    double (*ceil)(double x);
    double (*round)(double x);
    double (*fmod)(double x, double y);
} omath_t;

void omath_enable(void);
omath_t* omath();

#endif // OMATH_H
