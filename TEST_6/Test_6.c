/********************************************************
* Research Environment
* Test_6.c
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
#include <stdbool.h> // true, false
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
#define STR_SIZE 512
#define SUBSTR_SIZE 64

static FUNC func;
FICHEIRO* file;
char str[STR_SIZE]={0};
char substr[SUBSTR_SIZE]={0};
char entry[STR_SIZE]={0};
char feedback[SUBSTR_SIZE]={0};
const size_t str_size = STR_SIZE - 1;
const size_t substr_size = SUBSTR_SIZE - 1;
char* token[10];
char* subtoken[10];
int read_num(void);
int i;


int main(void){
file = FICHEIROenable();
(void)file;
func = FUNCenable();
char* cmd = NULL;
int number;
(void)number;
strcpy(feedback,"zero");
/*****************/
strcpy(file->par.permission, "r");
strcpy(file->par.filename, "lfsm.txt");
if(chdir("../example")) 
	fprintf(stderr, "chdir failed: %s\n", strerror(errno));

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


file->openp();	

printf("Entry : ");
cmd=func.fltos(stdin);

while(file->fgets(str, str_size)) {
	for(i=0;*(str+i);i++) if(*(str+i) == '\n') *(str+i)='\0';
	printf("file:%s\n", str);

	func.strtotok(str,token,"=");
	printf("token[0]:%s\n", token[0]);
	if(token[0]){
		strcpy(substr,token[0]);
		if(snprintf(entry, str_size, "Columns*%s+%s", feedback, cmd) > 0) {
			printf("entry:%s\n", entry);
			if(!strcmp(entry, substr)){ strcpy(feedback, token[1]); printf("OUT: %s\n-------\n", feedback); break;}
		}
	}else{printf("Skip Token.\n");}
}

if (feof(file->filepointer())) {
       printf("End of file reached.\n");
}

file->close();

printf("\n-------------\n OUT: %s.\n-------------\n", feedback);

if(!strcmp(cmd,"restart")) strcpy(feedback,"zero");

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

