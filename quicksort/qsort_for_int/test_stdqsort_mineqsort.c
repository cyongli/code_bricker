#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int * a ,int * b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

int median_of_three(int a[],int l,int r){
  int mid = (l+r)/2;
  if(a[mid]<a[l])
    swap(&(a[mid]),&(a[l]));
  if(a[r]<a[mid])
    swap(&(a[mid]),&(a[r]));
  else return mid;
  if(a[mid]<a[l])
    swap(&(a[mid]),&(a[l]));
  return mid;
}

int partition_lumoto(int a[],int l,int r){
  /*lumoto划分方法*/
  int key = a[r],i=l-1,j;
  for(j=l;j<r-1;j++)
    if(a[j]<=key){
      i = i+1;
      swap(&a[j],&a[i]);
    }
  swap(&a[i+1],&a[r]);
  return i+1;
}

int partition_hoare(int a[],int l,int r){
  /*hoare划分方法*/
  int mid = median_of_three(a,l,r);
  int key = a[r-1];
  int i=l+1;
  int j=r-1;
  while(i<j){
    while(i<j && a[i]<=key) i++;
    a[j]=a[i];
    while(i<j && a[j]>=key) j--;
    a[i]=a[j];
  }
  a[j]=key;
  return j;
}


void quicksort(int a[],int l,int r){
  if(l<r){
    int q = partition_hoare(a,l,r);
    quicksort(a,l,q-1);
    quicksort(a,q+1,r);
  }

}

inline int compare(const void*  a,const void* b){
  return ( *(int*)a - *(int*)b );
}

int main(int argc,char*argv[]){
  int i;
  int len = atoi(argv[1]);
  int * array = (int *)malloc(sizeof(int)*len);
  srandom(time(NULL));
  for(i=0;i<len;i++){
    array[i]=random();
  }
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",array[i]); */
  /* printf("\n"); */
  clock_t start,end;
  start = clock();
  //quicksort(array,0,len-1);
  qsort(array,len,sizeof(int),compare);
  end = clock();
  /* for(i=0;i<len;i++) */
  /*   printf("%d\n",array[i]); */
  printf("%lf\n",(double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}

