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
    int shm_fd = shm_open("TEST_MEM", O_RDONLY, 0666);
    void *ptr = mmap(0, 4096, PROT_READ, MAP_SHARED, shm_fd, 0);
    int *ptr_int = (int *)(ptr+20);
    printf("%s\n%i", (char *)ptr, *(int *)(ptr+20));

    shm_unlink("TEST_MEM");
    return 0;
}