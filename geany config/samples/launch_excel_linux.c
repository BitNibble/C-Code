#include <unistd.h> // fork, chdir

/***launch_excel_equivalent***/
void launch_excel_equivalent(void) {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return;
	}
	if (pid == 0) {
		execl("/usr/bin/libreoffice", "libreoffice", "--calc", (char *)0);
		perror("execl");
		_exit(1);
	}
}

