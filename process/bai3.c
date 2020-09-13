#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int TT(int n){
printf("%i\n", n);
return (n&1)*(3*n+1)+(!(n&1))*(n/2);
}
int main(int argc, char ** argv){
   pid_t pd;
   int n = atoi(argv[1]);
   int status;
   
   x: pd = fork();
   if(pd == 0){
   wait(&status);
   }
   else
   {
       n = TT(n);
       if(n==1) return 0;
       else {
       goto x;
        
       }
   }
   
}
