#include<stdio.h>
#include<string.h>
#include<time.h>
#include "quicksort.c"

int compare(const void* a,const void* b){
  return (strcmp((const char*)a,(const char*)b));
}

int main(int argc,char* argv[]){
  int len = atoi(argv[1]);
  int i=0;
  char arr[len][len];
  for(i=0;i<len;i++)
    scanf("%s",arr[i]);
  quicksort(arr,len,len,compare);
  printf("\noutputResult:\n");
  for(i=0;i<len;i++)
    printf("%s\n",arr[i]);
  return 0;
}
