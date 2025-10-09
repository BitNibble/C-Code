#ifndef _SERVERSOCKET_H
#define _SERVERSOCKET_H
/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define TRUE 1

struct serversocket{
  int id, clid, portno;
  socklen_t clilen;
  struct sockaddr_in serv_addr, cli_addr;
  struct sockaddr_in6 serv_addr6, cli_addr6;
  struct addrinfo addrCriteria;
  struct addrinfo *servAddr;
  //vtable
  void (*Accept)(struct serversocket* server);
  int (*Close)(struct serversocket* server);
  ssize_t (*Write)(struct serversocket* server, void* buffer, size_t size);
  ssize_t (*Read)(struct serversocket* server, void* buffer, size_t size);
  int (*SetOwner)(struct serversocket* server, pid_t owner);
};

typedef struct serversocket serversocket;

struct serversocket* serversocketcreate(int domain,int type,int protocol, char* serverIP, char* portno);

#endif
