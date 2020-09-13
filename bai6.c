#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
int main(){
printf("%i", mkdir("../Test folder", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH ));
printf("\n%s", strerror(errno));
DIR* dir = opendir("../Test folder");

printf("%i", mkdir("../Test folder/Test1", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH));

}
return 0;
}
