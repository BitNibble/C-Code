#include "clientsocket.h"

struct clientsocket* clientsocketcreate(int domain,int type,int protocol, char* serverIP, char* portno)
{ 
  int rtnVal;
  //PROTOTYPES
  ssize_t clientsocketWrite(struct clientsocket* client, void* buffer, size_t size);
  ssize_t clientsocketRead(struct clientsocket* client, void* buffer, size_t size);
  int clientsocketClose(struct clientsocket* client);
  int clientsocketSetOwner(struct clientsocket* client, pid_t owner);
  //
  struct clientsocket* client;
  client=(struct clientsocket*)calloc(1,sizeof(struct clientsocket));
  switch(type){
    case SOCK_STREAM:
      break;
    case SOCK_DGRAM:
      break;
    case SOCK_SEQPACKET:
      break;
    case SOCK_RAW:
      break;
    case SOCK_RDM:
      break;
    case SOCK_PACKET:
      break;
    default:
      fprintf(stderr,"clientsocketcreate type not defined\n");
      exit (0);
  }
  switch(protocol){
    case 0:
      break;    
    case SOCK_NONBLOCK:
      break;
    case SOCK_CLOEXEC:
      break;
    case IPPROTO_TCP:
      break;
    default:
      fprintf(stderr,"clientsocketcreate protocol not defined\n");
      exit (0);
  }
  switch(domain){
    case AF_LOCAL:
      client->serv_addr.sin_family = AF_LOCAL;
      //waiting
      break;
    case AF_INET:
      client->serv_addr.sin_family = AF_INET;
      client->server=gethostbyname(serverIP);
      if (client->server == NULL){
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
      }
      bcopy((char*)client->server->h_addr,(char *)&client->serv_addr.sin_addr.s_addr,client->server->h_length);
      if(portno == NULL){
        fprintf(stderr,"ERROR, no such portno\n");
        exit(0);
      }else{ 
        client->portno = atoi(portno);
        client->serv_addr.sin_port = htons(client->portno);
      }
      client->id = socket(AF_INET, type, protocol);
      if(client->id < 0){ 
        perror("clientsocketcreate ERROR opening socket");
        exit(0);
      }
      if(connect(client->id,(struct sockaddr*) &client->serv_addr,sizeof(client->serv_addr)) < 0){
        perror("clientsocketcreate ERROR connecting");
        exit(0);
      }   
      break;
    case AF_INET6:
      client->serv_addr6.sin6_family = AF_INET6;
      rtnVal = inet_pton(AF_INET6, serverIP, &client->serv_addr6.sin6_addr.s6_addr);
      if (rtnVal == 0){
        perror("clientsocketcreate at inet_pton() failed, invalid address string");
        exit(0);
      }else if (rtnVal < 0){
        perror("clientsocketcreate at inet_pton() failed");
        exit(0);
      }
      if(portno == NULL){
        fprintf(stderr,"clientsocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        client->portno = atoi(portno);
        client->serv_addr6.sin6_port = htons(client->portno);
      }
      client->id = socket(AF_INET6, type, protocol);
      if(client->id < 0){ 
        perror("clientsocketcreate ERROR opening socket");
        exit(0);
      }
      if(connect(client->id,(struct sockaddr*) &client->serv_addr6,sizeof(client->serv_addr6)) < 0){
        perror("clientsocketcreate ERROR connecting");
        exit(0);
      }
      break;
    case AF_IPX:
      client->serv_addr.sin_family = AF_IPX;
      //await
      break;
    case AF_NETLINK:
      client->serv_addr.sin_family = AF_NETLINK;
      //await
      break;
    case AF_X25:
      client->serv_addr.sin_family = AF_X25;
      //await
      break;
    case AF_ATMPVC:
      client->serv_addr.sin_family = AF_ATMPVC;
      //await
      break;
    case AF_APPLETALK:
      client->serv_addr.sin_family = AF_APPLETALK;
      //await
      break;
    case AF_PACKET:
      client->serv_addr.sin_family = AF_PACKET;
      //await
      break;
    default:
      fprintf(stderr,"clientsocketcreate domain not defined\n");
      exit (0);
  }
  //vtable
  client->Close=clientsocketClose;
  client->Write=clientsocketWrite;
  client->Read=clientsocketRead;
  client->SetOwner=clientsocketSetOwner;
  return client;
}

int clientsocketClose(struct clientsocket* client)
{
  int RETURN;
  RETURN=close(client->id);
  if(RETURN<0)
    perror("Close at close");
  free(client);
  printf("Close at client shutdown!\n");
  return RETURN;
}

ssize_t clientsocketWrite(struct clientsocket* client, void* buffer, size_t size){
  ssize_t n;
  n = write(client->id,buffer,size);
  if (n < 0) 
    perror("Write at write");
  return n;
}

ssize_t clientsocketRead(struct clientsocket* client, void* buffer, size_t size)
{
  ssize_t n;
  n = read(client->id,buffer,size);
  if (n < 0) 
    perror("Read at read");
  return n;
}

int clientsocketSetOwner(struct clientsocket* client, pid_t owner){
  int RETURN;
  RETURN=fcntl(client->id, F_SETOWN, owner);
  if (RETURN < 0){
    perror("Owner at Unable to set process to owner");
  }
  return RETURN;
}

/***ReadConsole***/
char* ReadConsole(FILE* stream)
{
  int i, NBytes;
  char caracter;
  char* value=NULL;
  for(i=0, NBytes=4; (caracter=getc(stream)) != EOF; i++){
    if((i==0) | (i==NBytes)){
      NBytes=2*NBytes;
      value=(char*)realloc(value, NBytes*sizeof(char));
      if(value==NULL)
        perror("ReadConsole at calloc");
    }
    *(value+i)=caracter;
    if(caracter=='\n'){
      *(value+i)='\0';
      break;
    }
  }
  return value;
}
/***getnum***/
unsigned int getnum(char* x)
{
  unsigned int RETURN;
  unsigned int value;
  unsigned int n;
  errno=0;
  n=sscanf(x,"%d",&value);
  if(n==1){
    RETURN=value;
  }else if(errno != 0){
    perror("getnum at sscanf");
    RETURN=0;
  }else{
    RETURN=0;
  }
  return RETURN;
}
/**/
int Strtok(char* line,char* token[],const char* parser)
{
  int i;
  char* str;
  str=calloc(strlen(line),sizeof(char));
  for (i = 0, strcpy(str,line); ; i++, str = NULL) {
    token[i] = strtok(str, parser);
    if (token[i] == NULL)
      break;
    printf("%d: %s\n", i, token[i]);
  }
  free(str);
  return i;
}
/**/
