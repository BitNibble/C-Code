/*************************************************************************
Title:    PCFICHEIRO (WRAPPER)
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: PCficheiro.c, v 0.1 2015/08/12 14:00:00 sergio Exp $
Software: GCC
Hardware: PC
License:  GNU General Public License
Comment:
	
*************************************************************************/
#include "PCficheiro.h"

static FICHEIRO self = {0}; // Object Variable

void FICHEIROopenp(void); //inic
void FICHEIROopen(const char* filename, const char *permission); //inic
int FICHEIROclose(void);
int FICHEIROgetc(void);
char* FICHEIROfgets(char* buffer, size_t size);
int FICHEIROfputc(int c);
int FICHEIROfputs(const char* s);
void FICHEIROprintf(const char* fmt, ...);
size_t FICHEIROread(void *ptr, size_t size, size_t nmemb);
size_t FICHEIROwrite(const void *ptr, size_t size, size_t nmemb);
void FICHEIROrewind(void);
FILE* FICHEIROfilepointer(void);
int FICHEIROfiledescriptor(void);
int seekposition(int whence, long offset);

FICHEIRO* FICHEIROenable(void)
{
	errno=0;
	self.openp=FICHEIROopenp;
	self.open=FICHEIROopen;
	self.close=FICHEIROclose;
	self.getc=FICHEIROgetc;
	self.fgets=FICHEIROfgets;
	self.fputc=FICHEIROfputc;
	self.fputs=FICHEIROfputs;
	self.printf=FICHEIROprintf;
	self.read=FICHEIROread;
	self.write=FICHEIROwrite;
	self.rewind=FICHEIROrewind;
	self.filepointer=FICHEIROfilepointer;
	self.filedescriptor=FICHEIROfiledescriptor;
	/***Control Pointer***/
	return &self;
}

/***FICHEIROopenp***/
void FICHEIROopenp(void)
{
	unsigned int step;
	for(step=1; step; ){
		if(step==1){
			self.par.fp = fopen(self.par.filename, self.par.permission);
			if(self.par.fp){
				fprintf(stderr, "Opening file: %s\n", self.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=2;
			}
		}
		if(step==2){
			self.par.fp = fopen(self.par.filename, "a+");
			if(self.par.fp){
				fprintf(stderr, "Re-Opening file: %s\n", self.par.filename);
				FICHEIROclose();
				step=3;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
		if(step==3){
			self.par.fp = fopen(self.par.filename, self.par.permission);
			if(self.par.fp){
				fprintf(stderr, "Opening file: %s\n", self.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
	}
	#ifdef linux
		self.par.fd=fileno(self.par.fp);
	#elif _WIN32
		self.par.fd=_fileno(self.par.fp);
	#endif
	if(self.par.fd < 0){
		perror("FICHEIROopen");
		fprintf(stderr, "errno: %d\n", errno);
	}
}

/***FICHEIROopen***/
void FICHEIROopen(const char *filename, const char *permission)
{
	unsigned int step;
	strcpy(self.par.filename, filename);
	strcpy(self.par.permission, permission);
	for(step=1; step; ){
		if(step==1){
			self.par.fp = fopen(self.par.filename, self.par.permission);
			if(self.par.fp){
				fprintf(stderr, "Opening file: %s\n", self.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=2;
			}
		}
		if(step==2){
			self.par.fp = fopen(self.par.filename, "a+");
			if(self.par.fp){
				fprintf(stderr, "Re-Opening file: %s\n", self.par.filename);
				FICHEIROclose();
				step=3;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
		if(step==3){
			self.par.fp = fopen(self.par.filename, self.par.permission);
			if(self.par.fp){
				fprintf(stderr, "Opening file: %s\n", self.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
	}
	#ifdef linux
		self.par.fd=fileno(self.par.fp);
	#elif _WIN32
		self.par.fd=_fileno(self.par.fp);
	#endif
	if(self.par.fd < 0){
		perror("FICHEIROopen");
		fprintf(stderr, "errno: %d\n", errno);
	}
}

/***FICHEIROclose***/
int FICHEIROclose(void)
{
	int r;
	if(self.par.fp)
		r = fclose(self.par.fp);
	else
		r = 0;
	return r;
}

/***FICHEIROgetc***/
int FICHEIROgetc(void)
{
	return getc(self.par.fp);
}

/***FICHEIROfgets***/
char* FICHEIROfgets(char* buffer, size_t size)
{
	return fgets(buffer, size, self.par.fp);
}
/***FICHEIROfputc***/
int FICHEIROfputc(int c)
{
	return fputc(c, self.par.fp);
}

/***FICHEIROfputs***/
int FICHEIROfputs(const char* s)
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
size_t FICHEIROread(void *ptr, size_t size, size_t nmemb)
{
	return fread(ptr, size, nmemb, self.par.fp);
}

/***FICHEIROwrite***/
size_t FICHEIROwrite(const void *ptr, size_t size, size_t nmemb)
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
        fprintf(stderr, "Error at seekposition: %d\n", errno);
    }else{
        fprintf(stderr, "At position: %ld\n",ftell(self.par.fp));
    }
	return r;
}
/***EOF***/

