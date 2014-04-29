/*
  题目大意:括号序列S以及由此产生的P，W序列
           P序列:每个右括号左边有多少个左括号
           W序列:对每个右括号，与它匹配的左括号是第几个(从要判断的右括号开始往回数)
           S:(((()()())))
           P:4 5 6 6 6 6
           W:1 1 1 4 5 6
           给定P序列求W序列
  解题思路:从要判断右括号的位置往回数，碰到的第一个未配对的左括号就是要求的结果

 */


#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,testcase;
  int p[21];
  int w[21];
  int used[21];
  scanf("%d",&testcase);
  int i,j,k;
  for(i=0;i<testcase;i++){
    scanf("%d",&n);
    for(j=1;j<=n;j++){
      scanf("%d",&p[j]);
      used[j]=0;
    }
    int pos = 1;
    for(j=1;j<=n;j++){
      for(k=p[j];k>=1 && used[k]!=0;k--,pos++);
      used[k]=1;
      w[j]= pos;
      pos = 1;
    }
    for(j=1;j<=n;j++)
      printf("%d ",w[j]);
    printf("\n");
  }
}
