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
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
/***Definition and Macros***/
#define ZERO 0
#define ONE 1
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
static FUNC func;
/*******************************************************/
unsigned int RCC_CR;

/*******************************************************/

int main(int argc, char *argv[]){
RCC_CR = 2;	
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
func = FUNCenable();

// Prototypes
void enable(unsigned int clock);

// Local variables
char c;
char* cmd=NULL;
unsigned int number0;
unsigned int number1;

/*******************************************************/
/*******************************************************/
while(ONE)
{
	printf("\nEnter i Data : ");
	
	cmd=func.fltos(stdin);
	number1=func.getnumv2(cmd);
	
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n");
		printf("\trun - r\n");
		printf("\tquit - q\n");
		printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing
		
		enable(20);



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
void enable(unsigned int clock)
{
	unsigned int count;
	unsigned int set;
	unsigned int rdy;
	for( count = 0, set = 1, rdy = 1;  rdy && count < 10; count++ ){
		if(clock == 0){
			if( set ){ RCC_CR |= ( 1 << 0); set = 0; }else{ if( RCC_CR & ( 1 << 1) ) rdy = 0; }
		}
		else if(clock == 1){
			if( set ){ RCC_CR |= ( 1 << 16); set = 0; }else{ if( RCC_CR & ( 1 << 17) ) rdy = 0; }
		}
		else if(clock == 2){
			if( set ) RCC_CR |= ( 1 << 18 );
			clock = 0;
		}
		else clock = 0; // default
		printf("count - %d ' set - %d ' rdy - %d ' RCC_CR - %d clock - %d \n", count, set, rdy, RCC_CR, clock );
	}	
}

/*******************************************************/

/***EOF***/

