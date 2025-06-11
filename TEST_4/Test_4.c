/********************************************************
* Research Environment
* Test_4.c
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
#include "user_lib\inc\PCfunction.h"
#include "user_lib\inc\PCficheiro.h"
#include "user_lib\inc\explode.h"
#include "user_lib\inc\circbuffer.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef volatile union{
	struct{
		uint8_t b0:1;
		uint8_t b1:1;
		uint8_t b2:1;
		uint8_t b3:1;
		uint8_t b4:1;
		uint8_t b5:1;
		uint8_t b6:1;
		uint8_t b7:1;
	}par;
	uint8_t reg;
} Byte;

typedef struct{
	Byte* A;
	Byte* B;
	Byte* C;
} List;

static FUNC func;

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);

func = FUNCenable();
char* cmd = NULL;
/*****************/
uint8_t vector[100] = {0};

List lst;
lst.A = (Byte*)vector;
lst.B = (Byte*)vector+1;
lst.C = (Byte*)NULL;
Byte *byte = NULL;
byte = (Byte*)vector;
vector[0]=10;
vector[1]=255;

while ass
{
	printf("\nEnter i Data : ");
	cmd=func.fltos(stdin);
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
/****************************************************************************************************************************/


printf("byte->reg: %d\n", byte->reg);
printf("byte->par.b7: %d\n", byte->par.b7);
printf("byte->par.b6: %d\n", byte->par.b6);
printf("byte->par.b5: %d\n", byte->par.b5);
printf("byte->par.b4: %d\n", byte->par.b4);
printf("byte->par.b3: %d\n", byte->par.b3);
printf("byte->par.b2: %d\n", byte->par.b2);
printf("byte->par.b1: %d\n", byte->par.b1);
printf("byte->par.b0: %d\n", byte->par.b0);
printf("\n");
printf("lst->A->reg: %d\n", lst.A->reg);
printf("lst->A->par.b7: %d\n", lst.A->par.b7);
printf("lst->A->par.b6: %d\n", lst.A->par.b6);
printf("lst->A->par.b5: %d\n", lst.A->par.b5);
printf("lst->A->par.b4: %d\n", lst.A->par.b4);
printf("lst->A->par.b3: %d\n", lst.A->par.b3);
printf("lst->A->par.b2: %d\n", lst.A->par.b2);
printf("lst->A->par.b1: %d\n", lst.A->par.b1);
printf("lst->A->par.b0: %d\n", lst.A->par.b0);
printf("\n");
printf("lst->B->reg: %d\n", lst.B->reg);
printf("lst->B->par.b7: %d\n", lst.B->par.b7);
printf("lst->B->par.b6: %d\n", lst.B->par.b6);
printf("lst->B->par.b5: %d\n", lst.B->par.b5);
printf("lst->B->par.b4: %d\n", lst.B->par.b4);
printf("lst->B->par.b3: %d\n", lst.B->par.b3);
printf("lst->B->par.b2: %d\n", lst.B->par.b2);
printf("lst->B->par.b1: %d\n", lst.B->par.b1);
printf("lst->B->par.b0: %d\n", lst.B->par.b0);

//if(&lst == vector) printf("Yes"); else printf("No");

/****************************************************************************************************************************/
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
/***EOF***/

