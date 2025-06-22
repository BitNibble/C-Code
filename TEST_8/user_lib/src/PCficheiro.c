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

static FICHEIRO setup = {0};

void ofile_enable(void)
{
	setup.par.whence = 0;
	setup.par.offset = 0;
	setup.par.fd = 0;
	setup.par.fp = NULL;
	setup.openp=FICHEIROopenp;
	setup.open=FICHEIROopen;
	setup.close=FICHEIROclose;
	setup.getc=FICHEIROgetc;
	setup.fgets=FICHEIROfgets;
	setup.fputc=FICHEIROfputc;
	setup.fputs=FICHEIROfputs;
	setup.printf=FICHEIROprintf;
	setup.read=FICHEIROread;
	setup.write=FICHEIROwrite;
	setup.rewind=FICHEIROrewind;
	setup.filepointer=FICHEIROfilepointer;
	setup.filedescriptor=FICHEIROfiledescriptor;
}

FICHEIRO* ofile(void){ return &setup;}

/***FICHEIROopenp***/
void FICHEIROopenp(void)
{
	unsigned int step;
	for(step=1; step; ){
		if(step==1){
			setup.par.fp = fopen(setup.par.filename, setup.par.permission);
			if(setup.par.fp){
				fprintf(stderr, "Opening file: %s\n", setup.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=2;
			}
		}
		if(step==2){
			setup.par.fp = fopen(setup.par.filename, "a+");
			if(setup.par.fp){
				fprintf(stderr, "Re-Opening file: %s\n", setup.par.filename);
				FICHEIROclose();
				step=3;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
		if(step==3){
			setup.par.fp = fopen(setup.par.filename, setup.par.permission);
			if(setup.par.fp){
				fprintf(stderr, "Opening file: %s\n", setup.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
	}
	#ifdef linux
		setup.par.fd=fileno(setup.par.fp);
	#elif _WIN32
		setup.par.fd=_fileno(setup.par.fp);
	#endif
	if(setup.par.fd < 0){
		perror("FICHEIROopen");
		fprintf(stderr, "errno: %d\n", errno);
	}
}

/***FICHEIROopen***/
void FICHEIROopen(const char *filename, const char *permission)
{
	unsigned int step;
	strcpy(setup.par.filename, filename);
	strcpy(setup.par.permission, permission);
	for(step=1; step; ){
		if(step==1){
			setup.par.fp = fopen(setup.par.filename, setup.par.permission);
			if(setup.par.fp){
				fprintf(stderr, "Opening file: %s\n", setup.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=2;
			}
		}
		if(step==2){
			setup.par.fp = fopen(setup.par.filename, "a+");
			if(setup.par.fp){
				fprintf(stderr, "Re-Opening file: %s\n", setup.par.filename);
				FICHEIROclose();
				step=3;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
		if(step==3){
			setup.par.fp = fopen(setup.par.filename, setup.par.permission);
			if(setup.par.fp){
				fprintf(stderr, "Opening file: %s\n", setup.par.filename);
				step=0;
			}else{
				fprintf(stderr, "FICHEIROopen, %d\n", errno);
				step=0;
			}
		}
	}
	#ifdef linux
		setup.par.fd=fileno(setup.par.fp);
	#elif _WIN32
		setup.par.fd=_fileno(setup.par.fp);
	#endif
	if(setup.par.fd < 0){
		perror("FICHEIROopen");
		fprintf(stderr, "errno: %d\n", errno);
	}
}

/***FICHEIROclose***/
int FICHEIROclose(void)
{
	int r;
	if(setup.par.fp)
		r = fclose(setup.par.fp);
	else
		r = 0;
	return r;
}

/***FICHEIROgetc***/
int FICHEIROgetc(void)
{
	return getc(setup.par.fp);
}

/***FICHEIROfgets***/
char* FICHEIROfgets(char* buffer, size_t size)
{
	return fgets(buffer, size, setup.par.fp);
}
/***FICHEIROfputc***/
int FICHEIROfputc(int c)
{
	return fputc(c, setup.par.fp);
}

/***FICHEIROfputs***/
int FICHEIROfputs(const char* s)
{
	return fputs(s, setup.par.fp);
}

/***FICHEIROprintf***/
void FICHEIROprintf(const char* fmt, ...)
{
	va_list args;
    va_start(args, fmt);
	vfprintf(setup.par.fp, fmt, args);
	va_end(args);
}

/***FICHEIROread***/
size_t FICHEIROread(void *ptr, size_t size, size_t nmemb)
{
	return fread(ptr, size, nmemb, setup.par.fp);
}

/***FICHEIROwrite***/
size_t FICHEIROwrite(const void *ptr, size_t size, size_t nmemb)
{
	return fwrite(ptr, size, nmemb, setup.par.fp);
}

/***FICHEIROrewind***/
void FICHEIROrewind(void)
{
	rewind(setup.par.fp);
}

/***FICHEIROfilepointer***/
FILE* FICHEIROfilepointer(void)
{
	return setup.par.fp;
}
/***FICHEIROfiledescriptor***/
int FICHEIROfiledescriptor(void)
{
	return setup.par.fd;
}

/***setposition***/
int seekposition(int whence, long offset)
{
	int r;
    r = fseek(setup.par.fp, offset, whence);
    if(r){
        fprintf(stderr, "Error at seekposition: %d\n", errno);
    }else{
        fprintf(stderr, "At position: %ld\n",ftell(setup.par.fp));
    }
	return r;
}
/***EOF***/

