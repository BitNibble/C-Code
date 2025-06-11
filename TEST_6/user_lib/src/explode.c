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
#include "explode.h"
#include <inttypes.h>

void EXPLODEupdate(EXPLODE_par* par, unsigned int x);
unsigned int EXPLODEhh(EXPLODE_par* par);
unsigned int EXPLODEll(EXPLODE_par* par);
unsigned int EXPLODElh(EXPLODE_par* par);
unsigned int EXPLODEhl(EXPLODE_par* par);

EXPLODE EXPLODEenable( void )
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	EXPLODE setup; // Dummy Setup
	setup.par.XI = 0;
	setup.par.XF = 0;
	setup.par.HL = 0;
	setup.par.LH = 0;
	setup.par.HH = 0;
	setup.par.LL = 0;
	setup.update = EXPLODEupdate;
	// Control Copy
	return setup;
}
// boot
void EXPLODEupdate(EXPLODE_par* par, unsigned int x)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	par->XI = par->XF;
	par->XF = x;
	par->HL = EXPLODEhl(par);
	par->LH = EXPLODElh(par);
	par->HH = EXPLODEhh(par);
	par->LL = EXPLODEll(par);
}
// hh
unsigned int EXPLODEhh(EXPLODE_par* par)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	return (par->XI & par->XF);
}
// ll
unsigned int EXPLODEll(EXPLODE_par* par)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	return ~(par->XI | par->XF);
}
// lh
unsigned int EXPLODElh(EXPLODE_par* par)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	return ((par->XI ^ par->XF) & par->XF);
}
// hl
unsigned int EXPLODEhl(EXPLODE_par* par)
{
	//printf("%d -> ",__LINE__);
	//printf("%s\n",__func__);
	return ((par->XF ^ par->XI) & par->XI);
}
/***EOF***/
