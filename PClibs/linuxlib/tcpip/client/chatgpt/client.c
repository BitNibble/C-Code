#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include "clientsocket.h"

int main(int argc, char *argv[])
{
	char obuffer[256];
	char ibuffer[256];

	if (argc < 3) {
		fprintf(stderr, "usage: %s hostname port\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	struct clientsocket* client;
	client = clientsocketcreate(AF_INET, SOCK_STREAM, 0, argv[1], argv[2]);
	if (client == NULL) {
		fprintf(stderr, "Failed to create client socket\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Please enter the message: ");
	memset(obuffer, 0, sizeof(obuffer));
	memset(ibuffer, 0, sizeof(ibuffer));
	
	if (fgets(obuffer, sizeof(obuffer) - 1, stdin) == NULL) {
		perror("Error reading input");
		client->Close(client);
		exit(EXIT_FAILURE);
	}

	ssize_t bytes_written = client->Write(client, obuffer, strlen(obuffer));
	if (bytes_written < 0) {
		fprintf(stderr, "Failed to write to socket\n");
		client->Close(client);
		exit(EXIT_FAILURE);
	}

	ssize_t bytes_read = client->Read(client, ibuffer, sizeof(ibuffer) - 1);
	if (bytes_read < 0) {
		fprintf(stderr, "Failed to read from socket\n");
		client->Close(client);
		exit(EXIT_FAILURE);
	}

	printf("Received: %s\n", ibuffer);
	client->Close(client);
	return 0;
}
