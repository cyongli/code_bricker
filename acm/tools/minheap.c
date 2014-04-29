
#include<stdio.h>
#include<stdlib.h>

void swap(int*a,int*b){
  int temp=*a;
  *a=*b;
  *b=temp;
}

void siftdown(int*a,int i,int n){
  int j=i;
  while(2*i+1<n){
    if(2*i+2<n)
      j = (a[2*i+2]>a[2*i+1])?(2*i+1):(2*i+2);
    else if(2*i+1<n)
      j = 2*i+1;
    else break;
    if(a[i]>a[j])
      swap(&a[i],&a[j]);
    i = j;
  }
}

void extract_min(int*a,int n){
  swap(&a[0],&a[n-1]);
  siftdown(a,0,n-1);
}

int main(){
  int n,*a,i;
  printf("input the number of heap:");
  scanf("%d",&n);
  a=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  for(i=n/2-1;i>=0;i--)
    siftdown(a,i,n);
  printf("output the heap:\n");
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
  for(i=0;i<n;i++)
    extract_min(a,n-i);
  for(i=0;i<n;i++)
    printf("%d ",a[i]);
  printf("\n");
}
