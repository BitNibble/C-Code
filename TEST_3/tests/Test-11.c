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
#define tits (..)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))

#define buff_size 4

static FUNC func;
circbuff circ;
/*******************************************************/
unsigned int number;
struct Example
{
	uint8_t a;
	uint16_t b;
	uint32_t c;
	uint32_t* ptr;
}test;

char string[32];

/*******************************************************/
void STM32446Gpiosetupreg( volatile uint32_t* reg, uint32_t size_block, uint32_t data, uint32_t pin );
void STM32446PinBlock( volatile uint32_t* dest, uint32_t size_block, uint32_t data, uint32_t pin );


/*******************************************************/

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);

func = FUNCenable();
circ = CIRCBUFFenable(4, string);
// Prototypes

test.a=1;
test.b=2;
test.c=3;
test.ptr=&test.c;

// Local variables
char c;
char* cmd=NULL;
uint32_t reg;
uint32_t mask;
unsigned int number0;
uint32_t number1;

/*******************************************************/
/*******************************************************/
while ass
{
	printf("\nEnter i Data : ");
	
	cmd=func.fltos(stdin);
	number0=func.getnumv2(cmd);
	
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n"); printf("\trun - r\n"); printf("\tquit - q\n"); printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing

		reg=1;
		STM32446PinBlock( &reg, 3, 8, 2 );
		printf( "%ud \n", reg );
		STM32446PinBlock( &reg, 2, 2, 1 );
		printf( "%ud \n", reg );

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
void STM32446Gpiosetupreg( volatile uint32_t* reg, uint32_t size_block, uint32_t data, uint32_t pin )
{
	uint32_t mask = (uint32_t)(pow(2, size_block) - 1);
	uint32_t location = pin * size_block;
	data &= mask;
	*reg |= (mask << location);
	*reg &= (data << location) | ~(mask << location);
}

void STM32446PinBlock( volatile uint32_t* dest, uint32_t size_block, uint32_t data, uint32_t pin )
{
	uint32_t mask = (uint32_t)(pow(2, size_block) - 1);
	data &= mask;
	*dest &= ~(mask << pin);
	*dest |= (data << pin);
}



/*******************************************************/
/*******************************************************
Numer / denominator --> N/D
X % X is always equal ZERO.
if numerator < denominator
N % D is always equal to N
Therefore X % X can be used as a flag to detect when N == D when N counts to D.
*******************************************************/
// ~0  (1)  (..)
/*******************************************************/
/***EOF***/

