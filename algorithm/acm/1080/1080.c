
/*
  题目大意:基因相似度判断，基因序列可以补'-'
              A  C  G  T  -
           A  5 -1 -2 -1 -3
           C -1  5 -3 -2 -4
           G -2 -3  5 -2 -2
           T -1 -2 -2  5 -1
           - -3 -4 -2 -1  *
          表中为匹配的权值，求两对基因序列的匹配权重，不允许'-'和-'-'匹配。
   解题思路:此题是LCS的变换形式，把状态方程改成如下即可
      c[i][j]=max(c[i-1][j-1]+value(x[i],y[j]),c[i][j-1]+value('-',y[j]),c[i-1][j]+value(x[i],'-'))
      唯一需要注意的点是这个题目中x[i]=y[j]时并不能去掉子问题
*/

#include<stdio.h>

int c[111][111];

int dic[5][5]={5,-1,-2,-1,-3,
               -1,5,-3,-2,-4,
               -2,-3,5,-2,-2,
               -1,-2,-2,5,-1,
               -3,-4,-2,-1,0};

static inline int max(int a,int b,int c){
  return (a>b)?(a>c?a:c):(b>c?b:c);
}

int value(char x,char y){
  if(x==y)
    return 5;
  int a,b;
  switch(x){
    case 'A':a=0;break;
    case 'C':a=1;break;
    case 'G':a=2;break;
    case 'T':a=3;break;
    case '-':a=4;break;
    default:break;
  }
  switch(y){
    case 'A':b=0;break;
    case 'C':b=1;break;
    case 'G':b=2;break;
    case 'T':b=3;break;
    case '-':b=4;break;
    default:break;
  }
  return dic[a][b];
}

int similarity(x,len1,y,len2)
     char*x,*y;
     int len1,len2;
{
  c[0][0]=0;
  int i,j;
  for(i=1;i<=len1;i++){
    switch(x[i]){
    case 'A':c[i][0]=c[i-1][0]-3;break;
    case 'C':c[i][0]=c[i-1][0]-4;break;
    case 'G':c[i][0]=c[i-1][0]-2;break;
    case 'T':c[i][0]=c[i-1][0]-1;break;
    default:break;
    }
  }
  for(j=1;j<=len2;j++){
    switch(y[j]){
    case 'A':c[0][j]=c[0][j-1]-3;break;
    case 'C':c[0][j]=c[0][j-1]-4;break;
    case 'G':c[0][j]=c[0][j-1]-2;break;
    case 'T':c[0][j]=c[0][j-1]-1;break;
    default:break;
    }
  }
  for(i=1;i<=len1;i++){
    for(j=1;j<=len2;j++){
      c[i][j]=max(c[i-1][j-1]+value(x[i],y[j]),c[i][j-1]+value('-',y[j]),c[i-1][j]+value(x[i],'-'));
    }
  }
  return c[len1][len2];
}

int main(){
  int testcase;
  char x[111],y[111];
  int len1,len2;
  scanf("%d",&testcase);
  int i=0,j=0;
  for(i=0;i<testcase;i++){
    scanf("%d %s",&len1,x+1);
    scanf("%d %s",&len2,y+1);
    printf("%d\n",similarity(x,len1,y,len2));
  }
  return 0;
}
