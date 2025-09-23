/*
*
* Research
* Test-9.c
* Nome: sergio santos
* Contacto: 916919898; sergio.salazar.santos@gmail.com
* data: 24-02-2018 11:00
* commnet: the simplest lfsm ever
*
* reviewed: 16122021
*
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>
#include <inttypes.h>
#include"user_lib\inc\PCfunction.h"
#include"user_lib\inc\PCficheiro.h"
#include"user_lib\inc\explode.h"
/***Definition and Macros***/
#define ZERO 0
#define ONE 1
#define AREA(l, b) (l * b)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define ptradd(a)(a)
#define lines 256
#define columns 256
unsigned int ftest(void);
//*****GLOBAL FILE VARIABLES*****
static FUNC func;
uint8_t book[AREA(lines, columns)];
typedef struct
{
	unsigned int testa;
	unsigned int (*testb)(void);

}test;


/***/
// Main Main Main Main Main Main Main Main Main Main Main Main
int main(int argc, char *argv[]){
//int main(void){
/***/
// Capture arguments
printf("Running program - %s\nwith - %d arguments\n\n", argv[0], argc);
// Local variables
test test;
test.testb = ftest;
//char c;
char* cmd=NULL;
unsigned int state;
//unsigned int number0;
unsigned int number1;
unsigned int number2;
unsigned int number3;
unsigned int index;
unsigned int i;
char* sample = "ola mundo";
char* token[32];
char* str=NULL;
char* ptr=NULL;
char tmp[256];
char string[256];

test.testa = ftest();
func=FUNCenable();

FICHEIRO* f = FICHEIROenable(); // one object all files

//EXPLODE port = EXPLODEenable();
//EXPLODE input = EXPLODEenable();

number1 = number2 = number3 = state = 0;

printf(func.print("%d %d %d \n\n",1,2,test.testb()));

str=sample;
printf("%s\n\n", str);

for(i=0;i<(lines*columns);i++) // offset vector to 255 (emulate eeprom)
	book[i]=0xFF;

f->open("file.txt", "r");
str = func.ftos(f->filepointer());
printf("read entire file\n%s \n", str);
f->close();

f->open("file.txt", "a+"); // Load Data from file to book vector (book[]).
//f.open(f.self, "file.txt", "a+");
for(i=1; (str = func.fltos(f->filepointer())); i++){
	func.strtotok(str, token, ",");
	printf("%d Tokens: %s -> %s\n", i, token[0], token[1]);
	number1=func.getnumv2(token[0]);
	number2=func.getnumv2(token[1]);
	book[number1]=number2;
}
f->close();

// open testing object functionality
f->open("another.txt", "r+"); //rewind only works in r+
f->fputs("bla bla bla bla bla !!!\n");
f->fputs("bla bla bla bla bla !!!\n");
f->fputs("ua ua ua ua ua ua u !!!\n");
f->rewind();
f->fputs("ble ble ble ble ble !!!\n");
f->close();


while(ONE){
	printf("\nEnter i Data : ");
	cmd=func.fltos(stdin);
	number1=func.getnumv2(cmd);
	//port.update(&port,number1);
	//printf("[Command ->  %s]\n", cmd);
	if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
		goto end;
	}
	if(!strcmp(cmd,"help") || !strcmp(cmd,"h")){
		printf("Possible commands:\n");
		printf("\trun - r\n");
		printf("\tquit - q\n");
		printf("\thelp - h\n");
		continue;
	}
	//FILTER
	if(number1 > (lines-2))
		continue;
	

	index = number2+lines*number1;
	number3=book[index];
	
	strcpy(tmp, func.ftoa(index,tmp,0));
	
	printf("ftoa---> %s\n", tmp);


	for(;number3 > (lines-2); state = 1){
		printf("Enter mem Data : ");
		cmd=func.fltos(stdin);
		if(!strcmp(cmd,"quit") || !strcmp(cmd,"q")){
			number3=number2;
			state = 0;
			break;
		}
		number3=func.getnumv2(cmd);
	}


	if(number2!=number3){
		book[number2+lines*number1]=number3;
		number2=number3;
	}
	printf("\nExtracted Data : %d ", number3);
	printf("\n**************************\n");

	ptr = func.ftoa(number3,string, 0);
	
	if(state == 1){ //Record new entry
		f->open("file.txt", "a+");
		//f.open(&f, "file.txt", "a+");
		strcat(tmp,",");
		strcat(tmp, ptr);
		strcat(tmp, "\n");
		printf("ftoa---> %s\n", tmp);
		f->fputs(tmp);
		f->close();
		state=0;
	}
	
// RUN TESTING CONDITION:
	if(!strcmp(cmd,"run") || !strcmp(cmd,"r")){ // one shot testing
		
		
		continue;
	}

}

end:
	free(cmd);
	//free(ptr);
	free(str);
	//system("PAUSE");
	return 0;
/******/
}
/***FUNCTION***/
unsigned int ftest(void)
{
	return 6;
}
/***EOF***/
