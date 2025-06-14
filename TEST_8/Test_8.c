/**********************************************************************
* Research Environment
* Test_8.c
* Nome: 
*	sergio santos
* Contacto: 
*	916919898; 
*	sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
* comment: 
*	file pointer learning finite state machine
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
#include <errno.h>
#include <signal.h>
//#include <assert.h>
#ifdef _WIN32
	#include <process.h> // _spawnl	
#endif
#include <unistd.h>  // fork, chdir
#include "PCficheiro.h"
#include "PCfunction.h"
#include "explode.h"
#include "circbuffer.h"
#include "poop.h"
#include "procedures.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define STR_SIZE 512
#define SUBSTR_SIZE 64

static FUNC func;
FICHEIRO* file;
char logic[SUBSTR_SIZE]={0};
char feedback[SUBSTR_SIZE]={0};
char* cmd = NULL;
void Ctrl_C_Handler(int sig);

int main(void) {
	file = FICHEIROenable();
	(void)file;
	func = FUNCenable();
	signal(SIGINT, Ctrl_C_Handler); // Create function pointer to signal (callback)
	/*****************/
	strcpy(feedback, "zero");
	/*****************/
	strcpy(file->par.permission, "r");
	strcpy(file->par.filename, "lfsm_1.txt");
	if(chdir("./poop"))
		fprintf(stderr, "chdir: %s\n", strerror(errno));
	printf("\n------------------\nProgram START\n------------------\n");
	while ass {
		printf("\n Entry : ");
		cmd=func.fltos(stdin);
		
		
		//fplfsm( "seq", cmd, STR_SIZE, file, logic, feedback );
		pooplfsm( seqsnprintf( "seq", cmd, feedback ), "=", STR_SIZE, file, feedback);
		
		//fplfsm( "seq_1", cmd, STR_SIZE, file, logic, feedback );
		pooplfsm( seqsnprintf( "seq_1", cmd, feedback ), "=", STR_SIZE, file, feedback);
		
		logic[0]='\0'; // oneshot
		pooplfsm( logsnprintf(cmd), "=", STR_SIZE, file, logic);
		
		
		if(!strcmp(cmd,"restart")) {
			strcpy(feedback, "zero");
		}
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")) {
			printf("Exiting Program\n");
			goto end;
		}
		if(!strcmp(cmd,"help")) {
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
		if(!strcmp(logic,"exit")) {
			printf("Exiting Program\n");
			goto end;
		}
		/***/
		if(!strcmp(logic,"excel")) {
			launch_excel();
		}
		if(!strcmp(logic,"word")) {
			launch_word();
		}
		if(!strcmp(logic,"powerpoint")) {
			launch_powerpoint();
		}
		if(!strcmp(logic,"flowchart")) {
			launch_flowchart();
		}
		if(!strcmp(logic,"formula")) {
			launch_formula();
		}


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
/***EOF***/

// Handler for SIGINT, triggered by 
// Ctrl-C at the keyboard 
void Ctrl_C_Handler(int sig)  { 
    printf("Caught signal %d\n", sig);
    free(cmd);
	printf("\n------------------\nProgram END\n------------------\n");
    exit(sig);
}

