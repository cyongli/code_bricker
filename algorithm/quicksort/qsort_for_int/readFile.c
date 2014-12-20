#include<stdio.h>
//#include<stdlib.h>

const int len = 1000000;

int main(){
  srandom(time(NULL));
  int i,a;
  FILE * newFile = fopen("tet","a+");
  for(i=0;i<len;i++){
    a=random();
    fprintf(newFile,"%d\n",a);
  }
  fclose(newFile);
  return 0;
}
