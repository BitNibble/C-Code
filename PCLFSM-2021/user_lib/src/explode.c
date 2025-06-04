/********************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
    Pin Analysis
********************************************************************/
/***Library***/
#include <inttypes.h>
#include"..\inc\explode.h"
/***Constant & Macro***/
#ifndef ZERO
	#define ZERO 0
	#define ONE 1
#endif
/***Global File Variable***/
/***Header***/
unsigned int EXPLODEPwr(unsigned int bs, unsigned int n);
/************/
void EXPLODEupdate(EXPLODE* self, unsigned int x);
unsigned int EXPLODEmayia(EXPLODE* self, unsigned int nbits);
unsigned int EXPLODEhh(EXPLODE* self);
unsigned int EXPLODEll(EXPLODE* self);
unsigned int EXPLODElh(EXPLODE* self);
unsigned int EXPLODEhl(EXPLODE* self);
struct expld EXPLODEread(struct expld* self);
/***Procedure & Function***/
EXPLODE EXPLODEenable( void )
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	// OBJECT STRUCT
	struct expld explode;
	// inic VAR
	explode.XI = ZERO;
	explode.XF = ZERO;
	explode.HL = ZERO;
	explode.LH = ZERO;
	explode.HH = ZERO;
	explode.LL = ZERO;
	// function pointers
	explode.update = EXPLODEupdate;
	explode.mayia = EXPLODEmayia;
	explode.read = EXPLODEread;
	/******/
	return explode; //return copy
}
// boot
void EXPLODEupdate(EXPLODE* self, unsigned int x)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	self->XI = self->XF;
	self->XF = x;
	self->HL = EXPLODEhl(self);
	self->LH = EXPLODElh(self);
	self->HH = EXPLODEhh(self);
	self->LL = EXPLODEll(self);
}
// mayia
unsigned int EXPLODEmayia(EXPLODE* self, unsigned int nbits)
{//magic formula
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int mask = 0;
	unsigned int diff = 0;
	unsigned int trans = 0;
	mask = EXPLODEPwr(2,nbits)-ONE;
	self->XI &= mask;
	self->XF &= mask;
	diff = self->XF ^ self->XI;
	trans = diff & self->XF;
	return (trans << nbits) | diff;
}
// hh
unsigned int EXPLODEhh(EXPLODE* self)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int i = 0;
	i = self->XI & self->XF;
	return i;
}
// ll
unsigned int EXPLODEll(EXPLODE* self)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int i = 0;
	i = self->XI | self->XF;
	return ~i;
}
// lh
unsigned int EXPLODElh(EXPLODE* self)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int i = 0;
	i = self->XI ^ self->XF;
	i &= self->XF;
	return i;
}
// hl
unsigned int EXPLODEhl(EXPLODE* self)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int i = 0;
	i = self->XF ^ self->XI;
	i &= self->XI;
	return i;
}
struct expld EXPLODEread(struct expld* self)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	return *self; // return a copy
}
/*******************************************************************/
// power: raise base to n-th power; n >= 0
unsigned int EXPLODEPwr(unsigned int bs, unsigned int n)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	unsigned int i = 0, p = 0;
	p = ONE;
	for (i = ONE; i <= n; ++i)
	p = p * bs;
	return p;
}
/***Interrupt***/
/***Comment***
*************/
/***EOF***/
