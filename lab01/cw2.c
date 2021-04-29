#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define PROCESS 5
/* 	Biedka H. && Dusza I. 	*/
/** 
	PRiR Lab01 Ćwiczenie 2*
	Utworzyć linię 5 procesów w której każdy nowy proces jest potomkiem poprzedniego
**/
int nowy_proces(int nr, pid_t pid);

int main() {
    pid_t pid;
    int i=0;
    for (i = 1; i <= PROCESS; i++) {
    	nowy_proces(i, pid);
    }
    return EXIT_SUCCESS;
}

int nowy_proces(int nr, pid_t pid) {
	switch(pid = fork()){
	    case -1:
	    	fprintf(stderr, "Blad w fork\n\n");
	   		return EXIT_FAILURE;
	   	case 0:
	   		printf("Jestem dzieckiem.\n PID = %d\n Mój rodzic to \033[22;34m%d\n\033[0m Wartość przekazana przez fork() = %d\n\n", getpid(), getppid(), pid);
	   		return EXIT_SUCCESS;
    	default:
	    	printf("Jestem rodzicem nr %d.\n PID = %d\n Wartość przekazana przez fork() = %d\n\n", nr, getpid(), pid);
	    	if (wait(0) == -1) {
	   			fprintf(stderr, "Blad w wait\n"); 
	   			return EXIT_FAILURE;
	   		}
	   		printf("Istniejące procesy:\n");
	   		execlp("ps", "ps", NULL);
	   		return EXIT_SUCCESS;
	}
	return EXIT_SUCCESS;
}