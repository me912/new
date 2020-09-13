#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char* argv[]){
if(argc!=2) {
printf("Nhap sai");
exit(1);
}
DIR *dp;
struct dirent *dirp;
if((dp=opendir(argv[1]))==NULL){
printf("cant open %s", argv[1]);
exit(1);
}
struct stat buf;
while((dirp = readdir(dp)) != NULL){
stat(dirp->d_name, &buf);
printf("Name:%s\tSize:%li\tModified Time:%li", dirp->d_name, buf.st_size, buf.st_mtim.tv_sec);
printf("\n");
}
return 0;
}
