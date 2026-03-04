#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

struct clientsocket{
  int id, portno;
  struct sockaddr_in serv_addr;
  struct sockaddr_in6 serv_addr6;
  struct hostent* server;
  struct addrinfo addrCriteria;
  struct addrinfo *servAddr;
  //vtable
  int (*Close)(struct clientsocket* client);
  ssize_t (*Write)(struct clientsocket* client, void* buffer, size_t size);
  ssize_t (*Read)(struct clientsocket* client, void* buffer, size_t size);
  int (*SetOwner)(struct clientsocket* client, pid_t owner);
};

typedef struct clientsocket clientsocket;

clientsocket* clientsocketcreate(int domain,int type,int protocol, char* serverIP, char* portno);

#endif

