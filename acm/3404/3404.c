/*
  
  问题描述：n个人夜间要过桥，总共只有一盏灯。桥一次只能通过两个人，每次过桥的时间由两人中的速度慢者决定，求n个人过桥的最短时间
  解决方案：如果是1个人，直接过去
            如果是2个人，直接过去
            如果是3个人，时间分别为A,B,C(A<B<C)，无论怎么设计，最短时间为A+B+C
	    如果是4个人，时间分别为A,B,C,D(A<B<C<D)。有两种优化方案
	       A,B先过河，A回；C,D在过河B回;A,B过河，总时间为B+A+D+B+B;
	       A,D先过河，A回；A,C在过河A回;A,B过河，总时间为D+A+C+A+B
	       A+C<2B则下种方案好，否则上种方案好。每次选取的C,D是逐渐变小的,A和B不变,A+C<2B一旦成立,则下面的就一直为最优方案

 */

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
  int i=0,num,result=0;
  int a[50];
  scanf("%d",&num);
  //int*a = (int*)malloc(num*sizeof(int));
  for(i=0;i<num;i++)
    scanf("%d",&a[i]);
  quicksort(a,0,num-1);
  //for(i=0;i<num;i++)
  //  printf("%d ",a[i]);
  //printf("\n");
  bridge(a,num,&result);
  printf("%d\n",result);
}
