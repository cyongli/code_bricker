#include<stdio.h>
#include<stdlib.h>

int main(int argc,char*argv[]){
  char* a = (char*)malloc(sizeof(char)*5);
  scanf("%s",a);
  int i=0;
  while(a[i]!='\0'){
    printf("%c\n",a[i]);
    i++;
  }
  printf("i=%d,%d\n",i,a[6]);
  return 0;
}
