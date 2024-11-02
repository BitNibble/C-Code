#include <stdio.h>
#include <stdlib.h>
#include "PCfunction.h"
#include "PClfsm.h"
#include "PCficheiro.h"

#define TRUE 1
#define ZERO 0

int main(int argc, char *argv[]) {
	printf("Running program - %s with - %d arguments\n", argv[0], argc);

	// Local variables
	char *cmd;
	unsigned int number1, number2, number3, value, status = ZERO;
	char* str = NULL;

	FUNC func = FUNCenable();
	LFSMDATA MEM[128];
	LFSM r = LFSMenable(MEM, 128);

	FICHEIRO f = FICHEIROenable("file.txt");
	f.colocarchar(&f, 'A');
	f.colocarstring(&f, " qualquer coisa\n");
	rewind(f.filepointer(&f));
	str = func.ftos(f.filepointer(&f));
	printf("string in file:\n%s\n\n", str);
	free(str);
	f.close(this(&f));

	// Main loop
	while (TRUE) {
		printf("write string with number or instruction: ");
		cmd = func.fltos(stdin);
		number1 = func.getnumv2(cmd);
		printf("[Input ->  %s]\n", func.print_binary(8, number1));

		if (!strcmp(cmd, "quit") || !strcmp(cmd, "q")) {
			free(cmd);
			break;
		}

		// Other commands...
		// Implement other command handling here

		free(cmd);
	}
	
	return 0;
}
