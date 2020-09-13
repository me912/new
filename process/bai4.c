#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stack>
#define MAX_LINE 80 /* The maximum length command */

int main(void)
{
char *args[MAX_LINE/2 + 1]; /* command line arguments */
int should_run = 1; /* flag to determine when to exit program */
std::stack<char*> st;
int t=0;
while(t<10){
t++;
printf("osh>");
fflush(stdout);
int i=0;
char* s = new char [10];
st.push(s);
fgets(s, 80, stdin);
args[0] = strtok(s, " ");
while(args[i]!=NULL){
i++;
args[i] = strtok(NULL, " ");
}

if(args[i-1][strlen(args[i-1])-1] == '\n') args[i-1][strlen(args[i-1])-1] = '\0';
pid_t pd;
pd = fork();
int status;
args[i] = NULL;

if(pd == 0){
wait(&status);
}

else {
   if(args[0] == "history") {
   	if (st.size()<=10){
   	while(!st.empty()){
     	 printf("%s\n", st.top());
      	st.pop();
  	 }	
   	}
   
   else {
   for(int i=0; i<10; i++)
   printf("%s\n", st.top());
   st.pop();
   }
   }
   execvp(args[0], args);
   return 0;
}
}
return 0;
}

