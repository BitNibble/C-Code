#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <process.h> // for _spawnl
#else
#include <unistd.h>  // for fork, execl
#endif

/***launch_excel_equivalent***/
int launch_excel_equivalent(void) {
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

