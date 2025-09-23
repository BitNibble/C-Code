#include <process.h> // for _spawnl

/***launch_excel_equivalent***/
void launch_excel_equivalent(void) {
	const char *path = "C:\\Program Files\\LibreOffice\\program\\scalc.exe";
	int pid = _spawnl(_P_NOWAIT, path, "scalc.exe", NULL);
	if (pid == -1) {
		perror("_spawnl");
	}
}
/***launch_excel_wsl_equivalent***/
void launch_excel_wsl_equivalent(void) {
	pid_t pid = fork();
	if (pid < 0) {
		perror("fork");
		return;
	}
	if (pid == 0) {
		execl("/mnt/c/Program Files/LibreOffice/program/scalc.exe",
		      "scalc.exe", (char *)0);
		perror("execl");
		_exit(1);
	}
}

