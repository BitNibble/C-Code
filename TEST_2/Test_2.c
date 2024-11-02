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
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>
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

static FUNC func;

void delay(int number_of_seconds);

static unsigned int func_id = 2;
static unsigned int test_counter = 3;
void func_test_1(unsigned int next);
void func_test_2(unsigned int next);
void func_test_3(unsigned int next);
void func_test_4(unsigned int next);

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
func = FUNCenable();
char* cmd;
unsigned int choice;
/*****************/

while ass
{
	printf("\nEnter i Data : ");
	
	cmd=func.fltos(stdin);
	choice = func.getnumv2(cmd);
	
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n"); printf("\trun - r\n"); printf("\tquit - q\n"); printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing
/****************************************************************************************************************************/

for(uint8_t i = 100; i; i--){ //delay(1);

func_test_1(3);

func_test_2(4);

func_test_3(2);

func_test_4(1);

}

/****************************************************************************************************************************/
		continue;
	}
}

/*******************************************************/
/*******************************************************/

end:
	free(cmd);
	return 0;
}
/****************************************************************************************************************************/

void func_test_1(unsigned int next){
	unsigned int id = 1; 
	if(id == func_id){
			printf("function %d - %d\n", test_counter, id);
		if(test_counter){test_counter--;}else{test_counter=3;func_id=next;}
	} 
}

void func_test_2(unsigned int next){
	unsigned int id = 2; 
	if(id == func_id){
			printf("function %d - %d\n", test_counter, id);
		if(test_counter){test_counter--;}else{test_counter=3;func_id=next;}
	} 
}

void func_test_3(unsigned int next){
	unsigned int id = 3; 
	if(id == func_id){
			printf("function %d - %d\n", test_counter, id);
		if(test_counter){test_counter--;}else{test_counter=3;func_id=next;}
	} 
}

void func_test_4(unsigned int next){
	unsigned int id = 4; 
	if(id == func_id){
			printf("function %d - %d\n", test_counter, id);
		if(test_counter){test_counter--;}else{test_counter=3;func_id=next;}
	} 
}

void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}

/***EOF***/

