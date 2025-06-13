/************************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
	Pin Analysis
************************************************************************/
#ifndef _EXPLODE_H_
	#define _EXPLODE_H_

#include <stdint.h>

#define IS_BIT_LH(par, bit) ((par.LH >> (bit)) & 1)
#define IS_BIT_HL(par, bit) ((par.HL >> (bit)) & 1)
#define IS_BIT_LL(par, n)  (((par).LL >> (n)) & 1)
#define IS_BIT_HH(par, n) (((par).HH >> (n)) & 1)


typedef struct {
	unsigned int XI;
	unsigned int XF;
	unsigned int HL;
	unsigned int LH;
	unsigned int HH;
	unsigned int LL;
}EXPLODE_par;

typedef struct explode{
	EXPLODE_par par;
	void (*update)(EXPLODE_par* par, unsigned int x);
}EXPLODE;

EXPLODE EXPLODEenable(void);
#endif
/***EOF***/

