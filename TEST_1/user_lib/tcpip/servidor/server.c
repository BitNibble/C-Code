/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include "serversocket.h"

char* ftos(FILE* stream);

int main(int argc, char *argv[])
{
  char obuffer[256];
  char ibuffer[256];
  if (argc < 3) {
    fprintf(stderr,"Usage %s servIP portno\n", argv[0]);
    exit(1);
  }
  
  FILE *fp;
  fp=fopen("file.txt","r");
  
  printf("File:\n%s\n",ftos(fp));

  serversocket* server=serversocketcreate(AF_INET,SOCK_STREAM,IPPROTO_TCP,argv[1],argv[2]);
  //
  server->SetOwner(server,getpid());
  
  while(TRUE){
  server->Accept(server);
  
  bzero(obuffer,256);
  bzero(ibuffer,256);
  server->Read(server,ibuffer,256);
  printf("server received: %s\n",ibuffer);
  server->Write(server,"received message from cliente\n",32);
  
  }

  server->Close(server);
  return 0; 
}

