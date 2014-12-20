//send.c
#include <mqueue.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

bool quit = false;

void sigHandler(int sig){
  quit = true;
}

int main(int argc, char* argv[])
{
  if (argc != 3){
    printf("Usage:  %s /qname message\n", argv[0]);
    return 1;
  }

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
    printf("error: %s (%d)\n", strerror(errno), errno);
    return 1;
  }

  //signal(SIGINT, sigHandler);

  if (mq_send(qid, argv[2], strlen(argv[2])+1, 0) == -1){
	/*strlen(argv[2])+1是为了输入一个'\0'*/
	printf("send message failed\n");
  }

  mq_close(qid);
  //mq_unlink(argv[1]);//mq_unlink可以用来删除mq_queue

  return 0;
}
