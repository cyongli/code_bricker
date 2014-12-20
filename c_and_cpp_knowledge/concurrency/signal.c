#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigproc(){
    signal(SIGINT, sigproc); /*  */
    /* NOTE some versions of UNIX will reset signal to default
       after each call. So for portability reset signal each time */
 
    printf("you have pressed ctrl-c \n");
}
 
void quitproc(){
    printf("ctrl-\\ pressed to quit\n");
    exit(0); /* normal exit status */
}
 
int main(int argc, char *argv[]){
    signal(SIGINT, sigproc);
    signal(SIGQUIT, quitproc);
    printf("ctrl-c disabled use ctrl-\\ to quit\n");
    for(;;); /* infinite loop */
}
 
