#include "serversocket.h"

struct serversocket* serversocketcreate(int domain,int type,int protocol,char* serverIP,char* portno)
{
  int rtnVal;
  //PROTOTYPES
  void serversocketAccept(struct serversocket* server);
  ssize_t serversocketRead(struct serversocket* server, void* buffer, size_t size);
  ssize_t serversocketWrite(struct serversocket* server, void* buffer, size_t size);
  int serversocketClose(struct serversocket* server);
  int serversocketSetOwner(struct serversocket* server, pid_t owner);
  //
  struct serversocket* server;
  server=(struct serversocket*)calloc(1,sizeof(struct serversocket));
  
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
      fprintf(stderr,"serversocketcreate type not defined\n");
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
    case IPPROTO_UDP:
      break;
    default:
      fprintf(stderr,"serversocketcreate protocol not defined\n");
      exit (0);
  }
  switch(domain){
	
    case AF_LOCAL:
      server->serv_addr.sin_family = AF_LOCAL;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_LOCAL, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_INET:
      server->serv_addr.sin_family = AF_INET;
      rtnVal = inet_pton(AF_INET, serverIP, &server->serv_addr.sin_addr.s_addr);
      if (rtnVal == 0){
        perror("serversocketcreate at inet_pton() failed, invalid address string");
        exit(0);
      }else if (rtnVal < 0){
        perror("serversocketcreate at inet_pton() failed");
        exit(0);
      }
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_INET, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      serversocketSetOwner(server, getpid());
      break;
     case AF_INET6:
      server->serv_addr.sin_family = AF_INET6;
      server->serv_addr6.sin6_family = AF_INET6;
      //server->serv_addr6.sin6_addr.s6_addr = in6addr_any;//serverIP
      rtnVal = inet_pton(AF_INET6, serverIP, &server->serv_addr6.sin6_addr.s6_addr);
      if (rtnVal == 0){
        perror("serversocketcreate at inet_pton() failed, invalid address string");
        exit(0);
      }else if (rtnVal < 0){
        perror("serversocketcreate at inet_pton() failed");
        exit(0);
      }
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr6.sin6_port = htons(server->portno);
      }
      server->id = socket(AF_INET6, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr*) &server->serv_addr6, sizeof(server->serv_addr6)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      serversocketSetOwner(server, getpid());
      break;
    case AF_IPX:
      server->serv_addr.sin_family = AF_IPX;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_IPX, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_NETLINK:
      server->serv_addr.sin_family = AF_NETLINK;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_NETLINK, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_X25:
      server->serv_addr.sin_family = AF_X25;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_X25, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_ATMPVC:
      server->serv_addr.sin_family = AF_ATMPVC;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_ATMPVC, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_APPLETALK:
      server->serv_addr.sin_family = AF_APPLETALK;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_APPLETALK, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    case AF_PACKET:
      server->serv_addr.sin_family = AF_PACKET;
      server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
      if (portno == NULL){
        fprintf(stderr,"serversocketcreate at ERROR, no such portno\n");
        exit(0);
      }else{ 
        server->portno = atoi(portno);
        server->serv_addr.sin_port = htons(server->portno);
      }
      server->id = socket(AF_PACKET, type, protocol);
      if (server->id < 0){ 
        perror("serversocketcreate at ERROR opening socket");
        exit(0);
      }
      //apply struct to filedescriptor
      if (bind(server->id, (struct sockaddr *) &server->serv_addr, sizeof(server->serv_addr)) < 0){
        perror("serversocketcreate at ERROR on binding");
        exit(0);
      }
      break;
    default :
      fprintf(stderr,"serversocketcreate domain not defined\n");
      exit (0);
  }
  //listening
  listen(server->id,5);
  //vtable
  server->Accept=serversocketAccept;
  server->Read=serversocketRead;
  server->Write=serversocketWrite;
  server->Close=serversocketClose;
  server->SetOwner=serversocketSetOwner;
  return server;
}

void serversocketAccept(struct serversocket* server)
{
  switch(server->serv_addr.sin_family){
    case AF_LOCAL:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_INET:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_INET6:
      server->clilen = sizeof(server->cli_addr6);
      server->clid = accept(server->id, (struct sockaddr*) &server->cli_addr6, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_IPX:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_NETLINK:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_X25:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_ATMPVC:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_APPLETALK:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    case AF_PACKET:
      server->clilen = sizeof(server->cli_addr);
      server->clid = accept(server->id, (struct sockaddr *) &server->cli_addr, &server->clilen);
      if (server->clid < 0) 
        perror("Accept at ERROR on accept");
      break;
    default:
      fprintf(stderr,"Accept domain not defined\n");
      exit (0);
  }
}

ssize_t serversocketWrite(struct serversocket* server, void* buffer, size_t size){
  ssize_t n;
  n = write(server->clid,buffer,size);
  if (n < 0) 
    perror("Write at write");
  return n;
}

ssize_t serversocketRead(struct serversocket* server, void* buffer, size_t size)
{
  ssize_t n;
  n = read(server->clid,buffer,size);
  if (n < 0) 
    perror("Read at read");
  return n;
}

int serversocketClose(struct serversocket* server)
{
  int RETURN;
  RETURN=close(server->clid);
  if(RETURN<0)
    perror("Close at close");
  RETURN=close(server->id);
  if(RETURN<0)
    perror("Close at close");
  free(server);
  printf("Close at server shutdown!\n");
  return RETURN;
}

int serversocketSetOwner(struct serversocket* server, pid_t owner){
  int RETURN;
  RETURN=fcntl(server->id, F_SETOWN, owner);
  if (RETURN < 0){
    perror("Owner at Unable to set process to owner");
  }
  return RETURN;
}
/***ftos***/
char* ftos(FILE* stream)
{
  int i, NBytes;
  char caracter;
  char* value=NULL;
  for(i=0, NBytes=4; (caracter=getc(stream)) != EOF; i++){
    if((i==0) | (i==NBytes)){
      NBytes=2*NBytes;
      value=(char*)realloc(value, NBytes*sizeof(char));
      if(value==NULL){
        perror("ReadConsole at calloc");
        break;
      }
    }
    *(value+i)=caracter;
  }
  return value;
}
//fltos
char* fltos(FILE* stream)
{
  int i, NBytes;
  char caracter;
  char* value=NULL;
  for(i=0, NBytes=4; (caracter=getc(stream)) != EOF; i++){
    if((i==0) | (i==NBytes)){
      NBytes=2*NBytes;
      value=(char*)realloc(value, NBytes*sizeof(char));
      if(value==NULL){
        perror("ReadConsole at calloc");
        break;
      }
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

