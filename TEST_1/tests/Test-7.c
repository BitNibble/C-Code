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
#include <assert.h>
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
static FUNC func;
/*******************************************************/
unsigned int number;
unsigned int AFR[20];
/*******************************************************/
void STM32446GpioAafr( unsigned int size_block, unsigned int data, unsigned int block_n );
/*******************************************************/
int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
func = FUNCenable();

// Prototypes

// Local variables
char c;
char* cmd=NULL;
unsigned int number0;
unsigned int number1;

/*******************************************************/
/*******************************************************/
while(1)
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
		
	printf("%ud  %ud  %ud\n", (uint32_t) sperm, (uint16_t) sperm, (uint8_t) sperm);
		
	AFR[0] = 0; AFR[1] = 0; AFR[2] = 0; AFR[3] = 0;
	printf("%ud  %ud  %ud  %ud  %ud  %ud\n", 1%6, 2%6, 3%6,4%6,5%6,6%6);
	printf("%ud  %ud  %ud  %ud  %ud  %ud\n", 1/6, 2/6, 3/6,4/6,5/6,6/6);
	printf("%ud  %ud  %ud\n", 3%2, 7%6, 9%9);
	
	
	
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

