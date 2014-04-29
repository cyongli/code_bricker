#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/socket.h>

int main(int argc,char * argv[]){
  if(argc == 2){
    unsigned int ip = ntohl(inet_addr(argv[1]));
    printf("%u\n",ip);
  }
  else if ((strcmp(argv[1],"-i")==0) && (argc == 3)){
    char ip[20];    
    struct in_addr __in;
    __in.s_addr = htonl(strtoul(argv[2],NULL,10));
    strcpy(ip,inet_ntoa(__in));
    printf("%s\n",ip);
  }
  return 0;
}
