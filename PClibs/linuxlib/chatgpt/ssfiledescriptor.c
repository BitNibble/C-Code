#include "ssfiledescriptor.h"

struct filedescriptor* FileDescriptorCreate(const char* pathname, int flags, mode_t mode)
{
	// Allocate memory for the filedescriptor structure
	struct filedescriptor* fd = (struct filedescriptor*)calloc(1, sizeof(struct filedescriptor));
	if (fd == NULL) {
		perror("FileDescriptorCreate at calloc");
		return NULL; // Return NULL on failure
	}

	// Initialize variables
	fd->FDpathname = pathname;
	fd->FDflags = flags;
	fd->FDmode = mode;
	sprintf(fd->errcode, "None errno: %d\n", errno);

	// Set function pointers
	fd->GetFDpath = filedescriptorGetFDpath;
	fd->Write = filedescriptorWrite;
	fd->ID = filedescriptorID;
	fd->Close = filedescriptorClose;
	fd->Setoffset = filedescriptorSetoffset;
	fd->Setend = filedescriptorSetend;
	fd->Setendoffset = filedescriptorSetendoffset;
	fd->Getpos = filedescriptorGetpos;
	fd->Read = filedescriptorRead;
	fd->SetDefault = filedescriptorSetDefault;
	fd->SetFLflags = filedescriptorSetFLflags;
	fd->SetFDflags = filedescriptorSetFDflags;
	fd->GetFLflags = filedescriptorGetFLflags;
	fd->GetFDflags = filedescriptorGetFDflags;
	fd->GetFDmode = filedescriptorGetFDmode;
	fd->Request = filedescriptorRequest;
	fd->Rewind = filedescriptorRewind;
	fd->SetOwner = filedescriptorSetOwner;

	// Open the file and handle errors
	fd->id = open(fd->FDpathname, fd->FDflags, fd->FDmode);
	if (fd->id < 0) {
		perror("FileDescriptorCreate at open");
		sprintf(fd->errcode, "FileDescriptorCreate at open errno: %d\n", errno);
		free(fd);
		return NULL; // Return NULL on failure
	}

	if (fcntl(fd->id, F_SETFL, 0) < 0) {
		perror("FileDescriptorCreate at fcntl");
		sprintf(fd->errcode, "FileDescriptorCreate at fcntl errno: %d\n", errno);
		} else {
		fd->FLflags = 0; // Default file status flags
	}

	return fd;
}

int filedescriptorID(struct filedescriptor* fd)
{
	return fd->id;
}

int filedescriptorClose(struct filedescriptor* fd)
{
	int result = close(fd->id);
	if (result < 0) {
		perror("Close at close");
		sprintf(fd->errcode, "Close at close errno: %d\n", errno);
	}
	free(fd); // Free the filedescriptor structure
	return result;
}

const char* filedescriptorGetFDpath(struct filedescriptor* fd)
{
	return fd->FDpathname;
}

mode_t filedescriptorGetFDmode(struct filedescriptor* fd)
{
	return fd->FDmode;
}

off_t filedescriptorSetoffset(struct filedescriptor* fd, off_t offset)
{
	off_t result = lseek(fd->id, offset, SEEK_SET);
	if (result < 0) {
		perror("Setoffset at lseek");
		sprintf(fd->errcode, "Setoffset at lseek errno: %d\n", errno);
	}
	return result;
}

off_t filedescriptorRewind(struct filedescriptor* fd)
{
	off_t pos = lseek(fd->id, 0, SEEK_CUR);
	if (pos < 0) {
		perror("Rewind at lseek");
		sprintf(fd->errcode, "Rewind at lseek errno: %d\n", errno);
		return -1;
	}
	off_t result = lseek(fd->id, -pos, SEEK_CUR);
	if (result < 0) {
		perror("Rewind at lseek");
		sprintf(fd->errcode, "Rewind at lseek errno: %d\n", errno);
	}
	return result;
}

off_t filedescriptorSetend(struct filedescriptor* fd)
{
	off_t result = lseek(fd->id, 0, SEEK_END);
	if (result < 0) {
		perror("Setend at lseek");
		sprintf(fd->errcode, "Setend at lseek errno: %d\n", errno);
	}
	return result;
}

off_t filedescriptorSetendoffset(struct filedescriptor* fd, off_t offset)
{
	off_t result = lseek(fd->id, offset, SEEK_END);
	if (result < 0) {
		perror("Setendoffset at lseek");
		sprintf(fd->errcode, "Setendoffset at lseek errno: %d\n", errno);
	}
	return result;
}

off_t filedescriptorGetpos(struct filedescriptor* fd)
{
	off_t result = lseek(fd->id, 0, SEEK_CUR);
	if (result < 0) {
		perror("Getpos at lseek");
		sprintf(fd->errcode, "Getpos at lseek errno: %d\n", errno);
	}
	return result;
}

ssize_t filedescriptorWrite(struct filedescriptor* fd, const void* buf, size_t count)
{
	ssize_t result = write(fd->id, buf, count);
	if (result < 0) {
		perror("Write at write");
		sprintf(fd->errcode, "Write at write errno: %d\n", errno);
	}
	return result;
}

ssize_t filedescriptorRead(struct filedescriptor* fd, void* buf, size_t count)
{
	ssize_t result = read(fd->id, buf, count);
	if (result < 0) {
		perror("Read at read");
		sprintf(fd->errcode, "Read at read errno: %d\n", errno);
	}
	return result;
}

void filedescriptorSetDefault(struct filedescriptor* fd)
{
	int var = O_RDWR | O_NOCTTY | O_NDELAY;
	if (fcntl(fd->id, F_SETFD, var) < 0) {
		perror("SetDefault at fcntl");
		sprintf(fd->errcode, "SetDefault at fcntl errno: %d\n", errno);
		} else {
		fd->FDflags = var;
	}
	var = FNDELAY;
	if (fcntl(fd->id, F_SETFL, var) < 0) {
		perror("SetDefault at fcntl");
		sprintf(fd->errcode, "SetDefault at fcntl errno: %d\n", errno);
		} else {
		fd->FLflags = O_NONBLOCK;
	}
}

void filedescriptorSetFLflags(struct filedescriptor* fd, int arg)
{
	if (fcntl(fd->id, F_SETFL, arg) < 0) {
		perror("SetFLflags at fcntl");
		sprintf(fd->errcode, "SetFLflags at fcntl errno: %d\n", errno);
		} else {
		fd->FLflags = arg;
	}
}

void filedescriptorSetFDflags(struct filedescriptor* fd, int arg)
{
	if (fcntl(fd->id, F_SETFD, arg) < 0) {
		perror("SetFDflags at fcntl");
		sprintf(fd->errcode, "SetFDflags at fcntl errno: %d\n", errno);
		} else {
		fd->FDflags = arg;
	}
}

int filedescriptorGetFLflags(struct filedescriptor* fd)
{
	return fd->FLflags;
}

int filedescriptorGetFDflags(struct filedescriptor* fd)
{
	return fd->FDflags;
}

int filedescriptorRequest(struct filedescriptor* fd, int request, char* argp)
{
	fd->argp = argp;
	int result = ioctl(fd->id, request, fd->argp);
	if (result < 0) {
		perror("Request at ioctl");
		sprintf(fd->errcode, "Request at ioctl errno: %d\n", errno);
	}
	return result;
}

int filedescriptorSetOwner(struct filedescriptor* fd, pid_t owner)
{
	int result = fcntl(fd->id, F_SETOWN, owner);
	if (result < 0) {
		perror("Owner at Unable to set process to owner");
		sprintf(fd->errcode, "Owner at Unable to set process to owner errno: %d\n", errno);
	}
	return result;
}

/*** ftos ***/
char* ftos(FILE* stream)
{
	int i, NBytes;
	char caracter;
	char* value = NULL;
	for (i = 0, NBytes = 4; (caracter = getc(stream)) != EOF; i++) {
		if ((i == 0) || (i == NBytes)) {
			NBytes = 2 * NBytes;
			value = (char*)realloc(value, NBytes * sizeof(char));
			if (value == NULL) {
				perror("ftos at realloc");
				break; // Exit if memory allocation fails
			}
		}
		*(value + i) = caracter;
	}
	if (value) {
		value[i] = '\0'; // Null-terminate the string
	}
	return value;
}

/*** fltos ***/
char* fltos(FILE* stream)
{
	int i, NBytes;
	char caracter;
	char* value = NULL;
	for (i = 0, NBytes = 4; (caracter = getc(stream)) != EOF; i++) {
		if ((i == 0) || (i == NBytes)) {
			NBytes = 2 * NBytes;
			value = (char*)realloc(value, NBytes * sizeof(char));
			if (value == NULL) {
				perror("fltos at realloc");
				break; // Exit if memory allocation fails
			}
		}
		*(value + i) = caracter;
	}
	if (value) {
		value[i] = '\0'; // Null-terminate the string
	}
	return value;
}
