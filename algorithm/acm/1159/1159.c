/*
  题目大意:一个字符串中最少加入几个字符可以使得原字符串变为回文字符串
  解题思路:1.最少需要补充的字母数 = 原序列S的长度 —  S和S'的最长公共子串长度
             其中S'是S的逆序列
           2.使用动态规划，状态转移方程如下:
             str[i]==str[j] dp[i][j]=str[i+1][j-1] ;
             str[i]!=str[j] dp[i][j]=mina(str[i+1][j],str[i][j-1]);
*/

#include<stdio.h>
#include<string.h>

int dp[2][6000];
char str[6000];

int min(int x,int y){
  return (x>y)?y:x;
}

int main(){
  int n;
  scanf("%d",&n);
  scanf("%s",str+1);
  int i,j,k=0;
  memset(dp,0,sizeof(dp));
  for(i=n-1;i>0;i--){
    for(j=i+1;j<=n;j++){
      if(str[i]==str[j])
	dp[k][j]=dp[1-k][j-1];
      else
	dp[k][j]=min(dp[1-k][j],dp[k][j-1])+1;
    }
    for(j=1;j<=n;j++) dp[1-k][j]=0;
    k = 1-k;
  }
  printf("%d\n",dp[1-k][n]);
  return 0;
}
