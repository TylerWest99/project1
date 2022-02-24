// code for project 1 by Jacob and Tyler

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>


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
	//printf("Value of k is... %d\n", k);
	
	// sets k to be for 3 nodes
	k = 3;

	int parentID = getpid();
	

	for(int i = 0; i < k; i++){
		if(parentID == getpid()){
			printf("Mission accomplished process made\n");
			fork();
			//printf("Mission accomplished process made\n");		
		}
	}
	printf("process... %d\n", getpid());
}
