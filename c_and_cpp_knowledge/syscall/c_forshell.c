#include<stdio.h>

int main(int argc,char**argv){
  char* dir = "/home/chaoyli";
  char sendme[20];
  char result[200];
  sprintf(sendme,"ls %s",dir);
  printf("%s\n",sendme);
  FILE * fp = popen(sendme,"r");
  while(fscanf(fp,"%s",result)!=EOF){
    printf("%s\n",result);
  }
  pclose(fp);
  //printf("%s\n",result);
  return 0;
}
