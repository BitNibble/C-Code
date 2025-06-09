/********************************************************
* Research Environment
* Test_5.c
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
#include <unistd.h> // chdir 
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
FICHEIRO* file;

int main(int argc, char *argv[]){
file = FICHEIROenable();
(void)file;
file->open("log.txt","w");
file->printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
file->close();

func = FUNCenable();
char* cmd = NULL;
/*****************/

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
//							-------TESTING AREA--------
/****************************************************************************************************************************/
if(chdir("../example")) 
	perror("chdir"); 
else 
{
	file->open("test.txt","w"); 
	file->puts("Changed directory.\n"); 
	file->close();
}






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

