/*************************************************************************
Title:    PCFICHEIRO (WRAPPER)
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Description:  PC emulation
Comment:
	
*************************************************************************/
#include"PCficheiro.h"

static FICHEIRO self; // Object Variable

void FICHEIROopen(const char* filename, const char *permision); //inic
int FICHEIROclose(void);
int FICHEIROputc(int c);
int FICHEIROputs(const char* s);
void FICHEIROprintf(const char* fmt, ...);
int FICHEIROread(void *ptr, size_t size, size_t nmemb);
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb);
void FICHEIROrewind(void);
FILE* FICHEIROfilepointer(void);
int FICHEIROfiledescriptor(void);
int seekposition(int whence, long offset);

FICHEIRO* FICHEIROenable(void)
{
	/***Glocal variables assigning***/
	errno=0;
	/***local variables***/
	self.par.fp = NULL;
	self.par.fd = 0;
	self.par.errcode=0;
	/***Local variables assigning***/
	//Functions pointers or Vtable to declared functions
	self.open=FICHEIROopen;
	self.close=FICHEIROclose;
	self.putch=FICHEIROputc;
	self.puts=FICHEIROputs;
	self.printf=FICHEIROprintf;
	self.read=FICHEIROread;
	self.write=FICHEIROwrite;
	self.rewind=FICHEIROrewind;
	self.filepointer=FICHEIROfilepointer;
	self.filedescriptor=FICHEIROfiledescriptor;
	/***Control Pointer***/
	return &self;
}

/***FICHEIROopen***/
void FICHEIROopen(const char *filename, const char *permision)
{
	unsigned int exit;
	//Inicialize variables
	strcpy(self.par.filename, filename);
	//Do a checkup if exists first !
	strcpy(self.par.permision, permision);
	//procedures
	for(exit=1; exit; ){
		if(exit==1){
			self.par.fp = fopen(self.par.filename, self.par.permision);
			if(self.par.fp){
				printf("Opening file: %s\n", self.par.filename);
				exit=0;
			}else{
				perror("FICHEIROopen");
				fclose(self.par.fp);
				exit=2;
			}
		}
		if(exit==2){
			strcpy(self.par.permision, "W"); //setting as default
			self.par.fp = fopen(self.par.filename, self.par.permision);
			if(self.par.fp){
				printf("Re-Opening file: %s\n", self.par.filename);
				strcpy(self.par.permision, permision);
				fclose(self.par.fp);
				exit=1;
			}else{
				perror("FICHEIROopen");
				fclose(self.par.fp);
				exit=0;
			}
		}
	}
	//Apart
	#ifdef linux
		self.par.fd=fileno(self.par.fp);
	#elif _WIN32
		self.par.fd=_fileno(self.par.fp);
	#endif
	if(self.par.fd < 0){
		perror("FICHEIROopen");
		printf("errno: %d\n", errno);
		self.par.errcode=errno;
	}
}

/***FICHEIROclose***/
int FICHEIROclose(void)
{
	if(fclose(self.par.fp)){
        perror("FICHEIROclose");
        return 1;
    }else{
		self.par.fp = NULL;
		self.par.fd = 0;
	    return 0;
	}
}

/***FICHEIROputc***/
int FICHEIROputc(int c)
{
	return fputc(c, self.par.fp);
}

/***FICHEIROputs***/
int FICHEIROputs(const char* s)
{
	return fputs(s, self.par.fp);
}

/***FICHEIROprintf***/
void FICHEIROprintf(const char* fmt, ...)
{
	va_list args;
    va_start(args, fmt);
	vfprintf(self.par.fp, fmt, args);
	va_end(args);
}

/***FICHEIROread***/
int FICHEIROread(void *ptr, size_t size, size_t nmemb)
{
	return fread(ptr, size, nmemb, self.par.fp);
}

/***FICHEIROwrite***/
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb)
{
	return fwrite(ptr, size, nmemb, self.par.fp);
}

/***FICHEIROrewind***/
void FICHEIROrewind(void)
{
	rewind(self.par.fp);
}

/***FICHEIROfilepointer***/
FILE* FICHEIROfilepointer(void)
{
	return self.par.fp;
}
/***FICHEIROfiledescriptor***/
int FICHEIROfiledescriptor(void)
{
	return self.par.fd;
}

/***setposition***/
int seekposition(int whence, long offset)
{
	int r;
    r = fseek(self.par.fp, offset, whence);
    if(r){
        printf("Error at seekposition: %d\n", errno);
    }else{
        printf("At position: %ld\n",ftell(self.par.fp));
    }
	return r;
}
/***EOF***/

