#include "clientsocket.h"

int main(int argc, char *argv[])
{
  char obuffer[256];
  char ibuffer[256];  

  if (argc < 3){
    fprintf(stderr,"usage %s hostname port\n", argv[0]);
    exit(0);
  }
  
  clientsocket* client;
  client=clientsocketcreate(AF_INET, SOCK_STREAM, 0, argv[1], argv[2]);
  
  printf("Please enter the message: ");
  bzero(obuffer,256);
  memset(ibuffer,0,256);
  fgets(obuffer,255,stdin);
  client->Write(client,obuffer,strlen(obuffer));
  client->Read(client,ibuffer,255);
  printf("%s\n",(char*)ibuffer);
  client->Close(client);
  return 0;
}

