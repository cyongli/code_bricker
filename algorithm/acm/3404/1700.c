#include<stdio.h>
#include<stdlib.h>

#define MIN(x,y) ((x)<(y)?(x):(y))

void swap(int *a,int *b){
  int temp =*a;
  *a=*b;
  *b=temp;
}

int partition(int* a,int p,int r){
  int key = a[r];
  int i=p-1;
  int j=p;
  for(;j<=r-1;j++){
    if(a[j]<=key){
      i += 1;
      swap(&a[i],&a[j]);
    }
  }
  swap(&a[i+1],&a[r]);
  return i+1;
}

void quicksort(int*a,int p,int r){
  if(p<r){
    int q = partition(a,p,r);
    quicksort(a,p,q-1);
    quicksort(a,q+1,r);
  }
}

void bridge(int*a,int num,int*result){
  int i=num-1,tmp1,tmp2;
  for(i=num-1;i>=3;i-=2){
    tmp1=a[0]+2*a[1]+a[i];
    tmp2=2*a[0]+a[i-1]+a[i];
    *result += MIN(tmp1,tmp2);
  }
  if(i==2) *result += a[0]+a[1]+a[2];
  if(i==1) *result += a[1];
  if(i==0) *result += a[0];
}

int main(){
  int i=0,num,testcase,result=0;
  int a[1000];
  scanf("%d",&testcase);
  while(testcase>0){
    result = 0;
    scanf("%d",&num);
    for(i=0;i<num;i++)
      scanf("%d",&a[i]);
    quicksort(a,0,num-1);
    bridge(a,num,&result);
    printf("%d\n",result);
    testcase -= 1;
  }
}
