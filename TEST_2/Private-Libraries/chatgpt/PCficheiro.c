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
#include "PCficheiro.h"

/*
** variable
*/
int errno;
struct ficheiro *self = NULL;

/*
** procedure and function header
*/
void FICHEIROopen(const char* filename, const char* permission);
int FICHEIROclose(void);
int FICHEIROputc(int c);
int FICHEIROputs(const char* s);
int FICHEIROread(void* ptr, size_t size, size_t nmemb);
int FICHEIROwrite(const void* ptr, size_t size, size_t nmemb);
void FICHEIROrewind(void);
FILE* FICHEIROfilepointer(void);
int FICHEIROfiledescriptor(void);
int seekposition(int whence, long offset);

/*
** Object Initialize
*/
FICHEIRO FICHEIROenable(struct ficheiro *this) {
	// Assign global variable
	errno = 0;
	self = this;

	// Initialize function pointers
	FICHEIRO f = {
		.self = this,
		.open = FICHEIROopen,
		.close = FICHEIROclose,
		.putch = FICHEIROputc,
		.puts = FICHEIROputs,
		.read = FICHEIROread,
		.write = FICHEIROwrite,
		.rewind = FICHEIROrewind,
		.filepointer = FICHEIROfilepointer,
		.filedescriptor = FICHEIROfiledescriptor
	};

	return f; // Return initialized structure
}

/*
** Procedure and Function Implementations
*/

/*** FICHEIROopen ***/
void FICHEIROopen(const char *filename, const char *permission) {
	strcpy(self->filename, filename);
	strcpy(self->permision, permission);

	// Attempt to open the file
	self->fp = fopen(self->filename, self->permision);
	if (self->fp == NULL) {
		perror("Error opening file");
		strcpy(self->permision, "a+"); // Set default permission
		self->fp = fopen(self->filename, self->permision);
		if (self->fp == NULL) {
			perror("Error reopening file");
			return;
		}
	}

	printf("Opening file: %s\n", self->filename);
	#ifdef linux
		self->fd = fileno(self->fp);
	#elif _WIN32
		self->fd = _fileno(self->fp);
	#endif

	if (self->fd < 0) {
		perror("Error FICHEIROopen");
		self->errcode = errno;
	}
}

/* FICHEIROclose */
int FICHEIROclose(void) {
	if (fclose(self->fp) != 0) {
		printf("Error at FICHEIROclose\n");
		return 1;
	}
	return 0;
}

/* FICHEIROputc */
int FICHEIROputc(int c) {
	return fputc(c, self->fp);
}

/* FICHEIROputs */
int FICHEIROputs(const char* s) {
	return fputs(s, self->fp);
}

/*** FICHEIROread ***/
int FICHEIROread(void *ptr, size_t size, size_t nmemb) {
	return fread(ptr, size, nmemb, self->fp);
}

/*** FICHEIROwrite ***/
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb) {
	return fwrite(ptr, size, nmemb, self->fp);
}

/* FICHEIROrewind */
void FICHEIROrewind(void) {
	rewind(self->fp);
}

/*** FICHEIROfilepointer ***/
FILE* FICHEIROfilepointer(void) {
	return self->fp;
}

/*** FICHEIROfiledescriptor ***/
int FICHEIROfiledescriptor(void) {
	return self->fd;
}

/*** seekposition ***/
int seekposition(int whence, long offset) {
	int r = fseek(self->fp, offset, whence);
	if (r != 0) {
		printf("Error at seekposition: %d\n", errno);
	} else {
		printf("At position: %ld\n", ftell(self->fp));
	}
	return r;
}

/*
** EOF
*/
