#include<stdio.h>
#include<time.h>
#include "quicksort.c"

int compare(const void* a,const void* b){
  if(*(double*)a == *(double*)b) return 0;
  else  return (*(double*)a > *(double*)b)?1:-1;
}

int main(int argc,char*argv[]){
  int i=0;
  int len=atoi(argv[1]);
  double arr[len];
  srandom(time(NULL));
  for(i=0;i<len;i++)
    arr[i]=(random()%100)/(5.0);
  quicksort(arr,len,sizeof(double),compare);
  for(i=0;i<len;i++)
    printf("%g\n",arr[i]);
  return 0;
}
