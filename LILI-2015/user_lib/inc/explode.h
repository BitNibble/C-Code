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

typedef struct {
	unsigned int XI;
	unsigned int XF;
	unsigned int HL;
	unsigned int LH;
	unsigned int HH;
	unsigned int LL;
}EXPLODE_par;

typedef struct {
	EXPLODE_par par;
	void (*update)(EXPLODE_par* par, unsigned int x);
}EXPLODE;

EXPLODE EXPLODEenable(void);
#endif
/***EOF***/
