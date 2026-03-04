/*
* Research
* PCLFSM2018.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
*
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
//#include <time.h>
// tcflsuh read write close
//#include <unistd.h>
// perror
//#include <errno.h>
// open
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
//#include <stdio_ext.h>
#include <math.h>
// personal library
#include"PCfunction.h"
#include"PClfsm.h"
#include"PCficheiro.h"
/***Definition and Macros***/
#define TRUE 1
#define ZERO 0
#define EMPTY 0 //on a pc vectores are at zero therefore empty is zero.
#define HIGH 1
#define high 1
#define LOW 0
#define low 0

/*****GLOBAL VARIABLES*****/
LFSMDATA MEM[128];

/*****Procedure and Function*****/
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
// Main Main Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[])
{
	printf("Running program - %s with - %d arguments", argv[0], argc);
	char *cmd;
	unsigned int number3;
	unsigned int number1;
	unsigned int number2;
    unsigned int value;
    unsigned int status=ZERO;
/*******************************************************/
	FUNC func=FUNCenable();
	LFSM r = LFSMenable(MEM, 128);
	/***************************/
	FICHEIRO* f=FICHEIROenable();
	f->open("file.txt", "a+");
	f->fputc('A');
	f->fputs(" qualquer coisa\n");
	f->close();
	printf("lfsmdata size: %lld\n",sizeof(LFSMDATA));
/********************************************************/
	printf("sizeeeprom: %d\n", r.sizeeeprom);
	printf("randomize %d\n", rand());
	/*******************************************************************************************/
	// Cycle
	while(TRUE){
		printf("write string with number or instruction : ");
		cmd=func.fltos(stdin);
		number1=func.getnumv2(cmd);
		printf("[Input ->  %s  ]\n",func.print_binary(8, number1));
        //printf("Entered numeral value: %d\n",number1);
        
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			goto end;
		}

		if(!strcmp(cmd,"learn") || !strcmp(cmd,"l")){
			printf("enter input\n");
			cmd=func.fltos(stdin);
			//number1=func.binary_decimal(func.getnum(cmd));
			number1=func.getnum(cmd);
			printf("enter output data\n");
			cmd=func.fltos(stdin);
			number2=func.getnum(cmd);
			printf("enter page\n");
			cmd=func.fltos(stdin);
			number3=func.getnum(cmd);
			printf("Entered values %d %d %d\n",number1,number2,number3);
			r.learn(&r,number1,number2,number3);
            continue;
		}

		if(!strcmp(cmd,"how many") || !strcmp(cmd,"n")){
			printf("------ %d ------\n",r.quant(&r));
            continue;
		}

		if(!strcmp(cmd,"delete all") || !strcmp(cmd,"d")){
			r.deleteall(&r);
            continue;
		}

		if(!strcmp(cmd,"remove") || !strcmp(cmd,"r")){
			printf("enter input to remove\n");
			cmd=func.fltos(stdin);
			number1=func.getnum(cmd);
			//l.remove(&l,number1);
			r.remove(&r,number1);
            continue;
		}

		if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
			printf("Possible commands:\n");
           		printf("\tquit - q\n");
            		printf("\tlearn - l\n");
            		printf("\thelp - h\n");
            		printf("\thow many - n\n");
            		printf("\tdelete all - d\n");
            		printf("\tremove\n");
            		printf("\toptions\n");
            		printf("Page setting:\n");
            		printf("\t1 is for global logic\n");
            		printf("\tAbove 1 is for local logic\n");
            		printf("Input procedure:\n");
            		printf("\tProgram sequence is first desired input\n");
			printf("\tsecond is desired ouput\n");
			printf("\tthen select what page to store as refered above.\n");
			continue;
		}

		if(!strcmp(cmd,"options") || !strcmp(cmd,"o")){
			printf("learn or l\nquit or q\nhow many or n\ndelete all or d\nremove or r\noptions\n");
            continue;
		}
        if(status==ZERO){
            value=r.read(&r,number1);
            printf("\t\t\t\t\t[Output ->  %s  ]\n",func.print_binary(8, value));
        } 
	}
	/******/
	end:
		free(cmd);
		//system("PAUSE");
		return 0;
}
/***EOF***/
