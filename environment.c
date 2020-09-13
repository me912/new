#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
     extern char** environ;
  for (char **env = environ; *env != 0; env++)
  {
    char *thisEnv = *env;
    printf("%s\n", thisEnv);    
  }
     return 0;
}
