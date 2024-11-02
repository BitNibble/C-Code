/*************************************************************************
Title:    PCLILI
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PClili.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware:
License:  GNU General Public License
DESCRIPTION:
	PC emulation
USAGE:
NOTES:
LICENSE:
    Copyright (C) 2015
    This program is free software; you can redistribute it and/or modify
    it under the consent of the code developer, in case of commercial use
    need licence.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
COMMENT:
	perfect
*************************************************************************/
#include"PClili.h"
/*
** constant and macro
*/
#define EMPTY 0
#define RMFR 1
#define INSFR 1
/*
** variable
*/
// default return result
LILIDATA empty = 
{
	.next = NULL,
	.back = NULL,
	.vector = "empty"
};
/*
** procedure and function header
*/
LILIDATA LILIplay(struct lili *l);
void LILIforward(struct lili *l);
void LILIreverse(struct lili *l);
void LILIrecord(struct lili *l, const char* data);
void LILIremove(struct lili *l);
void LILIfree(struct lili *l);
unsigned int LILIquant(struct lili *l);
/***to be implemented***/
void LILIinsert(struct lili *l, const char* data); // not finished
void LILIreplace(struct lili *l, const char* data);
void LILIpush(struct lili *l, const char* data);
LILIDATA LILIpop(struct lili *l);
/*
** Object Inicialize
*/
LILI LILIenable(void)
{
	/***Local Variable***/
	/***Local Function Header***/
	/***Create Object***/
	LILI l;
	//Inicialize variables
	l.target=NULL;
	l.tail=NULL;
	l.head=NULL;
	l.total=0;
	//Function Vtable
	l.play=LILIplay;
	l.forward=LILIforward;
	l.reverse=LILIreverse;
	l.record=LILIrecord;
	l.remove=LILIremove;
	l.free=LILIfree;
	l.quant=LILIquant;
	l.insert=LILIinsert;
	l.replace=LILIreplace;
	l.push=LILIpush;
	l.pop=LILIpop;
	/******/
	return l;
}
/*
** procedure and function
*/
/***play***/
LILIDATA LILIplay(struct lili *l)
{
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
		return empty;
	}else{
		return *l->target;
	}
}
/***forward***/
void LILIforward(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		if(l->target!=l->head){
			l->target=l->target->next;
		}
	}
}
/***reverse***/
void LILIreverse(struct lili *l)
{
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		if(l->target!=l->tail){
			l->target=l->target->back;
		}
	}
}
/***record***/
void LILIrecord(struct lili *l, const char* data)
{
	if(l->target==NULL){//INICIALIZE LIST
		l->target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next=l->target->back=l->target;
		/***/
		l->tail=l->head=l->target;
		strcpy(l->target->vector,data);
		l->total++;
	}else{
		if(l->head==l->target){
			l->target->next=(LILIDATA*)calloc(1,sizeof(LILIDATA));
			l->target->next->next=l->target->next;
			l->target->next->back=l->target;
			/****/
			l->target=l->target->next;
			l->head=l->target;
			strcpy(l->target->vector,data);
			l->total++;
		}else{
			printf("Record only permitted at end of list, append only\n");
		}
	}
}
/***remove***/
void LILIremove(struct lili *l)
{
	LILIDATA *ptr;
	if(l->target==NULL)
		printf("Linked List EMPTY\n");
	else{
		if(l->target->next==l->target->back){
			printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE
			free(l->target);
			l->target=NULL;
			l->tail=NULL;
			l->head=NULL;
			l->total--;
		}else if(l->target->back==l->target){ //tail
			printf("troubleshoot: if((l->target->back==l->target) «FIRST IN LIST»\n");//FIRST IN LIST
			ptr=l->target;
			l->target->next->back=l->target->next;
			//
			l->target=l->target->next;
			l->tail=l->target;
			l->total--;
			free(ptr);
		}else if(l->target->next==l->target){ //head
			printf("troubleshoot: if((l->target->next==l->target) «LAST IN LIST»\n");//LAST IN LIST
			ptr=l->target;
			l->target->back->next=l->target->back;
			//
			l->target=l->target->back;
			l->head=l->target;
			l->total--;
			free(ptr);
		}else{
			printf("troubleshoot: In between «IN BETWEEN»\n"); //middle
			ptr=l->target;
			l->target->next->back=l->target->back;
			l->target->back->next=l->target->next;
			//***choice**
			if(RMFR){
				l->target=l->target->back;
			}else{
				l->target=l->target->next;
			}
			l->total--;
			free(ptr);
		}
	}
}
/***free***/
void LILIfree(struct lili *l)
{
	while(l->target)
		LILIremove(l);
}
/***quant***/
unsigned int LILIquant(struct lili *l)
{
	return l->total;
}
/***insert***/
void LILIinsert(struct lili *l, const char* data)
{
	LILIDATA* ptr = NULL;
	if(l->target==NULL){//INICIALIZE LIST
		ptr=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		strcpy(ptr->vector,data);
		//
		l->target=ptr;
		l->target->next=l->target->back=l->target;
		//
		l->tail=l->head=l->target;
		l->total++;
	}if(l->target->next==l->target->back){
		printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else if(l->target->back==l->target){
		printf("troubleshoot: if((l->target->back==l->target) «FIRST IN LIST»\n");//FIRST IN LIST
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else if(l->target->next==l->target){
		printf("troubleshoot: if((l->target->next==l->target) «LAST IN LIST»\n");//LAST IN LIST
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}else{
		printf("troubleshoot: In between «IN BETWEEN»\n");//IN BETWEEN
		if(INSFR){
		
		
		
		
		}else{
		
		
		
		
		}
	}
}
/***replace***/
void LILIreplace(struct lili *l, const char* data)
{
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
	}else{
		strcpy(l->target->vector,data);
	}
}
/***push***/
void LILIpush(struct lili *l, const char* data)
{
	if(l->target==NULL){//INICIALIZE LIST
		l->target=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next=l->target->back=l->target;
		strcpy(l->target->vector,data);
		//strcpy(l->vector,data);
		//
		l->tail=l->head=l->target;
		l->total++;
	}else{
		l->target=l->head;
		l->target->next=(LILIDATA*)calloc(1,sizeof(LILIDATA));
		l->target->next->next=l->target->next;
		l->target->next->back=l->target;
		strcpy(l->target->next->vector,data);
		//strcpy(l->vector,data);
		//
		l->target=l->target->next;
		l->head=l->target;
		l->total++;
	}
}
/***pop***/
LILIDATA LILIpop(struct lili *l)
{
	LILIDATA* ptr = &empty;
	if(l->target==NULL){
		printf("Linked List EMPTY\n");
	}else{
		ptr=l->target=l->head;
		if(l->target->next==l->target->back){
			printf("troubleshoot: if((l->target->next==l->target->back) «ONLY ONE»\n");//ONLY ONE
			free(l->target);
			l->target=NULL;
			l->tail=NULL;
			l->head=NULL;
			l->total--;
		}else{
			l->target->back->next=l->target->back;
			l->target=l->target->back;
			free(l->head);
			l->head=l->target;
			l->total--;
		}
	}
	return *ptr;
}
/*
** interrupt
*/
/*
*** Comments
*/
//encapsulation mandates repetition of code.
/***EOF***/
