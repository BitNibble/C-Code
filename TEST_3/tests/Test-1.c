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
//uint8_t pin[16];
unsigned int reg;

void setpins( uint8_t n_pin, ... );
void resetpins( int n_pin, ... );
unsigned int setup(unsigned int blocksize, unsigned int data, unsigned int pin);
/*******************************************************/
/*******************************************************/

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);

func = FUNCenable();

// Local variables
char c;
char* cmd=NULL;
unsigned int state;
int n;
double x;
double m;
unsigned int number0;
unsigned int number1;
unsigned int number2;
unsigned int number3;
unsigned int index;
unsigned int i;
char* sample = "ola mundo";
char* token[32];
char* str=NULL;
char tmp[256];
reg=0;

double y, fracpart, intpart;
/*******************************************************/
/*******************************************************/
while(ONE)
{

	m = 0.500;
	// x = 104.1785;
	x = (double) 16000000 / ( 16 * 9600 );


   	fracpart = modf(x, &intpart);

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
		
		
		printf(" reg -> %ld \n", setup(4, 1, 15));



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
/**/
void setpins( uint8_t n_pin, ... )
{
	uint8_t i;
	unsigned int pin = 0;

	va_list list;
	va_start(list, n_pin);
	for(i = 0; i < n_pin; i++){
		pin |= (1 << va_arg(list, int));
	}
	va_end(list);
	printf("%d\n", pin);
}

void resetpins( int n_pin, ... )
{
	uint8_t i;
	unsigned int pin = 0;
	
	if(n_pin > 0 && n_pin < 33){ // Filter input
		va_list list;
		va_start(list, n_pin);
		for(i = 0; i < n_pin; i++){
			pin |= (unsigned int)((1 << va_arg(list, int)) << 16);
		}
		va_end(list);
		printf("%d\n", pin);
	}
}
/**/
unsigned int setup(unsigned int blocksize, unsigned int data, unsigned int pin)
{
	unsigned int mask = (unsigned int)(pow(2, blocksize) - 1);
	data &= mask;
	reg &= ~(mask << (pin * blocksize));
	reg |= (data << (pin * blocksize));
	reg &= 0xFFFFFFFF;
	return reg;
}
/**/
/***EOF***/

