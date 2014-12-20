#define _XOPEN_SOURCE 600
#include <time.h>
#include <mqueue.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

bool quit = false;

void sigHandler(int sig){
  quit = true;
}

int main(int argc, char* argv[])
{
  char* name  = argv[1];

  int flags = O_RDWR | O_CREAT;
  mode_t mode  = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;

  struct mq_attr attr;
  attr.mq_flags   = 0;
  attr.mq_maxmsg  = 10;
  attr.mq_msgsize = 100;
  attr.mq_curmsgs = 0;

  mqd_t qid = mq_open(name, flags, mode, &attr);

  if (qid == -1){
    perror("Failed to open the message queue");
  }

  signal(SIGINT, sigHandler);//只有当来SIGINT时，进程才会终止

  char buf[100];
  while (!quit){
	/*当quit==false时，blocked得读取mq_queue的结果*/
    if (mq_receive(qid, buf, sizeof(buf), NULL) != -1){
      printf("%s\n", buf);
    }
    else{
      printf("error: %s (%d)\n", strerror(errno), errno);
    }
  }

  mq_close(qid);
  //mq_unlink(name);
  return 0;
}

