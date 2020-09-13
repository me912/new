#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
int main(){ 
     pid_t pid;
     pid = fork();
     if(0==pid)
     printf("Parent process %u\n", getpid());
     else
     printf("Child process %u\n", getpid());
     	return 0;
     	
}
