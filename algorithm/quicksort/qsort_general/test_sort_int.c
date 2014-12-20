
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"quicksort.c"
//#include"quicksortfaster.c"
//#include"quicksortfastest.c"
//#include"glibcqsort.c"

inline int compare(const void*a, const void*b){
  return (*(int*)a - *(int*)b);
}

int main(int argc,char* argv[]){
  srandom(time(NULL));
  size_t len = atoi(argv[1]);
  size_t i;
  int* arr = (int*)malloc(sizeof(int)*len);
  for(i=0;i<len;i++)
    arr[i]=random();
  //scanf("%d",arr+i);
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",arr[i]); */
  /* printf("\n"); */
  clock_t start,end;
  start = clock();	
  quicksort(arr,len,sizeof(int),compare);
  //qsort(arr,len,sizeof(int),compare);
  end = clock();
  printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",arr[i]); */
  return 0;
}
