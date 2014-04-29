/*
  题目大意:planar graph中的染色问题
  解题思路:四色定理说明任意的planar graph只要4中颜色就可以对图中的节点进行染色
           所以现在只需要对图进行1,2,3染色判断，枚举即可，
           可以算作dfs的变种但是和dfs的遍历方式不一样
  主要:planar graph的定义
*/

#include<stdio.h>
#include<string.h>

int graph[30][30];
char adj[30];
int n,length,ans;
int used[30];

int max(int used[]){
  int max=used[0];
  int i=0;
  for(i=0;i<n;i++)
    max = (max<used[i])?used[i]:max;
  return max;
}

int check(int x,int color){
  int i,flag=1;
  for(i=0;i<n && i!=x;i++)
    if(graph[x][i] && used[i]==color)
      {flag=0;break;}
  return flag;    
}

void enumerate(int m){
  if(m==n){
    int t = max(used);
    ans = (t<ans)?t:ans;
    return;
  }
  int i,j;
  for(i=m;i<n;i++)
    for(j=1;j<=4;j++)
      if(check(i,j)){
	  used[i]=j;
	  enumerate(i+1);
	}
}

int main(){
  int i,j;
  while(scanf("%d",&n)!=EOF && n){
    memset(graph,0,sizeof(graph));
    memset(used,0,sizeof(used));
    for(i=0;i<n;i++){
      scanf("%s",adj);
      length = strlen(adj);
      for(j=2;j<length;j++)
	graph[i][adj[j]-'A']=graph[adj[j]-'A'][i]=1;
    }
    ans = 4;
    used[0]=1;
    enumerate(1);
    if(ans==1)
      printf("%d channel needed.\n",ans);
    else
      printf("%d channels needed.\n",ans);
    /* for(i=0;i<n;i++){ */
    /*   for(j=0;j<n;j++) */
    /* 	printf("%5d",graph[i][j]); */
    /*   printf("\n"); */
    /* } */
    /* printf("\n"); */
  }
  return 0;
}
