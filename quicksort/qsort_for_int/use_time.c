
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"msort.c"

inline int compare(const void*  a,const void* b){
  return ( *(int*)a - *(int*)b );
}

int main(int argc,char*argv[])
{
  int i;
  int len = atoi(argv[1]);
  int * array = (int *)malloc(sizeof(int)*len);
  srandom(time(NULL));
  for(i=0;i<len;i++){
    array[i]=random();
    //scanf("%d",&array[i]);
  }
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",array[i]); */
  /* printf("\n"); */
  clock_t start,end;
  start = clock();
  chaoyli_qsort(array,len,sizeof(int),compare);
  end = clock();
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",array[i]); */
  printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;

}


