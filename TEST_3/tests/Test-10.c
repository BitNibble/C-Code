/********************************************************
* Research Environment
* Test.c
* Nome: 
*	sergio santos
* Contacto: 
*	916919898; 
*	sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
* comment: 
*	Explore ideas
* 
*******************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <inttypes.h>
#include <math.h>
#include <inttypes.h>
//#include <assert.h>
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
#include "circbuffer.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define buff_size 4

static FUNC func;
circbuff circ;
/*******************************************************/
unsigned int number;

char string[32];

/*******************************************************/
/*******************************************************/

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);

func = FUNCenable();
circ = CIRCBUFFenable(4, string);
// Prototypes

// Local variables
char c;
char* cmd=NULL;
unsigned int number0;
uint8_t number1;

/*******************************************************/
/*******************************************************/
while ass
{
	printf("\nEnter i Data : ");
	
	cmd=func.fltos(stdin);
	number1=func.getnumv2(cmd);
	
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n"); printf("\trun - r\n"); printf("\tquit - q\n"); printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing
		/**/
		printf( "get :" );		
		cmd=func.fltos(stdin);
		number1=func.getnumv2(cmd);
		if(!strcmp(cmd,"skip") || !strcmp(cmd,"n")){
			printf( "%ud		%ud\n", circ.tail, circ.head );
		}else{
			printf( "%ud\n", circ.get(&circ) );
			printf( "%ud		%ud\n", circ.tail, circ.head );
		}
		
		
		printf( "put :" );		
		cmd=func.fltos(stdin);
		number1=func.getnumv2(cmd);
		if(!strcmp(cmd,"skip") || !strcmp(cmd,"n")){
			printf( "%ud		%ud\n", circ.tail, circ.head );
			continue;
		}else{
			circ.put(&circ, number1);
			printf( "%ud		%ud\n", circ.tail, circ.head );
		}
		/**/
		
		continue;
	}
}
/*******************************************************/
/*******************************************************/
end:
	free(cmd);
	//free(ptr);
	//free(str);
	//system("PAUSE");
	return 0;
/******/
}
/*******************************************************/
/*******************************************************/
/*******************************************************/
/*******************************************************
Numer/ denominator --> N/D
X%X is always equal ZERO.
if numerator < denominator
N%D is always equal to N
Therefore X%X can be used as a flag to detect when N == D when N counts to D.
*******************************************************/
// ~0  (1)  (..)
/*******************************************************/
/***EOF***/

