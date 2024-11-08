/*************************************************************************
Title:    PCFICHEIRO (WRAPPER)
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:  PC emulation
Comment:
	Very Stable
*************************************************************************/
#include"PCficheiro.h"
/*
** constant and macro
*/
/*
** variable
*/
int errno;
struct ficheiro *self = NULL;
//Only draw back is, can only work with one file at a time, 
//that is sequencially, which is fine open and close one after the other.
/**
*
* Big chalenge how can get list of pointer to objects created synchronized with each one, 
* in order to not use passing by reference method ? Head twister problem.
*
**/
/*
** procedure and function header
*/
void FICHEIROopen(const char* filename, const char *permision); //inic
int FICHEIROclose(void);
int FICHEIROputc(int c);
int FICHEIROputs(const char* s);
int FICHEIROread(void *ptr, size_t size, size_t nmemb);
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb);
void FICHEIROrewind(void);
FILE* FICHEIROfilepointer(void);
int FICHEIROfiledescriptor(void);
int seekposition(int whence, long offset);
/*
** Object Inicialize
*/
FICHEIRO FICHEIROenable(struct ficheiro *this)
{
	/***Glocal variables assigning***/
	errno=0;
	self=this;
	/***local variables***/
	FICHEIRO f;
	/***Local variables assigning***/
	f.self=this;
	//Functions pointers or Vtable to declared functions
	f.open=FICHEIROopen;
	f.close=FICHEIROclose;
	f.putch=FICHEIROputc;
	f.puts=FICHEIROputs;
	f.read=FICHEIROread;
	f.write=FICHEIROwrite;
	f.rewind=FICHEIROrewind;
	f.filepointer=FICHEIROfilepointer;
	f.filedescriptor=FICHEIROfiledescriptor;
	//return result
	return f;
}
/*
** procedure and function
*/
/***FICHEIROopen***/
void FICHEIROopen(const char *filename, const char *permision)
{
	unsigned int exit;
	//Inicialize varibles
	strcpy(self->filename, filename);
	//do a checkup if exists first !
	strcpy(self->permision, permision);
	//procedures
	for(exit=1; exit; ){
		if(exit==1){
			self->fp = fopen(self->filename, self->permision);
			if(self->fp!=NULL){
				printf("Opening file: %s\n", self->filename);
				exit=0;
			}else{
				perror("Error FICHEIROopen");
				printf("Error Opening file -> %s\n", self->filename);
				fclose((FILE*)self->fp);
				exit=2;
			}
		}
		if(exit==2){
			strcpy(self->permision, "a+");//setting as default
			self->fp = fopen(self->filename, self->permision);
			if(self->fp!=NULL){
				printf("ReOpening file: %s\n", self->filename);
				strcpy(self->permision, permision);
				fclose((FILE*)self->fp);
				exit=1;
			}else{
				perror("Error FICHEIROopen");
				printf("Error ReOpening file -> %s\n", self->filename);
				fclose((FILE*)self->fp);
				exit=0;
			}
		}
	}
	//Apart
	#ifdef linux
		self->fd=fileno(self->fp);
		#elif _WIN32
			self->fd=_fileno(self->fp);
	#endif
	if(self->fd < 0){
		perror("Error FICHEIROopen");
		printf("Numb errno: %d\n", errno);
		self->errcode=errno;
	}
}
/*FICHEIROclose*/
int FICHEIROclose(void)
{
	if(fclose((FILE*)self->fp) != 0){
        printf("Error at FICHEIROclose\n");
        return 1;
    }else
	    return 0;
}
/*FICHEIROputc*/
int FICHEIROputc(int c)
{
	int r;
	r=fputc(c, (FILE*)self->fp);
	return r;
}
/*FICHEIROputs*/
int FICHEIROputs(const char* s)
{
	int r;
	r=fputs(s, (FILE*)self->fp);
	return r;
}
/***FICHEIROread***/
int FICHEIROread(void *ptr, size_t size, size_t nmemb)
{
	int r;
	r=fread(ptr, size, nmemb, self->fp);
	return r;
}
/***FICHEIROwrite***/
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb)
{
	int r;
	r=fwrite(ptr, size, nmemb, self->fp);
	return r;
}
/*FICHEIROrewind*/
void FICHEIROrewind(void)
{
	rewind((FILE*)self->fp);
}
/***FICHEIROfilepointer***/
FILE* FICHEIROfilepointer(void)
{
	return (FILE*)self->fp;
}
/***FICHEIROfiledescriptor***/
int FICHEIROfiledescriptor(void)
{
	return self->fd;
}
/***setposition***/
int seekposition(int whence, long offset)
{
	int r;
    r=fseek(self->fp, offset, whence);
    if(r!=0){
        printf("Error at seekposition: %d\n", errno);
    }else{
        printf("At position: %ld\n",ftell(self->fp));
    }
	return r;
}
/*
** interrupt
*/
/***Comment
Working with the most difficult, makes the easy seem easier.
***/
/***EOF***/
