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
/***Library***/
/***Constant & Macro***/
/***Global Variable***/
struct expld{
	/***Variable***/
	unsigned int XI;
	unsigned int XF;
	unsigned int HL;
	unsigned int LH;
	unsigned int HH;
	unsigned int LL;
	/***PROTOTYPES VTABLE***/
	void (*update)(struct expld* self, unsigned int x);
	unsigned int (*mayia)(struct expld* self, unsigned int nbits);
	struct expld (*read)(struct expld* self);
};
struct expld_base{
	struct expld obj;
	struct expld* ptr;
};
typedef struct expld EXPLODE;
/***Header***/
EXPLODE EXPLODEenable(void);
#endif
/***Comment***
*************/
/***EOF***/
