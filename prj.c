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
#define READ 0
#define WRITE 1

void signalHandler (int sigNum)
{
        printf("\nEnding program got a control C\n");
        exit(0);
}


int main() {

	//signal
	signal(SIGINT, signalHandler);
	
	int k;
	printf("Enter value for k: ");
	scanf("%d", &k);

	// gets parent ID
	int parentID = getpid();
	
	//makes node id var for each child to use
	int nodeID;
	//makes header string for each message
	char* header;

	//creates pipe for parent and children
	int myPipe[2];
	int pipeResult;
	pipeResult = pipe(myPipe);

	// creates each node with a process and gives the node a node ID
	for(int i = 0; i < k; i++){
		if(fork() == 0){
			// Code for each node and child process here!
			// Node ids and headers for different and not shared for each node 
			nodeID = i;
			header = "";
			printf("Child process created! parent process: %d, child process: %d, nodeID: %d\n", getppid(), getpid(), nodeID);
			exit(0);
		}
	}
	
	//waits for each process
	for(int i = 0; i < k; i++){
		wait(NULL);
	}

	printf("Waiting for a signal to shutdown\n");
	pause();
	printf("Shutting down\n");
	return(0);
	
}
