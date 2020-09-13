#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(){
	int fd = open("/home/minh/Documents/test.c",  O_RDWR | O_CREAT, 0777);
	pid_t pd = fork();
	if(pd == 0) 
	write(fd, "IAMPARENT\n", sizeof("IAMPARENT\n")-1);
	else 
	write(fd, "IAMCHILD\n", sizeof("IAMCHILD\n")-1);
	return 0;
}
