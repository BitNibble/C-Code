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
#include <ostdio.h>
#include <stdlib.h>
#include <ostring.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h> // true, false
#include <math.h>
#include <time.h>
//#include <assert.h>
#include <unistd.h> // chdir 
#include <windows.h>
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
#include "circbuffer.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define STR_SIZE 256

static FUNC func;
FICHEIRO* file;
char str[STR_SIZE];
size_t str_size = STR_SIZE - 1;
char* token[10];
int read_num(void);


int main(int argc, char *argv[]){
file = FICHEIROenable();
(void)file;
strcpy(file->par.filename, "log.txt");
strcpy(file->par.permission, "w");
file->openp();
file->printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
file->close();

func = FUNCenable();
char* cmd = NULL;
int number;
(void)number;
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
	fprintf(stderr, "chdir failed: %s\n", strerror(errno));
else 
{
	strcpy(file->par.permission, "a+");
	strcpy(file->par.filename, "log.txt");
	file->openp();
	number = read_num();
	file->printf("-> %d\n", number);
	file->close();

}
strcpy(file->par.permission, "r");
strcpy(file->par.filename, "cvs.txt");
file->openp();
file->read(str, sizeof(char), str_size);
printf("\nstring:\n %s\n------\n", str);
func.strtotok(str,token,"\n");
printf("\ntoken[0]:\n %s\n------\n", token[0]);
printf("\ntoken[1]:\n %s\n------\n", token[1]);
printf("\ntoken[2]:\n %s\n------\n", token[2]);
printf("\ntoken[3]:\n %s\n------\n", token[3]);
printf("\ntoken[4]:\n %s\n------\n", token[4]);


file->close();


/****************************************************************************************************************************/
/****************************************************************************************************************************/
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
int read_num(void)
{
	char c; int number;
	printf("Enter a Number:\n");
	if(scanf("%d",&number)){
		printf("Number: %d\n", number);
		for(c = getchar() ;c != '\n' && c != EOF; c = getchar()); // clear stdin
	}else{
		perror("scanf");
		for(c = getchar() ;c != '\n' && c != EOF; c = getchar()); // clear stdin
		number=read_num();
	}
	return number;
}

