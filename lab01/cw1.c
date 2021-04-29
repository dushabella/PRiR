#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define PROCESS 5
/* 	Biedka H. && Dusza I. 	*/
/** 
	PRiR Lab01 Ćwiczenie 1 
	Utworzyć grupę 5 procesów o jednym wspólnym procesie macierzystym 
**/

int main() {
    int i=0;
    for (i = 1; i <= PROCESS; i++) {
    	pid_t pid;
    	switch(pid = fork()){
	    	case -1:
	    		fprintf(stderr, "Blad w fork\n\n");
	    		return EXIT_FAILURE;
	    	case 0:
	    		printf("Jestem dzieckiem numer %d.\n PID = %d\n Mój rodzic to \033[22;34m%d\n\033[0m Wartość przekazana przez fork() = %d\n\n", i, getpid(), getppid(), pid);
	    		return EXIT_SUCCESS;
	    	default:
	    		printf("Jestem rodzicem.\n PID = %d\n Wartość przekazana przez fork() = %d\n\n", getpid(), pid);
	    		// czeka na zakonczenie procesow potomnych
	    		if (wait(0) == -1) 
	    			fprintf(stderr, "Blad w wait\n");
		}
    }
    return EXIT_SUCCESS;
}