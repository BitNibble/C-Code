/************************************************************************
Title:    poop
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: poop.h$
Software: GCC
Hardware: OS
License: Free beer
************************************************************************/
#include "poop.h"
/***strtotok***/
int strtotok(char* line, char* token[], const char* parser)
{
	int i;
	for (i = 0, token[i] = strtok(line, parser); token[i] ; i++, token[i] = strtok(NULL, parser));
	return i;
}
/***rmcrnl***/
void rmcrnl(char* str)
{
	int i; int stop;
	for(i=strlen(str), stop=i-3; i > stop ; i--) {
		if(*(str+i) == '\r' || *(str+i) == '\n') {
			*(str+i)='\0';
		}
	}
}
/***lfsm***/
void fplfsm( const char* seq_name, const char* search, const size_t buff_size, FICHEIRO* file, char* logic, char* feedback )
{
	char line[buff_size];
	char LOG[buff_size];
	const size_t BUFF_SIZE = buff_size - 1;
	char* token[4];
	int logic_size = sizeof(logic);
	file->openp();
	memset(logic, 0, logic_size);
	while(file->fgets(line, BUFF_SIZE)) {
		rmcrnl(line);
		//printf("file: %s\n", line);
		strtotok(line, token, "=");
		//printf("\ttoken[0]:%s\n", token[0]);
		if(token[0]){
			if(snprintf(LOG, BUFF_SIZE, "log+%s", search) > 0) {
				//printf("\tlogic: %s\n", LOG);
				if(!strcmp(LOG, token[0])){
					strcpy(logic, token[1]);
					printf("LOG-out: ----> %s\n", logic); 
				}
				if(snprintf(LOG, BUFF_SIZE, "%s*%s+%s",seq_name ,feedback, search) > 0) {
					//printf("\tsequence: %s\n", LOG);
					if(!strcmp(LOG, token[0])){
						strcpy(feedback, token[1]);
						printf("SEQ-out ----> %s\n", feedback); 
						break;
					}
				}else{perror("LOG");}
			}else{perror("LOG");}
		}else {
			//printf("Skip Token\n");
		}
	}
	if (feof(file->filepointer())) {
		//printf("End of file reached.\n");
	}
	file->close();
}
/***EOF***/

