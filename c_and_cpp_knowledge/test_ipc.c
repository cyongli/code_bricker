#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sighup(){
    signal(SIGHUP,sighup); /* reset signal */
    printf("CHILD: I have received a SIGHUP\n");
}

void sigint(){
    signal(SIGINT,sigint); /* reset signal */
    printf("CHILD: I have received a SIGINT\n");
}

void sigkill(){ 
    printf("My DADDY has Killed me!!!\n");
    exit(0);
}

int main(int argc, char *argv[]){ 
    int pid;
    /* get child process */
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    
    if (pid == 0){ /* child */
	signal(SIGHUP,sighup); /* set function calls */
	signal(SIGINT,sigint);
	signal(SIGKILL, sigkill);
	for(;;); /* loop for ever */
    }
    else{  /* pid hold id of child */
  	printf("\nPARENT: sending SIGHUP\n\n");
	kill(pid,SIGHUP);
	sleep(3); /* pause for 3 secs */
	printf("\nPARENT: sending SIGINT\n\n");
	kill(pid,SIGINT);
	sleep(3); /* pause for 3 secs */
	printf("\nPARENT: sending SIGKILL\n\n");
	kill(pid,SIGKILL);
	sleep(3);
	//for(;;);
    }
    //pthread_exit(NULL);
}

