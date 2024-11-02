#include "clientsocket.h"

struct clientsocket* clientsocketcreate(int domain, int type, int protocol, char* serverIP, char* portno) {
	struct clientsocket* client = (struct clientsocket*)calloc(1, sizeof(struct clientsocket));
	if (client == NULL) {
		perror("Failed to allocate memory for clientsocket");
		return NULL;
	}

	switch (type) {
		case SOCK_STREAM:
		case SOCK_DGRAM:
		case SOCK_SEQPACKET:
		case SOCK_RAW:
		case SOCK_RDM:
		case SOCK_PACKET:
		break;
		default:
		fprintf(stderr, "clientsocketcreate: unsupported socket type\n");
		free(client);
		return NULL;
	}

	switch (protocol) {
		case 0:
		case SOCK_NONBLOCK:
		case SOCK_CLOEXEC:
		case IPPROTO_TCP:
		break;
		default:
		fprintf(stderr, "clientsocketcreate: unsupported protocol\n");
		free(client);
		return NULL;
	}

	switch (domain) {
		case AF_LOCAL:
		client->serv_addr.sin_family = AF_LOCAL;
		break;
		case AF_INET:
		client->serv_addr.sin_family = AF_INET;
		client->server = gethostbyname(serverIP);
		if (client->server == NULL) {
			fprintf(stderr, "ERROR: no such host\n");
			free(client);
			return NULL;
		}
		memcpy(&client->serv_addr.sin_addr.s_addr, client->server->h_addr, client->server->h_length);
		if (portno == NULL) {
			fprintf(stderr, "ERROR: no port number provided\n");
			free(client);
			return NULL;
			} else {
			client->portno = atoi(portno);
			client->serv_addr.sin_port = htons(client->portno);
		}
		break;
		case AF_INET6:
		client->serv_addr6.sin6_family = AF_INET6;
		if (inet_pton(AF_INET6, serverIP, &client->serv_addr6.sin6_addr.s6_addr) <= 0) {
			perror("clientsocketcreate: inet_pton() failed");
			free(client);
			return NULL;
		}
		if (portno == NULL) {
			fprintf(stderr, "clientsocketcreate: no port number provided\n");
			free(client);
			return NULL;
			} else {
			client->portno = atoi(portno);
			client->serv_addr6.sin6_port = htons(client->portno);
		}
		break;
		default:
		fprintf(stderr, "clientsocketcreate: unsupported domain\n");
		free(client);
		return NULL;
	}

	client->id = socket(domain, type, protocol);
	if (client->id < 0) {
		perror("clientsocketcreate: ERROR opening socket");
		free(client);
		return NULL;
	}

	if (domain == AF_INET) {
		if (connect(client->id, (struct sockaddr*)&client->serv_addr, sizeof(client->serv_addr)) < 0) {
			perror("clientsocketcreate: ERROR connecting");
			free(client);
			return NULL;
		}
		} else if (domain == AF_INET6) {
		if (connect(client->id, (struct sockaddr*)&client->serv_addr6, sizeof(client->serv_addr6)) < 0) {
			perror("clientsocketcreate: ERROR connecting");
			free(client);
			return NULL;
		}
	}

	// Set up the vtable
	client->Close = clientsocketClose;
	client->Write = clientsocketWrite;
	client->Read = clientsocketRead;
	client->SetOwner = clientsocketSetOwner;

	return client;
}

int clientsocketClose(struct clientsocket* client) {
	int RETURN = close(client->id);
	if (RETURN < 0) {
		perror("clientsocketClose: ERROR closing socket");
	}
	free(client);
	printf("clientsocketClose: client shutdown\n");
	return RETURN;
}

ssize_t clientsocketWrite(struct clientsocket* client, void* buffer, size_t size) {
	ssize_t n = write(client->id, buffer, size);
	if (n < 0) {
		perror("clientsocketWrite: ERROR writing to socket");
	}
	return n;
}

ssize_t clientsocketRead(struct clientsocket* client, void* buffer, size_t size) {
	ssize_t n = read(client->id, buffer, size);
	if (n < 0) {
		perror("clientsocketRead: ERROR reading from socket");
	}
	return n;
}

int clientsocketSetOwner(struct clientsocket* client, pid_t owner) {
	int RETURN = fcntl(client->id, F_SETOWN, owner);
	if (RETURN < 0) {
		perror("clientsocketSetOwner: ERROR setting owner");
	}
	return RETURN;
}

/*** ReadConsole ***/
char* ReadConsole(FILE* stream) {
	int i = 0, NBytes = 4;
	char* value = (char*)calloc(NBytes, sizeof(char));
	if (value == NULL) {
		perror("ReadConsole: calloc failed");
		return NULL;
	}

	char caracter;
	while ((caracter = getc(stream)) != EOF) {
		if (i == NBytes) {
			NBytes *= 2;
			char* temp = realloc(value, NBytes * sizeof(char));
			if (temp == NULL) {
				perror("ReadConsole: realloc failed");
				free(value);
				return NULL;
			}
			value = temp;
		}
		value[i++] = caracter;
		if (caracter == '\n') {
			break;
		}
	}
	value[i] = '\0'; // Null-terminate the string
	return value;
}

/*** getnum ***/
unsigned int getnum(char* x) {
	unsigned int value;
	if (sscanf(x, "%u", &value) != 1) {
		perror("getnum: sscanf failed");
		return 0;
	}
	return value;
}

/*** Strtok ***/
int Strtok(char* line, char* token[], const char* parser) {
	int i = 0;
	char* str = strdup(line); // Using strdup for automatic memory allocation
	if (str == NULL) {
		perror("Strtok: strdup failed");
		return 0;
	}

	char* token_ptr = strtok(str, parser);
	while (token_ptr != NULL) {
		token[i++] = token_ptr;
		printf("%d: %s\n", i - 1, token_ptr);
		token_ptr = strtok(NULL, parser);
	}

	free(str); // Free the allocated string
	return i;
}
