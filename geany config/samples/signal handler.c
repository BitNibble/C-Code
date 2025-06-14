#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#define  ONE_K  1024
#define OUT_OF_STORAGE       (SIGUSR1)
/* The SIGNAL macro does a signal() checking the return code */
#define SIGNAL(SIG, StrCln)       {                    \
  if (signal((SIG), (StrCln)) == SIG_ERR) {            \
    perror("Could not signal user signal");            \
    abort();                                           \
  }                                                    \
}
 
void StrCln(int);
void DoWork(char **, int);
 
int main(int argc, char *argv[]) {
  int size;
  char *buffer;
  SIGNAL(OUT_OF_STORAGE, StrCln);
  if (argc != 2) {
    printf("Syntax: %s size \n", argv[0]);
    return(-1);
  }
  size = atoi(argv[1]);
  DoWork(&buffer, size);
  return(0);
}
 
void StrCln(int SIG_TYPE) {
  printf("Failed trying to malloc storage\n");
  SIGNAL(SIG_TYPE, SIG_DFL);
  exit(0);
}
 
void DoWork(char **buffer, int size) {
  int rc;
  *buffer = malloc(size*ONE_K);    /* get the size in number of K */
  if (*buffer == NULL) {
     if (raise(OUT_OF_STORAGE)) {
        perror("Could not raise user signal");
        abort();
     }
  }
  return;
}
/*  This is a program fragment and not a complete function example  */

