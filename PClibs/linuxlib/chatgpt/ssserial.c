#include "ssserial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <termios.h>

// Function Prototypes
int serialConfigDefault(struct serial* ser);
int serialConfignew(struct serial* ser, unsigned int c_cflag, unsigned int c_iflag, unsigned int c_oflag, unsigned int c_lflag);
int serialSetold(struct serial* ser);
int serialSetnew(struct serial* ser);
int serialGetold(struct serial* ser);
int serialGetnew(struct serial* ser);
ssize_t serialWrite(struct serial* ser, const void* buf, size_t count);
ssize_t serialRead(struct serial* ser, void* buf, size_t count);
int serialIOflush(struct serial* ser);
int serialRequest(struct serial* ser, int request, char* argp);
int serialSetOwner(struct serial* ser, pid_t owner);

struct serial* SerialCreate(int filedescriptorid) {
	// Memory allocation for serial structure
	struct serial* ser = (struct serial*)calloc(1, sizeof(struct serial));
	if (ser == NULL) {
		perror("SerialCreate at calloc");
		return NULL;  // Return NULL to indicate failure
	}

	// Initialize variables
	ser->c = 0;
	errno = 0;
	ser->id = filedescriptorid;
	sprintf(ser->errcode, "None errno: %d\n", errno);

	// Assign function pointers
	ser->ConfigDefault = serialConfigDefault;
	ser->Confignew = serialConfignew;
	ser->Setold = serialSetold;
	ser->Setnew = serialSetnew;
	ser->Getold = serialGetold;
	ser->Getnew = serialGetnew;
	ser->Write = serialWrite;
	ser->Read = serialRead;
	ser->IOflush = serialIOflush;
	ser->Request = serialRequest;
	ser->SetOwner = serialSetOwner;

	// Save old configuration
	if (tcgetattr(ser->id, &ser->oldtio) < 0) {
		perror("SerialCreate at tcgetattr");
		sprintf(ser->errcode, "SerialCreate at tcgetattr errno: %d\n", errno);
		free(ser);  // Clean up memory on error
		return NULL;
	}

	// Initialize newtio structure
	memset(&ser->newtio, 0, sizeof(ser->newtio));
	return ser;
}

int serialConfigDefault(struct serial* ser) {
	// Set default configurations
	ser->newtio.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
	ser->newtio.c_iflag = ICRNL | IXON;
	ser->newtio.c_oflag = OPOST | ONLCR;
	ser->newtio.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

	// Control characters initialization
	ser->newtio.c_cc[VINTR] = 3;
	ser->newtio.c_cc[VQUIT] = 28;
	ser->newtio.c_cc[VERASE] = 127;
	ser->newtio.c_cc[VKILL] = 21;
	ser->newtio.c_cc[VEOF] = 4;
	ser->newtio.c_cc[VTIME] = 0;
	ser->newtio.c_cc[VMIN] = 1;
	ser->newtio.c_cc[VSTART] = 17;
	ser->newtio.c_cc[VSTOP] = 19;
	ser->newtio.c_cc[VSUSP] = 26;
	ser->newtio.c_cc[VREPRINT] = 18;
	ser->newtio.c_cc[VDISCARD] = 15;
	ser->newtio.c_cc[VWERASE] = 23;
	ser->newtio.c_cc[VLNEXT] = 22;

	return 0;
}

int serialConfignew(struct serial* ser, unsigned int c_cflag, unsigned int c_iflag, unsigned int c_oflag, unsigned int c_lflag) {
	// Set new configurations
	ser->newtio.c_iflag = c_iflag;
	ser->newtio.c_oflag = c_oflag;
	ser->newtio.c_cflag = c_cflag;
	ser->newtio.c_lflag = c_lflag;

	// Control characters initialization
	ser->newtio.c_cc[VINTR] = 3;
	ser->newtio.c_cc[VQUIT] = 0;
	ser->newtio.c_cc[VERASE] = 0;
	ser->newtio.c_cc[VKILL] = 0;
	ser->newtio.c_cc[VEOF] = 0;
	ser->newtio.c_cc[VTIME] = 0;
	ser->newtio.c_cc[VMIN] = 1;
	ser->newtio.c_cc[VSTART] = 0;
	ser->newtio.c_cc[VSTOP] = 0;
	ser->newtio.c_cc[VSUSP] = 0;

	return 0;
}

int serialSetold(struct serial* ser) {
	if (tcflush(ser->id, TCIFLUSH) != 0) {
		perror("Setold at tcflush");
		sprintf(ser->errcode, "Setold at tcflush errno: %d\n", errno);
		return -1;
	}
	if (tcsetattr(ser->id, TCSANOW, &ser->oldtio) != 0) {
		perror("Setold at tcsetattr");
		sprintf(ser->errcode, "Setold at tcsetattr errno: %d\n", errno);
		return -1;
	}
	return 0;
}

int serialSetnew(struct serial* ser) {
	if (tcflush(ser->id, TCIFLUSH) != 0) {
		perror("Setnew at tcflush");
		sprintf(ser->errcode, "Setnew at tcflush errno: %d\n", errno);
		return -1;
	}
	if (tcsetattr(ser->id, TCSANOW, &ser->newtio) != 0) {
		perror("Setnew at tcsetattr");
		sprintf(ser->errcode, "Setnew at tcsetattr errno: %d\n", errno);
		if (tcsetattr(ser->id, TCSANOW, &ser->oldtio) != 0) {
			perror("Setnew at tcsetattr (restoring)");
			sprintf(ser->errcode, "Setnew at tcsetattr (restoring) errno: %d\n", errno);
		}
		return -1;
	}
	return 0;
}

int serialGetold(struct serial* ser) {
	printf("Old configuration:\n");
	printf("c_iflag: %u\n", ser->oldtio.c_iflag);
	printf("c_oflag: %u\n", ser->oldtio.c_oflag);
	printf("c_cflag: %u\n", ser->oldtio.c_cflag);
	printf("c_lflag: %u\n", ser->oldtio.c_lflag);
	for (int i = 0; i < NCCS; i++) {
		printf("c_cc[%d]: %u\n", i, ser->oldtio.c_cc[i]);
	}
	return 0;
}

int serialGetnew(struct serial* ser) {
	printf("New configuration:\n");
	printf("c_iflag: %u\n", ser->newtio.c_iflag);
	printf("c_oflag: %u\n", ser->newtio.c_oflag);
	printf("c_cflag: %u\n", ser->newtio.c_cflag);
	printf("c_lflag: %u\n", ser->newtio.c_lflag);
	for (int i = 0; i < NCCS; i++) {
		printf("c_cc[%d]: %u\n", i, ser->newtio.c_cc[i]);
	}
	return 0;
}

ssize_t serialWrite(struct serial* ser, const void* buf, size_t count) {
	ssize_t written = write(ser->id, buf, count);
	if (written < 0) {
		perror("serialWrite");
		sprintf(ser->errcode, "serialWrite errno: %d\n", errno);
	}
	return written;  // Return the number of bytes written
}

ssize_t serialRead(struct serial* ser, void* buf, size_t count) {
	ssize_t read_bytes = read(ser->id, buf, count);
	if (read_bytes < 0) {
		perror("serialRead");
		sprintf(ser->errcode, "serialRead errno: %d\n", errno);
	}
	return read_bytes;  // Return the number of bytes read
}

int serialIOflush(struct serial* ser) {
	if (tcflush(ser->id, TCIOFLUSH) != 0) {
		perror("serialIOflush");
		sprintf(ser->errcode, "serialIOflush errno: %d\n", errno);
		return -1;
	}
	return 0;
}

int serialRequest(struct serial* ser, int request, char* argp) {
	int status = ioctl(ser->id, request, argp);
	if (status < 0) {
		perror("serialRequest");
		sprintf(ser->errcode, "serialRequest errno: %d\n", errno);
		return -1;
	}
	return 0; // Return success
}

int serialSetOwner(struct serial* ser, pid_t owner) {
	// Example usage, change according to your requirements
	if (setpgrp(0, owner) < 0) {
		perror("serialSetOwner");
		sprintf(ser->errcode, "serialSetOwner errno: %d\n", errno);
		return -1;
	}
	return 0; // Return success
}

void SerialDestroy(struct serial* ser) {
	if (ser != NULL) {
		serialSetold(ser);  // Restore old settings
		free(ser);          // Free allocated memory
	}
}
