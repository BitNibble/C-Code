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
#define sperm ~0
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
		printf("Possible commands:\n");
		printf("\trun - r\n");
		printf("\tquit - q\n");
		printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing
		
	printf("%ud  %ud  %ud\n", (uint32_t) sperm, (uint16_t) sperm, (uint8_t) sperm);
	


	
	AFR[0] = 0; AFR[1] = 0; AFR[2] = 0; AFR[3] = 0;
	STM32446GpioAafr( 4, (uint8_t)1, 1 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);
	


	//AFR[0] = 0; AFR[1] = 0; AFR[2] = 0; AFR[3] = 0;
	STM32446GpioAafr( 4, 1, 1 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);

	
	//AFR[0] = 0; AFR[1] = 0; AFR[2] = 0; AFR[3] = 0;
	STM32446GpioAafr( 4, 7, 9 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);

	STM32446GpioAafr( 4, 7, 3 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);

	STM32446GpioAafr( 4, 7, 15 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);

	STM32446GpioAafr( 4, 15, 19 );
	printf("%ud  %ud  %ud\n", (uint32_t) AFR[0], (uint32_t) AFR[1], (uint32_t) AFR[2]);
	
	
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
void STM32446GpioAafr( const unsigned int size_block, unsigned int data, unsigned int block_n )
{
	const unsigned int n_bits = sizeof(data) * 8;
	const unsigned int mask = (unsigned int) (pow(2, size_block) - 1);
	unsigned int index = (block_n * size_block) / n_bits;
	printf( "size_block - %ud, n_bits - %ud, mask - %ud, index - %ud\n\n",  size_block, n_bits, mask, index );
	data &= mask;
	AFR[index] &= ~( mask << ((block_n * size_block) - (index * n_bits)) );
	AFR[index] |= ( data << ((block_n * size_block) - (index * n_bits)) );
	AFR[index] &= (unsigned int) sperm;
}
/*******************************************************/
// ~0  (1)  (..)
/*******************************************************/
/***EOF***/

