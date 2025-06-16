/**********************************************************************
* Research Environment
* Test_8.c
* Nome: <sergio.salazar.santos@gmail.com>
* data: 24-02-2018 11:00
* comment: 
*	file pointer learning finite state machine
* 
***********************************************************************/
#include <ostdio.h>
#include <stdlib.h>
#include <ostring.h>
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

FUNC func;
FICHEIRO* file;
PROCEDURES* procedure;
POOP* poop;
OSTDIO* stdio;
OSTRING* string;
char logic[SUBSTR_SIZE]={0};
char feedback[SUBSTR_SIZE]={0};
char* cmd = NULL;
void Ctrl_C_Handler(int sig);
void Hang_Up_Handler(int sig);

int main(void) {
	file = FICHEIROenable();
	procedure = PROCEDURESenable();
	poop = POOPenable();
	(void)file;
	func = FUNCenable();
	stdio = OSTDIOenable();
	string = OSTRINGenable();
	signal(SIGINT, Ctrl_C_Handler); // Create function pointer to signal (callback)
	signal(SIGTERM, Hang_Up_Handler); // Create function pointer to signal (callback)
	/*****************/
	string->cpy(feedback, "zero");
	/*****************/
	string->cpy(file->par.permission, "r");
	string->cpy(file->par.filename, "lfsm_1.txt");
	procedure->change_directory("./poop");
	stdio->printf("\n------------------\nProgram START\n------------------\n");
	while ass {
		stdio->printf("\n Entry : ");
		cmd=func.fltos(stdin);
		
		//poop->fplfsm( "seq", cmd, STR_SIZE, file, logic, feedback );
		poop->pooplfsm( poop->seqsnprintf( "seq", cmd, feedback ), "=", STR_SIZE, file, feedback);
		
		//poop->fplfsm( "seq_1", cmd, STR_SIZE, file, logic, feedback );
		poop->pooplfsm( poop->seqsnprintf( "seq_1", cmd, feedback ), "=", STR_SIZE, file, feedback);
		
		logic[0]='\0'; // oneshot
		poop->pooplfsm( poop->logsnprintf(cmd), "=", STR_SIZE, file, logic );
		
		if(!string->cmp(cmd,"restart")) {
			string->cpy(feedback, "zero");
		}
		if(!string->cmp(cmd,"quit") || !string->cmp(cmd,"q")) {
			stdio->printf("Exiting Program\n");
			goto end;
		}
		if(!string->cmp(cmd,"help")) {
			stdio->printf("Possible commands:\n"); 
			stdio->printf("\trestart - r\n"); 
			stdio->printf("\tquit - q\n"); 
			stdio->printf("\thelp - h\n");
			continue;
		}
		/**************************************************************/
		/**************************************************************/
		if(!string->cmp(logic,"restart")) {
			string->cpy(feedback, "zero");
		}
		stdio->printf("\n-------------\n LOG-OUT: %s\n-------------", logic);
		stdio->printf("\n-------------\n SEQ-OUT: %s\n-------------\n", feedback);
		/**************************************************************/
		//				-------TESTING AREA--------
		/**************************************************************/
		if(!string->cmp(logic,"exit")) {
			stdio->printf("Exiting Program\n");
			goto end;
		}
		/***/
		if(!string->cmp(logic,"excel")) {
			procedure->launch_excel();
		}
		if(!string->cmp(logic,"word")) {
			procedure->launch_word();
		}
		if(!string->cmp(logic,"powerpoint")) {
			procedure->launch_powerpoint();
		}
		if(!string->cmp(logic,"flowchart")) {
			procedure->launch_flowchart();
		}
		if(!string->cmp(logic,"formula")) {
			procedure->launch_formula();
		}
		if(!string->cmp(logic,"time")) {
			stdio->printf("Time: %s\n", procedure->time());
		}






	}
/**********************************************************************/
/**********************************************************************/
end:
	free(cmd);
	stdio->printf("\n------------------\nProgram END\n------------------\n");
	return 0;
}
/***EOF***/

// Handler for SIGINT, triggered by 
// Ctrl-C at the keyboard 
void Ctrl_C_Handler(int sig)  { 
    stdio->printf("Caught signal %d\n", sig);
    free(cmd);
	stdio->printf("\n------------------\nProgram END\n------------------\n");
    exit(sig);
}
// Handler for SIGHUP, triggered by 
// Close Terminal 
void Hang_Up_Handler(int sig)  { 
    stdio->printf("Caught signal %d\n", sig);
    free(cmd);
	stdio->printf("\n------------------\nProgram END\n------------------\n");
    exit(sig);
}

