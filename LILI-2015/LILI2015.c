/*:
* Research
* LILI2015.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 12-08-2015 14:00
* 
* reviewed: 16122021
*
*/
/*
*** Library
*/
// fopen perror fread fwrite feof fseek ferror fclose rewind scanf sscanf getchar scanf fscanf
#include <stdio.h>
// calloc free realloc malloc
#include <stdlib.h>
// strcpy strcmp strcat memcmp
#include <string.h>
// termios tcflush
//#include <termios.h>
// nanosleep sleep
#include <time.h>
// tcflsuh read write close
//#include <unistd.h>
// perror
#include <errno.h>
// open
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
/*
** Personal library
*/
#include"user_lib\inc\PClili.h"
#include"user_lib\inc\PCfunction.h"
/*
*** Definition and Macros
*/
#define TRUE 1
/*
*** GLOBAL VARIABLES
*/
/***
*** Procedure and Function
*/
void* this(void* address);
/*
*** Main Algorithm
*/
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
(void)argc;
(void)argv;
/*
** Capture parameters
*/
	//printf("Running program - %s with - %d parameter\n",argv[0], argc);
/*
*** Local variables
*/
//char vector[256];
char* cmd=NULL;
LILI l=LILIenable();
FUNC func=FUNCenable();

/***
l.target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
//l.target->data="ola";
strcpy(l.target->vector,"ola");
//strcpy(vector,"ola");
printf("testing -> %s\n", l.target->vector);
//printf("testing -> %s\n", vector);
free(l.target);
***/

/*
*** CYCLE ROUTINES
*/
while(TRUE){
	printf("->->	write string:\n");
	cmd=func.fltos(stdin);
	//func.fltosv(stdin, cmd); // does not work why ??
	if(!strcmp(cmd,"quit")){
		goto end;
	}	
	if(!strcmp(cmd,"play") || !strcmp(cmd,"p")){
		printf("data:\n%s\n", l.play(&l).vector);
	}
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Available commands:\n 1-quit\n 2-play\n 3-help\n 4-forward\n 5-reverse\n 6-record\n 7-remove\n 8-quant\n 9-status\n 10-replace\n 11-push\n 12-pop\n 13-non\n 14-free\n\n");
		printf("This program is a simple linked list testing sample\n");
	}
	if(!strcmp(cmd,"forward") || !strcmp(cmd,"f")){
		l.forward(&l);
		printf("data:\n%s\n", l.play(&l).vector);
	}
	if(!strcmp(cmd,"reverse") || !strcmp(cmd,"r")){
		l.reverse(&l);
		printf("data:\n%s\n", l.play(&l).vector);
	}
	if(!strcmp(cmd,"record") || !strcmp(cmd,"rec")){
		printf("enter input to record\n");
		cmd=func.fltos(stdin);
		//func.fltosv(stdin, cmd); // does not work why ??
		l.record(&l, cmd);
	}
	if(!strcmp(cmd,"remove") || !strcmp(cmd,"rm")){
		l.remove(&l);
		printf("data:\n%s\n", l.play(&l).vector);
	}
	if(!strcmp(cmd,"free")){
		l.free(&l);
	}
	if(!strcmp(cmd,"quant") || !strcmp(cmd,"qt")){
		printf("N:\n%u\n",l.quant(&l));
	}
	if(!strcmp(cmd,"replace") || !strcmp(cmd,"subs")){
		printf("enter input to substitute\n");			
		cmd=func.fltos(stdin);
		l.replace(&l, cmd);
	}
	if(!strcmp(cmd,"push")){
		printf("enter input to push to list\n");			
		cmd=func.fltos(stdin);
		l.push(&l, cmd);
	}
	if(!strcmp(cmd,"pop")){
		printf("data:\n%s\n", l.pop(&l).vector);
	}
	if(!strcmp(cmd,"non")){
	}
}
	end:
		free(cmd);
		l.free(&l);
		//system("PAUSE");
		return 0;
/****/
}
/*
*** Function and procedure
*/
void* this(void* address){
	return address;
}
/*
*** Interrupt requestes
*/
/***EOF***/
