/************************************************************************
Title:    procedures
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: procedures.c$
Software: GCC
Hardware: OS
License:  Free beer
************************************************************************/
#include "procedures.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>
#ifdef _WIN32
	#include <direct.h>
	#include <process.h>
#else
	#include <unistd.h>
#endif

#define BUFF_SIZE 512

/***_procs***/
int _proc_strtotok(char* line, char* token[], const char* parser);
void _proc_rmcrnl(char* str);
char* _proc_vsnprintf(char *s, ... );
int _change_directory(const char* dirname);
int _launch_excel(void);
int _launch_word(void);
int _launch_powerpoint(void);
int _launch_flowchart(void);
int _launch_formula(void);
char* _proc_get_time(void);

static PROCEDURES setup = {
	.strtotok         = _proc_strtotok,
	.rmcrnl           = _proc_rmcrnl,
	.vsnprintf        = _proc_vsnprintf,
	.change_directory = _change_directory,
	.launch_excel     = _launch_excel,
	.launch_word      = _launch_word,
	.launch_powerpoint= _launch_powerpoint,
	.launch_flowchart = _launch_flowchart,
	.launch_formula   = _launch_formula,
	.time             = _proc_get_time
};

int _proc_strtotok(char* line, char* token[], const char* parser)
{
    int i;
    for (i = 0, token[i] = strtok(line, parser); token[i]; i++, token[i] = strtok(NULL, parser));
    return i;
}

void _proc_rmcrnl(char* str)
{
    int i;
    int stop;
    size_t len = strlen(str);
    for (i = (int)len, stop = (int)len - 3; i > stop; i--) {
        if (*(str + i) == '\r' || *(str + i) == '\n') {
            *(str + i) = '\0';
        }
    }
}

char* _proc_vsnprintf(char *s, ... )
{
	static char buff[BUFF_SIZE] = {0};
	const size_t size = BUFF_SIZE - 1;
	int ret;
	va_list arg;
	va_start(arg, s);
	ret = vsnprintf(buff, size, s, arg);
	va_end(arg);
	if(ret < 0){
		return NULL;
	}else
		return buff;
}

int _change_directory(const char* dirname) {
	#ifdef _WIN32
		if (_chdir(dirname)) {
			fprintf(stderr, "_chdir: %s\n", strerror(errno));
			return 0;
		}
	#else
		if (chdir(dirname)) {
			fprintf(stderr, "chdir fail: %d\n", errno);
			return 0;
		}
	#endif
	return -1;
}

int _launch_excel(void) {
	#ifdef _WIN32
		const char *path = "C:\\Program Files\\LibreOffice\\program\\scalc.exe";
		int pid = _spawnl(_P_NOWAIT, path, "scalc.exe", NULL);
		if (pid == -1) {
			perror("_spawnl");
			return 1;
		}
	#else
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			execl("/mnt/c/Program Files/LibreOffice/program/scalc.exe",
			      "scalc.exe", (char *)0);
			perror("execl");
			_exit(1);
		}
	#endif
	return 0;
}

int _launch_word(void) {
	#ifdef _WIN32
		const char *path = "C:\\Program Files\\LibreOffice\\program\\swriter.exe";
		int pid = _spawnl(_P_NOWAIT, path, "swriter.exe", NULL);
		if (pid == -1) {
			perror("_spawnl");
			return 1;
		}
	#else
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			execl("/mnt/c/Program Files/LibreOffice/program/swriter.exe",
			      "swriter.exe", (char *)0);
			perror("execl");
			_exit(1);
		}
	#endif
	return 0;
}

int _launch_powerpoint(void) {
	#ifdef _WIN32
		const char *path = "C:\\Program Files\\LibreOffice\\program\\simpress.exe";
		int pid = _spawnl(_P_NOWAIT, path, "simpress.exe", NULL);
		if (pid == -1) {
			perror("_spawnl");
			return 1;
		}
	#else
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			execl("/mnt/c/Program Files/LibreOffice/program/simpress.exe",
			      "simpress.exe", (char *)0);
			perror("execl");
			_exit(1);
		}
	#endif
	return 0;
}

int _launch_flowchart(void) {
	#ifdef _WIN32
		const char *path = "C:\\Program Files\\LibreOffice\\program\\sdraw.exe";
		int pid = _spawnl(_P_NOWAIT, path, "sdraw.exe", NULL);
		if (pid == -1) {
			perror("_spawnl");
			return 1;
		}
	#else
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			execl("/mnt/c/Program Files/LibreOffice/program/sdraw.exe",
			      "sdraw.exe", (char *)0);
			perror("execl");
			_exit(1);
		}
	#endif
	return 0;
}

int _launch_formula(void) {
	#ifdef _WIN32
		const char *path = "C:\\Program Files\\LibreOffice\\program\\smath.exe";
		int pid = _spawnl(_P_NOWAIT, path, "smath.exe", NULL);
		if (pid == -1) {
			perror("_spawnl");
			return 1;
		}
	#else
		pid_t pid = fork();
		if (pid < 0) {
			perror("fork");
			return 1;
		}
		if (pid == 0) {
			execl("/mnt/c/Program Files/LibreOffice/program/smath.exe",
			      "smath.exe", (char *)0);
			perror("execl");
			_exit(1);
		}
	#endif
	return 0;
}

char* _proc_get_time(void)
{
	time_t current_time;
	char* c_time_string;
	
	current_time = time(NULL);
	
	if (current_time == ((time_t)-1))
	{
		return  NULL;
	}
	
	c_time_string = ctime(&current_time);
	
	return c_time_string;
}

/***interface***/
PROCEDURES* PROCEDURESenable(void)
{
	return &setup;
}

/***EOF***/

/***
registers->intances->objects->systems
***/

