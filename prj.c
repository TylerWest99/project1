// code for project 1 by Jacob and Tyler

//includes are below
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <signal.h>

int main(){

	int k;
	printf("How many nodes would you like to spawn?");
	scanf("%d", &k);
	printf("k is... %d\n", k); 

}
