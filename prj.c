// code for project 1 by Jacob and Tyler

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
#include <signal.h>
#include <time.h>


#define MAX_LINE_SIZE 255


void signalHandler (int sigNum)
{
        printf("Ending program got a control C\n");
        exit(0);
}


int main() {
signal(SIGINT, signalHandler);


 printf("Enter value for k: ");

   char temp[MAX_LINE_SIZE];
   char k[MAX_LINE_SIZE];
   fgets(k, MAX_LINE_SIZE, stdin);

   strcpy(temp,k);
}
