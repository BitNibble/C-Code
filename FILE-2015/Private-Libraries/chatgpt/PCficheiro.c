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
** Structure for file handling
*/
struct ficheiro {
    char filename[256];
    char permision[4];
    FILE *fp;
    int fd;
    int errcode;
};

/*
** Function pointer structure for file operations
*/
typedef struct FICHEIRO {
    struct ficheiro *self;
    void (*open)(const char *filename, const char *permision);
    int (*close)(void);
    int (*putch)(int c);
    int (*puts)(const char *s);
    int (*read)(void *ptr, size_t size, size_t nmemb);
    int (*write)(const void *ptr, size_t size, size_t nmemb);
    void (*rewind)(void);
    FILE* (*filepointer)(void);
    int (*filedescriptor)(void);
    int (*seek)(int whence, long offset);
} FICHEIRO;

/*
** Global Error variable
*/
int errno;

/*
** Object Initialization
*/
FICHEIRO FICHEIROenable(struct ficheiro *this) {
    // Assign self
    FICHEIRO f;
    f.self = this;

    // Initialize function pointers
    f.open = FICHEIROopen;
    f.close = FICHEIROclose;
    f.putch = FICHEIROputc;
    f.puts = FICHEIROputs;
    f.read = FICHEIROread;
    f.write = FICHEIROwrite;
    f.rewind = FICHEIROrewind;
    f.filepointer = FICHEIROfilepointer;
    f.filedescriptor = FICHEIROfiledescriptor;
    f.seek = seekposition;

    return f;
}

/*
** File Operations
*/

/*** FICHEIROopen ***/
void FICHEIROopen(const char *filename, const char *permision) {
    // Initialize variables
    strcpy(self->filename, filename);
    strcpy(self->permision, permision);

    // Attempt to open the file
    self->fp = fopen(self->filename, self->permision);
    if (!self->fp) {
        perror("Error opening file");
        // Try to open with default permission if initial open failed
        strcpy(self->permision, "a+");
        self->fp = fopen(self->filename, self->permision);
        if (!self->fp) {
            perror("Error reopening file");
            self->errcode = errno;
            return;
        }
        printf("Reopened file: %s with default permission\n", self->filename);
    } else {
        printf("Opened file: %s\n", self->filename);
    }

#ifdef linux
    self->fd = fileno(self->fp);
#elif _WIN32
    self->fd = _fileno(self->fp);
#endif

    if (self->fd < 0) {
        perror("Error getting file descriptor");
        self->errcode = errno;
    }
}

/* FICHEIROclose */
int FICHEIROclose(void) {
    if (self->fp && fclose(self->fp) != 0) {
        perror("Error closing file");
        return 1;
    }
    self->fp = NULL; // Reset file pointer after closing
    return 0;
}

/* FICHEIROputc */
int FICHEIROputc(int c) {
    return fputc(c, self->fp);
}

/* FICHEIROputs */
int FICHEIROputs(const char *s) {
    return fputs(s, self->fp);
}

/* FICHEIROread */
int FICHEIROread(void *ptr, size_t size, size_t nmemb) {
    return fread(ptr, size, nmemb, self->fp);
}

/* FICHEIROwrite */
int FICHEIROwrite(const void *ptr, size_t size, size_t nmemb) {
    return fwrite(ptr, size, nmemb, self->fp);
}

/* FICHEIROrewind */
void FICHEIROrewind(void) {
    rewind(self->fp);
}

/* FICHEIROfilepointer */
FILE* FICHEIROfilepointer(void) {
    return self->fp;
}

/* FICHEIROfiledescriptor */
int FICHEIROfiledescriptor(void) {
    return self->fd;
}

/* seekposition */
int seekposition(int whence, long offset) {
    int result = fseek(self->fp, offset, whence);
    if (result != 0) {
        perror("Error seeking position");
    } else {
        printf("Current position: %ld\n", ftell(self->fp));
    }
    return result;
}

/*
** EOF
*/
