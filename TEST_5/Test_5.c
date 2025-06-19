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
#include <ostdlib.h>
#include <ostring.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h> // true, false
#include <math.h>
#include <time.h>
//#include <assert.h>
#include <unistd.h> // chdir 
//#include <windows.h>
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
OSTRING* string;
OSTDIO* stdio;
OSTDLIB* stdlib;
FICHEIRO* file;
char str[STR_SIZE];
size_t str_size = STR_SIZE - 1;
char* token[10];
int read_num(void);

void func1(void);

void proc_link(void (*ptr) ()){
	if(ptr)
		(*ptr)();
}

int main(int argc, char *argv[]){
file = FICHEIROenable();
(void)file;
string = OSTRINGenable();
stdio = OSTDIOenable();
stdlib = OSTDLIBenable();
string->cpy(file->par.filename, "log.txt");
string->cpy(file->par.permission, "w");
file->openp();
file->printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
file->close();

func = FUNCenable();
char* cmd = NULL;
int number = 0;
(void)number;
/*****************/
void (*link)(void);
link=func1;

while ass
{
	stdio->printf("\nEnter i Data : ");
	cmd=func.fltos(stdin);
	if(!string->cmp(cmd,"quit") || !string->cmp(cmd,"q")){
		goto end;
	}
	if(!string->cmp(cmd,"help") || !string->cmp(cmd,"h")){
		stdio->printf("Possible commands:\n"); stdio->printf("\trun - r\n"); stdio->printf("\tquit - q\n"); stdio->printf("\thelp - h\n");
		continue;
	}
	// RUN TESTING CONDITION:
	if( !string->cmp(cmd,"run") || !string->cmp(cmd,"r") ){  // one shot testing
/****************************************************************************************************************************/
//							-------TESTING AREA--------
/****************************************************************************************************************************/

if(chdir("../example")) 
	stdio->fprintf(stderr, "chdir failed: %d\n", errno);
else 
{
	string->cpy(file->par.permission, "a+");
	string->cpy(file->par.filename, "log.txt");
	file->openp();
	number = read_num();
	file->printf("-> %d\n", number);
	file->close();

}
string->cpy(file->par.permission, "r");
string->cpy(file->par.filename, "cvs.txt");
file->openp();
file->read(str, sizeof(char), str_size);
stdio->printf("\nstring:\n %s\n------\n", str);
func.strtotok(str,token,"\n");
stdio->printf("\ntoken[0]:\n %s\n------\n", token[0]);
stdio->printf("\ntoken[1]:\n %s\n------\n", token[1]);
stdio->printf("\ntoken[2]:\n %s\n------\n", token[2]);
stdio->printf("\ntoken[3]:\n %s\n------\n", token[3]);
stdio->printf("\ntoken[4]:\n %s\n------\n", token[4]);

//if(number > 100){
	proc_link(&func1);
	proc_link(NULL);
	link();
//}

file->close();

/****************************************************************************************************************************/
/****************************************************************************************************************************/
	}
}
/*******************************************************/
/*******************************************************/
end:
	stdlib->free(cmd);
	return 0;
}
/****************************************************************************************************************************/
/***EOF***/
int read_num(void)
{
	char c; int number;
	stdio->printf("Enter a Number:\n");
	if(stdio->scanf("%d",&number)){
		stdio->printf("Number: %d\n", number);
		for(c = stdio->getchar() ;c != '\n' && c != EOF; c = stdio->getchar()); // clear stdin
	}else{
		stdio->perror("scanf");
		for(c = stdio->getchar() ;c != '\n' && c != EOF; c = stdio->getchar()); // clear stdin
		number=read_num();
	}
	return number;
}

void func1(void)
{
	stdio->printf("Hello world");
}

