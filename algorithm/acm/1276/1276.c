/*
  题目大意:现有不同币值的硬币各若干枚,对于给定的任意钱数n
           问:用现有的硬币能够凑到的不大于n的最大钱数
  解题思路:此题为有界背包问题一种变形，题目的意思相当于背包
           中物品的价值和权重相同
*/

#include<stdio.h>
#include<string.h>

typedef struct{
  int nk;
  int dk;
  int wk;
}deno;
int cash,num;
deno bill[11];
int f[100050];

int max(int x,int y){
  return (x>y)?x:y;
}

int main(){
  int i,j,k,cost,weight;
  while(scanf("%d %d",&cash,&num) != EOF){
    memset(f,0,sizeof(f));
    for(i=1;i<=num;i++){
      scanf("%d %d",&(bill[i].nk),&(bill[i].dk));
      bill[i].wk = bill[i].dk;
    }
    for(i=1;i<=num;i++){
      k=1;
      while(k<bill[i].nk){
	weight = cost = k*bill[i].dk;
	for(j=cash;j>=cost;j--){
	  f[j]=max(f[j],f[j-cost]+weight);
	}
	bill[i].nk -= k;
	k = k*2;
      }
      weight = cost = bill[i].nk*bill[i].dk;
      for(j=cash;j>=cost;j--){
	f[j]=max(f[j],f[j-cost]+weight);
      }
    }
    printf("%d\n",f[cash]);
  }
  return 0;
}
