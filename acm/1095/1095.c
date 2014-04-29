#include<stdio.h>

int h[20]={1,1,2,5,14,42,132,429,1430,4862,
           16796,58786,208012,742900,2674440,
           9694845,35357670,129644790,477638700,1767263190};

void fun(int n,int k){
  if(0==n) return;
  if(1==n) {
    printf("X");
    return;
  }
  int i,s,sum;
  for(i=0,sum=0;sum<k;sum+=h[i]*h[n-i-1],i++);
  s = k+h[--i]*h[n-i-1]-sum;
  if(i>0) {
    printf("(");
    fun(i,(s-1)/h[n-i-1]+1);
    printf(")");
  }
  printf("X");
  if(n-i-1>0){
    printf("(");
    fun(n-i-1,(s-1)%h[n-i-1]+1);
    printf(")");
  }
}

int main(){
  int n,i,sum,k;
  scanf("%d",&n);
  while(n!=0){
    for(i=1,sum=0;sum<n;sum+=h[i++]);
    k=n+h[i-1]-sum;
    fun(i-1,k);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}
