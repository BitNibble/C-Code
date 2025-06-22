/********************************************************
* Research Environment
* Test_1.c
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
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
//#include <assert.h>
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
#include "circbuffer.h"
/***Definition and Macros***/
#define wala ~0
#define yey (1)
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

int test_int0 = 0;
int test_int1 = 0;
int test_int2 = 0;
int test_int3 = 0;

unsigned int test_uint0 = 0;
unsigned int test_uint1 = 0;
unsigned int test_uint2 = 0;
unsigned int test_uint3 = 0;

/*******************************************************/
void STM32446Gpiosetupreg( volatile uint32_t* reg, uint32_t size_block, uint32_t data, uint32_t pin );
void STM32446PinBlock( volatile uint32_t* dest, uint32_t size_block, uint32_t data, uint32_t pin );

/*******************************************************/

const char s[] = "+IPD,99,6:message";

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);

char test_str0[32] = {0};
char test_str1[32] = {0};
char test_str2[32] = {0};
char test_str3[32] = {0};

func = FUNCenable();
circ = CIRCBUFFenable(4, string);
// Prototypes
test.a=1;
test.b=2;
test.c=3;
test.ptr=&test.c;
// Local variables
//char c = '\0';
char* cmd=NULL;
uint32_t reg = 0;
(void)reg;
//uint32_t mask = 0;
unsigned int number0 = 0;
(void)number0;
//uint32_t number1 = 0;
//

/*******************************************************/
	//const char s[] = "+IPD,99,6:message";
    //char s1[0xff] = {0};
	//char s2[0xff] = {0};
    //int d = 0;
	//int e = 0;
    //sscanf(s, "%[^,],%d,%d:%s", s1, &d, &e, s2);
    //printf("here: %s  ,  %d , %d : %s\n", s1, d, e, s2);

	sscanf(s, "%[^,],%d,%d:%s", test_str0, &test_int0, &test_int1, test_str1);
    //printf("here: %s  ,  %d , %d : %s\n", test_str0, test_int0, test_int1, test_str1);

	//sscanf(s, "%[+A-Z],%d,%d:%s", test_str0, &test_int0, &test_int1, test_str1);
	printf("here: %s  ,  %d , %d : %s\n", test_str0, test_int0, test_int1, test_str1);


/*******************************************************/
while yey
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
		//STM32446PinBlock( &reg, 3, 8, 2 );
		//printf( "%ud \n", reg );
		//STM32446PinBlock( &reg, 2, 2, 1 );
		//printf( "s1: %s \n", s1 );
		//printf( "d: %d \n", d );
		//printf( "e: %d \n", e );
		//printf( "s2: %s \n", s2 );

		printf( "str0: %s \n", test_str0 );
		printf( "str1: %s \n", test_str1 );
		printf( "str2: %s \n", test_str2 );
		printf( "str3: %s \n", test_str3 );

		printf( "num0: %d \n", test_int0 );
		printf( "num1: %d \n", test_int1 );
		printf( "num2: %d \n", test_int2 );
		printf( "num3: %d \n", test_int3 );

		printf( "num0: %d \n", test_uint0 );
		printf( "num1: %d \n", test_uint1 );
		printf( "num2: %d \n", test_uint2 );
		printf( "num3: %d \n", test_uint3 );

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
	uint32_t mask = (uint32_t)(1 << size_block) - 1;
	uint32_t location = pin * size_block;
	data &= mask;
	*reg |= (mask << location);
	*reg &= (data << location) | ~(mask << location);
}

void STM32446PinBlock( volatile uint32_t* dest, uint32_t size_block, uint32_t data, uint32_t pin )
{
	uint32_t mask = (uint32_t)(1 << size_block) - 1;
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

