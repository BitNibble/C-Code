/************************************************************************
Title:    procedures
Author:   <sergio.salazar.santos@gmail.com>
File:     $Id: procedures.c$
Software: GCC
Hardware: OS
License: Free beer
************************************************************************/
#include "procedures.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#ifdef _WIN32
	#include <direct.h>
	#include <process.h> // _spawnl	
#else
	#include <unistd.h>  // fork, chdir
#endif
/***change_directory***/
int change_directory(const char* dirname) {
	#ifdef _WIN32
		if(_chdir(dirname)) {
			fprintf(stderr, "_chdir: %s\n", strerror(errno));
			return 0;
		}
	#else
		if(chdir(dirname)) {
			fprintf(stderr, "chdir fail: %d\n", errno);
			return 0;
		}
	#endif
	return -1;
}
/***launch_excel***/
int launch_excel(void) {
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
/***launch_word***/
int launch_word(void) {
#ifdef _WIN32
	const char *path = "C:\\Program Files\\LibreOffice\\program\\swriter.exe";
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
		execl("/mnt/c/Program Files/LibreOffice/program/swriter.exe",
		      "scalc.exe", (char *)0);
		perror("execl");
		_exit(1);
	}
#endif
	return 0;
}
/***launch_powerpoint***/
int launch_powerpoint(void) {
#ifdef _WIN32
	const char *path = "C:\\Program Files\\LibreOffice\\program\\simpress.exe";
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
		execl("/mnt/c/Program Files/LibreOffice/program/simpress.exe",
		      "scalc.exe", (char *)0);
		perror("execl");
		_exit(1);
	}
#endif
	return 0;
}
/***launch_flowchart***/
int launch_flowchart(void) {
#ifdef _WIN32
	const char *path = "C:\\Program Files\\LibreOffice\\program\\sdraw.exe";
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
		execl("/mnt/c/Program Files/LibreOffice/program/sdraw.exe",
		      "scalc.exe", (char *)0);
		perror("execl");
		_exit(1);
	}
#endif
	return 0;
}
/***launch_formula***/
int launch_formula(void) {
#ifdef _WIN32
	const char *path = "C:\\Program Files\\LibreOffice\\program\\smath.exe";
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
		execl("/mnt/c/Program Files/LibreOffice/program/smath.exe",
		      "scalc.exe", (char *)0);
		perror("execl");
		_exit(1);
	}
#endif
	return 0;
}
/***EOF***/

