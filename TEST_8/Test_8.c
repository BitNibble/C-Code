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
#include <ostdlib.h>
#include <ostring.h>
#include <stdarg.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h> // true, false
#include <omath.h>
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

char logic[SUBSTR_SIZE]={0};
char feedback[SUBSTR_SIZE]={0};
char* cmd = NULL;
void Ctrl_C_Handler(int sig);
void Hang_Up_Handler(int sig);

int main(void) {
	signal(SIGINT, Ctrl_C_Handler); // Create function pointer to signal (callback)
	signal(SIGTERM, Hang_Up_Handler); // Create function pointer to signal (callback)
	/*****************/
	ostring()->cpy(feedback, "zero");
	/*****************/
	ostring()->cpy(ofile()->par.permission, "r");
	ostring()->cpy(ofile()->par.filename, "lfsm_1.txt");
	oprocedure()->change_directory("./poop");
	ostdio()->printf("\n------------------\nProgram START\n------------------\n");
	while ass {
		ostdio()->printf("\n Entry : ");
		cmd=ofunc()->fltos(stdin);
		
		//opoop()->fplfsm( "seq", cmd, STR_SIZE, ofile(), logic, feedback );
		opoop()->pooplfsm( opoop()->seqsnprintf( "seq", cmd, feedback ), "=", STR_SIZE, ofile(), feedback);
		
		//opoop()->fplfsm( "seq_1", cmd, STR_SIZE, ofile(), logic, feedback );
		opoop()->pooplfsm( opoop()->seqsnprintf( "seq_1", cmd, feedback ), "=", STR_SIZE, ofile(), feedback);
		
		logic[0]='\0'; // oneshot
		opoop()->pooplfsm( opoop()->logsnprintf(cmd), "=", STR_SIZE, ofile(), logic );
		
		if(!ostring()->cmp(cmd,"restart")) {
			ostring()->cpy(feedback, "zero");
		}
		if(!ostring()->cmp(cmd,"quit") || !ostring()->cmp(cmd,"q")) {
			ostdio()->printf("Exiting Program\n");
			goto end;
		}
		if(!ostring()->cmp(cmd,"help")) {
			ostdio()->printf("Possible commands:\n"); 
			ostdio()->printf("\trestart - r\n"); 
			ostdio()->printf("\tquit - q\n"); 
			ostdio()->printf("\thelp - h\n");
			continue;
		}
		/**************************************************************/
		/**************************************************************/
		if(!ostring()->cmp(logic,"restart")) {
			ostring()->cpy(feedback, "zero");
		}
		ostdio()->printf("\n-------------\n LOG-OUT: %s\n-------------", logic);
		ostdio()->printf("\n-------------\n SEQ-OUT: %s\n-------------\n", feedback);
		/**************************************************************/
		//				-------TESTING AREA--------
		/**************************************************************/
		if(!ostring()->cmp(logic,"exit")) {
			ostdio()->printf("Exiting Program\n");
			goto end;
		}
		/***/
		if(!ostring()->cmp(logic,"excel")) {
			oprocedure()->launch_excel();
		}
		if(!ostring()->cmp(logic,"word")) {
			oprocedure()->launch_word();
		}
		if(!ostring()->cmp(logic,"powerpoint")) {
			oprocedure()->launch_powerpoint();
		}
		if(!ostring()->cmp(logic,"flowchart")) {
			oprocedure()->launch_flowchart();
		}
		if(!ostring()->cmp(logic,"formula")) {
			oprocedure()->launch_formula();
		}
		if(!ostring()->cmp(logic,"time")) {
			ostdio()->printf("Time: %s\n", oprocedure()->time());
		}






	}
/**********************************************************************/
/**********************************************************************/
end:
	ostdlib()->free(cmd);
	ostdio()->printf("\n------------------\nProgram END\n------------------\n");
	return 0;
}
/***EOF***/

// Handler for SIGINT, triggered by 
// Ctrl-C at the keyboard 
void Ctrl_C_Handler(int sig)  { 
    ostdio()->printf("Caught signal %d\n", sig);
    ostdlib()->free(cmd);
	ostdio()->printf("\n------------------\nProgram END\n------------------\n");
    ostdlib()->exit(sig);
}
// Handler for SIGHUP, triggered by 
// Close Terminal 
void Hang_Up_Handler(int sig)  { 
    ostdio()->printf("Caught signal %d\n", sig);
    ostdlib()->free(cmd);
	ostdio()->printf("\n------------------\nProgram END\n------------------\n");
    ostdlib()->exit(sig);
}

