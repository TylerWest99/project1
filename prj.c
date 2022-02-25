// code for project 1 by Jacob and Tyler

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_LINE_SIZE 255


void signalHandler (int sigNum)
{
        printf("\nEnding program got a control C\n");
        exit(0);
}


int main() {

	signal(SIGINT, signalHandler);

	int k;
	printf("Enter value for k: ");
	scanf("%d", &k);

	int parentID = getpid();
	int nodeID;

	for(int i = 0; i < k; i++){
		if(fork() == 0){
			nodeID = i;
			printf("parent process: %d, child process: %d, nodeID: %d\n", getppid(), getpid(), nodeID);
			exit(0);
		}
	}

	for(int i = 0; i < k; i++){
		wait(NULL);
	}

	printf("Waiting for a signal to shutdown\n");
	pause();
	printf("Shutting down\n");
	return(0);
	
}
