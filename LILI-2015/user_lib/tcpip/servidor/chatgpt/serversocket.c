#include "serversocket.h"

// Helper function to create and bind the socket
static int create_and_bind_socket(struct serversocket* server, int domain, int type, int protocol) {
	server->id = socket(domain, type, protocol);
	if (server->id < 0) {
		perror("Error opening socket");
		return -1;
	}
	
	if (bind(server->id, (struct sockaddr *)&server->serv_addr, sizeof(server->serv_addr)) < 0) {
		perror("Error on binding");
		return -1;
	}
	
	return 0;
}

struct serversocket* serversocketcreate(int domain, int type, int protocol, char* serverIP, char* portno) {
	struct serversocket* server = (struct serversocket*)calloc(1, sizeof(struct serversocket));
	if (server == NULL) {
		perror("Failed to allocate memory for serversocket");
		exit(1);
	}

	// Set socket domain
	switch (domain) {
		case AF_LOCAL:
		server->serv_addr.sin_family = AF_LOCAL;
		server->serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
		break;
		case AF_INET:
		server->serv_addr.sin_family = AF_INET;
		if (inet_pton(AF_INET, serverIP, &server->serv_addr.sin_addr.s_addr) <= 0) {
			perror("Invalid IPv4 address");
			free(server);
			return NULL;
		}
		break;
		case AF_INET6:
		server->serv_addr6.sin6_family = AF_INET6;
		if (inet_pton(AF_INET6, serverIP, &server->serv_addr6.sin6_addr.s6_addr) <= 0) {
			perror("Invalid IPv6 address");
			free(server);
			return NULL;
		}
		break;
		// Handle additional protocols here...
		default:
		fprintf(stderr, "Domain not defined\n");
		free(server);
		return NULL;
	}

	// Set port number
	if (portno == NULL) {
		fprintf(stderr, "Error: no such portno\n");
		free(server);
		return NULL;
	}
	
	server->portno = atoi(portno);
	if (domain == AF_INET) {
		server->serv_addr.sin_port = htons(server->portno);
		} else if (domain == AF_INET6) {
		server->serv_addr6.sin6_port = htons(server->portno);
	}
	
	// Create and bind the socket
	if (create_and_bind_socket(server, domain, type, protocol) < 0) {
		free(server);
		return NULL;
	}

	// Listening
	listen(server->id, 5);

	// vtable
	server->Accept = serversocketAccept;
	server->Read = serversocketRead;
	server->Write = serversocketWrite;
	server->Close = serversocketClose;
	server->SetOwner = serversocketSetOwner;

	return server;
}

void serversocketAccept(struct serversocket* server) {
	server->clilen = (server->serv_addr.sin_family == AF_INET6) ? sizeof(server->cli_addr6) : sizeof(server->cli_addr);
	server->clid = accept(server->id, (struct sockaddr *)((server->serv_addr.sin_family == AF_INET6) ? (void*)&server->cli_addr6 : (void*)&server->cli_addr), &server->clilen);
	if (server->clid < 0) {
		perror("Error on accept");
	}
}
