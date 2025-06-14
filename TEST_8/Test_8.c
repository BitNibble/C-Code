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
//#include <assert.h>
#include <unistd.h> // chdir 
#include "PCfunction.h"
#include "explode.h"
#include "circbuffer.h"
#include "poop.h"
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

int main(void) {
	file = FICHEIROenable();
	(void)file;
	func = FUNCenable();
	char* cmd = NULL;
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
		/***/
		if(!strcmp(logic,"excel")) {
			system("\"C:\\Program Files\\LibreOffice\\program\\scalc.exe\""); // Launches Excel via cmd.exe
		}
		if(!strcmp(logic,"word")) {
			system("\"C:\\Program Files\\LibreOffice\\program\\swriter.exe\""); // Launches Excel via cmd.exe
		}
		if(!strcmp(logic,"powerpoint")) {
			system("\"C:\\Program Files\\LibreOffice\\program\\simpress.exe\""); // Launches Excel via cmd.exe
		}
		if(!strcmp(logic,"flowchart")) {
			system("\"C:\\Program Files\\LibreOffice\\program\\sdraw.exe\""); // Launches Excel via cmd.exe
		}
		if(!strcmp(logic,"formula")) {
			system("\"C:\\Program Files\\LibreOffice\\program\\smath.exe\""); // Launches Excel via cmd.exe
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

/*****
system("ls -l /");
/bin/sh -c "ls -l /"
system("bash -c 'some-bash-command'");
system("powershell -Command \"Get-Process\"");
cmd.exe /c dir
system("dir");
system("start \"\" \"notepad.exe\" \"C:\\test.txt\"");
system("\"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE\"");
system("start winword \"C:\\Users\\Salazar\\Documents\\example.docx\"");
system("start excel"); // Launches Excel via cmd.exe
system("wsl bash -c \"ls -l /\""); // Calls WSL bash
system("dir"); // Equivalent to 'ls' on Unix


******/
