/**********************************************************************
* Research Environment
* Test_7.c
* Nome: 
*	sergio santos
* Contacto: 
*	916919898; 
*	sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
* comment: 
*	Explore ideas
* 
***********************************************************************/
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
char SEQ[STR_SIZE]={0};
char LOG[STR_SIZE]={0};
char logic[SUBSTR_SIZE]={0};
char feedback[SUBSTR_SIZE]={0};
const size_t str_size = STR_SIZE - 1;
const size_t substr_size = SUBSTR_SIZE - 1;
char* token[4];
void rmcrnl(char* str);

int main(void) {
	file = FICHEIROenable();
	(void)file;
	func = FUNCenable();
	char* cmd = NULL;
	int number;
	(void)number;
	strcpy(feedback, "zero");
	/*****************/
	strcpy(file->par.permission, "r");
	strcpy(file->par.filename, "lfsm.txt");
	if(chdir("../example")) 
		fprintf(stderr, "chdir failed: %s\n", strerror(errno));
	printf("\n------------------\nProgram START\n------------------\n");
	while ass {
		file->openp();
		printf("\n Entry : ");
		cmd=func.fltos(stdin);
		memset(logic, 0, SUBSTR_SIZE);
		while(file->fgets(str, str_size)) {
			rmcrnl(str);
			//printf("file: %s\n", str);
			func.strtotok(str,token,"=");
			//printf("\ttoken[0]:%s\n", token[0]);
			if(token[0]){
				if(snprintf(LOG, str_size, "log+%s", cmd) > 0) {
					//printf("\tlogic: %s\n", LOG);
					if(!strcmp(LOG, token[0])){
						strcpy(logic, token[1]);
						//printf("LOG-out: ----> %s\n", logic); 
					}
					if(snprintf(SEQ, str_size, "seq*%s+%s", feedback, cmd) > 0) {
						//printf("\tsequence: %s\n", SEQ);
						if(!strcmp(SEQ, token[0])){
							strcpy(feedback, token[1]);
							//printf("SEQ-out ----> %s\n", feedback); 
							break;
						}
					}
				}
			}else {
				//printf("Skip Token\n");
			}
		}
		if (feof(file->filepointer())) {
			   //printf("End of file reached.\n");
		}
		file->close();

		if(!strcmp(cmd,"restart") || !strcmp(cmd,"r")) {
			strcpy(feedback, "zero");
		}
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")) {
			printf("Exiting Program\n");
			goto end;
		}
		if(!strcmp(cmd,"help") || !strcmp(cmd,"h")) {
			printf("Possible commands:\n"); 
			printf("\trestart - r\n"); 
			printf("\tquit - q\n"); 
			printf("\thelp - h\n");
			continue;
		}
		/**************************************************************/
		//				-------TESTING AREA--------
		/**************************************************************/
		if(!strcmp(logic,"restart")) {
			strcpy(feedback, "zero");
		}
		/***/












		/**************************************************************/
		/**************************************************************/
		printf("\n-------------\n LOG-OUT: %s\n-------------", logic);
		printf("\n-------------\n SEQ-OUT: %s\n-------------\n", feedback);
	}
/**********************************************************************/
/**********************************************************************/
end:
	free(cmd);
	printf("\n------------------\nProgram END\n------------------\n");
	return 0;
}
/**********************************************************************/
void rmcrnl(char* str)
{
	int i; int stop;
	for(i=strlen(str), stop=i-3; i > stop ; i--) {
		if(*(str+i) == '\r' || *(str+i) == '\n') {
			*(str+i)='\0';
		}
	}
}
/***EOF***/

