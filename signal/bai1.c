#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int main(){
	sigset_t sg;
	sigemptyset(&sg);
	sigprocmask(SIG_BLOCK, NULL, &sg);
	
    int sig, cnt;
    cnt = 0;
    for (sig = 1; sig < NSIG; sig++) {
        if (sigismember(&sg, sig)) {
            cnt++;
            printf("%d (%s)\n", sig, strsignal(sig));
        }
    }

    if (cnt == 0)
        printf( "<empty signal set>\n");
	
	
}
