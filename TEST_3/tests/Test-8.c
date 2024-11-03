/********************************************************
* Research Environment
* Test.c
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
#include <inttypes.h>
#include <math.h>
#include <inttypes.h>
//#include <assert.h>
#include "PCfunction.h"
#include "PCficheiro.h"
#include "explode.h"
/***Definition and Macros***/
#define sperm ~0
#define ass (1)
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define buff_size 4

static FUNC func;
/*******************************************************/
unsigned int number;

uint8_t BUFFER[buff_size];

struct circ_buf_template
{
	uint8_t* tail;
	uint8_t* head;
	uint8_t* buff;
	uint8_t* orig;
	uint8_t* jump;
	uint8_t (*get)(struct circ_buf_template* circ);
	void (*put)(struct circ_buf_template* circ);
} ;
typedef struct circ_buf_template circ_buff;


/*******************************************************/
uint8_t CIRC_get(struct circ_buf_template* circ);
void CIRC_put(struct circ_buf_template* circ, uint8_t data);
/*******************************************************/

int main(int argc, char *argv[]){
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
func = FUNCenable();


circ_buff circ;
circ.tail = circ.head = circ.buff = BUFFER;
circ.head += 3;
// flags
circ.orig = BUFFER;
circ.jump = BUFFER + ( buff_size - 1 );

// Prototypes

// Local variables
char c;
char* cmd=NULL;
unsigned int number0;
unsigned int number1;

BUFFER[0] = 0; BUFFER[1] = 1; BUFFER[2] = 2; BUFFER[3] = 3;

/*******************************************************/
/*******************************************************/
while ass
{
	printf("\nEnter i Data : ");
	
	cmd=func.fltos(stdin);
	number1=func.getnumv2(cmd);
	
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n"); printf("\trun - r\n"); printf("\tquit - q\n"); printf("\thelp - h\n");
		continue;
	}
	
	// RUN TESTING CONDITION:
	if( !strcmp(cmd,"run") || !strcmp(cmd,"r") ){  // one shot testing
	


		printf( "get :" );		
		cmd=func.fltos(stdin);
		number1=func.getnumv2(cmd);
		if(!strcmp(cmd,"skip") || !strcmp(cmd,"n")){
		}else{
			printf( "%ud\n", CIRC_get(&circ) );
		}
		
		
		printf( "put :" );		
		cmd=func.fltos(stdin);
		number1=func.getnumv2(cmd);
		if(!strcmp(cmd,"skip") || !strcmp(cmd,"n")){
			continue;
		}else{
			CIRC_put(&circ, (uint8_t) number1);
		}
	
	
		continue;
	}

}
/*******************************************************/
/*******************************************************/
end:
	free(cmd);
	//free(ptr);
	//free(str);
	//system("PAUSE");
	return 0;
/******/
}
/*******************************************************/

uint8_t CIRC_get( struct circ_buf_template* circ ){
	uint8_t* tail; uint8_t* next;
	tail = circ->tail;
	
	if( tail == circ->jump )
		next = circ->orig;
	else
		next = tail + 1;

	if( (tail == circ->head)  )
		;
	else{
		circ->tail = next;
		tail = next;
	}

	return *tail;
}

void CIRC_put( struct circ_buf_template* circ, uint8_t data ){
	uint8_t* head; uint8_t* next;
	head = circ->head;

	if( head == circ->jump )
		next = circ->orig;
	else
		next = head + 1;
	
	if( next == circ->tail )
		;
	else{
		*next = data;
		circ->head = next;
	}
}

/*******************************************************/
/*******************************************************/
/*******************************************************
Numer/ denominator --> N/D
X%X is always equal ZERO.
if numerator < denominator
N%D is always equal to N
Therefore X%X can be used as a flag to detect when N == D when N counts to D.
*******************************************************/
// ~0  (1)  (..)
/*******************************************************/
/***EOF***/

