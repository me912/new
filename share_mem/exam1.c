#include <sys/stat.h>   
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <string.h>
int main(){
    int shm_fd;
    shm_fd=shm_open("TEST_MEM", O_RDWR | O_CREAT, 0666);
    ftruncate(shm_fd, 4096);
    void* ptr = mmap(0, 20, PROT_WRITE | PROT_READ, MAP_SHARED,shm_fd, 0);
    char * a = "hello world!!!\n" ;
    strcpy(ptr, a);
    *(int *)(ptr + 20) = 5;

}