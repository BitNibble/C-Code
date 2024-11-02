/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "serversocket.h"

#define BUFFER_SIZE 256

char* ftos(FILE* stream);

int main(int argc, char *argv[])
{
    char obuffer[BUFFER_SIZE];
    char ibuffer[BUFFER_SIZE];
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s servIP portno\n", argv[0]);
        exit(1);
    }
  
    FILE *fp = fopen("file.txt", "r");
    if (fp == NULL) {
        perror("Failed to open file");
        exit(1);
    }
  
    printf("File:\n%s\n", ftos(fp));
    fclose(fp);  // Close the file after reading

    serversocket* server = serversocketcreate(AF_INET, SOCK_STREAM, IPPROTO_TCP, argv[1], argv[2]);
    if (server == NULL) {
        perror("Failed to create server socket");
        exit(1);
    }

    server->SetOwner(server, getpid());
  
    while (1) {
        server->Accept(server);
      
        bzero(obuffer, BUFFER_SIZE);
        bzero(ibuffer, BUFFER_SIZE);
        if (server->Read(server, ibuffer, BUFFER_SIZE) < 0) {
            perror("Failed to read from socket");
            continue;  // Handle read error and continue
        }
        
        printf("server received: %s\n", ibuffer);
        server->Write(server, "received message from client\n", 32);
    }

    server->Close(server);
    return 0; 
}

// Example implementation of ftos function
char* ftos(FILE* stream) {
    static char buffer[BUFFER_SIZE]; // Make sure this is large enough
    size_t bytesRead = fread(buffer, sizeof(char), BUFFER_SIZE - 1, stream);
    buffer[bytesRead] = '\0'; // Null-terminate the string
    return buffer;
}
